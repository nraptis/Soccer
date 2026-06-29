#include "TwistExpander_Karate_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Karate_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint8_t *pSnow,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltA = pDomainSaltSet->mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltB = pDomainSaltSet->mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltC = pDomainSaltSet->mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltD = pDomainSaltSet->mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltE = pDomainSaltSet->mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltF = pDomainSaltSet->mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltA = pDomainSaltSet->mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltB = pDomainSaltSet->mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltC = pDomainSaltSet->mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltD = pDomainSaltSet->mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltE = pDomainSaltSet->mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltF = pDomainSaltSet->mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltA = pDomainSaltSet->mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltB = pDomainSaltSet->mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltC = pDomainSaltSet->mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltD = pDomainSaltSet->mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltE = pDomainSaltSet->mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltF = pDomainSaltSet->mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEA4B969C8F7BF68DULL + 0x88B1906BECF93DD3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB2BFAEB259186005ULL + 0xFCC5465E3F64ECADULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB3531D71D79BF47BULL + 0xBC113EC4FCC60F8BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE124102988FA1961ULL + 0x89EA19513201C181ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE3288FB2D353B9C1ULL + 0xCB41441936EB953BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE373B3D50616844FULL + 0xA9D277688D7E3790ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x807E76D986D082A5ULL + 0xB9F4E9BFAF2A647EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB5D3AF086B0E985DULL + 0x92B03FE71D6A5A3CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEA6FD70FC5680AEBULL + 0xC4AFFCF0EE8D5E42ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8BD3E7AD219683FBULL + 0xB20FCBC65D788E89ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE02D7DA8ACF8C8F7ULL + 0xCAC50C6A04E1B06BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC2A91835B3573761ULL + 0xE393935D08BD043CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFA580F0F188DCA31ULL + 0xE75969C1F9876244ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC03270333C1B1383ULL + 0x8F22EFD25FCF2E28ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDA7554797C663865ULL + 0xE7B5D53C07EB9B82ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEF66F36331EBCEC9ULL + 0xFA88CE5B059998FDULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_A_A kdf_a_loop_a (start)
    {
        // KDF_A_A kdf_a_loop_a lane group
        // read from: mSource, pSnow, aFireLaneA, aFireLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // ingress from: mSource, pSnow
        // ingress directions: mSource forward forced, pSnow forward/backward random
        // cross from: pSnow, mSource
        // cross directions: pSnow backward forced, mSource backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(mSource[((aIndex + 190U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((aIndex + 77U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2506U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 5421U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = (((aWandererE + RotL64(aScatter, 46U)) + RotL64(aCarry, 11U)) + 12029393034357490020U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 51U)) + 4526754731580694987U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 41U)) + 17060419646421271853U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aWandererA + RotL64(aIngress, 21U)) + 4128488893837059683U;
            aOrbiterD = (aWandererH + RotL64(aCross, 37U)) + 12706894827547160110U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 12506324593645825056U) + aNonceWordA;
            aOrbiterI = (aWandererK + RotL64(aIngress, 11U)) + 12581344490649250025U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 23U)) + 14357032418199130132U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 19U)) + 15341977701796331249U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 35U)) + 7086602307544733241U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 44U)) + RotL64(aCarry, 39U)) + 12398300065276832486U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2499745046076601988U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7249361592814001829U;
            aOrbiterH = RotL64((aOrbiterH * 14597139848072319685U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3254456186337366437U) + aNonceWordF;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 3472973415969046680U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 14583566953969168353U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7905718972111691591U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15941413652144021522U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3473779492962783565U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10583964125960308762U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13659925272340853715U;
            aOrbiterJ = RotL64((aOrbiterJ * 16708294803316630743U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9487054537489454887U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13287757570441887517U;
            aOrbiterA = RotL64((aOrbiterA * 17351439045329892107U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15279245465808571942U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12424999114621745879U;
            aOrbiterB = RotL64((aOrbiterB * 2274918760256527137U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13915392738892970475U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13797668053788805126U;
            aOrbiterF = RotL64((aOrbiterF * 13752161103680525317U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14344766585550401077U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13727554194373146727U;
            aOrbiterC = RotL64((aOrbiterC * 17164450431362670223U), 37U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 1332966642432651232U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 938583742533681467U;
            aOrbiterE = RotL64((aOrbiterE * 13323340043936037549U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5659239372701978244U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8501778564909302938U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 15629932660749672503U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1698500835332753591U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12029393034357490020U;
            aOrbiterK = RotL64((aOrbiterK * 18176507271635640153U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterI, 27U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterA, 60U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + aNonceWordC) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterB, 41U)) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterF, 38U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 47U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterH, 3U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 52U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // ingress from: aFireLaneA, pSnow
        // ingress directions: aFireLaneA forward forced, pSnow forward/backward random
        // cross from: aFireLaneA, mSource
        // cross directions: aFireLaneA backward forced, mSource backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 8443U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 8831U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6473U)) & S_BLOCK1], 40U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8558U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 47U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 53U)) + 9855743441035905047U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 58U)) + 8426286937143990276U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 23U)) + 7146752367170267002U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 12947210066678101726U) + aNonceWordG;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 29U)) + 15902163559925328965U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 8506649889346449469U;
            aOrbiterH = (aWandererG + RotL64(aCross, 5U)) + 8226286036430263052U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 35U)) + 2703047093452420216U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = ((aWandererH + RotL64(aCross, 56U)) + 6769351326360139560U) + aNonceWordH;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 9857025533281333281U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 19U)) + 238297452132277585U) + aNonceWordN;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7203572312072908931U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12497027346166575632U;
            aOrbiterB = RotL64((aOrbiterB * 1703586436725662307U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 473851890609048879U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1664484956453886047U;
            aOrbiterG = RotL64((aOrbiterG * 8566500756326590209U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4635095143004754116U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17695676150967345793U;
            aOrbiterA = RotL64((aOrbiterA * 5780416541584439301U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15628965269863402796U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9190117464399730235U;
            aOrbiterK = RotL64((aOrbiterK * 5586437438425999715U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17835918238346011086U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 4398005402429282682U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 14828737209913317463U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10902589938246551273U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15124274429081385923U;
            aOrbiterD = RotL64((aOrbiterD * 13524180348258805367U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8747233520702236018U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5445611443463112371U;
            aOrbiterJ = RotL64((aOrbiterJ * 10294109295823410447U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16296005217836151910U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6468336224317602364U;
            aOrbiterE = RotL64((aOrbiterE * 7369779919748367133U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3827976387089403774U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7773383658122100111U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 9784711300597525161U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 18273794621528918389U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8401424792700263455U;
            aOrbiterH = RotL64((aOrbiterH * 13003420427441089595U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11402828934846813949U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9855743441035905047U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7339549576423555273U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 48U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterI, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG + ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterK, 41U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 54U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 19U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterF, 37U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ) + aNonceWordO);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 24U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + aNonceWordL) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 39U)) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // ingress from: aFireLaneB, mSource
        // ingress directions: aFireLaneB forward forced, mSource forward/backward random
        // cross from: aFireLaneA, pSnow
        // cross directions: aFireLaneA backward forced, pSnow backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneB[((aIndex + 12065U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 12592U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13389U)) & S_BLOCK1], 39U) ^ RotL64(pSnow[((aIndex + 13737U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 4U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 15549114274303128055U) + aNonceWordM;
            aOrbiterB = ((aWandererE + RotL64(aCross, 51U)) + 16466750056388063241U) + aNonceWordH;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 12209449840836787142U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 27U)) + 14551496099734294336U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 39U)) + 6266576428679808622U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 48U)) + 16892841575635668152U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 19U)) + 7375966221423362125U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 53U)) + 11926105302821753530U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 41U)) + 16219253791550461124U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 14U)) + RotL64(aCarry, 13U)) + 7299056065319248160U) + aNonceWordC;
            aOrbiterK = (aWandererF + RotL64(aIngress, 11U)) + 15234001484933728439U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6615802589932632120U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5481176858895819247U;
            aOrbiterI = RotL64((aOrbiterI * 3604590158551984877U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17220507586542139380U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14137921473739415340U;
            aOrbiterE = RotL64((aOrbiterE * 10634645686035907603U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16981960446540932787U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10897565927079518588U;
            aOrbiterJ = RotL64((aOrbiterJ * 418843936329303571U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2746889569299593263U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4894117146736361379U;
            aOrbiterB = RotL64((aOrbiterB * 2656750612042673191U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18294823016957137777U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 86828501068883383U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11432686669235402365U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 6322053762209547826U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6754524552483363820U;
            aOrbiterD = RotL64((aOrbiterD * 1746163087826694641U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7306452650619361017U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12717201204443785828U;
            aOrbiterA = RotL64((aOrbiterA * 6121251603905574991U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10422327053543898585U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14786413282036348183U;
            aOrbiterC = RotL64((aOrbiterC * 8713024293107068275U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4599182534559908397U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5080179685914177581U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14984675846207762951U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6527649204956325409U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8327234966110052920U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9343969092668123661U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7845497893651522069U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15549114274303128055U;
            aOrbiterK = RotL64((aOrbiterK * 15263427406359082909U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 21U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 53U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 46U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 28U)) + aOrbiterG) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 14U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 38U) + aOrbiterF) + RotL64(aOrbiterI, 23U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 42U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 48U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // ingress from: aExpandLaneA, pSnow, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, pSnow forward forced, aFireLaneA forward/backward random
        // cross from: mSource, aFireLaneB
        // cross directions: mSource backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20798U)) & S_BLOCK1], 60U) ^ RotL64(pSnow[((aIndex + 20830U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17505U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 17999U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20758U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 38U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (aWandererC + RotL64(aScatter, 56U)) + 16124889768301047791U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 11912338587186717280U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 8594012868813114354U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 29U)) + 18281043566156682815U) + aNonceWordH;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 16853106130200942302U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 37U)) + 2611212958619673086U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 3U)) + 18039472325066855180U) + aNonceWordK;
            aOrbiterG = (aWandererF + RotL64(aCross, 60U)) + 14495785571345122046U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 19U)) + 4556063793412832418U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 21U)) + 14896419970271244358U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 51U)) + 880028529183500036U) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2379557167489415783U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11854373946064529806U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 150755294320438887U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1487252775956449964U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12777924204511625545U;
            aOrbiterE = RotL64((aOrbiterE * 1366019527386994789U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15998631485222477969U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8864212892296191613U;
            aOrbiterK = RotL64((aOrbiterK * 579242788050369815U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17069347835763226743U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7443008171694679791U;
            aOrbiterJ = RotL64((aOrbiterJ * 748894368884566607U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 17334256152350782002U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8986626119086556393U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2258172145924120235U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8528180968228358674U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12702290928064582589U;
            aOrbiterD = RotL64((aOrbiterD * 15673603224146737631U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7742438100860023610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3729687240959702198U;
            aOrbiterA = RotL64((aOrbiterA * 3756794766163746783U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 426129097367382096U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16782175452274911213U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1041477289638333659U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5942016166948841079U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5260815086125551703U;
            aOrbiterG = RotL64((aOrbiterG * 1603799103692438147U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11732742583346900772U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17182924380693084401U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 14858685629471497071U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8539335803784852017U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16124889768301047791U;
            aOrbiterF = RotL64((aOrbiterF * 6607245691919237755U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 41U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 18U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA + ((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 35U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 52U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // ingress from: aExpandLaneB, mSource, pSnow, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, mSource forward forced, pSnow forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22605U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 23526U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(pSnow[((aIndex + 24274U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneA[((aIndex + 25933U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26882U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26138U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 26U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 11U)) + 13174219512651137892U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 19U)) + 2715455762789269341U) + aNonceWordH;
            aOrbiterD = ((aWandererH + RotL64(aCross, 41U)) + 1338018183235594313U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aIngress, 22U)) + RotL64(aCarry, 43U)) + 16566866551729552930U) + aNonceWordA;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 6901845297307236726U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 2476078302049201718U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 43U)) + 15531109473927052260U) + aNonceWordE;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 5U)) + 4087849380858572351U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 38U)) + 5167830630098599644U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 51U)) + 7275995452428627217U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 13U)) + 14794340370010024117U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8509217403041662849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2321522025240806996U;
            aOrbiterD = RotL64((aOrbiterD * 113568101672878697U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5676672952755594051U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2304681269233504384U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15731441084605554497U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8383399721062437300U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13181984036942227666U;
            aOrbiterH = RotL64((aOrbiterH * 1648761328771932069U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13602604532551684210U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12725687663616352843U;
            aOrbiterB = RotL64((aOrbiterB * 4684699861686199753U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5831790822416009806U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4535048543735457407U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12076777878870257053U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10617608605149381858U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5244225377862618630U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 15307177251167023999U), 37U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 18229989093139888456U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9728120630096192811U;
            aOrbiterA = RotL64((aOrbiterA * 16052574428163231023U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1312233443099767304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8043115602160128619U;
            aOrbiterF = RotL64((aOrbiterF * 9365756845731616963U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4679339316686216023U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 211799535650113758U;
            aOrbiterC = RotL64((aOrbiterC * 1478368466990144107U), 41U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 13307123762743628190U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7093673238704478497U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 13273906568866802561U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16396459072175632290U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13174219512651137892U;
            aOrbiterE = RotL64((aOrbiterE * 7581008806810219369U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 34U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 24U) + aOrbiterK) + RotL64(aOrbiterH, 11U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterG, 24U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterE, 51U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 43U));
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 46U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterF) + aNonceWordK);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + aNonceWordL) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 39U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, mSource, pSnow, aFireLaneB
        // cross directions: aExpandLaneB backward forced, mSource backward forced, pSnow backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29677U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 27860U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 28033U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27659U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31384U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 32319U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28622U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 58U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 18255347001097480328U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 21U)) + 13679246790311505735U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 37U)) + 10565839529765027116U) + aNonceWordJ;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 14327172566224769901U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 29U)) + 16239024612038195174U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 56U)) + 13800012174212131890U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 35U)) + 13900288860157577583U) + aNonceWordP;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 4144386119777112740U) + aNonceWordI;
            aOrbiterD = (aWandererH + RotL64(aIngress, 41U)) + 3154558262670631372U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 54U)) + 7456728543137614001U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 3U)) + 11709519851158935384U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15607438907832240304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9276575329661725624U;
            aOrbiterF = RotL64((aOrbiterF * 8879744070762412745U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6459435969129449226U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6442382118416542275U;
            aOrbiterK = RotL64((aOrbiterK * 2921027306686588233U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12117432107282150865U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6831279293184793243U;
            aOrbiterB = RotL64((aOrbiterB * 2435360641135249073U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 9520022957804572889U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8322178689474588679U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1627707191467537115U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4162401591586869316U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8994015844714895961U;
            aOrbiterE = RotL64((aOrbiterE * 15421910378057951895U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10038095909727959633U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17756404450592957616U;
            aOrbiterJ = RotL64((aOrbiterJ * 14255952184627347295U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3379089265413427719U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11341713098678108441U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 2500587373161411961U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4030296130743454165U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6332387792111212064U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 16490982218150897861U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14893209417387662133U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9265457389326311687U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9778404505547862689U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13496086915199406901U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14576555328710787951U;
            aOrbiterA = RotL64((aOrbiterA * 13155395071667672943U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11482324648071976743U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18255347001097480328U;
            aOrbiterI = RotL64((aOrbiterI * 10918514878283385643U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 56U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 24U));
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 43U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 29U)) + aNonceWordN);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 46U)) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 39U)) + aOrbiterE) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterI, 21U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 53U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 35U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_A_A kdf_a_loop_a (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltA = pDomainSaltSet->mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltB = pDomainSaltSet->mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltC = pDomainSaltSet->mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltD = pDomainSaltSet->mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltE = pDomainSaltSet->mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltF = pDomainSaltSet->mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltA = pDomainSaltSet->mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltB = pDomainSaltSet->mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltC = pDomainSaltSet->mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltD = pDomainSaltSet->mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltE = pDomainSaltSet->mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltF = pDomainSaltSet->mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltA = pDomainSaltSet->mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltB = pDomainSaltSet->mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltC = pDomainSaltSet->mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltD = pDomainSaltSet->mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltE = pDomainSaltSet->mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltF = pDomainSaltSet->mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCDED4EB7F27E4665ULL + 0xC2E1375092C5178AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA15AADADCAC3726DULL + 0xE170FAC00C1CFB6FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD3F013F3AE77B9D1ULL + 0xDB8865E95EE12F94ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB2A8CED66EA17C63ULL + 0xEB03B7FE20D4F091ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBEAED8EEB421A2AFULL + 0x8DCF9B2831F901A0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBE49BE753F19F163ULL + 0xA09E9D210200948BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE7E8B1647BBFFCA7ULL + 0x89B7A370E2BD0CCFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB4DD6D9AE94FAA55ULL + 0xC4C5417A173817CAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8841115577D3810BULL + 0xD2B794F98E11862AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFB214FD27367E6A5ULL + 0xFDE7F040665B23A2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x93B8DCB1429EA29DULL + 0xF255EC6E7173E325ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD55AD730F1469835ULL + 0xD9289496C7D675C8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE069A0D4F2A598CFULL + 0xA9D814D1F41B3FFAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAD05E9786A493925ULL + 0xC2125A6AA7ADC081ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x81083A5FDF30538DULL + 0x9C5171252D9D37F2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9956F4B0E92B3E53ULL + 0xE25CAEE546637FB9ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_A_B kdf_a_loop_b (start)
    {
        // KDF_A_B kdf_a_loop_b lane group
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aFireLaneC, aFireLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aFireLaneC, aFireLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_a_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneA[((aIndex + 733U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 2337U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 216U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4787U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 19U)) + 3236820517816085022U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 52U)) + RotL64(aCarry, 53U)) + 741288875914097926U;
            aOrbiterH = (aWandererI + RotL64(aCross, 39U)) + 8417246926007729580U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 3U)) + 9715717805774537170U) + aNonceWordP;
            aOrbiterK = ((((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 14360243844821619482U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aWandererA + RotL64(aScatter, 47U)) + 10760908100206775334U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 35U)) + 3434641779946167811U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 10U)) + RotL64(aCarry, 39U)) + 7885568822756234567U;
            aOrbiterE = (aWandererH + RotL64(aCross, 27U)) + 3041563437672051294U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15761355327564963516U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1158633562785937421U;
            aOrbiterH = RotL64((aOrbiterH * 15511324886867188235U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9338581575871970653U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9172038894262857354U;
            aOrbiterB = RotL64((aOrbiterB * 3110871165285625807U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14653924713599790081U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3854497592598563309U;
            aOrbiterD = RotL64((aOrbiterD * 11737111068815795303U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16286980180327600557U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5092583772591249756U;
            aOrbiterA = RotL64((aOrbiterA * 13955105624639442903U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4288397994175567333U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15584236478994873104U;
            aOrbiterJ = RotL64((aOrbiterJ * 1860480595862755379U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5557463939827483792U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 2659814275753280856U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 17702430405693184643U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6941807963525063449U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 2040598555191211307U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 14750544987531722765U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 347572666231116258U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 779304821185302523U;
            aOrbiterF = RotL64((aOrbiterF * 14180254150318109855U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10632524582873079742U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9761308771280517212U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13926235411726048921U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (RotL64(aOrbiterE, 18U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterE, 11U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 26U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterE, 39U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + aNonceWordM) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 48U) + aOrbiterB) + RotL64(aOrbiterI, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 34U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 2
        // ingress from: aFireLaneC, aExpandLaneB, aExpandLaneC
        // ingress directions: aFireLaneC forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 5909U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 9851U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6348U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7390U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8574U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 19U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = ((aWandererF + RotL64(aIngress, 14U)) + RotL64(aCarry, 53U)) + 18191288703716505885U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 41U)) + 9824014524910417136U) + aNonceWordI;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 11953012029254917548U) + aNonceWordG;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 6297568011027199089U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 34U)) + 2576999400457367975U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 27U)) + 13176139160575558254U) + aNonceWordP;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 47U)) + 9978408174563621810U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererH + RotL64(aCross, 53U)) + 16765834875061607142U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 5U)) + 16534507305459121344U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3114710944346151807U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10240517868726718592U;
            aOrbiterC = RotL64((aOrbiterC * 4645691562915606463U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10721450637990777883U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16689590768796583952U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3046344179729901637U), 21U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 2427422768928450209U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 13495584061816457831U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6670984773768885119U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7058636403765106682U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9897341853944713767U;
            aOrbiterI = RotL64((aOrbiterI * 14286816859999869231U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17749559755733386064U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12515645083926326659U;
            aOrbiterK = RotL64((aOrbiterK * 6582878478865838245U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2625692458813609962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10596240255026143019U;
            aOrbiterH = RotL64((aOrbiterH * 11605800195771080135U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12374290338067865540U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1507386663796330249U;
            aOrbiterJ = RotL64((aOrbiterJ * 1210241080424446087U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9288099549484146726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15159312464747000702U;
            aOrbiterG = RotL64((aOrbiterG * 500055502081347757U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14998608679505446229U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17625038109437732009U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 14785862243019841689U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 14U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 23U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 18U) + RotL64(aOrbiterD, 39U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterC, 43U)) + aNonceWordM) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterG, 3U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 18U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 3
        // ingress from: aFireLaneD, aExpandLaneD, aExpandLaneC
        // ingress directions: aFireLaneD forward forced, aExpandLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 13459U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 13132U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 11201U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11970U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((aIndex + 16168U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 58U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (aWandererD + RotL64(aScatter, 51U)) + 2786079456995203065U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 5U)) + 7237256119153857253U) + aNonceWordM;
            aOrbiterA = ((aWandererG + RotL64(aCross, 10U)) + 9310834010563647604U) + aNonceWordG;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 47U)) + 17361734905706517877U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 43U)) + 15837111231884647451U) + aNonceWordF;
            aOrbiterB = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 18065431964418026445U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 3029123922999952652U;
            aOrbiterK = ((((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 5166926595573507837U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 28U)) + 1918425684273807598U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4724551751012661440U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1818014487579644390U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14904092108647864911U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6670090372241084216U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8485757110007268693U;
            aOrbiterD = RotL64((aOrbiterD * 11876760095108618363U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4928130251509514742U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2528788422725346792U;
            aOrbiterG = RotL64((aOrbiterG * 1855982047967756661U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2860387120895147503U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12927802338151379368U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8876144125458603029U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18029699867733207083U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13361836994951253312U;
            aOrbiterF = RotL64((aOrbiterF * 5349767426256597073U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11957294454794128079U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 3755417922063414648U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 13896364063651241401U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18001157153447913032U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16214145724690286854U;
            aOrbiterB = RotL64((aOrbiterB * 5874139687703360515U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3860958772090975562U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 12395621524459640173U) ^ aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 722817135977510161U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 3402035664910754484U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2139099117325745602U;
            aOrbiterC = RotL64((aOrbiterC * 14008983756425796029U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 46U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 41U) + RotL64(aOrbiterF, 37U)) + aOrbiterC) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 23U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 57U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 42U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 4
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20094U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 20248U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21079U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20864U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 19783U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 38U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 8367680518550579791U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 11491674725611181241U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 23U)) + 16673861720782164214U;
            aOrbiterE = (aWandererA + RotL64(aCross, 5U)) + 9786610124108350855U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 46U)) + 5745080601557577637U;
            aOrbiterH = (((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 1959402215131684684U) + aNonceWordE;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 35U)) + 6121650036079196522U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 19U)) + 12016309761037342392U) + aNonceWordD;
            aOrbiterG = (aWandererH + RotL64(aScatter, 30U)) + 5986936646177049603U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1000367700904043468U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 17425288243569101032U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2174614006719048535U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4856917474950325209U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16312111093223166419U;
            aOrbiterB = RotL64((aOrbiterB * 11046477664487805241U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 456110002032422270U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11393724374787795662U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 1176984359123668389U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8378176867715697176U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8086186452345234815U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8450438271765985235U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8470349167474173245U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2528229938740192694U;
            aOrbiterD = RotL64((aOrbiterD * 8717790851266520943U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13247168811545753141U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8745293957516815264U;
            aOrbiterH = RotL64((aOrbiterH * 14270617180621072619U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6165915500564961987U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12015407798844173213U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3913451986559154153U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 545006684939922156U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16366753936267185001U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 6495185976430013201U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3097605623436091728U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15950167830259022926U;
            aOrbiterG = RotL64((aOrbiterG * 4415538963984293323U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 54U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 48U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 27U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 18U) + aOrbiterA) + RotL64(aOrbiterD, 5U));
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterC, 43U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterD, 13U));
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 21U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 58U)) + aOrbiterE) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 5
        // ingress from: aOperationLaneB, aFireLaneD
        // ingress directions: aOperationLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneA
        // cross directions: aOperationLaneA backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aOperationLaneB[((aIndex + 23480U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27151U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23534U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24702U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (aWandererA + RotL64(aIngress, 57U)) + 18302975933754610273U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 43U)) + 16736972646771456082U;
            aOrbiterD = (aWandererB + RotL64(aCross, 14U)) + 17389406266488137442U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 19U)) + 5252511566486165539U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 51U)) + 5730715427422747640U) + aNonceWordO;
            aOrbiterF = ((((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 6412695646456045825U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 9539701605708994494U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 34U)) + 18355107116412945722U;
            aOrbiterJ = ((((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 11735742491750132942U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12363819388562658842U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5861430292304371543U;
            aOrbiterD = RotL64((aOrbiterD * 12989055611235382695U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15027487084595017708U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7012850020745791926U;
            aOrbiterA = RotL64((aOrbiterA * 15952928839355613939U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11904871669287886120U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 11199760114477343208U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 7156374911847525867U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3856004502263742700U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3705931243173921893U;
            aOrbiterK = RotL64((aOrbiterK * 10334871178498711485U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12305785390539209389U) + aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 18057980996551978823U;
            aOrbiterB = RotL64((aOrbiterB * 4850564181113470859U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3229431819292153014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2994716629242460094U;
            aOrbiterJ = RotL64((aOrbiterJ * 1029427328395257917U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9796307843453735512U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2957260393651252432U;
            aOrbiterF = RotL64((aOrbiterF * 7261055869794739609U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4060469664218866340U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17462081697889685330U;
            aOrbiterC = RotL64((aOrbiterC * 7712009170974461225U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 13638660073917821172U) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15202349592659062565U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4514326257446024301U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 34U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterA, 30U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 43U)) + aOrbiterB) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aCross, 28U) + RotL64(aOrbiterF, 26U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + aNonceWordN);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 6
        // ingress from: aOperationLaneC, aOperationLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aOperationLaneC[((aIndex + 27413U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30905U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31744U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 32029U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 34U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 29U)) + 8988572360732005217U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 17889613225105985335U;
            aOrbiterJ = ((((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 15563478320513948626U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererH + RotL64(aIngress, 3U)) + 3441351228410524816U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 27U)) + 4425592689451435346U) + aNonceWordE;
            aOrbiterD = (aWandererA + RotL64(aIngress, 51U)) + 12733160231627305928U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 47U)) + 3574152157304607854U) + aNonceWordF;
            aOrbiterH = ((aWandererD + RotL64(aCross, 38U)) + 15167631896729808783U) + aNonceWordN;
            aOrbiterE = (aWandererC + RotL64(aIngress, 19U)) + 15822667973915417055U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 17181685481076577637U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9979204751408873468U;
            aOrbiterJ = RotL64((aOrbiterJ * 8244434774754786565U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1334240485667164762U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9190066751460137016U;
            aOrbiterG = RotL64((aOrbiterG * 14585141844653660363U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15465215829109246336U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2305208282453624419U;
            aOrbiterB = RotL64((aOrbiterB * 10257861974108363283U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16951510027310993926U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11117938943423526901U;
            aOrbiterD = RotL64((aOrbiterD * 7805486716716924787U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12461379120662979432U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11719697049048823897U;
            aOrbiterH = RotL64((aOrbiterH * 14880996802304818757U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6843357278142933570U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12727898578324702374U;
            aOrbiterI = RotL64((aOrbiterI * 9786435451654365097U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 18127999660067652233U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11754709060558683082U;
            aOrbiterE = RotL64((aOrbiterE * 12798744012150745847U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16940151146420516184U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12924950783056761895U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 8898170377271926745U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14829713915929878471U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 840466047621042565U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 10748511630509529489U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 30U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterD, 37U)) + aNonceWordI);
            aWandererG = aWandererG + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 23U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + aNonceWordH);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterF, 60U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + aNonceWordK);
            aWandererC = aWandererC + ((((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 24U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_A_B kdf_a_loop_b (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltA = pDomainSaltSet->mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltB = pDomainSaltSet->mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltC = pDomainSaltSet->mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltD = pDomainSaltSet->mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltE = pDomainSaltSet->mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltF = pDomainSaltSet->mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltA = pDomainSaltSet->mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltB = pDomainSaltSet->mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltC = pDomainSaltSet->mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltD = pDomainSaltSet->mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltE = pDomainSaltSet->mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltF = pDomainSaltSet->mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltA = pDomainSaltSet->mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltB = pDomainSaltSet->mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltC = pDomainSaltSet->mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltD = pDomainSaltSet->mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltE = pDomainSaltSet->mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltF = pDomainSaltSet->mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE7009D3947483F97ULL + 0xD28AC46BE97D3322ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF09AEF1641B095A3ULL + 0xEC18A592E7DC63AFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFA0EC5B405874F83ULL + 0xA50FAD1EB87F6FC3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8578DC561A0EB87FULL + 0xA1DBD154292D25F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF92014BE4D460D87ULL + 0xB6EF6DC35F69F4FFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAB49C2648532C19FULL + 0xB272395BA8657290ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB3113F62FF682CCDULL + 0x88F1B0509F272381ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF377EBAFCC4EEE8BULL + 0xDBF023F23F92881CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x83545DF1AEAFD377ULL + 0xFBDF6A7CB13F57A9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB1604D057472A8CDULL + 0xC9D8F4AB21A748D5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9C028DE911196981ULL + 0xC8AF8C9FC2228C7BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC296F23411877401ULL + 0xF12131E039A88A9BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE1A36A045B468923ULL + 0xF99B4641196B0D9CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEF75DE0487ED4AE1ULL + 0x80367F8471C3214DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9DD4ACD11CF4BE9FULL + 0xE2F146E8D1BA45D6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCDA993CEBC7A7A23ULL + 0xD08C5CC74FF201AAULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_A_C kdf_a_loop_c (start)
    {
        // KDF_A_C kdf_a_loop_c lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2700U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 3495U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7833U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8169U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8018U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5367U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 60U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 7948891781097675369U) + aNonceWordG;
            aOrbiterK = ((((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 13928362874228230226U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 50U)) + 10776180542602258926U) + aNonceWordH;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 5735115172149470447U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 29U)) + 5353591822981766987U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 562301708107268570U) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10467810247578364868U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10449089554007059823U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14541630141152308564U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2350076897065139429U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12222554362482034393U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17519109078651162228U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6061035173339902910U;
            aOrbiterD = RotL64((aOrbiterD * 10021905773432907835U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15654836633731000065U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13723521735153718904U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 14459516479283070563U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2849680038315532197U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17336102435576647923U;
            aOrbiterJ = RotL64((aOrbiterJ * 10984689101753586739U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 18U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 58U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 58U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13248U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((aIndex + 15702U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 11367U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9970U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8227U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12622U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12582U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 13296600294247799698U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 5818503518080877515U) + aNonceWordK;
            aOrbiterE = ((aWandererK + RotL64(aCross, 47U)) + 6735784238734173597U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((((aWandererJ + RotL64(aScatter, 22U)) + RotL64(aCarry, 13U)) + 7368398209488856201U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aWandererE + RotL64(aIngress, 3U)) + 961734029066455638U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 797011946660892011U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 12841876018396622350U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 14056540056414153277U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16213253970483895623U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15186950557113470375U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4647470430467908107U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5117930310827477341U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12265429373166094162U;
            aOrbiterA = RotL64((aOrbiterA * 1522823535151532249U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13920531346698601568U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14695405206998211456U;
            aOrbiterJ = RotL64((aOrbiterJ * 13950964363414164279U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 7851960904825938443U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9501511171732550190U;
            aOrbiterF = RotL64((aOrbiterF * 5614164120361489613U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 22U) + RotL64(aOrbiterE, 35U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 58U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + aNonceWordA);
            aWandererC = aWandererC + ((((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 19U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneC, aExpandLaneB
        // cross directions: aWorkLaneA backward forced, aOperationLaneC backward forced, aExpandLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21124U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 19685U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 18285U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19630U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17597U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21544U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19401U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 47U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 13U)) + 9107326720193244489U) + aNonceWordL;
            aOrbiterG = (aWandererA + RotL64(aIngress, 4U)) + 10868585484401664145U;
            aOrbiterA = ((((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 13637736741437846622U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 6130725216183918844U) + aNonceWordG;
            aOrbiterI = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 2063834478521338187U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8564870627911949158U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6524015751064086390U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 12055267995727104463U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9874937766875388236U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14723718409522680894U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17379140128833323431U), 43U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 13767059954741528279U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 6387608251033722169U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 6601902195707980693U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5391425980008431000U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11524218415655093779U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12508457981779189389U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 155510463350385905U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10554591788433641311U;
            aOrbiterI = RotL64((aOrbiterI * 5412084824127934293U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 22U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterA) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 50U)) + aOrbiterG) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 19U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterH, 29U)) + aNonceWordN) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 14U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26361U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 28994U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27866U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26686U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30319U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32204U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27105U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 57U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 13278949403988203974U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 51U)) + 9213599924054673756U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aIngress, 22U)) + RotL64(aCarry, 35U)) + 1255746482932381798U) + aNonceWordM;
            aOrbiterD = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 11575321997144516122U) + aNonceWordJ;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 41U)) + 15881587525529432437U) + aNonceWordO;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9846195809864862707U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12319815691858217670U;
            aOrbiterC = RotL64((aOrbiterC * 14271546305640811091U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16322617427294439587U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 16332130810525887437U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 7588076439690559343U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4920951156015336794U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16767126455124552329U;
            aOrbiterA = RotL64((aOrbiterA * 4440352337076842603U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12553595911087945223U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 1437522202135436142U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2001992794165550905U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12313100454852227143U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2761983020631055729U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3874839760378039509U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 5U)) + aOrbiterC) + aNonceWordP) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterA, 39U));
            aWandererB = aWandererB + (((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterA, 56U)) + aNonceWordF);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 23U)) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_A_C kdf_a_loop_c (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltA = pDomainSaltSet->mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltB = pDomainSaltSet->mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltC = pDomainSaltSet->mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltD = pDomainSaltSet->mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltE = pDomainSaltSet->mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltF = pDomainSaltSet->mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltA = pDomainSaltSet->mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltB = pDomainSaltSet->mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltC = pDomainSaltSet->mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltD = pDomainSaltSet->mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltE = pDomainSaltSet->mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltF = pDomainSaltSet->mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltA = pDomainSaltSet->mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltB = pDomainSaltSet->mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltC = pDomainSaltSet->mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltD = pDomainSaltSet->mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltE = pDomainSaltSet->mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltF = pDomainSaltSet->mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD9E932F343129679ULL + 0xF3607D17027EBE3EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x972C6AF0B3C8A669ULL + 0x833B4D35B2A6B117ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD25800DB9AFA12D1ULL + 0x883C50E2C689C5E4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC2E29F8384FCD307ULL + 0xEEC9AA3FB524F881ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB41AA312D2E44EEBULL + 0x908E8ABEA7589506ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDD83232423B9887FULL + 0xED35260C0CBB75BCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE7AED63564ECE17FULL + 0x9694B0223FD58B9FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBFDB36D78FDDFC4BULL + 0x8128271AC78BC17EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDDDEE8CA7AC94973ULL + 0xF4FBABFC6FAC5EF9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF7B54DFE9238B5FDULL + 0xC8558DC41619FC61ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF0F14D43DDA21DB3ULL + 0xCA04EA29664DDE40ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAD1289F6AB026C25ULL + 0xA116BEB37C0E2865ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB35FDAF9E682FF33ULL + 0xEB71D02FCA983648ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEF22D325AA83834BULL + 0xFF8C60938A39392BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD92E85EF9CE98387ULL + 0xB62DB0F375B47895ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB6077D1FACD09E13ULL + 0x82CDF4C926BEF6D7ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_A_D kdf_a_loop_d (start)
    {
        // KDF_A_D kdf_a_loop_d lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7375U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 1419U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2971U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4716U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3813U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 442U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 20U)) + (RotL64(aPrevious, 37U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (aWandererD + RotL64(aIngress, 21U)) + 15549114274303128055U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 29U)) + 16466750056388063241U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 5U)) + 12209449840836787142U) + aNonceWordJ;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 14551496099734294336U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 6266576428679808622U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (((aWandererF + RotL64(aScatter, 44U)) + RotL64(aCarry, 35U)) + 16892841575635668152U) + aNonceWordH;
            aOrbiterC = (aWandererI + RotL64(aCross, 11U)) + 7375966221423362125U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11926105302821753530U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16219253791550461124U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2117550758226173419U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7299056065319248160U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15234001484933728439U;
            aOrbiterF = RotL64((aOrbiterF * 8182244796017018911U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6615802589932632120U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5481176858895819247U;
            aOrbiterH = RotL64((aOrbiterH * 3604590158551984877U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17220507586542139380U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14137921473739415340U;
            aOrbiterC = RotL64((aOrbiterC * 10634645686035907603U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16981960446540932787U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10897565927079518588U;
            aOrbiterK = RotL64((aOrbiterK * 418843936329303571U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2746889569299593263U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4894117146736361379U;
            aOrbiterI = RotL64((aOrbiterI * 2656750612042673191U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18294823016957137777U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 86828501068883383U) ^ aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11432686669235402365U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterF, 21U)) + aNonceWordL) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 60U)) + aOrbiterH) + aNonceWordK);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterK, 51U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterK, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 39U)) + aOrbiterC) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererC, 26U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12935U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 9825U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 16356U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15109U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9783U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11568U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11931U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 36U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 18087125778766689269U) + aNonceWordJ;
            aOrbiterD = (aWandererC + RotL64(aCross, 13U)) + 13710545066503235196U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 1701939704736254645U) + aNonceWordL;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 8064093611384019909U) + aNonceWordD;
            aOrbiterF = (aWandererF + RotL64(aIngress, 28U)) + 16623332751533885431U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 47U)) + 15590129153794910109U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aCross, 3U)) + 7413312683079107383U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4186064478651458810U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5501191643940735954U;
            aOrbiterI = RotL64((aOrbiterI * 14254804649177125269U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11064645242200570835U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13825922087298055833U;
            aOrbiterF = RotL64((aOrbiterF * 7529317892716108867U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5944980709887369970U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8181136916070569646U;
            aOrbiterJ = RotL64((aOrbiterJ * 395183021205661827U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15442336949157292482U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11580554435240641337U;
            aOrbiterA = RotL64((aOrbiterA * 6654637892858767739U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11240018128174598322U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2027565596050777471U;
            aOrbiterB = RotL64((aOrbiterB * 18048186560314431815U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16425887196883725233U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16828683527588834095U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 17746289103235902485U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9923829146479008804U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6669171007279929454U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 681823450939955099U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterI, 12U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + aNonceWordP) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + aNonceWordM);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneA, aExpandLaneB, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneC, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23417U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((aIndex + 24183U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 23108U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 23517U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16557U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18259U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 20990U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 43U)) + 3238389262925516513U) + aNonceWordD;
            aOrbiterD = ((((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 12381787182611386995U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 23U)) + 7883885539305181549U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 1185413044597727092U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 11U)) + 15219353497204773135U) + aNonceWordC;
            aOrbiterK = ((aWandererI + RotL64(aCross, 37U)) + 7533774715626734082U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 29U)) + 2599930450937763464U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 16074720663961214284U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15483613196360051221U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 11717479088020532861U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9396557867081376268U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9668459976852660245U;
            aOrbiterK = RotL64((aOrbiterK * 11748505665890567063U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9037269914643207212U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16936742640861088240U;
            aOrbiterF = RotL64((aOrbiterF * 1040172193161012227U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 16481274825758546398U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 481851372837611166U;
            aOrbiterD = RotL64((aOrbiterD * 2225030139210599207U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13608921517203544108U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16930740723286214636U;
            aOrbiterH = RotL64((aOrbiterH * 2605108503821980865U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 902242902582149908U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1510861213079342977U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3309753895727400707U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7116243600304980310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6631412278359709602U;
            aOrbiterG = RotL64((aOrbiterG * 11452627691392637463U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterF, 29U));
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + aNonceWordL);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterG, 18U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + aNonceWordG) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneD, aOperationLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneB, aOperationLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26011U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 30685U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 30493U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32638U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30065U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25918U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 26242U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 48U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = (((aWandererC + RotL64(aScatter, 5U)) + 13204735390996728477U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererF + RotL64(aCross, 41U)) + 851171359595647173U) + aNonceWordP;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 16745304202825290723U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 20U)) + 562392736584913979U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 3244267012529053918U) + aNonceWordA;
            aOrbiterK = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 17282536111067869133U) + aNonceWordO;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 27U)) + 14851130066471729068U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5256130407952363129U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2904742485828362001U;
            aOrbiterC = RotL64((aOrbiterC * 12941135856735075457U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3723346325449225387U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5344621093694027341U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 9044881458629673499U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 12919263300833603026U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17989801264160996071U;
            aOrbiterG = RotL64((aOrbiterG * 15468293047311883751U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5022175042377172157U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16684822380107847758U;
            aOrbiterA = RotL64((aOrbiterA * 2834049270263837537U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2740326510600876682U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13981423865219318820U;
            aOrbiterK = RotL64((aOrbiterK * 14593082145080056441U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 231945878229848395U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14139797734944312580U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6492256080432266407U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16704102101387552373U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8506734780526852552U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4684566118627414659U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 37U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 23U) + RotL64(aOrbiterA, 3U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 60U)) + aOrbiterB) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererK, 44U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_A_D kdf_a_loop_d (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltA = pDomainSaltSet->mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltB = pDomainSaltSet->mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltC = pDomainSaltSet->mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltD = pDomainSaltSet->mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltE = pDomainSaltSet->mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltF = pDomainSaltSet->mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltA = pDomainSaltSet->mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltB = pDomainSaltSet->mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltC = pDomainSaltSet->mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltD = pDomainSaltSet->mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltE = pDomainSaltSet->mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltF = pDomainSaltSet->mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltA = pDomainSaltSet->mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltB = pDomainSaltSet->mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltC = pDomainSaltSet->mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltD = pDomainSaltSet->mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltE = pDomainSaltSet->mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltF = pDomainSaltSet->mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCCBD2274F172F0F7ULL + 0xF325BCA10FBAEC9EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEAAA3D0BD639CA41ULL + 0xE2A708E2ACF8FC20ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB512353BA27C0933ULL + 0xE534B6256B2F7A0CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x888FAF8398B23629ULL + 0xF4F2B9823F817EF1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFD9977033FA6AFDFULL + 0xC6809455E9C2CCD5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBDA8976789C53B49ULL + 0x8D223885CD4ED1F4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFC398AE11EE5A639ULL + 0xC89029A3A18F86FCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA3E8284F73DE534DULL + 0x8DDF0AADCB4E99F5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF999566F1F46E151ULL + 0xE53084FC71B56F67ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC7486BCA7DC630F1ULL + 0x8DCDFDBCAA72A5D9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEECEF8AA7A6C00D3ULL + 0xE7F2A4940F749345ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBF54BCD76C66438FULL + 0x9C49B283C05D9568ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAC62B8F86626C96FULL + 0xC4CB711386846C0BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB8CA8D99453BA095ULL + 0xCBEC6F6ED08A9E71ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA1703766758EB97DULL + 0xB31CD184863C7BB7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x84F2D7540DEAF271ULL + 0xDC9A6159549FCCBFULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_B_A kdf_b_loop_a (start)
    {
        // KDF_B_A kdf_b_loop_a lane group
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aFireLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aExpandLaneA, aOperationLaneD, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 42U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 2402U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 2507U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3137U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5155U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 48U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 701291026547470433U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 13U)) + 17283292650462111643U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 27U)) + 9969124091931303406U) + aNonceWordA;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 41U)) + 889176772718046988U) + aNonceWordB;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 6U)) + 6054541844643748084U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 14703226235143028132U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 7977975878522921062U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16894322614172266274U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 12160451749345900570U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18055355572903901749U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10870847008043897470U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8159920947172520247U;
            aOrbiterG = RotL64((aOrbiterG * 4833194641611011805U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2440099120969517932U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2428396147731468007U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9363073341539598441U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 2213226274394673479U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7079731443427765333U;
            aOrbiterE = RotL64((aOrbiterE * 16918930776877030559U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 958896789550478970U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10788682955708075458U;
            aOrbiterC = RotL64((aOrbiterC * 913321215613559729U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2003386579317564870U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8419686358774204999U;
            aOrbiterK = RotL64((aOrbiterK * 6547052526438697621U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6989167615157578904U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 17636634003643824148U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 11038576417283732937U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterG, 30U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 13U)) + aOrbiterC) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aFireLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aFireLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aWorkLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 8966U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 7416U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6685U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5538U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7463U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7902U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 966899917801652720U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 10996327672320748649U) + aNonceWordJ;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 4188171566846621107U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 5U)) + 5886209243097387959U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 56U)) + 14940428957136728111U) + aNonceWordG;
            aOrbiterH = (aWandererG + RotL64(aCross, 11U)) + 179187285531914832U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 47U)) + 6685351948936817752U) + aNonceWordF;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1894506461704029700U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4182760368636977082U;
            aOrbiterD = RotL64((aOrbiterD * 972988091869133921U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12523318028514940790U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5059306166973366892U;
            aOrbiterC = RotL64((aOrbiterC * 2857409765717296483U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5890872367917643851U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17747338389865221534U;
            aOrbiterE = RotL64((aOrbiterE * 5306740664798049267U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13906227834259884100U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 7152105382899756368U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 6772157117358310485U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17868101884759619240U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11758843266314148347U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5919135169337501485U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13950566197090324859U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17278105609930477854U;
            aOrbiterH = RotL64((aOrbiterH * 11431842718945107359U), 27U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 9556785965646738355U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 841298436857932987U;
            aOrbiterA = RotL64((aOrbiterA * 15077843186688841797U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 34U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + aNonceWordP);
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 4U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 51U)) + aOrbiterA) + aNonceWordB) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aFireLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aFireLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aFireLaneA
        // cross directions: aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 15332U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 16377U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11502U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16216U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneA[((aIndex + 14303U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 44U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 29U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 24U)) + RotL64(aCarry, 41U)) + 10336802574069791273U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 13U)) + 169025388197058936U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 57U)) + 6541354188379168846U) + aNonceWordC;
            aOrbiterI = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 16223920526599306104U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 12756613707692514808U) + aNonceWordF;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 41U)) + 5082475548176484035U) + aNonceWordK;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 51U)) + 4907435526952698526U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14236627073831834337U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11502511046130497584U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3460330807286625917U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3679044835550219497U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11254838916686736746U;
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10582608424233200966U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10449735026385340313U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7363770199734997411U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4628253464169957835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17664454668473204465U;
            aOrbiterD = RotL64((aOrbiterD * 4234720298731378527U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3798386391743884889U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1379331161819246587U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 13086160171095077295U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 9816600392407327227U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16781971616348376878U;
            aOrbiterA = RotL64((aOrbiterA * 12503867584828289879U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4807797577690520554U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2492057261148595922U;
            aOrbiterF = RotL64((aOrbiterF * 9453302540675483005U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 13U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 27U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 51U)) + aOrbiterG);
            aWandererK = aWandererK + ((((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterD, 58U)) + RotL64(aCarry, 53U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aFireLaneB, aWorkLaneD
        // cross directions: aFireLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17830U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((aIndex + 18600U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 19462U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21111U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19886U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 1457104756581596530U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 6127240317844622874U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 21U)) + 16492290056044189421U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 10963676850938416468U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 12U)) + 4872917367399752405U) + aNonceWordN;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 27U)) + 15218882377875616148U) + aNonceWordL;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 35U)) + 5934166612122118251U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14215280930872003003U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11428034799044600979U;
            aOrbiterC = RotL64((aOrbiterC * 12162528943733976177U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5453003654321728726U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 14273775120265649389U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 5139018128323795309U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 328723770018440271U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13032190719588211088U;
            aOrbiterI = RotL64((aOrbiterI * 13363368478932798315U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2386881543033598494U) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1649501123340887116U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 11148976582360499033U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16462401546754210583U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1510579201823042227U;
            aOrbiterK = RotL64((aOrbiterK * 16287912400104043275U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6889066000014251983U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11324594596597724357U;
            aOrbiterH = RotL64((aOrbiterH * 15344987814648586023U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12237796033168436537U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17306069670330000343U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3167451351403385259U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + aNonceWordM);
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterC, 14U));
            aWandererI = aWandererI + (((((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 35U)) + aNonceWordG) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterA, 21U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 5
        // ingress from: aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneB[((aIndex + 23506U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25687U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24813U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 23817U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 5295352595333316211U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 2341795367042042605U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 29U)) + 10122175780504033663U) + aNonceWordB;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 10084612804696198554U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 50U)) + 16470424309851045971U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 41U)) + 656016130975227994U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 23U)) + 15313268829659834317U) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3795220914993923394U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14044442220988813825U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3270650852546606835U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3804224626734584802U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7980006306010255693U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13958505239726088561U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 13746830564584711549U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11852212099729274845U;
            aOrbiterB = RotL64((aOrbiterB * 2164880979318247855U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9083223471018084847U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13706723820703853346U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 11361854103656219887U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 1713819986642275223U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1382000168233902914U;
            aOrbiterJ = RotL64((aOrbiterJ * 3894160765130198157U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 4540474625764565485U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1756168174375757220U;
            aOrbiterF = RotL64((aOrbiterF * 12739160208010092017U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1409297070183609309U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6082750101445444357U;
            aOrbiterE = RotL64((aOrbiterE * 17438740230251860935U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 28U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 28U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterK, 41U)) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 47U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterE, 56U)) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 6
        // ingress from: aExpandLaneC, aExpandLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 31230U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 31807U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31107U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 32684U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 20U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 2225397913940961213U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 13U)) + 8342544893601343643U) + aNonceWordK;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 47U)) + 162922186381417187U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 11660218373710972210U) + aNonceWordL;
            aOrbiterA = (aWandererG + RotL64(aIngress, 53U)) + 14909034764605802354U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 60U)) + 16776955237009701511U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 5834487809188925253U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1498492772767040320U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 4161765458781579617U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15535994410289065281U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10511923076962447765U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8575954471692620021U;
            aOrbiterA = RotL64((aOrbiterA * 12526744988828982731U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6536325446331340573U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1790628986900286346U;
            aOrbiterD = RotL64((aOrbiterD * 5262997114200816715U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2623814807619278590U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11676970995834706612U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 10057461115132434901U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13836786354224256591U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6293096163612129260U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 8977954126326217153U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 4271144764978661248U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15938494256992560202U;
            aOrbiterJ = RotL64((aOrbiterJ * 10004841288382726739U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11038155227307702976U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12408749795071243930U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5527720475032868855U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterA, 35U)) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterD, 13U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 21U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 41U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aCross, 10U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_B_A kdf_b_loop_a (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltA = pDomainSaltSet->mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltB = pDomainSaltSet->mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltC = pDomainSaltSet->mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltD = pDomainSaltSet->mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltE = pDomainSaltSet->mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltF = pDomainSaltSet->mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltA = pDomainSaltSet->mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltB = pDomainSaltSet->mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltC = pDomainSaltSet->mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltD = pDomainSaltSet->mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltE = pDomainSaltSet->mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltF = pDomainSaltSet->mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltA = pDomainSaltSet->mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltB = pDomainSaltSet->mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltC = pDomainSaltSet->mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltD = pDomainSaltSet->mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltE = pDomainSaltSet->mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltF = pDomainSaltSet->mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCD1CC1CB1C5D0617ULL + 0xE92684E782BBF75EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF4D534FF74E73755ULL + 0xF24404B2549D1AE5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD494411B1484526BULL + 0xEA3CD106F1029F63ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF6B42BB146CC2BB1ULL + 0xD06B62D32E137CC4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEA560C248C466C89ULL + 0xA5FA3DAA6F830228ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x839E88DD2289A925ULL + 0xBEA4B4D37345ABC4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBA2CE8FA259520B9ULL + 0xD0C7C0A075941CCFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBE4662B2927C50E1ULL + 0xCE08CC09418A2743ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE4302F412EA0D74FULL + 0xB4017DC72DA7F84FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC4E1E66C60A393BBULL + 0xEE5CAD72E058B158ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x86776DE123C5625BULL + 0xBD582A71DCD29437ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9CC5CADC454110B1ULL + 0xE3C8C71C7A3A7F56ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8C5546CB1992A57FULL + 0xDA7424B1FE0611AFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDD5F715DB36D0EE3ULL + 0x8F492AB852430C98ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8191AEC5998D9219ULL + 0xF43CCC4FD60EFB1AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAD4808070468006FULL + 0xFF04CEC77A07EE6EULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_B_B kdf_b_loop_b (start)
    {
        // KDF_B_B kdf_b_loop_b lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aFireLaneC, aFireLaneD, aOperationLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6536U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 6418U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2940U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6943U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6269U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3110U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 47U)) ^ (RotL64(aIngress, 34U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 53U)) + 11177787645248006236U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 13U)) + 3808340254579817169U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 22U)) + RotL64(aCarry, 23U)) + 828030667598518279U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 47U)) + 16177835921238398371U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 3U)) + 5518747735458708741U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 35U)) + 17346319082399995165U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 28U)) + RotL64(aCarry, 13U)) + 6397156921893030937U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 15559381654710713582U) + aNonceWordF;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 11U)) + 940404446491415088U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 37U)) + 8047166032048732645U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 19U)) + 4688468645859470491U) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3710878044770337260U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 116343189456629220U;
            aOrbiterI = RotL64((aOrbiterI * 5637725064169289339U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 883908030159391659U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 18058691521694880482U;
            aOrbiterJ = RotL64((aOrbiterJ * 3132200449123497619U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17521015077103586117U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3668332225435714918U;
            aOrbiterF = RotL64((aOrbiterF * 12658899101297839881U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12229480388278883300U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16206524049491531816U;
            aOrbiterH = RotL64((aOrbiterH * 11122340196620859805U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5743265849441077466U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2812293020719282236U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8903956475200417109U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 13718364781538837074U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 861529717259766236U;
            aOrbiterC = RotL64((aOrbiterC * 17019744777211266685U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4862687502126693872U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7722024283321020761U;
            aOrbiterA = RotL64((aOrbiterA * 18086944039541060829U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8205803118233399853U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15130160926615050422U;
            aOrbiterB = RotL64((aOrbiterB * 1454552751453996765U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 667469191899263617U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18048970185163843471U;
            aOrbiterD = RotL64((aOrbiterD * 1800698970568737425U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 508102841337488721U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3803840516662727630U;
            aOrbiterG = RotL64((aOrbiterG * 8477778555284121637U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17055028117762299436U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11177787645248006236U;
            aOrbiterK = RotL64((aOrbiterK * 12457019014051206805U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 48U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterB, 53U)) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 43U)) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ) + aNonceWordO);
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterA, 26U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterE, 37U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 34U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13319U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 13054U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 14389U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((aIndex + 12290U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11443U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15069U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 11773U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 22U)) + (RotL64(aCross, 47U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 26U)) + 18319689184146942855U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 29U)) + 8041304130090501019U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 13U)) + 11347064191990897738U) + aNonceWordL;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 15242243470024447468U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 48U)) + RotL64(aCarry, 57U)) + 10619749107163611105U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 19U)) + 14795614276221947128U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 21U)) + 1578095288886372393U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 13593906305770501684U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 11U)) + 8919815528334599172U) + aNonceWordC;
            aOrbiterE = (aWandererD + RotL64(aScatter, 35U)) + 17425548324720065145U;
            aOrbiterH = (aWandererF + RotL64(aCross, 53U)) + 11125018338392347335U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3779189180734244399U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10958224663276134041U;
            aOrbiterG = RotL64((aOrbiterG * 6206963519509783781U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4317305352561612995U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4891139433808505355U;
            aOrbiterK = RotL64((aOrbiterK * 11507024985663120317U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5166074784835930965U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10080890270621589202U;
            aOrbiterJ = RotL64((aOrbiterJ * 13170894418184288695U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4501071771615514619U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6486573807774431753U;
            aOrbiterC = RotL64((aOrbiterC * 324029625116648669U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15714881857668975753U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3506619392820235900U;
            aOrbiterH = RotL64((aOrbiterH * 5707033870161224499U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5295711072762443783U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11192836530396570648U;
            aOrbiterI = RotL64((aOrbiterI * 4361810118382207039U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 7993389678399774574U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12551394763541226695U;
            aOrbiterF = RotL64((aOrbiterF * 11903486656172026403U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11553674370322129668U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4459881583199320245U;
            aOrbiterB = RotL64((aOrbiterB * 2805857426321555685U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3053507713574219459U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15458441755058850309U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7296609957819165877U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17429750026356459756U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17114614857181230304U;
            aOrbiterE = RotL64((aOrbiterE * 10541235280918902739U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8958993884028672039U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18319689184146942855U;
            aOrbiterD = RotL64((aOrbiterD * 5430881344386342703U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 58U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 44U)) + aOrbiterF) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterC, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aIngress, 48U) + RotL64(aOrbiterG, 41U)) + aOrbiterC) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterB, 51U)) + aNonceWordP);
            aWandererE = aWandererE + (((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 29U)) + aNonceWordJ) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterH, 57U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 6U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterI, 54U)) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererA, 54U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18722U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((aIndex + 19018U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 19475U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 21249U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21319U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21917U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 20245U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 36U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (aWandererG + RotL64(aIngress, 41U)) + 12029393034357490020U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 53U)) + 4526754731580694987U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 21U)) + 17060419646421271853U) + aNonceWordK;
            aOrbiterK = ((aWandererH + RotL64(aCross, 13U)) + 4128488893837059683U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 12706894827547160110U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 23U)) + 12506324593645825056U;
            aOrbiterE = (aWandererI + RotL64(aCross, 18U)) + 12581344490649250025U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 57U)) + 14357032418199130132U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 15341977701796331249U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 7086602307544733241U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 26U)) + 12398300065276832486U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2499745046076601988U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7249361592814001829U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14597139848072319685U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 3254456186337366437U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3472973415969046680U;
            aOrbiterB = RotL64((aOrbiterB * 14583566953969168353U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7905718972111691591U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15941413652144021522U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 3473779492962783565U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10583964125960308762U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 13659925272340853715U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16708294803316630743U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9487054537489454887U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13287757570441887517U;
            aOrbiterI = RotL64((aOrbiterI * 17351439045329892107U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15279245465808571942U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12424999114621745879U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2274918760256527137U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13915392738892970475U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13797668053788805126U;
            aOrbiterH = RotL64((aOrbiterH * 13752161103680525317U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14344766585550401077U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 13727554194373146727U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 17164450431362670223U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1332966642432651232U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 938583742533681467U;
            aOrbiterF = RotL64((aOrbiterF * 13323340043936037549U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5659239372701978244U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8501778564909302938U;
            aOrbiterC = RotL64((aOrbiterC * 15629932660749672503U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1698500835332753591U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12029393034357490020U;
            aOrbiterK = RotL64((aOrbiterK * 18176507271635640153U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 10U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 10U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterA, 5U));
            aWandererB = aWandererB + ((RotL64(aIngress, 46U) + RotL64(aOrbiterE, 27U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 54U)) + aOrbiterA) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + aNonceWordC);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterG, 41U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 57U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + aNonceWordA) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterK, 3U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 10U) + aOrbiterI) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aExpandLaneD, aWorkLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aExpandLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28492U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 29254U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 27490U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 26172U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28319U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28323U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30686U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 60U)) + 13442819395490639310U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 19U)) + 8187292523194120936U) + aNonceWordA;
            aOrbiterA = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 11469697159823131388U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 13414083692375929653U;
            aOrbiterE = (aWandererH + RotL64(aCross, 51U)) + 11404010733687907517U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 27U)) + 6783212827186218247U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 53U)) + 8561131439340372614U) + aNonceWordC;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 29U)) + 6252609642004429113U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 5U)) + 12804867444200448952U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 2739648749603690781U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 40U)) + 14808861217017399752U) + aNonceWordF;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 17588866502571268888U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5882260142735642980U;
            aOrbiterA = RotL64((aOrbiterA * 7688252946143263869U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15493099088132862949U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 5175647411532429582U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15226544495598541883U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14279707376173642767U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6826363572161275158U;
            aOrbiterJ = RotL64((aOrbiterJ * 5263708315440161809U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 13267185753040999992U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9980987858092888720U;
            aOrbiterC = RotL64((aOrbiterC * 13210290848800728635U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3582972937645514549U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10140409019562890804U;
            aOrbiterI = RotL64((aOrbiterI * 6944490201647678479U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6160444117287330557U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16344602960561293113U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 2319964919335633293U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3497141036108337171U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 91269118352540308U;
            aOrbiterB = RotL64((aOrbiterB * 5160060720189045505U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12739932748793144857U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12820180915064791197U;
            aOrbiterK = RotL64((aOrbiterK * 5843849637411948699U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17572075652083359962U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10684041099654982701U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 7121293375756263771U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10739534650885677354U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9731206787727954809U;
            aOrbiterH = RotL64((aOrbiterH * 3730875775588585547U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9655432616347117764U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13442819395490639310U;
            aOrbiterD = RotL64((aOrbiterD * 3650859301708619119U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterG, 54U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterB, 39U)) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 11U)) + aOrbiterH) + aNonceWordK);
            aWandererD = aWandererD + ((RotL64(aCross, 52U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterF, 37U));
            aWandererA = aWandererA + ((((RotL64(aCross, 21U) + RotL64(aOrbiterC, 47U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 34U) + aOrbiterB) + RotL64(aOrbiterF, 51U));
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterE, 34U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_B_B kdf_b_loop_b (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltA = pDomainSaltSet->mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltB = pDomainSaltSet->mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltC = pDomainSaltSet->mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltD = pDomainSaltSet->mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltE = pDomainSaltSet->mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltF = pDomainSaltSet->mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltA = pDomainSaltSet->mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltB = pDomainSaltSet->mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltC = pDomainSaltSet->mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltD = pDomainSaltSet->mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltE = pDomainSaltSet->mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltF = pDomainSaltSet->mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltA = pDomainSaltSet->mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltB = pDomainSaltSet->mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltC = pDomainSaltSet->mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltD = pDomainSaltSet->mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltE = pDomainSaltSet->mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltF = pDomainSaltSet->mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEA9CD82BBC790923ULL + 0xD4852B5DE843C5A8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC395E224BF4E7FBBULL + 0xF895AACA23402720ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x84E1408C9045F90BULL + 0x825B0859D8417C3BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC7DC59045CEE177DULL + 0x9CD9014B6574E85EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEFEAF45C7C93B209ULL + 0xFFABDE7B85D0C992ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBD32815CF7C320CFULL + 0xD9BFC7040691E9F8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF731C3CA01B7D577ULL + 0xB1D5EA0280592B91ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD4AABF37BD9BEF19ULL + 0xBF595BE0AD22608EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCDBCB9183F78F407ULL + 0x962FB47489652FCEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9600F81FCF9F5E6BULL + 0xAE13D46F75BF3994ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCDA274B8B269ABFBULL + 0xFD5E939211D67A08ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCCBC88F7A6F2DEBBULL + 0xF03C48EDF0553DDDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF406F2D99002FBA1ULL + 0xEA37AF69DE23E404ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBC753778511617F3ULL + 0xA13E846055B3773CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAE7B59B999F27421ULL + 0xF832817FC994E5AAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBF8710E3DD26F889ULL + 0xA145CF83FD24D23DULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_B_C kdf_b_loop_c (start)
    {
        // KDF_B_C kdf_b_loop_c lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aExpandLaneA, aFireLaneC, aFireLaneD, aExpandLaneB, aWorkLaneA, aWorkLaneB, aExpandLaneC, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2410U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 3587U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4097U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7240U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3601U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4333U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 4U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererD + RotL64(aCross, 41U)) + 12122689833405846292U) + aNonceWordJ;
            aOrbiterE = (aWandererF + RotL64(aIngress, 12U)) + 9640400270962766788U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 23U)) + 9141937998266739071U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 12899395770434090537U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 13457918115408031842U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aScatter, 36U)) + 15134784483576000943U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 12540961268790055438U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 19U)) + 6306886773092764230U) + aNonceWordL;
            aOrbiterK = (aWandererI + RotL64(aScatter, 47U)) + 13573343491337243121U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 8545588657348974413U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10891410570357275120U;
            aOrbiterA = RotL64((aOrbiterA * 5399310978367842841U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2877137119767060151U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9178097682386595144U;
            aOrbiterI = RotL64((aOrbiterI * 3524486002084427513U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15528007881855616978U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11368419529245281435U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 12433207037378339309U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5932738914934356645U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5551842263864055419U;
            aOrbiterC = RotL64((aOrbiterC * 16093776759971522681U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3824433359595690603U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17184628855571662441U;
            aOrbiterG = RotL64((aOrbiterG * 691208053136187317U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8724462245014132623U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7481349499528092352U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8212182934509617583U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 6908362960248294718U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5354057969992655314U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 16586084885820679343U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11138301629323903147U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14164180536320940750U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9099767681053390287U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 709942920176922902U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17128241237359414945U;
            aOrbiterK = RotL64((aOrbiterK * 14063385518459963529U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 4U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 23U) + RotL64(aOrbiterA, 53U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterG, 41U));
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 46U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterA, 34U)) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13282U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 14338U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 16086U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10214U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14557U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10916U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13184U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 54U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 11450949896247900941U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 3905542253538116335U;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 28U)) + 9529740545977785305U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 1856876631533143492U;
            aOrbiterC = (aWandererF + RotL64(aCross, 57U)) + 84253466320181686U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 53U)) + 12577480918745432444U) + aNonceWordA;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 14U)) + 5625703170397704029U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 3U)) + 694608607323629282U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 41U)) + 3993981243536262204U) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4119215953484892051U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8785040118556157146U;
            aOrbiterH = RotL64((aOrbiterH * 17113521266125471625U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16234403619456882890U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10398727475672860610U;
            aOrbiterC = RotL64((aOrbiterC * 5086871400049644715U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18327987141759096769U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2645964788056875452U;
            aOrbiterF = RotL64((aOrbiterF * 8778681366114628045U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2859452497983106129U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7196557924940881076U;
            aOrbiterJ = RotL64((aOrbiterJ * 14415389907490256711U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 930127943984174668U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15673596916054795749U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7505660488733199479U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16673140529110941163U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2258448294877833760U;
            aOrbiterI = RotL64((aOrbiterI * 1821550319748977445U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6870209259643931219U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12749790107942194104U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 4871407285968611725U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17131374134617173866U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6426448390733751612U;
            aOrbiterD = RotL64((aOrbiterD * 12490559588384058417U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15592826434339731146U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14182944418026376183U;
            aOrbiterB = RotL64((aOrbiterB * 7218860482893476233U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 57U) + RotL64(aOrbiterK, 22U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 43U)) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 14U) + aOrbiterD) + RotL64(aOrbiterK, 27U));
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterA, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 60U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 47U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 39U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aCross, 40U) + aOrbiterH) + RotL64(aOrbiterA, 13U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneA, aOperationLaneB, aWorkLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneC, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18102U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 18208U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 22954U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 20022U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20378U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21181U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 22952U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 8604208734152026945U) + aNonceWordM;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 57U)) + 1374329953253889829U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 14U)) + 5779278910548228339U;
            aOrbiterK = ((((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 17670451230882805140U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aWandererK + RotL64(aCross, 53U)) + 8193848740764866860U) + aNonceWordO;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 47U)) + 15801168428145650104U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 20U)) + 2584718176087499066U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 14950366247822737997U;
            aOrbiterD = (aWandererA + RotL64(aCross, 43U)) + 9779293225265670135U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8688968319288372383U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13665723186950342601U;
            aOrbiterI = RotL64((aOrbiterI * 292035540396910837U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9395428688359973510U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2152719218018108418U;
            aOrbiterF = RotL64((aOrbiterF * 15271961483518392671U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1350324137411377992U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8729317951386057921U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6008790836417785083U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6317310451893678411U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10175620379041384281U;
            aOrbiterB = RotL64((aOrbiterB * 14079679617394330781U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 1203082119358827708U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 523869107818193101U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 4629501113595689157U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 4028324959540432983U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15447631947468213912U;
            aOrbiterG = RotL64((aOrbiterG * 6037306615787729185U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14225888694733041031U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11925000696281947629U;
            aOrbiterD = RotL64((aOrbiterD * 4337022940520411253U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15015531024930608745U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16752579225076943550U;
            aOrbiterC = RotL64((aOrbiterC * 15551083683579981439U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2432733494869267901U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10103430321388601485U;
            aOrbiterA = RotL64((aOrbiterA * 18372919379972432569U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (RotL64(aOrbiterK, 22U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 4U)) + aOrbiterD) + aNonceWordK) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 58U) + RotL64(aOrbiterB, 53U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterD, 11U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterF, 19U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 47U)) + aOrbiterC) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 29U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterI);
            aWandererE = aWandererE + (((((RotL64(aIngress, 44U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordN) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 42U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD, aWorkLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB, aWorkLaneD
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32500U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((aIndex + 25585U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27681U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29254U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26226U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25325U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30232U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 9654059367478508868U) + aNonceWordL;
            aOrbiterC = (aWandererC + RotL64(aIngress, 27U)) + 6473006635864677427U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 4U)) + 6944184481315853243U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 4061496421939102306U) + aNonceWordP;
            aOrbiterE = (aWandererK + RotL64(aIngress, 41U)) + 15791809275719085463U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 19U)) + 14050798802646323055U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 23U)) + 12072905924741758266U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 17639076509231343896U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 46U)) + 12195388285571234715U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4325404419499496529U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5910567888204238382U;
            aOrbiterI = RotL64((aOrbiterI * 11503787177122206937U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13092940059929942699U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13381962590820308761U;
            aOrbiterE = RotL64((aOrbiterE * 6345904465930943295U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15622862439323440527U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14027151901132249793U;
            aOrbiterH = RotL64((aOrbiterH * 2273573821630510087U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4584410023907605157U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15763755180625487157U;
            aOrbiterD = RotL64((aOrbiterD * 6755736130607297639U), 23U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 17023059745666559199U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 5298529579288492971U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 2483562793328357721U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2870152867331654736U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12017191100173748848U;
            aOrbiterB = RotL64((aOrbiterB * 9958191466506480519U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15899529176182436062U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16482713846343388735U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 719465695044265601U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12943393531812774449U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9881108254540483225U;
            aOrbiterA = RotL64((aOrbiterA * 8011108108007885059U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3532054586199716750U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7142230313294797435U;
            aOrbiterF = RotL64((aOrbiterF * 14154176174768868421U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 52U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 37U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 12U)) + aOrbiterA) + aNonceWordA) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 41U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + aNonceWordG);
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 5U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 18U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterH, 47U)) + aOrbiterD) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererI, 56U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_B_C kdf_b_loop_c (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltA = pDomainSaltSet->mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltB = pDomainSaltSet->mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltC = pDomainSaltSet->mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltD = pDomainSaltSet->mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltE = pDomainSaltSet->mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterAssignSaltF = pDomainSaltSet->mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltA = pDomainSaltSet->mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltB = pDomainSaltSet->mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltC = pDomainSaltSet->mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltD = pDomainSaltSet->mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltE = pDomainSaltSet->mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aOrbiterUpdateSaltF = pDomainSaltSet->mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltA = pDomainSaltSet->mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltB = pDomainSaltSet->mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltC = pDomainSaltSet->mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltD = pDomainSaltSet->mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltE = pDomainSaltSet->mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aWandererUpdateSaltF = pDomainSaltSet->mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x91D868EEFDB10191ULL + 0xAFD5474073050953ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFF3DCB0C62CDC6D5ULL + 0x87DC085B4FEF0DB6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB5709FFB3FCFB75BULL + 0x930D212884A0B445ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x83C7A1FC84837C09ULL + 0xF65F7BDA6F36B30EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x88D5581E624C0BF3ULL + 0x853EB4D757C41EB5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC9C90A30C82B99B5ULL + 0xF65800135A4F009CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAAB412C61F648BDDULL + 0xB75CF0B2EDB63EB9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x89AB0B4C015E9615ULL + 0xFDE04A7237E406F9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDE08C233161FF79FULL + 0xA0FBA9F615CBC22CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE75B1F2AFF4E99D9ULL + 0xF4259A4A9B05D6FBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE83680A48439E961ULL + 0xB3F8D72D8168CB0DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF84532175433F7F7ULL + 0x9B2D356FA44DBB4AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE2C87E177B466255ULL + 0x9F10E3E70D79B067ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC2ECB2C5DD7035A3ULL + 0x969A2FD28554D553ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDA6EC4ADE514FC9FULL + 0x96B7DB92C6BFFE2DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEAB41ADA849CE279ULL + 0x9C066C25FC8AAE1AULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // KDF_B_D kdf_b_loop_d (start)
    {
        // KDF_B_D kdf_b_loop_d lane group
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneA, aWorkLaneC, aWorkLaneD, aFireLaneB, aExpandLaneA, aFireLaneC, aFireLaneD, aExpandLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4501U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 2188U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5012U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6208U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 761U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7115U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 39U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 57U)) + 8866844335448071821U) + aNonceWordE;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 15159698739856430085U;
            aOrbiterB = ((((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 9582805772989594633U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aWandererA + RotL64(aScatter, 27U)) + 1438538239931588373U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 39U)) + 10862044156620436139U) + aNonceWordN;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 18U)) + RotL64(aCarry, 39U)) + 13682173320058164615U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 51U)) + 8351013291045977592U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15777857431516633916U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16178966745333885377U;
            aOrbiterB = RotL64((aOrbiterB * 7545129923202147703U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9031889187993001617U) + aNonceWordJ;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6308472367425865347U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17118710301967158153U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 642109145903321046U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9186268569255318035U;
            aOrbiterK = RotL64((aOrbiterK * 10714674348507516749U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6091345356803675860U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13218507921880873749U;
            aOrbiterD = RotL64((aOrbiterD * 15415157927185637717U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4266652275234474616U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4391422098164506195U;
            aOrbiterA = RotL64((aOrbiterA * 17634679403195085867U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5160682323243635577U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10351728852161347404U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 11105410036471745951U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3950932176454814023U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9536466386833427441U;
            aOrbiterF = RotL64((aOrbiterF * 18064984243491293435U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 58U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 21U) + RotL64(aOrbiterI, 6U)) + aOrbiterJ) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneB, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12645U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 13615U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 12465U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10326U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8497U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14947U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14126U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 43U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 3561491146322798260U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 53U)) + 7075025056181885339U) + aNonceWordM;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 3U)) + 9230910887904171613U) + aNonceWordO;
            aOrbiterF = (aWandererH + RotL64(aIngress, 47U)) + 4119781172609908917U;
            aOrbiterE = ((((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 17155609083870983149U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aWandererE + RotL64(aIngress, 27U)) + 2423018561430181695U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 38U)) + RotL64(aCarry, 5U)) + 12957280305617615744U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2461704174772065813U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7907123257849391997U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9416171962847312179U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 7257868138318960007U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16425903703085702285U;
            aOrbiterE = RotL64((aOrbiterE * 7996935869077231999U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 2990822664594079467U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5654819006718953817U;
            aOrbiterF = RotL64((aOrbiterF * 4465096036756887801U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12183676471235678779U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15026286960542123922U;
            aOrbiterD = RotL64((aOrbiterD * 17199049329995315279U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12169080607071830522U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2906296852254787499U;
            aOrbiterB = RotL64((aOrbiterB * 6754514406846040163U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3029858695410344584U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14406410317495954566U;
            aOrbiterH = RotL64((aOrbiterH * 9663780721657983421U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11048818178401163861U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13622063920319445043U;
            aOrbiterG = RotL64((aOrbiterG * 2516025554421589857U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 58U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterE, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 41U)) + aOrbiterD) + aNonceWordN);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterB, 4U)) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 47U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 52U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18551U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 18940U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 18448U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 20967U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17851U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23395U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23123U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 13U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 8767379393098711499U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aScatter, 6U)) + RotL64(aCarry, 23U)) + 7168159491580816433U) + aNonceWordB;
            aOrbiterA = (((aWandererI + RotL64(aCross, 27U)) + 9879279829061883406U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 10537167136053399303U) + aNonceWordM;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 13U)) + 2839070018069188936U;
            aOrbiterI = (aWandererC + RotL64(aCross, 37U)) + 13844278063968429732U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 57U)) + 11278946626186474646U) + aNonceWordL;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11798425216660557799U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7618446090703335192U;
            aOrbiterA = RotL64((aOrbiterA * 7168757300685156779U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 695423597006983660U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14344728202803488813U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 5168825904902285909U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11656100506575697086U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 10384358779985773937U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 247494692039140973U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17585001605131977341U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9964478171465522911U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13484044854790175315U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2710943171829692624U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17809072853457153057U;
            aOrbiterB = RotL64((aOrbiterB * 16341884203303271365U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12814092033910687774U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 1743186323268668740U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11150822630624332557U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10750472346626754704U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15925901217078035356U;
            aOrbiterF = RotL64((aOrbiterF * 9276504171291801637U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 30U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + aNonceWordI);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterE, 41U)) + aOrbiterI) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneB, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25809U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 25407U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 28705U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32055U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25066U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24977U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29639U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = (aWandererE + RotL64(aIngress, 47U)) + 7960325128608297381U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 53U)) + 12773836012104052042U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 27U)) + 3173972621347773016U) + aNonceWordO;
            aOrbiterD = (aWandererI + RotL64(aCross, 21U)) + 3708401356314308171U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 950774285720019449U) + aNonceWordF;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 13U)) + 4170092315705438265U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 17000449130864980747U) + aNonceWordC;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8793910540062893860U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 520277969543516469U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4150613128885828229U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12762214857389827271U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2932451184340207695U;
            aOrbiterC = RotL64((aOrbiterC * 7513337346940091655U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11062179998786293839U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7919119215271524178U;
            aOrbiterD = RotL64((aOrbiterD * 9053677007180081359U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1774988449597115155U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3799792889466518953U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 17512791286490623455U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1815062051307896589U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15260373951371654483U;
            aOrbiterK = RotL64((aOrbiterK * 2208604434669491625U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12867546628945676853U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7772820973895846946U;
            aOrbiterI = RotL64((aOrbiterI * 7581704643538761985U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14213957831821966834U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16561105721170419454U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2540533987337175367U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 35U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 53U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterB, 27U)) + aNonceWordP) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // KDF_B_D kdf_b_loop_d (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF;
    const std::uint64_t &aPhaseEDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseEConstants.mIngress;
    const std::uint64_t &aPhaseEDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseEConstants.mScatter;
    const std::uint64_t &aPhaseEDomainWordCross = pWorkSpace->mDomainBundle.mPhaseEConstants.mCross;
    const std::uint64_t &aPhaseFDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseFConstants.mIngress;
    const std::uint64_t &aPhaseFDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseFConstants.mScatter;
    const std::uint64_t &aPhaseFDomainWordCross = pWorkSpace->mDomainBundle.mPhaseFConstants.mCross;
    const std::uint64_t &aPhaseGDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseGConstants.mIngress;
    const std::uint64_t &aPhaseGDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseGConstants.mScatter;
    const std::uint64_t &aPhaseGDomainWordCross = pWorkSpace->mDomainBundle.mPhaseGConstants.mCross;
    const std::uint64_t &aPhaseHDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseHConstants.mIngress;
    const std::uint64_t &aPhaseHDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseHConstants.mScatter;
    const std::uint64_t &aPhaseHDomainWordCross = pWorkSpace->mDomainBundle.mPhaseHConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [seed arx]
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAF2190A11C307847ULL + 0xD90EEC3AD0FD5C58ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8DF8DBBD2E29C4BFULL + 0xBED2D5690E0F3D2EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC999CD6C3C22C5ADULL + 0x972DAB76594BE3FAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF0CC2A53EC6225F9ULL + 0xF973808360A4FD28ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFA2E0993F71FCA9FULL + 0xD2400B2724CCAB42ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD659A154B350D845ULL + 0xA333E5BCB1798A30ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEB5A99CBD052F811ULL + 0x9984BEAAD8915EAAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8A262157AFBF7997ULL + 0xA9BD1357B31217F5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE1C96047A0E60515ULL + 0x8E73DD50392A2234ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF8E69C13ECF3D87BULL + 0xF8B994F576D36FAFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC03A772923E9D6A9ULL + 0xCC10F8B3B5CD9390ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9B725055D5BBD477ULL + 0x98C04F0C8F3FF3DAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC94ED274248A29F3ULL + 0x9C6F85BBF186234AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDC386B266F7FEA89ULL + 0xCC17691D8C02E6A0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFDD776CB0482D2D9ULL + 0xFE26CBA144FB7C1CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC745697DAA65C445ULL + 0xA2832EF2F00C057DULL);
    // GSeedRunSeed_A seed_loop_a (start)
    {
        // GSeedRunSeed_A seed_loop_a lane group
        // read from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_a loop 1
        // ingress from: aKeyRowReadA, aKeyRowReadB
        // ingress directions: aKeyRowReadA forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource
        // cross directions: aKeyRowReadA backward forced, mSource backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1556U)) & W_KEY1], 24U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1961U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2476U)) & W_KEY1], 60U) ^ RotL64(mSource[((aIndex + 1894U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 43U)) + (RotL64(aCross, 10U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (aWandererG + RotL64(aScatter, 58U)) + 10336802574069791273U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 51U)) + 169025388197058936U) + aPhaseEOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 6541354188379168846U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 19U)) + 16223920526599306104U) + aNonceWordN;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 12756613707692514808U) + aNonceWordD;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 41U)) + 5082475548176484035U) + aNonceWordM;
            aOrbiterF = ((((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 4907435526952698526U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14236627073831834337U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11502511046130497584U;
            aOrbiterC = RotL64((aOrbiterC * 3460330807286625917U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3679044835550219497U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11254838916686736746U;
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10582608424233200966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10449735026385340313U;
            aOrbiterF = RotL64((aOrbiterF * 7363770199734997411U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4628253464169957835U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17664454668473204465U;
            aOrbiterB = RotL64((aOrbiterB * 4234720298731378527U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 3798386391743884889U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1379331161819246587U;
            aOrbiterH = RotL64((aOrbiterH * 13086160171095077295U), 37U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 9816600392407327227U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16781971616348376878U;
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4807797577690520554U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 2492057261148595922U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9453302540675483005U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 60U)) + aOrbiterF) + aNonceWordJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 27U)) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aFireLaneA, aKeyRowReadA
        // ingress directions: aFireLaneA forward forced, aKeyRowReadA forward/backward random
        // cross from: aKeyRowReadB, mSource
        // cross directions: aKeyRowReadB backward forced, mSource backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 5136U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4254U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3677U)) & W_KEY1], 39U) ^ RotL64(mSource[((aIndex + 3315U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererH + RotL64(aCross, 3U)) + 1866656689936219099U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aWandererK + RotL64(aScatter, 13U)) + 2312314528139448289U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 37U)) + 3554037526469185237U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 39U)) + 405707755060974111U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 1862976326004007697U) + aNonceWordD;
            aOrbiterE = ((((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 12992483065443288263U) + aPhaseEOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 43U)) + 3793854946371595197U) + aNonceWordG;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4244007978867369382U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 10280867500312580308U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 13729899124177931289U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 472563452959164242U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12041770406895816553U;
            aOrbiterC = RotL64((aOrbiterC * 17811798500132002631U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6118634015704900486U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13637107920449233307U;
            aOrbiterD = RotL64((aOrbiterD * 17712028184714868053U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 16673735670669318830U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8602681273646630496U;
            aOrbiterI = RotL64((aOrbiterI * 6995213887710749241U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7683264695930369476U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 9146674871199188218U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 7403427067419261981U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3012935612827493084U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1259789268731661945U;
            aOrbiterB = RotL64((aOrbiterB * 2372843620327050137U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5623690455471160780U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 18355567776031865462U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 9553862670107886679U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 43U)) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 19U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 53U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterG, 37U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 4U) + aOrbiterE) + RotL64(aOrbiterB, 13U));
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterD, 28U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aFireLaneB, aKeyRowReadB
        // ingress directions: aFireLaneB forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aFireLaneA backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneB[((aIndex + 6486U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 6462U)) & W_KEY1], 30U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6846U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5596U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5509U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = (((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 6024062041314952357U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 41U)) + 18340757093658015585U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 35U)) + 11911120493880346751U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 29U)) + 17428074353884654439U) + aNonceWordA;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 12790849760814795936U) + aNonceWordJ;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 12633397052172117800U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 50U)) + 11946150433665237945U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16842157900909419285U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14186235783224155962U;
            aOrbiterF = RotL64((aOrbiterF * 10521157787073684417U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 13284904542579767591U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11609181965078844357U;
            aOrbiterH = RotL64((aOrbiterH * 5455780554452453513U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9628562297095374984U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7850281529011259759U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 17611485102925470357U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 257458718073794527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10693404545773519306U;
            aOrbiterK = RotL64((aOrbiterK * 14821443722828498323U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3430519236533871460U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6183054506953198055U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6121082743789970911U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2905610989884221654U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4472163910775333862U;
            aOrbiterG = RotL64((aOrbiterG * 7770678426310856745U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16870142883133769663U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1403692060594816451U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 9740854430251597879U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 44U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 12U) + aOrbiterF) + RotL64(aOrbiterI, 5U));
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererG = aWandererG + (((((RotL64(aCross, 21U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aNonceWordF) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 51U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + aNonceWordC) + aPhaseEWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 58U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aFireLaneC, aKeyRowReadB, mSource, aFireLaneA
        // ingress directions: aFireLaneC forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aFireLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 9389U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadB[((aIndex + 10227U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(mSource[((aIndex + 8683U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9052U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8848U)) & W_KEY1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 9497U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 28U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 13U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = (((aWandererK + RotL64(aScatter, 54U)) + RotL64(aCarry, 21U)) + 18302975933754610273U) + aNonceWordL;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 29U)) + 16736972646771456082U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 21U)) + 17389406266488137442U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 5252511566486165539U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 37U)) + 5730715427422747640U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 6412695646456045825U) + aNonceWordE;
            aOrbiterC = (((aWandererI + RotL64(aCross, 3U)) + 9539701605708994494U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18355107116412945722U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11735742491750132942U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18129835093627763685U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12363819388562658842U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 5861430292304371543U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 12989055611235382695U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15027487084595017708U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7012850020745791926U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 15952928839355613939U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11904871669287886120U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11199760114477343208U;
            aOrbiterC = RotL64((aOrbiterC * 7156374911847525867U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 3856004502263742700U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3705931243173921893U;
            aOrbiterE = RotL64((aOrbiterE * 10334871178498711485U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12305785390539209389U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18057980996551978823U;
            aOrbiterD = RotL64((aOrbiterD * 4850564181113470859U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3229431819292153014U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2994716629242460094U;
            aOrbiterG = RotL64((aOrbiterG * 1029427328395257917U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + aNonceWordJ);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 54U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 41U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + aNonceWordI) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // ingress from: aFireLaneD, aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB
        // ingress directions: aFireLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneB forward/backward random
        // cross from: aFireLaneA, aFireLaneC
        // cross directions: aFireLaneA backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 13397U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 12223U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12264U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 12918U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11931U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12500U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneC[((aIndex + 13359U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = ((aWandererC + RotL64(aCross, 5U)) + 3248574644570178787U) + aPhaseFOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 54U)) + RotL64(aCarry, 29U)) + 4506961512959200024U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 8423739774540738590U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 37U)) + 6593975869641735337U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 43U)) + 16441716090557369103U) + aNonceWordD;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 11U)) + 7936601450453207914U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 13333752583560167065U) + aNonceWordH;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8013703284795432973U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2349852779887439236U;
            aOrbiterB = RotL64((aOrbiterB * 2422888500648100783U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5318539364763284138U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11450957608502944376U;
            aOrbiterK = RotL64((aOrbiterK * 1957880366707810635U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9058992558327552687U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 632095686920230926U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 12460364388358520799U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14734218428913777098U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16344357661370784442U;
            aOrbiterH = RotL64((aOrbiterH * 15049472842002138369U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2981145363531184308U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14176472085175714494U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 2584623327412130939U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11198457590069700889U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 952584436750426828U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1165713888651280355U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4311591763498985972U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16194341833989936369U;
            aOrbiterG = RotL64((aOrbiterG * 9997934560195932575U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 20U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterD, 13U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 58U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 23U)) + aOrbiterD) + aNonceWordG);
            aWandererA = aWandererA + ((((RotL64(aCross, 5U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // ingress from: aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, mSource backward forced, aFireLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 14509U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneC[((aIndex + 15502U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15507U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15788U)) & W_KEY1], 53U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13850U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14302U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16262U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 21U)) ^ (RotL64(aIngress, 38U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (aWandererC + RotL64(aPrevious, 19U)) + 13714409587461539863U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 11U)) + 14101156723903265839U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 7063754562895369001U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aScatter, 41U)) + 12320578575245519386U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 56U)) + 11744826789631008424U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 8744816505096675597U) + aNonceWordK;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 10405435520084528645U) + aNonceWordB;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1463157688070683543U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12379603577919617703U;
            aOrbiterG = RotL64((aOrbiterG * 14858901470015109311U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1343439118031348146U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16118850268070235540U;
            aOrbiterJ = RotL64((aOrbiterJ * 11184386483735388257U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14116264435819277136U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 5251698273012432109U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 1495818611622063967U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14806408656041403829U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11569345414052398227U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9913158908301414861U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17063874769147888574U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9927420478679581917U;
            aOrbiterE = RotL64((aOrbiterE * 9042782809534196563U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2550285599827162167U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17801534123304996448U;
            aOrbiterK = RotL64((aOrbiterK * 2160836889363614721U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6456685241021762041U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17064208177372969289U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 13726627607233302493U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 28U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterB, 27U)) + aNonceWordM) + aPhaseFWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + RotL64(aOrbiterE, 21U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 47U));
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 41U)) + aOrbiterA) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 36U) + aOrbiterK) + RotL64(aOrbiterG, 14U)) + aNonceWordH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 7
        // ingress from: aWorkLaneB, aKeyRowReadA, mSource, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aKeyRowReadA forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadB, aFireLaneD, aWorkLaneA
        // cross directions: aKeyRowReadB backward forced, aFireLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16687U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadA[((aIndex + 18381U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 16766U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((aIndex + 17606U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17216U)) & W_KEY1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18876U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 16411U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 4622023259121087483U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 10253505250223501352U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 29U)) + 17133877904420462669U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aWandererF + RotL64(aCross, 57U)) + 6162827793741796700U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 48U)) + 9610986424765907615U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 3U)) + 11210747154264753754U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 16554205219580654546U) + aNonceWordM;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10352576357413766388U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3651845783283479752U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 1011289824180799641U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 18145542190463500476U) + aNonceWordL;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 5415609566767162857U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 6474184559323816389U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2033734872464201570U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3507213117125813345U;
            aOrbiterH = RotL64((aOrbiterH * 5453058336688881113U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8716253393049851856U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 695984869565941856U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8377921610764044735U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7661578828878284931U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 906654265099155956U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 8117625377607536949U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6050049984731254612U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17882717590338190821U;
            aOrbiterB = RotL64((aOrbiterB * 10807367411402733215U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4996521991532815957U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4246460672800604436U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12047466401960824903U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 60U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 54U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + aNonceWordN) + aPhaseGWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 58U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + aNonceWordI);
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterC, 29U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + aNonceWordF) + aPhaseGWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 8
        // ingress from: aWorkLaneC, mSource, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, mSource forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, aWorkLaneB, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19932U)) & S_BLOCK1], 12U) ^ RotL64(mSource[((aIndex + 19431U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19172U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20180U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20391U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19566U)) & W_KEY1], 5U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19716U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((aIndex + 19475U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 52U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 13U)) + 10404808878585437255U) + aPhaseGOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 10587858736301591439U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 1430530909801644435U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 39U)) + 9090938022430118902U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 6U)) + RotL64(aCarry, 5U)) + 12936604311751121235U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 19U)) + 1000583006020232032U) + aNonceWordB;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 51U)) + 12352532088997042232U) + aNonceWordK;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16723410947058502564U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16614089235313154270U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 11530998303573027827U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4245553025593349277U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3353146318549477494U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 14246377408238318091U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5935727336135635196U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10312187090293319667U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1395964500396711899U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12192843181244744484U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2542570124502586365U;
            aOrbiterK = RotL64((aOrbiterK * 17222847847573534963U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3315472769469002444U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17512858811783071174U;
            aOrbiterF = RotL64((aOrbiterF * 9070400454074283765U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16633218007427888082U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 2502077714838858460U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 970762420815997725U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14792910273226469214U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15739513291150783151U;
            aOrbiterH = RotL64((aOrbiterH * 11896279674116906915U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 4U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterI, 53U));
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aScatter, 12U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + aNonceWordE) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterF, 39U)) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterK, 26U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererG, 12U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 9
        // ingress from: aWorkLaneD, aKeyRowReadA, aKeyRowReadB, aWorkLaneC
        // ingress directions: aWorkLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: mSource, aWorkLaneA, aFireLaneC, aFireLaneD
        // cross directions: mSource backward forced, aWorkLaneA backward forced, aFireLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23155U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 22546U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22857U)) & W_KEY1], 58U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23725U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23969U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23860U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22991U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24166U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 51U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 51U)) + 3612110001869385068U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 5U)) + 16340824141280225936U) + aNonceWordN;
            aOrbiterD = (aWandererA + RotL64(aScatter, 14U)) + 15222338965130765231U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 6649270508107155041U) + aNonceWordF;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 768217258655426384U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 4481855259658861851U) + aPhaseGOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 57U)) + 18318041934562434016U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4212457153804401807U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16143621095636987628U;
            aOrbiterD = RotL64((aOrbiterD * 6576072860505961427U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2095664232866642086U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4339527736737366572U;
            aOrbiterJ = RotL64((aOrbiterJ * 17503569508822244125U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13679353177869884790U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11582168502846418236U;
            aOrbiterB = RotL64((aOrbiterB * 135539430034462861U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10451330452898542191U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12951448817640617841U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 4141870904192742091U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 15389161934419370747U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4754886272708253014U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16638243718191281597U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11746389873929280688U) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12042680172517298768U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 3814780289755857543U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2648103752465009244U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 451594673632597973U;
            aOrbiterK = RotL64((aOrbiterK * 8496763663271072425U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterE, 43U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aNonceWordP) + aPhaseGWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 4U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 37U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 10
        // ingress from: aExpandLaneA, aKeyRowReadA, aWorkLaneD, aWorkLaneB
        // ingress directions: aExpandLaneA forward forced, aKeyRowReadA forward forced, aWorkLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aKeyRowReadB, mSource, aWorkLaneC, aFireLaneD
        // cross directions: aKeyRowReadB backward forced, mSource backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24854U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 27035U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 24717U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((aIndex + 25145U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25479U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26436U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25010U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 26736U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 29U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = (((aWandererE + RotL64(aScatter, 12U)) + RotL64(aCarry, 37U)) + 4204560462077827182U) + aNonceWordG;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 43U)) + 6572370199668594039U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 15958999876732622825U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 29U)) + 9969349486879280377U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 21U)) + 15450238998293956181U) + aPhaseHOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 9128619863683138259U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 57U)) + 5691270563628979565U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5901029710568933106U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10442738941988588834U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 7386621444831603817U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3508116020325721993U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13221917083569767259U;
            aOrbiterI = RotL64((aOrbiterI * 6845108555710135357U), 21U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 11627915460377128176U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17858261365514253433U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7535577636975884641U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4294837988806295989U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11242915481585070249U;
            aOrbiterK = RotL64((aOrbiterK * 17540688242763829319U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13030663829236027109U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7451948220723185149U;
            aOrbiterB = RotL64((aOrbiterB * 5191778587712222029U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5575508866505031037U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5161096033789876794U;
            aOrbiterE = RotL64((aOrbiterE * 16843827915802461797U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3980482740649505122U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11188906150207270241U;
            aOrbiterJ = RotL64((aOrbiterJ * 408550837615188413U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 58U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterE, 47U)) + aPhaseHWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterG, 11U)) + aNonceWordD) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 11
        // ingress from: aExpandLaneB, aWorkLaneD, aKeyRowReadB, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: aKeyRowReadA, mSource, aExpandLaneA, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aExpandLaneA backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27360U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 29711U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28804U)) & W_KEY1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29911U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27649U)) & W_KEY1], 40U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28398U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29004U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28609U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 54U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 2783898056762489197U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 7177192902873343053U) + aPhaseHOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 12254703232691980774U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 43U)) + 15446547245691219559U) + aNonceWordF;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 29U)) + 888475203006174856U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 53U)) + 3649183529366307877U) + aNonceWordB;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 35U)) + 4642631047518805167U) + aNonceWordG;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6108329730724782250U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8334054653023816636U;
            aOrbiterE = RotL64((aOrbiterE * 9352516059501924393U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 5891895375031474350U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3176720746238477862U;
            aOrbiterG = RotL64((aOrbiterG * 1869961473768307911U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6111038696865301675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11914998302228682704U;
            aOrbiterJ = RotL64((aOrbiterJ * 11738924766359642853U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17005063057791320948U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 18333780598768130670U;
            aOrbiterK = RotL64((aOrbiterK * 5416759844884107303U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2056115016443263153U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 10245512728872962677U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 707106795383284903U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4810366069422162351U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3051442983125942469U;
            aOrbiterD = RotL64((aOrbiterD * 13558537578054436423U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9285068547223654308U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13067251130180968842U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7000687697769766605U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 10U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 58U)) + aOrbiterG) + aNonceWordJ);
            aWandererA = aWandererA + ((((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 11U)) + aOrbiterE) + aPhaseHWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterC, 5U)) + aOrbiterG) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 12
        // ingress from: aExpandLaneC, aKeyRowReadA
        // ingress directions: aExpandLaneC forward forced, aKeyRowReadA forward/backward random
        // cross from: aWorkLaneD, aExpandLaneA, aExpandLaneB, aKeyRowReadB
        // cross directions: aWorkLaneD backward forced, aExpandLaneA backward forced, aExpandLaneB backward forced, aKeyRowReadB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 32743U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadA[((aIndex + 31038U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30453U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31797U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30732U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30527U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 52U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 11U)) + 3973833383430652211U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 5760227042747169187U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aScatter, 27U)) + 4923009065139227286U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 43U)) + 1477807307009107590U) + aNonceWordL;
            aOrbiterA = ((((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 5707194514329007301U) + aPhaseHOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aWandererF + RotL64(aCross, 21U)) + 5340439728375269724U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 50U)) + RotL64(aCarry, 21U)) + 17080457898946572387U) + aNonceWordG;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 281559150259472813U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16160633048230910560U;
            aOrbiterC = RotL64((aOrbiterC * 16883442583309073785U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9003989610509592121U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 10579322462808454333U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 100832431598087235U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15059383289528723069U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10417647757852880956U;
            aOrbiterB = RotL64((aOrbiterB * 1457919230286043137U), 51U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 14484665027393813330U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12344463053485837974U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5762654194001525041U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5826453246659297805U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12547902286376986223U;
            aOrbiterJ = RotL64((aOrbiterJ * 2982850000322672789U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9637855144278126174U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2132744427444501938U;
            aOrbiterG = RotL64((aOrbiterG * 5911587798564836199U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9248933938130311231U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13274297928717090383U;
            aOrbiterK = RotL64((aOrbiterK * 2901398809555237563U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 44U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_A seed_loop_a (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

    // [seed arx]
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE787A434701B5BFFULL + 0xBAC5DF211FDA7D5EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA6052703EB9262A3ULL + 0x81FB978239583057ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF14CC8145711DCA5ULL + 0xCEAED7DFE4651C56ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD1BDD83E76441DC1ULL + 0x8D09D3664625A6E1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAF9387DC52568851ULL + 0xE8A42411CF4DA931ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC93B9A0AE8C850E1ULL + 0xB6FCBF36EF8B4A31ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB9BC7E8B8C3DD2A1ULL + 0xE81CEF7DD2F199E8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF3529B9E48AFCFB9ULL + 0xEA1B1CB57FEE928EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9991DB407535ED29ULL + 0xBB35A0B6D8A640BEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9719314A66B61D77ULL + 0xBE6220D64613DFD2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDF2F3382937F7DAFULL + 0xE548F3B83A3FC60CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9D925C7BCAE2ACAFULL + 0xC3B6FD100FA2D962ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x844DE86B3058DDDDULL + 0xAA7E1D904ECA9D54ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFEF63D63AB49ACA9ULL + 0x930625E60B1427FEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x80844528D2F1BBB3ULL + 0x9C65C29EC68326B6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAF686346B7C5A087ULL + 0xEFA192A6AEAC1E0BULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aInvestLaneA, aFireLaneC, aFireLaneD, aInvestLaneB, aWorkLaneA, aOperationLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aOperationLaneC, aWorkLaneD
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 623U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 3676U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 584U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4094U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1892U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4020U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 1142447269198373880U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 56U)) + 10581460640040336191U) + aPhaseAOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 14703062773878202900U) + aNonceWordF;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 15737525756286914746U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 35U)) + 16178774478273186999U) + aNonceWordM;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2514897053906809160U) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 13702496607592508464U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16540143680974064057U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18030885275418337965U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 5241783876161655984U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 10970981186787227937U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2807052676283587925U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8022804576763271327U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11727096043219370577U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15597099852232205860U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1538435607932096400U;
            aOrbiterF = RotL64((aOrbiterF * 7900752511710516981U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11147868774413615365U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 9325213746830411568U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 561819005818948769U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererC = aWandererC + (((((RotL64(aIngress, 30U) + aOrbiterF) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 27U)) + aNonceWordD) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 51U)) + aOrbiterD) + aPhaseAWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8627U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 8808U)) & S_BLOCK1], 34U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10898U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((aIndex + 6061U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7564U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9802U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 6302U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 48U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 54U)) + RotL64(aCarry, 11U)) + 8506388683755208267U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 43U)) + 2179323259055019735U) + aNonceWordH;
            aOrbiterI = (aWandererG + RotL64(aIngress, 21U)) + 3345902531140983016U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 17456139311481306584U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aIngress, 29U)) + 14587864088462311164U) + aPhaseAOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13178947246650647057U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12866578138946916962U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 121991325166969319U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13098524333655118173U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 15451329483787541982U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 13580376920467431451U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9494299579678389385U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15581954810375490643U;
            aOrbiterC = RotL64((aOrbiterC * 13670002280188424825U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4487042505730624892U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2774455928791636186U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 15847933919136777451U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12435319582397755819U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10077180055177766823U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3924363471701748703U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 38U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 21U)) + aOrbiterF) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 50U) + RotL64(aOrbiterF, 48U)) + aOrbiterC) + aNonceWordA) + aPhaseAWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + aNonceWordO) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneA, aWorkLaneA
        // ingress directions: aInvestLaneB forward forced, aExpandLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aInvestLaneA, aExpandLaneC
        // cross directions: aInvestLaneA backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15798U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 16131U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10936U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12098U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12103U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 22U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererC + RotL64(aCross, 11U)) + 7075016829833562104U) + aNonceWordI;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 8783765886115517036U) + aPhaseAOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aScatter, 28U)) + RotL64(aCarry, 41U)) + 2996723892384565829U) + aNonceWordF;
            aOrbiterC = ((((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 9494134707342189476U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 19U)) + 5052642981395679904U) + aNonceWordJ;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 8766787055127962238U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4467211954388738079U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8599295330343804047U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8030255604633658608U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16962408063455702251U;
            aOrbiterH = RotL64((aOrbiterH * 11171737929747471631U), 37U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 3768222186567699076U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14930990410207899871U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10930005786146268241U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14179761938395502502U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1879084742719898108U;
            aOrbiterF = RotL64((aOrbiterF * 16783034788172670121U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5535012408925981515U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12792553516710295939U;
            aOrbiterC = RotL64((aOrbiterC * 8577530993755159329U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 35U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 58U)) + aOrbiterC) + aNonceWordG) + aPhaseAWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterH, 47U)) + aNonceWordC) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16521U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((aIndex + 19145U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18791U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19584U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16890U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 21U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 21U)) + 252059974543142812U) + aNonceWordN;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 54U)) + RotL64(aCarry, 27U)) + 11690823093681457368U) + aNonceWordK;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 3U)) + 13282189752890971123U) + aPhaseAOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 9507416294305708435U) + aPhaseAOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 14053038174390776539U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14605253312318725009U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 18138286582677863671U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10595905899691011321U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 8530091235978489988U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14381731677571170073U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 11675896999665768253U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13316413456378978456U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3910529530149320706U;
            aOrbiterB = RotL64((aOrbiterB * 16000139333493588429U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6302070286831566901U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12324134652758551396U;
            aOrbiterD = RotL64((aOrbiterD * 17136438281540250165U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4773478557638475048U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4031153435446078944U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 3876928995240982769U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterC, 44U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 41U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 53U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererH, 38U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // ingress from: aOperationLaneB, aInvestLaneB, aWorkLaneC
        // ingress directions: aOperationLaneB forward forced, aInvestLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aInvestLaneA
        // cross directions: aOperationLaneA backward forced, aInvestLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23561U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneB[((aIndex + 23620U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25451U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27056U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26317U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = ((aWandererD + RotL64(aScatter, 19U)) + 9914837590440975587U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 6706125076401958051U) + aNonceWordA;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 47U)) + 16570817772679258409U) + aPhaseAOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 6843705658115186948U) + aNonceWordB;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 38U)) + RotL64(aCarry, 27U)) + 16099930446791572351U) + aNonceWordD;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5420550009556030459U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5729549069420177477U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7842192631021712569U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 15590601126188675834U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13044027390998620029U;
            aOrbiterK = RotL64((aOrbiterK * 16845199115313444123U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11068338135659636772U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6584988841809544332U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1683336180438945439U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8516813219883915404U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 10647314042912492785U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 15559481057047148785U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 201691689889605304U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15512161798401184003U;
            aOrbiterH = RotL64((aOrbiterH * 11473219183982564709U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aCross, 35U) + RotL64(aOrbiterA, 51U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordE) + aPhaseAWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aNonceWordM) + aPhaseAWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 10U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterH, 39U)) + aNonceWordN);
            aWandererH = aWandererH + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 39U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31541U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 32074U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27409U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29243U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 29172U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 18U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (((aWandererA + RotL64(aIngress, 3U)) + 6733949564325516029U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 19U)) + 7304098437143918796U) + aNonceWordC;
            aOrbiterG = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 3923949518391777800U) + aNonceWordA;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 30U)) + RotL64(aCarry, 47U)) + 14243591003388927124U) + aPhaseAOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 18329498724605410406U) + aNonceWordD;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13118172167747037249U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5272025143849174212U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 9935990954321437743U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16075917179214318424U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15263590648674658399U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9918239923411740337U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13730046728289525921U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7703141464499623408U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5886009900621521987U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1382279753822135359U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 2973369221699098292U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 7440242040663550631U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11578274119583013219U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3419411247737896674U;
            aOrbiterA = RotL64((aOrbiterA * 17814942652262802991U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aCross, 27U) + RotL64(aOrbiterF, 29U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + aNonceWordM) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterG, 20U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_B seed_loop_a (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    const std::uint64_t &aPhaseBDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [seed arx]
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCB9E112DAAC5A42DULL + 0xFB28AF5E501EEEBCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC3210534E51B9AB3ULL + 0xC66060410E7CD913ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFB2875662F26215FULL + 0xE0320F2503E5B196ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD64D194FDDBD4FAFULL + 0xCFFF7848F96BA06EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x85EF97E3758247E9ULL + 0xC65A9ECFAB44F876ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE6E3263CC6B426CBULL + 0xE7C70DCB17DEBB96ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC72151F7D105A857ULL + 0xDF4249F24F9D11F8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDDC7B1AAF0277B43ULL + 0xCB9DB0A4D657A097ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFD12013E9E100977ULL + 0x9BD0F5781A69C012ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF410028FCF661E01ULL + 0x8D7B70D8238E0794ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x90BA766ADA1DF691ULL + 0x989B2378F97201AAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFB533C03514CA5D3ULL + 0xD6F4EF6A7848CFFBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9EB449BA06130131ULL + 0xB4428CCF0B9FBFABULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD650C2632AE28289ULL + 0x9F2A0A1F6D590E33ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8E904A3F47B6EECBULL + 0xC91B5131B7F8685FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEEDE72C4BB9B717BULL + 0xC87B47D3579DA538ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7780U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((aIndex + 5311U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4641U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7736U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5414U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5776U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 41U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 41U)) + 6163290588946759209U) + aPhaseBOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aScatter, 57U)) + 7342672468560105447U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 27U)) + 11574563167017282321U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 11U)) + 2254820206194758964U) + aPhaseBOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 18U)) + 1469783447473099498U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 14174828900676165088U) + aNonceWordI;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 5U)) + 16277954291890598132U) + aNonceWordN;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 14845750668693136766U) + aNonceWordL;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 46U)) + RotL64(aCarry, 47U)) + 150099699692047766U) + aNonceWordG;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1200784917165131703U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9469982764806754302U;
            aOrbiterJ = RotL64((aOrbiterJ * 17851969334511301943U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10956702761701710182U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7915506894975487807U;
            aOrbiterD = RotL64((aOrbiterD * 8874108311712727983U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17335794183733623213U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 557028996286989506U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3993359298602424281U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1597385667771002414U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4376417959915162639U;
            aOrbiterB = RotL64((aOrbiterB * 4626236858205178149U), 37U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 549770198518993876U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 756554555648070919U;
            aOrbiterK = RotL64((aOrbiterK * 16272320259614325355U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7298557532533152193U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3336802611342112013U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14679103452120080499U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2314938232094714365U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12215066333571149153U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10747052773052630601U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7762752719356805046U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6519429915769040078U;
            aOrbiterI = RotL64((aOrbiterI * 15548676502167938513U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7556691736109752918U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13731245903412646404U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 15581965016668635409U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 38U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 18U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + aNonceWordM);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 42U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + aNonceWordO) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterG, 30U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterK, 37U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14971U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((aIndex + 12558U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12508U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8729U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13176U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11685U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12138U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 14U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererG + RotL64(aIngress, 47U)) + 11177787645248006236U) + aPhaseBOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 23U)) + 3808340254579817169U) + aNonceWordH;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 28U)) + RotL64(aCarry, 43U)) + 828030667598518279U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 57U)) + 16177835921238398371U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 5518747735458708741U) + aNonceWordO;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 51U)) + 17346319082399995165U) + aNonceWordI;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 35U)) + 6397156921893030937U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 15559381654710713582U) + aPhaseBOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 10U)) + 940404446491415088U) + aNonceWordL;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8047166032048732645U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4688468645859470491U;
            aOrbiterG = RotL64((aOrbiterG * 14383536431614496369U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3710878044770337260U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 116343189456629220U;
            aOrbiterA = RotL64((aOrbiterA * 5637725064169289339U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 883908030159391659U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 18058691521694880482U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3132200449123497619U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17521015077103586117U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3668332225435714918U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12658899101297839881U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12229480388278883300U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16206524049491531816U;
            aOrbiterJ = RotL64((aOrbiterJ * 11122340196620859805U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5743265849441077466U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2812293020719282236U;
            aOrbiterK = RotL64((aOrbiterK * 8903956475200417109U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13718364781538837074U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 861529717259766236U;
            aOrbiterE = RotL64((aOrbiterE * 17019744777211266685U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4862687502126693872U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 7722024283321020761U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 18086944039541060829U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8205803118233399853U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15130160926615050422U;
            aOrbiterD = RotL64((aOrbiterD * 1454552751453996765U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 50U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterG, 34U)) + aNonceWordA) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aScatter, 10U) + aOrbiterE) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 38U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 23U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aWorkLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneC, aExpandLaneB
        // cross directions: aWorkLaneA backward forced, aOperationLaneC backward forced, aExpandLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19652U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 16453U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 19832U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16741U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19362U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17581U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21366U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 19U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (aWandererE + RotL64(aIngress, 21U)) + 6361545377408870615U;
            aOrbiterA = (aWandererB + RotL64(aCross, 13U)) + 2967245486744774933U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 26U)) + 3836634268482850139U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 47U)) + 7691642115360086297U) + aPhaseBOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 16479280384178279281U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 43U)) + 2901468732552539249U) + aPhaseBOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 5U)) + 2600353867755647475U) + aNonceWordN;
            aOrbiterF = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 5666596904781510956U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 30U)) + RotL64(aCarry, 39U)) + 16108791609267427553U) + aNonceWordO;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8389926875737312112U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1689501721163024426U;
            aOrbiterG = RotL64((aOrbiterG * 6517194895779049139U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11721701506949917719U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3963842745030140473U;
            aOrbiterC = RotL64((aOrbiterC * 6692473494944919373U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8510538243472109368U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 18281865214102080387U;
            aOrbiterJ = RotL64((aOrbiterJ * 1351546966368884609U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2259725140963665123U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11652011949557979650U;
            aOrbiterD = RotL64((aOrbiterD * 11260100762113295037U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1116085424226174473U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4725260319270802912U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4697109059565450269U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 7348945429843437036U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1249234309180653260U;
            aOrbiterI = RotL64((aOrbiterI * 3136745255820405881U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 12463505532573389603U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2304125977906510386U;
            aOrbiterA = RotL64((aOrbiterA * 9960816714791454421U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2178037443783425551U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11712110130079307683U;
            aOrbiterF = RotL64((aOrbiterF * 9797864956200779505U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10703510612147312252U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 18155460326242413483U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 6903953708987478723U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 22U)) + aOrbiterG) + aNonceWordE);
            aWandererE = aWandererE + ((RotL64(aScatter, 30U) + RotL64(aOrbiterD, 51U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterE, 41U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 42U) + aOrbiterD) + RotL64(aOrbiterF, 28U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 40U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererC, 6U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27972U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 27192U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 28042U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 32400U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27252U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26306U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27088U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCarry, 3U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 37U)) + 380024772508948442U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 14U)) + RotL64(aCarry, 21U)) + 7649029098162567210U) + aPhaseBOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 5329304598870421851U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 43U)) + 12306118665045151326U) + aNonceWordH;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 3U)) + 960751560457324256U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 35U)) + 3244070254386191876U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 60U)) + 15733408571609521746U) + aNonceWordA;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 47U)) + 17623448932647018544U) + aPhaseBOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 23U)) + 8787759896149035829U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 14741681792348288162U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8801731213568307302U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 12127126999570616489U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9872248187499779222U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15407371518644528235U;
            aOrbiterH = RotL64((aOrbiterH * 1245102406469471673U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4242060317152943062U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9942784962409917541U;
            aOrbiterC = RotL64((aOrbiterC * 888649755587764533U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7296348796484458631U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15061417216070157797U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10349554676953256231U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3233185810644297433U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9241229457641024287U;
            aOrbiterB = RotL64((aOrbiterB * 2728237515724597517U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8464051359381554575U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3307872165699029375U;
            aOrbiterJ = RotL64((aOrbiterJ * 4859663401033023433U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5482617843966711997U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4442149210462943872U;
            aOrbiterG = RotL64((aOrbiterG * 8979352218576515647U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10591636597580147381U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14925122230279312217U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15038171961638724013U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9772367878232735350U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15800661165607190092U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10493976952980533589U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 54U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 56U)) + aOrbiterJ) + aNonceWordE) + aPhaseBWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 19U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterH, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + aNonceWordP);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterA, 60U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_C seed_loop_b (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF;
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    const std::uint64_t &aPhaseDDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [seed arx]
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDF33A84CB0344129ULL + 0xD519558ACD90221DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9C566F85E6AFAB81ULL + 0xCC849CFE0A063DF1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x809E6E7468F4DEC1ULL + 0xBD853FCF8FE85CFAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEA30801918599B0DULL + 0xE68889E798754169ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEF16259283472D87ULL + 0xC1013B7FF68656E7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE9CEA414E8A556E9ULL + 0x822BB8E7E0FF3474ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9D339A77651F46F5ULL + 0xD34D781B09B17065ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8BDE58B9AEBFBD97ULL + 0xB9A11B4EB0CFDED2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9C074FB80C48ACB5ULL + 0xDA630C37BFD1683FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD3C5CEEA0A891CF1ULL + 0x8E378E322DD22315ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAC50C31FC3DA9C59ULL + 0x9B97A742CA7C6428ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFE1272F8844A81C9ULL + 0xABB364B7CB0D4D4FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD7C0ECF8BAE27D69ULL + 0xC502BDF3BEB3226AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCAAD537290C8BDF9ULL + 0xE0252B93C8CAD40AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x96E756981B7E27AFULL + 0x9D2AFA989D88B22DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB6EE79155EA3358DULL + 0xA38AD0C57E9D5EE3ULL);
    // GSeedRunSeed_D seed_loop_d (start)
    {
        // GSeedRunSeed_D seed_loop_d lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneA, aInvestLaneA, aOperationLaneB, aInvestLaneB, aOperationLaneC, aInvestLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aInvestLaneA, aInvestLaneB, aInvestLaneC, aInvestLaneD
    
        // seed_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4313U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 2584U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3962U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4165U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4034U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4253U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 24U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 11210042748013785976U) + aNonceWordH;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 4584747303233477454U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 21U)) + 8878765929792969517U) + aNonceWordK;
            aOrbiterD = ((aWandererI + RotL64(aCross, 37U)) + 2172232330280041122U) + aNonceWordB;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 50U)) + 8378937026022264016U) + aPhaseDOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 8683007464695824208U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 29U)) + 9564352997357118134U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11713878436769887528U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8052917623074021077U;
            aOrbiterA = RotL64((aOrbiterA * 7450115139081623477U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7720597162792145185U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2602847785328475621U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14065077077207224525U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17813669222300509724U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8724263063156573013U;
            aOrbiterJ = RotL64((aOrbiterJ * 3632927017737834359U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6882429835961613492U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13213313479525717359U;
            aOrbiterI = RotL64((aOrbiterI * 2411431247725974895U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2401526093648669573U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 3616448566579979749U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 13323155103752121393U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18268262471839710401U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5116424918948694752U;
            aOrbiterB = RotL64((aOrbiterB * 7641143782996332069U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11405305689555640431U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12427591396711015574U;
            aOrbiterC = RotL64((aOrbiterC * 8112834135715541223U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA) + aPhaseDWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 50U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aNonceWordP) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6391U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 7015U)) & S_BLOCK1], 52U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6301U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((aIndex + 6866U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6017U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9919U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8552U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 40U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (aWandererE + RotL64(aIngress, 60U)) + 15652862298542575895U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 37U)) + 16925323928418184554U) + aNonceWordP;
            aOrbiterG = (((aWandererK + RotL64(aCross, 3U)) + 4413861484961668394U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 23U)) + 2215946422098155969U) + aNonceWordH;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 14975185533513111110U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 9711613814905834552U) + aNonceWordJ;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 13154957291850149471U) + aPhaseDOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5058313016418534840U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15011423472941211620U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 6125316151731105673U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2030053257469580168U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 150530795186791193U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 11106050063717096073U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10878237472104183427U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11724672539469573109U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 16158741837357985395U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9589700906445846956U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1367381624958248949U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8459515089081211977U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12003215666757518106U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11232479330848006729U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10993290955464593033U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13013910456628561621U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6092509838924105265U;
            aOrbiterC = RotL64((aOrbiterC * 805601154718006061U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11999225836250312801U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14421271973875748413U;
            aOrbiterK = RotL64((aOrbiterK * 9529010940887430157U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterF, 29U));
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 51U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 50U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterH, 12U)) + aNonceWordO) + aPhaseDWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneA, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12073U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 11936U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13291U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14003U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 11149U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = (aWandererA + RotL64(aCross, 19U)) + 826930775230515406U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 5137814617363250861U) + aPhaseDOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 14761561947426681616U) + aNonceWordK;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 26U)) + 12773023438753662590U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 51U)) + 7331345852207096322U;
            aOrbiterC = ((((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 3899381212671247460U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 11U)) + 10072004147620068599U) + aNonceWordH;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3424585039401897560U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8246760141625966321U;
            aOrbiterG = RotL64((aOrbiterG * 11478879365443736383U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3655992860610853290U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11154618022505863898U;
            aOrbiterD = RotL64((aOrbiterD * 4791494171286145231U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15629361991059709973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10842068502278489664U;
            aOrbiterC = RotL64((aOrbiterC * 17223002513104960799U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5571312349016336686U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 589313823745748879U;
            aOrbiterB = RotL64((aOrbiterB * 1356685926549786027U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13633457935771935260U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12684602052812183096U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4689206269919806711U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 5711307583717354204U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7181854170553728211U;
            aOrbiterE = RotL64((aOrbiterE * 9835601115561325911U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1884620014396115821U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1471516373272364262U;
            aOrbiterH = RotL64((aOrbiterH * 5126319375714848029U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + aNonceWordJ) + aPhaseDWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 21U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + aNonceWordA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterE, 58U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 4
        // ingress from: aInvestLaneA, aWorkLaneA, aOperationLaneB
        // ingress directions: aInvestLaneA forward forced, aWorkLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 18393U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 17193U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 17711U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19994U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 18368U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 9774364261626083532U) + aPhaseDOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 18059001521926116420U) + aPhaseDOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 10615626210406381148U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 12U)) + 10536484278007898620U) + aNonceWordB;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 5U)) + 13320663045139972700U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 37U)) + 17127001787268166583U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 43U)) + 16742574590844166551U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8347719720758228053U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13502468705946051986U;
            aOrbiterG = RotL64((aOrbiterG * 13822952083584784695U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3512687886188904904U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 495660316165795934U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6724596801190194913U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5092722552034477356U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15641128019608284015U;
            aOrbiterI = RotL64((aOrbiterI * 3621036395703527059U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 15421873776811085458U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17978775513204574125U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18359600395119440183U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 16617179197537669849U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1931805387534012528U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 3400139345857733775U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9544923119559308431U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12930999400470173353U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 16791006919271490005U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13673733276226249890U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2032263473309124738U;
            aOrbiterD = RotL64((aOrbiterD * 3088728329261360607U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 20U) + aOrbiterD) + RotL64(aOrbiterH, 53U)) + aNonceWordI);
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + RotL64(aOrbiterG, 41U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + aPhaseDWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 14U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aNonceWordC) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 5
        // ingress from: aInvestLaneB, aWorkLaneB, aOperationLaneC
        // ingress directions: aInvestLaneB forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aInvestLaneA, aWorkLaneA
        // cross directions: aInvestLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25580U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((aIndex + 25147U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 27065U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25740U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24019U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 41U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererE + RotL64(aIngress, 3U)) + 8975885703279267062U) + aNonceWordE;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 51U)) + 8664844915562660637U) + aNonceWordG;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 12281774799736296726U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 15347461352311329726U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 57U)) + 12967500561828907834U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 5002833859280402726U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 10U)) + 11908257536954668983U) + aPhaseDOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17017174811949227162U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16851323125613931180U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12446990992858763577U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13469326957728686706U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5228638551056105241U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13369947664646167255U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11945166198089308564U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16268645041872996022U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 5391448793718370911U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14781204627695095701U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5365325354838101092U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8017284997946310807U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 563147416025715953U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14660867395395625851U;
            aOrbiterC = RotL64((aOrbiterC * 4769458126865307103U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3168989056355712105U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16179131669773665579U;
            aOrbiterG = RotL64((aOrbiterG * 5641461617066671723U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4160220074225527179U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8597134686962559111U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 639572585431474015U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 54U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterA, 23U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + aNonceWordA) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 6
        // ingress from: aInvestLaneC, aInvestLaneA, aOperationLaneD
        // ingress directions: aInvestLaneC forward forced, aInvestLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aInvestLaneB, aExpandLaneB
        // cross directions: aInvestLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 32587U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneA[((aIndex + 28263U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27387U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27922U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29920U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 3U)) + 4848316479321533394U) + aNonceWordA;
            aOrbiterD = (aWandererK + RotL64(aCross, 51U)) + 6919360256662636195U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 9897013582181108544U) + aNonceWordC;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 7319353809896158678U) + aNonceWordI;
            aOrbiterF = ((aWandererD + RotL64(aCross, 57U)) + 2848175435514849859U) + aNonceWordL;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 6967780718720437934U) + aPhaseDOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 20U)) + 10143884766603388136U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8675965006150972051U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16350117755560994281U;
            aOrbiterA = RotL64((aOrbiterA * 15072308930382994425U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17976597517118423760U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1399631141355370237U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16537788276543236833U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3590613762034716792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5134624314245932157U;
            aOrbiterD = RotL64((aOrbiterD * 13077589037975283371U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10082236952942943654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4015535035905433450U;
            aOrbiterC = RotL64((aOrbiterC * 4961808568701908559U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 611474103801573800U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5786708483794098001U;
            aOrbiterH = RotL64((aOrbiterH * 7694007039340089267U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5201943497363274455U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9282160506938328489U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5368182164239021367U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4932320527498940158U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11576526341731392916U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1712051774729439363U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 14U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterC, 51U)) + aNonceWordF) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterE, 36U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 11U)) + aOrbiterF) + aNonceWordG);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterG, 19U));
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_D seed_loop_d (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    const std::uint64_t &aPhaseEDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseEConstants.mIngress;
    const std::uint64_t &aPhaseEDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseEConstants.mScatter;
    const std::uint64_t &aPhaseEDomainWordCross = pWorkSpace->mDomainBundle.mPhaseEConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [seed arx]
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBEFAB7256F8A32A1ULL + 0xF77FCB0497E1FFFBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8D861675122985F5ULL + 0xA396A100099728E1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB37FE9E0D934E3DDULL + 0xA558E32695E206B1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x95A2FDDC7A2D07D9ULL + 0xCACFFD65AF0972DAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD977B364E3506A9FULL + 0x96D07CF49B066EE6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD1EFBAD6C82CCBE7ULL + 0xBC648F7BEA2038F7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDE3EE210101A7FC7ULL + 0xC7E8883F2BE7AC21ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA8672B25BB084DA5ULL + 0x854752F6A03FD43DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x808BEBB38AAC9637ULL + 0xA9B8B744FB3DFF71ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE5F6B90489620003ULL + 0x95BF296718CB6592ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA04BAE4C566957E1ULL + 0x8EF265254937062BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA9644DF62A7EF0E7ULL + 0xCAAE22A876C1848BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xADBD1AC21613C3EBULL + 0xDAB4899BC507B7E2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAEDB1CA633867729ULL + 0x8EC3B0AB978B59C0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE955A7958FC993CFULL + 0xE192AB7B1C49C62BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA507813C62B76545ULL + 0xB013FB0C2075B211ULL);
    // GSeedRunSeed_E seed_loop_e (start)
    {
        // GSeedRunSeed_E seed_loop_e lane group
        // read from: aInvestLaneA, aInvestLaneB, aFireLaneA, aInvestLaneC, aInvestLaneD, aFireLaneB, aSnowLaneA, aFireLaneC, aFireLaneD, aSnowLaneB, aWorkLaneA, aOperationLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aOperationLaneC, aWorkLaneD
        // write to: aSnowLaneA, aSnowLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_e loop 1
        // ingress from: aInvestLaneA, aInvestLaneB, aFireLaneA
        // ingress directions: aInvestLaneA forward forced, aInvestLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneC, aInvestLaneD, aFireLaneB
        // cross directions: aInvestLaneC backward forced, aInvestLaneD backward forced, aFireLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 4241U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneB[((aIndex + 4311U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 998U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3632U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4407U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1115U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 40U)) ^ (RotL64(aPrevious, 13U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = (aWandererB + RotL64(aIngress, 30U)) + 6024062041314952357U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 5U)) + 18340757093658015585U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 11911120493880346751U;
            aOrbiterC = (aWandererH + RotL64(aCross, 43U)) + 17428074353884654439U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 12790849760814795936U) + aNonceWordE;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 52U)) + RotL64(aCarry, 57U)) + 12633397052172117800U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 35U)) + 11946150433665237945U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 47U)) + 16842157900909419285U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 27U)) + 14186235783224155962U) + aNonceWordC;
            aOrbiterA = (aWandererE + RotL64(aCross, 57U)) + 13284904542579767591U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 13U)) + 11609181965078844357U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9628562297095374984U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7850281529011259759U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17611485102925470357U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 257458718073794527U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10693404545773519306U;
            aOrbiterE = RotL64((aOrbiterE * 14821443722828498323U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3430519236533871460U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6183054506953198055U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 6121082743789970911U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 2905610989884221654U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4472163910775333862U;
            aOrbiterK = RotL64((aOrbiterK * 7770678426310856745U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16870142883133769663U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1403692060594816451U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9740854430251597879U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16904169913507057108U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4773518591580333357U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5306070307776061267U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6528141733853494275U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11254806909313951442U;
            aOrbiterH = RotL64((aOrbiterH * 6316669786405548827U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6857506858448143407U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2855763534355983644U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 16881334940165182415U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12328391751024624740U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16475072086109949522U;
            aOrbiterD = RotL64((aOrbiterD * 15218626930666825883U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15505670341076785424U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6972128419331939330U;
            aOrbiterC = RotL64((aOrbiterC * 12206069109180246067U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7151546362283646210U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6024062041314952357U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 10243806128059850493U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 48U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterA, 6U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 19U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterD, 27U));
            aWandererE = aWandererE + ((((RotL64(aCross, 12U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 41U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterD, 13U)) + aNonceWordD) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterG, 4U)) + aNonceWordK) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterE, 39U));
            aWandererD = aWandererD + ((RotL64(aCross, 48U) + aOrbiterC) + RotL64(aOrbiterE, 29U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 21U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 2
        // ingress from: aSnowLaneA, aInvestLaneC, aInvestLaneD, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aInvestLaneC forward forced, aInvestLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneA, aInvestLaneB, aFireLaneD
        // cross directions: aInvestLaneA backward forced, aInvestLaneB backward forced, aFireLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8873U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneC[((aIndex + 10544U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 6238U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9563U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 10453U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9600U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10756U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 27U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 3339283916456813609U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 43U)) + 11339086426180649584U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 46U)) + 16819191669329316585U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 21U)) + 8361916937762630725U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 3U)) + 18031328374429899857U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 29U)) + 18261756894092897276U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 4250319792907645666U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 24U)) + 1492411503643460886U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 19U)) + 17369549067879344180U) + aNonceWordE;
            aOrbiterK = (aWandererF + RotL64(aCross, 11U)) + 7301713524358676722U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 2985193736033012535U) + aNonceWordL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14086975808140927408U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10390516547834639800U;
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 18205555540941493267U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16967799565443938873U;
            aOrbiterC = RotL64((aOrbiterC * 3009081009044782443U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9209505304067579944U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3522631966146762306U;
            aOrbiterD = RotL64((aOrbiterD * 3441982898533162599U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8811497120829041188U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 14707301680850257294U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 11383709499376464085U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10080595991787801029U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6822892187784299166U;
            aOrbiterB = RotL64((aOrbiterB * 7417016898027778287U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1981637172055758689U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16463077485583119324U;
            aOrbiterK = RotL64((aOrbiterK * 2876782050665869121U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8383837717361569465U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2788511294985017326U;
            aOrbiterI = RotL64((aOrbiterI * 2809163242875130677U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3529607472855930041U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8850940802020173766U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 7821450253655655943U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7469160295100147267U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16973986572163482061U;
            aOrbiterJ = RotL64((aOrbiterJ * 15660743778376905023U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12371372942863279718U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12098525148034303633U;
            aOrbiterE = RotL64((aOrbiterE * 11234127652230231751U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5138683482859889480U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3339283916456813609U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 10975353228235695455U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 20U)) + aOrbiterG) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aScatter, 48U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterK, 23U)) + aPhaseEWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterI, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_e loop 3
        // ingress from: aSnowLaneB, aInvestLaneA, aWorkLaneA
        // ingress directions: aSnowLaneB forward forced, aInvestLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aSnowLaneA, aInvestLaneC
        // cross directions: aSnowLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14073U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneA[((aIndex + 15719U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 11805U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15152U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12695U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 47U)) + (RotL64(aPrevious, 34U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 35U)) + 14499676118633326000U) + aNonceWordC;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 17191273593018552288U) + aNonceWordP;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 58U)) + 4085176294948097737U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 11112671474158908186U) + aPhaseEOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 41U)) + 8745787969012266485U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 18074049663777707948U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 50U)) + 2543758649719164688U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 21U)) + 4659584749412700523U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 29U)) + 974639159259871273U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 43U)) + 9211220687971081987U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 27U)) + 8567024626862182714U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5803002132294840900U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11968489432878148467U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4501441062617123165U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9470807228394903442U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1692347973120388469U;
            aOrbiterD = RotL64((aOrbiterD * 17433393164156231575U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16510815732690193145U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 755159406833096510U;
            aOrbiterE = RotL64((aOrbiterE * 14091736464659561165U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1518824876475937620U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 701225390867330446U;
            aOrbiterG = RotL64((aOrbiterG * 12264618860580199927U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8425976693733003889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7182176375442410367U;
            aOrbiterJ = RotL64((aOrbiterJ * 8860605703761731859U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4546566785167467924U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2593340999038753749U;
            aOrbiterF = RotL64((aOrbiterF * 10152461487764567563U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9756331608356622299U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 5511625814747641978U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 4806076157539829529U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8694400787420160733U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12648969491371382682U;
            aOrbiterC = RotL64((aOrbiterC * 5346585704222643759U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15261238546696118531U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14236129054778329471U;
            aOrbiterB = RotL64((aOrbiterB * 11789581469516267749U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16251500056378064213U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 790320176607605195U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 15706130623435648555U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17114773669444878655U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 14499676118633326000U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 8095707555083587081U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 39U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 4U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterF, 51U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 40U) + aOrbiterJ) + RotL64(aOrbiterF, 41U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterB, 28U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterE, 23U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterD);
            aWandererD = aWandererD + (((((RotL64(aCross, 57U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordH) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 4
        // ingress from: aOperationLaneA, aSnowLaneA, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aSnowLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aSnowLaneB, aInvestLaneD
        // cross directions: aSnowLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18341U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneA[((aIndex + 16392U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16489U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17650U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneD[((aIndex + 21013U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 39U)) + (RotL64(aIngress, 26U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (aWandererC + RotL64(aPrevious, 43U)) + 3970829908171131502U;
            aOrbiterK = ((((aWandererJ + RotL64(aCross, 22U)) + RotL64(aCarry, 5U)) + 7040283759419531991U) + aPhaseEOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aWandererK + RotL64(aScatter, 11U)) + 11856292169397052901U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 35U)) + 819598588791819022U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 3U)) + 2176451710970866848U;
            aOrbiterD = ((((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 6454704928613390494U) + aPhaseEOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 29U)) + 11792122387218053841U) + aNonceWordN;
            aOrbiterB = (aWandererE + RotL64(aCross, 39U)) + 9254780213489752211U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 54U)) + 16591812589999846482U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 1471246223935074832U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 41U)) + 1424843083106386453U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1856469958050891629U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6331743690452052712U;
            aOrbiterA = RotL64((aOrbiterA * 15327924647897459645U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10351075711345476487U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9518585245330480185U;
            aOrbiterE = RotL64((aOrbiterE * 3792179827396760391U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17787514620244712033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14182328067398162557U;
            aOrbiterF = RotL64((aOrbiterF * 18107337388659070197U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12798088948801072444U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9563215159275202323U;
            aOrbiterB = RotL64((aOrbiterB * 7058145016617349141U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9904919772580498232U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16579777394992143043U;
            aOrbiterK = RotL64((aOrbiterK * 10516761340320196661U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6344049286854588503U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3531503618941046788U;
            aOrbiterC = RotL64((aOrbiterC * 10855385899703024105U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11334308840132700377U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11093833870078787770U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 16105889714648555755U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3831491136025364271U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12505259454860591372U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6135450888433504093U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2210290810330253363U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10786160915224323113U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 799075068398619501U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7791474921127653867U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1046454625851499863U;
            aOrbiterD = RotL64((aOrbiterD * 18040454167287729591U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14636813124839719351U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 3970829908171131502U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 2737568880005765517U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 56U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterE, 13U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterD, 26U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterA, 53U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterA, 39U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterK, 47U));
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + aPhaseEWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 60U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_e loop 5
        // ingress from: aOperationLaneB, aSnowLaneB, aWorkLaneC
        // ingress directions: aOperationLaneB forward forced, aSnowLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aSnowLaneA
        // cross directions: aOperationLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25430U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((aIndex + 22283U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 23679U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23659U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25757U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 20U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 5U)) + 12380376990224645149U) + aNonceWordP;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 60U)) + RotL64(aCarry, 29U)) + 18296928500297384014U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 47U)) + 3550626816361145100U) + aNonceWordK;
            aOrbiterK = (aWandererA + RotL64(aIngress, 57U)) + 2667792936946706027U;
            aOrbiterA = (aWandererE + RotL64(aCross, 19U)) + 12020969779370926953U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 53U)) + 737340727886903447U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 44U)) + 1681797651799760502U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 13U)) + 2956186342689489064U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 21U)) + 1876852870402977177U) + aPhaseEOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 6433205819353555071U) + aNonceWordL;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 9065076854974222998U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3254410578766789992U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2005081975473815576U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9947701153722014085U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15992999234834560419U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3458344156815120948U;
            aOrbiterA = RotL64((aOrbiterA * 1668460113964608051U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17069783053664877727U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1260234710193913099U;
            aOrbiterI = RotL64((aOrbiterI * 4561226779897414381U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3825186451876061335U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2905344294992827535U;
            aOrbiterF = RotL64((aOrbiterF * 2469896090698580795U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18141402347899180617U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8760129857609925066U;
            aOrbiterJ = RotL64((aOrbiterJ * 2507999156108123047U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 594052473780678210U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 13216719212966128379U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10691355329696722303U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10029948739466316169U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11912428807431992996U;
            aOrbiterG = RotL64((aOrbiterG * 85016510811938307U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8735634019801417287U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12785916159063273545U;
            aOrbiterE = RotL64((aOrbiterE * 1161917531260663357U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 367752057919802452U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3961036242431041564U;
            aOrbiterK = RotL64((aOrbiterK * 16352646009782597315U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3858415336170090719U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14325258358254321551U;
            aOrbiterH = RotL64((aOrbiterH * 12080431158781060059U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16872184337970977180U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12380376990224645149U;
            aOrbiterC = RotL64((aOrbiterC * 16559121155413059221U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 12U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterK, 60U));
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterC, 51U)) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterG, 53U));
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterH, 6U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 24U) + RotL64(aOrbiterA, 35U)) + aOrbiterG) + aNonceWordJ) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 41U)) + aPhaseEWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 6
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32674U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 30828U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31381U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27546U)) & S_BLOCK1], 18U) ^ RotL64(aInvestLaneB[((aIndex + 28790U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 26U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 10726035965553989335U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 967354339530195662U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 3U)) + 10834593005478605624U;
            aOrbiterG = (aWandererH + RotL64(aCross, 47U)) + 1012888282838656933U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 56U)) + 15283530351725183253U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 11724495956731703750U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 23U)) + 4288330117317505776U) + aNonceWordI;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 51U)) + 10894778070022873473U) + aNonceWordH;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 35U)) + 15563886747621617467U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 14U)) + 11182488628562891937U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aWandererI + RotL64(aScatter, 29U)) + 10420140066310588580U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11775138062167543111U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16545391898578161683U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 14588306527161321535U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1550144656312299266U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 14903504853138279883U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8003033561266164387U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 309935535526750396U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13991265868040011411U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 2887531132228588441U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 1755976294857114222U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2259275858478396846U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 7416165760067878161U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4838175912944552936U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12307900457200936013U;
            aOrbiterH = RotL64((aOrbiterH * 14719363144850838805U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 18025411832912225805U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 981375022769564523U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15869361544011831483U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3174014054982742562U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8119692378748963609U;
            aOrbiterB = RotL64((aOrbiterB * 3072354179707448489U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14502863160788675807U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1207582534593709516U;
            aOrbiterA = RotL64((aOrbiterA * 3045412087535529357U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5838011917777875072U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 434594114594643600U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 1591023655239709931U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15711060039063734443U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8307150522686198490U;
            aOrbiterK = RotL64((aOrbiterK * 2082452039297764679U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5805686529930815226U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10726035965553989335U;
            aOrbiterI = RotL64((aOrbiterI * 5563221485243331689U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 36U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 3U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 23U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 50U)) + aOrbiterH) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 27U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aIngress, 48U) + RotL64(aOrbiterD, 57U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterH, 5U)) + aNonceWordN);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 39U) + RotL64(aOrbiterK, 36U)) + aOrbiterB) + aNonceWordM) + aPhaseEWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 53U)) + aOrbiterK) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_E seed_loop_e (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    const std::uint64_t &aPhaseFDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseFConstants.mIngress;
    const std::uint64_t &aPhaseFDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseFConstants.mScatter;
    const std::uint64_t &aPhaseFDomainWordCross = pWorkSpace->mDomainBundle.mPhaseFConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [seed arx]
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB1ED044990765019ULL + 0xFA951806ACFA09BDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8047BDED4C8FDD47ULL + 0x9EF0F190F72F719BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF681186DF66F41ABULL + 0xD351B75D332D47BDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x94F100EC1391FEC1ULL + 0xDD9213817A2A785EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9576EDAB2C226011ULL + 0x8ABCCB658A98C698ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBE6D22CEE356DEC7ULL + 0xED1420DC277B6C09ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9121741F8C62FEB9ULL + 0xF6586D5AA7EE9084ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF5AEDECE8403DC0FULL + 0xB46D432FA4A3ABA2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFE94E8B5FD4503C1ULL + 0xAB87CD008A2076A9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8C46FBAC1BAC44F1ULL + 0xEBB485F0AA80F2FCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAE87FC686A5DA38BULL + 0xDAEDBCB1FE892BC3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8A6319977FE7124FULL + 0xE087E0DEBB7D4B85ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBFCE1B13EAAD2117ULL + 0xDCB5776AD7CFFE16ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE2C03C7CD74A5A39ULL + 0xDA6D07E5C47970BBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x90C7130F9BCFDEC3ULL + 0x9FA7E73D431E9B22ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE50B1A0BC6685FDDULL + 0xC63CF6964608FADFULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aSnowLaneA, aFireLaneC, aFireLaneD, aSnowLaneB, aInvestLaneA, aExpandLaneA, aInvestLaneB, aExpandLaneB, aInvestLaneC, aExpandLaneC, aInvestLaneD
        // write to: aSnowLaneA, aSnowLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2114U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 95U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4877U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 970U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4997U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4346U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 19U)) + (RotL64(aCarry, 50U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 2617613537256538553U) + aNonceWordG;
            aOrbiterA = (((aWandererK + RotL64(aCross, 4U)) + RotL64(aCarry, 39U)) + 16642868916835132715U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aPrevious, 57U)) + 10860291124337073254U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 47U)) + 6432511273906902472U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 23U)) + 7505375005848241910U;
            aOrbiterK = (aWandererD + RotL64(aCross, 29U)) + 11086616004678821329U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 3298830587569881951U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 18U)) + 9775143140064220979U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 53U)) + 4147601326580823120U) + aNonceWordD;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12245920269898100415U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8391940489176734499U;
            aOrbiterE = RotL64((aOrbiterE * 9119606167674098007U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17876893379544668477U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 18301882058180370541U;
            aOrbiterI = RotL64((aOrbiterI * 16680384667098921309U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6869225862715140102U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15404118372589259800U;
            aOrbiterD = RotL64((aOrbiterD * 5766851935950389915U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17757381020518233814U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17677969146092374455U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 3469432916562405063U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15783378556632870114U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5792858258663697864U;
            aOrbiterK = RotL64((aOrbiterK * 12008981883482080427U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11737803388202260296U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16001927091970715330U;
            aOrbiterB = RotL64((aOrbiterB * 3062030309852922061U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1749586939123286632U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 6169421068855905938U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 12374789910763348695U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10073586820719728062U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17744171227198661555U;
            aOrbiterC = RotL64((aOrbiterC * 10658375268803957647U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 1149819647337612792U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7725598665625892006U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15097586655234391559U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 54U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 46U)) + aOrbiterD) + aNonceWordB) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 6U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + aNonceWordO);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + aNonceWordK);
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 39U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterK, 60U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 42U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6668U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 5486U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8250U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10275U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8798U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6142U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9556U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 11U)) + 439898681482066326U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 39U)) + 17362083676671776094U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 57U)) + 6418499837265155024U) + aNonceWordK;
            aOrbiterB = (aWandererA + RotL64(aIngress, 29U)) + 17262244253027454972U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 34U)) + 2382066162993139503U) + aNonceWordH;
            aOrbiterE = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 14345808395587174135U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 7534743166385552851U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 16994453324688523966U) + aNonceWordC;
            aOrbiterG = (aWandererI + RotL64(aIngress, 6U)) + 7079553728544045092U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3562822704508440641U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13990892681975857821U;
            aOrbiterI = RotL64((aOrbiterI * 8352929306654078795U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1796728922368577238U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6605161260520067178U;
            aOrbiterK = RotL64((aOrbiterK * 8147537646591674091U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13994083795942328918U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6144523182899107711U;
            aOrbiterE = RotL64((aOrbiterE * 4153879991344611283U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12247462325297436642U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1065809332002012789U;
            aOrbiterB = RotL64((aOrbiterB * 5496601177032953251U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10147919864511540753U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17138553441127273354U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5773875596275267871U), 47U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 2653924016109573974U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6254416952351699582U;
            aOrbiterH = RotL64((aOrbiterH * 12756861659704947257U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 813046408080197079U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9624466135414123483U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6960320253124395015U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 972586705850825744U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 155283774901960223U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 9928051687724257041U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18200100644751360406U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1168426822045686004U;
            aOrbiterJ = RotL64((aOrbiterJ * 5867027156069481313U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 58U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD + (((((RotL64(aCross, 43U) + RotL64(aOrbiterE, 6U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aNonceWordO) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterB, 41U)) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterI, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 27U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 23U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aIngress, 24U) + aOrbiterE) + RotL64(aOrbiterH, 12U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 20U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11376U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 11999U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 16236U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15517U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((aIndex + 11842U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 42U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (((aWandererG + RotL64(aIngress, 6U)) + 1364174714924216027U) + aPhaseFOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 13561796874229506613U) + aNonceWordA;
            aOrbiterB = (aWandererD + RotL64(aCross, 47U)) + 11845572344206238305U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 11U)) + 15762708240326773763U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 19U)) + 1157119665207900473U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 6823546624372055260U) + aPhaseFOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 51U)) + 14465564210523945121U) + aNonceWordI;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 26U)) + RotL64(aCarry, 35U)) + 10667464548080807531U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 39U)) + 13445737493224316575U) + aNonceWordB;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3009837893785957665U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2886920524111083752U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15308180928967762543U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 10886177449328249656U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15067759884678100433U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5724566815989860041U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 18307930462682331536U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8791864377579255801U;
            aOrbiterH = RotL64((aOrbiterH * 9265158882471421767U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 805797468642992351U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5743305867058244964U;
            aOrbiterD = RotL64((aOrbiterD * 16263000753351131717U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17102025528234481273U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1841579177327486899U;
            aOrbiterC = RotL64((aOrbiterC * 3841603385577825265U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2189493507896508972U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 18209567010094914374U;
            aOrbiterI = RotL64((aOrbiterI * 3737080408976852351U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6697069234216868330U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 927471474577415372U;
            aOrbiterA = RotL64((aOrbiterA * 10680760991009199309U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13155854301197725408U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1014625081915435892U;
            aOrbiterE = RotL64((aOrbiterE * 11592754232949990435U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 12697209921410914931U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11555096613655648647U;
            aOrbiterK = RotL64((aOrbiterK * 4598821388864997089U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 14U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 10U)) + aOrbiterC) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterI, 37U));
            aWandererC = aWandererC + (((RotL64(aCross, 34U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterB, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + aNonceWordK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterI, 43U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 28U) + aOrbiterH) + RotL64(aOrbiterA, 14U)) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 5U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneA, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aSnowLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21132U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneA[((aIndex + 20138U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20708U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17362U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19754U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 19U)) + (RotL64(aPrevious, 6U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 4848316479321533394U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 6919360256662636195U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 6U)) + 9897013582181108544U) + aPhaseFOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 13U)) + 7319353809896158678U) + aNonceWordJ;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 23U)) + 2848175435514849859U) + aNonceWordB;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 37U)) + 6967780718720437934U) + aNonceWordL;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 53U)) + 10143884766603388136U) + aNonceWordD;
            aOrbiterB = (aWandererE + RotL64(aScatter, 29U)) + 8675965006150972051U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 48U)) + RotL64(aCarry, 19U)) + 16350117755560994281U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17976597517118423760U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1399631141355370237U;
            aOrbiterG = RotL64((aOrbiterG * 16537788276543236833U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3590613762034716792U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5134624314245932157U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 13077589037975283371U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10082236952942943654U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 4015535035905433450U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4961808568701908559U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 611474103801573800U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5786708483794098001U;
            aOrbiterJ = RotL64((aOrbiterJ * 7694007039340089267U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5201943497363274455U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9282160506938328489U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5368182164239021367U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4932320527498940158U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11576526341731392916U;
            aOrbiterF = RotL64((aOrbiterF * 1712051774729439363U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10790691517638887125U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16280649213607464422U;
            aOrbiterB = RotL64((aOrbiterB * 10756733801499471873U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9553716940667712810U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11827518270964003341U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 1322489827908132831U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16777463701235809321U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3375489084588454149U;
            aOrbiterK = RotL64((aOrbiterK * 3335010977457647307U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 26U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterD, 21U));
            aWandererE = aWandererE + (((RotL64(aScatter, 34U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 30U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterA, 5U)) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterB, 43U)) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 20U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneB, aInvestLaneC
        // ingress directions: aExpandLaneB forward forced, aSnowLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aSnowLaneA
        // cross directions: aExpandLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25130U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneB[((aIndex + 23255U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25941U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24346U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((aIndex + 26355U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 36U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererE + RotL64(aScatter, 5U)) + 6467297102954816305U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 23U)) + 7921154109831114952U) + aNonceWordA;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 13U)) + 5701131763215638919U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 34U)) + 10022999076719002684U) + aNonceWordP;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 4367135243038982316U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 14445846824810383592U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 39U)) + 7683697954545773253U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 44U)) + RotL64(aCarry, 53U)) + 17517006750428030899U) + aNonceWordI;
            aOrbiterE = ((aWandererF + RotL64(aCross, 57U)) + 2052484792684025476U) + aNonceWordN;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6279463052085808926U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 679280153651813684U;
            aOrbiterH = RotL64((aOrbiterH * 3047031560593583881U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2939516520188460569U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1960616434964712325U;
            aOrbiterJ = RotL64((aOrbiterJ * 15145998415466343039U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12273819390719947361U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5685033154709449397U;
            aOrbiterB = RotL64((aOrbiterB * 9845666295874714959U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9314494172199500653U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15757631834636427621U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15483543888965744529U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10878078046389399574U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3583495913766365232U;
            aOrbiterG = RotL64((aOrbiterG * 2913540984990155225U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 7385544065754622301U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 16839599460207922881U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 240651605910592561U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13038163804940349251U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2587538594933924000U;
            aOrbiterA = RotL64((aOrbiterA * 3091149760401278671U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13109518583364738004U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2447689055742474261U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12100180201235703193U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5752044906692668618U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6637725371036522120U;
            aOrbiterD = RotL64((aOrbiterD * 6021986525167161115U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 18U) + aOrbiterA) + RotL64(aOrbiterJ, 53U));
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterH, 4U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 46U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + aNonceWordK);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterC) + aNonceWordO) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 34U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28609U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 29222U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 28363U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28557U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 32762U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 27U)) + (RotL64(aPrevious, 13U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 17074147006464019918U) + aNonceWordD;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 13U)) + 10559516626129419928U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 20U)) + 13280363679503946221U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 51U)) + 17657115422132457413U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 13325837013304973008U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 3059707750486106037U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 56U)) + 4529045702503050852U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 43U)) + 10726578475550904292U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 39U)) + 14832537837996659885U) + aNonceWordA;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 220094417441809246U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15343130035105342194U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 7984652435043810845U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16592263353426409884U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15649290906447931918U;
            aOrbiterF = RotL64((aOrbiterF * 8405875177836650731U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11437410545843708269U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5859769136073011444U;
            aOrbiterJ = RotL64((aOrbiterJ * 1065016088086441107U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15188064100307340341U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4367466521843260049U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15916715854192820923U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8482617283860566845U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2585745804937342972U;
            aOrbiterE = RotL64((aOrbiterE * 8267269625632139809U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1687641344403425541U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13667916445979421400U;
            aOrbiterA = RotL64((aOrbiterA * 8191322670355590027U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7684258716388029228U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14764266202380443369U;
            aOrbiterG = RotL64((aOrbiterG * 1746254773647650741U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12685190466981675661U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9958374400222383893U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12696606920219838929U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1352584794098160330U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16057453941015251708U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 6051546505117202495U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 52U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 42U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + aNonceWordK) + aPhaseFWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 23U)) + aOrbiterE) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterD, 10U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + aNonceWordG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterA, 53U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterA, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_F seed_loop_f (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aSnowLaneC = pWorkSpace->mSnowLaneC;
    [[maybe_unused]] std::uint8_t *aSnowLaneD = pWorkSpace->mSnowLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF;
    const std::uint64_t &aPhaseHDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseHConstants.mIngress;
    const std::uint64_t &aPhaseHDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseHConstants.mScatter;
    const std::uint64_t &aPhaseHDomainWordCross = pWorkSpace->mDomainBundle.mPhaseHConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [seed arx]
    [[maybe_unused]] std::uint8_t *mSource = pWorkSpace->mSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA6B3D4D97A017A19ULL + 0xFA7232DAC18B0A9FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA337F3230D3B0A19ULL + 0xFA5685C964AC6F81ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA56C8E1AC761A9A9ULL + 0xF0F381605114431EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB41F52C683F3F25DULL + 0x8C6ABB73FC6B3BB8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDE499C460A13BC77ULL + 0xD85ACCFE873164A3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCDF851ADA555ACC5ULL + 0x961D0A969B79ED11ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB48F23962FEBFF0BULL + 0xD85919FE5DCEF876ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9EA682CF80A2D373ULL + 0xCFB9DC15C7E639EBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF7A83BE323688175ULL + 0x9C17F29C3AB70EF8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD982C89F63AE26B5ULL + 0x838355D28A4F54FAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9C8EAF11B87C7ED9ULL + 0xAE6D6EB0DE183845ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEA8398A2376BF4EDULL + 0xCF480F625AF43E98ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDD7F6E4181F25645ULL + 0xC8617A3AAF1A4A49ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD8BB1AA772297E71ULL + 0xCFF1D9375A7FCD13ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA15216C189DDBE39ULL + 0x9605279DD75D688CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC9919AF0364A1AEDULL + 0xD45F3BC03B84E0F8ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneA, aSnowLaneC, aSnowLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneA, aExpandLaneA, aOperationLaneB, aExpandLaneB, aOperationLaneC, aExpandLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneB
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 1985U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 2331U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2633U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2802U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 465U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4913U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 10U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererC + RotL64(aIngress, 50U)) + 898812731947995389U;
            aOrbiterK = (aWandererB + RotL64(aCross, 13U)) + 8677347622525527167U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 770321564027567654U) + aNonceWordH;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 27U)) + 11020474858081526395U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 17289793580414993470U) + aPhaseHOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 57U)) + 10111912559295118444U) + aNonceWordA;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 8083622125544542011U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 7149858558922988240U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5919683821379905699U;
            aOrbiterB = RotL64((aOrbiterB * 16705119888884231567U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6860902846079238714U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15083517836867542075U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 4686657139237578325U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14852868368708376381U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9860233289028878323U;
            aOrbiterJ = RotL64((aOrbiterJ * 13418143547952204667U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 772406119079116272U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7971141501337627589U;
            aOrbiterG = RotL64((aOrbiterG * 10168120622976358617U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8478568022896691911U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4027604850785607101U;
            aOrbiterA = RotL64((aOrbiterA * 4826627523578901467U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17199331557841535430U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7515957656979776361U;
            aOrbiterK = RotL64((aOrbiterK * 5468950152869656599U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17138249294921502391U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 16236812863923234668U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 2925542836624164807U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 51U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 37U)) + aOrbiterK) + aNonceWordK) + aPhaseHWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterI) + aNonceWordJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 4U) + RotL64(aOrbiterG, 30U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneD
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8125U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneC[((aIndex + 8875U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10249U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((aIndex + 6808U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 9693U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 10496U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 5660U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 60U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 11177787645248006236U) + aPhaseHOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 35U)) + 3808340254579817169U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 46U)) + RotL64(aCarry, 51U)) + 828030667598518279U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 29U)) + 16177835921238398371U) + aNonceWordN;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 5518747735458708741U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 19U)) + 17346319082399995165U) + aNonceWordK;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 57U)) + 6397156921893030937U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15559381654710713582U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 940404446491415088U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16401260971303026881U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8047166032048732645U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4688468645859470491U;
            aOrbiterE = RotL64((aOrbiterE * 14383536431614496369U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3710878044770337260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 116343189456629220U;
            aOrbiterB = RotL64((aOrbiterB * 5637725064169289339U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 883908030159391659U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 18058691521694880482U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3132200449123497619U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17521015077103586117U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 3668332225435714918U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12658899101297839881U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12229480388278883300U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16206524049491531816U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11122340196620859805U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5743265849441077466U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2812293020719282236U;
            aOrbiterF = RotL64((aOrbiterF * 8903956475200417109U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 51U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + aNonceWordH) + aPhaseHWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterF, 5U));
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15775U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneA[((aIndex + 11110U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 15410U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11840U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 14656U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 6U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 15904465836916519864U;
            aOrbiterE = (aWandererK + RotL64(aCross, 5U)) + 17725629806317789307U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 18U)) + 13794170125914914828U) + aNonceWordC;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 35U)) + 2149055907476874332U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 5342047776745074649U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 8268148484060546838U) + aPhaseHOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 51U)) + 10821151364028563719U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4294213820894407378U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10884726101307943090U;
            aOrbiterK = RotL64((aOrbiterK * 1116128870387229159U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16432210042202444824U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15196602644336228055U;
            aOrbiterB = RotL64((aOrbiterB * 12680438355124070237U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14117787670220328165U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 219833877949480215U;
            aOrbiterH = RotL64((aOrbiterH * 10736293047771972173U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3326396981881473962U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14918513066311426279U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14269763278564574663U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11795234681370163206U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3068267285352664813U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15746255933920904619U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 245233356957999496U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 709926406353796673U;
            aOrbiterG = RotL64((aOrbiterG * 13627039596842073595U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 5378105439430271038U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10114555061122044430U;
            aOrbiterJ = RotL64((aOrbiterJ * 5351295043424885549U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 5U)) + aOrbiterB) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterK, 58U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 29U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 13U)) + aOrbiterE) + aNonceWordF) + aPhaseHWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21698U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 21779U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17756U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20023U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17344U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 11698283336767769359U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 13297826354831483872U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 19U)) + 15254999058287530795U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 23U)) + 17474166585085346567U) + aPhaseHOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 41U)) + 15684783498452840289U) + aPhaseHOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 47U)) + 5061229733465216486U) + aNonceWordM;
            aOrbiterG = (aWandererI + RotL64(aCross, 29U)) + 15370981279168377944U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17966672773619554092U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14685092893994491068U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1627758964162892429U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12798804186209406389U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2848444181474221574U;
            aOrbiterH = RotL64((aOrbiterH * 13730480364920876877U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8551142075919636146U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8833198159158950723U;
            aOrbiterG = RotL64((aOrbiterG * 7650289040764974737U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 7351473160893666232U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14204899612487622222U;
            aOrbiterA = RotL64((aOrbiterA * 6317485031956448029U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7008985178526543258U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13576796403863120356U;
            aOrbiterB = RotL64((aOrbiterB * 13745839827679114077U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5769784656937900699U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14075925808204936705U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 5844894088757604713U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17818667502858010896U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16016922065572683130U;
            aOrbiterD = RotL64((aOrbiterD * 7525645833898085373U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterH, 41U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 12U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + aPhaseHWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 4U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25373U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 24332U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 25361U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27223U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23979U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 13960289014350612206U) + aNonceWordH;
            aOrbiterE = (aWandererK + RotL64(aCross, 58U)) + 3483331015269589730U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 6873299241002444518U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 3562094007125534229U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 21U)) + 11422367439932782705U) + aNonceWordP;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 41U)) + 532453428514259816U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 5U)) + 17810941465810193088U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11869759058631106331U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8837581071876177566U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 15329827515970522213U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17185378327053837778U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7578253375676981500U;
            aOrbiterE = RotL64((aOrbiterE * 13371647568758721729U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17112646434432814442U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14949096407295697881U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14770977858283051753U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4259590620758467836U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 6534899413644542303U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 7987609419215568661U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 2637407498893694243U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15819295597921425711U;
            aOrbiterJ = RotL64((aOrbiterJ * 5202015597375051399U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 6373559542002699718U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11694562937392022505U;
            aOrbiterG = RotL64((aOrbiterG * 9311557972331218597U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3308736483775453062U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12749929710650475901U;
            aOrbiterH = RotL64((aOrbiterH * 248428400724560945U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 38U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 34U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + aPhaseHWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31957U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 29007U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32244U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27665U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 30229U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 24U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 6771552164800695068U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 12131763371571322040U) + aNonceWordI;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 39U)) + 3326182381395522013U) + aNonceWordF;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 21U)) + 12288775097697156383U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 3U)) + 5195948373449796741U) + aNonceWordM;
            aOrbiterH = (aWandererA + RotL64(aCross, 27U)) + 14404044002250137144U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 21U)) + 11142382920035825426U) + aPhaseHOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2967149520256475485U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1470907369577818097U;
            aOrbiterD = RotL64((aOrbiterD * 9398653295177725883U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9231668148004163910U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13078929163913892386U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7509829068700523627U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9485274692075657877U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12216951187543631673U;
            aOrbiterH = RotL64((aOrbiterH * 6571066246507310805U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 6933334652581744234U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17260276102423580920U;
            aOrbiterK = RotL64((aOrbiterK * 7796879893790990605U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 387767848169714392U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8597538259308082638U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 4888054690557707241U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7996708724489146033U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15357384191688149939U;
            aOrbiterF = RotL64((aOrbiterF * 9827691726832491373U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 17739222908739454637U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1614322333281471170U;
            aOrbiterA = RotL64((aOrbiterA * 7063116837752240891U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterH, 12U)) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterI, 35U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_G seed_loop_h (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [twist arx]
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // GTwistRunTwist_A twist_loop_a (start)
    {
        // GTwistRunTwist_A twist_loop_a lane group
        // read from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // twist_loop_a loop 1
        // ingress from: aKeyRowReadA, aKeyRowReadB
        // ingress directions: aKeyRowReadA forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource
        // cross directions: aKeyRowReadA backward forced, mSource backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aKeyRowReadA[((aIndex + 534U)) & W_KEY1], 6U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 974U)) & W_KEY1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1985U)) & W_KEY1], 4U) ^ RotL64(mSource[((aIndex + 2384U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 29U)) + 4179952823252098240U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 14U)) + 3745613452332101749U) + aPhaseAOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 47U)) + 2955689793395307176U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 5639060180251322019U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 7901969163853586463U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 10U)) + 2242166787816318119U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 19U)) + 5239936443960750064U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 41U)) + 13939136954732185558U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 17058884136712717463U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18148618660054585941U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7022023484530327814U;
            aOrbiterJ = RotL64((aOrbiterJ * 650100011311048589U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7722084537340095637U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11764151879690934182U;
            aOrbiterH = RotL64((aOrbiterH * 12264384877711365655U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 16412785901758144708U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9666718667728274824U;
            aOrbiterK = RotL64((aOrbiterK * 10865799822751771795U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4307127540152109364U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2457646804702647606U;
            aOrbiterE = RotL64((aOrbiterE * 6340030928007058595U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3179394870088602208U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 504977947273774249U;
            aOrbiterI = RotL64((aOrbiterI * 16190282058883481551U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16182729401018310837U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7110817020445860609U;
            aOrbiterG = RotL64((aOrbiterG * 13371352088428584087U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12960656706837391973U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7103806893724395904U;
            aOrbiterF = RotL64((aOrbiterF * 14365984439655979791U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1248300178080633527U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7195473175424961337U;
            aOrbiterA = RotL64((aOrbiterA * 4633558992739305045U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13007951568242991449U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10296811247653636372U;
            aOrbiterB = RotL64((aOrbiterB * 16469682651380549395U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterG, 60U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterK, 43U));
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 26U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 36U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 2
        // ingress from: aFireLaneA, aKeyRowReadA
        // ingress directions: aFireLaneA forward forced, aKeyRowReadA forward/backward random
        // cross from: aKeyRowReadB, mSource
        // cross directions: aKeyRowReadB backward forced, mSource backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 5317U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3952U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4861U)) & W_KEY1], 53U) ^ RotL64(mSource[((aIndex + 3557U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 50U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 3236820517816085022U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 35U)) + 741288875914097926U) + aPhaseAOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 14U)) + RotL64(aCarry, 41U)) + 8417246926007729580U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 53U)) + 9715717805774537170U) + aPhaseAOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 47U)) + 14360243844821619482U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 57U)) + 10760908100206775334U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 43U)) + 3434641779946167811U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 7885568822756234567U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 6U)) + 3041563437672051294U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15761355327564963516U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1158633562785937421U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15511324886867188235U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9338581575871970653U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9172038894262857354U;
            aOrbiterD = RotL64((aOrbiterD * 3110871165285625807U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14653924713599790081U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3854497592598563309U;
            aOrbiterA = RotL64((aOrbiterA * 11737111068815795303U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16286980180327600557U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 5092583772591249756U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13955105624639442903U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4288397994175567333U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15584236478994873104U;
            aOrbiterE = RotL64((aOrbiterE * 1860480595862755379U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5557463939827483792U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2659814275753280856U;
            aOrbiterK = RotL64((aOrbiterK * 17702430405693184643U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6941807963525063449U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2040598555191211307U;
            aOrbiterC = RotL64((aOrbiterC * 14750544987531722765U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 347572666231116258U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 779304821185302523U;
            aOrbiterJ = RotL64((aOrbiterJ * 14180254150318109855U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10632524582873079742U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9761308771280517212U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13926235411726048921U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 28U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 46U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterE, 13U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 58U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 42U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 3
        // ingress from: aFireLaneB, aKeyRowReadB
        // ingress directions: aFireLaneB forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aFireLaneA backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneB[((aIndex + 6929U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 7166U)) & W_KEY1], 58U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6327U)) & W_KEY1], 22U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6665U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6631U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 3199575576585871314U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 34U)) + 2533378188975571824U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 57U)) + 6819782112558312658U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 53U)) + 12690060987724798497U) + aPhaseAOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 39U)) + 7088375139715629606U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 6U)) + 17785618677423695666U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 1714999280296491277U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 17611338506932491624U;
            aOrbiterA = (aWandererB + RotL64(aCross, 23U)) + 6475727359297421201U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2347744591204119530U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2739317903351401068U;
            aOrbiterI = RotL64((aOrbiterI * 15435029315209475631U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8663535261373274338U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8205245127823536479U;
            aOrbiterF = RotL64((aOrbiterF * 13857005110466856439U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8916510616749754516U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3944805940148512932U;
            aOrbiterD = RotL64((aOrbiterD * 18082271583211389701U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14094751253118853302U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14094299829196076311U;
            aOrbiterE = RotL64((aOrbiterE * 6370012560657108493U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3940673811518673802U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3015106523254484839U;
            aOrbiterB = RotL64((aOrbiterB * 9655401190755573379U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15404103131982599922U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1828655763233900875U;
            aOrbiterK = RotL64((aOrbiterK * 13024358077740310049U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1236981890899916502U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 18208975564570342697U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4577109989465876801U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17882273895471449661U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16196010765612713713U;
            aOrbiterA = RotL64((aOrbiterA * 15624856645134182005U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14639250100311162559U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9139027997336903273U;
            aOrbiterJ = RotL64((aOrbiterJ * 1853126389565574293U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterE, 27U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 37U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 12U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 42U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 23U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 52U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 4
        // ingress from: aFireLaneC, aKeyRowReadB, mSource, aFireLaneA
        // ingress directions: aFireLaneC forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aFireLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 9031U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 10728U)) & W_KEY1], 40U));
            aIngress ^= (RotL64(mSource[((aIndex + 10419U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((aIndex + 9576U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10612U)) & W_KEY1], 43U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10313U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 28U)) + 4773124477323378268U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 16848723289435796005U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 47U)) + 13846642134917107058U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 6472057872482789939U;
            aOrbiterD = (aWandererK + RotL64(aCross, 21U)) + 2747019500690707226U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 41U)) + 9003965289739733880U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 5U)) + 3013390651936257377U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 12U)) + RotL64(aCarry, 41U)) + 3331004709895625067U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 57U)) + 15355010435553517129U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7709870658004280052U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13568728443963926564U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6736090830113688981U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12409548853419307131U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 969183352023661537U;
            aOrbiterD = RotL64((aOrbiterD * 5549220554838837145U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15370309834426476775U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3896803894396631184U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11018830202891911603U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10848873633291935766U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12885336509190543440U;
            aOrbiterC = RotL64((aOrbiterC * 1487357252619221365U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8252290890093788010U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9201553615601641350U;
            aOrbiterI = RotL64((aOrbiterI * 420321130559162915U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14014209645503188472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4015071464301844550U;
            aOrbiterJ = RotL64((aOrbiterJ * 17444195018239904971U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16173085647514027347U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16916627014974363360U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7699587344277490953U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1591680303404522110U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16499606051269327916U;
            aOrbiterE = RotL64((aOrbiterE * 814405848002794813U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6932673635509444619U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8745681160108707944U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14565255558668084787U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 36U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterC, 19U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + aPhaseBWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 34U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 47U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterG, 51U));
            aWandererG = aWandererG + ((RotL64(aIngress, 30U) + RotL64(aOrbiterC, 58U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 5
        // ingress from: aFireLaneD, aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB
        // ingress directions: aFireLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneB forward/backward random
        // cross from: aFireLaneA, aFireLaneC
        // cross directions: aFireLaneA backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 11028U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 11447U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11049U)) & W_KEY1], 46U) ^ RotL64(mSource[((aIndex + 11381U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12810U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11526U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11279U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererI + RotL64(aPrevious, 47U)) + 10404808878585437255U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 57U)) + 10587858736301591439U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 18U)) + 1430530909801644435U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 9090938022430118902U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 53U)) + 12936604311751121235U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 1000583006020232032U) + aPhaseBOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 12352532088997042232U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 27U)) + 16723410947058502564U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 6U)) + 16614089235313154270U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4245553025593349277U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3353146318549477494U;
            aOrbiterI = RotL64((aOrbiterI * 14246377408238318091U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5935727336135635196U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10312187090293319667U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1395964500396711899U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12192843181244744484U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2542570124502586365U;
            aOrbiterC = RotL64((aOrbiterC * 17222847847573534963U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3315472769469002444U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17512858811783071174U;
            aOrbiterG = RotL64((aOrbiterG * 9070400454074283765U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16633218007427888082U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2502077714838858460U;
            aOrbiterB = RotL64((aOrbiterB * 970762420815997725U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14792910273226469214U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15739513291150783151U;
            aOrbiterF = RotL64((aOrbiterF * 11896279674116906915U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2192903544350345992U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 844428341223009295U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4768368713974002539U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2998511458298901402U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7790789639864783373U;
            aOrbiterA = RotL64((aOrbiterA * 9173097618440495497U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4540735375055164995U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13700342877362633034U;
            aOrbiterK = RotL64((aOrbiterK * 14730797752841670505U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 53U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 27U)) + aOrbiterI) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 34U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + aPhaseBWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 18U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 6
        // ingress from: aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, mSource backward forced, aFireLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 15330U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 16252U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14133U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13931U)) & W_KEY1], 21U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14198U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15832U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 15280U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 3U)) + (RotL64(aPrevious, 34U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 51U)) + 13204735390996728477U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 46U)) + RotL64(aCarry, 57U)) + 851171359595647173U;
            aOrbiterC = (aWandererD + RotL64(aCross, 41U)) + 16745304202825290723U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 5U)) + 562392736584913979U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 37U)) + 3244267012529053918U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 17282536111067869133U;
            aOrbiterE = (aWandererF + RotL64(aCross, 27U)) + 14851130066471729068U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 5256130407952363129U;
            aOrbiterF = (aWandererA + RotL64(aCross, 18U)) + 2904742485828362001U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3723346325449225387U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5344621093694027341U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9044881458629673499U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12919263300833603026U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17989801264160996071U;
            aOrbiterJ = RotL64((aOrbiterJ * 15468293047311883751U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5022175042377172157U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16684822380107847758U;
            aOrbiterK = RotL64((aOrbiterK * 2834049270263837537U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2740326510600876682U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13981423865219318820U;
            aOrbiterD = RotL64((aOrbiterD * 14593082145080056441U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 231945878229848395U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14139797734944312580U;
            aOrbiterH = RotL64((aOrbiterH * 6492256080432266407U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16704102101387552373U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8506734780526852552U;
            aOrbiterG = RotL64((aOrbiterG * 4684566118627414659U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2774630043988894695U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12490034334296488127U;
            aOrbiterF = RotL64((aOrbiterF * 16765455396278233145U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 545238171291436006U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1023872898002379590U;
            aOrbiterB = RotL64((aOrbiterB * 8626333831510136515U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5065187021047872560U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10391809965648089863U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10912471108849550469U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 43U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterB, 30U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 53U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 22U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + aPhaseBWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 54U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 7
        // ingress from: aWorkLaneB, aKeyRowReadA, mSource, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aKeyRowReadA forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadB, aFireLaneD, aWorkLaneA
        // cross directions: aKeyRowReadB backward forced, aFireLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16923U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 17861U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(mSource[((aIndex + 18358U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneA[((aIndex + 17196U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17282U)) & W_KEY1], 5U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17666U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18889U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererA + RotL64(aCross, 47U)) + 1297415699043177788U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 17583786534509260153U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 58U)) + 643197858925708798U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 11U)) + 5062653766915694874U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 29U)) + 7034273638367180511U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 2026909726972916996U) + aPhaseCOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 3U)) + 2785690475553211646U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 35U)) + 2910341716302991892U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 24U)) + RotL64(aCarry, 27U)) + 2834181605200829791U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13323052600571281928U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10434901530315760460U;
            aOrbiterK = RotL64((aOrbiterK * 2042210188346767033U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 247903955625194782U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5196515747387257163U;
            aOrbiterD = RotL64((aOrbiterD * 1799024689023272275U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7196305682377987476U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14777739876892587484U;
            aOrbiterE = RotL64((aOrbiterE * 95220583948241581U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10609060796540136671U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8386027207212484155U;
            aOrbiterG = RotL64((aOrbiterG * 4855610536246556893U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 729659744301903424U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2350564261412606157U;
            aOrbiterC = RotL64((aOrbiterC * 16713856782349084977U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16611987556673864177U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 1525195188708550503U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10045858602151004553U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4654808490980989596U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8189569777087686263U;
            aOrbiterB = RotL64((aOrbiterB * 17278657566389299577U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10932857495004451792U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1833880112534916813U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8004341577533825681U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 13100236350175516423U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2773759534195186313U;
            aOrbiterI = RotL64((aOrbiterI * 3194954066097323161U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 6U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 58U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aScatter, 58U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 23U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 36U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 19U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 42U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 8
        // ingress from: aWorkLaneC, mSource, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, mSource forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, aWorkLaneB, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19791U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 21151U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19732U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19282U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20705U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21505U)) & W_KEY1], 3U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19533U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneB[((aIndex + 19132U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 20U)) + (RotL64(aIngress, 37U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererD + RotL64(aIngress, 23U)) + 8506388683755208267U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 12U)) + 2179323259055019735U) + aPhaseCOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 3345902531140983016U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 5U)) + 17456139311481306584U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 43U)) + 14587864088462311164U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 47U)) + 13178947246650647057U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 36U)) + RotL64(aCarry, 13U)) + 12866578138946916962U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 13098524333655118173U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 27U)) + 15451329483787541982U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9494299579678389385U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15581954810375490643U;
            aOrbiterB = RotL64((aOrbiterB * 13670002280188424825U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4487042505730624892U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2774455928791636186U;
            aOrbiterI = RotL64((aOrbiterI * 15847933919136777451U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12435319582397755819U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10077180055177766823U;
            aOrbiterF = RotL64((aOrbiterF * 3924363471701748703U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10391963896910956455U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6149237416725301794U;
            aOrbiterK = RotL64((aOrbiterK * 10115917698918612823U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15673402771629639978U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14729117178956592426U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9070464269215820531U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14492001279368870240U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6278248084483259952U;
            aOrbiterD = RotL64((aOrbiterD * 16731228350971263873U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15727518866499740411U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8652631010810965473U;
            aOrbiterE = RotL64((aOrbiterE * 9508484121620912715U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13660890300188313775U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14699253534935936300U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3978135617259934869U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1621689916308271346U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5651399428852950385U;
            aOrbiterC = RotL64((aOrbiterC * 12220143634120124133U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterA, 60U));
            aWandererH = aWandererH + (((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterD, 29U));
            aWandererD = aWandererD + ((((RotL64(aCross, 39U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterI, 18U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 9
        // ingress from: aWorkLaneD, aKeyRowReadA, aKeyRowReadB, aWorkLaneC
        // ingress directions: aWorkLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: mSource, aWorkLaneA, aFireLaneC, aFireLaneD
        // cross directions: mSource backward forced, aWorkLaneA backward forced, aFireLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22404U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[((aIndex + 23128U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22180U)) & W_KEY1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21916U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23541U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22845U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24333U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneD[((aIndex + 23836U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 6U)) + 16200278595895089008U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 1029614154810465897U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 19U)) + 7129562468705441295U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 14388903902433951274U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 39U)) + 1013568949315967455U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 52U)) + 3128823373497815651U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 14525694606889470589U;
            aOrbiterE = (aWandererA + RotL64(aCross, 47U)) + 14443983602196782887U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 43U)) + 12244220415328641190U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10477159225338766614U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2842870123078131566U;
            aOrbiterA = RotL64((aOrbiterA * 11522265477555954071U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8621138818955849917U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5038396344400303181U;
            aOrbiterG = RotL64((aOrbiterG * 14636756322207385447U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2768613802894372496U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2027754864051410015U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2461322540050569287U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2848088309172056399U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15017458513904884651U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9926904679902843055U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9079797279596336139U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15424866642305110811U;
            aOrbiterI = RotL64((aOrbiterI * 12912331089970158845U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13751764050290602740U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7694557131324740282U;
            aOrbiterE = RotL64((aOrbiterE * 14980807690491467023U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3508673897305667669U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3600868397311393233U;
            aOrbiterB = RotL64((aOrbiterB * 5165032044164139165U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1222655844979128996U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2257342337168905875U;
            aOrbiterH = RotL64((aOrbiterH * 6198995971182272119U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6290990717563682725U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 15308494772443447109U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1925593111157842325U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterA, 43U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterB, 21U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 47U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + aPhaseCWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 4U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aScatter, 28U) + RotL64(aOrbiterA, 11U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterB, 52U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 10
        // ingress from: aExpandLaneA, aKeyRowReadA, aWorkLaneD, aWorkLaneB
        // ingress directions: aExpandLaneA forward forced, aKeyRowReadA forward forced, aWorkLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aKeyRowReadB, mSource, aWorkLaneC, aFireLaneD
        // cross directions: aKeyRowReadB backward forced, mSource backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26906U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 24693U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 27000U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26532U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26486U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25531U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26834U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneD[((aIndex + 25701U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aCross, 28U)) + 6973892330986118220U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 9886813896272094864U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 19U)) + 10996306582517553173U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 8490648283899856223U;
            aOrbiterK = (aWandererE + RotL64(aCross, 35U)) + 105141713530704655U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 5U)) + 3114337422810562588U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 41U)) + 980857684690886131U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aScatter, 14U)) + 6562042345807072665U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 15665371138706353619U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18113013571374375028U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17405346422601997299U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11162604605443005253U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5130876096426182506U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1813821672299154629U;
            aOrbiterK = RotL64((aOrbiterK * 15478100342425611875U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15793814882743306728U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13925299440495476399U;
            aOrbiterJ = RotL64((aOrbiterJ * 12049601510660117401U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9924458846049579438U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7810034662781768090U;
            aOrbiterC = RotL64((aOrbiterC * 10310594595026622513U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12812586478656872854U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5709576448057435237U;
            aOrbiterE = RotL64((aOrbiterE * 9101555233909853025U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7839807649914541516U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4717944526755429647U;
            aOrbiterH = RotL64((aOrbiterH * 8515229146471335721U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3933911971504256022U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4814079680865379831U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15100740696230557391U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18352577312212175569U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9670612998448920742U;
            aOrbiterD = RotL64((aOrbiterD * 5743579439303300553U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 72737302703035726U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10032869372369626210U;
            aOrbiterA = RotL64((aOrbiterA * 7449905669249993731U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 22U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterD, 23U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 60U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 53U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterC, 37U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterF, 47U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + aPhaseDWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 50U) + aOrbiterA) + RotL64(aOrbiterC, 30U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 11
        // ingress from: aExpandLaneB, aWorkLaneD, aKeyRowReadB, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: aKeyRowReadA, mSource, aExpandLaneA, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aExpandLaneA backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29121U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 30021U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29397U)) & W_KEY1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28408U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29191U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29942U)) & S_BLOCK1], 6U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27421U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 27858U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 27U)) + (RotL64(aIngress, 6U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererA + RotL64(aPrevious, 48U)) + 11998579547770778580U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 8409465187298704610U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 19U)) + 3470222286110333500U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 29U)) + 5704486785203069994U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 10334944660253279633U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 39U)) + 7626852700722567477U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 5U)) + 14631310754943209743U;
            aOrbiterF = (aWandererE + RotL64(aCross, 34U)) + 807160297237854120U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 5624154783624196107U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4971444394698940423U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6340057638461027062U;
            aOrbiterC = RotL64((aOrbiterC * 12027586111086798629U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9003019862787819481U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13632057463595873033U;
            aOrbiterE = RotL64((aOrbiterE * 12575202147280216765U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 12766104026871797746U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4062118445824915939U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13130770039048080701U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5258212525426469978U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9956946981015983939U;
            aOrbiterI = RotL64((aOrbiterI * 8106382657040497669U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10837606223056473999U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13292864885504191134U;
            aOrbiterA = RotL64((aOrbiterA * 4445739587553669471U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 166087925900318658U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6786842221885441388U;
            aOrbiterD = RotL64((aOrbiterD * 4411147600413147773U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16888086378070246404U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5240855484445974002U;
            aOrbiterG = RotL64((aOrbiterG * 402652898573422271U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6874866669211571608U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 732890824978127460U;
            aOrbiterF = RotL64((aOrbiterF * 3776365957702257453U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5541380495707308058U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 17947326584411475765U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10920952349981652899U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterC, 30U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 11U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 23U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 34U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterE, 39U)) + aPhaseDWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 19U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 47U));
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 12
        // ingress from: aExpandLaneC, aKeyRowReadA
        // ingress directions: aExpandLaneC forward forced, aKeyRowReadA forward/backward random
        // cross from: aWorkLaneD, aExpandLaneA, aExpandLaneB, aKeyRowReadB
        // cross directions: aWorkLaneD backward forced, aExpandLaneA backward forced, aExpandLaneB backward forced, aKeyRowReadB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 31979U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30252U)) & W_KEY1], 36U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32621U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30246U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30366U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31644U)) & W_KEY1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererD + RotL64(aScatter, 23U)) + 16651241552253078315U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 40U)) + 4558144676982478003U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 3U)) + 8814884320080367550U) + aPhaseDOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 35U)) + 16011579668555672117U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 51U)) + 4738918668759862438U) + aPhaseDOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 18U)) + 12526083125540985108U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 8048723561746000552U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 1082218464034639039U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 8432043246965946816U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9982080524048636852U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6720069955755215919U;
            aOrbiterH = RotL64((aOrbiterH * 1025046364205332059U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1019035028070247757U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7360619079463870467U;
            aOrbiterA = RotL64((aOrbiterA * 6623074813047915863U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10893918488381348474U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1390297670907738019U;
            aOrbiterB = RotL64((aOrbiterB * 11909657437658597735U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12512200589031203480U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14741471280748399540U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3012135242889901095U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8543897248359826770U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8545972622733791272U;
            aOrbiterC = RotL64((aOrbiterC * 11793879362775346821U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7049384618581928664U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14730773807906925408U;
            aOrbiterE = RotL64((aOrbiterE * 10711566871536755073U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11480717275652449986U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1135397594974536859U;
            aOrbiterD = RotL64((aOrbiterD * 6347492892938856497U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6897207625849516702U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10920630712550287148U;
            aOrbiterG = RotL64((aOrbiterG * 4140705091806993359U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1094056478999931332U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6784487144549717207U;
            aOrbiterF = RotL64((aOrbiterF * 6295177724167067891U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 18U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 30U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterC, 47U)) + aPhaseDWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterG, 57U));
            aWandererD = aWandererD + (((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 19U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterB, 24U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_A twist_loop_a (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [twist arx]
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // GTwistRunTwist_B twist_loop_b (start)
    {
        // GTwistRunTwist_B twist_loop_b lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aFireLaneC, aFireLaneD, aOperationLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3232U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 5878U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1809U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 929U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8136U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1024U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 26U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererE + RotL64(aPrevious, 5U)) + 9751314027302668907U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 12175450995523107056U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aScatter, 30U)) + RotL64(aCarry, 11U)) + 17519694958730119552U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 9093525527925682263U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 21U)) + 3713831321786810138U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 51U)) + 10108355209191835040U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 41U)) + 12956307447311314768U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1904298513945877359U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4658049993308574460U;
            aOrbiterD = RotL64((aOrbiterD * 10482422152074338611U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9826333658248851902U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12058666914724365134U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 964233873188373939U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2516574707110528099U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13335308331049750235U;
            aOrbiterF = RotL64((aOrbiterF * 5880227828760598587U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8230749255538495304U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16536559486797811486U;
            aOrbiterE = RotL64((aOrbiterE * 7097036838156464969U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12387639130570188998U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8459259798142872020U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8001346480955847013U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16083784052002800300U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1957284290736468379U;
            aOrbiterB = RotL64((aOrbiterB * 5046501301740813065U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7349538179311335863U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16395170077006105258U;
            aOrbiterH = RotL64((aOrbiterH * 4230485452156662763U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 26U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterB, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 3U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 44U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererD = aWandererD + (((RotL64(aCross, 50U) + aOrbiterD) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10629U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 10321U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8611U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9260U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12858U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12027U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9665U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 8975885703279267062U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 8664844915562660637U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 19U)) + 12281774799736296726U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 3U)) + 15347461352311329726U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 11U)) + 12967500561828907834U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 57U)) + 5002833859280402726U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 36U)) + RotL64(aCarry, 51U)) + 11908257536954668983U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17017174811949227162U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16851323125613931180U;
            aOrbiterG = RotL64((aOrbiterG * 12446990992858763577U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13469326957728686706U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5228638551056105241U;
            aOrbiterD = RotL64((aOrbiterD * 13369947664646167255U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11945166198089308564U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16268645041872996022U;
            aOrbiterE = RotL64((aOrbiterE * 5391448793718370911U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14781204627695095701U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5365325354838101092U;
            aOrbiterC = RotL64((aOrbiterC * 8017284997946310807U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 563147416025715953U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14660867395395625851U;
            aOrbiterA = RotL64((aOrbiterA * 4769458126865307103U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3168989056355712105U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16179131669773665579U;
            aOrbiterH = RotL64((aOrbiterH * 5641461617066671723U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4160220074225527179U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8597134686962559111U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 639572585431474015U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterA, 37U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 11U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterH, 27U));
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterK, 44U)) + aPhaseEWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20432U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 17933U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 19572U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17560U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18036U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24207U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 16599U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 2168513956284366370U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 5U)) + 10290361969974613111U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 15673836275828498050U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 18U)) + RotL64(aCarry, 29U)) + 16600540024145812236U) + aPhaseEOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 47U)) + 9428052101528111892U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 35U)) + 12763657928312763377U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 41U)) + 10751286982008662485U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1708230173038057979U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4011389705422783816U;
            aOrbiterG = RotL64((aOrbiterG * 11692237130784795961U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11704428328093077714U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2055336619674699284U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6374289210096410907U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1870865272102705804U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3574214263751923179U;
            aOrbiterH = RotL64((aOrbiterH * 13132083406834413563U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 984611970726966186U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15207945449947643672U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9539470161576639981U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4181398506373973169U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15222345431506025949U;
            aOrbiterC = RotL64((aOrbiterC * 6925143692628659467U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15023513452326240962U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14965669361708810699U;
            aOrbiterE = RotL64((aOrbiterE * 587008860996713147U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7985755518735406360U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 225592097619240187U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2313509354133400439U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterD, 53U));
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterD, 41U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterG, 47U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 23U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterH, 14U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aExpandLaneD, aWorkLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aExpandLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26777U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 32618U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25591U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 27154U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25826U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25908U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 30261U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 5U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aScatter, 5U)) + 14179205183062705133U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 51U)) + 210032324058740920U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 60U)) + 7387115089142500152U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 17583362781238061430U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 4991442849150005943U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 2891376254689854555U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 11U)) + 10523274382407446239U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3861893764676218667U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3366674459852093746U;
            aOrbiterF = RotL64((aOrbiterF * 14005994095369483813U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5898492634386601145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7047353571244768721U;
            aOrbiterA = RotL64((aOrbiterA * 2257518291062508467U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14374108805453186316U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8763667021501226510U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7694695426430267863U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 18261523829316379575U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 650477532238860965U;
            aOrbiterE = RotL64((aOrbiterE * 8291758490821819851U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2162326554604894042U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5776546692501825278U;
            aOrbiterD = RotL64((aOrbiterD * 14911545784585246537U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3501863793638415049U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14853789267425352958U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10590325397179928739U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15399673014671329743U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12253428583438990426U;
            aOrbiterB = RotL64((aOrbiterB * 12052855472196447849U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterA, 38U)) + aPhaseEWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 12U) + aOrbiterF) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_B twist_loop_b (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [twist arx]
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // GTwistRunTwist_C twist_loop_c (start)
    {
        // GTwistRunTwist_C twist_loop_c lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2605U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 659U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2849U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2166U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2822U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 8049U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 3U)) + 2974056819475622600U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 44U)) + RotL64(aCarry, 37U)) + 7345051759236356098U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 47U)) + 12738468816846628882U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 7694520596043297922U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 23U)) + 5530753590015084774U;
            aOrbiterH = (aWandererE + RotL64(aCross, 27U)) + 3776309161718383105U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 41U)) + 784780304358106404U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 19U)) + 8999942326995036509U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 5194986506064092779U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 34U)) + 7920040007459652762U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 51U)) + 11311997270710107937U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5365231114813547251U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8630110234623825263U;
            aOrbiterA = RotL64((aOrbiterA * 2735881715888325759U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2358235238039571072U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 18059414891616491807U;
            aOrbiterF = RotL64((aOrbiterF * 17150786106857185467U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14526050556461782864U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6937282036603272474U;
            aOrbiterE = RotL64((aOrbiterE * 14954512365270028029U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10105832250694931310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3884223553012098137U;
            aOrbiterK = RotL64((aOrbiterK * 16340956813003906195U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10385284339549648087U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1257633893341505930U;
            aOrbiterD = RotL64((aOrbiterD * 2669950791270500977U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5528890519572824318U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15664241747527713256U;
            aOrbiterI = RotL64((aOrbiterI * 16670884497088220497U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14264122979415331887U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17985061405540198036U;
            aOrbiterC = RotL64((aOrbiterC * 2729487440173395133U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1663986734997903415U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3706166884286400587U;
            aOrbiterG = RotL64((aOrbiterG * 10549736618301955745U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12736963182099961466U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 95411267612114381U;
            aOrbiterH = RotL64((aOrbiterH * 8011937916302325057U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4966620136499917388U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8478316876240452401U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13297718919105366563U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11123814701411614557U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2974056819475622600U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5913569942407618997U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 24U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterC, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 11U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterB, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 36U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterH, 19U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + aPhaseFWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterF, 44U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterB, 21U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10050U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 15590U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 16149U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneC[((aIndex + 12849U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8875U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14603U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13732U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 38U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 11U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererC + RotL64(aCross, 54U)) + 18191288703716505885U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 43U)) + 9824014524910417136U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 19U)) + 11953012029254917548U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 6297568011027199089U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 2576999400457367975U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 3U)) + 13176139160575558254U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 9978408174563621810U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 41U)) + 16765834875061607142U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 21U)) + 16534507305459121344U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 37U)) + 3114710944346151807U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 12U)) + 10240517868726718592U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10721450637990777883U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16689590768796583952U;
            aOrbiterA = RotL64((aOrbiterA * 3046344179729901637U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2427422768928450209U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13495584061816457831U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6670984773768885119U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7058636403765106682U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9897341853944713767U;
            aOrbiterE = RotL64((aOrbiterE * 14286816859999869231U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17749559755733386064U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12515645083926326659U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6582878478865838245U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2625692458813609962U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10596240255026143019U;
            aOrbiterK = RotL64((aOrbiterK * 11605800195771080135U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12374290338067865540U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1507386663796330249U;
            aOrbiterH = RotL64((aOrbiterH * 1210241080424446087U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9288099549484146726U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15159312464747000702U;
            aOrbiterI = RotL64((aOrbiterI * 500055502081347757U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14998608679505446229U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17625038109437732009U;
            aOrbiterB = RotL64((aOrbiterB * 14785862243019841689U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10543192232885637211U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10330547522729618042U;
            aOrbiterD = RotL64((aOrbiterD * 7635903835474874057U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5753298214283941201U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15943436872588208065U;
            aOrbiterC = RotL64((aOrbiterC * 17704547766822075741U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5757218926946874970U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 18191288703716505885U;
            aOrbiterF = RotL64((aOrbiterF * 2644970408001409575U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 10U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 60U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 27U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 11U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterI, 58U));
            aWandererD = aWandererD + ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneC, aExpandLaneB
        // cross directions: aWorkLaneA backward forced, aOperationLaneC backward forced, aExpandLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22712U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 22536U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 22642U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 21136U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17023U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18597U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23379U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aCross, 19U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 18255347001097480328U;
            aOrbiterB = (aWandererH + RotL64(aCross, 43U)) + 13679246790311505735U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 28U)) + RotL64(aCarry, 5U)) + 10565839529765027116U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 14327172566224769901U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 5U)) + 16239024612038195174U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aPrevious, 47U)) + 13800012174212131890U;
            aOrbiterH = (aWandererE + RotL64(aCross, 21U)) + 13900288860157577583U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 11U)) + 4144386119777112740U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 37U)) + 3154558262670631372U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 39U)) + 7456728543137614001U;
            aOrbiterE = (aWandererG + RotL64(aCross, 50U)) + 11709519851158935384U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15607438907832240304U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9276575329661725624U;
            aOrbiterD = RotL64((aOrbiterD * 8879744070762412745U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6459435969129449226U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6442382118416542275U;
            aOrbiterC = RotL64((aOrbiterC * 2921027306686588233U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12117432107282150865U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6831279293184793243U;
            aOrbiterK = RotL64((aOrbiterK * 2435360641135249073U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9520022957804572889U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8322178689474588679U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1627707191467537115U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 4162401591586869316U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8994015844714895961U;
            aOrbiterB = RotL64((aOrbiterB * 15421910378057951895U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10038095909727959633U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17756404450592957616U;
            aOrbiterJ = RotL64((aOrbiterJ * 14255952184627347295U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3379089265413427719U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11341713098678108441U;
            aOrbiterH = RotL64((aOrbiterH * 2500587373161411961U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4030296130743454165U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 6332387792111212064U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16490982218150897861U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14893209417387662133U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9265457389326311687U;
            aOrbiterI = RotL64((aOrbiterI * 9778404505547862689U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13496086915199406901U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14576555328710787951U;
            aOrbiterF = RotL64((aOrbiterF * 13155395071667672943U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11482324648071976743U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 18255347001097480328U;
            aOrbiterG = RotL64((aOrbiterG * 10918514878283385643U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 52U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 57U));
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterE, 48U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 27U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 50U) + aOrbiterK) + RotL64(aOrbiterC, 41U)) + aPhaseFWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 46U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30121U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((aIndex + 28999U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 26199U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29141U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25663U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31364U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26438U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 3U)) + 4476099022490972343U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 16836423700375760429U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 8850577488928703557U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 54U)) + 7091631824560042743U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 37U)) + 12560498899956759494U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 23U)) + 7797973377112012161U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 39U)) + 6173820673874805794U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aScatter, 13U)) + 10805025132310245348U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 29U)) + 7139216143268029968U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 60U)) + 8241544862261635722U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 4735527016563596150U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5166171126690294033U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11117641762075368393U;
            aOrbiterK = RotL64((aOrbiterK * 4980156869201219393U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6312932356458415421U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1304139291184508668U;
            aOrbiterF = RotL64((aOrbiterF * 90744653170922319U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10085025354842771067U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16745854428789531080U;
            aOrbiterI = RotL64((aOrbiterI * 1945983905747274355U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2497187958708890337U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16069701876646548995U;
            aOrbiterD = RotL64((aOrbiterD * 16606039730973709495U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17242004368025978091U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 12334315722243232121U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16528598396696346719U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8007042082518126895U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5665686359038811484U;
            aOrbiterA = RotL64((aOrbiterA * 11289316305875751813U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3913477186958600592U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16918984318564170343U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5128293326494417281U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10227611546502931418U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7187623463085447228U;
            aOrbiterH = RotL64((aOrbiterH * 8479839369622163181U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16655159122037336519U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9844145011519243346U;
            aOrbiterB = RotL64((aOrbiterB * 16512883184116277583U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8660130685326542506U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16192687259641294851U;
            aOrbiterE = RotL64((aOrbiterE * 2882649237163668499U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15208432734447317310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4476099022490972343U;
            aOrbiterG = RotL64((aOrbiterG * 7447168142776253041U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 54U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 11U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 14U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 26U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 41U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 37U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 34U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 44U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 52U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_C twist_loop_c (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [grow arx]
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // GROW_A grow_key_a (start)
    {
        // grow_key_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4892U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 7941U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 6725U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 177U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7549U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2553U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 13960289014350612206U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 36U)) + RotL64(aCarry, 35U)) + 3483331015269589730U) + aPhaseGOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 11U)) + 6873299241002444518U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 3562094007125534229U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 21U)) + 11422367439932782705U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 532453428514259816U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17810941465810193088U;
            aOrbiterD = RotL64((aOrbiterD * 2830829128884590275U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11869759058631106331U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8837581071876177566U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15329827515970522213U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17185378327053837778U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7578253375676981500U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13371647568758721729U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17112646434432814442U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14949096407295697881U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14770977858283051753U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4259590620758467836U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6534899413644542303U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7987609419215568661U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterI, 30U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 53U)) + aOrbiterD) + aPhaseGWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 5U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterD, 41U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // grow_key_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16229U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 10459U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10404U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15129U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10086U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9315U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererE + RotL64(aScatter, 40U)) + RotL64(aCarry, 51U)) + 12775735908960052604U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 51U)) + 11791373812080296887U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 5537362877706057303U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 2023912048504189380U) + aPhaseGOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 21U)) + 17668828109963766893U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 558908629933941224U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1479633119685446888U;
            aOrbiterC = RotL64((aOrbiterC * 4447153373540811385U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15460320397843364063U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10059749397555469054U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8671817118586065469U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9987633811929693924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10087337844580228269U;
            aOrbiterI = RotL64((aOrbiterI * 13817142288940843815U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 4446204415503364254U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15106063243302192717U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9430197906134676162U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1226048679997253363U;
            aOrbiterA = RotL64((aOrbiterA * 14247538885252664127U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 41U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aScatter, 28U) + RotL64(aOrbiterD, 5U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 30U)) + aOrbiterA) + aPhaseGWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_a loop 3
        // ingress from: aExpandLaneB, aExpandLaneA, aWorkLaneD
        // ingress directions: aExpandLaneB forward forced, aExpandLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneD, aWorkLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17444U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((aIndex + 23639U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 23446U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23889U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21072U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21536U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 24U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aIngress, 40U)) + RotL64(aCarry, 43U)) + 9751314027302668907U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 12175450995523107056U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 11U)) + 17519694958730119552U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 9093525527925682263U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 3U)) + 3713831321786810138U) + aPhaseGOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10108355209191835040U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12956307447311314768U;
            aOrbiterB = RotL64((aOrbiterB * 9198936928658626667U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1904298513945877359U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4658049993308574460U;
            aOrbiterD = RotL64((aOrbiterD * 10482422152074338611U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9826333658248851902U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12058666914724365134U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 964233873188373939U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2516574707110528099U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13335308331049750235U;
            aOrbiterI = RotL64((aOrbiterI * 5880227828760598587U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8230749255538495304U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 16536559486797811486U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7097036838156464969U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 13U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterG, 60U));
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + aPhaseGWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // grow_key_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneB, aExpandLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24849U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 29182U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30030U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31747U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32676U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 31451U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 60U)) + (RotL64(aCarry, 47U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 29U)) + 2225397913940961213U) + aPhaseGOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aPrevious, 57U)) + 8342544893601343643U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 162922186381417187U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 11660218373710972210U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 20U)) + RotL64(aCarry, 41U)) + 14909034764605802354U) + aPhaseGOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16776955237009701511U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5834487809188925253U;
            aOrbiterJ = RotL64((aOrbiterJ * 4458820879204327709U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1498492772767040320U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4161765458781579617U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15535994410289065281U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10511923076962447765U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8575954471692620021U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12526744988828982731U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6536325446331340573U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1790628986900286346U;
            aOrbiterC = RotL64((aOrbiterC * 5262997114200816715U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2623814807619278590U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11676970995834706612U;
            aOrbiterA = RotL64((aOrbiterA * 10057461115132434901U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 48U) + RotL64(aOrbiterH, 39U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterI, 58U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 27U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GROW_A grow_key_a (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}

void TwistExpander_Karate_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t *pPrevious,
                     std::uint64_t *pIngress,
                     std::uint64_t *pCarry,
                     std::uint64_t *pWandererA,
                     std::uint64_t *pWandererB,
                     std::uint64_t *pWandererC,
                     std::uint64_t *pWandererD,
                     std::uint64_t *pWandererE,
                     std::uint64_t *pWandererF,
                     std::uint64_t *pWandererG,
                     std::uint64_t *pWandererH,
                     std::uint64_t *pWandererI,
                     std::uint64_t *pWandererJ,
                     std::uint64_t *pWandererK) {
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [grow arx]
    std::uint64_t aPrevious = *pPrevious;
    std::uint64_t aIngress = *pIngress;
    std::uint64_t aCarry = *pCarry;
    std::uint64_t aWandererA = *pWandererA;
    std::uint64_t aWandererB = *pWandererB;
    std::uint64_t aWandererC = *pWandererC;
    std::uint64_t aWandererD = *pWandererD;
    std::uint64_t aWandererE = *pWandererE;
    std::uint64_t aWandererF = *pWandererF;
    std::uint64_t aWandererG = *pWandererG;
    std::uint64_t aWandererH = *pWandererH;
    std::uint64_t aWandererI = *pWandererI;
    std::uint64_t aWandererJ = *pWandererJ;
    std::uint64_t aWandererK = *pWandererK;
    // GROW_B grow_key_b (start)
    {
        // grow_key_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneB backward forced, aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2197U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((aIndex + 3996U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1852U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4721U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7864U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 7353U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 37U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 28U)) + 7825479804710770560U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 5298124167101358123U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 17774541024369233726U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 7679371833537454082U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 3U)) + 5385914900748772224U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3879781930908486531U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 659110346638873236U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17439162088869824407U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10749021728538539749U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3631252455767429457U;
            aOrbiterF = RotL64((aOrbiterF * 8552825360915119613U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2271978810960685021U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5963558780692551176U;
            aOrbiterB = RotL64((aOrbiterB * 4772055335210781149U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 974909966119198104U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9296998242911152296U;
            aOrbiterJ = RotL64((aOrbiterJ * 2613629915877957661U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2245318466901521959U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 13391076374843288568U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18094558036982107419U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 4U) + aOrbiterF) + RotL64(aOrbiterH, 60U)) + aPhaseHWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // grow_key_b loop 2
        // ingress from: aWorkLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9946U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 12177U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13165U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14411U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13798U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8936U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 52U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 53U)) + 13924571355038625040U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 29U)) + 16328300979357156658U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 3947771961206012461U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 15428284250569311285U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 41U)) + 5777369485254032486U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16813320300717644673U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16689933050200758251U;
            aOrbiterB = RotL64((aOrbiterB * 4832495563863469353U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 1856422419049390708U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18214498743831925517U;
            aOrbiterH = RotL64((aOrbiterH * 10744120577560529379U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18278550878494094923U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 797712062039591797U;
            aOrbiterF = RotL64((aOrbiterF * 7212998747080137625U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15854849439012341347U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 996882939768167773U;
            aOrbiterD = RotL64((aOrbiterD * 14936703950807908575U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3005829974130671692U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8793495343509953906U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14065479348374612031U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterG, 50U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + aPhaseHWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_b loop 3
        // ingress from: aWorkLaneB, aWorkLaneA, aExpandLaneD
        // ingress directions: aWorkLaneB forward forced, aWorkLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneA, aExpandLaneD, aExpandLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21970U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 22373U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 21240U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22411U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17072U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 16572U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 2786079456995203065U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 34U)) + 7237256119153857253U) + aPhaseHOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 9310834010563647604U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 17361734905706517877U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 11U)) + 15837111231884647451U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18065431964418026445U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3029123922999952652U;
            aOrbiterD = RotL64((aOrbiterD * 16309219658285890145U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5166926595573507837U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1918425684273807598U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16616641579714896719U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4724551751012661440U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1818014487579644390U;
            aOrbiterE = RotL64((aOrbiterE * 14904092108647864911U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6670090372241084216U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8485757110007268693U;
            aOrbiterB = RotL64((aOrbiterB * 11876760095108618363U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4928130251509514742U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2528788422725346792U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1855982047967756661U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + aPhaseHWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 12U) + RotL64(aOrbiterB, 13U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 41U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterD, 52U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // grow_key_b loop 4
        // ingress from: aWorkLaneC, aWorkLaneB, aWorkLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31432U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 26574U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 27822U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27159U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25703U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26974U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 40U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 2915859148137000694U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 48U)) + 210680583721444425U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 6668118118775650387U) + aPhaseHOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 11U)) + 15794200818099010989U) + aPhaseHOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 6565076707062828369U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16323164497808856719U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7965435318816716560U;
            aOrbiterG = RotL64((aOrbiterG * 5984608704943623687U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7390281030573369017U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2269738866911824875U;
            aOrbiterB = RotL64((aOrbiterB * 1198697877998135567U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9664014216039993873U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18284857398028357633U;
            aOrbiterH = RotL64((aOrbiterH * 8402008251343393737U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 367667619795303009U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7935945060956274197U;
            aOrbiterA = RotL64((aOrbiterA * 5481786693511955209U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16683666162337789540U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 10655658270998102390U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15231596813382239841U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterB, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterA, 19U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterH, 52U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 6U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GROW_B grow_key_b (end)
    *pPrevious = aPrevious;
    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;
}
