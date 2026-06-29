#include "TwistExpander_Archery_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Archery_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE0B68333AB8C82CBULL + 0xD1EF1C55E2E40B3AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9066490CE4E30F13ULL + 0xA7C9F3C86FDF63DBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFA6D477573979DD9ULL + 0xB9BF0C518787557DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB9C4E837F04EF55DULL + 0x8EFAE59F572CFF9CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCA6FDE4008C0551BULL + 0x8E0B6AE92EFFD304ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBAAE9AA818E9182DULL + 0xF776B4C24DB422BFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE0FEAA670CDE664FULL + 0x82AAC4E35EE5A0B5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCE2A57CFBF8AA41FULL + 0x9FD822568B87E6C1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8C28D55E1A1BFB83ULL + 0x8279C6D2384AAB5EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBBD604793316DDEBULL + 0xAEE3DC26D7B4CA7DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x86C5EBF8FA4CE7C3ULL + 0xAC2D1D79EB536C6EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x95ADD1691CB0DF17ULL + 0xC3BAFB3B1E62AF2DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC0072874EC90140BULL + 0xD37F98AFF1A5D866ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF3B13CFE791B6883ULL + 0xF8322064EEE27E03ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD1AA5027A7F6D013ULL + 0xAA8FB750B8A854ABULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF6715463B88E5C17ULL + 0xB45205633771B16BULL);
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
        // read from: mSource, pSnow, aWorkLaneA, aWorkLaneB, aFireLaneA, aFireLaneB, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD
    
        // kdf_a_loop_a loop 1
        // ingress from: mSource, pSnow
        // ingress directions: mSource forward forced, pSnow forward/backward random
        // cross from: pSnow, mSource
        // cross directions: pSnow backward forced, mSource backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(mSource[((aIndex + 5022U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((aIndex + 994U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2796U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2583U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 19U)) + (RotL64(aCross, 60U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (aWandererA + RotL64(aIngress, 53U)) + 3561491146322798260U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 3U)) + 7075025056181885339U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 44U)) + RotL64(aCarry, 53U)) + 9230910887904171613U) + aNonceWordL;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 4119781172609908917U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 5U)) + 17155609083870983149U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 37U)) + 2423018561430181695U;
            aOrbiterE = (aWandererF + RotL64(aCross, 35U)) + 12957280305617615744U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 23U)) + 2461704174772065813U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 60U)) + 7907123257849391997U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 41U)) + 7257868138318960007U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 16425903703085702285U) + aNonceWordB;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 2990822664594079467U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5654819006718953817U;
            aOrbiterC = RotL64((aOrbiterC * 4465096036756887801U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12183676471235678779U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15026286960542123922U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17199049329995315279U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12169080607071830522U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2906296852254787499U;
            aOrbiterJ = RotL64((aOrbiterJ * 6754514406846040163U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3029858695410344584U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14406410317495954566U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 9663780721657983421U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11048818178401163861U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13622063920319445043U;
            aOrbiterF = RotL64((aOrbiterF * 2516025554421589857U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2642646089141233277U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12761571777929273548U;
            aOrbiterD = RotL64((aOrbiterD * 5518252696078700127U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7753802695131502382U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8510425459525030222U;
            aOrbiterH = RotL64((aOrbiterH * 12412361423636026483U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13522645164493316722U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1437430302489702713U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14019316635365783545U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14745189473423751499U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16968328257002103715U;
            aOrbiterI = RotL64((aOrbiterI * 17915588590593471981U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5001838243344386314U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13506188720092630563U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 7010027510838271877U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 16902624500530747723U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3561491146322798260U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 95761172090277669U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 6U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterH, 44U)) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 3U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 11U));
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 54U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 52U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 44U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // ingress from: aWorkLaneA, mSource
        // ingress directions: aWorkLaneA forward forced, mSource forward/backward random
        // cross from: aWorkLaneA, pSnow
        // cross directions: aWorkLaneA backward forced, pSnow backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 7594U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((aIndex + 7522U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7402U)) & S_BLOCK1], 11U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 8312U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (aWandererA + RotL64(aScatter, 21U)) + 12692813903177772178U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 6U)) + 7112496446691277899U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 2112247138290568813U) + aNonceWordM;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 19U)) + 3699421080882855947U) + aNonceWordD;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 53U)) + 13761832028354380922U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 4U)) + 9243822514887600214U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 6863833516853046129U) + aNonceWordI;
            aOrbiterI = (aWandererD + RotL64(aScatter, 51U)) + 8863897995943098018U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 43U)) + 13346785686701467520U) + aNonceWordP;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 47U)) + 15309543066305531619U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 19U)) + 17515530938817919111U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 760493237816424254U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7282586354117620860U;
            aOrbiterD = RotL64((aOrbiterD * 2327153408185290635U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4129706068526969105U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7020175432730888755U;
            aOrbiterA = RotL64((aOrbiterA * 10095158356907592239U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9102258982216515596U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10822031305361453690U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 2036205056490578491U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12571477440964330246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8436347026653095199U;
            aOrbiterH = RotL64((aOrbiterH * 17930734781213681573U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14214789872073941940U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12915911919403385001U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13161681603528031511U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15443240166233851298U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7311369180113240915U;
            aOrbiterB = RotL64((aOrbiterB * 13339195007946889423U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12976516224995960015U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7823308381434556721U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 502385172763861451U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 4829417661664149137U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16306394751966719700U;
            aOrbiterF = RotL64((aOrbiterF * 5294376579588592157U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16769868341852572677U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7107433163189177642U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 5279050651595743649U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11896784111967113871U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 389626690429371003U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10665914532159182181U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8226849597052979358U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12692813903177772178U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 17909062471564422847U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 10U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 6U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterK, 58U));
            aWandererG = aWandererG + ((RotL64(aIngress, 54U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 3U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 41U)) + aOrbiterI) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 51U)) + aOrbiterE) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 20U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // ingress from: aWorkLaneB, mSource
        // ingress directions: aWorkLaneB forward forced, mSource forward/backward random
        // cross from: pSnow, aWorkLaneA
        // cross directions: pSnow backward forced, aWorkLaneA backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneB[((aIndex + 13836U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 13689U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14496U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14483U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 24U)) + 17668251151213543491U) + aNonceWordG;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 16101602509895104517U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 53U)) + 9083915270773304935U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 19U)) + 12810720730318214811U;
            aOrbiterH = ((((aWandererE + RotL64(aPrevious, 46U)) + RotL64(aCarry, 13U)) + 18113428002071925621U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 1582208899354109878U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 3U)) + 4180688104819188154U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 13U)) + 8954598189262820611U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 5U)) + 15360094153175355879U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 43U)) + 8383954114668216260U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 39U)) + 15626783326234049197U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10609978564404958066U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17656516608997517984U;
            aOrbiterI = RotL64((aOrbiterI * 4590620354119899777U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 760077259110786536U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3597338735888033063U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 6548831472863517621U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4431777844935985157U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10710423172154671296U;
            aOrbiterD = RotL64((aOrbiterD * 16267496318491473315U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10240882795242085185U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7826053487019825891U;
            aOrbiterJ = RotL64((aOrbiterJ * 15053729937684375907U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9418883403715727353U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11507423614799075545U;
            aOrbiterK = RotL64((aOrbiterK * 16189463984557044693U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11545217316421066655U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 617921402135485341U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 8182920764965471653U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14456933220749921009U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7990243583564535387U;
            aOrbiterG = RotL64((aOrbiterG * 5994900368027985469U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14023633125757654751U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11319146808574958827U;
            aOrbiterC = RotL64((aOrbiterC * 13676159969338309307U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14161653180846538446U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17993503892528842342U;
            aOrbiterA = RotL64((aOrbiterA * 12184170842617942651U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10449311783872638478U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17210495321003036773U;
            aOrbiterE = RotL64((aOrbiterE * 17591257107603354151U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14586515403314763393U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17668251151213543491U;
            aOrbiterF = RotL64((aOrbiterF * 9367185933291003363U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 20U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 28U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 26U) + aOrbiterB) + RotL64(aOrbiterF, 53U));
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 50U)) + aOrbiterB) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterE, 37U)) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // ingress from: aFireLaneA, aWorkLaneA
        // ingress directions: aFireLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: mSource, pSnow, aWorkLaneB
        // cross directions: mSource backward forced, pSnow backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 17526U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19448U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 20378U)) & S_BLOCK1], 18U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 20138U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18808U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 6U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererE + RotL64(aScatter, 51U)) + 16519040829220310189U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 23U)) + 6888002778416941825U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 60U)) + 1310832187746534025U;
            aOrbiterI = (aWandererC + RotL64(aCross, 3U)) + 5890888009051281674U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 5143864838362464857U) + aNonceWordL;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 53U)) + 15591534069452660003U;
            aOrbiterE = (aWandererK + RotL64(aCross, 5U)) + 1466867671765325096U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 48U)) + RotL64(aCarry, 51U)) + 13931443680107902488U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 37U)) + 15400747367673245552U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 2836975369734495759U) + aNonceWordM;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 21U)) + 2370720358274970117U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3470677184188006133U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7175584278499266723U;
            aOrbiterA = RotL64((aOrbiterA * 10067096593682482345U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6095078817776863055U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2176637999243513070U;
            aOrbiterK = RotL64((aOrbiterK * 12215701810843975501U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5580391239754903129U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15196125567953871184U;
            aOrbiterB = RotL64((aOrbiterB * 12686361960729564519U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12787014151503209931U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1523153207064063495U;
            aOrbiterJ = RotL64((aOrbiterJ * 3113907543551927561U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12973289026485937829U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9087439766232078173U;
            aOrbiterF = RotL64((aOrbiterF * 5817029335999350327U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16318022893068674015U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 11089160685103562409U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 17087834321385147603U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 8680037953925067235U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3112588943274158119U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 9214011370307670371U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16749015684369649821U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9419550535891334966U;
            aOrbiterI = RotL64((aOrbiterI * 5421312787569114811U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12309598080688360615U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12244971765096881835U;
            aOrbiterE = RotL64((aOrbiterE * 17260277357109449509U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10088685417774847648U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3241987595838650154U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14096986158958931367U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17916401586500786536U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16519040829220310189U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6742024268853509861U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 39U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + aNonceWordG);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 24U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 56U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 27U));
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterI, 46U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 24U) + aOrbiterG) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 40U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererC, 30U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // ingress from: aFireLaneB, mSource, pSnow, aWorkLaneA
        // ingress directions: aFireLaneB forward forced, mSource forward forced, pSnow forward forced, aWorkLaneA forward/backward random
        // cross from: aFireLaneA, aWorkLaneB
        // cross directions: aFireLaneA backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 25687U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 22910U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25470U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 25679U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24191U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 22699U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 21U)) + 8375305456876489425U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 51U)) + 16193562952772453047U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 18088652458594816223U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 767344788620249944U;
            aOrbiterG = (aWandererG + RotL64(aCross, 24U)) + 7705194930396368752U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 57U)) + 3829736891311272834U) + aNonceWordL;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 29U)) + 9881681671347640061U) + aNonceWordM;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 35U)) + 1721196560190164264U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 3002652618388454213U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 37U)) + 9811621464004005202U) + aNonceWordJ;
            aOrbiterK = (aWandererH + RotL64(aCross, 54U)) + 5652598941069986530U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6250499348327316328U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16025054277615264530U;
            aOrbiterE = RotL64((aOrbiterE * 16446892258704281903U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13800298546867243172U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 12256104592865905782U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 16983140179497142713U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17817225416918329229U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17738671327352776217U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 393488251327705063U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6816031224188400541U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16989563985059237014U;
            aOrbiterA = RotL64((aOrbiterA * 8677884225771717797U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16891524847268207549U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1833508573940405571U;
            aOrbiterB = RotL64((aOrbiterB * 9709196587703979539U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12729999421507068973U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6839758643521968957U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16350557395881283975U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8524167125469267428U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14741523560290472617U;
            aOrbiterG = RotL64((aOrbiterG * 4367850822282205897U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10983798459868424892U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5649250846622078964U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7149612714806023987U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8587302028325090061U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17457129226030333666U;
            aOrbiterF = RotL64((aOrbiterF * 18107356450566915215U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15600113588474915690U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6595247491374683783U;
            aOrbiterI = RotL64((aOrbiterI * 1432432381540098765U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13246325856585534283U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8375305456876489425U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8331406038795786099U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 60U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 47U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 54U)) + aOrbiterI) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // ingress from: aFireLaneC, pSnow, aFireLaneA
        // ingress directions: aFireLaneC forward forced, pSnow forward forced, aFireLaneA forward/backward random
        // cross from: aFireLaneB, mSource, aWorkLaneB
        // cross directions: aFireLaneB backward forced, mSource backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 27590U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((aIndex + 29868U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 32106U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30293U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31601U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29013U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCarry, 35U)) + (RotL64(aIngress, 4U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 37U)) + 4752759164691497960U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 29U)) + 12088872623537639782U;
            aOrbiterH = (aWandererD + RotL64(aCross, 10U)) + 3734943577379734227U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 8854778183012444234U) + aNonceWordA;
            aOrbiterC = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 16948373492893967275U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 53U)) + 7962415690046184385U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 12U)) + 1872682375669714454U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 21U)) + 7776801806943853566U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 51U)) + 16665439117257230732U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 11088186766134265676U) + aNonceWordN;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 23U)) + 10850237991780969350U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6464817712131305812U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 244557182884209844U;
            aOrbiterH = RotL64((aOrbiterH * 2394270354887582889U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13261563971157415841U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2323811103717827362U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 11483723582415081925U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12338803568475493422U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2811342930111104982U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5020981755203607757U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5554497011738996057U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12712169745460598698U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1985586486150377769U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17415058661427002973U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9430421222715343818U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10321140659099470811U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3926618548181233180U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6172453297026957838U;
            aOrbiterB = RotL64((aOrbiterB * 1161551082037835233U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8633288765997226004U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17270881130844274342U;
            aOrbiterI = RotL64((aOrbiterI * 8888559940161770791U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12232950994807835262U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15352600312956742750U;
            aOrbiterF = RotL64((aOrbiterF * 6140396356904933003U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5614120002595447983U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1920822446545182835U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 17049182594382482085U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 625576652179261739U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2362773059031414585U;
            aOrbiterK = RotL64((aOrbiterK * 17049048587829564949U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16749690978107177915U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 4752759164691497960U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8442185754037031199U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterD, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 23U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 39U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterH, 11U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 14U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + aNonceWordJ);
            aWandererC = aWandererC + ((((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 46U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 48U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
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

void TwistExpander_Archery_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD1BE6A60ED89D1C3ULL + 0xFD25F131905FB8E3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9AD1EFB237070509ULL + 0xD8FF1DD557AFFEECULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE3CD7A8F48B2D62FULL + 0xC629D1A5315D8CB5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD6CDF91169FD01D5ULL + 0xBC80A7FF77886B44ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEFF8FB97CD1F090BULL + 0xD237CA2E70B38890ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8FE85AC9FD0F69CDULL + 0x8E4386B210EEA14DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9B7FF1E3286EF18FULL + 0xA299077BF2663E4EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFF61727937A27F8FULL + 0xD2EE5F62228E6654ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFB8886B8778217A3ULL + 0xEFF0F3A4FA9B3E39ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFD51EC420AA1B6D1ULL + 0xBE456B37A7164B82ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8AA98C06545722D5ULL + 0xC6A6C7AEA008FF0EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB9528C81A3EFB4B7ULL + 0x8B2F73841DB92DC2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCB8A41E7B392ED0DULL + 0xA7B46CBF9CAD623FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x975C83422A4C9ACFULL + 0xE3ED2AC7E86C4F00ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB4B3FA88E540818BULL + 0xBF772BEFC627A506ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC0EB4794BD8AF6D1ULL + 0xD4BF02C77FB06AB8ULL);
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
        // read from: aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_a_loop_b loop 1
        // ingress from: aFireLaneA, aFireLaneB
        // ingress directions: aFireLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aFireLaneC, aFireLaneD
        // cross directions: aFireLaneC backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 1544U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 6605U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6506U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneD[((aIndex + 581U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 24U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (aWandererB + RotL64(aScatter, 18U)) + 17711946802293254150U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 16652362590489569378U) + aNonceWordL;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 57U)) + 6972810344198183097U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 47U)) + 13117100889782940546U;
            aOrbiterD = (aWandererE + RotL64(aCross, 30U)) + 13199305696782626591U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 11U)) + 992156184392760945U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 13791265442074543880U) + aNonceWordD;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 17057087245252294859U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 43U)) + 13444195995883541046U) + aNonceWordA;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6723678233676059420U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7913379431208430475U;
            aOrbiterJ = RotL64((aOrbiterJ * 2295062944289127123U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4481887195529300665U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11892724101424384078U;
            aOrbiterG = RotL64((aOrbiterG * 3468639499716604111U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7700902083270424194U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1888001433557140271U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8975562955027025349U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14996753906788986929U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 939004845422123765U;
            aOrbiterD = RotL64((aOrbiterD * 2507090308972292313U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11922230289291941807U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 15681187459741147199U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 10124947739653819101U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9119043713532718155U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 8327697433992362166U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 11157657162184304567U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13630755116592440359U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 771252613886022889U;
            aOrbiterA = RotL64((aOrbiterA * 2958918915223536519U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8524239721467527770U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17732617735422435572U;
            aOrbiterB = RotL64((aOrbiterB * 13992947983987668631U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5265753270696005619U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14456128349522985053U;
            aOrbiterF = RotL64((aOrbiterF * 5406509991740849617U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aCross, 28U) + aOrbiterB) + RotL64(aOrbiterC, 52U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 37U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aCross, 52U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterA, 58U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 23U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 2
        // ingress from: aOperationLaneA, aFireLaneB, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aFireLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aFireLaneA, aFireLaneD
        // cross directions: aFireLaneA backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8961U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((aIndex + 15658U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11797U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13449U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12128U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 60U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (aWandererI + RotL64(aScatter, 18U)) + 7960325128608297381U;
            aOrbiterF = (aWandererD + RotL64(aCross, 53U)) + 12773836012104052042U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 29U)) + 3173972621347773016U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 3708401356314308171U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 22U)) + 950774285720019449U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 4170092315705438265U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 17000449130864980747U) + aNonceWordO;
            aOrbiterH = (aWandererG + RotL64(aIngress, 5U)) + 8793910540062893860U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 37U)) + 520277969543516469U) + aNonceWordL;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12762214857389827271U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2932451184340207695U;
            aOrbiterK = RotL64((aOrbiterK * 7513337346940091655U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11062179998786293839U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7919119215271524178U;
            aOrbiterF = RotL64((aOrbiterF * 9053677007180081359U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1774988449597115155U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3799792889466518953U;
            aOrbiterC = RotL64((aOrbiterC * 17512791286490623455U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 1815062051307896589U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15260373951371654483U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2208604434669491625U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12867546628945676853U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7772820973895846946U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7581704643538761985U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 14213957831821966834U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16561105721170419454U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2540533987337175367U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16556502948339949526U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9706742922075498974U;
            aOrbiterA = RotL64((aOrbiterA * 8527361328901355457U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13455756934917486016U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9107769876332723454U;
            aOrbiterH = RotL64((aOrbiterH * 1722386100852683783U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 15793099079168487016U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7968278803691283365U;
            aOrbiterB = RotL64((aOrbiterB * 11644765391940099387U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 14U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aCross, 36U) + aOrbiterA) + RotL64(aOrbiterF, 27U)) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 48U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + aNonceWordG) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 10U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aCross, 48U) + aOrbiterE) + RotL64(aOrbiterH, 23U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 3
        // ingress from: aOperationLaneB, aFireLaneD, aFireLaneA
        // ingress directions: aOperationLaneB forward forced, aFireLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aFireLaneB, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aFireLaneB backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17352U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 17139U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 17422U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22471U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18558U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19070U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 58U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 3684295017013759987U) + aNonceWordF;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 3U)) + 6740408842457292881U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 53U)) + 4563975890702399441U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 11U)) + 797804144825287940U) + aNonceWordJ;
            aOrbiterC = (((aWandererK + RotL64(aCross, 5U)) + 2763779540450101303U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererG + RotL64(aIngress, 43U)) + 13211846164102089685U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 47U)) + 15214578447281401982U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 30U)) + 13745208628754232427U) + aNonceWordC;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 17358621225969190747U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 779739369960480023U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4370963533701407813U;
            aOrbiterK = RotL64((aOrbiterK * 3123135216876641039U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6061333005507739975U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3589705340762734456U;
            aOrbiterC = RotL64((aOrbiterC * 16499293983611196967U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10607697666369230567U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9356757995305239271U;
            aOrbiterD = RotL64((aOrbiterD * 10945513661439954731U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10093033335903048138U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11037328061699834100U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11189760551792389605U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 558431161176115540U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17795680919453449358U;
            aOrbiterJ = RotL64((aOrbiterJ * 3910117359996283803U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 6096779391116214109U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17594243286880690775U;
            aOrbiterA = RotL64((aOrbiterA * 12655610181937429915U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 15414704802398002423U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 18040588240488602196U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16344249573086571225U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14636298592697156931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9677305688594936561U;
            aOrbiterE = RotL64((aOrbiterE * 8354776999961642997U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 16408025751875050713U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10018342878801454965U;
            aOrbiterI = RotL64((aOrbiterI * 10349132962708124117U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 60U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 60U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            aWandererK = aWandererK + (((((RotL64(aCross, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterC, 53U)) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aScatter, 30U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 14U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterB, 41U));
            aWandererG = aWandererG + ((RotL64(aIngress, 26U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 4
        // ingress from: aOperationLaneC, aFireLaneC, aOperationLaneA
        // ingress directions: aOperationLaneC forward forced, aFireLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aOperationLaneB, aFireLaneD, aFireLaneA
        // cross directions: aOperationLaneB backward forced, aFireLaneD backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31436U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 29436U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 25508U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32415U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32728U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 25355U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 29U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 44U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererE + RotL64(aIngress, 47U)) + 3561491146322798260U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 51U)) + 7075025056181885339U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 24U)) + 9230910887904171613U) + aNonceWordF;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 4119781172609908917U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aCross, 57U)) + 17155609083870983149U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 13U)) + 2423018561430181695U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 6U)) + 12957280305617615744U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 2461704174772065813U) + aNonceWordL;
            aOrbiterD = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 7907123257849391997U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7257868138318960007U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16425903703085702285U;
            aOrbiterG = RotL64((aOrbiterG * 7996935869077231999U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2990822664594079467U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5654819006718953817U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 4465096036756887801U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12183676471235678779U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15026286960542123922U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 17199049329995315279U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12169080607071830522U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2906296852254787499U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 6754514406846040163U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3029858695410344584U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 14406410317495954566U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9663780721657983421U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11048818178401163861U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13622063920319445043U;
            aOrbiterA = RotL64((aOrbiterA * 2516025554421589857U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2642646089141233277U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12761571777929273548U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5518252696078700127U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7753802695131502382U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8510425459525030222U;
            aOrbiterE = RotL64((aOrbiterE * 12412361423636026483U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13522645164493316722U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1437430302489702713U;
            aOrbiterD = RotL64((aOrbiterD * 14019316635365783545U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 50U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterE, 58U)) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterH, 48U)) + aOrbiterF) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Archery_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x97D9F6AAA8E7B97BULL + 0xA386DD1813685CA0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA80DEE21197ADECFULL + 0xA47F7886953100DEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA74ECACBB5D23C29ULL + 0xCDD8698CD8077D25ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE79D21FE16C03ABFULL + 0xCE8C0317AFDAB5C9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC89ECCBE0F508699ULL + 0xA74A950C254987D9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD5230A3B02A10D65ULL + 0xEAED373DCF550EC3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x88F3CCB80831EC1FULL + 0xD5051FE4D86F641DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x843ACEEE0FB48E0FULL + 0xD3568664BC560152ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEACAB5B4D1EFF1CFULL + 0xDC8D9AFA73942A51ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF316F1C2DC11F17FULL + 0xA057CB9FAD6D6BC3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC2425360D188AC69ULL + 0xB2633A2D0FBAB7C5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDC01447518886BA1ULL + 0xCC34215F8805220BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDC58FD7A2340D403ULL + 0xAB4A8ABC9FE93099ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8CF9AF0052715819ULL + 0x85D7AE4311061F95ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8973DD0830B51713ULL + 0xFA9092C4301BADBAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBA584564D8C4BA73ULL + 0xD818834FC0EA8129ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6571U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 2458U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 4623U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6800U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6178U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 23U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 1087148170018530502U;
            aOrbiterD = ((((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 15530846874509311414U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 23U)) + 16987358651515511212U) + aNonceWordK;
            aOrbiterI = ((((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 12504143181007924259U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 46U)) + 393322117322732418U) + aNonceWordE;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14325937299241887166U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9395262907017475742U;
            aOrbiterF = RotL64((aOrbiterF * 3442643798173589117U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13658510441418344769U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6410754322737005336U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6932217611373076391U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 9257290738538818434U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 7489828960857692286U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16519674788777989043U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4118778591214588387U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16619215231168796563U;
            aOrbiterE = RotL64((aOrbiterE * 14876884956536265157U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 11326283811003573430U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1865401866017614604U;
            aOrbiterK = RotL64((aOrbiterK * 8378326058282460073U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 38U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterK, 27U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterD, 48U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + aNonceWordD);
            aWandererF = aWandererF + (((((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 53U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererB, 58U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13457U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 11379U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16131U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10160U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12774U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 15684U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 3917730204724097072U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 3U)) + 1874642340716212824U) + aNonceWordG;
            aOrbiterH = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 6900165757434854160U) + aNonceWordK;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 12750946097023807161U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 14U)) + 6563216048479513594U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14960240191349450795U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16306180275951788289U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 12077366095522790283U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6502066618271045547U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6219852857850888738U;
            aOrbiterA = RotL64((aOrbiterA * 10892297250334325283U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2272931312452845850U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3028929882263199463U;
            aOrbiterB = RotL64((aOrbiterB * 11005324285856805069U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 6067393030073568112U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10094809900437037258U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18095564940730322769U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5962414178157074575U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15755563045799129417U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 3692603590609922031U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 56U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterG, 27U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 40U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneD
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18980U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneD[((aIndex + 20834U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 20202U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18390U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20885U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 20049U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 39U)) + (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 16462052553719977502U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 42U)) + 12337064059566619581U) + aNonceWordM;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 15801005007094515447U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 29U)) + 8228706742665081656U) + aNonceWordJ;
            aOrbiterA = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 11006723027845190869U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 18173765337829177450U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 530215083653542558U;
            aOrbiterH = RotL64((aOrbiterH * 8938680024265564887U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6608611827035564511U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2246051826221626809U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 6333352641495253539U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5228575308895381421U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10999213210689606857U;
            aOrbiterA = RotL64((aOrbiterA * 5467601259546342925U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3773371037240485696U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8887985779436152504U;
            aOrbiterF = RotL64((aOrbiterF * 698713082830739677U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11150566414723818350U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8336366151003049546U;
            aOrbiterJ = RotL64((aOrbiterJ * 9033771197242493699U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 56U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterA, 57U)) + aNonceWordI);
            aWandererG = aWandererG + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 14U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 3U));
            aWandererJ = aWandererJ + (((((RotL64(aCross, 34U) + RotL64(aOrbiterH, 41U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordO) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 24982U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 32000U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 31537U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25518U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26680U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28137U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 26496U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 52U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 12980104182836602177U) + aNonceWordD;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 5U)) + 3172622203188863995U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 3U)) + 1170974132219980203U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 6035201940965047490U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 57U)) + 18033907118424996722U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14604813424800580304U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 13720232492851066035U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 8927246214721284759U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3902659710585257448U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8331560652661619868U;
            aOrbiterD = RotL64((aOrbiterD * 11418103770615560205U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4485014147538689794U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 168202636924512424U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13711020666131492091U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16227825670092707848U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4792781933944671365U;
            aOrbiterJ = RotL64((aOrbiterJ * 15859849676231455283U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12636865372722601282U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 18198291399585556632U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 18155803890313399795U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 4U)) + aNonceWordC);
            aWandererE = aWandererE + ((((RotL64(aIngress, 56U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 37U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + aNonceWordI) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
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

void TwistExpander_Archery_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9B5FC0846AF551A1ULL + 0x8B83097658ABC07BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x961487DDD2BE4193ULL + 0x908CB385CD318A3CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB0AE6047ED891DC7ULL + 0x8A7295DB21534DD6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD8DB49D30F7A55E1ULL + 0xB3EED7158349A738ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xED9DF745881A8B2BULL + 0xFBEC62FBEEEAE946ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x98E228AD35F98C23ULL + 0xC9B6D08FB0CB1241ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9BCA76C29C87E31BULL + 0x88876F6D6E3956EBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB8EC05D6754362B1ULL + 0xD15F10608C3CB5C7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDF00CE17F39EF9ABULL + 0xD7EBC6BCBEF708BBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB4EA369B02EB84DFULL + 0xCB604ABFE00AA226ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9B7D4F80E19F09E3ULL + 0xB05E57406CF7674DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x815ADE7C0E66AC09ULL + 0xB8E3C01D19734651ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xECBF58A25A65A195ULL + 0xAC7C949C865847ECULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA4C81D7907B607DFULL + 0x8027C315FA98A529ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x90704BCFFF49E217ULL + 0xF1A37A1FBF03BD1DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE51322CF6A2BA8E9ULL + 0x94BED86D6682DA03ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneD, aExpandLaneC, aExpandLaneD, aFireLaneD, aWorkLaneA, aOperationLaneB, aOperationLaneC, aWorkLaneB, aFireLaneA, aFireLaneC, aWorkLaneC, aFireLaneB, aOperationLaneA
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5058U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 1932U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 5058U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 654U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7060U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 3212U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 7896237440058555694U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 23U)) + 11870529476037558635U) + aNonceWordA;
            aOrbiterC = (aWandererH + RotL64(aIngress, 37U)) + 9158983227801569448U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 43U)) + 4710172270996950329U) + aNonceWordL;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 12U)) + 14634482800356647630U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 8822207952170610891U;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 13755891414028982553U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4555293067488040719U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2816805148093762081U;
            aOrbiterC = RotL64((aOrbiterC * 16838149138341713943U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2122631477965135190U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4592922416380416071U;
            aOrbiterD = RotL64((aOrbiterD * 11644507904538573165U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7102471666524164715U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17274623547879474204U;
            aOrbiterA = RotL64((aOrbiterA * 5443572270546181789U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 938587316977094680U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 18258015823797023523U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 6068819567674605919U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5809987756043471595U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5083075160112581620U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 3313957222154937503U), 21U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 5960021727750946496U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 5967477320950630150U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 330964768256424655U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6578428711689296132U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5601728218197771276U;
            aOrbiterH = RotL64((aOrbiterH * 9552559022315971847U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterC, 46U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 19U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 37U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterE, 3U));
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 21U)) + aNonceWordF) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 52U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10481U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 16143U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10062U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14537U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9665U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9723U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 21U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((aWandererI + RotL64(aIngress, 53U)) + 6243113109470883144U) + aNonceWordM;
            aOrbiterC = (aWandererJ + RotL64(aCross, 41U)) + 3891552123999605832U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 21U)) + 8758797898587019128U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 14U)) + RotL64(aCarry, 5U)) + 1005891374086408851U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 47U)) + 3713426782180050764U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 18358143862391573534U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 17504394029693712404U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5312729289027417014U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2560873623431186029U;
            aOrbiterH = RotL64((aOrbiterH * 16843728573219210173U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 16309322822806704211U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10195513918020652600U;
            aOrbiterE = RotL64((aOrbiterE * 14569219741824123715U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2552116263258744287U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7732784879810980089U;
            aOrbiterB = RotL64((aOrbiterB * 15041929399477790999U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16499127570665381507U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 10890036715535519036U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9065115450010475187U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16288944603478791554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14542766121469312846U;
            aOrbiterF = RotL64((aOrbiterF * 8435383464425875209U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5973595239494084696U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1820492719977197097U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 16164917159141304405U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10489529555776381736U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6392552206958240484U;
            aOrbiterC = RotL64((aOrbiterC * 11761477994533503307U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 20U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterH, 3U)) + aOrbiterF) + aNonceWordK);
            aWandererI = aWandererI + ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 23U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterB) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterH, 13U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterE, 26U));
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19079U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 21501U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 18920U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22461U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19357U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 20751U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 9630214189402543339U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 35U)) + 4072576573737526819U) + aNonceWordO;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 4U)) + 15994787452709618869U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 6403240137132259482U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 47U)) + 10229266900170507720U) + aNonceWordL;
            aOrbiterK = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 5025294577989748989U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 27U)) + 16696461238217956883U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9878318855341719119U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16086635438116177346U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5585682357395705671U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 12295437783084203730U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7681150419912842402U;
            aOrbiterG = RotL64((aOrbiterG * 7289497379725191451U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2639104034287637448U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12298170009332243573U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 9397919591171238575U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3485932317267669626U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16569551670038752475U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 8139802826402217631U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4448490103784103954U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14510534073046885941U;
            aOrbiterA = RotL64((aOrbiterA * 7777192047386438305U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4286195398675733451U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15790355933840266463U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13342257823027075501U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6362891510370156055U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15121822034579983174U;
            aOrbiterK = RotL64((aOrbiterK * 7268045994574844937U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 4U) + aOrbiterK) + RotL64(aOrbiterA, 53U)) + aNonceWordA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterI, 18U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + aNonceWordM);
            aWandererE = aWandererE + ((((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 53U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26306U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 29950U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27427U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25099U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32730U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 26929U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 58U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 10U)) + 3970829908171131502U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 3U)) + 7040283759419531991U) + aNonceWordB;
            aOrbiterG = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 11856292169397052901U) + aNonceWordF;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 819598588791819022U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 29U)) + 2176451710970866848U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 57U)) + 6454704928613390494U) + aNonceWordD;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 11792122387218053841U) + aNonceWordG;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9254780213489752211U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16591812589999846482U;
            aOrbiterG = RotL64((aOrbiterG * 5425771603523423167U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1471246223935074832U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1424843083106386453U;
            aOrbiterF = RotL64((aOrbiterF * 15020536982657410783U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1856469958050891629U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6331743690452052712U;
            aOrbiterA = RotL64((aOrbiterA * 15327924647897459645U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10351075711345476487U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 9518585245330480185U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 3792179827396760391U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17787514620244712033U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 14182328067398162557U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18107337388659070197U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 12798088948801072444U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9563215159275202323U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 7058145016617349141U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9904919772580498232U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16579777394992143043U;
            aOrbiterD = RotL64((aOrbiterD * 10516761340320196661U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterC, 53U));
            aWandererC = aWandererC + (((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterK, 13U));
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 40U)) + aOrbiterE) + aNonceWordI);
            aWandererI = aWandererI + (((((RotL64(aCross, 11U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordL) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 38U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Archery_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB74AD4BCDEEAF9ADULL + 0xFE6FA4A328E7DF2DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x972A3931B47D1A07ULL + 0xA80EF28093816070ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB0EB5BC054125E23ULL + 0xAA0D3F4CE58D792FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA23E1A2CDFBB960FULL + 0xE6A01F9DB8B741A3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x85790CB36D422EF7ULL + 0xC6F6957BA84366F2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9F2F5DEDB615F20BULL + 0xDA5AF1488E8647BCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF7767C4D2E82C3D9ULL + 0xC859AF57780A0509ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC5B6701D0C4A2EF5ULL + 0xBD3527626F2CDD1BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFBBD7679FAD83D1DULL + 0xFC4868E5D7512E38ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC7A820B944389333ULL + 0x93AAB7AED937F241ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC59F58C2FDC2C159ULL + 0xE13C4B7FBA692519ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD0334C2EED248259ULL + 0xC5D5C8D960BB7071ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC0616529078564DFULL + 0xAAA691EFAC48FC7AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBA6DFCEC5CE9C2CBULL + 0xC9784E3AB0BCCC22ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x98C5075EB1E7D643ULL + 0xDB080AF474D0A0EFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCB653D66A2538E9DULL + 0xC53E3DAEC1429069ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aOperationLaneA, aFireLaneB, aExpandLaneB, aOperationLaneC, aFireLaneC, aExpandLaneC, aOperationLaneD, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1989U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 4767U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2406U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3516U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7333U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7731U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 53U)) + (RotL64(aCross, 38U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 11U)) + 6733949564325516029U) + aNonceWordA;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 7304098437143918796U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 27U)) + 3923949518391777800U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 14243591003388927124U) + aNonceWordC;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 5U)) + 18329498724605410406U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 51U)) + 13118172167747037249U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aWandererF + RotL64(aCross, 42U)) + RotL64(aCarry, 29U)) + 5272025143849174212U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16075917179214318424U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15263590648674658399U;
            aOrbiterE = RotL64((aOrbiterE * 9918239923411740337U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13730046728289525921U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7703141464499623408U;
            aOrbiterI = RotL64((aOrbiterI * 5886009900621521987U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1382279753822135359U) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2973369221699098292U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 7440242040663550631U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11578274119583013219U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3419411247737896674U;
            aOrbiterD = RotL64((aOrbiterD * 17814942652262802991U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2582783513078999303U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3959762790273529677U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 383974377372162751U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 465795011576934604U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17880826624185821135U;
            aOrbiterJ = RotL64((aOrbiterJ * 4445949147592860913U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10819659185349413173U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17298208553586835030U;
            aOrbiterF = RotL64((aOrbiterF * 1965860510614222093U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 10U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 21U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11201U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 10123U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11569U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14455U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10595U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8919U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 58U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 5697928251815176134U) + aNonceWordN;
            aOrbiterK = (aWandererG + RotL64(aScatter, 41U)) + 337587740689259575U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 34U)) + RotL64(aCarry, 39U)) + 4927686903263973950U;
            aOrbiterE = ((((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 3742409032569801033U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererE + RotL64(aCross, 3U)) + 1608092659172197650U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 11U)) + 15848744267145717509U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 53U)) + 15300174177963339253U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14162868453323648628U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12020167069983729869U;
            aOrbiterB = RotL64((aOrbiterB * 2071080217680099017U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16259538291658723956U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8516686212464112245U;
            aOrbiterA = RotL64((aOrbiterA * 4731296903548893627U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3722184575520553132U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5663609293306386784U;
            aOrbiterK = RotL64((aOrbiterK * 14364218128780764749U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15265344442454471986U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3050323350098829515U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5890624677162388135U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1093356813820599238U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15167726103772238440U;
            aOrbiterE = RotL64((aOrbiterE * 5719466863561311069U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 15170797965325981472U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17826286701992981628U;
            aOrbiterD = RotL64((aOrbiterD * 11186808881726573677U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14710892030473425181U) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 397194787697553904U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 14368930300818752833U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 50U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 27U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterD, 46U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18293U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneD[((aIndex + 17901U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16640U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20864U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18361U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16633U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 5U)) + (RotL64(aPrevious, 44U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = (((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 4068921616130916949U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 20U)) + 12077715273915151726U;
            aOrbiterE = (aWandererE + RotL64(aCross, 37U)) + 16047546802670596833U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 9690277462716999763U) + aNonceWordE;
            aOrbiterB = (aWandererG + RotL64(aIngress, 57U)) + 14484814700447992628U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 13U)) + 17089267243053958210U;
            aOrbiterD = ((((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 9138746214446211147U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10181001536979097045U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6657458969093373191U;
            aOrbiterE = RotL64((aOrbiterE * 4311019792293202747U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7515983477876590988U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3039935555863947600U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12511160550780270119U), 37U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 16209389224740851136U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 725253312098083182U;
            aOrbiterF = RotL64((aOrbiterF * 17535989492095522597U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13307041115748941383U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7159572004825238263U;
            aOrbiterG = RotL64((aOrbiterG * 4855009895002398449U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12027236743251643820U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8717826175991286553U;
            aOrbiterJ = RotL64((aOrbiterJ * 1175614802543098451U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4769096034227659937U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11201226563992939616U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15595355978388159931U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 17295978531215563256U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11850923890626719833U;
            aOrbiterB = RotL64((aOrbiterB * 3854851059897397075U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 36U)) + aOrbiterJ) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + aNonceWordH);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + aNonceWordF) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32405U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 28663U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 32169U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27862U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29465U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 30996U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 3U)) + (RotL64(aIngress, 40U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (aWandererI + RotL64(aCross, 11U)) + 8101351470141807662U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 57U)) + 6965474099521076705U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 38U)) + RotL64(aCarry, 37U)) + 6803828268885684784U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 13454235922950972488U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 11678091885751244777U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 29U)) + 5307134544628507141U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 47U)) + 4873703518950429353U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8542156221858586039U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3993726182905296513U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11331376012938127609U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12113047622035464386U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1944244448665721151U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 7010050836758762003U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12914188029425467576U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2486762763475327024U;
            aOrbiterC = RotL64((aOrbiterC * 12319769994433811617U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14580191602982245481U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12093414832400135066U;
            aOrbiterJ = RotL64((aOrbiterJ * 12720286833215690663U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13623906997320021065U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9977356009806428696U;
            aOrbiterB = RotL64((aOrbiterB * 2005536391712733499U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3694954095397810851U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11453812627797091638U;
            aOrbiterK = RotL64((aOrbiterK * 13730420725113907161U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 542311345544726351U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3024285045990499484U;
            aOrbiterD = RotL64((aOrbiterD * 5153745952148205645U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 21U)) + aOrbiterE) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + aNonceWordC);
            aWandererC = aWandererC + ((RotL64(aCross, 54U) + RotL64(aOrbiterC, 12U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Archery_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC3C192F2DE8D8A8DULL + 0xE57A516FB7385CA5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA76543BF85C4C3A1ULL + 0xC3B5529FD92DCDF7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x86D15A607A2B5509ULL + 0xF9B461614C3F504FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x97F4079C501F982FULL + 0xBBBDAAA0B9F480E7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC65B7705B599B737ULL + 0xB0063BF28EC0DC32ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD6E055308BCDA383ULL + 0x84F2A1C8B2DDAD14ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE062996D3BD2A71DULL + 0x82D7228456096F1FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE88160C08AD8FB3BULL + 0xF0F7DEC50085B3ACULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE4B13EB4CC77DFEFULL + 0xA6C38C05644E8EADULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC6F0E0AD363DC1E3ULL + 0xD0C284D734AC2C04ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC89500CD50A646BFULL + 0x8D4D05099140F95BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDCB28AE1AFEC530DULL + 0xD87CF9012F9853B8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x87D036C34D9DCE3FULL + 0xF94C719D6EB3572FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAB34D8A7C8EFA481ULL + 0x92E0A631FCE37BF3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE4F00F777C6638C5ULL + 0xBDD5312EB107F685ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFC8B333470569EADULL + 0xB72EBD674CEBA9EAULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aWorkLaneC, aOperationLaneA, aFireLaneB, aWorkLaneA, aOperationLaneB, aFireLaneC, aWorkLaneD, aOperationLaneC, aWorkLaneB, aFireLaneA
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 445U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 1238U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 4023U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8149U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7894U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 2779U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 13U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 30U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 51U)) + 16189787374324972735U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 21U)) + 17563763730956242224U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 10572803498593789385U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 47U)) + 7713105232072974166U) + aNonceWordC;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 13U)) + 10760839534772718139U) + aNonceWordD;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 40U)) + 13397069448391230253U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aWandererA + RotL64(aCross, 37U)) + 4569255679998375682U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 57U)) + 9888769350817876949U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 11351796060878856300U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 44U)) + 18153775071965707204U) + aNonceWordK;
            aOrbiterE = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 1282846411145853435U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16457743979262460660U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 173493260775251032U;
            aOrbiterG = RotL64((aOrbiterG * 4935807229040883505U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3927345926316409630U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5158769729850853623U;
            aOrbiterA = RotL64((aOrbiterA * 2446452358663812945U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12331351600010165154U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3940794200348684050U;
            aOrbiterB = RotL64((aOrbiterB * 13248997263062075043U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11248514843822945425U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 1391497323278226522U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8376841806072565005U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13265623528678787307U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2802033745265647317U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3437626962562016147U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6938444301018051844U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1086544666755559028U;
            aOrbiterE = RotL64((aOrbiterE * 16039728388882079889U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16156443117365816536U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3619942859562697142U;
            aOrbiterC = RotL64((aOrbiterC * 7589346043159112151U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17681848914912743292U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8848238631758130416U;
            aOrbiterF = RotL64((aOrbiterF * 810402256099500607U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6019192027793541890U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16917288363166352778U;
            aOrbiterK = RotL64((aOrbiterK * 17673667086593738207U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5598218150530046752U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17285995539011279010U;
            aOrbiterJ = RotL64((aOrbiterJ * 15621233176885995065U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12380627610747299268U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16189787374324972735U;
            aOrbiterH = RotL64((aOrbiterH * 2144714828503219209U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 34U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 54U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 39U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 11U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 19U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aCross, 34U) + aOrbiterB) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 30U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9996U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 10670U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8288U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10915U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11406U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9820U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (((aWandererC + RotL64(aIngress, 57U)) + 4970414922752555648U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aWandererE + RotL64(aScatter, 41U)) + 9462756592787669327U;
            aOrbiterF = (aWandererB + RotL64(aCross, 39U)) + 3948790686662213095U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 50U)) + 14542857212241578311U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 3387479009827029547U) + aNonceWordH;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 37U)) + 1411421370057797877U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 47U)) + 16894451466895681236U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 21U)) + 12727136462290223542U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 30U)) + RotL64(aCarry, 3U)) + 4625389198191960525U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 3471881403786164913U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 23U)) + 6433115856048534831U) + aNonceWordD;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9825592965466157982U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1553125767261293088U;
            aOrbiterF = RotL64((aOrbiterF * 411535191177308781U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9951616357109647617U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11231080382787286889U;
            aOrbiterC = RotL64((aOrbiterC * 14024961994986659187U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13419663264017317947U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4835055642466215566U;
            aOrbiterI = RotL64((aOrbiterI * 17898065852351759171U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14558747666410946768U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13120938960926874504U;
            aOrbiterB = RotL64((aOrbiterB * 5681766019285559739U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11910501376797343986U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 15074100100781785300U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 228976960937473851U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12415377930578091821U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14882039078390681802U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13855446647753150713U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8094338361713756895U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5478280604704108822U;
            aOrbiterH = RotL64((aOrbiterH * 18062931724700600993U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6977017654546871841U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4131602217285988962U;
            aOrbiterJ = RotL64((aOrbiterJ * 11865422227883712419U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9619228479582032318U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 13506679497441415586U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5789932662418992799U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10180259475831448124U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4721628773773094283U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10834196399754443771U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7898137727558813688U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4970414922752555648U;
            aOrbiterG = RotL64((aOrbiterG * 6651835668618579479U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterI, 18U)) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterC, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 37U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 60U));
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + aNonceWordI);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 47U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 40U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24046U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 17104U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 18858U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19630U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21713U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21654U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 26U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 41U)) + 9654059367478508868U) + aNonceWordL;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 52U)) + RotL64(aCarry, 21U)) + 6473006635864677427U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 6944184481315853243U;
            aOrbiterB = ((((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 4061496421939102306U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 57U)) + 15791809275719085463U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 11U)) + 14050798802646323055U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 23U)) + 12072905924741758266U) + aNonceWordK;
            aOrbiterG = (aWandererA + RotL64(aScatter, 3U)) + 17639076509231343896U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 21U)) + 12195388285571234715U) + aNonceWordB;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 27U)) + 4325404419499496529U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 48U)) + 5910567888204238382U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13092940059929942699U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 13381962590820308761U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6345904465930943295U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15622862439323440527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14027151901132249793U;
            aOrbiterK = RotL64((aOrbiterK * 2273573821630510087U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4584410023907605157U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15763755180625487157U;
            aOrbiterC = RotL64((aOrbiterC * 6755736130607297639U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17023059745666559199U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5298529579288492971U;
            aOrbiterF = RotL64((aOrbiterF * 2483562793328357721U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2870152867331654736U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12017191100173748848U;
            aOrbiterI = RotL64((aOrbiterI * 9958191466506480519U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 15899529176182436062U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 16482713846343388735U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 719465695044265601U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12943393531812774449U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9881108254540483225U;
            aOrbiterJ = RotL64((aOrbiterJ * 8011108108007885059U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3532054586199716750U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7142230313294797435U;
            aOrbiterB = RotL64((aOrbiterB * 14154176174768868421U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 733958394016131587U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2060800099014517137U;
            aOrbiterG = RotL64((aOrbiterG * 12988885554457108631U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 2278498033811574812U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15342071118593803929U;
            aOrbiterA = RotL64((aOrbiterA * 7842196613533603835U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 12987212219357101955U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9654059367478508868U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11796100167917742307U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 24U) + aOrbiterF) + RotL64(aOrbiterB, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 29U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterH, 56U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 19U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 43U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aPrevious, 54U) + aOrbiterD) + RotL64(aOrbiterF, 54U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneB
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneA
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30481U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 28779U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29026U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31164U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26607U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 26710U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 37U)) + (RotL64(aIngress, 20U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 5041131702736607991U;
            aOrbiterA = (aWandererE + RotL64(aCross, 18U)) + 9295010428212681446U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 37U)) + 6235875895358766017U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 2622227802531866918U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 3888894734834524972U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 35U)) + 241682012014701753U) + aNonceWordD;
            aOrbiterG = (aWandererJ + RotL64(aCross, 60U)) + 15758000422451568079U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 57U)) + 2061944548396976912U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 29U)) + 8177144990755754531U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aCross, 53U)) + 554978075608818497U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aWandererB + RotL64(aIngress, 51U)) + 250408260560714933U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8700027645880997552U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10026130047465480902U;
            aOrbiterB = RotL64((aOrbiterB * 12417270861933696623U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9785843014096326696U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9998582683258411251U;
            aOrbiterK = RotL64((aOrbiterK * 7197956237569462269U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13817734599383455151U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6647207154174092691U;
            aOrbiterC = RotL64((aOrbiterC * 1578528131687283531U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4957715980509035719U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4994885315786213197U;
            aOrbiterJ = RotL64((aOrbiterJ * 5676683798126497011U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5072908311783966503U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 5535039946192891515U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2989412783482309753U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6594577050344146271U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 8750154123258714856U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 6942158167127532003U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3514769314840874873U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8626045200273524281U;
            aOrbiterA = RotL64((aOrbiterA * 4315441782689789689U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8524870284841706517U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1841819423572964209U;
            aOrbiterE = RotL64((aOrbiterE * 9802481758007234681U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12668382464510772517U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6330331402801670515U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9096920618612750935U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10346986196055766087U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10932918162471200996U;
            aOrbiterF = RotL64((aOrbiterF * 6863632877625141567U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6264557195446069146U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5041131702736607991U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 4978591546106895045U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 30U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 30U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterF, 39U));
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 57U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterH, 11U)) + aOrbiterA) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterB) + aNonceWordP);
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 47U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterI, 19U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterI, 36U)) + aNonceWordL) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 26U) + aOrbiterK) + RotL64(aOrbiterG, 21U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Archery_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF5778210210BCB91ULL + 0xC93E302E14E3D0F5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x80CDFE2FAEC64E1FULL + 0xF89083082FC8A98CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x94BEE8013EB07475ULL + 0xA45D49F8360A2113ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8E89103FB04C8C77ULL + 0xECEE7C66F913035BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD5C5FD9E6F807C2FULL + 0xF2CC26A1E48FD1F2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEC897E6E4268F61FULL + 0xC2B10AC9A7180124ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8429439EFBB6D419ULL + 0xE4AF863B8938A479ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x91A95173713A8557ULL + 0x9B2432D5720C42C5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8E00051077189757ULL + 0xED9A7D5606E848A7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9BE0E87F85AF05A5ULL + 0xB181FA6C2A576BA8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCA46B27573AEB321ULL + 0xFD014D946F84591DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x95B375D6B1E6C223ULL + 0xEDE7D1332427A5ADULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x94C45D97F52B252FULL + 0xBF02424D5A5695CEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x87D0405D020C27B7ULL + 0x9653DE2C37C322B3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA63710D2954A1177ULL + 0xC73BFAAEACA3D548ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xABE92C67AD19B809ULL + 0x80BFE8A6E1462B92ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneA, aExpandLaneA, aWorkLaneC, aFireLaneB, aExpandLaneB, aWorkLaneD, aWorkLaneB, aExpandLaneC, aFireLaneD, aFireLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4919U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 4388U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1082U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 220U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3981U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 5906U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 27U)) + (RotL64(aCross, 13U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = (aWandererG + RotL64(aCross, 29U)) + 8988572360732005217U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 23U)) + 17889613225105985335U) + aNonceWordL;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 11U)) + 15563478320513948626U) + aNonceWordG;
            aOrbiterF = (aWandererH + RotL64(aIngress, 36U)) + 3441351228410524816U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 4425592689451435346U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 12733160231627305928U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 3574152157304607854U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 58U)) + 15167631896729808783U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 43U)) + 15822667973915417055U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17181685481076577637U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9979204751408873468U;
            aOrbiterJ = RotL64((aOrbiterJ * 8244434774754786565U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1334240485667164762U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9190066751460137016U;
            aOrbiterI = RotL64((aOrbiterI * 14585141844653660363U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15465215829109246336U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 2305208282453624419U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 10257861974108363283U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 16951510027310993926U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11117938943423526901U;
            aOrbiterD = RotL64((aOrbiterD * 7805486716716924787U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12461379120662979432U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11719697049048823897U;
            aOrbiterK = RotL64((aOrbiterK * 14880996802304818757U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6843357278142933570U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12727898578324702374U;
            aOrbiterC = RotL64((aOrbiterC * 9786435451654365097U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18127999660067652233U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11754709060558683082U;
            aOrbiterG = RotL64((aOrbiterG * 12798744012150745847U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16940151146420516184U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12924950783056761895U;
            aOrbiterA = RotL64((aOrbiterA * 8898170377271926745U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14829713915929878471U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 840466047621042565U;
            aOrbiterF = RotL64((aOrbiterF * 10748511630509529489U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 60U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 58U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 27U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 37U)) + aOrbiterI) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 22U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterA, 44U));
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13784U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((aIndex + 9454U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 16214U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11726U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11015U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 14692U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 34U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (aWandererH + RotL64(aIngress, 47U)) + 6163290588946759209U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 27U)) + 7342672468560105447U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 22U)) + 11574563167017282321U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 5U)) + 2254820206194758964U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 1469783447473099498U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 14174828900676165088U;
            aOrbiterK = (aWandererC + RotL64(aCross, 57U)) + 16277954291890598132U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 34U)) + RotL64(aCarry, 19U)) + 14845750668693136766U) + aNonceWordB;
            aOrbiterC = (aWandererI + RotL64(aCross, 39U)) + 150099699692047766U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1200784917165131703U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9469982764806754302U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 17851969334511301943U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10956702761701710182U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7915506894975487807U;
            aOrbiterG = RotL64((aOrbiterG * 8874108311712727983U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17335794183733623213U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 557028996286989506U;
            aOrbiterK = RotL64((aOrbiterK * 3993359298602424281U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1597385667771002414U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4376417959915162639U;
            aOrbiterI = RotL64((aOrbiterI * 4626236858205178149U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 549770198518993876U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 756554555648070919U;
            aOrbiterC = RotL64((aOrbiterC * 16272320259614325355U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7298557532533152193U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3336802611342112013U;
            aOrbiterJ = RotL64((aOrbiterJ * 14679103452120080499U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2314938232094714365U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12215066333571149153U;
            aOrbiterA = RotL64((aOrbiterA * 10747052773052630601U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7762752719356805046U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6519429915769040078U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15548676502167938513U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 7556691736109752918U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 13731245903412646404U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15581965016668635409U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererH = aWandererH + (((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterB, 53U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterI, 34U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 39U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterC, 60U)) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneD
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18006U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 21974U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 24289U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18158U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23119U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 23097U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 3448371607470865612U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 48U)) + RotL64(aCarry, 11U)) + 3743742913651580573U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 23U)) + 13069491287948807280U) + aNonceWordE;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 57U)) + 16872779275586545632U) + aNonceWordC;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 19U)) + 17945792656755062795U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aCross, 53U)) + 18199747196793731853U) + aNonceWordH;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 43U)) + 15953311878379809513U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 43U)) + 941268763494588338U) + aNonceWordK;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 27U)) + 10090221530365796809U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8335698093307607001U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6147498804734306100U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 6904444049941211327U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5980246079567570090U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4152167624425912978U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10019421651535123573U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14990418790239735916U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3418668387496597219U;
            aOrbiterK = RotL64((aOrbiterK * 12814077238529863119U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4206650904177199425U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3905470780938996069U;
            aOrbiterJ = RotL64((aOrbiterJ * 16030122739273137005U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9968672788233080924U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 602258075661864866U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2615726693066300065U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17751667243048041383U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2414054413585296027U;
            aOrbiterD = RotL64((aOrbiterD * 1049512574773201893U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6523322402744047752U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6729901917767398779U;
            aOrbiterA = RotL64((aOrbiterA * 8039939871405367139U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11460169185076814539U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7559640379553110573U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 9864654321914036135U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17271150091827475028U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3541809324556914646U;
            aOrbiterH = RotL64((aOrbiterH * 12655168871428868639U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterI, 4U)) + aOrbiterC) + aNonceWordL) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterA, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterA, 39U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 14U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 18U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28635U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 27700U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24636U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26107U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26397U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 27878U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 52U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererE + RotL64(aIngress, 44U)) + RotL64(aCarry, 29U)) + 18087125778766689269U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 13710545066503235196U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 57U)) + 1701939704736254645U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 8064093611384019909U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 53U)) + 16623332751533885431U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 35U)) + 15590129153794910109U) + aNonceWordN;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 39U)) + 7413312683079107383U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 10U)) + 4186064478651458810U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aWandererI + RotL64(aIngress, 19U)) + 5501191643940735954U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11064645242200570835U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13825922087298055833U;
            aOrbiterF = RotL64((aOrbiterF * 7529317892716108867U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5944980709887369970U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8181136916070569646U;
            aOrbiterK = RotL64((aOrbiterK * 395183021205661827U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15442336949157292482U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11580554435240641337U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6654637892858767739U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11240018128174598322U) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2027565596050777471U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 18048186560314431815U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16425887196883725233U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16828683527588834095U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17746289103235902485U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9923829146479008804U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6669171007279929454U;
            aOrbiterB = RotL64((aOrbiterB * 681823450939955099U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 3902430046523165149U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6739998149289590041U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 2675037435528416821U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16014401255534234075U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14741857638680634564U;
            aOrbiterH = RotL64((aOrbiterH * 8723611021403369393U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5064807861673260054U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 968747317273200299U;
            aOrbiterA = RotL64((aOrbiterA * 14122304002722582329U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 36U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterG, 4U)) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterA, 51U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 23U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 56U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aCross, 20U) + aOrbiterK) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Archery_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC3243FE82F2835E5ULL + 0xDB094FBAC6FD3121ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x844EE02AF27F2AA9ULL + 0xF12D2979075EBECCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF7860E247F381325ULL + 0xA2E8EA9D13F3F8FDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA13D36CE4B74E6C1ULL + 0xB37C7F9ADAD5621CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBABD7792ABF6F297ULL + 0x904D6AA618738803ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCF83EA9C9A8A61D1ULL + 0xAE700CA260C57F3EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBF25D94BFDB45EBBULL + 0x9D31BF1C9148F7CFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEF53D1E3637ECDDDULL + 0xF0D4F641F6C74BD3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD81119579513A0CFULL + 0x82C13D3B66601E35ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC6CE31B137FCB64BULL + 0x8BAAACC586B41719ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE06952DA1F4D4DA1ULL + 0xBDC9639642471C2FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE873F61B21D0DE2FULL + 0x866E4579EAC24F46ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCEFA45EFAB389EFBULL + 0xA281C9234FF1B71CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x932B5E6DD4499EC3ULL + 0xE20C7C47EFE7C1C6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAB47EA867F8052D5ULL + 0xFF36F1FC97EC36CDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDA161A846E8A492FULL + 0xB0976607F42F1345ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneA, aExpandLaneA, aFireLaneC, aFireLaneD, aExpandLaneB, aFireLaneA, aOperationLaneC, aExpandLaneC, aOperationLaneD, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5123U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 6238U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 6668U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4885U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6539U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 877U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = (aWandererG + RotL64(aScatter, 53U)) + 12775735908960052604U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 11791373812080296887U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 5537362877706057303U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 3U)) + 2023912048504189380U) + aNonceWordJ;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 43U)) + 17668828109963766893U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aCross, 30U)) + RotL64(aCarry, 27U)) + 558908629933941224U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aScatter, 37U)) + 1479633119685446888U) + aNonceWordC;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15460320397843364063U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 10059749397555469054U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8671817118586065469U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9987633811929693924U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10087337844580228269U;
            aOrbiterH = RotL64((aOrbiterH * 13817142288940843815U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4446204415503364254U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15106063243302192717U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 13273756657334709803U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9430197906134676162U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 1226048679997253363U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 14247538885252664127U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10611580584157624739U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3137391249289641509U;
            aOrbiterC = RotL64((aOrbiterC * 5462682413239873181U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9327201928815412810U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7890659377013147073U;
            aOrbiterG = RotL64((aOrbiterG * 13827717178378062047U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10675114832750356941U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8804440385852327267U;
            aOrbiterD = RotL64((aOrbiterD * 8520671775587260601U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 11U)) + aOrbiterH) + aNonceWordD);
            aWandererI = aWandererI + (((((RotL64(aCross, 13U) + RotL64(aOrbiterG, 23U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordO) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + aNonceWordN);
            aWandererE = aWandererE + ((((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 41U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererI, 34U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8383U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 11779U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 16214U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9512U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16359U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12112U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 47U)) ^ (RotL64(aCarry, 4U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 11039986441331892533U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 50U)) + RotL64(aCarry, 5U)) + 6256024955965426119U) + aNonceWordH;
            aOrbiterK = (aWandererA + RotL64(aScatter, 35U)) + 9857443189988995666U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 21U)) + 11900944813380998208U) + aNonceWordM;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 8422577734978875541U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 57U)) + 3100835100713928724U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 3U)) + 11871553509810206993U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17614749493763417027U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3638372131856199916U;
            aOrbiterK = RotL64((aOrbiterK * 480683274898147025U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6582275259281025770U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17016882418498941958U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4269869255230867823U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1747214688658984715U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9356088987044015278U;
            aOrbiterF = RotL64((aOrbiterF * 16221733545319753695U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4056238112133473456U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16013150119949532998U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 12913648646318115315U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16076621211111834889U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9940824359571581765U;
            aOrbiterB = RotL64((aOrbiterB * 11624767861336495331U), 13U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 15624084004784515753U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7630989544834680335U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12261063237156822067U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18003586430673313786U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 1654118743290334161U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1153250137357176071U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 5U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterE, 12U));
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 41U)) + aOrbiterF);
            aWandererH = aWandererH + (((((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 57U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 12U) + aOrbiterA) + RotL64(aOrbiterK, 57U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21523U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 23580U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18148U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20207U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17333U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18281U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (aWandererI + RotL64(aCross, 29U)) + 7075016829833562104U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 8783765886115517036U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aIngress, 41U)) + 2996723892384565829U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 21U)) + 9494134707342189476U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 5052642981395679904U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 35U)) + 8766787055127962238U) + aNonceWordB;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 12U)) + RotL64(aCarry, 13U)) + 4467211954388738079U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8030255604633658608U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16962408063455702251U;
            aOrbiterC = RotL64((aOrbiterC * 11171737929747471631U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3768222186567699076U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14930990410207899871U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 10930005786146268241U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14179761938395502502U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1879084742719898108U;
            aOrbiterF = RotL64((aOrbiterF * 16783034788172670121U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5535012408925981515U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12792553516710295939U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8577530993755159329U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8979253163346099252U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5559189896063990740U;
            aOrbiterH = RotL64((aOrbiterH * 8832485423727331621U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13937564337299044079U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2393376759689394948U;
            aOrbiterG = RotL64((aOrbiterG * 2352815657830413941U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12647519563697356479U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10946871249960389549U;
            aOrbiterI = RotL64((aOrbiterI * 6272580371881237173U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 11U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 20U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterF, 29U)) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterC, 35U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31006U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 27354U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 31196U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32022U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31675U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26853U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (aWandererB + RotL64(aScatter, 53U)) + 898812731947995389U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 20U)) + RotL64(aCarry, 51U)) + 8677347622525527167U;
            aOrbiterA = ((((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 770321564027567654U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 37U)) + 11020474858081526395U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 47U)) + 17289793580414993470U) + aNonceWordI;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 10111912559295118444U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 5U)) + 8083622125544542011U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7149858558922988240U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5919683821379905699U;
            aOrbiterA = RotL64((aOrbiterA * 16705119888884231567U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6860902846079238714U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15083517836867542075U;
            aOrbiterD = RotL64((aOrbiterD * 4686657139237578325U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14852868368708376381U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9860233289028878323U;
            aOrbiterC = RotL64((aOrbiterC * 13418143547952204667U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 772406119079116272U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7971141501337627589U;
            aOrbiterK = RotL64((aOrbiterK * 10168120622976358617U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8478568022896691911U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4027604850785607101U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4826627523578901467U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17199331557841535430U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7515957656979776361U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5468950152869656599U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17138249294921502391U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16236812863923234668U;
            aOrbiterG = RotL64((aOrbiterG * 2925542836624164807U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 10U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterA, 21U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 22U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Archery_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9088C14F3BF3B97FULL + 0xD7E26B0B6890ACB6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8AA638D8F6198CA3ULL + 0xEA616E3E6268F0DCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x95D16E9BC2D0FB51ULL + 0xAAFDE4E565DAA421ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9D062C3FF52D64CDULL + 0xCBAB7D348528019CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x88A3F0740B3E7299ULL + 0x908A997837426072ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFEA186CC9E38979FULL + 0xD2C7AD8D89A529B1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x93E1466533C8F153ULL + 0xA367DC22FC2F764AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE7FCBAA61E9C5695ULL + 0xF3875359D1253EAEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBF6B71C94B62A025ULL + 0xEA3816D95BBFAA82ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD6EE4FC669B356E5ULL + 0xF4CFD7DD30522EC1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA6BA2569EE9AC23FULL + 0xFB0C352D41E90B32ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE9188674E7CE2E0DULL + 0xB9E678A0F620F6A4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD3AD40DD02EE9D0FULL + 0xC4A200E7B8347466ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE4EB239F8C512547ULL + 0xF79D919E6CC957C2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBDED24F6734CF2EFULL + 0xB5A6CEEA611A1289ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8718AAAFD6F8EB1FULL + 0xA634D4FF3A9A964EULL);
    // GSeedRunSeed_A seed_loop_a (start)
    {
        // GSeedRunSeed_A seed_loop_a lane group
        // read from: aKeyRowReadA, aKeyRowReadB, mSource, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_a loop 1
        // ingress from: aKeyRowReadA, aKeyRowReadB
        // ingress directions: aKeyRowReadA forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource
        // cross directions: aKeyRowReadA backward forced, mSource backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1001U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[((aIndex + 1976U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1964U)) & W_KEY1], 39U) ^ RotL64(mSource[((aIndex + 2647U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 42U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 7790166497945719700U) + aNonceWordO;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 22U)) + 7136208896846119188U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 12123156943355100886U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 5095546037880875199U) + aNonceWordB;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 5U)) + 17642705393916765992U) + aNonceWordM;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 29U)) + 9918479837334416990U) + aNonceWordG;
            aOrbiterK = (aWandererG + RotL64(aCross, 47U)) + 4890009823843176466U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17652590786213674124U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 870002527644696135U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 915408393979165539U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12545429703552643682U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5310272867406182581U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 10420003334833925011U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3264719049050179440U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1967241238180278937U;
            aOrbiterK = RotL64((aOrbiterK * 13004319774269457957U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 773883832927040736U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12766817190261232485U;
            aOrbiterD = RotL64((aOrbiterD * 7448864556802318431U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 260069382395598265U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15462103891287350123U;
            aOrbiterC = RotL64((aOrbiterC * 5029268763635635753U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4072032867513289827U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 17153061419083897076U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11934532169271718913U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6207264270332656966U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 18048064697837314947U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13632594619404208489U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 12U) + RotL64(aOrbiterF, 53U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 27U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterH, 21U)) + aOrbiterC) + aNonceWordJ) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterF) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 6U)) + aOrbiterD) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aWorkLaneA, aKeyRowReadA
        // ingress directions: aWorkLaneA forward forced, aKeyRowReadA forward/backward random
        // cross from: aKeyRowReadB, mSource
        // cross directions: aKeyRowReadB backward forced, mSource backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 4935U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 4935U)) & W_KEY1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3999U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3412U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (aWandererJ + RotL64(aScatter, 3U)) + 5295352595333316211U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 2341795367042042605U) + aNonceWordE;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 41U)) + 10122175780504033663U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 11U)) + 10084612804696198554U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 19U)) + 16470424309851045971U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 656016130975227994U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 56U)) + RotL64(aCarry, 37U)) + 15313268829659834317U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 3795220914993923394U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14044442220988813825U;
            aOrbiterJ = RotL64((aOrbiterJ * 3270650852546606835U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3804224626734584802U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7980006306010255693U;
            aOrbiterA = RotL64((aOrbiterA * 13958505239726088561U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 13746830564584711549U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11852212099729274845U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 2164880979318247855U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9083223471018084847U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 13706723820703853346U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 11361854103656219887U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1713819986642275223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1382000168233902914U;
            aOrbiterG = RotL64((aOrbiterG * 3894160765130198157U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4540474625764565485U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1756168174375757220U;
            aOrbiterI = RotL64((aOrbiterI * 12739160208010092017U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1409297070183609309U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6082750101445444357U;
            aOrbiterE = RotL64((aOrbiterE * 17438740230251860935U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterF, 4U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + aNonceWordA) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 52U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + aNonceWordB) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aWorkLaneB, aKeyRowReadB
        // ingress directions: aWorkLaneB forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource, aWorkLaneA
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aWorkLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneB[((aIndex + 6596U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 5676U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5804U)) & W_KEY1], 56U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7769U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6895U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 48U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 8793908991006073956U) + aNonceWordP;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 53U)) + 2932916283348441943U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 19U)) + 11069042087940968262U) + aNonceWordO;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 37U)) + 14369628676782894441U) + aPhaseEOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 60U)) + 8602903272780978282U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 3827036107178568820U) + aNonceWordA;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 8905245209036772489U) + aNonceWordB;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13331387530760017893U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9880107580289737823U;
            aOrbiterE = RotL64((aOrbiterE * 10302652857542703753U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10199619040626900278U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2466307560891374281U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6295342978834217571U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13973403407981259448U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2851460278409385243U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11226902976321781743U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10365453393815690776U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2382382358987358791U;
            aOrbiterB = RotL64((aOrbiterB * 481563628980705781U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5058198848163792422U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10500434740387593487U;
            aOrbiterK = RotL64((aOrbiterK * 5946747708776079787U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11289798395177667084U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14327152153231286666U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18155778059595245561U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8065137263811956313U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3865153574847924816U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9495741102667755161U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterC, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 21U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterA, 53U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterA, 47U)) + aNonceWordG);
            aWandererG = aWandererG + ((((RotL64(aCross, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aWorkLaneC, aKeyRowReadB, mSource, aWorkLaneA
        // ingress directions: aWorkLaneC forward forced, aKeyRowReadB forward forced, mSource forward forced, aWorkLaneA forward/backward random
        // cross from: aKeyRowReadA, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, aWorkLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9131U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 9675U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 10390U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 10183U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9888U)) & W_KEY1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9522U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 44U) ^ RotL64(aPrevious, 29U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 1297415699043177788U) + aNonceWordM;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 37U)) + 17583786534509260153U) + aNonceWordF;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 5U)) + 643197858925708798U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 5062653766915694874U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 13U)) + 7034273638367180511U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 19U)) + 2026909726972916996U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 60U)) + 2785690475553211646U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2910341716302991892U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2834181605200829791U;
            aOrbiterJ = RotL64((aOrbiterJ * 1510617068750957651U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13323052600571281928U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10434901530315760460U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2042210188346767033U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 247903955625194782U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5196515747387257163U;
            aOrbiterI = RotL64((aOrbiterI * 1799024689023272275U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 7196305682377987476U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14777739876892587484U;
            aOrbiterD = RotL64((aOrbiterD * 95220583948241581U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10609060796540136671U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8386027207212484155U;
            aOrbiterA = RotL64((aOrbiterA * 4855610536246556893U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 729659744301903424U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2350564261412606157U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 16713856782349084977U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16611987556673864177U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1525195188708550503U;
            aOrbiterC = RotL64((aOrbiterC * 10045858602151004553U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 27U)) + aNonceWordC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 21U));
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterF, 13U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterE, 46U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + aNonceWordK) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 27U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // ingress from: aWorkLaneD, aKeyRowReadA, aKeyRowReadB, mSource, aWorkLaneB
        // ingress directions: aWorkLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, mSource forward forced, aWorkLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneC backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11038U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 13275U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11665U)) & W_KEY1], 27U) ^ RotL64(mSource[((aIndex + 11803U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13516U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11086U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 12641U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 20U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 41U)) + 16016931609704150191U) + aNonceWordK;
            aOrbiterH = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 14511433515861302636U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 19U)) + 11691237442613269593U) + aPhaseFOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 16383220587320484649U) + aPhaseFOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 11U)) + 14293015313458219868U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 56U)) + RotL64(aCarry, 3U)) + 4407695248205526670U) + aNonceWordB;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 27U)) + 1158323195324398372U) + aNonceWordC;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6577683409653864555U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 171080079472863843U;
            aOrbiterJ = RotL64((aOrbiterJ * 3063978974927752653U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5766333425872228205U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16173508656917582960U;
            aOrbiterH = RotL64((aOrbiterH * 12187968015372936695U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11781450063402219202U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13033139686637576694U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 4331137994135472025U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4006310759400926020U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 13156817947481574467U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 563189239835001483U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12791290558893516411U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 989729955679243234U;
            aOrbiterF = RotL64((aOrbiterF * 8757228712495095017U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 838379839663022790U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2830743864262313606U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10173947177104802797U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 2146646527331684652U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4629168181742174906U;
            aOrbiterG = RotL64((aOrbiterG * 9046124907945045131U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 46U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aNonceWordP);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterF, 3U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 12U)) + aOrbiterG) + aNonceWordO);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 43U)) + aNonceWordE) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterH, 37U)) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // ingress from: aFireLaneA, aWorkLaneC
        // ingress directions: aFireLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, mSource, aWorkLaneB, aWorkLaneA
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, mSource backward forced, aWorkLaneB backward forced, aWorkLaneA backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 16202U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16375U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15898U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14186U)) & W_KEY1], 29U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15706U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14947U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14467U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 52U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 6361545377408870615U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 29U)) + 2967245486744774933U) + aNonceWordF;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 50U)) + 3836634268482850139U) + aPhaseFOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 7691642115360086297U;
            aOrbiterD = ((((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 16479280384178279281U) + aPhaseFOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererJ + RotL64(aCross, 57U)) + 2901468732552539249U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 35U)) + 2600353867755647475U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 5666596904781510956U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16108791609267427553U;
            aOrbiterF = RotL64((aOrbiterF * 8904649663479834199U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8389926875737312112U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1689501721163024426U;
            aOrbiterB = RotL64((aOrbiterB * 6517194895779049139U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11721701506949917719U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 3963842745030140473U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 6692473494944919373U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8510538243472109368U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 18281865214102080387U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1351546966368884609U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2259725140963665123U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11652011949557979650U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 11260100762113295037U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 1116085424226174473U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4725260319270802912U;
            aOrbiterG = RotL64((aOrbiterG * 4697109059565450269U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7348945429843437036U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1249234309180653260U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3136745255820405881U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 14U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterK, 10U));
            aWandererE = aWandererE + ((RotL64(aCross, 14U) + RotL64(aOrbiterB, 29U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + aNonceWordI);
            aWandererC = aWandererC + (((((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 37U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordA) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 7
        // ingress from: aFireLaneB, aKeyRowReadA, mSource, aWorkLaneA
        // ingress directions: aFireLaneB forward forced, aKeyRowReadA forward forced, mSource forward forced, aWorkLaneA forward/backward random
        // cross from: aKeyRowReadB, aWorkLaneD, aFireLaneA
        // cross directions: aKeyRowReadB backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 17017U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 17778U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 17498U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16961U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18344U)) & W_KEY1], 24U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18954U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18340U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 38U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 9774364261626083532U) + aNonceWordH;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 51U)) + 18059001521926116420U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 58U)) + 10615626210406381148U) + aPhaseGOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 10536484278007898620U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 5U)) + 13320663045139972700U) + aPhaseGOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 17127001787268166583U;
            aOrbiterA = (aWandererF + RotL64(aCross, 23U)) + 16742574590844166551U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8347719720758228053U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13502468705946051986U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 13822952083584784695U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3512687886188904904U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 495660316165795934U;
            aOrbiterD = RotL64((aOrbiterD * 6724596801190194913U), 51U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 5092722552034477356U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 15641128019608284015U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3621036395703527059U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15421873776811085458U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17978775513204574125U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18359600395119440183U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16617179197537669849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1931805387534012528U;
            aOrbiterA = RotL64((aOrbiterA * 3400139345857733775U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9544923119559308431U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12930999400470173353U;
            aOrbiterB = RotL64((aOrbiterB * 16791006919271490005U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13673733276226249890U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2032263473309124738U;
            aOrbiterH = RotL64((aOrbiterH * 3088728329261360607U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 26U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordM) + aPhaseGWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterD, 43U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterF, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 38U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + aNonceWordE) + aPhaseGWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 8
        // ingress from: aFireLaneC, mSource, aFireLaneA, aWorkLaneA
        // ingress directions: aFireLaneC forward forced, mSource forward forced, aFireLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, aFireLaneB, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, aFireLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 21229U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 21195U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19284U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 20660U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20846U)) & W_KEY1], 40U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20968U)) & W_KEY1], 29U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21643U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 19557U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 28U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (aWandererJ + RotL64(aScatter, 37U)) + 2617613537256538553U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 57U)) + 16642868916835132715U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 10860291124337073254U;
            aOrbiterE = ((((aWandererK + RotL64(aPrevious, 28U)) + RotL64(aCarry, 51U)) + 6432511273906902472U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 7505375005848241910U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 5U)) + 11086616004678821329U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 51U)) + 3298830587569881951U) + aPhaseGOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9775143140064220979U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 4147601326580823120U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13462244678782260871U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12245920269898100415U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8391940489176734499U;
            aOrbiterJ = RotL64((aOrbiterJ * 9119606167674098007U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17876893379544668477U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18301882058180370541U;
            aOrbiterD = RotL64((aOrbiterD * 16680384667098921309U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6869225862715140102U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15404118372589259800U;
            aOrbiterB = RotL64((aOrbiterB * 5766851935950389915U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17757381020518233814U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17677969146092374455U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 3469432916562405063U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15783378556632870114U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5792858258663697864U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 12008981883482080427U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11737803388202260296U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16001927091970715330U;
            aOrbiterG = RotL64((aOrbiterG * 3062030309852922061U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 22U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 35U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aCross, 29U) + RotL64(aOrbiterC, 41U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterE, 57U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 14U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + aNonceWordI) + aPhaseGWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 9
        // ingress from: aFireLaneD, aKeyRowReadA, aKeyRowReadB, aFireLaneC
        // ingress directions: aFireLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, aFireLaneC forward/backward random
        // cross from: mSource, aFireLaneA, aWorkLaneC, aWorkLaneD
        // cross directions: mSource backward forced, aFireLaneA backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 23577U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 22654U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23425U)) & W_KEY1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23418U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23762U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23538U)) & S_BLOCK1], 42U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23576U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23745U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCross, 3U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (aWandererE + RotL64(aCross, 53U)) + 9888431329297626900U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 2937735167534624403U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 27U)) + 17626022970343789617U) + aNonceWordP;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 44U)) + 5665660859333693743U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 1060537034632076669U) + aNonceWordG;
            aOrbiterC = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 743777763907175800U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 3U)) + 5744905970181808845U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3545351394494002180U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4877547088414106007U;
            aOrbiterF = RotL64((aOrbiterF * 5416792889338547109U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11669378338379598445U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2961072441706158212U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 2677988507090705371U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13984945589234919765U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1433097875470903205U;
            aOrbiterC = RotL64((aOrbiterC * 451996840039906781U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 716415411025451152U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8542286150858297810U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9139015340823332449U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12932391786479661299U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14005503313299177013U;
            aOrbiterG = RotL64((aOrbiterG * 802663466907819743U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9382792812676318046U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5138554251079724724U;
            aOrbiterD = RotL64((aOrbiterD * 6386016499265056247U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8522380066269546172U) + aNonceWordF;
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 11825536408101906458U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 17042837108792016849U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterG, 37U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + aNonceWordO) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 21U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aScatter, 54U) + aOrbiterC) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 30U)) + aOrbiterF);
            aWandererC = aWandererC + (((((RotL64(aCross, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aNonceWordB) + aPhaseGWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 40U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 10
        // ingress from: aExpandLaneA, aKeyRowReadA, aFireLaneD, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aKeyRowReadA forward forced, aFireLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aKeyRowReadB, mSource, aFireLaneC, aWorkLaneD
        // cross directions: aKeyRowReadB backward forced, mSource backward forced, aFireLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25863U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 25554U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26373U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneB[((aIndex + 26138U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24951U)) & W_KEY1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24979U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27091U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25505U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 52U)) + (RotL64(aCross, 27U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (aWandererF + RotL64(aScatter, 47U)) + 3236820517816085022U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 57U)) + 741288875914097926U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 21U)) + 8417246926007729580U) + aNonceWordO;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 13U)) + 9715717805774537170U) + aNonceWordE;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 30U)) + RotL64(aCarry, 35U)) + 14360243844821619482U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 10760908100206775334U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 3434641779946167811U) + aNonceWordI;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7885568822756234567U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3041563437672051294U;
            aOrbiterF = RotL64((aOrbiterF * 11440300917533482297U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15761355327564963516U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1158633562785937421U;
            aOrbiterH = RotL64((aOrbiterH * 15511324886867188235U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9338581575871970653U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9172038894262857354U;
            aOrbiterG = RotL64((aOrbiterG * 3110871165285625807U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14653924713599790081U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3854497592598563309U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 11737111068815795303U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 16286980180327600557U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5092583772591249756U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13955105624639442903U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4288397994175567333U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15584236478994873104U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1860480595862755379U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5557463939827483792U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2659814275753280856U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 17702430405693184643U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 12U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + aNonceWordH);
            aWandererF = aWandererF + ((((RotL64(aScatter, 4U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 41U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 41U)) + aOrbiterK) + aPhaseHWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterE, 58U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 11
        // ingress from: aExpandLaneB, aFireLaneD, aKeyRowReadB, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aFireLaneD forward forced, aKeyRowReadB forward forced, aFireLaneC forward/backward random
        // cross from: aKeyRowReadA, mSource, aExpandLaneA, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aExpandLaneA backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27330U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 27481U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29239U)) & W_KEY1], 13U) ^ RotL64(aFireLaneC[((aIndex + 27412U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28310U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28821U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29282U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28695U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 3U)) + 9654059367478508868U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererD + RotL64(aCross, 34U)) + 6473006635864677427U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 51U)) + 6944184481315853243U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 4061496421939102306U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 15791809275719085463U) + aNonceWordE;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 14050798802646323055U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 27U)) + 12072905924741758266U) + aNonceWordG;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17639076509231343896U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12195388285571234715U;
            aOrbiterD = RotL64((aOrbiterD * 4317060502521195769U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4325404419499496529U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5910567888204238382U;
            aOrbiterK = RotL64((aOrbiterK * 11503787177122206937U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13092940059929942699U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 13381962590820308761U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6345904465930943295U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15622862439323440527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14027151901132249793U;
            aOrbiterC = RotL64((aOrbiterC * 2273573821630510087U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4584410023907605157U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 15763755180625487157U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 6755736130607297639U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17023059745666559199U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5298529579288492971U;
            aOrbiterA = RotL64((aOrbiterA * 2483562793328357721U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2870152867331654736U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12017191100173748848U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9958191466506480519U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 50U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + aNonceWordH) + aPhaseHWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 56U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 60U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 29U)) + aOrbiterG) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 12
        // ingress from: aExpandLaneC, aKeyRowReadA
        // ingress directions: aExpandLaneC forward forced, aKeyRowReadA forward/backward random
        // cross from: aFireLaneD, aExpandLaneA, aExpandLaneB, aKeyRowReadB
        // cross directions: aFireLaneD backward forced, aExpandLaneA backward forced, aExpandLaneB backward forced, aKeyRowReadB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 32246U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30206U)) & W_KEY1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31689U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32015U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30138U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32167U)) & W_KEY1], 18U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (((aWandererE + RotL64(aIngress, 21U)) + 9855743441035905047U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 8426286937143990276U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 7146752367170267002U) + aNonceWordP;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 27U)) + 12947210066678101726U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 5U)) + 15902163559925328965U) + aPhaseHOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 12U)) + RotL64(aCarry, 5U)) + 8506649889346449469U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 57U)) + 8226286036430263052U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2703047093452420216U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6769351326360139560U;
            aOrbiterG = RotL64((aOrbiterG * 5318104980014706265U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9857025533281333281U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 238297452132277585U;
            aOrbiterH = RotL64((aOrbiterH * 12974709749856065985U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7203572312072908931U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12497027346166575632U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1703586436725662307U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 473851890609048879U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1664484956453886047U;
            aOrbiterB = RotL64((aOrbiterB * 8566500756326590209U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4635095143004754116U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17695676150967345793U;
            aOrbiterF = RotL64((aOrbiterF * 5780416541584439301U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15628965269863402796U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9190117464399730235U;
            aOrbiterD = RotL64((aOrbiterD * 5586437438425999715U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17835918238346011086U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 4398005402429282682U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 14828737209913317463U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 43U)) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 21U)) + aOrbiterH) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 51U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + aNonceWordO) + aPhaseHWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterG, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterB, 60U)) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aCross, 12U) + aOrbiterF) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Archery_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCF9DADE06A3D8BE3ULL + 0xEED2758B24340F15ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC800BBCF8AE483D1ULL + 0xBCBAD97098CD8679ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF59ADCC459D1CA91ULL + 0x95F8615DC8050D48ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x951A71C0F8B7CE73ULL + 0xAC4BBC052C6A9210ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8D5FDDCF6DB1C86FULL + 0xB65B61E0078F29C2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x95651D7F476ECB03ULL + 0xCB0E31B4C6A330C5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC007D0B87517974BULL + 0xD601B6961020ACE8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9289F955CE272C9DULL + 0x8CCE0E3AF3A2C567ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB99F3D08AC533E51ULL + 0xA6109BAB606FA1D8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA8BF484E8220708FULL + 0xBC7F488A1BBE33A9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x818FF8C2DD48E1ADULL + 0xE6E604693CF309BCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8F833A97557A1743ULL + 0xC879EC3252A476E0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB03EB29E4020EA3DULL + 0xE7284A8F3DC32B4CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE2B4989CEB189AC5ULL + 0xADD42E4B435DD9FBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA7FB841B2B10E5D1ULL + 0xB90D3F11780329C9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBBEC152A26F7C783ULL + 0x84DBAEEF64D4F62DULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneD, aInvestLaneB, aFireLaneB, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4077U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 3545U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1150U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4744U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 1261U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 26U)) + (RotL64(aCarry, 53U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 3973833383430652211U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 11U)) + 5760227042747169187U) + aPhaseAOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 54U)) + RotL64(aCarry, 21U)) + 4923009065139227286U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 1477807307009107590U) + aNonceWordA;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 43U)) + 5707194514329007301U) + aNonceWordP;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5340439728375269724U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17080457898946572387U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17719588880215414933U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 281559150259472813U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16160633048230910560U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 16883442583309073785U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9003989610509592121U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10579322462808454333U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 100832431598087235U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15059383289528723069U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10417647757852880956U;
            aOrbiterI = RotL64((aOrbiterI * 1457919230286043137U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14484665027393813330U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12344463053485837974U;
            aOrbiterG = RotL64((aOrbiterG * 5762654194001525041U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererB = aWandererB + ((((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterE) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneD
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5495U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 7345U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9406U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9359U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 7454U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 13650869943246163567U) + aNonceWordG;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 11U)) + 3435284932011770999U) + aNonceWordD;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 12388155658186776579U) + aNonceWordF;
            aOrbiterI = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 2374345913955712039U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aIngress, 50U)) + 6095094526980292156U) + aPhaseAOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4965147025852444174U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3261881216269075298U;
            aOrbiterD = RotL64((aOrbiterD * 4874733445914960785U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4939780217097329222U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 3019862009792676287U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 2452316208025448747U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 901910626217143974U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3647055146712366383U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 1792602402476450009U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7731765438957392967U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13409819457393479741U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3345078200262410715U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5415832109107794258U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8876738832313114471U;
            aOrbiterH = RotL64((aOrbiterH * 1304277600444504135U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterE, 40U)) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 56U) + RotL64(aOrbiterI, 53U)) + aOrbiterH) + aNonceWordL) + aPhaseAWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneB
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15164U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 14796U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11264U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12824U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11101U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11106U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = ((aWandererC + RotL64(aScatter, 13U)) + 5906639480605353429U) + aNonceWordF;
            aOrbiterF = ((((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 5293518570213287605U) + aPhaseAOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 52U)) + RotL64(aCarry, 39U)) + 15383185501428521377U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 15364072512743978902U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 3U)) + 4525473357144014271U) + aPhaseAOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10400911938125603074U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16417506293824627550U;
            aOrbiterD = RotL64((aOrbiterD * 8303380456072515611U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2419329331753341815U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14929222427923332069U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11596261802662514979U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16771573504983922586U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1863466450051787622U;
            aOrbiterC = RotL64((aOrbiterC * 2585626547126027053U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12895350137096692415U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3700979086526298327U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 10279730254867618193U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1977099106211282426U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6144698304096915742U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5039822990560519609U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterD, 54U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + aNonceWordC) + aPhaseAWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aNonceWordH) + aPhaseAWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 27U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aCross, 6U) + aOrbiterD) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16856U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((aIndex + 16880U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 21578U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21640U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17074U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 19789U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 11U)) + 17711946802293254150U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (((aWandererA + RotL64(aCross, 35U)) + 16652362590489569378U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 43U)) + 6972810344198183097U) + aNonceWordK;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 13117100889782940546U) + aNonceWordC;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 22U)) + RotL64(aCarry, 57U)) + 13199305696782626591U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 992156184392760945U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13791265442074543880U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 1263919538622722673U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17057087245252294859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13444195995883541046U;
            aOrbiterG = RotL64((aOrbiterG * 13067044288608808777U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6723678233676059420U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7913379431208430475U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2295062944289127123U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4481887195529300665U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11892724101424384078U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 3468639499716604111U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7700902083270424194U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 1888001433557140271U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8975562955027025349U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + aNonceWordD) + aPhaseAWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterE, 4U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterC, 19U)) + aNonceWordA);
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterF, 51U)) + aNonceWordB) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // ingress from: aOperationLaneB, aOperationLaneA, aExpandLaneB
        // ingress directions: aOperationLaneB forward forced, aOperationLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aExpandLaneC, aInvestLaneA, aInvestLaneB
        // cross directions: aExpandLaneC backward forced, aInvestLaneA backward forced, aInvestLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26375U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 21905U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 27175U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26973U)) & S_BLOCK1], 46U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25254U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26037U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 39U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 2571116506511057880U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 13U)) + 13112435411509707292U;
            aOrbiterF = ((((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 10403251762787357256U) + aPhaseAOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 8461951095541400405U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 47U)) + 9890793478557463815U) + aPhaseAOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3030229465991783707U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7273848154043719247U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17562254601517935669U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10681774862516028276U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7105082755586853104U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 12217705329504230357U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 6588579345319551129U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14616333550242386092U;
            aOrbiterC = RotL64((aOrbiterC * 2934574715879306337U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 15439666290229654921U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3360304356760164799U;
            aOrbiterB = RotL64((aOrbiterB * 5164191920584106237U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14438730801970761889U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14515616787452085729U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 2041601927968559821U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 21U)) + aOrbiterH) + aNonceWordL) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterK, 50U)) + aNonceWordM);
            aWandererH = aWandererH + ((((RotL64(aIngress, 36U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + aPhaseAWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 5U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 20U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // ingress from: aOperationLaneC, aExpandLaneA, aExpandLaneB
        // ingress directions: aOperationLaneC forward forced, aExpandLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneB, aOperationLaneA, aInvestLaneB
        // cross directions: aOperationLaneB backward forced, aOperationLaneA backward forced, aInvestLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28254U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 29059U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31349U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31126U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30830U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 31047U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 11U)) + 5568146815535263910U) + aNonceWordN;
            aOrbiterE = ((((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 7736084960873834666U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 41U)) + 1336413621817562093U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 30U)) + RotL64(aCarry, 27U)) + 5218462026934984692U) + aNonceWordP;
            aOrbiterB = ((((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 7048890985969555935U) + aPhaseAOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13415955213864702118U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5657023257021528548U;
            aOrbiterA = RotL64((aOrbiterA * 5200798937081797819U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 14338310943137497116U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12305161641833950473U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11949964304435964395U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14514226578370459131U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12692904083266024340U;
            aOrbiterE = RotL64((aOrbiterE * 14800805065279908839U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11012959130001327964U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 7106471380403489078U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 515626559384817223U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3718101961355280891U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13364192077222322664U;
            aOrbiterF = RotL64((aOrbiterF * 1411328915372590283U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterA, 14U)) + RotL64(aCarry, 51U)) + aNonceWordC) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 23U)) + aOrbiterB) + aNonceWordK) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 12U) + aOrbiterE) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterE, 57U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterB, 39U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererF, 36U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Archery_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF568F35DA79A1F09ULL + 0xEC6CC2CC72B98C3AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x88DC52A48A4B07C3ULL + 0xAF7A2E99B404BBB7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB625D332A1A3AF93ULL + 0xE2AF3113DE4F3F35ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD43E2A4974AA22B5ULL + 0xE57A067B83E4387AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFEA4615DF3B03AF3ULL + 0xE8DA607ECDF8B493ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x91625A26913F41F5ULL + 0xF20B7609460F5E4AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x93CC3E71B3FCB363ULL + 0xEC8E401DC9A7F74CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFA1325CD841C67B1ULL + 0x82576775B117594BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA233112C421A3175ULL + 0x98E72ECDB4667D8AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8082E29707B23343ULL + 0xA8073857A1362CBAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x84A7448E245FCF2FULL + 0xE3250A3AC5AD4127ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x890D75247FC82069ULL + 0xBC7A189E83CA6320ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAA1B02E10E1AE47DULL + 0xF98BA9553945FD88ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE9F0E11E48C4FE09ULL + 0xBE31567B5C43BE41ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCCB9D955903C368DULL + 0xF2B84156C8292A3BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC2F3F36F22B09CD7ULL + 0xBCCBCCBB31A7E7C2ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB, aInvestLaneC, aFireLaneD, aFireLaneA, aInvestLaneD, aFireLaneC, aWorkLaneA, aExpandLaneA, aWorkLaneB, aFireLaneB, aWorkLaneC, aExpandLaneD
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4893U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 1029U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4553U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4798U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 984U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 3492U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 14U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 60U)) + 2974056819475622600U) + aNonceWordB;
            aOrbiterJ = (aWandererI + RotL64(aCross, 41U)) + 7345051759236356098U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 12738468816846628882U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 3U)) + 7694520596043297922U) + aNonceWordN;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 47U)) + 5530753590015084774U) + aNonceWordD;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 19U)) + 3776309161718383105U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 784780304358106404U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 24U)) + RotL64(aCarry, 35U)) + 8999942326995036509U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 29U)) + 5194986506064092779U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 7920040007459652762U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11311997270710107937U;
            aOrbiterD = RotL64((aOrbiterD * 6227571709361790209U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5365231114813547251U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8630110234623825263U;
            aOrbiterB = RotL64((aOrbiterB * 2735881715888325759U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2358235238039571072U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 18059414891616491807U;
            aOrbiterF = RotL64((aOrbiterF * 17150786106857185467U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 14526050556461782864U) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6937282036603272474U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 14954512365270028029U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10105832250694931310U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3884223553012098137U;
            aOrbiterJ = RotL64((aOrbiterJ * 16340956813003906195U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10385284339549648087U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1257633893341505930U;
            aOrbiterA = RotL64((aOrbiterA * 2669950791270500977U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5528890519572824318U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 15664241747527713256U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 16670884497088220497U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14264122979415331887U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17985061405540198036U;
            aOrbiterI = RotL64((aOrbiterI * 2729487440173395133U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1663986734997903415U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3706166884286400587U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10549736618301955745U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 28U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + aPhaseBWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterF, 60U)) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterG, 29U));
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 43U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aIngress, 24U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 24U)) + aNonceWordG) + aPhaseBWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneD
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneA backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 5716U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 6836U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5711U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9451U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8183U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8183U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 10847U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 26U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 3448371607470865612U) + aNonceWordA;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 53U)) + 3743742913651580573U) + aNonceWordJ;
            aOrbiterF = (aWandererE + RotL64(aCross, 57U)) + 13069491287948807280U;
            aOrbiterE = ((((aWandererC + RotL64(aIngress, 34U)) + RotL64(aCarry, 47U)) + 16872779275586545632U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 17945792656755062795U) + aPhaseBOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 13U)) + 18199747196793731853U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 23U)) + 15953311878379809513U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 46U)) + 941268763494588338U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 19U)) + 10090221530365796809U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8335698093307607001U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6147498804734306100U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 6904444049941211327U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5980246079567570090U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4152167624425912978U;
            aOrbiterB = RotL64((aOrbiterB * 10019421651535123573U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14990418790239735916U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3418668387496597219U;
            aOrbiterK = RotL64((aOrbiterK * 12814077238529863119U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4206650904177199425U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3905470780938996069U;
            aOrbiterJ = RotL64((aOrbiterJ * 16030122739273137005U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9968672788233080924U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 602258075661864866U;
            aOrbiterH = RotL64((aOrbiterH * 2615726693066300065U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 17751667243048041383U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2414054413585296027U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 1049512574773201893U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6523322402744047752U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6729901917767398779U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8039939871405367139U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11460169185076814539U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7559640379553110573U;
            aOrbiterI = RotL64((aOrbiterI * 9864654321914036135U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17271150091827475028U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3541809324556914646U;
            aOrbiterE = RotL64((aOrbiterE * 12655168871428868639U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 26U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterH, 41U));
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 46U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterB, 37U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 23U)) + aNonceWordK);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 26U) + RotL64(aOrbiterB, 18U)) + aOrbiterC) + aNonceWordB) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneC
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13735U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 16339U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 14321U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11427U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15656U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 38U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 7896237440058555694U) + aNonceWordH;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 18U)) + RotL64(aCarry, 53U)) + 11870529476037558635U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 23U)) + 9158983227801569448U) + aNonceWordO;
            aOrbiterC = (aWandererH + RotL64(aScatter, 53U)) + 4710172270996950329U;
            aOrbiterB = (aWandererG + RotL64(aCross, 39U)) + 14634482800356647630U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 11U)) + 8822207952170610891U) + aNonceWordM;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 43U)) + 13755891414028982553U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 4555293067488040719U) + aNonceWordG;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 60U)) + 2816805148093762081U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 2122631477965135190U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4592922416380416071U;
            aOrbiterH = RotL64((aOrbiterH * 11644507904538573165U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7102471666524164715U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17274623547879474204U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5443572270546181789U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 938587316977094680U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 18258015823797023523U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6068819567674605919U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5809987756043471595U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5083075160112581620U;
            aOrbiterG = RotL64((aOrbiterG * 3313957222154937503U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5960021727750946496U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5967477320950630150U;
            aOrbiterC = RotL64((aOrbiterC * 330964768256424655U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 6578428711689296132U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5601728218197771276U;
            aOrbiterA = RotL64((aOrbiterA * 9552559022315971847U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7923809409017855241U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16479366540906497019U;
            aOrbiterE = RotL64((aOrbiterE * 7118578387798460919U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17000467091738009736U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6801634573655508028U;
            aOrbiterD = RotL64((aOrbiterD * 10584635770060137089U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 123668445682719574U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14462802805503986316U;
            aOrbiterI = RotL64((aOrbiterI * 12398236364304875941U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterC, 11U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterI, 18U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + aNonceWordF) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 52U) + aOrbiterD) + RotL64(aOrbiterH, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 60U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 6U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aExpandLaneA
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aExpandLaneA forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19024U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneC[((aIndex + 16394U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 21229U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18828U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20125U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 5160910997561396461U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 28U)) + RotL64(aCarry, 57U)) + 14920764751058512062U) + aPhaseBOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 19U)) + 6080952401749660022U) + aNonceWordO;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 17667234330526298627U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 23U)) + 760630072638686756U) + aPhaseBOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 58U)) + 3504157162816997476U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 5U)) + 9489022223422585882U) + aNonceWordP;
            aOrbiterC = (aWandererF + RotL64(aCross, 43U)) + 1149898536879968964U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 11U)) + 10492284328940025310U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13213275606286399312U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10557118912847180413U;
            aOrbiterJ = RotL64((aOrbiterJ * 10077877991284587845U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15618980209023994776U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5268600749854045564U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 3849660559223919613U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8011552687609649990U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3148133096349525066U;
            aOrbiterD = RotL64((aOrbiterD * 5245156554959620007U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12032847944237867285U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14999005703490824673U;
            aOrbiterA = RotL64((aOrbiterA * 6631584955208646049U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5426735969392906710U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 3593177531650386729U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12997284886192717043U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1701444719333347373U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15928731228196894960U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1919318226904213433U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5960179456039157036U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5716434224061596483U;
            aOrbiterK = RotL64((aOrbiterK * 3731976564761202801U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2136841536293340279U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12969550408652728526U;
            aOrbiterG = RotL64((aOrbiterG * 7612191387451455137U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3641997570461447114U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4677572491523684525U;
            aOrbiterC = RotL64((aOrbiterC * 2730358077882211651U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 37U)) + aOrbiterB) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterH, 13U)) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterD, 47U)) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aCross, 26U) + aOrbiterJ) + RotL64(aOrbiterD, 42U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 5U));
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 29U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterD, 24U)) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneB
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24477U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneD[((aIndex + 24365U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26219U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23617U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25404U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 47U)) + (RotL64(aIngress, 60U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (aWandererE + RotL64(aCross, 10U)) + 4980738603982643969U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 29U)) + 17660278413018470020U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 3U)) + 17598114429859543466U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 43U)) + 10993929335279994739U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 17967203122976322481U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 58U)) + 1872290205549034384U) + aPhaseBOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 16607778671782810797U) + aNonceWordJ;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 4895226930754394376U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 19U)) + 14960359005982301383U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9921642352377700630U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 893281964367208693U;
            aOrbiterB = RotL64((aOrbiterB * 2345509157333444217U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8232519988397858732U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4433022122758913407U;
            aOrbiterJ = RotL64((aOrbiterJ * 834240393225479419U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12689609831247168353U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 404535388957472176U;
            aOrbiterG = RotL64((aOrbiterG * 14534020545479806593U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3349108201964013155U) + aNonceWordG;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 4386449511297371730U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 9596273264321140229U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14314587717949070586U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10923886625271054985U;
            aOrbiterC = RotL64((aOrbiterC * 7838969002623486809U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17634909585329833520U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2021301459918350372U;
            aOrbiterD = RotL64((aOrbiterD * 1388242915918642741U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5219599112498224367U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10641339455385046206U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 1022283727595400719U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5003342156562330058U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10951027475628404336U;
            aOrbiterK = RotL64((aOrbiterK * 17836928292555158461U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13040991872592235460U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11149099984302782267U;
            aOrbiterI = RotL64((aOrbiterI * 4248667283139686251U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 10U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 12U) + aOrbiterC) + RotL64(aOrbiterE, 10U)) + aNonceWordM);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + aNonceWordK) + aPhaseBWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterB, 19U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 47U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 5U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aCross, 51U) + RotL64(aOrbiterG, 39U)) + aOrbiterD) + aNonceWordC) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterH, 56U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31378U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 31343U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29041U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31040U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((aIndex + 31553U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCarry, 39U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (aWandererB + RotL64(aCross, 47U)) + 9654059367478508868U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 6473006635864677427U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 6944184481315853243U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 52U)) + 4061496421939102306U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 23U)) + 15791809275719085463U) + aPhaseBOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aCross, 57U)) + 14050798802646323055U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 5U)) + 12072905924741758266U) + aNonceWordD;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 41U)) + 17639076509231343896U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 10U)) + RotL64(aCarry, 47U)) + 12195388285571234715U) + aNonceWordL;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4325404419499496529U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5910567888204238382U;
            aOrbiterE = RotL64((aOrbiterE * 11503787177122206937U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13092940059929942699U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13381962590820308761U;
            aOrbiterJ = RotL64((aOrbiterJ * 6345904465930943295U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15622862439323440527U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14027151901132249793U;
            aOrbiterC = RotL64((aOrbiterC * 2273573821630510087U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4584410023907605157U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15763755180625487157U;
            aOrbiterH = RotL64((aOrbiterH * 6755736130607297639U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17023059745666559199U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5298529579288492971U;
            aOrbiterA = RotL64((aOrbiterA * 2483562793328357721U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2870152867331654736U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12017191100173748848U;
            aOrbiterK = RotL64((aOrbiterK * 9958191466506480519U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15899529176182436062U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16482713846343388735U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 719465695044265601U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12943393531812774449U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9881108254540483225U;
            aOrbiterD = RotL64((aOrbiterD * 8011108108007885059U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3532054586199716750U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7142230313294797435U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14154176174768868421U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 22U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 21U)) + aOrbiterF) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterF, 60U));
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 24U) + aOrbiterK) + RotL64(aOrbiterB, 43U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 47U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 39U));
            aWandererG = aWandererG + ((((RotL64(aCross, 4U) + RotL64(aOrbiterE, 12U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Archery_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD078EDA3BBFA2B0BULL + 0xF873205B619EC86FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAD0B990709EE8C83ULL + 0xAC3EA236719F2DABULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBCA1A344BD175C1FULL + 0xA3712D0C7E785625ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x891EA1C87290660DULL + 0xDBF3C77D82E97893ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD03133605A3E2CA1ULL + 0xD747F0AFC4D0AC8DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x86DD0F9AC3D3AB39ULL + 0xEE484B86AD20E97FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA10ED2FC86DADC33ULL + 0xB89FB925971DB5FAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFDA103B984595395ULL + 0x95D92F6375661152ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8145ED1AF8BFA143ULL + 0xF504C575115EFF7CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xED97404B22B0E80FULL + 0xF7718B7BB97B445DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xED2407F897B0D1DFULL + 0xEF4640B7FF4A6A3AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC01AD0B6E047775FULL + 0xF5DF23877A4F6BB0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFF94CD04CD424A8DULL + 0xAA1BB667418C1D0DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAD58FB87619B754BULL + 0xBE5F1C3DB1F5807CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAD4B3EF45D9AA261ULL + 0xBB9F7465A7A51E74ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC02DC7D11F22ACADULL + 0xFCC8CCBC66DF0542ULL);
    // GSeedRunSeed_D seed_loop_d (start)
    {
        // GSeedRunSeed_D seed_loop_d lane group
        // read from: aExpandLaneA, aExpandLaneB, aInvestLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneB, aSnowLaneA, aInvestLaneC, aInvestLaneD, aSnowLaneB, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD
        // write to: aSnowLaneA, aSnowLaneB, aInvestLaneA, aInvestLaneB, aInvestLaneC, aInvestLaneD
    
        // seed_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aInvestLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3901U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 4083U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 429U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3380U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1622U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 4766U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 2101601659597850213U) + aPhaseDOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 2759794072560720121U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 23U)) + 9443562552411269339U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 51U)) + 10801360546699857975U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 36U)) + RotL64(aCarry, 53U)) + 8020716394829332019U) + aNonceWordC;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 57U)) + 1021894212367773801U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 13U)) + 13346855534622490176U) + aNonceWordA;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16359309548462953836U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12642446944680783519U;
            aOrbiterB = RotL64((aOrbiterB * 12197935153255283321U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8197424982767553380U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14346334610901859094U;
            aOrbiterE = RotL64((aOrbiterE * 16982899923227935679U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14171304260534233539U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 334531601308283605U;
            aOrbiterH = RotL64((aOrbiterH * 5012968232749075075U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10707856298471572695U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 18364775750091914766U;
            aOrbiterF = RotL64((aOrbiterF * 15735143943129143265U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8531394793118363836U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15352876929406908882U;
            aOrbiterI = RotL64((aOrbiterI * 475199047053777179U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 567682016232278157U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2068146551757663119U;
            aOrbiterA = RotL64((aOrbiterA * 1557877740957797555U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7776122587613256525U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16430938890724272256U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 4540270493783593257U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 26U) + aOrbiterI) + RotL64(aOrbiterB, 13U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterE, 21U)) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterK, 40U)) + aNonceWordJ);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 51U)) + aNonceWordI) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + aPhaseDWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererI, 48U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 2
        // ingress from: aSnowLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC
        // ingress directions: aSnowLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aInvestLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9270U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 8398U)) & S_BLOCK1], 44U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9612U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 10792U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6996U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8753U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 9131U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 44U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 29U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 41U)) + 9133751643283278896U) + aNonceWordC;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 11U)) + 8971581804375380408U) + aNonceWordL;
            aOrbiterB = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 12559650383714566592U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 51U)) + 15753206088872859163U) + aPhaseDOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 5U)) + 7640756270450762350U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 7340073357551376125U) + aNonceWordO;
            aOrbiterF = (aWandererB + RotL64(aCross, 35U)) + 5270256573644196046U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3567367996479995928U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 11939634537492733738U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 5640541900117183639U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7051817732424527120U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1730487669951837941U;
            aOrbiterH = RotL64((aOrbiterH * 15191634337956285841U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18009252467909454817U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2361024272031696442U;
            aOrbiterF = RotL64((aOrbiterF * 15215151562500226027U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15902755877642960397U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12243517544704116184U;
            aOrbiterA = RotL64((aOrbiterA * 2576071074148141447U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16846181962302186187U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 636121425116506681U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 17075030673338779993U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6887385655828217318U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3705834550934775862U;
            aOrbiterJ = RotL64((aOrbiterJ * 11275428284929594435U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11165142437077969438U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6426659930331618269U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17170640810530893705U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 36U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterH, 50U)) + aPhaseDWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterH, 11U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + aPhaseDWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 60U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterK, 39U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 43U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 3
        // ingress from: aSnowLaneB, aExpandLaneA, aFireLaneA
        // ingress directions: aSnowLaneB forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneA, aExpandLaneC
        // cross directions: aSnowLaneA backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11424U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 15397U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13802U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12854U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 14083U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 23U) + RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = ((((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 12027839670755583592U) + aPhaseDOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 15380130703509859843U) + aNonceWordK;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 11U)) + 4590907433867798074U) + aNonceWordI;
            aOrbiterK = (aWandererB + RotL64(aCross, 47U)) + 1754574023602519724U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 3U)) + 9832756659564903767U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 22U)) + 5035088494491470403U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 14199170923323644638U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8325619421264440438U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 969534320779067977U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 17767548306355264705U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 270575869402913847U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13344806516599578910U;
            aOrbiterI = RotL64((aOrbiterI * 10193544126281901579U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15143147951139409101U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14425582489214169238U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16893787086337916355U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13951127523239064584U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14177925225918293579U;
            aOrbiterJ = RotL64((aOrbiterJ * 13079514031864998485U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 8258920744278218901U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7408161179397242453U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 975737128100519169U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8581481606764773468U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10078416198417433133U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 1102721083915858247U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 18299772198826189580U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 18304668908084397946U;
            aOrbiterK = RotL64((aOrbiterK * 10589455451200578687U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 29U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 54U)) + aOrbiterI) + aNonceWordA) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 46U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + aNonceWordD) + aPhaseDWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 47U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 4
        // ingress from: aInvestLaneA, aSnowLaneA, aFireLaneB
        // ingress directions: aInvestLaneA forward forced, aSnowLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneB, aExpandLaneD
        // cross directions: aSnowLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 16697U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 20420U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18521U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19551U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18073U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 21U)) ^ (RotL64(aIngress, 38U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 16160838483846078448U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 23U)) + 15404960896190227946U) + aPhaseDOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 35U)) + 16904160594024977199U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 29U)) + 17790460246821031802U) + aNonceWordO;
            aOrbiterK = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 16395168254086971959U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 14U)) + RotL64(aCarry, 19U)) + 7484373204039901786U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 57U)) + 18026814691322913510U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 15244817793136966450U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5795491730356335666U;
            aOrbiterI = RotL64((aOrbiterI * 13253529465289332171U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3163873518027801504U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2690791759507349172U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 16677948635136515083U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17898067251167087906U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8028010015006604239U;
            aOrbiterB = RotL64((aOrbiterB * 5601629670521300241U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7304739457289910555U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6476837815096530043U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16380545138701113267U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14242499233467960602U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17305645693017634630U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14442976693206929569U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9772864059444171908U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7897200728282156408U;
            aOrbiterC = RotL64((aOrbiterC * 816306719390807411U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4890999319172950996U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8165132649356094963U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 17297706071263690189U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 20U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 44U) + aOrbiterE) + RotL64(aOrbiterJ, 43U));
            aWandererG = aWandererG + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordM) + aPhaseDWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 29U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererI, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 5
        // ingress from: aInvestLaneB, aSnowLaneB, aFireLaneC
        // ingress directions: aInvestLaneB forward forced, aSnowLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneA, aSnowLaneA
        // cross directions: aInvestLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 27129U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneB[((aIndex + 25990U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23523U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25429U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 26331U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 6U)) ^ (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = ((aWandererG + RotL64(aIngress, 29U)) + 16183871922837164759U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 51U)) + 7002058258090219055U) + aNonceWordE;
            aOrbiterE = ((aWandererD + RotL64(aCross, 4U)) + RotL64(aCarry, 27U)) + 5650868611888303705U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 11899839660943876690U) + aNonceWordA;
            aOrbiterA = ((aWandererA + RotL64(aCross, 57U)) + 15349649504488111111U) + aPhaseDOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 13U)) + 14060149569086744970U) + aNonceWordK;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 12920917574225030112U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2831994965175330135U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18312543585028439192U;
            aOrbiterE = RotL64((aOrbiterE * 11618182708195744321U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11657562205118394239U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10850792819281246052U;
            aOrbiterH = RotL64((aOrbiterH * 10663100544207879337U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17810371216216125323U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7963413941144223128U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 534217972450595401U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5498715358793875584U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9256727548911651373U;
            aOrbiterD = RotL64((aOrbiterD * 10498848323914000989U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17246360111302191699U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18309978718113983369U;
            aOrbiterK = RotL64((aOrbiterK * 18267472694666221077U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3100998994319502921U) + aNonceWordG;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 8129301860291235970U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 17847033539279176187U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1889641029473279114U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16538494307002917945U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 8081488217920885783U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterF, 28U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterH, 35U));
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 13U)) + aOrbiterB) + aNonceWordL);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + aNonceWordO);
            aWandererD = aWandererD + ((((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 57U)) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 6
        // ingress from: aInvestLaneC, aInvestLaneA, aFireLaneD
        // ingress directions: aInvestLaneC forward forced, aInvestLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneB, aExpandLaneB
        // cross directions: aInvestLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29347U)) & S_BLOCK1], 54U) ^ RotL64(aInvestLaneA[((aIndex + 30604U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 32142U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28327U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28621U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 1898718075389870739U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 37U)) + 5631794889237247403U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 30U)) + RotL64(aCarry, 3U)) + 18219714659484524607U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 3U)) + 15419581386225732921U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 9125575431710198210U) + aPhaseDOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aWandererD + RotL64(aCross, 13U)) + 12205871520544965505U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 23U)) + 7617534300497343422U) + aNonceWordA;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18017579105368135814U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10693882161946020042U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 2326507900303932855U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 11669615701700895306U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11045110212889232165U;
            aOrbiterH = RotL64((aOrbiterH * 5965171269273719849U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 18019107802806469913U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12315940560472528716U;
            aOrbiterF = RotL64((aOrbiterF * 4505122470351404065U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4899009736070044310U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17412253404253730364U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10791901166391946485U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4826286251927854181U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4523455921321845084U;
            aOrbiterD = RotL64((aOrbiterD * 14534103906736598099U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 4132514462154182215U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7164745605985109269U;
            aOrbiterA = RotL64((aOrbiterA * 14107325508977225261U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6297434295807635654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8813887638672996646U;
            aOrbiterC = RotL64((aOrbiterC * 17495632530773158201U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 46U)) + aOrbiterF) + aPhaseDWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + aNonceWordC);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 10U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Archery_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA4F4A5E93A9CEB75ULL + 0xC0E7CBA85F896EEBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xED542C8716C30677ULL + 0x9BA2555106C357EBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB5F8AB989F810F4BULL + 0xFBB0BF0508B31F45ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE314558200BFC767ULL + 0x83C3564ECF658B66ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF7C49EE3C23089A3ULL + 0xD2A41885A77E9DC8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB8FC1A0C1A0C544DULL + 0xCF830C9A534D9747ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF9DB7DF9133CB4EBULL + 0xDD8158ED7C5F2614ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAEFFEA45561F72CDULL + 0xC52E21B6E0A13299ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x931AB247A82588A1ULL + 0xF50407296A090C71ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF016CEF8FFB1AE39ULL + 0xE971A1DB83CECC15ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA953113C3F07B86BULL + 0xCAD82AAB10F49E9CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9EF93CE66E22222DULL + 0xE8C5E726CCE4D8A9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA0EF1314977E0569ULL + 0xE303F454C589EA52ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEA5035690698B0DBULL + 0xFAAC016973A6E486ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC89F9652034A9365ULL + 0xE57D0CB2B900EE7AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD0D2B1AEDD765DFBULL + 0xD27CB244CAA379C8ULL);
    // GSeedRunSeed_E seed_loop_e (start)
    {
        // GSeedRunSeed_E seed_loop_e lane group
        // read from: aInvestLaneA, aInvestLaneB, aFireLaneA, aInvestLaneC, aInvestLaneD, aFireLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aOperationLaneA, aWorkLaneD, aOperationLaneB, aFireLaneC, aOperationLaneC, aFireLaneD
        // write to: aFireLaneA, aFireLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_e loop 1
        // ingress from: aInvestLaneA, aInvestLaneB, aFireLaneA
        // ingress directions: aInvestLaneA forward forced, aInvestLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneC, aInvestLaneD, aFireLaneB
        // cross directions: aInvestLaneC backward forced, aInvestLaneD backward forced, aFireLaneB backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3541U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneB[((aIndex + 3615U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 990U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1310U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 1662U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1061U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (aWandererI + RotL64(aIngress, 53U)) + 16189787374324972735U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 29U)) + 17563763730956242224U) + aNonceWordB;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 10572803498593789385U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 44U)) + 7713105232072974166U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 10760839534772718139U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 39U)) + 13397069448391230253U) + aNonceWordD;
            aOrbiterA = (aWandererD + RotL64(aIngress, 51U)) + 4569255679998375682U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 9888769350817876949U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 37U)) + 11351796060878856300U) + aNonceWordO;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 21U)) + 18153775071965707204U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 24U)) + 1282846411145853435U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16457743979262460660U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 173493260775251032U;
            aOrbiterF = RotL64((aOrbiterF * 4935807229040883505U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3927345926316409630U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5158769729850853623U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2446452358663812945U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12331351600010165154U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3940794200348684050U;
            aOrbiterH = RotL64((aOrbiterH * 13248997263062075043U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11248514843822945425U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1391497323278226522U;
            aOrbiterK = RotL64((aOrbiterK * 8376841806072565005U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13265623528678787307U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2802033745265647317U;
            aOrbiterA = RotL64((aOrbiterA * 3437626962562016147U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6938444301018051844U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1086544666755559028U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 16039728388882079889U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16156443117365816536U) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3619942859562697142U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7589346043159112151U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17681848914912743292U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8848238631758130416U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 810402256099500607U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6019192027793541890U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16917288363166352778U;
            aOrbiterD = RotL64((aOrbiterD * 17673667086593738207U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5598218150530046752U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17285995539011279010U;
            aOrbiterC = RotL64((aOrbiterC * 15621233176885995065U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12380627610747299268U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 16189787374324972735U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2144714828503219209U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 53U)) + aOrbiterH) + aNonceWordN);
            aWandererE = aWandererE + ((RotL64(aCross, 34U) + aOrbiterG) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + aNonceWordC);
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 5U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterE, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 14U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + aNonceWordH);
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 19U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 58U)) + aOrbiterD) + aNonceWordK) + aPhaseEWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererF, 42U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 2
        // ingress from: aFireLaneA, aInvestLaneC, aInvestLaneD, aWorkLaneA
        // ingress directions: aFireLaneA forward forced, aInvestLaneC forward forced, aInvestLaneD forward forced, aWorkLaneA forward/backward random
        // cross from: aInvestLaneA, aInvestLaneB, aWorkLaneB
        // cross directions: aInvestLaneA backward forced, aInvestLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 10348U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneC[((aIndex + 9826U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 9211U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7251U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 10693U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10705U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 7428U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 60U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((aWandererH + RotL64(aIngress, 39U)) + 5568146815535263910U) + aNonceWordB;
            aOrbiterD = (aWandererD + RotL64(aScatter, 48U)) + 7736084960873834666U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 11U)) + 1336413621817562093U) + aPhaseEOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 5218462026934984692U) + aPhaseEOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 21U)) + 7048890985969555935U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 13415955213864702118U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 5U)) + 5657023257021528548U) + aNonceWordL;
            aOrbiterE = (aWandererC + RotL64(aCross, 51U)) + 14338310943137497116U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 54U)) + 12305161641833950473U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 14514226578370459131U) + aNonceWordM;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 19U)) + 12692904083266024340U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11012959130001327964U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7106471380403489078U;
            aOrbiterC = RotL64((aOrbiterC * 515626559384817223U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3718101961355280891U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13364192077222322664U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1411328915372590283U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6720867800318913440U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14497243926965866546U;
            aOrbiterI = RotL64((aOrbiterI * 13595058589060114653U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5789056168233262435U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14438482587495779937U;
            aOrbiterG = RotL64((aOrbiterG * 10593535547917767263U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 313917798940179945U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15241845511889502917U;
            aOrbiterB = RotL64((aOrbiterB * 16483477103771326107U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3591957424821693032U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1559050939014453558U;
            aOrbiterE = RotL64((aOrbiterE * 17933346117866604725U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15340590914441451383U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5538037287390050110U;
            aOrbiterD = RotL64((aOrbiterD * 4082576643144951473U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4151270491894969214U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 263593701314144898U;
            aOrbiterK = RotL64((aOrbiterK * 10372046955804512457U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9025145270653080646U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6867950904094870056U;
            aOrbiterF = RotL64((aOrbiterF * 9975247022340627751U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3183454301841252109U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3054904157641290615U;
            aOrbiterJ = RotL64((aOrbiterJ * 4092317552439599475U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 1768555574434776135U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5568146815535263910U;
            aOrbiterA = RotL64((aOrbiterA * 12466957001078663927U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterH, 23U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 6U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 41U)) + aOrbiterE) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 50U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 43U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 60U)) + aOrbiterE);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + aNonceWordJ);
            aWandererE = aWandererE + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 24U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 4U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_e loop 3
        // ingress from: aFireLaneB, aInvestLaneA, aWorkLaneC
        // ingress directions: aFireLaneB forward forced, aInvestLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aFireLaneA, aInvestLaneC
        // cross directions: aFireLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 15332U)) & S_BLOCK1], 42U) ^ RotL64(aInvestLaneA[((aIndex + 11658U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11919U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11470U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((aIndex + 11466U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 18U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 11210042748013785976U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 4584747303233477454U) + aNonceWordH;
            aOrbiterI = (aWandererG + RotL64(aIngress, 41U)) + 8878765929792969517U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 30U)) + 2172232330280041122U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 57U)) + 8378937026022264016U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 11U)) + 8683007464695824208U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 9564352997357118134U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 50U)) + 11713878436769887528U) + aPhaseEOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aPrevious, 43U)) + 8052917623074021077U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 13U)) + 7720597162792145185U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 21U)) + 2602847785328475621U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17813669222300509724U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8724263063156573013U;
            aOrbiterI = RotL64((aOrbiterI * 3632927017737834359U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6882429835961613492U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13213313479525717359U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 2411431247725974895U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2401526093648669573U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 3616448566579979749U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 13323155103752121393U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 18268262471839710401U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5116424918948694752U;
            aOrbiterK = RotL64((aOrbiterK * 7641143782996332069U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11405305689555640431U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12427591396711015574U;
            aOrbiterB = RotL64((aOrbiterB * 8112834135715541223U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16960781161508084626U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12382604781005282628U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 17196168631120103115U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10054839091354729292U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4167641616532985407U;
            aOrbiterF = RotL64((aOrbiterF * 919291747187787625U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14383737233143309039U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16258779988369405932U;
            aOrbiterD = RotL64((aOrbiterD * 8348773195366160215U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4777263172049970723U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12498046021142146499U;
            aOrbiterE = RotL64((aOrbiterE * 5941015011162130901U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7435001955334177144U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4100235545173125433U;
            aOrbiterH = RotL64((aOrbiterH * 5046572784117638909U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1981704568071298614U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11210042748013785976U;
            aOrbiterG = RotL64((aOrbiterG * 17889749044418386565U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterI, 37U));
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 29U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 60U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterG, 47U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 6U) + aOrbiterF) + RotL64(aOrbiterD, 20U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererH, 10U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 4
        // ingress from: aOperationLaneA, aFireLaneA, aWorkLaneD
        // ingress directions: aOperationLaneA forward forced, aFireLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aFireLaneB, aInvestLaneD
        // cross directions: aFireLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21674U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneA[((aIndex + 16963U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20847U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20448U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18313U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 46U)) + 13924571355038625040U) + aNonceWordC;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 5U)) + 16328300979357156658U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 3947771961206012461U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 35U)) + 15428284250569311285U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 37U)) + 5777369485254032486U) + aNonceWordB;
            aOrbiterH = ((aWandererB + RotL64(aCross, 39U)) + 16813320300717644673U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 16689933050200758251U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 3U)) + 1856422419049390708U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 27U)) + 18214498743831925517U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 24U)) + RotL64(aCarry, 37U)) + 18278550878494094923U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 57U)) + 797712062039591797U) + aNonceWordH;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15854849439012341347U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 996882939768167773U;
            aOrbiterA = RotL64((aOrbiterA * 14936703950807908575U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3005829974130671692U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8793495343509953906U;
            aOrbiterB = RotL64((aOrbiterB * 14065479348374612031U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7710453029930631112U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9511995836117707047U;
            aOrbiterJ = RotL64((aOrbiterJ * 7250766204781428201U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 670902975693341744U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 9045820304668279777U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 18373074917532639027U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 12417212387607119470U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12816983560669985622U;
            aOrbiterK = RotL64((aOrbiterK * 8406003970221889847U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17245432086377688540U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6806521945548502014U;
            aOrbiterE = RotL64((aOrbiterE * 11335859481858640857U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8947500746292365294U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4468060468522895852U;
            aOrbiterG = RotL64((aOrbiterG * 7022481284816599797U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9892975931958803992U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3042599331526937836U;
            aOrbiterI = RotL64((aOrbiterI * 3308512896171443645U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12991568221485810891U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8551331172836260315U;
            aOrbiterH = RotL64((aOrbiterH * 4509997595920847057U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 183547209633334407U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17275712817092769452U;
            aOrbiterF = RotL64((aOrbiterF * 15677355290000929085U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12743863879392372723U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13924571355038625040U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11966689345179279407U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 18U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 50U) + RotL64(aOrbiterD, 39U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterC, 57U)) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 44U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 37U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterD, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterG, 46U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + aNonceWordD) + aPhaseEWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 18U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_e loop 5
        // ingress from: aOperationLaneB, aFireLaneB, aFireLaneC
        // ingress directions: aOperationLaneB forward forced, aFireLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aFireLaneA, aInvestLaneA
        // cross directions: aOperationLaneA backward forced, aFireLaneA backward forced, aInvestLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27007U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((aIndex + 27080U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26245U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26878U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24854U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24509U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 42U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererK + RotL64(aPrevious, 41U)) + 8767379393098711499U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 7168159491580816433U) + aNonceWordK;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 21U)) + 9879279829061883406U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 19U)) + 10537167136053399303U) + aNonceWordI;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 2839070018069188936U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 5U)) + 13844278063968429732U) + aNonceWordB;
            aOrbiterB = ((aWandererF + RotL64(aCross, 50U)) + 11278946626186474646U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 11798425216660557799U) + aNonceWordP;
            aOrbiterG = (aWandererE + RotL64(aScatter, 39U)) + 7618446090703335192U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 13U)) + 695423597006983660U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 46U)) + 14344728202803488813U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11656100506575697086U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10384358779985773937U;
            aOrbiterF = RotL64((aOrbiterF * 247494692039140973U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17585001605131977341U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9964478171465522911U;
            aOrbiterE = RotL64((aOrbiterE * 13484044854790175315U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2710943171829692624U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17809072853457153057U;
            aOrbiterB = RotL64((aOrbiterB * 16341884203303271365U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12814092033910687774U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1743186323268668740U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11150822630624332557U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10750472346626754704U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15925901217078035356U;
            aOrbiterG = RotL64((aOrbiterG * 9276504171291801637U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2569102106359362359U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8868261301410769739U;
            aOrbiterK = RotL64((aOrbiterK * 3662495603133918101U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2143691008373582476U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 10606616796243205921U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 15794414817813485643U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16258070651850746855U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11720192793689633315U;
            aOrbiterA = RotL64((aOrbiterA * 14475623219460678021U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8230871037292355675U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16898650748046368353U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7368697435476300255U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9071122174426904737U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4506737259011736474U;
            aOrbiterC = RotL64((aOrbiterC * 11903039808814842447U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4545409671845718259U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8767379393098711499U;
            aOrbiterJ = RotL64((aOrbiterJ * 1210632171306946669U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 4U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterD, 57U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + aPhaseEWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 39U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 6U) + aOrbiterC) + RotL64(aOrbiterA, 53U)) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 5U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 22U)) + aOrbiterG) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 51U)) + aOrbiterI) + aNonceWordD);
            aWandererB = aWandererB + ((RotL64(aIngress, 4U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterA, 27U));
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 30U)) + aOrbiterF) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 6
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30296U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 29468U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28410U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32302U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneB[((aIndex + 31696U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 27U)) + (RotL64(aCross, 13U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 4U)) + 10812151398716051703U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 29U)) + 18202551453336003710U;
            aOrbiterA = (aWandererH + RotL64(aCross, 23U)) + 9434410809101973752U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 41U)) + 12955829998028534045U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 19U)) + 12271740641929640181U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 14009351527014534752U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 11U)) + 4316296955679133450U) + aNonceWordL;
            aOrbiterC = ((((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 16473324966997442872U) + aPhaseEOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 37U)) + 15735123324965019802U) + aNonceWordE;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 17656375090484080236U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 34U)) + 16066325053456055298U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12908968778503516903U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12761433987676836197U;
            aOrbiterA = RotL64((aOrbiterA * 1023329467480907925U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12737513138040664509U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14535795767570998392U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 15560519667062222269U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14370908061811284364U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7001358781208669795U;
            aOrbiterE = RotL64((aOrbiterE * 11641248025734015835U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7298578161120090849U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10498302152357484629U;
            aOrbiterC = RotL64((aOrbiterC * 13144110412179037175U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11447343228638006767U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 18284143620422655675U;
            aOrbiterG = RotL64((aOrbiterG * 572862190073605651U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5918253208127360199U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3910541329178205943U;
            aOrbiterD = RotL64((aOrbiterD * 4550654545328228103U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10357053096941367910U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5610891501128498748U;
            aOrbiterF = RotL64((aOrbiterF * 8676370811772047449U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9049881176058575811U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6307599924966452216U;
            aOrbiterB = RotL64((aOrbiterB * 5551444450572055895U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17109966783467892046U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11563095828344462249U;
            aOrbiterH = RotL64((aOrbiterH * 15463753739272001875U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3739147427725509014U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5324449517615050698U;
            aOrbiterK = RotL64((aOrbiterK * 5926079615575226853U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5706251076252597592U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10812151398716051703U;
            aOrbiterJ = RotL64((aOrbiterJ * 5666491216813197045U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 44U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterF, 18U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterG, 29U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + aNonceWordD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 36U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + aNonceWordC);
            aWandererF = aWandererF + ((RotL64(aCross, 28U) + aOrbiterI) + RotL64(aOrbiterJ, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Archery_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aSnowLaneC = pWorkSpace->mSnowLaneC;
    [[maybe_unused]] std::uint8_t *aSnowLaneD = pWorkSpace->mSnowLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x95602EE69F5CBD1BULL + 0xC3FDF9CA1843C802ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEC016229E63AC091ULL + 0xF848D80F67FC024EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD2DCAB34CCD621ABULL + 0xB29025244921A766ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA7E47536CDEC1473ULL + 0x9B3D9BEF81E661E1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF55F73244E83F135ULL + 0xD0E9BCE9309CA8E9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE117227E8C362C93ULL + 0xAEF963C5CAAFB93BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9A687647D12AC959ULL + 0xA5831DB3B4A85943ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAEACC9BBCACD1563ULL + 0xDC269816E622ADF1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x995AAFD5969DFB19ULL + 0xB4FE958CD9E5BB8FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB8217921A15CF3D3ULL + 0x885D2BEEFC171B37ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x924442A85228CA4FULL + 0xC3AF62823D0FF163ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB5ACBA3EBFAE4D23ULL + 0xA0F84D3942427A39ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x94C041C45CE05F37ULL + 0x8315C05BCD912C3AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD8D92C2788782529ULL + 0xB30195420BBC4CF7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAB461D936B4202F9ULL + 0xAF8AD3E1F358839CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBA08F3364B0DDCF9ULL + 0x844BCB405C3BD521ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD, aSnowLaneC, aInvestLaneD, aInvestLaneA, aSnowLaneD, aSnowLaneA, aExpandLaneA, aSnowLaneB, aExpandLaneB, aInvestLaneC, aExpandLaneC, aInvestLaneB
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2165U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 1010U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 1400U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2714U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5320U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 1121U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = (aWandererA + RotL64(aCross, 41U)) + 3236820517816085022U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 19U)) + 741288875914097926U) + aNonceWordG;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 6U)) + 8417246926007729580U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 35U)) + 9715717805774537170U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 11U)) + 14360243844821619482U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 23U)) + 10760908100206775334U) + aNonceWordB;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 46U)) + RotL64(aCarry, 47U)) + 3434641779946167811U) + aNonceWordH;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 7885568822756234567U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 3041563437672051294U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15761355327564963516U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1158633562785937421U;
            aOrbiterF = RotL64((aOrbiterF * 15511324886867188235U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9338581575871970653U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9172038894262857354U;
            aOrbiterI = RotL64((aOrbiterI * 3110871165285625807U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14653924713599790081U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3854497592598563309U;
            aOrbiterA = RotL64((aOrbiterA * 11737111068815795303U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16286980180327600557U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5092583772591249756U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 13955105624639442903U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4288397994175567333U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15584236478994873104U;
            aOrbiterC = RotL64((aOrbiterC * 1860480595862755379U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5557463939827483792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2659814275753280856U;
            aOrbiterD = RotL64((aOrbiterD * 17702430405693184643U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6941807963525063449U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2040598555191211307U;
            aOrbiterK = RotL64((aOrbiterK * 14750544987531722765U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 347572666231116258U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 779304821185302523U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14180254150318109855U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10632524582873079742U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9761308771280517212U;
            aOrbiterG = RotL64((aOrbiterG * 13926235411726048921U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 46U) + aOrbiterI) + RotL64(aOrbiterF, 52U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterA, 47U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 39U)) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aIngress, 42U) + aOrbiterB) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterD, 43U));
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterB, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 5938U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 8424U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9138U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6893U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9904U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10191U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 7216U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 39U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = (aWandererI + RotL64(aCross, 46U)) + 5173905450211892891U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 3555542451908039957U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 51U)) + 11559884700283861559U) + aNonceWordC;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 1352524329968738673U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 10U)) + RotL64(aCarry, 27U)) + 8914206450420616349U) + aNonceWordD;
            aOrbiterG = ((aWandererA + RotL64(aCross, 41U)) + 2251523378498463946U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 19U)) + 9541575923299247038U) + aNonceWordK;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 3U)) + 1239854507907214595U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 57U)) + 17698101462598498934U) + aNonceWordF;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12305566971683256060U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13804545036303215569U;
            aOrbiterD = RotL64((aOrbiterD * 10359543704152744971U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10239749097704329264U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4212214906286320308U;
            aOrbiterH = RotL64((aOrbiterH * 3661436621615751071U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12192418916967430783U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4475514289326450361U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 17497164630368757887U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17376102613298827459U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 18129393209955439341U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 6404089025014118979U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4014763724300253568U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17325007199676828814U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1420888274815627083U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15480474849292388685U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 14357924730184375449U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16723492259068034209U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4335731868597970070U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8296023680394303015U;
            aOrbiterI = RotL64((aOrbiterI * 14027415401430120543U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2807312426993262800U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 15510369660839648501U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 18207954408298333959U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12597844696606519907U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7231012798553551535U;
            aOrbiterG = RotL64((aOrbiterG * 2841306785994479299U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 20U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 20U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + aPhaseFWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 44U) + aOrbiterE) + RotL64(aOrbiterH, 51U));
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 56U)) + aOrbiterA) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterA, 3U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 10U) + aOrbiterF) + RotL64(aOrbiterG, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aSnowLaneA
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aSnowLaneA forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 14060U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 13995U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 13868U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11432U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneC[((aIndex + 13407U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 51U)) + (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (((aWandererG + RotL64(aCross, 6U)) + RotL64(aCarry, 13U)) + 7896237440058555694U) + aNonceWordF;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 47U)) + 11870529476037558635U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 53U)) + 9158983227801569448U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 4710172270996950329U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 14634482800356647630U) + aNonceWordH;
            aOrbiterB = (aWandererB + RotL64(aIngress, 37U)) + 8822207952170610891U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 11U)) + 13755891414028982553U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 57U)) + 4555293067488040719U) + aNonceWordL;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 18U)) + 2816805148093762081U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2122631477965135190U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4592922416380416071U;
            aOrbiterI = RotL64((aOrbiterI * 11644507904538573165U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7102471666524164715U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17274623547879474204U;
            aOrbiterB = RotL64((aOrbiterB * 5443572270546181789U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 938587316977094680U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 18258015823797023523U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 6068819567674605919U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5809987756043471595U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5083075160112581620U;
            aOrbiterC = RotL64((aOrbiterC * 3313957222154937503U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5960021727750946496U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5967477320950630150U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 330964768256424655U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6578428711689296132U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5601728218197771276U;
            aOrbiterH = RotL64((aOrbiterH * 9552559022315971847U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7923809409017855241U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16479366540906497019U;
            aOrbiterG = RotL64((aOrbiterG * 7118578387798460919U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17000467091738009736U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6801634573655508028U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10584635770060137089U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 123668445682719574U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14462802805503986316U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12398236364304875941U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterA, 50U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 57U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterG, 29U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 14U)) + aOrbiterC) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 41U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aSnowLaneB
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aSnowLaneB forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16742U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 16963U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 18591U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 20967U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 17452U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 29U)) + 3248574644570178787U) + aNonceWordH;
            aOrbiterD = (((aWandererE + RotL64(aCross, 18U)) + RotL64(aCarry, 5U)) + 4506961512959200024U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 8423739774540738590U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 51U)) + 6593975869641735337U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 43U)) + 16441716090557369103U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 13U)) + 7936601450453207914U) + aNonceWordG;
            aOrbiterC = ((((aWandererH + RotL64(aIngress, 22U)) + RotL64(aCarry, 43U)) + 13333752583560167065U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aWandererD + RotL64(aCross, 57U)) + 8013703284795432973U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 47U)) + 2349852779887439236U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5318539364763284138U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11450957608502944376U;
            aOrbiterI = RotL64((aOrbiterI * 1957880366707810635U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9058992558327552687U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 632095686920230926U;
            aOrbiterE = RotL64((aOrbiterE * 12460364388358520799U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14734218428913777098U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16344357661370784442U;
            aOrbiterG = RotL64((aOrbiterG * 15049472842002138369U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2981145363531184308U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14176472085175714494U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 2584623327412130939U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11198457590069700889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 952584436750426828U;
            aOrbiterF = RotL64((aOrbiterF * 1165713888651280355U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4311591763498985972U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16194341833989936369U;
            aOrbiterD = RotL64((aOrbiterD * 9997934560195932575U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7560794022401107431U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10683789740265711603U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15637823045351977883U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11614366395125937178U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10750771385100564416U;
            aOrbiterA = RotL64((aOrbiterA * 4987921274272444283U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2934697034132204529U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4646873794658020363U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 10555456865641580175U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 18U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 12U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 4U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterG, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 35U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterA, 5U));
            aWandererG = aWandererG + (((RotL64(aIngress, 42U) + aOrbiterE) + RotL64(aOrbiterA, 48U)) + aPhaseFWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 22U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneC
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23643U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneD[((aIndex + 24612U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 26995U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24592U)) & S_BLOCK1], 18U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 23831U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aCross, 22U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 46U)) + RotL64(aCarry, 19U)) + 8988572360732005217U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 13U)) + 17889613225105985335U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 15563478320513948626U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 5U)) + 3441351228410524816U) + aNonceWordH;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 4425592689451435346U) + aNonceWordK;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 19U)) + 12733160231627305928U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 29U)) + 3574152157304607854U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 58U)) + 15167631896729808783U) + aNonceWordG;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 23U)) + 15822667973915417055U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17181685481076577637U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9979204751408873468U;
            aOrbiterC = RotL64((aOrbiterC * 8244434774754786565U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1334240485667164762U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9190066751460137016U;
            aOrbiterG = RotL64((aOrbiterG * 14585141844653660363U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15465215829109246336U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2305208282453624419U;
            aOrbiterD = RotL64((aOrbiterD * 10257861974108363283U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16951510027310993926U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11117938943423526901U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 7805486716716924787U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12461379120662979432U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11719697049048823897U;
            aOrbiterF = RotL64((aOrbiterF * 14880996802304818757U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6843357278142933570U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12727898578324702374U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9786435451654365097U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 18127999660067652233U) + aNonceWordB;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 11754709060558683082U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12798744012150745847U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16940151146420516184U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12924950783056761895U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 8898170377271926745U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14829713915929878471U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 840466047621042565U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10748511630509529489U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 14U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 35U)) + aOrbiterF) + aNonceWordN);
            aWandererH = aWandererH + (((RotL64(aIngress, 12U) + aOrbiterI) + RotL64(aOrbiterC, 23U)) + aPhaseFWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 29U)) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 51U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterK, 58U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 6U) + aOrbiterF) + RotL64(aOrbiterJ, 41U)) + aNonceWordL);
            aWandererI = aWandererI + ((((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 46U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29019U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 32428U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 32022U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27370U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31136U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 52U)) + (RotL64(aCross, 39U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererB + RotL64(aCross, 10U)) + 14686411261024919129U) + aNonceWordD;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 7514582233957632005U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 23U)) + 6520710480103365552U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 43U)) + 1983621978676188036U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 51U)) + 9003524602590749672U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 6428568234045228995U) + aNonceWordO;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 8656552687136446989U) + aNonceWordC;
            aOrbiterI = ((aWandererE + RotL64(aCross, 39U)) + 16916248288415922490U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 28U)) + 9740237548002535784U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 907561000814618339U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4751108900841197631U;
            aOrbiterE = RotL64((aOrbiterE * 4545395964730641957U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 167774899400732287U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11907484918310854962U;
            aOrbiterF = RotL64((aOrbiterF * 7213139491146402985U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14910318613649863924U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14882888155751455276U;
            aOrbiterG = RotL64((aOrbiterG * 11394136445442060201U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16175942562693781908U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11022373758481651102U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6836331461393816027U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12548405399045031548U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10850926364556828443U;
            aOrbiterK = RotL64((aOrbiterK * 16231561687709867431U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13391684887911141790U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14648937281264822988U;
            aOrbiterB = RotL64((aOrbiterB * 6533299316940026059U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8298658887198526821U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13822977698661348891U;
            aOrbiterC = RotL64((aOrbiterC * 17769262972278410937U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7505646847564645719U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3238749538197209166U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15394286542600778567U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15853506915123709257U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8426329899401071248U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 1330397096577715113U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 24U) + aOrbiterI) + RotL64(aOrbiterE, 52U));
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + aNonceWordB) + aPhaseFWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterG, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 30U) + aOrbiterA) + RotL64(aOrbiterG, 60U)) + aNonceWordE);
            aWandererB = aWandererB + ((((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 53U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterB, 39U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Archery_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aSnowLaneC = pWorkSpace->mSnowLaneC;
    [[maybe_unused]] std::uint8_t *aSnowLaneD = pWorkSpace->mSnowLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9C5FC6DE90BC1649ULL + 0xD50C2FC88AA048C7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFDF63EEE61DCE8AFULL + 0xD3149A180791AB96ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCF12762DE3924AFFULL + 0xDC985F8227E3F0C0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9D6433A735E36A3DULL + 0xCA94A2E64B09EB6DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDFD8AC75DAC62AF9ULL + 0xCC72C02911E3C3CFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x89413F7DBB3EC9DFULL + 0xAE8300ACCF04EE3CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC7814C6BED8AD6EFULL + 0xF022BF617E38E059ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x88259DCCED0F38F3ULL + 0x918330191074E5AAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x94A2CDDA0DF252BBULL + 0xF19E619DC659458AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDF133A661A3CD95FULL + 0xAD56765B40B6C6F4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8972A5F5EA468F1DULL + 0xDBB4B95858EB8744ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD1232518294A1089ULL + 0xF8F8D6F4D1D59161ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA5E976D6F015887BULL + 0xFE9E081900EC6DE7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD992C394A057AFABULL + 0xEE4348B120DE4FC7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9C0A128579D7A0ABULL + 0x962C596E57248251ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x885212BBC5FC3E9BULL + 0xC3EDA7D9EB434322ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneD, aSnowLaneC, aSnowLaneD, aFireLaneC, aWorkLaneA, aFireLaneA, aFireLaneB, aWorkLaneB, aInvestLaneA, aExpandLaneA, aInvestLaneB, aExpandLaneB, aInvestLaneC, aExpandLaneC, aInvestLaneD
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneD
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneC
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 1839U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneB[((aIndex + 4137U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 1511U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 5232U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 2512U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 535U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 6361545377408870615U) + aNonceWordF;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 47U)) + 2967245486744774933U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (aWandererF + RotL64(aScatter, 23U)) + 3836634268482850139U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 7691642115360086297U) + aNonceWordB;
            aOrbiterD = (aWandererH + RotL64(aCross, 5U)) + 16479280384178279281U;
            aOrbiterG = ((((aWandererC + RotL64(aScatter, 36U)) + RotL64(aCarry, 53U)) + 2901468732552539249U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 11U)) + 2600353867755647475U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5666596904781510956U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16108791609267427553U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 8904649663479834199U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8389926875737312112U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1689501721163024426U;
            aOrbiterD = RotL64((aOrbiterD * 6517194895779049139U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11721701506949917719U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3963842745030140473U;
            aOrbiterC = RotL64((aOrbiterC * 6692473494944919373U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 8510538243472109368U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 18281865214102080387U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 1351546966368884609U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2259725140963665123U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11652011949557979650U;
            aOrbiterJ = RotL64((aOrbiterJ * 11260100762113295037U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 1116085424226174473U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4725260319270802912U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4697109059565450269U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7348945429843437036U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1249234309180653260U;
            aOrbiterH = RotL64((aOrbiterH * 3136745255820405881U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 54U) + RotL64(aOrbiterH, 36U)) + aOrbiterA) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + aNonceWordL) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneB
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8605U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneC[((aIndex + 9382U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 8650U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((aIndex + 6575U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 10062U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8331U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 8679U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 35U)) + (RotL64(aCross, 48U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (aWandererK + RotL64(aIngress, 53U)) + 8375305456876489425U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 41U)) + 16193562952772453047U) + aPhaseHOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 57U)) + 18088652458594816223U) + aNonceWordK;
            aOrbiterH = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 767344788620249944U) + aNonceWordC;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 7705194930396368752U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 19U)) + 3829736891311272834U) + aNonceWordL;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 27U)) + 9881681671347640061U) + aPhaseHOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1721196560190164264U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3002652618388454213U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15289749311593032657U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9811621464004005202U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5652598941069986530U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 4797973356708091621U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6250499348327316328U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16025054277615264530U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16446892258704281903U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13800298546867243172U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12256104592865905782U;
            aOrbiterA = RotL64((aOrbiterA * 16983140179497142713U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17817225416918329229U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 17738671327352776217U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 393488251327705063U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6816031224188400541U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16989563985059237014U;
            aOrbiterH = RotL64((aOrbiterH * 8677884225771717797U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16891524847268207549U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1833508573940405571U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9709196587703979539U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 29U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aPrevious, 40U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterH, 43U)) + aNonceWordH) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 60U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterI, 13U)) + aNonceWordA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aInvestLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13019U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 14485U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15849U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14773U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneC[((aIndex + 11032U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 51U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (aWandererF + RotL64(aPrevious, 53U)) + 17936518874386450467U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 39U)) + 13722737841589910344U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 26U)) + 11774969167948715796U;
            aOrbiterE = ((((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 3640101505680493777U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 47U)) + 1369495382725650822U) + aNonceWordE;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 11827310354654653345U) + aNonceWordB;
            aOrbiterA = (aWandererB + RotL64(aCross, 3U)) + 186037671377175394U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11428829344234627340U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2275016369870029068U;
            aOrbiterD = RotL64((aOrbiterD * 14936799202145280833U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15471646673734798328U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12172082573115640145U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9629417882787847753U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6626736341348283154U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12220614992483863623U;
            aOrbiterF = RotL64((aOrbiterF * 8137086205714097487U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13157102324253760215U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4143587482368093601U;
            aOrbiterA = RotL64((aOrbiterA * 5060677690991506895U), 51U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 11007575246013796426U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11721585930088637162U;
            aOrbiterK = RotL64((aOrbiterK * 15009627907125738519U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5720789204450196217U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3094696226821431648U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4412033981712165541U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14675830108100986773U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9444071495289719645U;
            aOrbiterI = RotL64((aOrbiterI * 10983136361953366557U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 21U)) + aOrbiterD) + aNonceWordK) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterI, 58U));
            aWandererE = aWandererE + ((((RotL64(aCross, 51U) + RotL64(aOrbiterF, 11U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterD) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20849U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 19464U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 19343U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16628U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18626U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 3199575576585871314U) + aPhaseHOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aCross, 51U)) + 2533378188975571824U) + aNonceWordI;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 39U)) + 6819782112558312658U) + aPhaseHOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 29U)) + 12690060987724798497U) + aNonceWordM;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 7088375139715629606U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 3U)) + 17785618677423695666U) + aNonceWordK;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 5U)) + 1714999280296491277U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17611338506932491624U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6475727359297421201U;
            aOrbiterC = RotL64((aOrbiterC * 15133348244242438069U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2347744591204119530U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2739317903351401068U;
            aOrbiterE = RotL64((aOrbiterE * 15435029315209475631U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8663535261373274338U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8205245127823536479U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 13857005110466856439U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8916510616749754516U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3944805940148512932U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18082271583211389701U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 14094751253118853302U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14094299829196076311U;
            aOrbiterB = RotL64((aOrbiterB * 6370012560657108493U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3940673811518673802U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3015106523254484839U;
            aOrbiterG = RotL64((aOrbiterG * 9655401190755573379U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15404103131982599922U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1828655763233900875U;
            aOrbiterD = RotL64((aOrbiterD * 13024358077740310049U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 19U)) + aOrbiterG);
            aWandererC = aWandererC + (((((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterE, 28U)) + RotL64(aCarry, 3U)) + aNonceWordL) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterE, 53U)) + aNonceWordB) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 42U) + RotL64(aOrbiterA, 5U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 27U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aInvestLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23793U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 26043U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25284U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21852U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 22120U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 13U) + RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = ((aWandererG + RotL64(aIngress, 21U)) + 6733949564325516029U) + aNonceWordE;
            aOrbiterH = (((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 7304098437143918796U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 57U)) + 3923949518391777800U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 27U)) + 14243591003388927124U) + aNonceWordL;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 18329498724605410406U) + aNonceWordI;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 13118172167747037249U) + aNonceWordD;
            aOrbiterI = (aWandererD + RotL64(aCross, 36U)) + 5272025143849174212U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16075917179214318424U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15263590648674658399U;
            aOrbiterA = RotL64((aOrbiterA * 9918239923411740337U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13730046728289525921U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7703141464499623408U;
            aOrbiterH = RotL64((aOrbiterH * 5886009900621521987U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1382279753822135359U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2973369221699098292U;
            aOrbiterJ = RotL64((aOrbiterJ * 7440242040663550631U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11578274119583013219U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3419411247737896674U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17814942652262802991U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 2582783513078999303U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3959762790273529677U;
            aOrbiterI = RotL64((aOrbiterI * 383974377372162751U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 465795011576934604U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17880826624185821135U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4445949147592860913U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10819659185349413173U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17298208553586835030U;
            aOrbiterF = RotL64((aOrbiterF * 1965860510614222093U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterI, 5U)) + aNonceWordF);
            aWandererD = aWandererD + ((((RotL64(aScatter, 12U) + aOrbiterG) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 3U)) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + aPhaseHWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + aNonceWordN);
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterH, 26U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterK, 53U)) + aNonceWordP) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30168U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 30813U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 29214U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32394U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 29234U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 3U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 37U)) + 6024062041314952357U) + aNonceWordE;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 18340757093658015585U) + aPhaseHOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 3U)) + 11911120493880346751U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 13U)) + 17428074353884654439U) + aNonceWordD;
            aOrbiterA = (aWandererB + RotL64(aCross, 21U)) + 12790849760814795936U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 12633397052172117800U) + aNonceWordI;
            aOrbiterI = ((((aWandererD + RotL64(aIngress, 50U)) + RotL64(aCarry, 39U)) + 11946150433665237945U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16842157900909419285U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14186235783224155962U;
            aOrbiterJ = RotL64((aOrbiterJ * 10521157787073684417U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13284904542579767591U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11609181965078844357U;
            aOrbiterA = RotL64((aOrbiterA * 5455780554452453513U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9628562297095374984U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7850281529011259759U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 17611485102925470357U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 257458718073794527U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 10693404545773519306U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 14821443722828498323U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3430519236533871460U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6183054506953198055U;
            aOrbiterF = RotL64((aOrbiterF * 6121082743789970911U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2905610989884221654U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4472163910775333862U;
            aOrbiterI = RotL64((aOrbiterI * 7770678426310856745U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16870142883133769663U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1403692060594816451U;
            aOrbiterE = RotL64((aOrbiterE * 9740854430251597879U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterF, 19U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 4U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterF, 41U)) + aNonceWordB) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterE, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 19U);
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

void TwistExpander_Archery_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
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
        // read from: aKeyRowReadA, aKeyRowReadB, mSource, aWorkLaneA, aWorkLaneB, aInvestLaneA, aInvestLaneB, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aInvestLaneA, aInvestLaneB, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // twist_loop_a loop 1
        // ingress from: aKeyRowReadA, aKeyRowReadB
        // ingress directions: aKeyRowReadA forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource
        // cross directions: aKeyRowReadA backward forced, mSource backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1301U)) & W_KEY1], 12U) ^ RotL64(aKeyRowReadB[((aIndex + 1674U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1696U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 1610U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 40U)) ^ (RotL64(aCross, 13U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 16462052553719977502U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 60U)) + 12337064059566619581U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 35U)) + 15801005007094515447U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 8228706742665081656U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 53U)) + 11006723027845190869U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 48U)) + 18173765337829177450U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 11U)) + 530215083653542558U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 3U)) + 6608611827035564511U) + aPhaseAOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 2246051826221626809U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5228575308895381421U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10999213210689606857U;
            aOrbiterB = RotL64((aOrbiterB * 5467601259546342925U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3773371037240485696U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8887985779436152504U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 698713082830739677U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11150566414723818350U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8336366151003049546U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9033771197242493699U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13233968794237090787U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8172558473508478819U;
            aOrbiterF = RotL64((aOrbiterF * 17837070423649268435U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 133564480283347997U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15104810248883567064U;
            aOrbiterJ = RotL64((aOrbiterJ * 706802420642303533U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9138629520201127075U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13993086066341664080U;
            aOrbiterG = RotL64((aOrbiterG * 4875046427147105077U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6547273508580516932U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9838727018769865759U;
            aOrbiterC = RotL64((aOrbiterC * 11395273371936839815U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11685694999526122626U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8945983172566303116U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17791527981004597623U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17606249889617356327U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9296903152000480008U;
            aOrbiterD = RotL64((aOrbiterD * 18066622289408024413U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 56U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 22U) + RotL64(aOrbiterC, 38U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterG, 3U));
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 56U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 46U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + aPhaseAWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 13U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 2
        // ingress from: aWorkLaneA, aKeyRowReadA
        // ingress directions: aWorkLaneA forward forced, aKeyRowReadA forward/backward random
        // cross from: aKeyRowReadB, mSource
        // cross directions: aKeyRowReadB backward forced, mSource backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 4709U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 4860U)) & W_KEY1], 30U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5033U)) & W_KEY1], 27U) ^ RotL64(mSource[((aIndex + 4982U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aScatter, 44U)) + 13442819395490639310U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 8187292523194120936U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 11469697159823131388U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 51U)) + 13414083692375929653U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 11404010733687907517U;
            aOrbiterB = (aWandererB + RotL64(aCross, 13U)) + 6783212827186218247U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 34U)) + 8561131439340372614U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 19U)) + 6252609642004429113U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 5U)) + 12804867444200448952U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2739648749603690781U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14808861217017399752U;
            aOrbiterK = RotL64((aOrbiterK * 373911885694012101U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17588866502571268888U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5882260142735642980U;
            aOrbiterA = RotL64((aOrbiterA * 7688252946143263869U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15493099088132862949U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5175647411532429582U;
            aOrbiterF = RotL64((aOrbiterF * 15226544495598541883U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14279707376173642767U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6826363572161275158U;
            aOrbiterC = RotL64((aOrbiterC * 5263708315440161809U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13267185753040999992U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9980987858092888720U;
            aOrbiterE = RotL64((aOrbiterE * 13210290848800728635U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3582972937645514549U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10140409019562890804U;
            aOrbiterG = RotL64((aOrbiterG * 6944490201647678479U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6160444117287330557U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16344602960561293113U;
            aOrbiterB = RotL64((aOrbiterB * 2319964919335633293U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3497141036108337171U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 91269118352540308U;
            aOrbiterH = RotL64((aOrbiterH * 5160060720189045505U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12739932748793144857U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12820180915064791197U;
            aOrbiterD = RotL64((aOrbiterD * 5843849637411948699U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 60U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 43U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterC, 27U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterB, 47U)) + aPhaseAWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterA, 11U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 36U)) + aOrbiterK) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 3
        // ingress from: aWorkLaneB, aKeyRowReadB
        // ingress directions: aWorkLaneB forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource, aWorkLaneA
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aWorkLaneA backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneB[((aIndex + 8108U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6218U)) & W_KEY1], 60U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6814U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7583U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6020U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 50U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererJ + RotL64(aCross, 58U)) + 8793908991006073956U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 27U)) + 2932916283348441943U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 5U)) + 11069042087940968262U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 14369628676782894441U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 8602903272780978282U) + aPhaseAOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 39U)) + 3827036107178568820U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 47U)) + 8905245209036772489U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 13331387530760017893U;
            aOrbiterA = (aWandererI + RotL64(aCross, 10U)) + 9880107580289737823U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10199619040626900278U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2466307560891374281U;
            aOrbiterF = RotL64((aOrbiterF * 6295342978834217571U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13973403407981259448U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2851460278409385243U;
            aOrbiterJ = RotL64((aOrbiterJ * 11226902976321781743U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10365453393815690776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2382382358987358791U;
            aOrbiterI = RotL64((aOrbiterI * 481563628980705781U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5058198848163792422U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10500434740387593487U;
            aOrbiterG = RotL64((aOrbiterG * 5946747708776079787U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11289798395177667084U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14327152153231286666U;
            aOrbiterA = RotL64((aOrbiterA * 18155778059595245561U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8065137263811956313U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3865153574847924816U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9495741102667755161U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 18102279969722473375U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6306428427188742325U;
            aOrbiterK = RotL64((aOrbiterK * 17826782872351406167U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16953348204663693724U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11950791817032898613U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1498946055469611133U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11980823193543752994U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17845490308799454871U;
            aOrbiterE = RotL64((aOrbiterE * 16385153013485463791U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 50U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 6U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterD, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 24U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 52U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 53U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterB, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 42U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterD, 11U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 18U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 4
        // ingress from: aInvestLaneA, aKeyRowReadB, mSource, aWorkLaneA
        // ingress directions: aInvestLaneA forward forced, aKeyRowReadB forward forced, mSource forward forced, aWorkLaneA forward/backward random
        // cross from: aKeyRowReadA, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, aWorkLaneB backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10885U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadB[((aIndex + 9957U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 10309U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 9695U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8975U)) & W_KEY1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 10499U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 12U)) ^ (RotL64(aCross, 41U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 14214886793361825363U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 14U)) + 17267959031078766320U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 16436067429484887644U) + aPhaseBOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 9885951769332633820U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 57U)) + 12971711341813893304U) + aPhaseBOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 41U)) + 199970353398450154U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 23U)) + 1237341696444162094U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 47U)) + 7991128854417613360U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 6U)) + 14809029847149045833U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2559509556915775947U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14336829730147834160U;
            aOrbiterG = RotL64((aOrbiterG * 15103242520064900873U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8853631886733610440U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13346159398673246914U;
            aOrbiterC = RotL64((aOrbiterC * 13660497151446983393U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12121095718571872976U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16239781125815589804U;
            aOrbiterD = RotL64((aOrbiterD * 5157009090454962231U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9051377033794324106U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13805815136723461780U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 571129481747181357U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14849157800322754413U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 18116651528452542634U;
            aOrbiterJ = RotL64((aOrbiterJ * 3638480428016835537U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4105057226952948599U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5911714320560994391U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1796514171654961389U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4439149331729987587U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10278532228230163632U;
            aOrbiterH = RotL64((aOrbiterH * 17428224919864716517U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2342456582668741750U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2360578572554664800U;
            aOrbiterA = RotL64((aOrbiterA * 1108428466956691925U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12132934875391401246U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17213278726790245812U;
            aOrbiterK = RotL64((aOrbiterK * 11904899990681410419U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 57U));
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 43U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterA, 34U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 4U) + aOrbiterF) + RotL64(aOrbiterH, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + aPhaseBWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterH, 30U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 48U) + aOrbiterB) + RotL64(aOrbiterF, 19U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 5
        // ingress from: aInvestLaneB, aKeyRowReadA, aKeyRowReadB, mSource, aWorkLaneB
        // ingress directions: aInvestLaneB forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, mSource forward forced, aWorkLaneB forward/backward random
        // cross from: aWorkLaneA, aInvestLaneA
        // cross directions: aWorkLaneA backward forced, aInvestLaneA backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13457U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 12862U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11859U)) & W_KEY1], 41U) ^ RotL64(mSource[((aIndex + 12208U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 13320U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11420U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((aIndex + 11389U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 58U) ^ RotL64(aCross, 23U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererE + RotL64(aIngress, 19U)) + 3448371607470865612U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 3U)) + 3743742913651580573U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 56U)) + 13069491287948807280U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 35U)) + 16872779275586545632U) + aPhaseBOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 17945792656755062795U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 11U)) + 18199747196793731853U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 15953311878379809513U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 51U)) + 941268763494588338U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 24U)) + RotL64(aCarry, 27U)) + 10090221530365796809U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8335698093307607001U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 6147498804734306100U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6904444049941211327U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5980246079567570090U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4152167624425912978U;
            aOrbiterC = RotL64((aOrbiterC * 10019421651535123573U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14990418790239735916U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3418668387496597219U;
            aOrbiterH = RotL64((aOrbiterH * 12814077238529863119U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4206650904177199425U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3905470780938996069U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16030122739273137005U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9968672788233080924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 602258075661864866U;
            aOrbiterK = RotL64((aOrbiterK * 2615726693066300065U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17751667243048041383U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2414054413585296027U;
            aOrbiterI = RotL64((aOrbiterI * 1049512574773201893U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6523322402744047752U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6729901917767398779U;
            aOrbiterB = RotL64((aOrbiterB * 8039939871405367139U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11460169185076814539U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7559640379553110573U;
            aOrbiterD = RotL64((aOrbiterD * 9864654321914036135U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17271150091827475028U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3541809324556914646U;
            aOrbiterG = RotL64((aOrbiterG * 12655168871428868639U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 24U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + aPhaseBWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 38U) + aOrbiterI) + RotL64(aOrbiterH, 30U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterA, 51U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 46U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 21U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aScatter, 34U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 6
        // ingress from: aFireLaneA, aInvestLaneA
        // ingress directions: aFireLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, mSource, aWorkLaneB, aWorkLaneA
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, mSource backward forced, aWorkLaneB backward forced, aWorkLaneA backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 15563U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneA[((aIndex + 14591U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14704U)) & W_KEY1], 28U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15419U)) & W_KEY1], 53U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13692U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13675U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15737U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 6U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 28U)) + 16160838483846078448U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 15404960896190227946U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 16904160594024977199U) + aPhaseBOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 23U)) + 17790460246821031802U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 51U)) + 16395168254086971959U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 3U)) + 7484373204039901786U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 18026814691322913510U;
            aOrbiterH = (aWandererH + RotL64(aCross, 39U)) + 15244817793136966450U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 18U)) + 5795491730356335666U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3163873518027801504U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2690791759507349172U;
            aOrbiterE = RotL64((aOrbiterE * 16677948635136515083U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17898067251167087906U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8028010015006604239U;
            aOrbiterF = RotL64((aOrbiterF * 5601629670521300241U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7304739457289910555U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6476837815096530043U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16380545138701113267U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14242499233467960602U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17305645693017634630U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14442976693206929569U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9772864059444171908U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7897200728282156408U;
            aOrbiterG = RotL64((aOrbiterG * 816306719390807411U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4890999319172950996U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8165132649356094963U;
            aOrbiterJ = RotL64((aOrbiterJ * 17297706071263690189U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9342923520083533265U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7213639583505088067U;
            aOrbiterK = RotL64((aOrbiterK * 1349251979649428909U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4079475132684197272U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3350998022472827283U;
            aOrbiterA = RotL64((aOrbiterA * 948841791460066265U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2479140576609216238U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7703147534931674972U;
            aOrbiterH = RotL64((aOrbiterH * 11419116495223970801U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 28U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 22U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererA = aWandererA + ((RotL64(aIngress, 44U) + aOrbiterJ) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 41U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 18U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterF, 5U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 37U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterE, 51U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 18U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 7
        // ingress from: aFireLaneB, aKeyRowReadA, mSource, aWorkLaneA
        // ingress directions: aFireLaneB forward forced, aKeyRowReadA forward forced, mSource forward forced, aWorkLaneA forward/backward random
        // cross from: aKeyRowReadB, aInvestLaneB, aFireLaneA
        // cross directions: aKeyRowReadB backward forced, aInvestLaneB backward forced, aFireLaneA backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 19098U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 16531U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(mSource[((aIndex + 16762U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 18937U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18234U)) & W_KEY1], 29U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17779U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17828U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 46U)) + RotL64(aCarry, 37U)) + 380024772508948442U;
            aOrbiterK = (aWandererB + RotL64(aCross, 57U)) + 7649029098162567210U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 23U)) + 5329304598870421851U) + aPhaseCOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 12306118665045151326U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 4U)) + 960751560457324256U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 39U)) + 3244070254386191876U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 19U)) + 15733408571609521746U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 17623448932647018544U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 29U)) + 8787759896149035829U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14741681792348288162U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8801731213568307302U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12127126999570616489U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9872248187499779222U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15407371518644528235U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1245102406469471673U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4242060317152943062U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9942784962409917541U;
            aOrbiterH = RotL64((aOrbiterH * 888649755587764533U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7296348796484458631U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15061417216070157797U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10349554676953256231U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3233185810644297433U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9241229457641024287U;
            aOrbiterC = RotL64((aOrbiterC * 2728237515724597517U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8464051359381554575U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3307872165699029375U;
            aOrbiterB = RotL64((aOrbiterB * 4859663401033023433U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5482617843966711997U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4442149210462943872U;
            aOrbiterK = RotL64((aOrbiterK * 8979352218576515647U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10591636597580147381U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14925122230279312217U;
            aOrbiterF = RotL64((aOrbiterF * 15038171961638724013U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9772367878232735350U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15800661165607190092U;
            aOrbiterD = RotL64((aOrbiterD * 10493976952980533589U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 46U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 12U));
            aWandererK = aWandererK + ((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterH, 23U));
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterG, 53U));
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 57U)) + aOrbiterC) + aPhaseCWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 34U)) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 8
        // ingress from: aFireLaneC, mSource, aFireLaneA, aWorkLaneA
        // ingress directions: aFireLaneC forward forced, mSource forward forced, aFireLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, aFireLaneB, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, aFireLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 21769U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 20805U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20157U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21088U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19833U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19533U)) & W_KEY1], 35U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19220U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 21108U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererD + RotL64(aCross, 47U)) + 3199575576585871314U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 23U)) + 2533378188975571824U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 53U)) + 6819782112558312658U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 37U)) + 12690060987724798497U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 14U)) + RotL64(aCarry, 41U)) + 7088375139715629606U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 17785618677423695666U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 27U)) + 1714999280296491277U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 17611338506932491624U;
            aOrbiterB = (aWandererB + RotL64(aCross, 10U)) + 6475727359297421201U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2347744591204119530U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2739317903351401068U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15435029315209475631U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8663535261373274338U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8205245127823536479U;
            aOrbiterJ = RotL64((aOrbiterJ * 13857005110466856439U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8916510616749754516U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3944805940148512932U;
            aOrbiterF = RotL64((aOrbiterF * 18082271583211389701U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14094751253118853302U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14094299829196076311U;
            aOrbiterE = RotL64((aOrbiterE * 6370012560657108493U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3940673811518673802U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3015106523254484839U;
            aOrbiterC = RotL64((aOrbiterC * 9655401190755573379U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15404103131982599922U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1828655763233900875U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13024358077740310049U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1236981890899916502U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 18208975564570342697U;
            aOrbiterH = RotL64((aOrbiterH * 4577109989465876801U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17882273895471449661U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16196010765612713713U;
            aOrbiterD = RotL64((aOrbiterD * 15624856645134182005U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 14639250100311162559U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9139027997336903273U;
            aOrbiterB = RotL64((aOrbiterB * 1853126389565574293U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 10U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterH, 22U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + aPhaseCWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterB, 41U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 58U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 9
        // ingress from: aFireLaneD, aKeyRowReadA, aKeyRowReadB, aFireLaneC
        // ingress directions: aFireLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, aFireLaneC forward/backward random
        // cross from: mSource, aFireLaneA, aInvestLaneA, aInvestLaneB
        // cross directions: mSource backward forced, aFireLaneA backward forced, aInvestLaneA backward forced, aInvestLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 23149U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 23540U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23239U)) & W_KEY1], 58U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24188U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22708U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23524U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22646U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22281U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCarry, 56U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 9023059520606551446U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 30U)) + 662441755115638133U) + aPhaseCOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 16957253361196144712U) + aPhaseCOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 19U)) + 7840955025765308605U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 5U)) + 346855809270395799U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 47U)) + 16099139781586668343U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 3706457327118322098U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 36U)) + 12166825885547622870U;
            aOrbiterG = (aWandererD + RotL64(aCross, 57U)) + 7792658665720344200U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7128477606152986326U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11116533962780290084U;
            aOrbiterJ = RotL64((aOrbiterJ * 11993485572912492297U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10443889548568288532U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4402387036946561017U;
            aOrbiterE = RotL64((aOrbiterE * 9032964741841833277U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 13002706161178447654U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13929727277530310708U;
            aOrbiterB = RotL64((aOrbiterB * 7005639090871200285U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10949073760696935106U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15405923432006783533U;
            aOrbiterF = RotL64((aOrbiterF * 17989565878445202495U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18096057968822208905U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3032155040484574973U;
            aOrbiterD = RotL64((aOrbiterD * 448597307502544605U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17462076466907467134U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15471015427013701406U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6113474000571976139U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3549031751266594344U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14243218483842508113U;
            aOrbiterI = RotL64((aOrbiterI * 9041601306479302047U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5803147589312920032U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5549470512227427855U;
            aOrbiterG = RotL64((aOrbiterG * 12592362489263862879U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10076661824293832189U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3196799148974716550U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8183276968961467775U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 10U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 42U) + aOrbiterB) + RotL64(aOrbiterF, 5U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterD, 27U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 22U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterB, 39U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 51U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aScatter, 10U) + aOrbiterI) + RotL64(aOrbiterF, 44U)) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterG, 35U));
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererG, 54U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 10
        // ingress from: aExpandLaneA, aKeyRowReadA, aFireLaneD, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aKeyRowReadA forward forced, aFireLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aKeyRowReadB, mSource, aFireLaneC, aInvestLaneB
        // cross directions: aKeyRowReadB backward forced, mSource backward forced, aFireLaneC backward forced, aInvestLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24993U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 26625U)) & W_KEY1], 22U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25316U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((aIndex + 26967U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26573U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26680U)) & S_BLOCK1], 4U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25444U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26336U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 12U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 27U)) + 10726035965553989335U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 14U)) + 967354339530195662U) + aPhaseDOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 47U)) + 10834593005478605624U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 23U)) + 1012888282838656933U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aCross, 19U)) + 15283530351725183253U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 36U)) + 11724495956731703750U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 4288330117317505776U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 10894778070022873473U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 15563886747621617467U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 11182488628562891937U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10420140066310588580U;
            aOrbiterB = RotL64((aOrbiterB * 13898299782819948719U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11775138062167543111U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16545391898578161683U;
            aOrbiterF = RotL64((aOrbiterF * 14588306527161321535U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1550144656312299266U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14903504853138279883U;
            aOrbiterD = RotL64((aOrbiterD * 8003033561266164387U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 309935535526750396U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13991265868040011411U;
            aOrbiterG = RotL64((aOrbiterG * 2887531132228588441U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1755976294857114222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2259275858478396846U;
            aOrbiterK = RotL64((aOrbiterK * 7416165760067878161U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4838175912944552936U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12307900457200936013U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14719363144850838805U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 18025411832912225805U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 981375022769564523U;
            aOrbiterC = RotL64((aOrbiterC * 15869361544011831483U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3174014054982742562U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8119692378748963609U;
            aOrbiterE = RotL64((aOrbiterE * 3072354179707448489U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14502863160788675807U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1207582534593709516U;
            aOrbiterA = RotL64((aOrbiterA * 3045412087535529357U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 30U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterD, 14U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 42U) + aOrbiterF) + RotL64(aOrbiterK, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterA, 27U));
            aWandererF = aWandererF + (((RotL64(aScatter, 48U) + aOrbiterK) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterC, 35U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 10U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 11
        // ingress from: aExpandLaneB, aFireLaneD, aKeyRowReadB, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aFireLaneD forward forced, aKeyRowReadB forward forced, aFireLaneC forward/backward random
        // cross from: aKeyRowReadA, mSource, aExpandLaneA, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aExpandLaneA backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27765U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneD[((aIndex + 27655U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28897U)) & W_KEY1], 35U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29317U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27934U)) & W_KEY1], 12U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29094U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27809U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28972U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 56U)) + RotL64(aCarry, 3U)) + 3561491146322798260U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 11U)) + 7075025056181885339U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 9230910887904171613U;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 4119781172609908917U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 51U)) + 17155609083870983149U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 36U)) + 2423018561430181695U;
            aOrbiterG = (aWandererI + RotL64(aCross, 3U)) + 12957280305617615744U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 23U)) + 2461704174772065813U;
            aOrbiterC = (aWandererG + RotL64(aCross, 47U)) + 7907123257849391997U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7257868138318960007U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16425903703085702285U;
            aOrbiterI = RotL64((aOrbiterI * 7996935869077231999U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2990822664594079467U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5654819006718953817U;
            aOrbiterA = RotL64((aOrbiterA * 4465096036756887801U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12183676471235678779U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15026286960542123922U;
            aOrbiterG = RotL64((aOrbiterG * 17199049329995315279U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12169080607071830522U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2906296852254787499U;
            aOrbiterH = RotL64((aOrbiterH * 6754514406846040163U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3029858695410344584U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14406410317495954566U;
            aOrbiterE = RotL64((aOrbiterE * 9663780721657983421U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11048818178401163861U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13622063920319445043U;
            aOrbiterJ = RotL64((aOrbiterJ * 2516025554421589857U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2642646089141233277U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12761571777929273548U;
            aOrbiterD = RotL64((aOrbiterD * 5518252696078700127U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7753802695131502382U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8510425459525030222U;
            aOrbiterF = RotL64((aOrbiterF * 12412361423636026483U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13522645164493316722U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1437430302489702713U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14019316635365783545U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterG, 29U));
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 36U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 19U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aIngress, 46U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterD, 11U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 40U)) + aPhaseDWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 23U));
            aWandererI = aWandererI + ((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 12
        // ingress from: aExpandLaneC, aKeyRowReadA
        // ingress directions: aExpandLaneC forward forced, aKeyRowReadA forward/backward random
        // cross from: aFireLaneD, aExpandLaneA, aExpandLaneB, aKeyRowReadB
        // cross directions: aFireLaneD backward forced, aExpandLaneA backward forced, aExpandLaneB backward forced, aKeyRowReadB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 31739U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 31846U)) & W_KEY1], 14U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32254U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30848U)) & S_BLOCK1], 30U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32762U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32540U)) & W_KEY1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 12U)) + 2786079456995203065U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 7237256119153857253U) + aPhaseDOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 9310834010563647604U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 51U)) + 17361734905706517877U;
            aOrbiterD = (aWandererG + RotL64(aCross, 47U)) + 15837111231884647451U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 56U)) + 18065431964418026445U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 41U)) + 3029123922999952652U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 5166926595573507837U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 27U)) + 1918425684273807598U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 4724551751012661440U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1818014487579644390U;
            aOrbiterI = RotL64((aOrbiterI * 14904092108647864911U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6670090372241084216U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8485757110007268693U;
            aOrbiterJ = RotL64((aOrbiterJ * 11876760095108618363U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4928130251509514742U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2528788422725346792U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1855982047967756661U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2860387120895147503U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12927802338151379368U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8876144125458603029U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18029699867733207083U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13361836994951253312U;
            aOrbiterH = RotL64((aOrbiterH * 5349767426256597073U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11957294454794128079U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3755417922063414648U;
            aOrbiterG = RotL64((aOrbiterG * 13896364063651241401U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 18001157153447913032U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16214145724690286854U;
            aOrbiterE = RotL64((aOrbiterE * 5874139687703360515U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3860958772090975562U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12395621524459640173U;
            aOrbiterF = RotL64((aOrbiterF * 722817135977510161U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3402035664910754484U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2139099117325745602U;
            aOrbiterK = RotL64((aOrbiterK * 14008983756425796029U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + aPhaseDWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 39U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 26U) + aOrbiterE) + RotL64(aOrbiterF, 18U)) + aPhaseDWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Archery_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
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
    // GTwistRunTwist_B twist_loop_b (start)
    {
        // GTwistRunTwist_B twist_loop_b lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneD, aInvestLaneD, aFireLaneA, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3608U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 586U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 1021U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5247U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 2724U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 53U)) + (RotL64(aIngress, 38U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 51U)) + 5041131702736607991U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 9295010428212681446U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 42U)) + RotL64(aCarry, 37U)) + 6235875895358766017U;
            aOrbiterE = (aWandererE + RotL64(aCross, 11U)) + 2622227802531866918U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 3U)) + 3888894734834524972U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 241682012014701753U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 29U)) + 15758000422451568079U) + aPhaseEOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2061944548396976912U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8177144990755754531U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12702392689484397947U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 554978075608818497U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 250408260560714933U;
            aOrbiterK = RotL64((aOrbiterK * 1295379390497107727U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8700027645880997552U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10026130047465480902U;
            aOrbiterG = RotL64((aOrbiterG * 12417270861933696623U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9785843014096326696U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9998582683258411251U;
            aOrbiterB = RotL64((aOrbiterB * 7197956237569462269U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13817734599383455151U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6647207154174092691U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1578528131687283531U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4957715980509035719U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4994885315786213197U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5676683798126497011U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5072908311783966503U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5535039946192891515U;
            aOrbiterJ = RotL64((aOrbiterJ * 2989412783482309753U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 19U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 54U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 60U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterK, 53U));
            aWandererB = aWandererB + ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneD
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 6808U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 9337U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7533U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10713U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((aIndex + 8249U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 22U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 3339283916456813609U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 11339086426180649584U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 29U)) + 16819191669329316585U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 5U)) + 8361916937762630725U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 56U)) + 18031328374429899857U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 35U)) + 18261756894092897276U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 4250319792907645666U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 1492411503643460886U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17369549067879344180U;
            aOrbiterK = RotL64((aOrbiterK * 2947354306696216579U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 7301713524358676722U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2985193736033012535U;
            aOrbiterE = RotL64((aOrbiterE * 7473297294949338265U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14086975808140927408U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10390516547834639800U;
            aOrbiterH = RotL64((aOrbiterH * 11441293212275890819U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18205555540941493267U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16967799565443938873U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3009081009044782443U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9209505304067579944U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3522631966146762306U;
            aOrbiterA = RotL64((aOrbiterA * 3441982898533162599U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8811497120829041188U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14707301680850257294U;
            aOrbiterJ = RotL64((aOrbiterJ * 11383709499376464085U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10080595991787801029U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6822892187784299166U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7417016898027778287U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterC, 37U));
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 14U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneA
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12789U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 14648U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 11177U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11484U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12809U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 13374U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 47U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererC + RotL64(aScatter, 11U)) + 4204560462077827182U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 6572370199668594039U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 15958999876732622825U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 29U)) + 9969349486879280377U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aScatter, 5U)) + 15450238998293956181U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 9128619863683138259U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 44U)) + 5691270563628979565U) + aPhaseEOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5901029710568933106U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10442738941988588834U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7386621444831603817U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3508116020325721993U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13221917083569767259U;
            aOrbiterI = RotL64((aOrbiterI * 6845108555710135357U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11627915460377128176U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17858261365514253433U;
            aOrbiterC = RotL64((aOrbiterC * 7535577636975884641U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4294837988806295989U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11242915481585070249U;
            aOrbiterF = RotL64((aOrbiterF * 17540688242763829319U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13030663829236027109U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7451948220723185149U;
            aOrbiterA = RotL64((aOrbiterA * 5191778587712222029U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5575508866505031037U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5161096033789876794U;
            aOrbiterB = RotL64((aOrbiterB * 16843827915802461797U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3980482740649505122U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11188906150207270241U;
            aOrbiterE = RotL64((aOrbiterE * 408550837615188413U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterA, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 41U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 27U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21064U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((aIndex + 19754U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19991U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21442U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21120U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 21262U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 51U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 23U)) + 15910560457440369082U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 29U)) + 17953072986407436888U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 15446940721193538669U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 3020785262774422009U;
            aOrbiterC = (aWandererB + RotL64(aCross, 43U)) + 7001288645424994404U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 60U)) + 13385250665458462689U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 4841895644623005949U) + aPhaseEOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13053476783239482065U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 641996979335975244U;
            aOrbiterB = RotL64((aOrbiterB * 3697673197256549833U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16211238020928688299U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12715448751323279480U;
            aOrbiterK = RotL64((aOrbiterK * 2116880429675303291U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17784406727699995290U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16626339815786580778U;
            aOrbiterI = RotL64((aOrbiterI * 13940754474750138041U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9035070625716345139U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6085848172494001945U;
            aOrbiterG = RotL64((aOrbiterG * 10405728912339646693U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1177103851507561053U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2281901691017816407U;
            aOrbiterD = RotL64((aOrbiterD * 3142197009403602497U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9040984343694325070U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13334258224023902365U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4782523727707164869U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1079824790138592518U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14024082692012948652U;
            aOrbiterC = RotL64((aOrbiterC * 3219489374333737903U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 3U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 51U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 19U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 27U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 54U) + aOrbiterJ) + RotL64(aOrbiterG, 58U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 5
        // ingress from: aOperationLaneB, aOperationLaneA, aExpandLaneB
        // ingress directions: aOperationLaneB forward forced, aOperationLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aExpandLaneC, aInvestLaneC, aInvestLaneD
        // cross directions: aExpandLaneC backward forced, aInvestLaneC backward forced, aInvestLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26372U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((aIndex + 27089U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23955U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23263U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22068U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 25393U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 60U)) + (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aScatter, 57U)) + 3970829908171131502U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 21U)) + 7040283759419531991U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 11856292169397052901U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 819598588791819022U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 47U)) + 2176451710970866848U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 4U)) + RotL64(aCarry, 5U)) + 6454704928613390494U) + aPhaseEOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 11U)) + 11792122387218053841U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9254780213489752211U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16591812589999846482U;
            aOrbiterI = RotL64((aOrbiterI * 5425771603523423167U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1471246223935074832U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1424843083106386453U;
            aOrbiterF = RotL64((aOrbiterF * 15020536982657410783U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1856469958050891629U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6331743690452052712U;
            aOrbiterE = RotL64((aOrbiterE * 15327924647897459645U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10351075711345476487U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9518585245330480185U;
            aOrbiterJ = RotL64((aOrbiterJ * 3792179827396760391U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17787514620244712033U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14182328067398162557U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18107337388659070197U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12798088948801072444U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9563215159275202323U;
            aOrbiterB = RotL64((aOrbiterB * 7058145016617349141U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9904919772580498232U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16579777394992143043U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10516761340320196661U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterF, 4U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 22U) + RotL64(aOrbiterI, 29U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterI, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterC, 23U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 6
        // ingress from: aOperationLaneC, aExpandLaneA, aExpandLaneB
        // ingress directions: aOperationLaneC forward forced, aExpandLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneB, aOperationLaneA, aInvestLaneD
        // cross directions: aOperationLaneB backward forced, aOperationLaneA backward forced, aInvestLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27420U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 31435U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 31113U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27569U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29034U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 28919U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 52U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aScatter, 35U)) + 12669015908335980355U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 43U)) + 5438715179868613192U;
            aOrbiterF = (aWandererC + RotL64(aCross, 29U)) + 13172104448184536460U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 20U)) + 13421421503244744803U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 13327113302994856582U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 4671768205922454413U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 5355759962838579929U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6691720614265406851U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7063906424700911378U;
            aOrbiterF = RotL64((aOrbiterF * 17091734375516280675U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17328616394166672263U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1542940602574207068U;
            aOrbiterD = RotL64((aOrbiterD * 8981679306319627975U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7203866278803132454U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 993485696233139264U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11609009908810366447U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15659679028507488331U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 18321361454094675842U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3966860765622641843U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9633319822696783352U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3496559332232402963U;
            aOrbiterJ = RotL64((aOrbiterJ * 7772060229838162977U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1918349708324205526U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7701088402761359134U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9649485438465644795U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6006824348814439686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 18088375375347012557U;
            aOrbiterK = RotL64((aOrbiterK * 12801082943086128385U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterC, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 34U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Archery_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB, aSnowLaneA, aInvestLaneA, aInvestLaneD, aSnowLaneB, aExpandLaneD, aWorkLaneA, aInvestLaneB, aWorkLaneB, aExpandLaneC, aWorkLaneC, aExpandLaneA
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2603U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 4287U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 3864U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4974U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1084U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3687U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 5U)) + 8506388683755208267U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 47U)) + 2179323259055019735U;
            aOrbiterK = (aWandererE + RotL64(aCross, 44U)) + 3345902531140983016U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 57U)) + 17456139311481306584U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 14587864088462311164U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 13U)) + 13178947246650647057U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 51U)) + 12866578138946916962U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 38U)) + 13098524333655118173U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 29U)) + 15451329483787541982U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 9494299579678389385U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 15581954810375490643U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4487042505730624892U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2774455928791636186U;
            aOrbiterK = RotL64((aOrbiterK * 15847933919136777451U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12435319582397755819U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10077180055177766823U;
            aOrbiterC = RotL64((aOrbiterC * 3924363471701748703U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10391963896910956455U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6149237416725301794U;
            aOrbiterH = RotL64((aOrbiterH * 10115917698918612823U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15673402771629639978U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14729117178956592426U;
            aOrbiterG = RotL64((aOrbiterG * 9070464269215820531U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14492001279368870240U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6278248084483259952U;
            aOrbiterB = RotL64((aOrbiterB * 16731228350971263873U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15727518866499740411U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8652631010810965473U;
            aOrbiterA = RotL64((aOrbiterA * 9508484121620912715U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13660890300188313775U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14699253534935936300U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3978135617259934869U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1621689916308271346U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5651399428852950385U;
            aOrbiterJ = RotL64((aOrbiterJ * 12220143634120124133U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9833573729127477238U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11171647423058940388U;
            aOrbiterF = RotL64((aOrbiterF * 9692915620701425697U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10346908196429120039U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11972183669378621435U;
            aOrbiterE = RotL64((aOrbiterE * 12364429258926549335U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11063215816236490488U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8506388683755208267U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11514304191652750181U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 18U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterH, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 46U) + aOrbiterF) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterG, 48U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 27U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterF, 13U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 6U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterK, 37U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 26U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneA
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6983U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneC[((aIndex + 9247U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8773U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9026U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6055U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7006U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 8735U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 28U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererF + RotL64(aCross, 44U)) + RotL64(aCarry, 41U)) + 8375305456876489425U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 16193562952772453047U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 3U)) + 18088652458594816223U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 19U)) + 767344788620249944U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 53U)) + 7705194930396368752U) + aPhaseFOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 51U)) + 3829736891311272834U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 23U)) + 9881681671347640061U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 56U)) + 1721196560190164264U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 21U)) + 3002652618388454213U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 9811621464004005202U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 47U)) + 5652598941069986530U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6250499348327316328U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16025054277615264530U;
            aOrbiterH = RotL64((aOrbiterH * 16446892258704281903U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13800298546867243172U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12256104592865905782U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16983140179497142713U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17817225416918329229U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17738671327352776217U;
            aOrbiterE = RotL64((aOrbiterE * 393488251327705063U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6816031224188400541U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16989563985059237014U;
            aOrbiterK = RotL64((aOrbiterK * 8677884225771717797U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16891524847268207549U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1833508573940405571U;
            aOrbiterF = RotL64((aOrbiterF * 9709196587703979539U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12729999421507068973U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6839758643521968957U;
            aOrbiterD = RotL64((aOrbiterD * 16350557395881283975U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8524167125469267428U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14741523560290472617U;
            aOrbiterG = RotL64((aOrbiterG * 4367850822282205897U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10983798459868424892U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5649250846622078964U;
            aOrbiterB = RotL64((aOrbiterB * 7149612714806023987U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8587302028325090061U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17457129226030333666U;
            aOrbiterA = RotL64((aOrbiterA * 18107356450566915215U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15600113588474915690U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 6595247491374683783U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1432432381540098765U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13246325856585534283U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8375305456876489425U;
            aOrbiterC = RotL64((aOrbiterC * 8331406038795786099U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 34U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 3U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 56U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 53U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 44U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterK, 43U));
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 6U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 23U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneD
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14273U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((aIndex + 11246U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11694U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12526U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((aIndex + 12671U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 14U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aScatter, 43U)) + 9774364261626083532U;
            aOrbiterB = (aWandererH + RotL64(aCross, 20U)) + 18059001521926116420U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 13U)) + 10615626210406381148U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 11U)) + 10536484278007898620U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 13320663045139972700U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 17127001787268166583U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 35U)) + 16742574590844166551U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 41U)) + 8347719720758228053U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 26U)) + 13502468705946051986U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 3512687886188904904U;
            aOrbiterC = (aWandererE + RotL64(aCross, 29U)) + 495660316165795934U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5092722552034477356U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15641128019608284015U;
            aOrbiterH = RotL64((aOrbiterH * 3621036395703527059U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15421873776811085458U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17978775513204574125U;
            aOrbiterD = RotL64((aOrbiterD * 18359600395119440183U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16617179197537669849U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1931805387534012528U;
            aOrbiterG = RotL64((aOrbiterG * 3400139345857733775U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9544923119559308431U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12930999400470173353U;
            aOrbiterK = RotL64((aOrbiterK * 16791006919271490005U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13673733276226249890U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2032263473309124738U;
            aOrbiterJ = RotL64((aOrbiterJ * 3088728329261360607U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14868502349358414206U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10116495537187552321U;
            aOrbiterI = RotL64((aOrbiterI * 1380512121796709469U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5341113995358179244U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8415417980279705731U;
            aOrbiterC = RotL64((aOrbiterC * 8521501372683793821U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2462819265072352463U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7657062767608441931U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15554638801273540163U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8153420530633265789U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10990681417675210534U;
            aOrbiterF = RotL64((aOrbiterF * 1928509513380702895U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17035995983178569271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2806563871848226777U;
            aOrbiterA = RotL64((aOrbiterA * 4137935663733587867U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6570698907081812011U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9774364261626083532U;
            aOrbiterB = RotL64((aOrbiterB * 1766375419340392741U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterH, 11U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterC, 18U));
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 23U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterH, 29U));
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 56U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + aPhaseFWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 56U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aInvestLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19152U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneA[((aIndex + 18867U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18239U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19316U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19696U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aScatter, 21U)) + 15383045568644941552U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 60U)) + 17452811657750910067U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 29U)) + 15660117718455155603U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 10396441207743665753U;
            aOrbiterE = (aWandererE + RotL64(aCross, 5U)) + 3708971058200841442U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 14U)) + 7000673057768598750U) + aPhaseFOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 23U)) + 9886354469011131596U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 16018065329058043467U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 5024756166109352320U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 53U)) + 6587818720728886652U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 27U)) + 3652672354944162319U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6307315649915348048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16405347331742979258U;
            aOrbiterJ = RotL64((aOrbiterJ * 7183142442906743699U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5427299664054601957U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4983381733483185898U;
            aOrbiterD = RotL64((aOrbiterD * 14646556236306407673U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10182995521328377487U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8694282877540593550U;
            aOrbiterK = RotL64((aOrbiterK * 14614602561910403893U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4085927978153269932U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6176195962815240877U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16792916528959579875U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6966742100601433005U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9920952446921247521U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1879821050131820933U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11958734477518336014U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2058335903640404380U;
            aOrbiterF = RotL64((aOrbiterF * 6986170159285417789U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 77366119537297816U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12072894199692855000U;
            aOrbiterB = RotL64((aOrbiterB * 9083781120514635987U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11874297832446385377U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13715562531763053196U;
            aOrbiterG = RotL64((aOrbiterG * 12822488258322963187U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13664465415354326653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10365386643010882315U;
            aOrbiterA = RotL64((aOrbiterA * 3687934567254955761U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2003863843075564853U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8864134110143237364U;
            aOrbiterC = RotL64((aOrbiterC * 4586162015675320985U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8055736412403126985U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15383045568644941552U;
            aOrbiterH = RotL64((aOrbiterH * 5175405553995854715U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 37U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterE, 58U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 43U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 50U) + aOrbiterK) + RotL64(aOrbiterA, 35U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 56U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 13U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 41U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 53U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneC
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23721U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((aIndex + 23906U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23083U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24007U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 24291U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 40U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 23U)) + 9220392006207660113U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 13U)) + 11305018553489132882U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 27U)) + 5860373868073513684U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 43U)) + 12319586170883987589U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 21U)) + 14072333614354649021U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 48U)) + 9332158529453194608U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 3860569321145958686U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 8119005668901240093U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 29U)) + 13918259792880333239U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 36U)) + RotL64(aCarry, 47U)) + 6938856216758228704U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 19U)) + 3960905839118710604U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6043879193734253929U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15691425268831319195U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7189195135654636271U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14912209933584715274U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16180183395910618923U;
            aOrbiterF = RotL64((aOrbiterF * 3942858974766467849U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4966642362507707776U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6962226782462822861U;
            aOrbiterE = RotL64((aOrbiterE * 3647802407741095419U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12409120845092026295U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2302946450253872465U;
            aOrbiterK = RotL64((aOrbiterK * 7099576330777297911U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16118304388937163838U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15968419034359049422U;
            aOrbiterB = RotL64((aOrbiterB * 11736207775827080165U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17098982091525008231U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10298979200690822062U;
            aOrbiterA = RotL64((aOrbiterA * 12620028874653521945U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 552826643694256437U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11786560990790695378U;
            aOrbiterH = RotL64((aOrbiterH * 11190309640069208311U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13730399230389329793U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17614226859252305432U;
            aOrbiterI = RotL64((aOrbiterI * 2640019643570222977U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1062738267846296283U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13959480457644980835U;
            aOrbiterC = RotL64((aOrbiterC * 1194145909157002977U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4635071137794189167U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13374502212707796180U;
            aOrbiterJ = RotL64((aOrbiterJ * 129680788767298945U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 11479902881487238033U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9220392006207660113U;
            aOrbiterD = RotL64((aOrbiterD * 1437457810224888809U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 6U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 39U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterC, 58U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 37U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 18U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterG, 35U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 54U) + RotL64(aOrbiterI, 21U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 44U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29542U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 31736U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29398U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27857U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28224U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 47U)) + 15910560457440369082U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 6U)) + 17953072986407436888U) + aPhaseFOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 39U)) + 15446940721193538669U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 3020785262774422009U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 7001288645424994404U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 13385250665458462689U) + aPhaseFOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 21U)) + 4841895644623005949U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 57U)) + 13053476783239482065U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 19U)) + 641996979335975244U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 14U)) + 16211238020928688299U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 29U)) + 12715448751323279480U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17784406727699995290U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16626339815786580778U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13940754474750138041U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9035070625716345139U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6085848172494001945U;
            aOrbiterC = RotL64((aOrbiterC * 10405728912339646693U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1177103851507561053U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2281901691017816407U;
            aOrbiterD = RotL64((aOrbiterD * 3142197009403602497U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9040984343694325070U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13334258224023902365U;
            aOrbiterB = RotL64((aOrbiterB * 4782523727707164869U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1079824790138592518U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14024082692012948652U;
            aOrbiterA = RotL64((aOrbiterA * 3219489374333737903U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2966776524421278970U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5510281854029308547U;
            aOrbiterE = RotL64((aOrbiterE * 9275402927591867297U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7126632329316720048U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1476827035602733472U;
            aOrbiterJ = RotL64((aOrbiterJ * 2217671289726794033U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6470212302133184965U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4172257438373147415U;
            aOrbiterG = RotL64((aOrbiterG * 4449314239630366533U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11445212164224402184U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1779825157413363285U;
            aOrbiterF = RotL64((aOrbiterF * 15393425495668107155U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7561888690947559866U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14440989817038856852U;
            aOrbiterK = RotL64((aOrbiterK * 5799807036762859679U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10618807050937260814U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15910560457440369082U;
            aOrbiterI = RotL64((aOrbiterI * 10902491688248464465U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 10U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 43U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterE, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 36U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterI, 41U));
            aWandererF = aWandererF + (((RotL64(aIngress, 24U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterH, 27U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterB, 6U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Archery_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4141U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 385U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 3914U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5438U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2347U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4709U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererA + RotL64(aScatter, 14U)) + RotL64(aCarry, 23U)) + 11700815697312060726U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 11808423452327465441U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 8670503858631730886U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 35U)) + 2400061067991988544U) + aPhaseGOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 23U)) + 16163118178366229686U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3280178595904941068U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3298683600817047727U;
            aOrbiterE = RotL64((aOrbiterE * 9865649058799255343U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16321624053445183574U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 6730229877611375225U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2022290495153519279U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10162830636713641322U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15646771327759599256U;
            aOrbiterB = RotL64((aOrbiterB * 15333053762177144775U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 14841751262270544102U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9545541117228834895U;
            aOrbiterH = RotL64((aOrbiterH * 11529769874752969377U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14676615635857599982U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1231768638470558855U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2716808508509014677U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 19U)) + aOrbiterG) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterK, 37U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 40U) + aOrbiterH) + RotL64(aOrbiterK, 46U)) + aPhaseGWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9208U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 9581U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11409U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16245U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13778U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 9288U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 37U)) + (RotL64(aIngress, 20U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 14214886793361825363U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 13U)) + 17267959031078766320U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aCross, 5U)) + 16436067429484887644U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 34U)) + RotL64(aCarry, 37U)) + 9885951769332633820U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 12971711341813893304U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 199970353398450154U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1237341696444162094U;
            aOrbiterF = RotL64((aOrbiterF * 2850125642665515751U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7991128854417613360U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 14809029847149045833U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5940857360838299105U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2559509556915775947U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14336829730147834160U;
            aOrbiterI = RotL64((aOrbiterI * 15103242520064900873U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8853631886733610440U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13346159398673246914U;
            aOrbiterH = RotL64((aOrbiterH * 13660497151446983393U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12121095718571872976U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16239781125815589804U;
            aOrbiterG = RotL64((aOrbiterG * 5157009090454962231U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 36U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterG, 13U));
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 5U)) + aOrbiterH) + aPhaseGWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 24U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 22U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19554U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 20560U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18528U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21694U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22617U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 20725U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 43U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 5U)) + 12136097566601676613U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 7969431322248040056U;
            aOrbiterE = (aWandererF + RotL64(aCross, 60U)) + 10530676021510553889U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 8740777303075445264U) + aPhaseGOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 13249434169895564739U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 15529577005925628472U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 344627093687331562U;
            aOrbiterE = RotL64((aOrbiterE * 3226087371456521323U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8824277416519988893U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5636276438449709875U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 222817930773618893U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2079413361031851552U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7807998179168655561U;
            aOrbiterH = RotL64((aOrbiterH * 961456853699784753U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13589392896232029112U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10733011474804473996U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 361749145931578805U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15934162328347805968U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7573511217796245232U;
            aOrbiterB = RotL64((aOrbiterB * 10694563909931636155U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 48U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + aPhaseGWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24680U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 28069U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 25077U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30431U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26474U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28458U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 18255347001097480328U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 37U)) + 13679246790311505735U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 20U)) + 10565839529765027116U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 14327172566224769901U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 16239024612038195174U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13800012174212131890U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13900288860157577583U;
            aOrbiterJ = RotL64((aOrbiterJ * 13177682776510523095U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4144386119777112740U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3154558262670631372U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13236911910092437063U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7456728543137614001U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11709519851158935384U;
            aOrbiterF = RotL64((aOrbiterF * 7016689518570071587U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 15607438907832240304U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 9276575329661725624U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8879744070762412745U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6459435969129449226U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6442382118416542275U;
            aOrbiterH = RotL64((aOrbiterH * 2921027306686588233U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererB = aWandererB + ((RotL64(aScatter, 46U) + aOrbiterB) + RotL64(aOrbiterJ, 4U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 35U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Archery_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7067U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 3613U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 1163U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4383U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 898U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 6380U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererK + RotL64(aCross, 53U)) + 16183871922837164759U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 44U)) + 7002058258090219055U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 5650868611888303705U) + aPhaseHOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 11899839660943876690U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 15349649504488111111U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14060149569086744970U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12920917574225030112U;
            aOrbiterJ = RotL64((aOrbiterJ * 6552626684290469367U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2831994965175330135U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 18312543585028439192U;
            aOrbiterA = RotL64((aOrbiterA * 11618182708195744321U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11657562205118394239U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10850792819281246052U;
            aOrbiterG = RotL64((aOrbiterG * 10663100544207879337U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17810371216216125323U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7963413941144223128U;
            aOrbiterC = RotL64((aOrbiterC * 534217972450595401U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5498715358793875584U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9256727548911651373U;
            aOrbiterK = RotL64((aOrbiterK * 10498848323914000989U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 42U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterK, 27U)) + aPhaseHWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterA, 39U));
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 12U) + aOrbiterK) + RotL64(aOrbiterA, 47U)) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9475U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 9166U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 8293U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12607U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8254U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14531U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 50U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aIngress, 53U)) + 10726035965553989335U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 967354339530195662U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 10834593005478605624U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 30U)) + RotL64(aCarry, 53U)) + 1012888282838656933U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 39U)) + 15283530351725183253U) + aPhaseHOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11724495956731703750U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4288330117317505776U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2738997410474076757U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10894778070022873473U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15563886747621617467U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17884709931569040065U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11182488628562891937U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10420140066310588580U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13898299782819948719U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11775138062167543111U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16545391898578161683U;
            aOrbiterH = RotL64((aOrbiterH * 14588306527161321535U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 1550144656312299266U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14903504853138279883U;
            aOrbiterK = RotL64((aOrbiterK * 8003033561266164387U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 38U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 51U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aIngress, 34U) + RotL64(aOrbiterC, 11U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 28U)) + aPhaseHWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererK, 46U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23573U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 24456U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 18839U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22633U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19496U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 21668U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 6521330037475130256U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 12611880456055428940U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 35U)) + 12061611078130934708U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 1558112410801116984U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 22U)) + 10509115227850160786U) + aPhaseHOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4045915960688792066U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1196541286513243082U;
            aOrbiterH = RotL64((aOrbiterH * 5454309408259753479U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15564991032722373702U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 4897765238703641798U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9693901276712946763U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12327429514907752733U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6189189797708711636U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9017615866338877651U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6374267075282018852U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1888758503831341439U;
            aOrbiterI = RotL64((aOrbiterI * 74387714918264257U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14956857689299491800U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14879361107223331957U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9166712966729591953U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterB, 18U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 44U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28644U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 26957U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 28175U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29671U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26169U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31481U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 3973833383430652211U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 3U)) + 5760227042747169187U) + aPhaseHOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 4923009065139227286U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 1477807307009107590U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 48U)) + 5707194514329007301U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5340439728375269724U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17080457898946572387U;
            aOrbiterI = RotL64((aOrbiterI * 17719588880215414933U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 281559150259472813U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16160633048230910560U;
            aOrbiterD = RotL64((aOrbiterD * 16883442583309073785U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9003989610509592121U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10579322462808454333U;
            aOrbiterJ = RotL64((aOrbiterJ * 100832431598087235U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15059383289528723069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10417647757852880956U;
            aOrbiterE = RotL64((aOrbiterE * 1457919230286043137U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14484665027393813330U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 12344463053485837974U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5762654194001525041U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 30U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 36U) + aOrbiterJ) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + aPhaseHWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
