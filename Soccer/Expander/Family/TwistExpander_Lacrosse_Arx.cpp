#include "TwistExpander_Lacrosse_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Lacrosse_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x954F61BE7F5B7845ULL + 0x9C9E41F160446615ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF71A2811BEBA9509ULL + 0xE3231375999011B5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA20B7235EB279423ULL + 0xBF5CC940CDA13A65ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDC4D8AF4F8E05C19ULL + 0x8628A8EB9A043305ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFA20CF586E395DCFULL + 0x878CF50670B70DA7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBE1A52DA602E7113ULL + 0xD738EBA19555A1FDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA5E0C17FBD6D4669ULL + 0xDD4733070CFE92B9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x92EDD70D6A35F0F1ULL + 0xD965D3B11CC9D663ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9B3A07F73A1B6ACDULL + 0x9FF9227F2860A445ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD313751AD8322B51ULL + 0xEEE0E43800717E92ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD2AAF7AC24105B9BULL + 0xC1C3AC28A20BEF4BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB7CABA712061B949ULL + 0x959B9CBD0F870450ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xADCBF4BC8E83C969ULL + 0xACE1443593F8E673ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA1586837EE28EF0BULL + 0xF130FB087B0FBF9DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x818CF3B4C3F5C361ULL + 0xD7C4D362A5265E38ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC1C2ED2B53FE6A49ULL + 0xDF0C4005CE147BB5ULL);
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
            aIngress = RotL64(mSource[((aIndex + 3664U)) & S_BLOCK1], 11U) ^ RotL64(pSnow[((aIndex + 2013U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 3417U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2157U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 36U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 12690502671561165478U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 17519943923428102801U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 10705515807975331385U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 5U)) + 16586447272278538179U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 35U)) + 8006560996840971798U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 37U)) + 12928600185788857701U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 28U)) + 14240723153798267172U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aScatter, 21U)) + 8636219177994872072U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 41U)) + 7586790235186467512U) + aNonceWordI;
            aOrbiterK = ((aWandererC + RotL64(aCross, 53U)) + 1103807034179512424U) + aNonceWordA;
            aOrbiterD = (aWandererK + RotL64(aScatter, 60U)) + 7547526530239498693U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8380239679344786397U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5690809173787433519U;
            aOrbiterB = RotL64((aOrbiterB * 5354724308093372953U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8390902801141804609U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3507306189192059486U;
            aOrbiterH = RotL64((aOrbiterH * 18336280496510253103U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6190745292098482871U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8065418693975056902U;
            aOrbiterJ = RotL64((aOrbiterJ * 6414621418430102589U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12111755051718111803U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7605877769709909297U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17525248694315944599U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5969794501112646237U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5127559299360591476U;
            aOrbiterA = RotL64((aOrbiterA * 4521563633438853069U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10593847754747739786U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4401750688524310121U;
            aOrbiterI = RotL64((aOrbiterI * 14265829318976633707U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6927893132508779499U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4874009978647014479U;
            aOrbiterD = RotL64((aOrbiterD * 13340466017023540755U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13146693487138744677U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3298472134223595298U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2145005258008477281U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8729305340729268734U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18347161842033439538U;
            aOrbiterC = RotL64((aOrbiterC * 7952715248988302017U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 166831495912855225U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4943633045563697271U;
            aOrbiterG = RotL64((aOrbiterG * 1809857625425000137U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2460623715340753589U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12690502671561165478U;
            aOrbiterK = RotL64((aOrbiterK * 16421139715633515623U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 30U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 38U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aCross, 42U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterE, 27U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 21U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterA, 30U));
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 23U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 10241U)) & S_BLOCK1], 28U) ^ RotL64(mSource[((aIndex + 6818U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9741U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((aIndex + 9415U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 12692813903177772178U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 7112496446691277899U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 2112247138290568813U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 27U)) + 3699421080882855947U) + aNonceWordN;
            aOrbiterF = ((aWandererG + RotL64(aCross, 21U)) + 13761832028354380922U) + aNonceWordC;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 11U)) + 9243822514887600214U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 46U)) + 6863833516853046129U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 37U)) + 8863897995943098018U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 23U)) + 13346785686701467520U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 19U)) + 15309543066305531619U) + aNonceWordD;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 14U)) + 17515530938817919111U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 760493237816424254U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7282586354117620860U;
            aOrbiterH = RotL64((aOrbiterH * 2327153408185290635U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4129706068526969105U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7020175432730888755U;
            aOrbiterI = RotL64((aOrbiterI * 10095158356907592239U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9102258982216515596U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 10822031305361453690U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 2036205056490578491U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12571477440964330246U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8436347026653095199U;
            aOrbiterK = RotL64((aOrbiterK * 17930734781213681573U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14214789872073941940U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12915911919403385001U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13161681603528031511U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15443240166233851298U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7311369180113240915U;
            aOrbiterG = RotL64((aOrbiterG * 13339195007946889423U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12976516224995960015U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7823308381434556721U;
            aOrbiterD = RotL64((aOrbiterD * 502385172763861451U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4829417661664149137U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16306394751966719700U;
            aOrbiterE = RotL64((aOrbiterE * 5294376579588592157U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16769868341852572677U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7107433163189177642U;
            aOrbiterF = RotL64((aOrbiterF * 5279050651595743649U), 53U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 11896784111967113871U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 389626690429371003U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10665914532159182181U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8226849597052979358U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 12692813903177772178U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17909062471564422847U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 42U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 29U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterH, 37U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterI, 53U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterK, 48U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 27U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 12059U)) & S_BLOCK1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15398U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 12833U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 13142U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 11U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 46U)) + 3448371607470865612U) + aNonceWordC;
            aOrbiterH = (aWandererB + RotL64(aIngress, 3U)) + 3743742913651580573U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 21U)) + 13069491287948807280U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aWandererD + RotL64(aCross, 41U)) + 16872779275586545632U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 11U)) + 17945792656755062795U) + aNonceWordJ;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 57U)) + 18199747196793731853U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 15953311878379809513U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 941268763494588338U;
            aOrbiterD = (aWandererG + RotL64(aCross, 19U)) + 10090221530365796809U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 37U)) + 8335698093307607001U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 26U)) + RotL64(aCarry, 53U)) + 6147498804734306100U) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5980246079567570090U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 4152167624425912978U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 10019421651535123573U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14990418790239735916U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3418668387496597219U;
            aOrbiterH = RotL64((aOrbiterH * 12814077238529863119U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4206650904177199425U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3905470780938996069U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16030122739273137005U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9968672788233080924U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 602258075661864866U;
            aOrbiterD = RotL64((aOrbiterD * 2615726693066300065U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17751667243048041383U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2414054413585296027U;
            aOrbiterJ = RotL64((aOrbiterJ * 1049512574773201893U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6523322402744047752U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6729901917767398779U;
            aOrbiterC = RotL64((aOrbiterC * 8039939871405367139U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11460169185076814539U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7559640379553110573U;
            aOrbiterE = RotL64((aOrbiterE * 9864654321914036135U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17271150091827475028U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3541809324556914646U;
            aOrbiterK = RotL64((aOrbiterK * 12655168871428868639U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10332471447306597185U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12580133010006951091U;
            aOrbiterF = RotL64((aOrbiterF * 1159183486084705865U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17333553613777910945U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14179392055698682109U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17675559451285279251U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3996830751779338356U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3448371607470865612U;
            aOrbiterA = RotL64((aOrbiterA * 5375529914102609947U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 58U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + aNonceWordD);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterD, 51U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 4U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 43U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 20U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 11U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 47U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aCross, 6U) + aOrbiterI) + RotL64(aOrbiterJ, 41U));
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 53U)) + aOrbiterH) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 58U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 39U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 20189U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18998U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 17116U)) & S_BLOCK1], 30U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 16970U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 16528U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 24U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 47U)) + 7960325128608297381U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 42U)) + RotL64(aCarry, 29U)) + 12773836012104052042U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 5U)) + 3173972621347773016U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 3708401356314308171U;
            aOrbiterF = (aWandererD + RotL64(aCross, 39U)) + 950774285720019449U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 13U)) + 4170092315705438265U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 21U)) + 17000449130864980747U) + aNonceWordD;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 51U)) + 8793910540062893860U;
            aOrbiterK = (aWandererG + RotL64(aCross, 27U)) + 520277969543516469U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 29U)) + 12762214857389827271U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aScatter, 58U)) + RotL64(aCarry, 11U)) + 2932451184340207695U) + aNonceWordP;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11062179998786293839U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 7919119215271524178U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 9053677007180081359U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1774988449597115155U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3799792889466518953U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17512791286490623455U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1815062051307896589U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15260373951371654483U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 2208604434669491625U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12867546628945676853U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7772820973895846946U;
            aOrbiterK = RotL64((aOrbiterK * 7581704643538761985U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14213957831821966834U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16561105721170419454U;
            aOrbiterC = RotL64((aOrbiterC * 2540533987337175367U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16556502948339949526U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9706742922075498974U;
            aOrbiterH = RotL64((aOrbiterH * 8527361328901355457U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13455756934917486016U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9107769876332723454U;
            aOrbiterB = RotL64((aOrbiterB * 1722386100852683783U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15793099079168487016U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7968278803691283365U;
            aOrbiterJ = RotL64((aOrbiterJ * 11644765391940099387U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15068302421261745111U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11373111908765197862U;
            aOrbiterE = RotL64((aOrbiterE * 17756438368103196771U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6362100123286229887U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 528778333872160609U;
            aOrbiterI = RotL64((aOrbiterI * 17377710146983314215U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6116442644744391285U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7960325128608297381U;
            aOrbiterA = RotL64((aOrbiterA * 17826511435509927061U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 10U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterG, 19U));
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 24U)) + aOrbiterG) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 5U)) + aOrbiterK) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aCross, 6U) + RotL64(aOrbiterE, 60U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterH, 53U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 24721U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 26173U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(pSnow[((aIndex + 27090U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 23346U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27045U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26044U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 15813325389431304548U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 43U)) + 2223874171125403602U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 10U)) + 5510483568496824130U) + aNonceWordN;
            aOrbiterG = (aWandererC + RotL64(aCross, 39U)) + 15474152493495661876U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 23U)) + 16846339705130829195U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 1289670576865739669U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 29U)) + 18017354919647006944U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 4U)) + 8539685539928984921U;
            aOrbiterA = (aWandererE + RotL64(aCross, 57U)) + 3333721400836704048U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 21U)) + 2261560416623815491U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 4377786131746816567U) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 18047393176583722719U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8184724021940434631U;
            aOrbiterF = RotL64((aOrbiterF * 9800116157750921119U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10469895939183324807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14543391765109879223U;
            aOrbiterK = RotL64((aOrbiterK * 4817987697437667225U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5757225781746158178U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3539000495894022869U;
            aOrbiterB = RotL64((aOrbiterB * 1032298408884695925U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11288971092707065923U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 2761384065186568294U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3323838837427471051U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7120580145300417101U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6977246291769372866U;
            aOrbiterI = RotL64((aOrbiterI * 15170353875184253779U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 17625434527765525937U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3299714663631376190U;
            aOrbiterG = RotL64((aOrbiterG * 6532628892760776767U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10331889953489885250U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8550932256881727932U;
            aOrbiterE = RotL64((aOrbiterE * 13085531621192583719U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11151195711186126257U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2552002192824926483U;
            aOrbiterC = RotL64((aOrbiterC * 9754056316698523849U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8038115194286715268U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16594489591573505305U;
            aOrbiterD = RotL64((aOrbiterD * 1241387574663818247U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13476964484361081681U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2136330439951908303U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12728359054660550527U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 231990686776499700U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15813325389431304548U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 9155088985405261637U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 6U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterC, 50U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterF, 3U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterK) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 23U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterC, 26U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterD, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 31643U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((aIndex + 28897U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28239U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28796U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 30566U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 30008U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 27U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 53U)) + 4773124477323378268U) + aNonceWordB;
            aOrbiterG = (aWandererI + RotL64(aScatter, 51U)) + 16848723289435796005U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 26U)) + RotL64(aCarry, 37U)) + 13846642134917107058U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 23U)) + 6472057872482789939U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 2747019500690707226U) + aNonceWordC;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 41U)) + 9003965289739733880U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 19U)) + 3013390651936257377U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 46U)) + RotL64(aCarry, 27U)) + 3331004709895625067U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 3U)) + 15355010435553517129U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 29U)) + 7709870658004280052U) + aNonceWordP;
            aOrbiterJ = (aWandererA + RotL64(aCross, 5U)) + 13568728443963926564U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12409548853419307131U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 969183352023661537U;
            aOrbiterI = RotL64((aOrbiterI * 5549220554838837145U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15370309834426476775U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3896803894396631184U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 11018830202891911603U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10848873633291935766U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12885336509190543440U;
            aOrbiterC = RotL64((aOrbiterC * 1487357252619221365U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8252290890093788010U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9201553615601641350U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 420321130559162915U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14014209645503188472U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4015071464301844550U;
            aOrbiterD = RotL64((aOrbiterD * 17444195018239904971U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16173085647514027347U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16916627014974363360U;
            aOrbiterF = RotL64((aOrbiterF * 7699587344277490953U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1591680303404522110U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16499606051269327916U;
            aOrbiterE = RotL64((aOrbiterE * 814405848002794813U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6932673635509444619U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8745681160108707944U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 14565255558668084787U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10387263947888920455U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2553335462317280031U;
            aOrbiterA = RotL64((aOrbiterA * 7253573275397985211U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17449861295444216249U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15716408844914738774U;
            aOrbiterJ = RotL64((aOrbiterJ * 10132631423215542589U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16974370193820578179U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4773124477323378268U;
            aOrbiterK = RotL64((aOrbiterK * 8982190762960590543U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 18U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 44U) + aOrbiterE) + RotL64(aOrbiterF, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 58U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 39U)) + aOrbiterB) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 50U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterD, 37U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterK, 41U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Lacrosse_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC362FF73C50C34EBULL + 0x9861430AF4250AD8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9D449782837524C3ULL + 0xC8723A76BC61D1AEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF56A9D8DD603099FULL + 0xFEE223C15115B766ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8BC3AFF10A78C287ULL + 0xA83C06A8F97400EEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE8A7B21D11CD8A55ULL + 0xB88D6031E06E7D8DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBD36B812ADCB1ABBULL + 0xD811711F32C2956EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEC1EAC943511F183ULL + 0xC3B554072418E87CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC325919AE276777FULL + 0xF58AA059E509E6B6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB559E4FB1F888F3DULL + 0x86BB2F68ED34D545ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA3B11A047B646C15ULL + 0x94A433F763151E87ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE8F70DD053950F83ULL + 0xB96F0DC5D823ECDBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC69550613204BD91ULL + 0x8F33A55CD8DD1231ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBF72EEA57F6A4AD7ULL + 0xA40C2F09897B179DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA32341D1A34723DDULL + 0xC31CF90E243B5B40ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF43035F689DD44AFULL + 0x8F8C4ADA291031B1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBA3630447F764273ULL + 0xDD1257EF37C37B0DULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 1905U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6240U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 5100U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((aIndex + 8032U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 12U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 13481227414590594621U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 48U)) + 17425964381118918026U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aPrevious, 39U)) + 4792004356135956581U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 11926849936000639098U) + aNonceWordP;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 990697329347742142U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 23U)) + 9307721505373076588U) + aNonceWordK;
            aOrbiterB = (aWandererA + RotL64(aCross, 53U)) + 17605732738841908719U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 60U)) + 13110764518634187439U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aWandererH + RotL64(aCross, 19U)) + 17970109897810645911U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10273133817644703654U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11239046688920468137U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5197802934333553327U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8355821483275763145U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 15522151127786049345U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 4844278537850520413U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5381663179722418112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9551368011768104906U;
            aOrbiterF = RotL64((aOrbiterF * 14202470972121732997U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16264476585232221270U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7721417776432288282U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10267770327791051869U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 339418090653475277U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3247926250495935511U;
            aOrbiterH = RotL64((aOrbiterH * 16824669543765729097U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3390560045236418590U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3894024951542543635U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10599637790900418767U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3878539166189668154U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5617705593218220843U;
            aOrbiterI = RotL64((aOrbiterI * 82771190372750823U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12320861089148474544U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14943790251625519550U;
            aOrbiterB = RotL64((aOrbiterB * 13758322022902008313U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18119213517612562775U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1413193144229486646U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14562375280658115687U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 6U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 13U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 43U)) + aOrbiterE) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterK, 18U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + aNonceWordI) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 30U) + aOrbiterI) + RotL64(aOrbiterJ, 22U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13588U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneB[((aIndex + 15129U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15027U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15359U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12380U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 21U)) + (RotL64(aIngress, 38U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 18191288703716505885U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 39U)) + 9824014524910417136U) + aNonceWordD;
            aOrbiterH = (aWandererE + RotL64(aScatter, 6U)) + 11953012029254917548U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 29U)) + 6297568011027199089U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 53U)) + 2576999400457367975U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 11U)) + 13176139160575558254U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 9978408174563621810U) + aNonceWordB;
            aOrbiterB = ((aWandererA + RotL64(aCross, 20U)) + RotL64(aCarry, 53U)) + 16765834875061607142U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 47U)) + 16534507305459121344U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3114710944346151807U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10240517868726718592U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 4645691562915606463U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10721450637990777883U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16689590768796583952U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 3046344179729901637U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2427422768928450209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13495584061816457831U;
            aOrbiterK = RotL64((aOrbiterK * 6670984773768885119U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7058636403765106682U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9897341853944713767U;
            aOrbiterF = RotL64((aOrbiterF * 14286816859999869231U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17749559755733386064U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12515645083926326659U;
            aOrbiterI = RotL64((aOrbiterI * 6582878478865838245U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2625692458813609962U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10596240255026143019U;
            aOrbiterE = RotL64((aOrbiterE * 11605800195771080135U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12374290338067865540U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1507386663796330249U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1210241080424446087U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9288099549484146726U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15159312464747000702U;
            aOrbiterD = RotL64((aOrbiterD * 500055502081347757U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14998608679505446229U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17625038109437732009U;
            aOrbiterB = RotL64((aOrbiterB * 14785862243019841689U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 40U)) + aOrbiterF) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterF, 57U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 47U)) + aOrbiterE) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterD, 21U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 27U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 52U)) + aOrbiterG) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20665U)) & S_BLOCK1], 22U) ^ RotL64(aFireLaneD[((aIndex + 22422U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 16998U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21657U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18304U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 16840U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 12046647397183218524U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 26U)) + RotL64(aCarry, 27U)) + 2760779375026461991U) + aNonceWordJ;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 3U)) + 13735454443176855650U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 43U)) + 4370377000586647724U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 14566322384189969094U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 57U)) + 5056565959818422786U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 53U)) + 8795403810686579209U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 30U)) + 9625947666256011567U) + aOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 39U)) + 1703669290934254701U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6664070663184147951U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2104148316797553431U;
            aOrbiterJ = RotL64((aOrbiterJ * 12887842067180975983U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1197910004222596145U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 9922977170060903197U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 13047828062605568603U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2048376210852567829U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12568990647075931409U;
            aOrbiterG = RotL64((aOrbiterG * 9860242601194210927U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15026894775772902751U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3439447160137900629U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1813754963043785165U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6532671388552829796U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17261098369835997661U;
            aOrbiterH = RotL64((aOrbiterH * 568292591215203521U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 3171300991007459947U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5935563269327662024U;
            aOrbiterC = RotL64((aOrbiterC * 11271790283157765003U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14290941734320455612U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12371794745736518824U;
            aOrbiterB = RotL64((aOrbiterB * 12208762336145168647U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8782840145467637373U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4067525421190366741U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6671002797916227485U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11854812920571789853U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17564890418553131451U;
            aOrbiterK = RotL64((aOrbiterK * 16657184504366731805U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 20U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 10U) + aOrbiterD) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterA, 10U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + aNonceWordL);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterA, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererB = aWandererB + (((((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 29U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterK, 35U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterK, 60U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 54U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28143U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneC[((aIndex + 28395U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26432U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32611U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29432U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27716U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 6U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 11700815697312060726U) + aNonceWordK;
            aOrbiterE = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 11808423452327465441U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 43U)) + 8670503858631730886U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 24U)) + 2400061067991988544U) + aNonceWordN;
            aOrbiterA = (((aWandererH + RotL64(aCross, 19U)) + 16163118178366229686U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 11U)) + 3280178595904941068U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 51U)) + 3298683600817047727U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 16321624053445183574U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 60U)) + 6730229877611375225U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10162830636713641322U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15646771327759599256U;
            aOrbiterI = RotL64((aOrbiterI * 15333053762177144775U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14841751262270544102U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9545541117228834895U;
            aOrbiterK = RotL64((aOrbiterK * 11529769874752969377U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14676615635857599982U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1231768638470558855U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2716808508509014677U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1945905595345404833U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1406171421638586846U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4577864352425476233U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1970292335806697198U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12309719390375013297U;
            aOrbiterJ = RotL64((aOrbiterJ * 16540660957923687327U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5352135521358954576U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15465675376193501658U;
            aOrbiterE = RotL64((aOrbiterE * 16385761112921041387U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2842123638916600369U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3544764287036748668U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3360772950777850115U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6038297172906492282U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10249342332287140970U;
            aOrbiterG = RotL64((aOrbiterG * 16701083081566042277U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1662076777040529446U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1949705569959740274U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 11340691546658994529U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 6U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 30U)) + aOrbiterK) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterA, 35U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 57U));
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 21U)) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterF, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 56U) + aOrbiterC) + RotL64(aOrbiterD, 26U)) + aNonceWordI);
            aWandererG = aWandererG + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 47U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Lacrosse_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8B51889156C41287ULL + 0xBE44FEE214D3C997ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA06F55C504373719ULL + 0x987A50E679E7FF8EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCB025F90F259E4F9ULL + 0xFA0E537FBCF17A5BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE870315136C3B2CBULL + 0xAD4C44A01FAE1E0DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA6C13A0B4C845B57ULL + 0x95897956A6D5AA94ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF7B79D04E349BFB9ULL + 0x9A44F05366F0D469ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBEEF987B1652D7A7ULL + 0xF9EC32097CC2D77FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8F69FAD566909579ULL + 0x9DD2C626DCFF269CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xABEA1623D1E0E70DULL + 0x89C14E1CB1C28309ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF1AE0E0500194FFDULL + 0xA748599BF7F5C403ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF0EC79590303BCA3ULL + 0x8E48C0D76674B97AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE9F35373A83D44E1ULL + 0xB75822955CE586CEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA1F2F5D4B8A798A5ULL + 0xF85BCB35B28F2E72ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA47731FDBEED6997ULL + 0xB5E5ADC38686735BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE960CE38CB241349ULL + 0xA1F7A3013AABC648ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x85F14DD356F24DA7ULL + 0xD2597B8CC5B4D5AEULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneD, aWorkLaneB, aFireLaneB, aWorkLaneC, aFireLaneA
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2919U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 7321U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 7475U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 413U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5266U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 18U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 7075016829833562104U;
            aOrbiterJ = ((((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 8783765886115517036U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((((aWandererK + RotL64(aPrevious, 4U)) + RotL64(aCarry, 21U)) + 2996723892384565829U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aWandererA + RotL64(aIngress, 13U)) + 9494134707342189476U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 23U)) + 5052642981395679904U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8766787055127962238U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4467211954388738079U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 8599295330343804047U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8030255604633658608U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16962408063455702251U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11171737929747471631U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 3768222186567699076U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 14930990410207899871U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 10930005786146268241U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14179761938395502502U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1879084742719898108U;
            aOrbiterJ = RotL64((aOrbiterJ * 16783034788172670121U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5535012408925981515U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12792553516710295939U;
            aOrbiterC = RotL64((aOrbiterC * 8577530993755159329U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterK, 53U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + aNonceWordJ);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 26U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 41U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + aNonceWordH) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11684U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 15651U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 9004U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10350U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11427U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13561U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 12U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 13714409587461539863U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 41U)) + 14101156723903265839U) + aNonceWordD;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 7063754562895369001U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 12320578575245519386U) + aNonceWordP;
            aOrbiterC = (aWandererG + RotL64(aCross, 20U)) + 11744826789631008424U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8744816505096675597U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10405435520084528645U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13279521344071568023U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 1463157688070683543U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 12379603577919617703U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14858901470015109311U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1343439118031348146U) + aNonceWordA;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 16118850268070235540U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 11184386483735388257U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14116264435819277136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5251698273012432109U;
            aOrbiterH = RotL64((aOrbiterH * 1495818611622063967U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14806408656041403829U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11569345414052398227U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9913158908301414861U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterA, 3U));
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + aNonceWordL) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + aNonceWordF) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneB
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24391U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 22861U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 22984U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21494U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20172U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21591U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 56U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererB + RotL64(aScatter, 11U)) + 16519040829220310189U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 42U)) + 6888002778416941825U) + aNonceWordM;
            aOrbiterI = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 1310832187746534025U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 5890888009051281674U;
            aOrbiterB = ((((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 5143864838362464857U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 15591534069452660003U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1466867671765325096U;
            aOrbiterI = RotL64((aOrbiterI * 1277202105237572301U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13931443680107902488U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15400747367673245552U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7011651369456453127U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 2836975369734495759U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2370720358274970117U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4615571902817575375U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3470677184188006133U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7175584278499266723U;
            aOrbiterG = RotL64((aOrbiterG * 10067096593682482345U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6095078817776863055U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 2176637999243513070U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 12215701810843975501U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 36U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 44U) + RotL64(aOrbiterB, 52U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + aNonceWordB);
            aWandererG = aWandererG + (((((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 19U)) + aNonceWordI) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28234U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 24850U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26749U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25628U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27982U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30990U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((aIndex + 25279U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 11698283336767769359U) + aNonceWordL;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 13297826354831483872U) + aNonceWordJ;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + 15254999058287530795U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aCross, 26U)) + 17474166585085346567U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 15684783498452840289U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5061229733465216486U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15370981279168377944U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15893028157665379361U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17966672773619554092U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14685092893994491068U;
            aOrbiterI = RotL64((aOrbiterI * 1627758964162892429U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 12798804186209406389U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2848444181474221574U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13730480364920876877U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 8551142075919636146U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8833198159158950723U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 7650289040764974737U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7351473160893666232U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14204899612487622222U;
            aOrbiterJ = RotL64((aOrbiterJ * 6317485031956448029U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 42U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 53U)) + aNonceWordA);
            aWandererH = aWandererH + (((((RotL64(aCross, 23U) + RotL64(aOrbiterD, 41U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordE) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 26U)) + aOrbiterG) + aNonceWordC);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 48U) + aOrbiterA) + RotL64(aOrbiterJ, 5U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 14U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Lacrosse_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xED8FA3ABACAA638BULL + 0xBC5CD10564726ED7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEFC7202573052559ULL + 0xC335FF36F2448BF0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCED721F170CAC237ULL + 0xBD52E8D0AE4FBD0EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD94B3CBA911E16AFULL + 0xE15EFAD9ED36C56CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAC2E02CC11AE47A5ULL + 0xE24B494BA104DB61ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC791E34E2B37FF69ULL + 0xCCE8A29DF94E6002ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB0F91B286E5916BFULL + 0xABD1C6940D004EE4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC5A32756179FBB49ULL + 0xDB392D1888FF4795ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEC053D53C6437D39ULL + 0x9A8038603A2BF0C3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x90E93610EA0D785BULL + 0xC2860415D1567D7AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDCE48AD74677012BULL + 0xF265E07D5CA72AA7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE52442C091A933FFULL + 0xC099C95601C10553ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDEA43853EFE0C4AFULL + 0x821983C091F40C61ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9CA271ADBBFEA87FULL + 0xE49A6BBF7D6EC6A9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBE23E971D37B04E1ULL + 0xDAFF41E792ADB428ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCA198D74C000C00DULL + 0xE1DE62E8D2647872ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aOperationLaneB, aWorkLaneA, aFireLaneC, aOperationLaneD, aWorkLaneB, aFireLaneA, aFireLaneD, aWorkLaneC, aOperationLaneC, aOperationLaneA
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5577U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 6909U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6137U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4104U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7769U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 2124U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 54U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 3650233661228036955U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 41U)) + 11607036400067735729U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 3899614406903883035U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 14U)) + 8159156925629965143U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 3U)) + 7148903913967261270U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 51U)) + 9161665622287517848U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 2981535013474059469U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15812469008200319549U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14687469489893270300U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14142363399696670451U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6025209349511417063U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 12964750392311112676U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 12955480283032701843U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6572355895765394340U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3542300121890027981U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 11201491178181273935U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6477175684045398359U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1081388388827929314U;
            aOrbiterK = RotL64((aOrbiterK * 8752188637514143529U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13754328481584620771U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3684673342659575917U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6139923312873039143U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6542045150319909445U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5352102692424060388U;
            aOrbiterD = RotL64((aOrbiterD * 7385758355501860261U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9110100774657340354U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2813273684436269057U;
            aOrbiterH = RotL64((aOrbiterH * 10468759062594022273U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 14U)) + aOrbiterI) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 21U)) + aOrbiterK) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 18U) + aOrbiterK) + RotL64(aOrbiterJ, 41U));
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10371U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 15790U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 8409U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16152U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15848U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 10202U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 9654059367478508868U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 43U)) + 6473006635864677427U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 6944184481315853243U) + aNonceWordG;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 18U)) + 4061496421939102306U) + aNonceWordC;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 11U)) + 15791809275719085463U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 29U)) + 14050798802646323055U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 12072905924741758266U) + aNonceWordB;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17639076509231343896U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12195388285571234715U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4317060502521195769U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4325404419499496529U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5910567888204238382U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11503787177122206937U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13092940059929942699U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13381962590820308761U;
            aOrbiterJ = RotL64((aOrbiterJ * 6345904465930943295U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 15622862439323440527U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14027151901132249793U;
            aOrbiterB = RotL64((aOrbiterB * 2273573821630510087U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4584410023907605157U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 15763755180625487157U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 6755736130607297639U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17023059745666559199U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5298529579288492971U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 2483562793328357721U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2870152867331654736U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12017191100173748848U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9958191466506480519U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 18U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 27U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 4U)) + aOrbiterD) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 19U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aCross, 22U) + RotL64(aOrbiterB, 43U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22894U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 19094U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23998U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20199U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21788U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 20523U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 18144572925667544139U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 5659758077574059728U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 6343330616999166392U) + aNonceWordA;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 47U)) + 17754639838410839447U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 29U)) + 9451843819849581729U) + aNonceWordC;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 14U)) + 7957854457197462212U) + aNonceWordF;
            aOrbiterC = (aWandererJ + RotL64(aCross, 23U)) + 1461994799722205010U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18002214276252170177U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14689869073147027164U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 12242482963989582191U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3978104368003440293U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8512135845221335386U;
            aOrbiterJ = RotL64((aOrbiterJ * 10506667163729414667U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1477533446382953439U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2166717790929947990U;
            aOrbiterA = RotL64((aOrbiterA * 6538884492418324461U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8082437060686606995U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4363687722464700362U;
            aOrbiterB = RotL64((aOrbiterB * 7199165810993478887U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15782763348014924206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8572509150015960728U;
            aOrbiterH = RotL64((aOrbiterH * 3340528604891897779U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12248271773316742521U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9602078627638561949U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1860631869877427405U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17244849374768558859U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 1030743048280579012U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 10858949914285817051U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 60U)) + aOrbiterF) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 29U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 23U)) + aOrbiterF) + aNonceWordB) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterG, 35U));
            aWandererC = aWandererC + ((((RotL64(aCross, 20U) + aOrbiterF) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 41U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27123U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 30884U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 31007U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30184U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30803U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 25373U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 11U)) + 9471546960258473684U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 18050235435948942244U) + aNonceWordM;
            aOrbiterE = ((aWandererE + RotL64(aCross, 21U)) + 3005107102671544641U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 57U)) + 17898396434573801850U;
            aOrbiterK = ((((aWandererB + RotL64(aCross, 50U)) + RotL64(aCarry, 13U)) + 15071602525497771648U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 5780119462702672108U) + aNonceWordG;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 27U)) + 13301326224151025687U) + aNonceWordL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18129323022260575961U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1199228670638790709U;
            aOrbiterE = RotL64((aOrbiterE * 1780426336211781025U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1839199978088021020U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4999517042246790165U;
            aOrbiterD = RotL64((aOrbiterD * 4585813675677234577U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8788607633376516299U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15143903839930468749U;
            aOrbiterK = RotL64((aOrbiterK * 12735914889325422675U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16674732686428431869U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15908873150953195581U;
            aOrbiterG = RotL64((aOrbiterG * 18049755517524334107U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11204775359756474667U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2525984309543939465U;
            aOrbiterA = RotL64((aOrbiterA * 3988529812023791571U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4566345170476825512U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14876612901557406267U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 9047956948845135339U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14926290877038883931U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12710203178186614846U;
            aOrbiterF = RotL64((aOrbiterF * 14841163494801662515U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 20U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterE, 41U)) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterI, 35U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + aNonceWordA) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 12U) + aOrbiterG) + RotL64(aOrbiterA, 60U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x89876743DEC87C1FULL + 0xF5E677DF62FE5938ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAE07C51392757CD7ULL + 0xF088649068C2D936ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC8484C0088875B4DULL + 0xFF15A89AF001403DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE0EEC480A7AC69CBULL + 0xCB1B1C9C85DE3F69ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDA08873B5805C3E9ULL + 0xC287ED5A0F4AEA19ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC86DE384D0A56C33ULL + 0x91AF9F07FD250C92ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCC02DEF7A7DC080BULL + 0xD534A55ACFC171BBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCB5BF6413E2F5879ULL + 0xBC246B21DFFD28A8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC619FA70BF7BC77FULL + 0x92D47E8569FA0903ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFF39F6D84E2A0129ULL + 0xEF935663005044EEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE2701A7256275A73ULL + 0xEF14DBF420DA78BDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x81709646F1F9ADABULL + 0x95B5B3F89005654EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC3F3D021FD468365ULL + 0x8525324DF0013960ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFFB4013E0D6A193FULL + 0xDF6F8ECBB0496EC5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCDF952E0B084E20BULL + 0x92EE02E5BEAC5E90ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA768DA9798BCBC9DULL + 0xFD94A19FC5E7E8ACULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aFireLaneC, aExpandLaneA, aOperationLaneB, aFireLaneB, aExpandLaneB, aOperationLaneD, aFireLaneA, aExpandLaneC, aOperationLaneA, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 178U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 7755U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 8047U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2733U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4120U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 3428U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 22U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 9080426856729228705U) + aNonceWordH;
            aOrbiterG = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 7851218321653539276U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 60U)) + 7023344692919298036U) + aNonceWordJ;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 9772846154227440734U) + aNonceWordG;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 39U)) + 12008298632429608431U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererB + RotL64(aScatter, 47U)) + 12201090455849562875U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 13U)) + 9498721803411445471U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 351203764023093632U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4966360430644539250U;
            aOrbiterI = RotL64((aOrbiterI * 10138518378274592739U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9194167899071345693U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4922477697284269116U;
            aOrbiterE = RotL64((aOrbiterE * 8444814161720407881U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15742625291642356429U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7528703106518431730U;
            aOrbiterD = RotL64((aOrbiterD * 11530049278751507567U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15279053574704935317U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2425839793660355555U;
            aOrbiterK = RotL64((aOrbiterK * 11486964816849830667U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13209849392400008898U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9041500097716231309U;
            aOrbiterJ = RotL64((aOrbiterJ * 340661035700748739U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7885423750878814599U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1992993999902904603U;
            aOrbiterG = RotL64((aOrbiterG * 1478629826632201617U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6120758615019314102U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8529621625846992066U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8485991471612862467U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 4U)) + aOrbiterG) + aNonceWordE) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 51U)) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 50U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE) + aNonceWordO);
            aWandererF = aWandererF + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 43U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13859U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 9861U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 14719U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13077U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14484U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 12808U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 6U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 8975885703279267062U) + aNonceWordH;
            aOrbiterA = ((((aWandererH + RotL64(aPrevious, 44U)) + RotL64(aCarry, 3U)) + 8664844915562660637U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 21U)) + 12281774799736296726U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererD + RotL64(aCross, 35U)) + 15347461352311329726U) + aNonceWordG;
            aOrbiterI = (aWandererA + RotL64(aScatter, 57U)) + 12967500561828907834U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 5002833859280402726U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 11U)) + 11908257536954668983U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17017174811949227162U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16851323125613931180U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12446990992858763577U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13469326957728686706U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5228638551056105241U;
            aOrbiterI = RotL64((aOrbiterI * 13369947664646167255U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11945166198089308564U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16268645041872996022U;
            aOrbiterG = RotL64((aOrbiterG * 5391448793718370911U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14781204627695095701U) + aNonceWordL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5365325354838101092U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 8017284997946310807U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 563147416025715953U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 14660867395395625851U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4769458126865307103U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3168989056355712105U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16179131669773665579U;
            aOrbiterK = RotL64((aOrbiterK * 5641461617066671723U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4160220074225527179U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8597134686962559111U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 639572585431474015U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 21U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 43U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterK, 60U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 10U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19295U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 23179U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17291U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20956U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23785U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 22011U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 40U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 57U)) + 5573188770530340913U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 1431772230889897111U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 43U)) + 4809192776429682319U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 26U)) + 5576603692574369341U;
            aOrbiterI = ((((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 2720143226007220386U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = ((((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 17220328778565331629U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aWandererC + RotL64(aScatter, 11U)) + 9629485808442089423U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1136998437010390983U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11893390497814523841U;
            aOrbiterE = RotL64((aOrbiterE * 5329621622743089531U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1764986431917532370U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1741014798007010376U;
            aOrbiterA = RotL64((aOrbiterA * 13414914086049500731U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 12221368453236547044U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7694538641172350430U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8439120733670016501U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17472344518811560603U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3308740700728172984U;
            aOrbiterC = RotL64((aOrbiterC * 15290400462887712083U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9535358833412446771U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11192312491731312451U;
            aOrbiterH = RotL64((aOrbiterH * 17405609148475445743U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14850451970047190039U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 11932493299452443256U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 7964808728820467795U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5972619895614731870U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17174497535809891690U;
            aOrbiterI = RotL64((aOrbiterI * 15471084511364572533U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 52U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 47U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 53U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterH, 60U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25559U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 25886U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 27902U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30192U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29774U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 26661U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 47U)) + 8988572360732005217U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 27U)) + 17889613225105985335U) + aNonceWordP;
            aOrbiterH = ((aWandererE + RotL64(aCross, 3U)) + 15563478320513948626U) + aNonceWordC;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 3441351228410524816U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 36U)) + RotL64(aCarry, 43U)) + 4425592689451435346U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 12733160231627305928U) + aNonceWordN;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 13U)) + 3574152157304607854U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15167631896729808783U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15822667973915417055U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5155661648455308057U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17181685481076577637U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 9979204751408873468U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 8244434774754786565U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1334240485667164762U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9190066751460137016U;
            aOrbiterI = RotL64((aOrbiterI * 14585141844653660363U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15465215829109246336U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2305208282453624419U;
            aOrbiterB = RotL64((aOrbiterB * 10257861974108363283U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 16951510027310993926U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11117938943423526901U;
            aOrbiterG = RotL64((aOrbiterG * 7805486716716924787U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12461379120662979432U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11719697049048823897U;
            aOrbiterA = RotL64((aOrbiterA * 14880996802304818757U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 6843357278142933570U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12727898578324702374U;
            aOrbiterC = RotL64((aOrbiterC * 9786435451654365097U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterI, 21U)) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterH, 42U)) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 53U)) + aOrbiterA) + aNonceWordG);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 5U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x846F79FF987F86EDULL + 0xFB1BCD29BA8229B1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD1D9741B05B94D57ULL + 0xAC638ECC2DF4D637ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEC5CBDE04B59E40FULL + 0xCEA5125327AFEB6BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE81FFD13B0FAFB5BULL + 0xB69A3FEE8620AB10ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x936962FC9D2D2601ULL + 0x9557EB47CC35ED55ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDCA8AD2EDCB1C2E9ULL + 0xAC083F89DED385A6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x91511FDB0F152B83ULL + 0x9946F22DD635B897ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBBEC19541E24143BULL + 0xF83CAD9BD42EC229ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x87927624E7C6C24DULL + 0x9A3E97773BD6DB6EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBDF302F8E07FC8D9ULL + 0x8A4CFB4EC8067902ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD581A05B387A9A7DULL + 0xFDA1549E7C11C29FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF7FCC05F40757935ULL + 0xAEE2B832EEF75878ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA74323ED49907AEFULL + 0xF93F161CE36B017BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA99DFDF432442917ULL + 0x856B48856F77812DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8F568EC3FBEAA605ULL + 0xFCA459EC782612A3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAB285ECB3D8B89F3ULL + 0xC4B05B0BD029196AULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD, aFireLaneD, aOperationLaneA, aFireLaneB, aWorkLaneB, aOperationLaneB, aWorkLaneA, aFireLaneC, aOperationLaneC, aFireLaneA, aWorkLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7767U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 2764U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 3960U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1787U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1867U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5289U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 6U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 8988572360732005217U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 43U)) + 17889613225105985335U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 26U)) + 15563478320513948626U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 35U)) + 3441351228410524816U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 37U)) + 4425592689451435346U) + aNonceWordL;
            aOrbiterE = (((aWandererA + RotL64(aCross, 13U)) + 12733160231627305928U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 3574152157304607854U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 47U)) + 15167631896729808783U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 39U)) + 15822667973915417055U) + aNonceWordP;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 58U)) + RotL64(aCarry, 51U)) + 17181685481076577637U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 3U)) + 9979204751408873468U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1334240485667164762U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9190066751460137016U;
            aOrbiterH = RotL64((aOrbiterH * 14585141844653660363U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15465215829109246336U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2305208282453624419U;
            aOrbiterK = RotL64((aOrbiterK * 10257861974108363283U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16951510027310993926U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11117938943423526901U;
            aOrbiterC = RotL64((aOrbiterC * 7805486716716924787U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12461379120662979432U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11719697049048823897U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14880996802304818757U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6843357278142933570U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12727898578324702374U;
            aOrbiterD = RotL64((aOrbiterD * 9786435451654365097U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18127999660067652233U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11754709060558683082U;
            aOrbiterB = RotL64((aOrbiterB * 12798744012150745847U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16940151146420516184U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12924950783056761895U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 8898170377271926745U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14829713915929878471U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 840466047621042565U;
            aOrbiterA = RotL64((aOrbiterA * 10748511630509529489U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11469637840333471085U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5561780312837795893U;
            aOrbiterI = RotL64((aOrbiterI * 11935079844970978957U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 1059834104159730610U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10122108814456766430U;
            aOrbiterE = RotL64((aOrbiterE * 2184693583782179921U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14857099570072635006U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8988572360732005217U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14409836741925393077U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 36U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 27U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 41U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterC, 37U));
            aWandererC = aWandererC + ((RotL64(aScatter, 10U) + aOrbiterI) + RotL64(aOrbiterB, 53U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterK, 50U));
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13337U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 11383U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10302U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11468U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12971U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 15068U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (aWandererE + RotL64(aPrevious, 13U)) + 6068543441070417854U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 44U)) + RotL64(aCarry, 51U)) + 2995980468193441856U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 18020277482171594003U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 39U)) + 4293807434721230702U;
            aOrbiterH = (aWandererA + RotL64(aCross, 53U)) + 7980599111583893156U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 60U)) + 8593141111851052016U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 57U)) + 5903487523900084325U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 15112035513447930209U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 51U)) + 9854037263057006439U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 19U)) + 16759760289688823193U) + aNonceWordK;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 5U)) + 12622628933030601390U) + aNonceWordH;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1264668857268123425U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16302812053619101593U;
            aOrbiterJ = RotL64((aOrbiterJ * 18291400055836111547U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 16087995784896123610U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7970269262800468363U;
            aOrbiterI = RotL64((aOrbiterI * 14924752223305807461U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5331477046030959632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16534913204255550893U;
            aOrbiterD = RotL64((aOrbiterD * 1013433634373673565U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 11042821902537871209U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8069677512345031660U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 13622218526054132397U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5737130058129936372U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1076627182956662997U;
            aOrbiterA = RotL64((aOrbiterA * 14342191224014199929U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 13911061091801078190U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15397603151098990373U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 1802890451633592245U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15137326716738637972U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11248737008959896786U;
            aOrbiterE = RotL64((aOrbiterE * 90789374131547005U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1847847987633923657U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10560748778679145431U;
            aOrbiterB = RotL64((aOrbiterB * 2919333327817231099U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2703726238610290251U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12950671360471467310U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7490327691501537047U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10331504168520449467U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1541527607705280906U;
            aOrbiterF = RotL64((aOrbiterF * 14197400812600186171U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9135056476214341809U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6068543441070417854U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 14102524444094948875U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 24U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterE, 23U));
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 41U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 38U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 51U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aIngress, 54U) + RotL64(aOrbiterB, 28U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 10U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22380U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 23400U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 19691U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24386U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19702U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 16452U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 34U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (aWandererE + RotL64(aIngress, 39U)) + 6521330037475130256U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 57U)) + 12611880456055428940U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 12061611078130934708U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 13U)) + 1558112410801116984U) + aNonceWordO;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 26U)) + 10509115227850160786U) + aNonceWordP;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 4045915960688792066U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + 1196541286513243082U) + aNonceWordG;
            aOrbiterI = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 15564991032722373702U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 53U)) + 4897765238703641798U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 21U)) + 12327429514907752733U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 30U)) + 6189189797708711636U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6374267075282018852U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1888758503831341439U;
            aOrbiterH = RotL64((aOrbiterH * 74387714918264257U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14956857689299491800U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14879361107223331957U;
            aOrbiterC = RotL64((aOrbiterC * 9166712966729591953U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16086885494838105042U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8069724185844303923U;
            aOrbiterE = RotL64((aOrbiterE * 8878470736758734353U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10854345917959911439U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7078313614360332089U;
            aOrbiterI = RotL64((aOrbiterI * 9864025732292844871U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15083669236062255011U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 594879695916679116U;
            aOrbiterK = RotL64((aOrbiterK * 9852515479152735283U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6721466068234534523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 475816724162626782U;
            aOrbiterA = RotL64((aOrbiterA * 4799725182757588407U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 4341655358154605899U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15477254302340298586U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13961520225881974201U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10179091913200895775U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6310490897546909571U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 15080621088825477613U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13462682513035460711U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16739138858084100385U;
            aOrbiterJ = RotL64((aOrbiterJ * 16386371811268298031U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13608837667062268989U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12902415667552110103U;
            aOrbiterD = RotL64((aOrbiterD * 16398790854093048017U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16596211634603915761U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6521330037475130256U;
            aOrbiterF = RotL64((aOrbiterF * 631958426544321145U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterC, 29U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterI, 27U));
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 39U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterI, 34U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterA, 5U)) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 21U)) + aOrbiterF) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 48U)) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27140U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 29674U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30351U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32110U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29958U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28361U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 52U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 11039986441331892533U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 57U)) + 6256024955965426119U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 6U)) + 9857443189988995666U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererD + RotL64(aCross, 53U)) + 11900944813380998208U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 39U)) + 8422577734978875541U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 3100835100713928724U) + aNonceWordF;
            aOrbiterD = (aWandererC + RotL64(aCross, 21U)) + 11871553509810206993U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 37U)) + 17614749493763417027U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 43U)) + 3638372131856199916U) + aNonceWordH;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 18U)) + RotL64(aCarry, 51U)) + 6582275259281025770U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 3U)) + 17016882418498941958U) + aNonceWordG;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1747214688658984715U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9356088987044015278U;
            aOrbiterK = RotL64((aOrbiterK * 16221733545319753695U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4056238112133473456U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16013150119949532998U;
            aOrbiterH = RotL64((aOrbiterH * 12913648646318115315U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16076621211111834889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9940824359571581765U;
            aOrbiterD = RotL64((aOrbiterD * 11624767861336495331U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15624084004784515753U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7630989544834680335U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12261063237156822067U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18003586430673313786U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1654118743290334161U;
            aOrbiterJ = RotL64((aOrbiterJ * 1153250137357176071U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3254189676528343910U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15629083361573065165U;
            aOrbiterF = RotL64((aOrbiterF * 17024833368570949107U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10056859810555674806U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15976683222786846254U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 2801754232182942635U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11872378594829637933U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7633773773528713489U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8218288492011593353U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 16305188578382203720U) + aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13293036594949754170U;
            aOrbiterI = RotL64((aOrbiterI * 1300645662609848183U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15185013801659166674U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11562899709899198100U;
            aOrbiterC = RotL64((aOrbiterC * 9115495024409604629U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1525205566739385260U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11039986441331892533U;
            aOrbiterE = RotL64((aOrbiterE * 9802284050237622047U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 36U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 56U) + aOrbiterH) + RotL64(aOrbiterG, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 21U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 58U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aCross, 12U) + RotL64(aOrbiterJ, 39U)) + aOrbiterI) + aNonceWordI) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 47U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterD, 11U));
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterF, 18U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterC, 21U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAB2952D96640503FULL + 0xB2B4E1BCB7D56E35ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD6A89B9E1AE9DBC3ULL + 0xB555C58331902E51ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB8D68AA0AA23F39BULL + 0xCF9F11245015C931ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8AEA656F20C890CBULL + 0xDBA776EC0635996DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB21C7D76418ECAA3ULL + 0xCA1AB1F2D4DE1EB9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x914D501FBB22E9ABULL + 0xCBF2F46CB0009C90ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFE48084C8611EF57ULL + 0xF026D6832EE5A53FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x90C332DC9A2ED7E9ULL + 0xD402C6186DACF755ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF5026ADD4AE49ADFULL + 0xBDE987711986E5B1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE8561DF8DA5CED99ULL + 0xE66AA20AF92B19EEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE415481FD60CFF57ULL + 0xCFB20B4D488B095AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD18C28D62DD2E6FDULL + 0xCFECE8C451FB34E4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDDFE1680EFF20109ULL + 0xAA31F440ECE4364EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDE68CE73346398B7ULL + 0xE1EB8B9EAF2DDC24ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB8FD99EC0540331FULL + 0x9D2697EB41668F17ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCC99F609D9265F4FULL + 0xF828DBFC93BCED9EULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aFireLaneD, aExpandLaneA, aWorkLaneC, aWorkLaneB, aExpandLaneB, aFireLaneC, aWorkLaneD, aExpandLaneC, aWorkLaneA, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 199U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 5888U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1207U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2303U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4494U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1923U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (aWandererE + RotL64(aIngress, 40U)) + 15904465836916519864U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 17725629806317789307U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 23U)) + 13794170125914914828U) + aNonceWordP;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 47U)) + 2149055907476874332U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 5342047776745074649U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 35U)) + 8268148484060546838U) + aNonceWordD;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 4U)) + RotL64(aCarry, 57U)) + 10821151364028563719U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 13U)) + 4294213820894407378U) + aNonceWordC;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 57U)) + 10884726101307943090U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16432210042202444824U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15196602644336228055U;
            aOrbiterG = RotL64((aOrbiterG * 12680438355124070237U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14117787670220328165U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 219833877949480215U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 10736293047771972173U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3326396981881473962U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14918513066311426279U;
            aOrbiterB = RotL64((aOrbiterB * 14269763278564574663U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11795234681370163206U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3068267285352664813U;
            aOrbiterD = RotL64((aOrbiterD * 15746255933920904619U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 245233356957999496U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 709926406353796673U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 13627039596842073595U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5378105439430271038U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 10114555061122044430U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5351295043424885549U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 13233010815716769713U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8231291294833548389U;
            aOrbiterF = RotL64((aOrbiterF * 10840516135212753869U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 7160760224172419829U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14767926435411546785U;
            aOrbiterJ = RotL64((aOrbiterJ * 1643485739468851073U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4464245330038080103U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15778166658285494712U;
            aOrbiterE = RotL64((aOrbiterE * 13980891936095282989U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 34U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 58U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterD, 19U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterK, 14U)) + aOrbiterG) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 58U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9092U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 14289U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 9715U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13025U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14604U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 12251U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 36U)) + 3973833383430652211U) + aNonceWordI;
            aOrbiterH = (aWandererC + RotL64(aCross, 3U)) + 5760227042747169187U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 4923009065139227286U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 43U)) + 1477807307009107590U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 30U)) + 5707194514329007301U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 5340439728375269724U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 17080457898946572387U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 23U)) + 281559150259472813U) + aNonceWordP;
            aOrbiterE = (aWandererI + RotL64(aIngress, 51U)) + 16160633048230910560U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9003989610509592121U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10579322462808454333U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 100832431598087235U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15059383289528723069U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10417647757852880956U;
            aOrbiterA = RotL64((aOrbiterA * 1457919230286043137U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14484665027393813330U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12344463053485837974U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5762654194001525041U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5826453246659297805U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12547902286376986223U;
            aOrbiterH = RotL64((aOrbiterH * 2982850000322672789U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9637855144278126174U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2132744427444501938U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 5911587798564836199U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9248933938130311231U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13274297928717090383U;
            aOrbiterE = RotL64((aOrbiterE * 2901398809555237563U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3690262236918560930U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3626005326410800344U;
            aOrbiterD = RotL64((aOrbiterD * 13030443356669355355U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10801089744186148218U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5446653082176311031U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4594267575901248321U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3205541585889107366U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4532327942368884436U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16287094987689326229U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 4U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterA, 56U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 27U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 56U) + aOrbiterH) + RotL64(aOrbiterB, 47U)) + aNonceWordA);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterF, 51U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + aNonceWordJ);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 46U) + aOrbiterC) + RotL64(aOrbiterF, 10U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16685U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 23517U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24440U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20406U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19957U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21705U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 37U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (aWandererG + RotL64(aCross, 13U)) + 4068921616130916949U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 47U)) + 12077715273915151726U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 16047546802670596833U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 6U)) + RotL64(aCarry, 27U)) + 9690277462716999763U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 57U)) + 14484814700447992628U) + aNonceWordD;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 41U)) + 17089267243053958210U) + aNonceWordI;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 51U)) + 9138746214446211147U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 34U)) + RotL64(aCarry, 35U)) + 10181001536979097045U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 29U)) + 6657458969093373191U) + aNonceWordC;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 7515983477876590988U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3039935555863947600U;
            aOrbiterA = RotL64((aOrbiterA * 12511160550780270119U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16209389224740851136U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 725253312098083182U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 17535989492095522597U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13307041115748941383U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7159572004825238263U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 4855009895002398449U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12027236743251643820U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8717826175991286553U;
            aOrbiterF = RotL64((aOrbiterF * 1175614802543098451U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4769096034227659937U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11201226563992939616U;
            aOrbiterH = RotL64((aOrbiterH * 15595355978388159931U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17295978531215563256U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11850923890626719833U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3854851059897397075U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14139441565288097706U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 988684899382304485U;
            aOrbiterI = RotL64((aOrbiterI * 11929090869999700891U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6159251276942253175U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4849529993914550651U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18240712676783671317U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6679745455842119497U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15838404437552215214U;
            aOrbiterC = RotL64((aOrbiterC * 17357853511591350887U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 50U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 28U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + RotL64(aOrbiterD, 48U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterC, 35U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterI, 52U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 23U)) + aOrbiterG) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30575U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 32578U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28946U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32548U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24742U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 27228U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 5295352595333316211U;
            aOrbiterB = (aWandererB + RotL64(aCross, 23U)) + 2341795367042042605U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 14U)) + 10122175780504033663U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 10084612804696198554U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 16470424309851045971U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 47U)) + 656016130975227994U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 37U)) + 15313268829659834317U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 19U)) + 3795220914993923394U) + aNonceWordJ;
            aOrbiterA = (aWandererD + RotL64(aScatter, 56U)) + 14044442220988813825U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3804224626734584802U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7980006306010255693U;
            aOrbiterG = RotL64((aOrbiterG * 13958505239726088561U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13746830564584711549U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11852212099729274845U;
            aOrbiterB = RotL64((aOrbiterB * 2164880979318247855U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9083223471018084847U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13706723820703853346U;
            aOrbiterJ = RotL64((aOrbiterJ * 11361854103656219887U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1713819986642275223U) + aNonceWordN;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 1382000168233902914U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 3894160765130198157U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4540474625764565485U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1756168174375757220U;
            aOrbiterH = RotL64((aOrbiterH * 12739160208010092017U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1409297070183609309U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6082750101445444357U;
            aOrbiterI = RotL64((aOrbiterI * 17438740230251860935U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1113239890859479202U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10932192439503964363U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5915660289913324281U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3732595033748508428U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5117760372351117286U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 2671510075176315761U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7399968659654088641U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14835608167871904147U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 8312521710415756159U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 50U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 43U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterH, 57U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterD, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 48U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterB, 53U)) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 10U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 42U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF7D8571430607439ULL + 0xED881AF1D3530DA6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF1771A0DAF54AD1BULL + 0xC3D7C310989D1F47ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xABD4BF48B9EA7D17ULL + 0xEA39EFE1B49DA4B6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE32A22DA4273F8A5ULL + 0xFC1FED5BBBDF84BFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBB9A9907CC9A8DC9ULL + 0xED414AA6A64C71B7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF40AFFB301990341ULL + 0xE4208795C747FEA9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCD1D58C343ACE221ULL + 0xA78CB97A12C9D4D8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF9080251C7600B05ULL + 0x8C8B28076363E67AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC7BEAA519FB34E39ULL + 0xA4A75D5EFACE8AE1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF461AA4F6FA513C5ULL + 0xCBF859BC752E79F0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA303B152E514C30BULL + 0xEC293293FC5422EFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB49F70BFAED71DA1ULL + 0xB8B21B791B010F65ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBF09EDE1CE0E7837ULL + 0xD8080B443FD231E4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCE431D507F118F1FULL + 0xD8D33CADC780E9F7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAF94771C3BE31C51ULL + 0x89A764530027A88CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA70B1937DCA5AA21ULL + 0xE45C846DD75A8844ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneA, aWorkLaneC, aWorkLaneD, aOperationLaneB, aExpandLaneA, aFireLaneB, aFireLaneC, aExpandLaneB, aOperationLaneC, aOperationLaneD, aExpandLaneC, aFireLaneD, aOperationLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7782U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 2183U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1098U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3339U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3300U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1089U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 36U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 3255291173184001106U) + aNonceWordO;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 15308468160116255528U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 51U)) + 18186972408589866656U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 14U)) + 4439324265978331914U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 13099263173016322486U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 39U)) + 7041561081767500660U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 3U)) + 6196422612687812971U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7664260932541281413U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17802347823020441056U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 2220679459017369255U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4253107484061190446U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13799496534030645312U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9167675060053848207U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14252892847595951926U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5663527578664291422U;
            aOrbiterA = RotL64((aOrbiterA * 18314294235895182465U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11148755959699137661U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17036900929333594592U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16041243617369003291U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2403828181385259549U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17813580350434928194U;
            aOrbiterF = RotL64((aOrbiterF * 13666780980793857831U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5623611126885414523U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7293224381174846969U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 7032561584670788117U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10602620906929686163U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 18015916257203385982U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 10684090189688871993U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 27U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterE, 58U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterF, 13U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 41U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 51U)) + aOrbiterI) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15568U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 9716U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10814U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13314U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11765U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14413U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 5U)) + 3970829908171131502U;
            aOrbiterC = (aWandererI + RotL64(aCross, 47U)) + 7040283759419531991U;
            aOrbiterH = ((((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 11856292169397052901U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 23U)) + 819598588791819022U) + aNonceWordJ;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 29U)) + 2176451710970866848U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 6454704928613390494U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 54U)) + RotL64(aCarry, 53U)) + 11792122387218053841U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9254780213489752211U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16591812589999846482U;
            aOrbiterH = RotL64((aOrbiterH * 5425771603523423167U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1471246223935074832U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1424843083106386453U;
            aOrbiterJ = RotL64((aOrbiterJ * 15020536982657410783U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1856469958050891629U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6331743690452052712U;
            aOrbiterI = RotL64((aOrbiterI * 15327924647897459645U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10351075711345476487U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9518585245330480185U;
            aOrbiterD = RotL64((aOrbiterD * 3792179827396760391U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17787514620244712033U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14182328067398162557U;
            aOrbiterG = RotL64((aOrbiterG * 18107337388659070197U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 12798088948801072444U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 9563215159275202323U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 7058145016617349141U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9904919772580498232U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16579777394992143043U;
            aOrbiterF = RotL64((aOrbiterF * 10516761340320196661U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 58U)) + aOrbiterF) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterG, 21U)) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterC, 39U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneD
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18300U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((aIndex + 16508U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20382U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17612U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17665U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 17196U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 14U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 37U)) + 1557680213571812384U) + aNonceWordI;
            aOrbiterH = (aWandererB + RotL64(aScatter, 19U)) + 7387349725778021121U;
            aOrbiterC = (aWandererC + RotL64(aCross, 51U)) + 15379264067601586976U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 35U)) + 3730195724576043708U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 11U)) + 9637070085323827066U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 1170865717363676184U;
            aOrbiterG = ((((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 2750833653175252030U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15118992811225568305U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 4974092922102988451U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10575977398702460975U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10625719096296719514U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 855167122475471865U;
            aOrbiterE = RotL64((aOrbiterE * 7441090331293158773U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 11322911068958340262U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4334591909425429835U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10059025861172038183U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14263701737208936392U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 678723206735649084U;
            aOrbiterD = RotL64((aOrbiterD * 10823239851733632227U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15652053114252065230U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1705225940224061401U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 3626023093533713579U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6826394665732900206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11902946775066981141U;
            aOrbiterH = RotL64((aOrbiterH * 18300629262162694137U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9802212958998591310U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14001358545610206524U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13172645840788327099U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 51U)) + aNonceWordL) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterG) + aNonceWordH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 13U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 20U)) + aOrbiterE) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30037U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 27296U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26781U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28283U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27843U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32076U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 38U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 10881271196314989997U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 20U)) + RotL64(aCarry, 23U)) + 6406461249988567558U) + aNonceWordN;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 57U)) + 17255067918280095959U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 16690850682497718411U) + aNonceWordM;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 47U)) + 5576201059361086866U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 5U)) + 11991259685693687554U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 35U)) + 14652535244217836909U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 1701789037170782122U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 953429054903473833U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 13482379459700651427U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12064513610469714211U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7993881398822002424U;
            aOrbiterD = RotL64((aOrbiterD * 11572884842788918377U), 23U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 14421313768013320050U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11112386845630998889U;
            aOrbiterH = RotL64((aOrbiterH * 11771526352030371669U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17069630896535699015U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3308240081138623373U;
            aOrbiterK = RotL64((aOrbiterK * 10449509484417835159U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 17615529807112933619U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11782807146851563541U;
            aOrbiterC = RotL64((aOrbiterC * 12992075832343669221U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14401645829607611983U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6736397344219993532U;
            aOrbiterI = RotL64((aOrbiterI * 1667287547938175641U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6446974060524700550U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7840991992443308254U;
            aOrbiterE = RotL64((aOrbiterE * 6891023544882740107U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterC, 54U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + aNonceWordB);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 11U)) + aNonceWordI) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 13U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 19U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + aNonceWordA) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 24U) + RotL64(aOrbiterE, 41U)) + aOrbiterI) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Lacrosse_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x92BE4C9342D4D8FDULL + 0xE8C7C11E3629F14CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF8DFE9B0BBC3D923ULL + 0xFCED43B3F89B08CAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xED110ECC3363AF2FULL + 0x9ACDC29A41DD850BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x95D96EB647DB31D3ULL + 0xA3D65AEAACFC8BB1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD3163EB58809109FULL + 0xD5417684630DD097ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE2E1573082152C43ULL + 0xD69CB9E9A71666A6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBC03B38CD2877FCBULL + 0xBF3F2070EFAD317EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD509F55234F679BBULL + 0xFBB1F97F7295F5AAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEB93C5F6E051E3BFULL + 0xD9E546C9D6C9511FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEF7451FFF198A14FULL + 0xD2C70588384CE95CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9157AE635E5420DDULL + 0xF6EF77C331E69DE9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD4E6737ED1431BF7ULL + 0xAD480DE4A345877CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xED4587D6CEDEC937ULL + 0xE08274CD2634FA87ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x948CDED582D7D231ULL + 0xA0A62A01B663CBFAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAF6621F575C148EDULL + 0xE9FF1FC923BDEBD4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF8FCD6715B402A8DULL + 0xD30FF713B8045D10ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1350U)) & W_KEY1], 52U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1667U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2142U)) & W_KEY1], 46U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 594U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 27U)) + 2786079456995203065U) + aNonceWordA;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 51U)) + 7237256119153857253U) + aNonceWordB;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 43U)) + 9310834010563647604U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aCross, 58U)) + RotL64(aCarry, 21U)) + 17361734905706517877U) + aNonceWordK;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 15837111231884647451U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 18065431964418026445U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 19U)) + 3029123922999952652U) + aNonceWordP;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5166926595573507837U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1918425684273807598U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16616641579714896719U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4724551751012661440U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1818014487579644390U;
            aOrbiterE = RotL64((aOrbiterE * 14904092108647864911U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6670090372241084216U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8485757110007268693U;
            aOrbiterD = RotL64((aOrbiterD * 11876760095108618363U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4928130251509514742U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2528788422725346792U;
            aOrbiterF = RotL64((aOrbiterF * 1855982047967756661U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 2860387120895147503U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12927802338151379368U;
            aOrbiterB = RotL64((aOrbiterB * 8876144125458603029U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 18029699867733207083U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13361836994951253312U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 5349767426256597073U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11957294454794128079U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3755417922063414648U;
            aOrbiterG = RotL64((aOrbiterG * 13896364063651241401U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 12U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 27U)) + aOrbiterA) + aNonceWordM) + aPhaseEWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3859U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 5042U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3112U)) & W_KEY1], 19U) ^ RotL64(mSource[((aIndex + 3267U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 966899917801652720U;
            aOrbiterJ = ((((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 10996327672320748649U) + aPhaseEOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aWandererJ + RotL64(aCross, 30U)) + 4188171566846621107U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 51U)) + 5886209243097387959U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 43U)) + 14940428957136728111U) + aPhaseEOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 179187285531914832U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 57U)) + 6685351948936817752U) + aNonceWordC;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1894506461704029700U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4182760368636977082U;
            aOrbiterD = RotL64((aOrbiterD * 972988091869133921U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12523318028514940790U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5059306166973366892U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2857409765717296483U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5890872367917643851U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17747338389865221534U;
            aOrbiterC = RotL64((aOrbiterC * 5306740664798049267U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13906227834259884100U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7152105382899756368U;
            aOrbiterF = RotL64((aOrbiterF * 6772157117358310485U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17868101884759619240U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11758843266314148347U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 5919135169337501485U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13950566197090324859U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17278105609930477854U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11431842718945107359U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9556785965646738355U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 841298436857932987U;
            aOrbiterB = RotL64((aOrbiterB * 15077843186688841797U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 10U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + aNonceWordO);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordL) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 56U) + aOrbiterK) + RotL64(aOrbiterJ, 60U)) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterB, 37U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 5U)) + aOrbiterF) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6485U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6787U)) & W_KEY1], 24U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6327U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8024U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6594U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 24U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (((aWandererD + RotL64(aIngress, 5U)) + 16200278595895089008U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 19U)) + 1029614154810465897U) + aNonceWordE;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 7129562468705441295U) + aNonceWordL;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 14388903902433951274U) + aNonceWordK;
            aOrbiterD = (aWandererA + RotL64(aIngress, 26U)) + 1013568949315967455U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 3128823373497815651U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 37U)) + 14525694606889470589U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14443983602196782887U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12244220415328641190U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 15052949098014803181U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10477159225338766614U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2842870123078131566U;
            aOrbiterD = RotL64((aOrbiterD * 11522265477555954071U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8621138818955849917U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5038396344400303181U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 14636756322207385447U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2768613802894372496U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2027754864051410015U;
            aOrbiterI = RotL64((aOrbiterI * 2461322540050569287U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2848088309172056399U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15017458513904884651U;
            aOrbiterJ = RotL64((aOrbiterJ * 9926904679902843055U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9079797279596336139U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15424866642305110811U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12912331089970158845U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13751764050290602740U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7694557131324740282U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14980807690491467023U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 6U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + aNonceWordF);
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 60U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterB) + aNonceWordP) + aPhaseEWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 10478U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 8506U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(mSource[((aIndex + 9642U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9375U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9051U)) & W_KEY1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 8453U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 27U)) + (RotL64(aPrevious, 42U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = ((aWandererC + RotL64(aScatter, 6U)) + 9041099828460168106U) + aNonceWordL;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 12883711604096848454U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 27U)) + 17420968786226443079U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 3448213891716125104U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 11866455977445336560U) + aPhaseFOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 51U)) + 4119356835384495905U) + aNonceWordJ;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 21U)) + 2186212599698637068U) + aNonceWordF;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6506144898969301620U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12556800923644051626U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 15961043406612913121U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4075551535185182945U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17877694808492008749U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 901315308379887473U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5553428900598223316U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14362304852277160675U;
            aOrbiterK = RotL64((aOrbiterK * 11415103199856419303U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9174200302876075831U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16110739511917638547U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7004356839428657949U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10189881974519849402U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2128076632642616677U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8860453653433114929U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 18133523799074400083U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9916472958834153766U;
            aOrbiterH = RotL64((aOrbiterH * 3454601168808001733U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10274457562795569227U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14134814273275356425U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 15912501063665343159U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 20U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + RotL64(aOrbiterH, 14U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + aNonceWordK);
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterH, 41U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 13375U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 11751U)) & W_KEY1], 10U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11088U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 13100U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 11182U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13478U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12056U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 44U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 12849591986267890852U) + aPhaseFOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 42U)) + RotL64(aCarry, 57U)) + 8232614804696815750U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 12141567259210877281U) + aNonceWordM;
            aOrbiterB = (aWandererA + RotL64(aScatter, 51U)) + 2928641981037885644U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 23U)) + 980733350554783938U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aWandererI + RotL64(aIngress, 35U)) + 2683985177993350746U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 29U)) + 14532148403815527355U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7736296629433884203U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10428437770166310549U;
            aOrbiterE = RotL64((aOrbiterE * 326634742742373401U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 18327174144859461029U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6810436935194432002U;
            aOrbiterJ = RotL64((aOrbiterJ * 2715987179577753597U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 12606153309690753435U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17123256945895150555U;
            aOrbiterB = RotL64((aOrbiterB * 13469111258504672565U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9057777759026189541U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16478485918911194442U;
            aOrbiterG = RotL64((aOrbiterG * 11054247078884894131U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 18064460487552100483U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11477276762421684083U;
            aOrbiterD = RotL64((aOrbiterD * 3886501230380184395U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18318375441973295081U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13849305985380030986U;
            aOrbiterF = RotL64((aOrbiterF * 12962140243967824959U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10240409420338313641U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 18360586077779529086U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18196875422391501927U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterI, 23U)) + aNonceWordD);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 3U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterB, 60U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterB, 53U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterE, 43U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14461U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 15229U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13859U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14135U)) & W_KEY1], 3U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13787U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14424U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15750U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 9888431329297626900U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 11U)) + 2937735167534624403U) + aNonceWordM;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 53U)) + 17626022970343789617U) + aPhaseFOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 5665660859333693743U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 26U)) + RotL64(aCarry, 37U)) + 1060537034632076669U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 47U)) + 743777763907175800U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 41U)) + 5744905970181808845U) + aPhaseFOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3545351394494002180U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4877547088414106007U;
            aOrbiterK = RotL64((aOrbiterK * 5416792889338547109U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11669378338379598445U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2961072441706158212U;
            aOrbiterC = RotL64((aOrbiterC * 2677988507090705371U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13984945589234919765U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1433097875470903205U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 451996840039906781U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 716415411025451152U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 8542286150858297810U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9139015340823332449U), 37U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 12932391786479661299U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 14005503313299177013U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 802663466907819743U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9382792812676318046U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5138554251079724724U;
            aOrbiterA = RotL64((aOrbiterA * 6386016499265056247U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8522380066269546172U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11825536408101906458U;
            aOrbiterD = RotL64((aOrbiterD * 17042837108792016849U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 58U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 26U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aPhaseFWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterC, 22U)) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererI, 52U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17173U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 18479U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(mSource[((aIndex + 17599U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16901U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16585U)) & W_KEY1], 54U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18726U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16948U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 28U) ^ RotL64(aIngress, 13U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererC + RotL64(aPrevious, 35U)) + 2915859148137000694U;
            aOrbiterC = ((((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 5U)) + 210680583721444425U) + aPhaseGOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aWandererF + RotL64(aIngress, 21U)) + 6668118118775650387U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 15794200818099010989U) + aNonceWordI;
            aOrbiterK = ((((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 6565076707062828369U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 27U)) + 16323164497808856719U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 53U)) + 7965435318816716560U) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7390281030573369017U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 2269738866911824875U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 1198697877998135567U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9664014216039993873U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 18284857398028357633U;
            aOrbiterC = RotL64((aOrbiterC * 8402008251343393737U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 367667619795303009U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 7935945060956274197U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 5481786693511955209U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16683666162337789540U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10655658270998102390U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15231596813382239841U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8307037916581540297U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3247742749860703524U;
            aOrbiterK = RotL64((aOrbiterK * 15052136713218656641U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10446792483683818139U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16374602929344972364U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 12599903932725787599U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2411334498322777183U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1093701164116833765U;
            aOrbiterA = RotL64((aOrbiterA * 13129220206835381729U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 21U);
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 36U)) + aPhaseGWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 36U) + RotL64(aOrbiterA, 27U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterC, 43U)) + aNonceWordF) + aPhaseGWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20318U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 19394U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19402U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 20005U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21512U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20104U)) & W_KEY1], 27U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21040U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 20624U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 43U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 2558105147674438050U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 3U)) + 15856662514774702561U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 13346869226246584582U) + aPhaseGOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 19U)) + 7632111846116243973U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 11U)) + 2102101361626976279U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 58U)) + 5605968705067851563U) + aNonceWordG;
            aOrbiterJ = ((((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 41U)) + 6842483186584326681U) + aPhaseGOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5559797213819425064U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12422313931331576759U;
            aOrbiterE = RotL64((aOrbiterE * 7399849122565913401U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2751024420047872601U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11031320239359798610U;
            aOrbiterH = RotL64((aOrbiterH * 8607639453141148025U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14366375309473793217U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 11971479429768505316U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 10063001532313098203U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3947595951884469542U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17882767922372770896U;
            aOrbiterB = RotL64((aOrbiterB * 3361906348965810211U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 513871456983509223U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 5951677013597794294U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 8508629569649935293U), 43U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 437626309049021931U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 466674061172005705U;
            aOrbiterI = RotL64((aOrbiterI * 1310502572084891157U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12362602809233133718U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10525852878882195702U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17755022180514914325U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + aNonceWordN) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 4U) + aOrbiterE) + RotL64(aOrbiterK, 30U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterC, 13U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 41U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24547U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 21902U)) & W_KEY1], 50U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23004U)) & W_KEY1], 11U) ^ RotL64(aFireLaneC[((aIndex + 24446U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24520U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23615U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22723U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 23958U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 20U)) + (RotL64(aIngress, 35U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (aWandererF + RotL64(aCross, 57U)) + 1297415699043177788U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 27U)) + 17583786534509260153U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 11U)) + 643197858925708798U) + aNonceWordE;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 5062653766915694874U) + aNonceWordC;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 18U)) + 7034273638367180511U) + aNonceWordD;
            aOrbiterE = ((((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 2026909726972916996U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 2785690475553211646U) + aPhaseGOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 2910341716302991892U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2834181605200829791U;
            aOrbiterH = RotL64((aOrbiterH * 1510617068750957651U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13323052600571281928U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10434901530315760460U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2042210188346767033U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 247903955625194782U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5196515747387257163U;
            aOrbiterK = RotL64((aOrbiterK * 1799024689023272275U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7196305682377987476U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14777739876892587484U;
            aOrbiterE = RotL64((aOrbiterE * 95220583948241581U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10609060796540136671U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8386027207212484155U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4855610536246556893U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 729659744301903424U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2350564261412606157U;
            aOrbiterG = RotL64((aOrbiterG * 16713856782349084977U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16611987556673864177U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1525195188708550503U;
            aOrbiterC = RotL64((aOrbiterC * 10045858602151004553U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 60U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterH) + aNonceWordH) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterG, 44U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aCross, 60U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + aNonceWordI) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterK) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26126U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 26861U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25727U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((aIndex + 26491U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26961U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26034U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26234U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25564U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (((aWandererI + RotL64(aScatter, 19U)) + 3973833383430652211U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aWandererH + RotL64(aIngress, 27U)) + 5760227042747169187U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 53U)) + 4923009065139227286U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 43U)) + 1477807307009107590U) + aNonceWordI;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 12U)) + RotL64(aCarry, 5U)) + 5707194514329007301U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 5340439728375269724U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 17080457898946572387U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 281559150259472813U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16160633048230910560U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 16883442583309073785U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9003989610509592121U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10579322462808454333U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 100832431598087235U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15059383289528723069U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10417647757852880956U;
            aOrbiterC = RotL64((aOrbiterC * 1457919230286043137U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14484665027393813330U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12344463053485837974U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 5762654194001525041U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5826453246659297805U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12547902286376986223U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 2982850000322672789U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9637855144278126174U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2132744427444501938U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5911587798564836199U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9248933938130311231U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13274297928717090383U;
            aOrbiterE = RotL64((aOrbiterE * 2901398809555237563U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 23U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + aNonceWordD) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterE, 41U)) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 48U)) + aOrbiterJ) + aNonceWordB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aPhaseHWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 51U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29784U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneD[((aIndex + 27844U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29437U)) & W_KEY1], 23U) ^ RotL64(aFireLaneC[((aIndex + 29790U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29994U)) & W_KEY1], 50U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27698U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29269U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((aIndex + 29508U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 35U)) + (RotL64(aIngress, 48U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 2974056819475622600U) + aNonceWordJ;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 7345051759236356098U) + aNonceWordH;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 11U)) + 12738468816846628882U) + aPhaseHOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererE + RotL64(aCross, 40U)) + RotL64(aCarry, 57U)) + 7694520596043297922U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 29U)) + 5530753590015084774U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 53U)) + 3776309161718383105U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 5U)) + 784780304358106404U) + aPhaseHOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8999942326995036509U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5194986506064092779U;
            aOrbiterD = RotL64((aOrbiterD * 15070787038006135963U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7920040007459652762U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11311997270710107937U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 6227571709361790209U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5365231114813547251U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8630110234623825263U;
            aOrbiterH = RotL64((aOrbiterH * 2735881715888325759U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2358235238039571072U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 18059414891616491807U;
            aOrbiterI = RotL64((aOrbiterI * 17150786106857185467U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14526050556461782864U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6937282036603272474U;
            aOrbiterE = RotL64((aOrbiterE * 14954512365270028029U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10105832250694931310U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3884223553012098137U;
            aOrbiterA = RotL64((aOrbiterA * 16340956813003906195U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10385284339549648087U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1257633893341505930U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 2669950791270500977U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + aNonceWordF) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 37U)) + aOrbiterD) + aNonceWordB);
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 53U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterA, 60U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 26U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32417U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 30507U)) & W_KEY1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32605U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31756U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31835U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 31351U)) & W_KEY1], 34U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 37U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 30U)) + 12632404972795375757U) + aNonceWordB;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 37U)) + 5351879979055988456U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 3597737727467443413U) + aNonceWordK;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 19U)) + 2830846754917852318U) + aPhaseHOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 17311925960294518018U) + aNonceWordJ;
            aOrbiterF = (aWandererD + RotL64(aCross, 11U)) + 2083584640523695383U;
            aOrbiterI = ((((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 15049343611387010158U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6443050378205811147U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6021965178697344070U;
            aOrbiterD = RotL64((aOrbiterD * 6054064448935006741U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5080289878758029976U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 576927745306972983U;
            aOrbiterJ = RotL64((aOrbiterJ * 16008958833683246115U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4728489691382690859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6184355840165758855U;
            aOrbiterC = RotL64((aOrbiterC * 1515043910404156423U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11220539885798595450U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11091438724966718214U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 8225347114759391961U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17184210490020062419U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2150997767099116408U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8058553821648892499U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7021953562676903717U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17159676348343312834U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13877284519668483549U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10367891770525239784U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11922478487264201233U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 9195137452661956029U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 50U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterC, 19U)) + aPhaseHWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aCross, 54U) + RotL64(aOrbiterB, 5U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + aPhaseHWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Lacrosse_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8F9F20DECAAA952BULL + 0xF0D501A571AF58F1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE7AE3FB52AE9E599ULL + 0xAA96CA2BF99BBBE9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD1994325A1632547ULL + 0xBAE590DC24D31871ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA59B1D6A2A127187ULL + 0xDD3BAA3F11502883ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA7A51B5AECD7E563ULL + 0xAFCF6B804A387417ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB9E4DFD7DA432C41ULL + 0xA46204943B8F1C33ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD9E9014CA411F84FULL + 0xFDF45417CAE1FB6EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC7BA70FDC5F38231ULL + 0xE04E411363A6F242ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD6E31A0D11F73813ULL + 0xB97CCA49BBB15459ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD0A7F3A3CACA7BC3ULL + 0xF37EA7C0D2D2EF89ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9E55298D557C8533ULL + 0xF95C974C7F72EAE6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF50C6AA2859EE631ULL + 0xDCC6F13A9E505D8CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD01995771914C579ULL + 0xB40942F8B0FE07A9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF99C6BF644A9FB7DULL + 0xAB3D4F7F80BF17F9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFDD5F21354F305B5ULL + 0xBA565C6C421F4167ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD483EB7D349A0BBDULL + 0xC0912AFF9006159DULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneC, aInvestLaneB, aFireLaneB, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 477U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 5410U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4947U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5386U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4525U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 60U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 6068543441070417854U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 29U)) + 2995980468193441856U) + aNonceWordE;
            aOrbiterC = (aWandererE + RotL64(aScatter, 47U)) + 18020277482171594003U;
            aOrbiterH = ((((aWandererH + RotL64(aPrevious, 58U)) + RotL64(aCarry, 47U)) + 4293807434721230702U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 7980599111583893156U) + aPhaseAOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 8593141111851052016U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 5903487523900084325U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 2508618861111356699U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15112035513447930209U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9854037263057006439U;
            aOrbiterB = RotL64((aOrbiterB * 396276470208637283U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 16759760289688823193U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12622628933030601390U;
            aOrbiterJ = RotL64((aOrbiterJ * 2151912984825538321U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1264668857268123425U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16302812053619101593U;
            aOrbiterG = RotL64((aOrbiterG * 18291400055836111547U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16087995784896123610U) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7970269262800468363U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14924752223305807461U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 52U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 37U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + aPhaseAWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 42U) + aOrbiterG) + RotL64(aOrbiterC, 5U)) + aNonceWordP) + aPhaseAWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9363U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 10284U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 9695U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9935U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8037U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 252059974543142812U) + aNonceWordG;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 11690823093681457368U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 57U)) + 13282189752890971123U) + aPhaseAOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 19U)) + 9507416294305708435U) + aNonceWordC;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 34U)) + RotL64(aCarry, 5U)) + 14053038174390776539U) + aNonceWordA;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14605253312318725009U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 18138286582677863671U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 10595905899691011321U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8530091235978489988U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14381731677571170073U;
            aOrbiterA = RotL64((aOrbiterA * 11675896999665768253U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13316413456378978456U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3910529530149320706U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16000139333493588429U), 5U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 6302070286831566901U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12324134652758551396U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 17136438281540250165U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4773478557638475048U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4031153435446078944U;
            aOrbiterH = RotL64((aOrbiterH * 3876928995240982769U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 41U)) + aOrbiterC) + aNonceWordL) + aPhaseAWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + aNonceWordD);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 39U) + RotL64(aOrbiterA, 28U)) + aOrbiterC) + aNonceWordP) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 57U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13285U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 12243U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12407U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13713U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11149U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 14112U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 58U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 17454559218352016650U) + aPhaseAOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 5U)) + 8005709669325164803U) + aNonceWordN;
            aOrbiterC = ((((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 13393741948412816357U) + aPhaseAOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (((aWandererI + RotL64(aCross, 30U)) + RotL64(aCarry, 27U)) + 3665865624348875553U) + aNonceWordJ;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 47U)) + 8334142570031883436U) + aNonceWordK;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17226066128706139657U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3319093033121522613U;
            aOrbiterC = RotL64((aOrbiterC * 17961784341097933029U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6657535603401588798U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 5469746182326331147U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 11315450342347794329U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17846791786050221418U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15939541003714896288U;
            aOrbiterH = RotL64((aOrbiterH * 1400351482213119809U), 53U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 12076763190461077406U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3594038213596405284U;
            aOrbiterG = RotL64((aOrbiterG * 10244002692575821495U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 8301291631324464622U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8460406137668390582U;
            aOrbiterI = RotL64((aOrbiterI * 9117147929757711595U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + aNonceWordL) + aPhaseAWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterC, 34U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 30U) + aOrbiterI) + RotL64(aOrbiterC, 23U)) + aNonceWordA);
            aWandererD = aWandererD + (((((RotL64(aCross, 21U) + RotL64(aOrbiterG, 43U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordM) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20848U)) & S_BLOCK1], 26U) ^ RotL64(aInvestLaneA[((aIndex + 21718U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 18861U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17905U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19859U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 16766U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 17264605017518259932U) + aNonceWordG;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 35U)) + 15209184354580778643U) + aNonceWordB;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 21U)) + 3299527965014731384U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 16293096431816127821U) + aNonceWordP;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 48U)) + RotL64(aCarry, 51U)) + 11031983436878828337U) + aPhaseAOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9188018632448236358U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 13420816400363406556U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 10958221259662190519U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2485063384097917101U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3089135816938128264U;
            aOrbiterJ = RotL64((aOrbiterJ * 8813152992957361153U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10730544971770435788U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10431767565618874806U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 4723078464590561545U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 14883796491656899074U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13465877783538483706U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14311686051108108503U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13322163435314643713U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3307316600284371955U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 12337846092069506365U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 54U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterG, 3U)) + aOrbiterF) + aNonceWordK);
            aWandererD = aWandererD + (((((RotL64(aCross, 29U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordA) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterF, 35U)) + aNonceWordL) + aPhaseAWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21887U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 27025U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 24198U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22288U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24008U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 24689U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 56U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = (((aWandererD + RotL64(aScatter, 36U)) + 12311607308490066301U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aWandererA + RotL64(aCross, 47U)) + 13100864684740679846U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 13697304189274329704U) + aNonceWordI;
            aOrbiterE = ((((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 9047976902871216732U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 2147897579538537888U) + aNonceWordD;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2072444829390996142U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 2129307836981020908U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 8065769537670939667U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10663145333751112064U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15019844390503785459U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 7442321463110790449U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5460865577557928142U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15806522559993224197U;
            aOrbiterB = RotL64((aOrbiterB * 8722932687972240099U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6361113778657833389U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 8306013884615042570U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 8234258702656728667U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4038420580499706912U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11908091484457158973U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 3964111175645156719U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 35U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterE, 38U)) + aNonceWordC) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordA) + aPhaseAWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterI, 21U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28668U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 27807U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31669U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31260U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29802U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29379U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 39U)) + 15813325389431304548U) + aNonceWordA;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 2223874171125403602U) + aNonceWordK;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 39U)) + 5510483568496824130U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 15474152493495661876U;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 21U)) + 16846339705130829195U) + aPhaseAOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1289670576865739669U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 18017354919647006944U;
            aOrbiterE = RotL64((aOrbiterE * 13103155460891498469U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8539685539928984921U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3333721400836704048U;
            aOrbiterI = RotL64((aOrbiterI * 3745286323481400085U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2261560416623815491U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4377786131746816567U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 9164777834392621157U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 18047393176583722719U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8184724021940434631U;
            aOrbiterK = RotL64((aOrbiterK * 9800116157750921119U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10469895939183324807U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14543391765109879223U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4817987697437667225U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 4U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + aNonceWordD);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aNonceWordE);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 11U)) + aNonceWordN) + aPhaseAWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Lacrosse_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE388FB1DBC8B3CE7ULL + 0xBEAF719987ACA63FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEBC58978AB917F5DULL + 0xA4279ED619DDFAE5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8948F8C26CDED733ULL + 0x81ADDE9C47C4C34AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD200CACDB6A97A57ULL + 0xA93927F5B549044DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC4B562830DB8D4F1ULL + 0xF2B9ACA5FB552193ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC76FAE7F28DD6E1BULL + 0xEE139B55722628B4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA4E50544A5EEFD79ULL + 0xA09FCAE7E9553412ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEDF504D59B18A465ULL + 0xA4096A7C5CC0675FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF13602E886A1E769ULL + 0xAC19C620B58B10E2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC4566FEAD1138805ULL + 0x87746B81A762592EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE435C9C2E02738FFULL + 0xDAA7582B7080F811ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x94166412A6B21661ULL + 0xADA8C40B9BC462CEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA7841F7D495A7325ULL + 0xDC27C57DCF759321ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9546C7A89ADC27BBULL + 0xE3A3BEB0B3E4E7ECULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCDF04ECDAB28F0FFULL + 0xDF68A2D3BF8197F9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC599D379DCE8D29DULL + 0x93628943CB4C49FDULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneB, aInvestLaneC, aExpandLaneD, aFireLaneD, aInvestLaneD, aExpandLaneC, aWorkLaneA, aFireLaneC, aWorkLaneB, aExpandLaneA, aWorkLaneC, aFireLaneB
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1340U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 4272U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 530U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 549U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1638U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3773U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 48U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = ((((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 12690502671561165478U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 29U)) + 17519943923428102801U) + aNonceWordH;
            aOrbiterB = (aWandererG + RotL64(aIngress, 23U)) + 10705515807975331385U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 3U)) + 16586447272278538179U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 42U)) + RotL64(aCarry, 47U)) + 8006560996840971798U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 12928600185788857701U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 19U)) + 14240723153798267172U;
            aOrbiterD = (aWandererH + RotL64(aCross, 51U)) + 8636219177994872072U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 36U)) + 7586790235186467512U) + aPhaseBOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1103807034179512424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7547526530239498693U;
            aOrbiterB = RotL64((aOrbiterB * 3360295583636013509U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8380239679344786397U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5690809173787433519U;
            aOrbiterI = RotL64((aOrbiterI * 5354724308093372953U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8390902801141804609U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3507306189192059486U;
            aOrbiterK = RotL64((aOrbiterK * 18336280496510253103U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6190745292098482871U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 8065418693975056902U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 6414621418430102589U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12111755051718111803U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7605877769709909297U;
            aOrbiterG = RotL64((aOrbiterG * 17525248694315944599U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5969794501112646237U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5127559299360591476U;
            aOrbiterJ = RotL64((aOrbiterJ * 4521563633438853069U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10593847754747739786U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4401750688524310121U;
            aOrbiterH = RotL64((aOrbiterH * 14265829318976633707U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6927893132508779499U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4874009978647014479U;
            aOrbiterC = RotL64((aOrbiterC * 13340466017023540755U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13146693487138744677U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3298472134223595298U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2145005258008477281U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 24U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterF, 23U));
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 38U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterI, 27U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + aNonceWordK);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterC, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneD
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9733U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 9628U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8249U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 9935U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6993U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10220U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10474U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 24U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (aWandererG + RotL64(aPrevious, 24U)) + 6654158889644956636U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 9045779659363991870U) + aNonceWordK;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 35U)) + 3888897662136993491U) + aPhaseBOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 47U)) + 6882016842864459345U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 11U)) + 15601891715956172291U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 41U)) + 5176811598629335350U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 12519945150889074325U) + aNonceWordE;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 4552583214397603278U) + aNonceWordD;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 58U)) + 14225482701804864688U) + aNonceWordC;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5485298070606280363U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 11237713257388094289U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 11032429223099413011U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14340345895626142788U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16275167270553643347U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 7308578867128951199U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14041860597556520250U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1436068974197066343U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3938460345031496843U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11483155566419547004U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4608508534724289325U;
            aOrbiterE = RotL64((aOrbiterE * 13461385011638899485U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2389196334288832895U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4062682330273866602U;
            aOrbiterD = RotL64((aOrbiterD * 8787682133271101901U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5655656046585592034U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7977947821249746880U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 10082104644185964787U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11653718118543974168U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5456429682072377614U;
            aOrbiterJ = RotL64((aOrbiterJ * 12504180638665296649U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12457179652004203574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 445821754230182952U;
            aOrbiterF = RotL64((aOrbiterF * 16043092621697786393U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12429505513284703263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12480745784412363537U;
            aOrbiterI = RotL64((aOrbiterI * 643617210585287593U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 30U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterK, 47U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 10U)) + aOrbiterJ) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + aNonceWordB);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 4U)) + aOrbiterK) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterE) + aPhaseBWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneC
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13879U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 15359U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15054U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13913U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 13441U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 13U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 30U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 12615321415808640429U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 15712784676459931207U) + aPhaseBOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 14U)) + 11013335427004930046U) + aNonceWordO;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 8298733856304768806U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 57U)) + 6207732959150824216U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 47U)) + 9769864876127544038U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 3U)) + 10782181918651152563U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 21U)) + 5790454015845620939U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 28U)) + 15606578025386733803U) + aNonceWordJ;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5522352539991175304U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5993355818572869649U;
            aOrbiterG = RotL64((aOrbiterG * 15221467311057431139U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10864534396947622047U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12090053126235913528U;
            aOrbiterK = RotL64((aOrbiterK * 7250801471645972261U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14191181677234981396U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2258570108233924592U;
            aOrbiterH = RotL64((aOrbiterH * 8307541155393855209U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8448114811381534603U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2702389315763499817U;
            aOrbiterE = RotL64((aOrbiterE * 6710443836432274393U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17202184076718780200U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 150549910056015002U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 195034681254956335U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4910512055808124967U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4783477997418403079U;
            aOrbiterA = RotL64((aOrbiterA * 861977492146512865U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13842899106208709771U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7930112618036681468U;
            aOrbiterD = RotL64((aOrbiterD * 8609551859830858419U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 8790107242863198659U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6882768826643279144U;
            aOrbiterI = RotL64((aOrbiterI * 13745521454063360763U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12136498871759890015U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8120456314755584336U;
            aOrbiterF = RotL64((aOrbiterF * 1830725195528043575U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 6U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 58U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterA, 13U)) + aNonceWordH);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterF, 36U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterI, 27U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 52U) + aOrbiterI) + RotL64(aOrbiterE, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterG, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 52U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 44U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 20587U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneC[((aIndex + 20970U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 19673U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17953U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((aIndex + 16872U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 6U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 47U)) + 13960289014350612206U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 21U)) + 3483331015269589730U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 52U)) + 6873299241002444518U) + aPhaseBOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 43U)) + 3562094007125534229U) + aNonceWordN;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 57U)) + 11422367439932782705U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 532453428514259816U) + aNonceWordE;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 17810941465810193088U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 11869759058631106331U) + aNonceWordB;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 28U)) + 8837581071876177566U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17185378327053837778U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7578253375676981500U;
            aOrbiterA = RotL64((aOrbiterA * 13371647568758721729U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17112646434432814442U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14949096407295697881U;
            aOrbiterG = RotL64((aOrbiterG * 14770977858283051753U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4259590620758467836U) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6534899413644542303U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 7987609419215568661U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 2637407498893694243U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15819295597921425711U;
            aOrbiterB = RotL64((aOrbiterB * 5202015597375051399U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6373559542002699718U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11694562937392022505U;
            aOrbiterE = RotL64((aOrbiterE * 9311557972331218597U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3308736483775453062U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12749929710650475901U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 248428400724560945U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1569528215675579656U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1044077933631689572U;
            aOrbiterC = RotL64((aOrbiterC * 6443796233912755143U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8393422728124537471U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2002732612516530754U;
            aOrbiterI = RotL64((aOrbiterI * 13702146823622364279U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13469191942843147943U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7633171368709520560U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 9713514012478203047U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 12U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterE, 39U));
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterH, 5U)) + aNonceWordO);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + aNonceWordM) + aPhaseBWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI + ((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 30U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24567U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneD[((aIndex + 23076U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 25018U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24011U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22769U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 10U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 57U)) + 7960325128608297381U) + aNonceWordL;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 27U)) + 12773836012104052042U) + aPhaseBOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aCross, 23U)) + 3173972621347773016U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 11U)) + 3708401356314308171U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 35U)) + 950774285720019449U) + aNonceWordD;
            aOrbiterH = ((aWandererI + RotL64(aCross, 18U)) + RotL64(aCarry, 3U)) + 4170092315705438265U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 47U)) + 17000449130864980747U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 8793910540062893860U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 43U)) + 520277969543516469U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12762214857389827271U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2932451184340207695U;
            aOrbiterC = RotL64((aOrbiterC * 7513337346940091655U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11062179998786293839U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7919119215271524178U;
            aOrbiterD = RotL64((aOrbiterD * 9053677007180081359U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1774988449597115155U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3799792889466518953U;
            aOrbiterI = RotL64((aOrbiterI * 17512791286490623455U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1815062051307896589U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15260373951371654483U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 2208604434669491625U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12867546628945676853U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 7772820973895846946U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 7581704643538761985U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14213957831821966834U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16561105721170419454U;
            aOrbiterH = RotL64((aOrbiterH * 2540533987337175367U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16556502948339949526U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9706742922075498974U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8527361328901355457U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13455756934917486016U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9107769876332723454U;
            aOrbiterJ = RotL64((aOrbiterJ * 1722386100852683783U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15793099079168487016U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7968278803691283365U;
            aOrbiterB = RotL64((aOrbiterB * 11644765391940099387U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 38U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 24U) + aOrbiterD) + RotL64(aOrbiterB, 42U)) + aPhaseBWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 6U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterI, 19U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31341U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 31719U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27965U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27314U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 27942U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (aWandererD + RotL64(aCross, 28U)) + 8604208734152026945U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 57U)) + 1374329953253889829U) + aPhaseBOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 5779278910548228339U) + aNonceWordJ;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 41U)) + 17670451230882805140U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aWandererK + RotL64(aScatter, 23U)) + 8193848740764866860U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 3U)) + 15801168428145650104U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 2584718176087499066U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 48U)) + RotL64(aCarry, 35U)) + 14950366247822737997U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 53U)) + 9779293225265670135U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 8688968319288372383U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13665723186950342601U;
            aOrbiterJ = RotL64((aOrbiterJ * 292035540396910837U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9395428688359973510U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2152719218018108418U;
            aOrbiterA = RotL64((aOrbiterA * 15271961483518392671U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1350324137411377992U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8729317951386057921U;
            aOrbiterI = RotL64((aOrbiterI * 6008790836417785083U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6317310451893678411U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10175620379041384281U;
            aOrbiterK = RotL64((aOrbiterK * 14079679617394330781U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1203082119358827708U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 523869107818193101U;
            aOrbiterB = RotL64((aOrbiterB * 4629501113595689157U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4028324959540432983U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15447631947468213912U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6037306615787729185U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14225888694733041031U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11925000696281947629U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4337022940520411253U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15015531024930608745U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16752579225076943550U;
            aOrbiterE = RotL64((aOrbiterE * 15551083683579981439U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2432733494869267901U) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10103430321388601485U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18372919379972432569U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 50U) + aOrbiterK) + RotL64(aOrbiterA, 23U)) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterA, 18U)) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 39U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 29U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 12U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 46U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + aNonceWordM) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Lacrosse_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8DA917FD7994D1F5ULL + 0x8C6123B862E0C20AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x96FD133DFD79B0A1ULL + 0xC268008939A487CEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD52CD87976E95B73ULL + 0x8E763AF4C31A5B1DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9681F6051425AFBBULL + 0x8ADF0AAC9DE28BABULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9E55659B0A6B41D1ULL + 0xE418DE7D7264F659ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE3B248B3E21B05E1ULL + 0xFD83EDA70EFF7D1CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFA3697CC82DEBBE1ULL + 0xE305AD693AE078DEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBCEB42486D5D8069ULL + 0x96D2561DB2BAD06DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB171E736613A19BDULL + 0xD1C46318D07E8CDDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x868B93616DC085F9ULL + 0x9C4D9248FD76B5F8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x84012B9A1FCBC68FULL + 0xF9EC93BF4F1BC618ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBFD0972F13948361ULL + 0xF9D7461CB800CBD3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9D06C46D55025D89ULL + 0xA87573CA33A78D8AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEF934F694DF0CC03ULL + 0xD3CDAA78B2ED09C6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9E9F38D4371035C9ULL + 0xB59840A795EE252EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x993D4F80A8DEDFA7ULL + 0xDBFF4C4D37C611AFULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4419U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 3821U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 752U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 636U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 676U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 928U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = (((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 11700815697312060726U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 57U)) + 11808423452327465441U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 8670503858631730886U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 2400061067991988544U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 4U)) + 16163118178366229686U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 35U)) + 3280178595904941068U) + aNonceWordP;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 51U)) + 3298683600817047727U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16321624053445183574U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6730229877611375225U;
            aOrbiterC = RotL64((aOrbiterC * 2022290495153519279U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10162830636713641322U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15646771327759599256U;
            aOrbiterG = RotL64((aOrbiterG * 15333053762177144775U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14841751262270544102U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9545541117228834895U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11529769874752969377U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14676615635857599982U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1231768638470558855U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 1945905595345404833U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1406171421638586846U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 4577864352425476233U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1970292335806697198U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12309719390375013297U;
            aOrbiterE = RotL64((aOrbiterE * 16540660957923687327U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5352135521358954576U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15465675376193501658U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 16385761112921041387U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 22U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterE);
            aWandererE = aWandererE + (((((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 58U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aNonceWordO) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 29U));
            aWandererI = aWandererI + ((((RotL64(aCross, 53U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7764U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 10250U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6966U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 9299U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7395U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8357U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 10392U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 4U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 37U)) + 14214886793361825363U) + aNonceWordK;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 23U)) + 17267959031078766320U) + aPhaseDOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 29U)) + 16436067429484887644U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 37U)) + 9885951769332633820U) + aNonceWordI;
            aOrbiterF = (aWandererC + RotL64(aScatter, 11U)) + 12971711341813893304U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 199970353398450154U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 1237341696444162094U) + aNonceWordB;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 7991128854417613360U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14809029847149045833U;
            aOrbiterA = RotL64((aOrbiterA * 5940857360838299105U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2559509556915775947U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14336829730147834160U;
            aOrbiterF = RotL64((aOrbiterF * 15103242520064900873U), 47U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 8853631886733610440U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13346159398673246914U;
            aOrbiterK = RotL64((aOrbiterK * 13660497151446983393U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12121095718571872976U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16239781125815589804U;
            aOrbiterE = RotL64((aOrbiterE * 5157009090454962231U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9051377033794324106U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13805815136723461780U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 571129481747181357U), 53U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 14849157800322754413U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18116651528452542634U;
            aOrbiterH = RotL64((aOrbiterH * 3638480428016835537U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4105057226952948599U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5911714320560994391U;
            aOrbiterD = RotL64((aOrbiterD * 1796514171654961389U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 12U) + RotL64(aOrbiterA, 41U)) + aOrbiterK) + aNonceWordG) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterF, 56U)) + RotL64(aCarry, 53U)) + aNonceWordP) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 5U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterK, 23U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15775U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 14305U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 12483U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12335U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15065U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 19U)) + 6163290588946759209U) + aNonceWordI;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 7342672468560105447U) + aPhaseDOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 11574563167017282321U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 2254820206194758964U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 4U)) + 1469783447473099498U) + aPhaseDOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aWandererA + RotL64(aIngress, 51U)) + 14174828900676165088U;
            aOrbiterB = (aWandererC + RotL64(aCross, 57U)) + 16277954291890598132U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 14845750668693136766U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 150099699692047766U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7644895634421086357U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1200784917165131703U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 9469982764806754302U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 17851969334511301943U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10956702761701710182U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7915506894975487807U;
            aOrbiterH = RotL64((aOrbiterH * 8874108311712727983U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17335794183733623213U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 557028996286989506U;
            aOrbiterB = RotL64((aOrbiterB * 3993359298602424281U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 1597385667771002414U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4376417959915162639U;
            aOrbiterJ = RotL64((aOrbiterJ * 4626236858205178149U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 549770198518993876U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 756554555648070919U;
            aOrbiterG = RotL64((aOrbiterG * 16272320259614325355U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7298557532533152193U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3336802611342112013U;
            aOrbiterK = RotL64((aOrbiterK * 14679103452120080499U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 54U) + aOrbiterK) + RotL64(aOrbiterB, 46U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + aNonceWordK);
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterH, 37U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 57U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterK, 13U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + aNonceWordL) + aPhaseDWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19880U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 17950U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 16385U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19734U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((aIndex + 20865U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 12029393034357490020U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 11U)) + 4526754731580694987U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 56U)) + RotL64(aCarry, 29U)) + 17060419646421271853U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 29U)) + 4128488893837059683U) + aNonceWordE;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 12706894827547160110U) + aNonceWordJ;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 35U)) + 12506324593645825056U) + aNonceWordP;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 47U)) + 12581344490649250025U) + aNonceWordB;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14357032418199130132U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15341977701796331249U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6332369248718076031U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7086602307544733241U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12398300065276832486U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18157408831225635333U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2499745046076601988U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7249361592814001829U;
            aOrbiterB = RotL64((aOrbiterB * 14597139848072319685U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3254456186337366437U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3472973415969046680U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 14583566953969168353U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 7905718972111691591U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15941413652144021522U;
            aOrbiterG = RotL64((aOrbiterG * 3473779492962783565U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10583964125960308762U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 13659925272340853715U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16708294803316630743U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9487054537489454887U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13287757570441887517U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 17351439045329892107U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 34U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aCross, 41U) + RotL64(aOrbiterC, 48U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + aPhaseDWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterI, 13U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterB, 5U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 22U) + RotL64(aOrbiterI, 19U)) + aOrbiterB) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25539U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((aIndex + 23156U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24953U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26532U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneA[((aIndex + 22202U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 21U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 10404808878585437255U) + aNonceWordM;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 11U)) + 10587858736301591439U) + aPhaseDOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 53U)) + 1430530909801644435U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 9090938022430118902U;
            aOrbiterC = (aWandererC + RotL64(aCross, 29U)) + 12936604311751121235U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 37U)) + 1000583006020232032U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 21U)) + 12352532088997042232U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 16723410947058502564U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 16614089235313154270U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 11530998303573027827U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4245553025593349277U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3353146318549477494U;
            aOrbiterC = RotL64((aOrbiterC * 14246377408238318091U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5935727336135635196U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10312187090293319667U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1395964500396711899U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12192843181244744484U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 2542570124502586365U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 17222847847573534963U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3315472769469002444U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 17512858811783071174U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 9070400454074283765U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16633218007427888082U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2502077714838858460U;
            aOrbiterA = RotL64((aOrbiterA * 970762420815997725U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14792910273226469214U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15739513291150783151U;
            aOrbiterD = RotL64((aOrbiterD * 11896279674116906915U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 60U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + aPhaseDWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + aNonceWordH);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterD, 27U)) + aNonceWordF);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 28945U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 28522U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 27851U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30311U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32641U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 39U) + RotL64(aCarry, 14U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (((aWandererE + RotL64(aCross, 58U)) + 18180797995100240808U) + aPhaseDOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 6585906608223552885U) + aNonceWordO;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 27U)) + 14088708930575939855U) + aNonceWordE;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 21U)) + 468974153311516044U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 12481951025619894110U) + aPhaseDOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 17227987923860711763U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 43U)) + 4373962756657477139U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2077576476565420951U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17435011300234663764U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 8910133867294004711U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4118039398293246896U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13724716599855216683U;
            aOrbiterJ = RotL64((aOrbiterJ * 17556333902751079677U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 12391461204689596339U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9900605191533799627U;
            aOrbiterE = RotL64((aOrbiterE * 13553565332531046301U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 972946858824366125U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17247681919694541215U;
            aOrbiterG = RotL64((aOrbiterG * 2974639094630445643U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15442851427306771601U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7303586227288294037U;
            aOrbiterK = RotL64((aOrbiterK * 15406402525021428799U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12650358753454105119U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1483710933373510492U;
            aOrbiterI = RotL64((aOrbiterI * 6531763256577221891U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 18065810162229740788U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11311677121338794007U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15116367961682119467U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + aNonceWordL);
            aWandererI = aWandererI + (((((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 57U)) + aNonceWordP) + aPhaseDWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 51U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 58U) + aOrbiterC) + RotL64(aOrbiterJ, 34U)) + RotL64(aCarry, 19U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 40U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Lacrosse_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC38EBFFD29E0BAC1ULL + 0x8F395384024F69C1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8ECBDBDBB1C96943ULL + 0xE03FE82044CB3AD2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBBC154F073744851ULL + 0xF26E90C0E5C904CCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA1D65518FE240463ULL + 0xA9CDE85DC02B1F75ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF97E255E29B0D941ULL + 0xABAD0398CAFA7705ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF9660A50CC439DE5ULL + 0xD402E6D0E4E17B42ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE9D15EC01232E847ULL + 0x9F56401B569DAD75ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEA30FDA0BFC39A5BULL + 0x826BB45FEC1C5508ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA476154D847EBB39ULL + 0xB33A6BFD9D1DBEADULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9FA77C1FC4957E9FULL + 0xF18A9ECFEB26DE60ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBB56D18A0B23819BULL + 0xE82C6974F95C80E7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDC857FBCB1CD928FULL + 0xE45DE7788BAD225DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF7C3A868B8DC0185ULL + 0xAA1F4ADD17AE0821ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD630DF048FE36C05ULL + 0xCA73F722E08CCD31ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCC954E589F9448C5ULL + 0xB6AEC13C6F0AE38EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEC3D5F6103675C9BULL + 0xEC9EF07BFC312F3BULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3264U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((aIndex + 151U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4657U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1874U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 950U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 558U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = (aWandererB + RotL64(aIngress, 37U)) + 15726877954695761686U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 26U)) + RotL64(aCarry, 41U)) + 14187652171881943587U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 3U)) + 8420423151313882782U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 53U)) + 14942322692433259283U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 7272331475919796255U) + aNonceWordJ;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 41U)) + 154504365041805840U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 47U)) + 17475491222554948786U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aWandererI + RotL64(aCross, 18U)) + 5759181483165339605U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 5U)) + 5993060214499322845U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 10901786237875941844U) + aPhaseEOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 11U)) + 17135786595614068473U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 5208202073886811165U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6821452921018900631U;
            aOrbiterF = RotL64((aOrbiterF * 13119330055184115669U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13348064837402206969U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8967943922403445136U;
            aOrbiterI = RotL64((aOrbiterI * 300168481725373093U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8130283784171430891U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6351113882502502876U;
            aOrbiterG = RotL64((aOrbiterG * 15960622823993072903U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6894708729226455769U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12065058511247133944U;
            aOrbiterD = RotL64((aOrbiterD * 5432601727436935831U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17138279326229372741U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12987698199066890628U;
            aOrbiterC = RotL64((aOrbiterC * 12665716655177320977U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13688833537574196675U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4211971980434000618U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1374411763361518851U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10376917117582537592U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4807742522197923516U;
            aOrbiterJ = RotL64((aOrbiterJ * 15257251453302090961U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 18038296468177121243U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6879666349379745258U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 15819475269715810555U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5193656664432659624U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 680899397323387963U;
            aOrbiterE = RotL64((aOrbiterE * 9857476056194621321U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1851929589073547860U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13093101559415170218U;
            aOrbiterB = RotL64((aOrbiterB * 13950928576652143737U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13695333301427028607U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 15726877954695761686U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 960063676226172027U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 58U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterG, 37U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererE = aWandererE + ((((RotL64(aCross, 18U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 35U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterE, 52U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterE, 29U));
            aWandererB = aWandererB + (((RotL64(aScatter, 4U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterH, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterA, 34U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 7244U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 7616U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 9575U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9020U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6597U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 5774U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 10414U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 13U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (aWandererK + RotL64(aIngress, 57U)) + 10881271196314989997U;
            aOrbiterC = (aWandererB + RotL64(aCross, 19U)) + 6406461249988567558U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 21U)) + 17255067918280095959U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 16690850682497718411U) + aNonceWordL;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 40U)) + 5576201059361086866U;
            aOrbiterG = (aWandererA + RotL64(aCross, 37U)) + 11991259685693687554U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 43U)) + 14652535244217836909U) + aPhaseEOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 13U)) + 1701789037170782122U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 46U)) + RotL64(aCarry, 43U)) + 953429054903473833U) + aPhaseEOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 12064513610469714211U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 27U)) + 7993881398822002424U) + aNonceWordO;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14421313768013320050U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 11112386845630998889U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 11771526352030371669U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17069630896535699015U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3308240081138623373U;
            aOrbiterG = RotL64((aOrbiterG * 10449509484417835159U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 17615529807112933619U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11782807146851563541U;
            aOrbiterB = RotL64((aOrbiterB * 12992075832343669221U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14401645829607611983U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6736397344219993532U;
            aOrbiterC = RotL64((aOrbiterC * 1667287547938175641U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6446974060524700550U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7840991992443308254U;
            aOrbiterH = RotL64((aOrbiterH * 6891023544882740107U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10362169906019794305U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4503700997923168911U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15066164494038852559U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13492041134973259041U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14337899277551397976U;
            aOrbiterJ = RotL64((aOrbiterJ * 5966740718899290915U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13693100781608180748U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16177545026405910052U;
            aOrbiterE = RotL64((aOrbiterE * 6019231448444020563U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9641191118119415680U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 735491776764667034U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11305930862759869997U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2225714710491247284U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16906789796765378455U;
            aOrbiterA = RotL64((aOrbiterA * 4341667316266234469U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9451961177946601088U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10881271196314989997U;
            aOrbiterD = RotL64((aOrbiterD * 10929686721061541543U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 44U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterC, 23U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 30U) + aOrbiterC) + RotL64(aOrbiterG, 27U)) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterA, 54U)) + RotL64(aCarry, 39U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 39U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 41U)) + aOrbiterI) + aNonceWordA);
            aWandererG = aWandererG + ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 58U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterD, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 46U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 14414U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneA[((aIndex + 10960U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11674U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12582U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14970U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCarry, 38U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (aWandererI + RotL64(aCross, 21U)) + 18255347001097480328U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 13679246790311505735U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 10565839529765027116U) + aNonceWordJ;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 42U)) + RotL64(aCarry, 35U)) + 14327172566224769901U) + aPhaseEOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 23U)) + 16239024612038195174U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 37U)) + 13800012174212131890U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 35U)) + 13900288860157577583U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 57U)) + 4144386119777112740U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 11U)) + 3154558262670631372U) + aNonceWordM;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 30U)) + 7456728543137614001U) + aPhaseEOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aCross, 3U)) + 11709519851158935384U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15607438907832240304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9276575329661725624U;
            aOrbiterF = RotL64((aOrbiterF * 8879744070762412745U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6459435969129449226U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6442382118416542275U;
            aOrbiterK = RotL64((aOrbiterK * 2921027306686588233U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12117432107282150865U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6831279293184793243U;
            aOrbiterD = RotL64((aOrbiterD * 2435360641135249073U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9520022957804572889U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8322178689474588679U;
            aOrbiterB = RotL64((aOrbiterB * 1627707191467537115U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 4162401591586869316U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8994015844714895961U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15421910378057951895U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10038095909727959633U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 17756404450592957616U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 14255952184627347295U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3379089265413427719U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11341713098678108441U;
            aOrbiterE = RotL64((aOrbiterE * 2500587373161411961U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4030296130743454165U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6332387792111212064U;
            aOrbiterJ = RotL64((aOrbiterJ * 16490982218150897861U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14893209417387662133U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9265457389326311687U;
            aOrbiterA = RotL64((aOrbiterA * 9778404505547862689U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13496086915199406901U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14576555328710787951U;
            aOrbiterI = RotL64((aOrbiterI * 13155395071667672943U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11482324648071976743U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 18255347001097480328U;
            aOrbiterH = RotL64((aOrbiterH * 10918514878283385643U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 50U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterE, 46U)) + aPhaseEWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 46U) + aOrbiterI) + RotL64(aOrbiterB, 29U)) + aPhaseEWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterH, 51U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterI) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 24U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 22U) + aOrbiterG) + RotL64(aOrbiterA, 37U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterC, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 12U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16600U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((aIndex + 17873U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16597U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17006U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18248U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 48U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 10336802574069791273U) + aNonceWordK;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 14U)) + RotL64(aCarry, 37U)) + 169025388197058936U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 47U)) + 6541354188379168846U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 5U)) + 16223920526599306104U) + aNonceWordP;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 3U)) + 12756613707692514808U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aCross, 56U)) + 5082475548176484035U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 53U)) + 4907435526952698526U) + aNonceWordB;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 35U)) + 14236627073831834337U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 41U)) + 11502511046130497584U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 3679044835550219497U) + aNonceWordJ;
            aOrbiterK = (aWandererC + RotL64(aIngress, 43U)) + 11254838916686736746U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10582608424233200966U) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10449735026385340313U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 7363770199734997411U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4628253464169957835U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17664454668473204465U;
            aOrbiterC = RotL64((aOrbiterC * 4234720298731378527U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3798386391743884889U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1379331161819246587U;
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9816600392407327227U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16781971616348376878U;
            aOrbiterI = RotL64((aOrbiterI * 12503867584828289879U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4807797577690520554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2492057261148595922U;
            aOrbiterH = RotL64((aOrbiterH * 9453302540675483005U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7909676419643119585U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 256053568910383007U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11965085163352053161U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16179914439220412472U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3968867762761955845U;
            aOrbiterG = RotL64((aOrbiterG * 7473632378251893139U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7474832923901283742U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4736994731050735779U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 9839654409121414047U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 596484364660389193U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13822222274464306169U;
            aOrbiterB = RotL64((aOrbiterB * 1723502278319885511U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 16307920280681985443U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3505106171801702915U;
            aOrbiterK = RotL64((aOrbiterK * 8479675421552861243U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4987142580981135150U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10336802574069791273U;
            aOrbiterJ = RotL64((aOrbiterJ * 2670706512498539705U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 60U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterF, 43U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 27U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 24U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterB, 30U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 37U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 39U)) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterA, 41U));
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterE, 60U)) + aNonceWordH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 18U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23193U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneB[((aIndex + 24046U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 26199U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25665U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25236U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26420U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 52U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererK + RotL64(aScatter, 3U)) + 4622023259121087483U) + aNonceWordK;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 10253505250223501352U) + aNonceWordH;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 27U)) + 17133877904420462669U) + aPhaseEOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aWandererD + RotL64(aCross, 48U)) + 6162827793741796700U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 29U)) + 9610986424765907615U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 23U)) + 11210747154264753754U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 41U)) + 16554205219580654546U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 18U)) + RotL64(aCarry, 53U)) + 10352576357413766388U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 57U)) + 3651845783283479752U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 18145542190463500476U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 35U)) + 5415609566767162857U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2033734872464201570U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3507213117125813345U;
            aOrbiterH = RotL64((aOrbiterH * 5453058336688881113U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8716253393049851856U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 695984869565941856U;
            aOrbiterD = RotL64((aOrbiterD * 8377921610764044735U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7661578828878284931U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 906654265099155956U;
            aOrbiterB = RotL64((aOrbiterB * 8117625377607536949U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6050049984731254612U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17882717590338190821U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10807367411402733215U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4996521991532815957U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4246460672800604436U;
            aOrbiterA = RotL64((aOrbiterA * 12047466401960824903U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8700148116452518842U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10039050281847466206U;
            aOrbiterF = RotL64((aOrbiterF * 11884791271239660157U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 4513844680425845372U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3037563127442815153U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 18363509277992292407U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1005237931570968724U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1373258132025712065U;
            aOrbiterJ = RotL64((aOrbiterJ * 10458020799382532395U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12759144329395682277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5139371668116336931U;
            aOrbiterE = RotL64((aOrbiterE * 10761543179345026943U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3211005174890625715U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18045286961878287418U;
            aOrbiterK = RotL64((aOrbiterK * 4536094526540761611U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4454078771279674978U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4622023259121087483U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8991756794989027019U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 41U)) + aOrbiterI) + aNonceWordA) + aPhaseEWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 34U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG) + aNonceWordG);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterE, 36U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 50U) + aOrbiterF) + RotL64(aOrbiterD, 11U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterE, 48U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterE, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31278U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 32478U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29464U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30552U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneB[((aIndex + 31946U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 34U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (aWandererE + RotL64(aCross, 3U)) + 9774364261626083532U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 18059001521926116420U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 30U)) + 10615626210406381148U) + aNonceWordG;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 5U)) + 10536484278007898620U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 37U)) + 13320663045139972700U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 17127001787268166583U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aIngress, 51U)) + 16742574590844166551U) + aPhaseEOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aWandererB + RotL64(aCross, 23U)) + 8347719720758228053U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 44U)) + 13502468705946051986U) + aNonceWordI;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 3512687886188904904U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 47U)) + 495660316165795934U) + aNonceWordM;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5092722552034477356U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15641128019608284015U;
            aOrbiterD = RotL64((aOrbiterD * 3621036395703527059U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15421873776811085458U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17978775513204574125U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 18359600395119440183U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16617179197537669849U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1931805387534012528U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3400139345857733775U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9544923119559308431U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12930999400470173353U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 16791006919271490005U), 43U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 13673733276226249890U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2032263473309124738U;
            aOrbiterJ = RotL64((aOrbiterJ * 3088728329261360607U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14868502349358414206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10116495537187552321U;
            aOrbiterF = RotL64((aOrbiterF * 1380512121796709469U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5341113995358179244U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8415417980279705731U;
            aOrbiterG = RotL64((aOrbiterG * 8521501372683793821U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2462819265072352463U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7657062767608441931U;
            aOrbiterK = RotL64((aOrbiterK * 15554638801273540163U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 8153420530633265789U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10990681417675210534U;
            aOrbiterB = RotL64((aOrbiterB * 1928509513380702895U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17035995983178569271U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2806563871848226777U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4137935663733587867U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6570698907081812011U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9774364261626083532U;
            aOrbiterI = RotL64((aOrbiterI * 1766375419340392741U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 6U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterG, 47U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 39U)) + aOrbiterB) + aNonceWordE);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 50U)) + aOrbiterA) + aNonceWordC) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 29U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 41U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 27U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 50U) + aOrbiterI) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 20U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterG, 5U));
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterH, 11U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 37U)) + aOrbiterK) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Lacrosse_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD3BD1FF4CAF484EDULL + 0xAEC69572968C9251ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x93E66A847AC7F763ULL + 0x94D96E3B6348C541ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9086CCCE2F2EF863ULL + 0xBC5AD3A02A898A59ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xED89D5CC91569A07ULL + 0xBA7E51716F88BA63ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC42C68C8C308F63DULL + 0x993B8FFE3F5AF792ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD1FB39C43127AED9ULL + 0x99E9D1A522854B3DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF466C43FCA730313ULL + 0x801BE90891A32AD3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8D372AAD6420137BULL + 0xC50798A005DB4EA3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9C9B81B7C9B1F98BULL + 0xE2F4B7B423EED646ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8568448D0B35C739ULL + 0xF2C992144B125B28ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC31FEDB22A0E3FD5ULL + 0x9A38F535E005C4FAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF06BCB988D4C4D5DULL + 0x9C1CC0EFE9CD5CA7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA777B6E3DA7AAA5BULL + 0xDB045ABC4C99CBACULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA990D5586A9E3945ULL + 0xF10EF783BBB42A10ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB4DB949BB8721673ULL + 0xCFF897DA78625BA8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC0C14E0AC4431E73ULL + 0x9B1433A996E76739ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneC, aSnowLaneA, aWorkLaneD, aSnowLaneD, aWorkLaneC, aExpandLaneA, aSnowLaneB, aExpandLaneB, aInvestLaneB, aExpandLaneC, aInvestLaneD
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3977U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 2500U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 4235U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1474U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 106U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2147U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 22U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 19U)) + 4204560462077827182U) + aNonceWordM;
            aOrbiterK = ((aWandererK + RotL64(aCross, 53U)) + 6572370199668594039U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aIngress, 27U)) + 15958999876732622825U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 46U)) + RotL64(aCarry, 27U)) + 9969349486879280377U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 15450238998293956181U) + aNonceWordD;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 9128619863683138259U;
            aOrbiterD = (aWandererG + RotL64(aCross, 5U)) + 5691270563628979565U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 42U)) + 5901029710568933106U) + aNonceWordO;
            aOrbiterA = ((aWandererA + RotL64(aCross, 35U)) + 10442738941988588834U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3508116020325721993U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13221917083569767259U;
            aOrbiterJ = RotL64((aOrbiterJ * 6845108555710135357U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 11627915460377128176U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17858261365514253433U;
            aOrbiterC = RotL64((aOrbiterC * 7535577636975884641U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4294837988806295989U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11242915481585070249U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 17540688242763829319U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13030663829236027109U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7451948220723185149U;
            aOrbiterG = RotL64((aOrbiterG * 5191778587712222029U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5575508866505031037U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5161096033789876794U;
            aOrbiterH = RotL64((aOrbiterH * 16843827915802461797U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3980482740649505122U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11188906150207270241U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 408550837615188413U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4435504916461645189U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9970252853543702833U;
            aOrbiterE = RotL64((aOrbiterE * 5829143716916091997U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 3766347619186305854U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11004616087340082895U;
            aOrbiterD = RotL64((aOrbiterD * 14469267845747063735U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17600791542296175812U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2556224430252009744U;
            aOrbiterB = RotL64((aOrbiterB * 14469426539907112137U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 26U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterD, 10U));
            aWandererK = aWandererK + ((RotL64(aCross, 48U) + RotL64(aOrbiterB, 57U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + aNonceWordH) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 5U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 14U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 52U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aSnowLaneA
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aSnowLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6231U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 10184U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10896U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneA[((aIndex + 6858U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8800U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10165U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 9998U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 51U)) + 14823268998003220191U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 3U)) + 15295237288788213847U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 47U)) + 16434853402001133899U) + aNonceWordH;
            aOrbiterB = (aWandererE + RotL64(aIngress, 24U)) + 7555911304407871631U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 14977248264994834620U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 57U)) + 9707764144919392380U) + aPhaseFOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 35U)) + 1277304385464681529U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 3089786220465849395U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 30U)) + RotL64(aCarry, 35U)) + 3700503853358695085U) + aNonceWordP;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3240054112993517371U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16897532076915366859U;
            aOrbiterK = RotL64((aOrbiterK * 4120874717534309035U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18167359289798364307U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8870819278575769863U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9334066154398059075U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15363069206212330251U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14858164441499725158U;
            aOrbiterC = RotL64((aOrbiterC * 14931933411393847915U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5357144808788707522U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2910681277417754860U;
            aOrbiterF = RotL64((aOrbiterF * 13170868582159347059U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9824408699018165151U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 368370224788793300U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14358982366258729959U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7095398304588825115U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11418879758164313554U;
            aOrbiterG = RotL64((aOrbiterG * 5983520332639771791U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 2171599720681913272U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17593730219647495033U;
            aOrbiterJ = RotL64((aOrbiterJ * 12926053208918563087U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17755947635188715523U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14565740605227022106U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15866418354612945335U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14538017880915584414U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6174566474851449123U;
            aOrbiterH = RotL64((aOrbiterH * 179569008593475683U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 4U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterH, 11U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 35U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 56U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 27U)) + aOrbiterB) + aNonceWordI) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterC, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aWorkLaneC
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 11010U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((aIndex + 14918U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13449U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 16251U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12872U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (aWandererD + RotL64(aScatter, 47U)) + 12535417189990029950U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 6U)) + RotL64(aCarry, 51U)) + 6204401443676390273U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 11U)) + 869613505613154672U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 35U)) + 15053590879563855802U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 13338989605204591428U;
            aOrbiterC = ((((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 18306470022403825392U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererC + RotL64(aIngress, 60U)) + 1150696349434090218U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 51U)) + 13549541786420596437U) + aNonceWordD;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 39U)) + 14302878430259588461U) + aNonceWordL;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4660437084477165225U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1653628537860912069U;
            aOrbiterJ = RotL64((aOrbiterJ * 2624835201155303123U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5594199757006711631U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11008472193138708891U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13645764762027798301U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3668516817279364310U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 128159531749679984U;
            aOrbiterF = RotL64((aOrbiterF * 4523246859249826987U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6378674346113979108U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11438762460659123362U;
            aOrbiterB = RotL64((aOrbiterB * 2733309638158283953U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10624263004446482910U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12546839706919241411U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11468326687628079347U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8466639576503293921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5828694979857951504U;
            aOrbiterE = RotL64((aOrbiterE * 7835487310289634515U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16496305151014092976U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 589464613876410567U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 13190816610718051897U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4168532743415647825U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15944887793736489375U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 17273403561158196717U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11642456814106259483U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1609897693632334867U;
            aOrbiterI = RotL64((aOrbiterI * 12912773555616819941U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + aNonceWordK);
            aWandererD = aWandererD + ((((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + aNonceWordM) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterC, 40U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 3U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 47U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterF, 58U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 23U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20928U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneC[((aIndex + 17372U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 20201U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17951U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 17478U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 28U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererE + RotL64(aCross, 38U)) + 16651241552253078315U) + aPhaseFOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aWandererC + RotL64(aIngress, 43U)) + 4558144676982478003U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 8814884320080367550U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 57U)) + 16011579668555672117U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 51U)) + 4738918668759862438U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 12526083125540985108U) + aNonceWordA;
            aOrbiterA = (aWandererB + RotL64(aScatter, 27U)) + 8048723561746000552U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 1082218464034639039U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 20U)) + 8432043246965946816U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9982080524048636852U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6720069955755215919U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1025046364205332059U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1019035028070247757U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7360619079463870467U;
            aOrbiterI = RotL64((aOrbiterI * 6623074813047915863U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10893918488381348474U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1390297670907738019U;
            aOrbiterA = RotL64((aOrbiterA * 11909657437658597735U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12512200589031203480U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14741471280748399540U;
            aOrbiterE = RotL64((aOrbiterE * 3012135242889901095U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8543897248359826770U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8545972622733791272U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11793879362775346821U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7049384618581928664U) + aNonceWordM;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 14730773807906925408U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 10711566871536755073U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11480717275652449986U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1135397594974536859U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6347492892938856497U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6897207625849516702U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10920630712550287148U;
            aOrbiterJ = RotL64((aOrbiterJ * 4140705091806993359U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1094056478999931332U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6784487144549717207U;
            aOrbiterK = RotL64((aOrbiterK * 6295177724167067891U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + aNonceWordJ);
            aWandererG = aWandererG + (((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 13U)) + aNonceWordL) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 42U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterC, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 58U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterE, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneB
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23343U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneD[((aIndex + 27009U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26951U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23157U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneC[((aIndex + 25847U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 58U)) + 13442819395490639310U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 13U)) + 8187292523194120936U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 11469697159823131388U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 13414083692375929653U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 47U)) + 11404010733687907517U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 51U)) + 6783212827186218247U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 35U)) + 8561131439340372614U) + aNonceWordM;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 22U)) + RotL64(aCarry, 41U)) + 6252609642004429113U) + aNonceWordF;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 27U)) + 12804867444200448952U) + aPhaseFOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2739648749603690781U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14808861217017399752U;
            aOrbiterG = RotL64((aOrbiterG * 373911885694012101U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17588866502571268888U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5882260142735642980U;
            aOrbiterE = RotL64((aOrbiterE * 7688252946143263869U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15493099088132862949U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5175647411532429582U;
            aOrbiterJ = RotL64((aOrbiterJ * 15226544495598541883U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14279707376173642767U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6826363572161275158U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5263708315440161809U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13267185753040999992U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9980987858092888720U;
            aOrbiterD = RotL64((aOrbiterD * 13210290848800728635U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3582972937645514549U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10140409019562890804U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6944490201647678479U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6160444117287330557U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16344602960561293113U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2319964919335633293U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 3497141036108337171U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 91269118352540308U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 5160060720189045505U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12739932748793144857U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12820180915064791197U;
            aOrbiterH = RotL64((aOrbiterH * 5843849637411948699U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterC, 10U)) + aNonceWordB) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterE, 23U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 39U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 52U)) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 19U));
            aWandererE = aWandererE + (((RotL64(aScatter, 52U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28809U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 32408U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 28283U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28569U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 32450U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 39U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 43U)) + 10336802574069791273U) + aNonceWordP;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 4U)) + RotL64(aCarry, 47U)) + 169025388197058936U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 53U)) + 6541354188379168846U) + aNonceWordF;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 16223920526599306104U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 12756613707692514808U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 23U)) + 5082475548176484035U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aWandererG + RotL64(aScatter, 35U)) + 4907435526952698526U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 30U)) + 14236627073831834337U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 11U)) + 11502511046130497584U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3679044835550219497U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11254838916686736746U;
            aOrbiterK = RotL64((aOrbiterK * 8631695922983532915U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10582608424233200966U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10449735026385340313U;
            aOrbiterJ = RotL64((aOrbiterJ * 7363770199734997411U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 4628253464169957835U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17664454668473204465U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 4234720298731378527U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3798386391743884889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1379331161819246587U;
            aOrbiterA = RotL64((aOrbiterA * 13086160171095077295U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9816600392407327227U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16781971616348376878U;
            aOrbiterF = RotL64((aOrbiterF * 12503867584828289879U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4807797577690520554U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2492057261148595922U;
            aOrbiterG = RotL64((aOrbiterG * 9453302540675483005U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7909676419643119585U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 256053568910383007U;
            aOrbiterB = RotL64((aOrbiterB * 11965085163352053161U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16179914439220412472U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3968867762761955845U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 7473632378251893139U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7474832923901283742U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4736994731050735779U;
            aOrbiterC = RotL64((aOrbiterC * 9839654409121414047U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 54U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterA, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 27U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterC, 56U)) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 20U) + aOrbiterC) + RotL64(aOrbiterF, 23U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD) + aNonceWordM) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 52U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Lacrosse_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x94629BF7172CDE19ULL + 0xAA9BB24DAE7861AEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA793F950FB57A9C5ULL + 0xC08C5EBD279BFE07ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x955CD73A9676E165ULL + 0x90CD05D8080D3BCCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC26EE31D56BF7F23ULL + 0xDF5BC39857178EA5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAAFB22189B3B8AB9ULL + 0xAA831620C26BE85DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA1B889F3304E5EFDULL + 0x924C1046FC891685ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x88A9C7901258767FULL + 0xF7DEED15842AECB1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x96D5E8EC0CBBC1D1ULL + 0xD31F35DD6CEB1C9BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF4A0C075DE27AB59ULL + 0xFB05F6DBB09255E6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x950976E96DD6406BULL + 0x92E7A03C0572940DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x817DCDF4A3C9B0C1ULL + 0xCF4D0BB65B6D706AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD1A42EBCA04ACCD7ULL + 0xDB583FED238C3FA7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9FEA368ED22731A1ULL + 0xDE189FC41DCCE88DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA3D95D07C9BC5C01ULL + 0x8B95ECC1A1BEE12FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD570CB1AFA694E93ULL + 0xB35CCA100F4DA989ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAF606306E8C70783ULL + 0xC41451A5A8884ABEULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneC, aSnowLaneC, aSnowLaneD, aFireLaneD, aWorkLaneA, aInvestLaneC, aFireLaneA, aWorkLaneB, aInvestLaneD, aExpandLaneA, aInvestLaneA, aExpandLaneB, aInvestLaneB, aExpandLaneC, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 2200U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((aIndex + 402U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1431U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 4012U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 4283U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3557U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 13U)) ^ (RotL64(aIngress, 28U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((aWandererI + RotL64(aIngress, 35U)) + 2225397913940961213U) + aNonceWordK;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 8342544893601343643U) + aNonceWordC;
            aOrbiterD = (((aWandererK + RotL64(aCross, 42U)) + RotL64(aCarry, 13U)) + 162922186381417187U) + aNonceWordM;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 11660218373710972210U) + aNonceWordN;
            aOrbiterH = (aWandererG + RotL64(aCross, 29U)) + 14909034764605802354U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 53U)) + 16776955237009701511U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 23U)) + 5834487809188925253U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1498492772767040320U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4161765458781579617U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15535994410289065281U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10511923076962447765U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8575954471692620021U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12526744988828982731U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6536325446331340573U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1790628986900286346U;
            aOrbiterE = RotL64((aOrbiterE * 5262997114200816715U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2623814807619278590U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11676970995834706612U;
            aOrbiterB = RotL64((aOrbiterB * 10057461115132434901U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13836786354224256591U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6293096163612129260U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8977954126326217153U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4271144764978661248U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15938494256992560202U;
            aOrbiterK = RotL64((aOrbiterK * 10004841288382726739U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11038155227307702976U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12408749795071243930U;
            aOrbiterC = RotL64((aOrbiterC * 5527720475032868855U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterD, 43U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 12U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 27U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterE, 35U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8152U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneC[((aIndex + 9179U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10368U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((aIndex + 10801U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6967U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8893U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 10028U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 44U) + RotL64(aCarry, 29U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 4980738603982643969U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 42U)) + 17660278413018470020U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 51U)) + 17598114429859543466U) + aNonceWordE;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 10993929335279994739U) + aNonceWordG;
            aOrbiterG = ((((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 17967203122976322481U) + aPhaseHOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 29U)) + 1872290205549034384U) + aNonceWordF;
            aOrbiterC = (aWandererC + RotL64(aCross, 23U)) + 16607778671782810797U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4895226930754394376U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14960359005982301383U;
            aOrbiterK = RotL64((aOrbiterK * 8546231310054433721U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9921642352377700630U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 893281964367208693U;
            aOrbiterG = RotL64((aOrbiterG * 2345509157333444217U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8232519988397858732U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4433022122758913407U;
            aOrbiterJ = RotL64((aOrbiterJ * 834240393225479419U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12689609831247168353U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 404535388957472176U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 14534020545479806593U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3349108201964013155U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4386449511297371730U;
            aOrbiterH = RotL64((aOrbiterH * 9596273264321140229U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14314587717949070586U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10923886625271054985U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 7838969002623486809U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17634909585329833520U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2021301459918350372U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1388242915918642741U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + aNonceWordL) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterC, 38U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterG, 29U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aInvestLaneD
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12847U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneA[((aIndex + 15792U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 12394U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13273U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneC[((aIndex + 13393U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 21U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 8375305456876489425U) + aNonceWordD;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 34U)) + 16193562952772453047U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 21U)) + 18088652458594816223U) + aPhaseHOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 5U)) + 767344788620249944U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 41U)) + 7705194930396368752U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 3829736891311272834U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 9881681671347640061U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1721196560190164264U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3002652618388454213U;
            aOrbiterG = RotL64((aOrbiterG * 15289749311593032657U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 9811621464004005202U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5652598941069986530U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 4797973356708091621U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6250499348327316328U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16025054277615264530U;
            aOrbiterH = RotL64((aOrbiterH * 16446892258704281903U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13800298546867243172U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12256104592865905782U;
            aOrbiterB = RotL64((aOrbiterB * 16983140179497142713U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17817225416918329229U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17738671327352776217U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 393488251327705063U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6816031224188400541U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16989563985059237014U;
            aOrbiterK = RotL64((aOrbiterK * 8677884225771717797U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 16891524847268207549U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1833508573940405571U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9709196587703979539U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 11U)) + aOrbiterH) + aNonceWordE);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 5U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aCross, 44U) + aOrbiterB) + RotL64(aOrbiterK, 20U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterH, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18190U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 17205U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 18908U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18948U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneD[((aIndex + 18185U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCarry, 41U)) + (RotL64(aIngress, 13U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 15920462086654025436U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 487844076858004017U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 4U)) + 14502883786442630566U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 13U)) + 3787107318658233674U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 53U)) + 12548777544693755491U) + aPhaseHOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 4907309444075181683U) + aNonceWordD;
            aOrbiterI = (aWandererA + RotL64(aIngress, 47U)) + 18342396700266492072U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13503051997624242670U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17845742460521374571U;
            aOrbiterB = RotL64((aOrbiterB * 1366356786138085155U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8640887211877858169U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5273913123709097537U;
            aOrbiterK = RotL64((aOrbiterK * 1661149444148461791U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17756844173695563883U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 6713055830729302951U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 2832836748513174311U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5106468334224035972U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10228769728713526172U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9760310686414358435U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 7687649520668883142U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7757480627354711605U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7222553727737349209U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10876291698508634557U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8149278085586014186U;
            aOrbiterE = RotL64((aOrbiterE * 8577133863470695381U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 15592893988925610485U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8639028256640537165U;
            aOrbiterI = RotL64((aOrbiterI * 1880655276432963955U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterH, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 21U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterB, 4U)) + RotL64(aCarry, 39U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterF, 41U)) + aOrbiterI) + aNonceWordP);
            aWandererC = aWandererC + ((((RotL64(aCross, 41U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + aNonceWordL) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aInvestLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22602U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 24749U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27118U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23200U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 27067U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 44U) + RotL64(aIngress, 5U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (((aWandererA + RotL64(aIngress, 50U)) + RotL64(aCarry, 11U)) + 16651241552253078315U) + aPhaseHOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 4558144676982478003U) + aNonceWordJ;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 5U)) + 8814884320080367550U) + aNonceWordC;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 35U)) + 16011579668555672117U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererB + RotL64(aIngress, 23U)) + 4738918668759862438U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 12526083125540985108U) + aNonceWordL;
            aOrbiterH = (aWandererG + RotL64(aScatter, 57U)) + 8048723561746000552U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 1082218464034639039U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8432043246965946816U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7801965585991025451U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9982080524048636852U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6720069955755215919U;
            aOrbiterF = RotL64((aOrbiterF * 1025046364205332059U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1019035028070247757U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 7360619079463870467U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6623074813047915863U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10893918488381348474U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1390297670907738019U;
            aOrbiterA = RotL64((aOrbiterA * 11909657437658597735U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12512200589031203480U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14741471280748399540U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 3012135242889901095U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8543897248359826770U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8545972622733791272U;
            aOrbiterC = RotL64((aOrbiterC * 11793879362775346821U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7049384618581928664U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 14730773807906925408U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 10711566871536755073U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 14U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 41U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterK, 51U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + aNonceWordN);
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterC, 13U)) + aOrbiterA) + aNonceWordO) + aPhaseHWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 6U)) + aOrbiterI) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29296U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 28253U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27978U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27398U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneB[((aIndex + 31682U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 6U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 35U)) + 9630214189402543339U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 19U)) + 4072576573737526819U) + aNonceWordF;
            aOrbiterK = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 15994787452709618869U) + aNonceWordI;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 27U)) + 6403240137132259482U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererA + RotL64(aCross, 43U)) + 10229266900170507720U) + aNonceWordB;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 5025294577989748989U) + aPhaseHOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 16696461238217956883U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9878318855341719119U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16086635438116177346U;
            aOrbiterK = RotL64((aOrbiterK * 5585682357395705671U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12295437783084203730U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7681150419912842402U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7289497379725191451U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2639104034287637448U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12298170009332243573U;
            aOrbiterE = RotL64((aOrbiterE * 9397919591171238575U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3485932317267669626U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16569551670038752475U;
            aOrbiterA = RotL64((aOrbiterA * 8139802826402217631U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4448490103784103954U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14510534073046885941U;
            aOrbiterB = RotL64((aOrbiterB * 7777192047386438305U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4286195398675733451U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15790355933840266463U;
            aOrbiterD = RotL64((aOrbiterD * 13342257823027075501U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6362891510370156055U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 15121822034579983174U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 7268045994574844937U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 50U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterE, 48U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + aNonceWordC) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + aPhaseHWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 34U) + aOrbiterB) + RotL64(aOrbiterC, 41U)) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 11U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Lacrosse_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 209U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 1715U)) & W_KEY1], 6U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1138U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1377U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 19U)) + 7722279280863371124U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 19U)) + 11584220561732385598U) + aPhaseAOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 29U)) + 7834679350105534657U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 43U)) + 11347994382444180879U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 5U)) + 9449903188047063431U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 6516243976652795170U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 24U)) + RotL64(aCarry, 51U)) + 8420815253991184777U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 53U)) + 9081386852515170937U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 13U)) + 14375955191735286867U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 880757589768436072U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3349856625725164229U;
            aOrbiterG = RotL64((aOrbiterG * 681514212582331781U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7826309957607577207U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8057435761214313635U;
            aOrbiterB = RotL64((aOrbiterB * 4718430712767038607U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9565237500443303103U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15893066735310588501U;
            aOrbiterE = RotL64((aOrbiterE * 8457633439171452397U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3276844534476430842U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6828644383891274120U;
            aOrbiterC = RotL64((aOrbiterC * 979580351653410157U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2815676923011504251U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5030251870850928417U;
            aOrbiterJ = RotL64((aOrbiterJ * 7075653570570819253U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13464083008377887034U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8994560761846897590U;
            aOrbiterD = RotL64((aOrbiterD * 9892839554658865143U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8398813387154468736U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8136429428340910892U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3348811490733577295U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 418587250696862341U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4111667833838312094U;
            aOrbiterH = RotL64((aOrbiterH * 860949442143849147U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6075478294190926371U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2208124955874142264U;
            aOrbiterF = RotL64((aOrbiterF * 15741988616251072075U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 30U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterF, 22U));
            aWandererE = aWandererE + (((RotL64(aScatter, 18U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 3U)) + aPhaseAWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 35U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 18U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4735U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3099U)) & W_KEY1], 34U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4887U)) & W_KEY1], 36U) ^ RotL64(mSource[((aIndex + 2735U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 36U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 8767379393098711499U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 29U)) + 7168159491580816433U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 9879279829061883406U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aPrevious, 35U)) + 10537167136053399303U;
            aOrbiterG = (aWandererI + RotL64(aCross, 19U)) + 2839070018069188936U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 47U)) + 13844278063968429732U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 51U)) + 11278946626186474646U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 12U)) + 11798425216660557799U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 43U)) + 7618446090703335192U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 695423597006983660U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14344728202803488813U;
            aOrbiterK = RotL64((aOrbiterK * 5168825904902285909U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11656100506575697086U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10384358779985773937U;
            aOrbiterF = RotL64((aOrbiterF * 247494692039140973U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17585001605131977341U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9964478171465522911U;
            aOrbiterH = RotL64((aOrbiterH * 13484044854790175315U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2710943171829692624U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17809072853457153057U;
            aOrbiterG = RotL64((aOrbiterG * 16341884203303271365U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12814092033910687774U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1743186323268668740U;
            aOrbiterD = RotL64((aOrbiterD * 11150822630624332557U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10750472346626754704U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15925901217078035356U;
            aOrbiterC = RotL64((aOrbiterC * 9276504171291801637U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 2569102106359362359U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8868261301410769739U;
            aOrbiterI = RotL64((aOrbiterI * 3662495603133918101U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2143691008373582476U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10606616796243205921U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15794414817813485643U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16258070651850746855U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11720192793689633315U;
            aOrbiterB = RotL64((aOrbiterB * 14475623219460678021U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 4U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterH, 36U)) + aPhaseAWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterC, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterI, 18U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 18U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterG, 23U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 54U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6010U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadB[((aIndex + 6708U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7382U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7573U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6108U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 6U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererI + RotL64(aIngress, 23U)) + 14157904117287696136U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 18U)) + 7369512677371640676U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 8411250745902073798U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 51U)) + 5002041814539710275U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aScatter, 27U)) + 9538041410816283124U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 35U)) + 5210700103927513061U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 53U)) + 7600709399101287982U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 2366369466696580499U) + aPhaseAOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aPrevious, 13U)) + 5544575244203019109U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8710073749110329779U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15998211310115361630U;
            aOrbiterF = RotL64((aOrbiterF * 15275657696897688955U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15354357553877376422U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10657523549259276169U;
            aOrbiterG = RotL64((aOrbiterG * 13695239532898311073U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10405750198355464768U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3465819693133515142U;
            aOrbiterK = RotL64((aOrbiterK * 14678343718277562799U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16724189641701408630U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3484340153620198872U;
            aOrbiterE = RotL64((aOrbiterE * 17247547677520703125U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7420442404884871126U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11138445997256757636U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11167543379937571127U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1428191560884663125U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16950093140800653985U;
            aOrbiterI = RotL64((aOrbiterI * 4423012306984814805U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17288299075036481960U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13793597915359681028U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9639204979982125757U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5017972942710079726U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12409957957614320964U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10273295741911545745U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12487994181992095174U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1573393166996612118U;
            aOrbiterA = RotL64((aOrbiterA * 13364311829104520751U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 50U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 34U) + RotL64(aOrbiterE, 37U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterI, 5U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 60U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterH, 43U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 14U) + aOrbiterK) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterA, 13U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterI, 50U)) + aPhaseAWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 23U)) + aOrbiterK) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8366U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 10467U)) & W_KEY1], 4U));
            aIngress ^= (RotL64(mSource[((aIndex + 10108U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8279U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9845U)) & W_KEY1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 9028U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 10U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererF + RotL64(aIngress, 23U)) + 6467297102954816305U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 3U)) + 7921154109831114952U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 56U)) + RotL64(aCarry, 3U)) + 5701131763215638919U) + aPhaseBOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 43U)) + 10022999076719002684U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 4367135243038982316U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 47U)) + 14445846824810383592U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 29U)) + 7683697954545773253U;
            aOrbiterC = (aWandererC + RotL64(aCross, 14U)) + 17517006750428030899U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 2052484792684025476U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6279463052085808926U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 679280153651813684U;
            aOrbiterI = RotL64((aOrbiterI * 3047031560593583881U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2939516520188460569U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1960616434964712325U;
            aOrbiterB = RotL64((aOrbiterB * 15145998415466343039U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12273819390719947361U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5685033154709449397U;
            aOrbiterF = RotL64((aOrbiterF * 9845666295874714959U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9314494172199500653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15757631834636427621U;
            aOrbiterC = RotL64((aOrbiterC * 15483543888965744529U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10878078046389399574U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3583495913766365232U;
            aOrbiterK = RotL64((aOrbiterK * 2913540984990155225U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7385544065754622301U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16839599460207922881U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 240651605910592561U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13038163804940349251U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2587538594933924000U;
            aOrbiterA = RotL64((aOrbiterA * 3091149760401278671U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13109518583364738004U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2447689055742474261U;
            aOrbiterD = RotL64((aOrbiterD * 12100180201235703193U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5752044906692668618U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 6637725371036522120U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6021986525167161115U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 10U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterK, 57U));
            aWandererI = aWandererI + ((RotL64(aScatter, 48U) + RotL64(aOrbiterC, 12U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 51U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 47U)) + aOrbiterD) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterF, 19U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 38U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterF, 3U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 44U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 27U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12340U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 12281U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13561U)) & W_KEY1], 41U) ^ RotL64(mSource[((aIndex + 12076U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12405U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12964U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13546U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 35U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 4970414922752555648U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 29U)) + 9462756592787669327U) + aPhaseBOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 52U)) + RotL64(aCarry, 29U)) + 3948790686662213095U;
            aOrbiterC = (aWandererH + RotL64(aCross, 19U)) + 14542857212241578311U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 47U)) + 3387479009827029547U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 23U)) + 1411421370057797877U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 13U)) + 16894451466895681236U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 35U)) + 12727136462290223542U) + aPhaseBOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 53U)) + 4625389198191960525U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3471881403786164913U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6433115856048534831U;
            aOrbiterH = RotL64((aOrbiterH * 9363233870194144053U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9825592965466157982U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 1553125767261293088U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 411535191177308781U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9951616357109647617U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11231080382787286889U;
            aOrbiterA = RotL64((aOrbiterA * 14024961994986659187U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13419663264017317947U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4835055642466215566U;
            aOrbiterF = RotL64((aOrbiterF * 17898065852351759171U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 14558747666410946768U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 13120938960926874504U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5681766019285559739U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11910501376797343986U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15074100100781785300U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 228976960937473851U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12415377930578091821U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14882039078390681802U;
            aOrbiterD = RotL64((aOrbiterD * 13855446647753150713U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8094338361713756895U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5478280604704108822U;
            aOrbiterC = RotL64((aOrbiterC * 18062931724700600993U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6977017654546871841U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4131602217285988962U;
            aOrbiterI = RotL64((aOrbiterI * 11865422227883712419U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 44U);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterE, 27U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 56U) + RotL64(aOrbiterC, 35U)) + aOrbiterD) + aPhaseBWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 40U)) + aOrbiterA) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterA, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterG, 47U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 54U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15637U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14978U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14915U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16233U)) & W_KEY1], 20U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 16116U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14158U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14284U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererH + RotL64(aIngress, 28U)) + 6733949564325516029U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 47U)) + 7304098437143918796U;
            aOrbiterI = (aWandererI + RotL64(aCross, 23U)) + 3923949518391777800U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 14243591003388927124U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 19U)) + 18329498724605410406U) + aPhaseBOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 13118172167747037249U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 5272025143849174212U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 12U)) + 16075917179214318424U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 43U)) + 15263590648674658399U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13730046728289525921U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7703141464499623408U;
            aOrbiterI = RotL64((aOrbiterI * 5886009900621521987U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1382279753822135359U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2973369221699098292U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7440242040663550631U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11578274119583013219U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3419411247737896674U;
            aOrbiterA = RotL64((aOrbiterA * 17814942652262802991U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2582783513078999303U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3959762790273529677U;
            aOrbiterK = RotL64((aOrbiterK * 383974377372162751U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 465795011576934604U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17880826624185821135U;
            aOrbiterG = RotL64((aOrbiterG * 4445949147592860913U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10819659185349413173U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17298208553586835030U;
            aOrbiterJ = RotL64((aOrbiterJ * 1965860510614222093U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12585880006661489402U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16650193903267408586U;
            aOrbiterE = RotL64((aOrbiterE * 5781132589396936615U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 885882046325991589U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 869560078374809974U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13440973563438747181U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11871305571797951851U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12137095015607196226U;
            aOrbiterD = RotL64((aOrbiterD * 7618152256560808581U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 14U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 39U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterF, 35U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 60U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterI, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 52U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 30U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18456U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[((aIndex + 17384U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 18252U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 17157U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17745U)) & W_KEY1], 43U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17269U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 16695U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 27U)) + 7270044678408187242U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 10U)) + 10192278965379756766U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 17568666746676060748U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 14312927531124963037U) + aPhaseCOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 21U)) + 9825825726152087706U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 9696778570255265896U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 35U)) + 17657841352013417228U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 4U)) + 16207815085909628439U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 57U)) + 1752979206374514227U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10456310689643905854U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16127830548663742550U;
            aOrbiterA = RotL64((aOrbiterA * 4355938404839045417U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2940917376003930842U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7353596864777649953U;
            aOrbiterG = RotL64((aOrbiterG * 7499468723171042005U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12725092740446150705U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5791296650856037010U;
            aOrbiterJ = RotL64((aOrbiterJ * 760379251950502133U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1200130368046206150U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16689604428598558547U;
            aOrbiterD = RotL64((aOrbiterD * 13815324235939996623U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14359561591103730856U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3975025843599045263U;
            aOrbiterC = RotL64((aOrbiterC * 5025047888533298617U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14017901732955607601U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10431526786489555196U;
            aOrbiterH = RotL64((aOrbiterH * 10181915874476132407U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7320527073559849223U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15333411223710709907U;
            aOrbiterE = RotL64((aOrbiterE * 3488684905528068775U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14302474063321663801U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2104154521019935187U;
            aOrbiterB = RotL64((aOrbiterB * 12944382959742278055U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5167600586916325228U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4566823109447208716U;
            aOrbiterF = RotL64((aOrbiterF * 9997799807454267443U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 10U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterH, 46U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 30U));
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 23U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 51U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 52U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19862U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 19664U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21345U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 19665U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20039U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21175U)) & W_KEY1], 60U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19490U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 19708U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 10U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererE + RotL64(aIngress, 42U)) + 18255347001097480328U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 13679246790311505735U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 10565839529765027116U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 3U)) + 14327172566224769901U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 47U)) + 16239024612038195174U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 13800012174212131890U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 37U)) + 13900288860157577583U) + aPhaseCOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 18U)) + 4144386119777112740U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 11U)) + 3154558262670631372U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 7456728543137614001U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11709519851158935384U;
            aOrbiterJ = RotL64((aOrbiterJ * 7016689518570071587U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15607438907832240304U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9276575329661725624U;
            aOrbiterA = RotL64((aOrbiterA * 8879744070762412745U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6459435969129449226U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6442382118416542275U;
            aOrbiterG = RotL64((aOrbiterG * 2921027306686588233U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12117432107282150865U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6831279293184793243U;
            aOrbiterI = RotL64((aOrbiterI * 2435360641135249073U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9520022957804572889U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8322178689474588679U;
            aOrbiterC = RotL64((aOrbiterC * 1627707191467537115U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4162401591586869316U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8994015844714895961U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15421910378057951895U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10038095909727959633U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17756404450592957616U;
            aOrbiterD = RotL64((aOrbiterD * 14255952184627347295U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3379089265413427719U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11341713098678108441U;
            aOrbiterH = RotL64((aOrbiterH * 2500587373161411961U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4030296130743454165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6332387792111212064U;
            aOrbiterE = RotL64((aOrbiterE * 16490982218150897861U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterA, 51U));
            aWandererF = aWandererF + ((((RotL64(aCross, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterH, 60U)) + aOrbiterI) + aPhaseCWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 47U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterH, 6U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 38U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22969U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadA[((aIndex + 24562U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23035U)) & W_KEY1], 21U) ^ RotL64(aFireLaneC[((aIndex + 22525U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23505U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22945U)) & S_BLOCK1], 38U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23976U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22441U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 18U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 14U)) + RotL64(aCarry, 37U)) + 6024062041314952357U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 47U)) + 18340757093658015585U) + aPhaseCOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 3U)) + 11911120493880346751U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 29U)) + 17428074353884654439U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 35U)) + 12790849760814795936U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 12633397052172117800U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 60U)) + 11946150433665237945U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 16842157900909419285U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 53U)) + 14186235783224155962U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13284904542579767591U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11609181965078844357U;
            aOrbiterB = RotL64((aOrbiterB * 5455780554452453513U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9628562297095374984U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7850281529011259759U;
            aOrbiterK = RotL64((aOrbiterK * 17611485102925470357U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 257458718073794527U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10693404545773519306U;
            aOrbiterG = RotL64((aOrbiterG * 14821443722828498323U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3430519236533871460U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 6183054506953198055U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6121082743789970911U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2905610989884221654U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4472163910775333862U;
            aOrbiterF = RotL64((aOrbiterF * 7770678426310856745U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16870142883133769663U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1403692060594816451U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9740854430251597879U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16904169913507057108U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4773518591580333357U;
            aOrbiterA = RotL64((aOrbiterA * 5306070307776061267U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 6528141733853494275U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11254806909313951442U;
            aOrbiterJ = RotL64((aOrbiterJ * 6316669786405548827U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6857506858448143407U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2855763534355983644U;
            aOrbiterC = RotL64((aOrbiterC * 16881334940165182415U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 53U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 19U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 60U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterK) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 20U) + aOrbiterB) + RotL64(aOrbiterF, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25648U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 24696U)) & W_KEY1], 48U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26070U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24820U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25109U)) & W_KEY1], 10U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26665U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26450U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 24583U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 14U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererI + RotL64(aScatter, 19U)) + 16016931609704150191U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 23U)) + 14511433515861302636U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 35U)) + 11691237442613269593U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 12U)) + RotL64(aCarry, 13U)) + 16383220587320484649U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 14293015313458219868U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 53U)) + 4407695248205526670U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 1158323195324398372U;
            aOrbiterK = (aWandererD + RotL64(aCross, 48U)) + 6577683409653864555U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 29U)) + 171080079472863843U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5766333425872228205U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16173508656917582960U;
            aOrbiterB = RotL64((aOrbiterB * 12187968015372936695U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11781450063402219202U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 13033139686637576694U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4331137994135472025U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4006310759400926020U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13156817947481574467U;
            aOrbiterK = RotL64((aOrbiterK * 563189239835001483U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12791290558893516411U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 989729955679243234U;
            aOrbiterE = RotL64((aOrbiterE * 8757228712495095017U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 838379839663022790U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2830743864262313606U;
            aOrbiterG = RotL64((aOrbiterG * 10173947177104802797U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2146646527331684652U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4629168181742174906U;
            aOrbiterD = RotL64((aOrbiterD * 9046124907945045131U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1150129989168501777U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 619659995945229440U;
            aOrbiterI = RotL64((aOrbiterI * 13734821008174603409U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8120315647582116952U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13754584116324996165U;
            aOrbiterC = RotL64((aOrbiterC * 12295486140772079747U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6084566798869999580U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5731665119233722504U;
            aOrbiterH = RotL64((aOrbiterH * 5921510209025133639U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 51U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 6U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterB, 35U));
            aWandererD = aWandererD + ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterD, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterH, 18U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 52U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererK, 46U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29791U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((aIndex + 29125U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28721U)) & W_KEY1], 11U) ^ RotL64(aFireLaneC[((aIndex + 28494U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28709U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28676U)) & S_BLOCK1], 4U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27936U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27690U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 24U)) + RotL64(aCarry, 39U)) + 9630214189402543339U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 5U)) + 4072576573737526819U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 29U)) + 15994787452709618869U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 6403240137132259482U) + aPhaseDOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 35U)) + 10229266900170507720U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 5025294577989748989U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 47U)) + 16696461238217956883U;
            aOrbiterF = (aWandererE + RotL64(aCross, 39U)) + 9878318855341719119U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 12U)) + 16086635438116177346U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12295437783084203730U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7681150419912842402U;
            aOrbiterH = RotL64((aOrbiterH * 7289497379725191451U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 2639104034287637448U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12298170009332243573U;
            aOrbiterI = RotL64((aOrbiterI * 9397919591171238575U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 3485932317267669626U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16569551670038752475U;
            aOrbiterE = RotL64((aOrbiterE * 8139802826402217631U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4448490103784103954U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14510534073046885941U;
            aOrbiterC = RotL64((aOrbiterC * 7777192047386438305U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4286195398675733451U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15790355933840266463U;
            aOrbiterK = RotL64((aOrbiterK * 13342257823027075501U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6362891510370156055U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15121822034579983174U;
            aOrbiterG = RotL64((aOrbiterG * 7268045994574844937U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13817341015719915628U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14113474087906143783U;
            aOrbiterD = RotL64((aOrbiterD * 12838910141533126059U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9988301252236121106U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11287477288382171758U;
            aOrbiterJ = RotL64((aOrbiterJ * 4979297247881426383U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9491727010910328644U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7961202721830514030U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16300364540313620767U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 34U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterG, 14U)) + aPhaseDWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterK, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 23U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterI, 58U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32468U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31325U)) & W_KEY1], 26U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31060U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30694U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30684U)) & S_BLOCK1], 20U) ^ RotL64(aKeyRowReadB[((aIndex + 31860U)) & W_KEY1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 35U)) + 13204735390996728477U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 12U)) + 851171359595647173U;
            aOrbiterF = (aWandererE + RotL64(aCross, 57U)) + 16745304202825290723U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 562392736584913979U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 39U)) + 3244267012529053918U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 17282536111067869133U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aCross, 48U)) + RotL64(aCarry, 27U)) + 14851130066471729068U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 21U)) + 5256130407952363129U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 3U)) + 2904742485828362001U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3723346325449225387U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5344621093694027341U;
            aOrbiterF = RotL64((aOrbiterF * 9044881458629673499U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12919263300833603026U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17989801264160996071U;
            aOrbiterD = RotL64((aOrbiterD * 15468293047311883751U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5022175042377172157U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16684822380107847758U;
            aOrbiterH = RotL64((aOrbiterH * 2834049270263837537U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2740326510600876682U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13981423865219318820U;
            aOrbiterC = RotL64((aOrbiterC * 14593082145080056441U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 231945878229848395U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14139797734944312580U;
            aOrbiterG = RotL64((aOrbiterG * 6492256080432266407U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16704102101387552373U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8506734780526852552U;
            aOrbiterA = RotL64((aOrbiterA * 4684566118627414659U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2774630043988894695U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12490034334296488127U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16765455396278233145U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 545238171291436006U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1023872898002379590U;
            aOrbiterJ = RotL64((aOrbiterJ * 8626333831510136515U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5065187021047872560U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10391809965648089863U;
            aOrbiterI = RotL64((aOrbiterI * 10912471108849550469U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 50U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 46U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 39U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 20U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + aPhaseDWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterC, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 34U) + aOrbiterD) + RotL64(aOrbiterJ, 51U));
            aWandererF = aWandererF + ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 35U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterB, 24U));
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Lacrosse_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneA, aInvestLaneD, aFireLaneB, aOperationLaneA, aFireLaneC, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2665U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 5082U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 2439U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1784U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 1589U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 20U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererD + RotL64(aIngress, 34U)) + 3238389262925516513U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 12381787182611386995U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 7883885539305181549U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aPrevious, 11U)) + 1185413044597727092U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 47U)) + 15219353497204773135U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 57U)) + 7533774715626734082U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 2599930450937763464U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16074720663961214284U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15483613196360051221U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11717479088020532861U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 9396557867081376268U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9668459976852660245U;
            aOrbiterH = RotL64((aOrbiterH * 11748505665890567063U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9037269914643207212U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16936742640861088240U;
            aOrbiterK = RotL64((aOrbiterK * 1040172193161012227U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16481274825758546398U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 481851372837611166U;
            aOrbiterE = RotL64((aOrbiterE * 2225030139210599207U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13608921517203544108U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16930740723286214636U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2605108503821980865U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 902242902582149908U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1510861213079342977U;
            aOrbiterD = RotL64((aOrbiterD * 3309753895727400707U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7116243600304980310U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6631412278359709602U;
            aOrbiterA = RotL64((aOrbiterA * 11452627691392637463U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 22U) + RotL64(aOrbiterD, 42U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterG, 13U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + aPhaseEWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 52U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneA
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 7312U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 7470U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6103U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7833U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 7199U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCarry, 29U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererA + RotL64(aCross, 4U)) + RotL64(aCarry, 57U)) + 15045917390223766480U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 10763054007033668758U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 13190170142593666607U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 11U)) + 9657025731441167065U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 47U)) + 11433367178975954211U;
            aOrbiterG = (aWandererB + RotL64(aCross, 35U)) + 17904920143996810366U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 41U)) + 3244383020512113283U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6538815775171139091U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7195368312757976343U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10515679176134176565U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18134430713910279374U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6571776588427107976U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11916502085252589161U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11830778129647517758U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9793702760907767365U;
            aOrbiterB = RotL64((aOrbiterB * 4096246227968677179U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2287235876793192036U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8951959188326141794U;
            aOrbiterG = RotL64((aOrbiterG * 9968356718110753845U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7583061790273240157U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3571364625022806085U;
            aOrbiterD = RotL64((aOrbiterD * 6238360922735480669U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13869345563551689212U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 277480328952975002U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1057564597096163085U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4983735092494677578U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9490022869381030928U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12926352917961703123U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 41U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterG, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterK, 13U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterG, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneB
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14340U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 15799U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 14129U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15726U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13711U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15888U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 4U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aCross, 57U)) + 4384716820085860551U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 13U)) + 9715780315942116888U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 15963520052789178632U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 14346700690686392938U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 6005518012489966643U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 51U)) + 2506732930310252119U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 22U)) + 16782163084851775826U) + aPhaseEOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 823673076571076303U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1634084509064077736U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1128407326773234517U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1288134975466877686U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2998220403162908444U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4321412662318298283U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 220430672180734911U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10223923547068528867U;
            aOrbiterD = RotL64((aOrbiterD * 12577370238343872139U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11696469696177647608U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6545430420379636963U;
            aOrbiterK = RotL64((aOrbiterK * 8387163146257553773U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 79691451831797107U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8971444023498649419U;
            aOrbiterF = RotL64((aOrbiterF * 7148919880477390009U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5624403902454498793U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9468064161002030997U;
            aOrbiterC = RotL64((aOrbiterC * 8243560528100864595U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4619361544913629805U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12682446273369750704U;
            aOrbiterA = RotL64((aOrbiterA * 10879074713156075641U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 3U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterK, 46U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17821U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((aIndex + 19677U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21338U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18398U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19077U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17940U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 6U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererA + RotL64(aPrevious, 53U)) + 16651241552253078315U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 21U)) + 4558144676982478003U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 35U)) + 8814884320080367550U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 16011579668555672117U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 3U)) + 4738918668759862438U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 12526083125540985108U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 8048723561746000552U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1082218464034639039U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8432043246965946816U;
            aOrbiterI = RotL64((aOrbiterI * 7801965585991025451U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9982080524048636852U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6720069955755215919U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1025046364205332059U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1019035028070247757U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7360619079463870467U;
            aOrbiterC = RotL64((aOrbiterC * 6623074813047915863U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10893918488381348474U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1390297670907738019U;
            aOrbiterD = RotL64((aOrbiterD * 11909657437658597735U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12512200589031203480U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14741471280748399540U;
            aOrbiterG = RotL64((aOrbiterG * 3012135242889901095U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8543897248359826770U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8545972622733791272U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11793879362775346821U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7049384618581928664U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14730773807906925408U;
            aOrbiterJ = RotL64((aOrbiterJ * 10711566871536755073U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 30U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterK, 58U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterG, 13U)) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23307U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 21868U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25237U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22099U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23289U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 25217U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 27U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aCross, 12U)) + 3973833383430652211U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 35U)) + 5760227042747169187U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 57U)) + 4923009065139227286U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 1477807307009107590U) + aPhaseEOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 5707194514329007301U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 21U)) + 5340439728375269724U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 17080457898946572387U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 281559150259472813U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16160633048230910560U;
            aOrbiterD = RotL64((aOrbiterD * 16883442583309073785U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9003989610509592121U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10579322462808454333U;
            aOrbiterH = RotL64((aOrbiterH * 100832431598087235U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15059383289528723069U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10417647757852880956U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1457919230286043137U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14484665027393813330U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12344463053485837974U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5762654194001525041U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5826453246659297805U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12547902286376986223U;
            aOrbiterF = RotL64((aOrbiterF * 2982850000322672789U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9637855144278126174U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2132744427444501938U;
            aOrbiterB = RotL64((aOrbiterB * 5911587798564836199U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9248933938130311231U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13274297928717090383U;
            aOrbiterK = RotL64((aOrbiterK * 2901398809555237563U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 50U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 11U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterK, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterK, 50U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 19U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 37U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30617U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 31756U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 27312U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28871U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31275U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 31051U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 29U) + RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 8101351470141807662U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 6965474099521076705U) + aPhaseEOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 30U)) + 6803828268885684784U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 13454235922950972488U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 13U)) + 11678091885751244777U) + aPhaseEOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 57U)) + 5307134544628507141U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 23U)) + 4873703518950429353U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8542156221858586039U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3993726182905296513U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11331376012938127609U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12113047622035464386U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1944244448665721151U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7010050836758762003U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12914188029425467576U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2486762763475327024U;
            aOrbiterI = RotL64((aOrbiterI * 12319769994433811617U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14580191602982245481U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12093414832400135066U;
            aOrbiterE = RotL64((aOrbiterE * 12720286833215690663U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 13623906997320021065U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9977356009806428696U;
            aOrbiterB = RotL64((aOrbiterB * 2005536391712733499U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3694954095397810851U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11453812627797091638U;
            aOrbiterD = RotL64((aOrbiterD * 13730420725113907161U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 542311345544726351U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3024285045990499484U;
            aOrbiterF = RotL64((aOrbiterF * 5153745952148205645U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 46U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterF, 57U));
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Lacrosse_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneA, aExpandLaneD, aInvestLaneC, aSnowLaneB, aInvestLaneD, aWorkLaneA, aExpandLaneB, aWorkLaneB, aExpandLaneA, aWorkLaneC, aInvestLaneA
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2040U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 3405U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 5211U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 542U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4771U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 747U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aIngress, 21U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererK + RotL64(aPrevious, 53U)) + 8604208734152026945U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 20U)) + 1374329953253889829U;
            aOrbiterH = (aWandererB + RotL64(aCross, 13U)) + 5779278910548228339U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 51U)) + 17670451230882805140U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 8193848740764866860U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 37U)) + 15801168428145650104U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 41U)) + 2584718176087499066U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 22U)) + RotL64(aCarry, 41U)) + 14950366247822737997U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 39U)) + 9779293225265670135U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 57U)) + 8688968319288372383U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 13665723186950342601U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9395428688359973510U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2152719218018108418U;
            aOrbiterH = RotL64((aOrbiterH * 15271961483518392671U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1350324137411377992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8729317951386057921U;
            aOrbiterC = RotL64((aOrbiterC * 6008790836417785083U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6317310451893678411U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10175620379041384281U;
            aOrbiterI = RotL64((aOrbiterI * 14079679617394330781U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1203082119358827708U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 523869107818193101U;
            aOrbiterA = RotL64((aOrbiterA * 4629501113595689157U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4028324959540432983U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15447631947468213912U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6037306615787729185U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14225888694733041031U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11925000696281947629U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4337022940520411253U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15015531024930608745U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16752579225076943550U;
            aOrbiterJ = RotL64((aOrbiterJ * 15551083683579981439U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2432733494869267901U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10103430321388601485U;
            aOrbiterB = RotL64((aOrbiterB * 18372919379972432569U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15943360147468638325U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9782703760233558733U;
            aOrbiterG = RotL64((aOrbiterG * 685056980418243879U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 18345087852012669037U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8897505040792027675U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14333687539092412967U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7402581293947129667U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8604208734152026945U;
            aOrbiterE = RotL64((aOrbiterE * 9965525485538037673U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 18U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterF, 41U));
            aWandererH = aWandererH + ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterB, 3U));
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterD, 6U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 39U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterG, 35U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + aPhaseFWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterB, 37U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 56U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneD
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5732U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((aIndex + 9121U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7003U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 6872U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8728U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6699U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 5467U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 56U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererK + RotL64(aIngress, 56U)) + 14214886793361825363U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 11U)) + 17267959031078766320U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 21U)) + 16436067429484887644U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 23U)) + 9885951769332633820U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 12971711341813893304U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 3U)) + 199970353398450154U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 13U)) + 1237341696444162094U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 7991128854417613360U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 39U)) + 14809029847149045833U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 52U)) + RotL64(aCarry, 5U)) + 2559509556915775947U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 5U)) + 14336829730147834160U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8853631886733610440U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13346159398673246914U;
            aOrbiterK = RotL64((aOrbiterK * 13660497151446983393U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12121095718571872976U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16239781125815589804U;
            aOrbiterA = RotL64((aOrbiterA * 5157009090454962231U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9051377033794324106U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13805815136723461780U;
            aOrbiterF = RotL64((aOrbiterF * 571129481747181357U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14849157800322754413U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18116651528452542634U;
            aOrbiterJ = RotL64((aOrbiterJ * 3638480428016835537U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4105057226952948599U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5911714320560994391U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1796514171654961389U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4439149331729987587U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10278532228230163632U;
            aOrbiterI = RotL64((aOrbiterI * 17428224919864716517U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2342456582668741750U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2360578572554664800U;
            aOrbiterH = RotL64((aOrbiterH * 1108428466956691925U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12132934875391401246U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17213278726790245812U;
            aOrbiterG = RotL64((aOrbiterG * 11904899990681410419U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7994340481560109811U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13735851271080138255U;
            aOrbiterC = RotL64((aOrbiterC * 12387076892129731557U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6682417543888875268U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15642799286975840550U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7861250716882028053U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9839299346094784067U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14214886793361825363U;
            aOrbiterB = RotL64((aOrbiterB * 2103132743364916037U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 38U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 27U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterA, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aCross, 46U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterA, 60U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 11U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 56U) + aOrbiterH) + RotL64(aOrbiterE, 53U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneD
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11630U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 13098U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 11098U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16215U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 16164U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 10U)) ^ (RotL64(aIngress, 43U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererA + RotL64(aPrevious, 3U)) + 9471546960258473684U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 18050235435948942244U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 52U)) + RotL64(aCarry, 57U)) + 3005107102671544641U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 43U)) + 17898396434573801850U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 47U)) + 15071602525497771648U;
            aOrbiterK = (aWandererC + RotL64(aCross, 5U)) + 5780119462702672108U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 38U)) + 13301326224151025687U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 57U)) + 18129323022260575961U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 1199228670638790709U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 35U)) + 1839199978088021020U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 13U)) + 4999517042246790165U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8788607633376516299U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15143903839930468749U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12735914889325422675U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16674732686428431869U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15908873150953195581U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18049755517524334107U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11204775359756474667U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2525984309543939465U;
            aOrbiterB = RotL64((aOrbiterB * 3988529812023791571U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4566345170476825512U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14876612901557406267U;
            aOrbiterG = RotL64((aOrbiterG * 9047956948845135339U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14926290877038883931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12710203178186614846U;
            aOrbiterE = RotL64((aOrbiterE * 14841163494801662515U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7315094513967387996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11050116830482816766U;
            aOrbiterF = RotL64((aOrbiterF * 3702999495721152019U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4505368486032503953U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17905748055257551092U;
            aOrbiterJ = RotL64((aOrbiterJ * 14775870175093453197U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5728886950801376350U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17998141690182325170U;
            aOrbiterI = RotL64((aOrbiterI * 16008599930125391379U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4325978018819134558U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13526905108565989379U;
            aOrbiterH = RotL64((aOrbiterH * 14121321495714166291U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10597169665474269506U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7500801022830471869U;
            aOrbiterA = RotL64((aOrbiterA * 3702717219742363777U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17063616328548689935U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9471546960258473684U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3029748230803396737U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 44U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterA, 41U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 22U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 30U) + aOrbiterB) + RotL64(aOrbiterE, 18U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterF, 5U));
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterI, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17542U)) & S_BLOCK1], 36U) ^ RotL64(aSnowLaneA[((aIndex + 16759U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16461U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17293U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18552U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 34U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 43U)) + 7960325128608297381U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 21U)) + 12773836012104052042U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 19U)) + 3173972621347773016U;
            aOrbiterB = (aWandererA + RotL64(aCross, 37U)) + 3708401356314308171U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 57U)) + 950774285720019449U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 3U)) + 4170092315705438265U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 17000449130864980747U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 39U)) + 8793910540062893860U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 13U)) + 520277969543516469U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 29U)) + 12762214857389827271U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 10U)) + RotL64(aCarry, 21U)) + 2932451184340207695U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11062179998786293839U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7919119215271524178U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9053677007180081359U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1774988449597115155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3799792889466518953U;
            aOrbiterA = RotL64((aOrbiterA * 17512791286490623455U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1815062051307896589U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15260373951371654483U;
            aOrbiterH = RotL64((aOrbiterH * 2208604434669491625U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12867546628945676853U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7772820973895846946U;
            aOrbiterI = RotL64((aOrbiterI * 7581704643538761985U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14213957831821966834U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16561105721170419454U;
            aOrbiterK = RotL64((aOrbiterK * 2540533987337175367U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16556502948339949526U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9706742922075498974U;
            aOrbiterD = RotL64((aOrbiterD * 8527361328901355457U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13455756934917486016U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9107769876332723454U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1722386100852683783U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15793099079168487016U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7968278803691283365U;
            aOrbiterC = RotL64((aOrbiterC * 11644765391940099387U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15068302421261745111U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11373111908765197862U;
            aOrbiterG = RotL64((aOrbiterG * 17756438368103196771U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6362100123286229887U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 528778333872160609U;
            aOrbiterB = RotL64((aOrbiterB * 17377710146983314215U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6116442644744391285U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7960325128608297381U;
            aOrbiterF = RotL64((aOrbiterF * 17826511435509927061U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterC, 10U));
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterB, 37U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 13U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterI, 35U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterH, 48U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 53U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24989U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((aIndex + 25408U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 24483U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25892U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneA[((aIndex + 26710U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 24U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererD + RotL64(aPrevious, 11U)) + 2617613537256538553U;
            aOrbiterC = (aWandererA + RotL64(aCross, 44U)) + 16642868916835132715U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 51U)) + 10860291124337073254U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 23U)) + 6432511273906902472U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 7505375005848241910U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 39U)) + 11086616004678821329U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 3298830587569881951U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 9775143140064220979U;
            aOrbiterI = (aWandererG + RotL64(aCross, 13U)) + 4147601326580823120U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 21U)) + 12245920269898100415U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 18U)) + 8391940489176734499U) + aPhaseFOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17876893379544668477U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 18301882058180370541U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16680384667098921309U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6869225862715140102U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15404118372589259800U;
            aOrbiterK = RotL64((aOrbiterK * 5766851935950389915U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17757381020518233814U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17677969146092374455U;
            aOrbiterF = RotL64((aOrbiterF * 3469432916562405063U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15783378556632870114U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5792858258663697864U;
            aOrbiterB = RotL64((aOrbiterB * 12008981883482080427U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11737803388202260296U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16001927091970715330U;
            aOrbiterG = RotL64((aOrbiterG * 3062030309852922061U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1749586939123286632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6169421068855905938U;
            aOrbiterD = RotL64((aOrbiterD * 12374789910763348695U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10073586820719728062U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17744171227198661555U;
            aOrbiterI = RotL64((aOrbiterI * 10658375268803957647U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1149819647337612792U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7725598665625892006U;
            aOrbiterA = RotL64((aOrbiterA * 15097586655234391559U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13930096050550704122U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3632241034947389647U;
            aOrbiterJ = RotL64((aOrbiterJ * 8442222389196610427U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17933893495867517142U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7888594392078082482U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9809847720610861237U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10805303827043372168U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2617613537256538553U;
            aOrbiterH = RotL64((aOrbiterH * 3940471942234248791U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 48U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterC, 51U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterA, 5U));
            aWandererD = aWandererD + (((RotL64(aScatter, 46U) + aOrbiterB) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterD, 56U)) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 27U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterC, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 42U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29484U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 29510U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 28657U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27594U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 28166U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 56U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 7790166497945719700U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 19U)) + 7136208896846119188U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 57U)) + 12123156943355100886U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 53U)) + 5095546037880875199U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 23U)) + 17642705393916765992U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 43U)) + 9918479837334416990U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 47U)) + 4890009823843176466U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 47U)) + 17652590786213674124U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 57U)) + 870002527644696135U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aScatter, 29U)) + 12545429703552643682U;
            aOrbiterK = (aWandererH + RotL64(aCross, 13U)) + 5310272867406182581U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3264719049050179440U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1967241238180278937U;
            aOrbiterI = RotL64((aOrbiterI * 13004319774269457957U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 773883832927040736U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12766817190261232485U;
            aOrbiterE = RotL64((aOrbiterE * 7448864556802318431U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 260069382395598265U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15462103891287350123U;
            aOrbiterG = RotL64((aOrbiterG * 5029268763635635753U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4072032867513289827U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17153061419083897076U;
            aOrbiterD = RotL64((aOrbiterD * 11934532169271718913U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 6207264270332656966U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 18048064697837314947U;
            aOrbiterC = RotL64((aOrbiterC * 13632594619404208489U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14484617445340272026U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16160443600497652026U;
            aOrbiterH = RotL64((aOrbiterH * 1988599349457831597U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5873314228291583482U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16418290052752166515U;
            aOrbiterB = RotL64((aOrbiterB * 18270363452003213317U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9158414409987627714U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8205937960146492168U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14008398661393344261U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16386126219854809263U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12418021156683187869U;
            aOrbiterA = RotL64((aOrbiterA * 13897930566207284517U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5427232681451476584U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 18237670074497382745U;
            aOrbiterK = RotL64((aOrbiterK * 15528665160297906195U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8330262458028468513U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7790166497945719700U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6001280767763971107U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 48U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 22U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterD, 29U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterD, 37U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 24U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aIngress, 14U) + RotL64(aOrbiterA, 5U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 54U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Lacrosse_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
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
    // GROW_A grow_key_a (start)
    {
        // grow_key_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aInvestLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5194U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 5320U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 1266U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4680U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3449U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 6009U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 54U)) + (RotL64(aCarry, 29U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 16160838483846078448U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 43U)) + 15404960896190227946U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 16904160594024977199U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 17790460246821031802U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 54U)) + 16395168254086971959U) + aPhaseGOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7484373204039901786U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 18026814691322913510U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12688155753775099489U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15244817793136966450U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5795491730356335666U;
            aOrbiterK = RotL64((aOrbiterK * 13253529465289332171U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3163873518027801504U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2690791759507349172U;
            aOrbiterD = RotL64((aOrbiterD * 16677948635136515083U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17898067251167087906U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8028010015006604239U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5601629670521300241U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7304739457289910555U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6476837815096530043U;
            aOrbiterA = RotL64((aOrbiterA * 16380545138701113267U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 10U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterK) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 28U) + aOrbiterH) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 20U));
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // grow_key_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14098U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 10330U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 12942U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8772U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15625U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 15885U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 6U)) + (RotL64(aCarry, 19U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererC + RotL64(aIngress, 56U)) + 12583180859826261500U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 9067093488553721468U) + aPhaseGOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 13U)) + 12173106198862881754U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 11333491014394592654U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 3511883526940919554U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7416810692106273044U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8341174972619784110U;
            aOrbiterD = RotL64((aOrbiterD * 17722163445765437279U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2220852854836962979U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8090781422229383825U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 578293950675644397U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2338801236599102223U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12484514711848308104U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10364216764253366067U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13684861340589131816U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12796636819991873058U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5533508014234835669U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7634198650894837690U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10240326122201201762U;
            aOrbiterH = RotL64((aOrbiterH * 8758703497719125901U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterB, 60U));
            aWandererH = aWandererH + ((((RotL64(aCross, 37U) + RotL64(aOrbiterD, 37U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterD) + aPhaseGWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 6U) + aOrbiterD) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 51U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aInvestLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20080U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((aIndex + 18812U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 21775U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18870U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16495U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17285U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 42U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aCross, 53U)) + 6024062041314952357U) + aPhaseGOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 18340757093658015585U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 18U)) + RotL64(aCarry, 41U)) + 11911120493880346751U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 5U)) + 17428074353884654439U) + aPhaseGOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 12790849760814795936U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12633397052172117800U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11946150433665237945U;
            aOrbiterA = RotL64((aOrbiterA * 10324089534873171291U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16842157900909419285U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14186235783224155962U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10521157787073684417U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13284904542579767591U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 11609181965078844357U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5455780554452453513U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9628562297095374984U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7850281529011259759U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17611485102925470357U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 257458718073794527U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10693404545773519306U;
            aOrbiterH = RotL64((aOrbiterH * 14821443722828498323U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 21U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterA, 60U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterE, 39U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 20U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // grow_key_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneA, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneA backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29330U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 26146U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 25844U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25170U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27446U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31816U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 12U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 1042610313571524121U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 13U)) + 3505725321008825582U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 12584654563843782991U) + aPhaseGOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 39U)) + 6645399144515770935U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 35U)) + 3608978423753715584U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8089198857670370983U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15207251813516399879U;
            aOrbiterH = RotL64((aOrbiterH * 7596841660069752069U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9579268660105824516U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16055044469473802812U;
            aOrbiterB = RotL64((aOrbiterB * 2269649280637188723U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 583811872609805949U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7027491967970873942U;
            aOrbiterK = RotL64((aOrbiterK * 12686754713465826139U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18256061823189677508U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12708429127816136937U;
            aOrbiterD = RotL64((aOrbiterD * 12593886633108075321U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12169216645156306078U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12694325407567795065U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3711789483877261899U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterG, 43U));
            aWandererG = aWandererG + (((RotL64(aIngress, 42U) + RotL64(aOrbiterD, 54U)) + aOrbiterB) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 3U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
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

void TwistExpander_Lacrosse_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
        // ingress from: aExpandLaneA, aExpandLaneB, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7459U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 2558U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 2526U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4447U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7029U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 4288U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 35U)) + 16462052553719977502U) + aPhaseHOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 12337064059566619581U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 15801005007094515447U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 5U)) + 8228706742665081656U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 13U)) + 11006723027845190869U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 18173765337829177450U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 530215083653542558U;
            aOrbiterC = RotL64((aOrbiterC * 8938680024265564887U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6608611827035564511U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2246051826221626809U;
            aOrbiterG = RotL64((aOrbiterG * 6333352641495253539U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5228575308895381421U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10999213210689606857U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5467601259546342925U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3773371037240485696U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8887985779436152504U;
            aOrbiterB = RotL64((aOrbiterB * 698713082830739677U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 11150566414723818350U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8336366151003049546U;
            aOrbiterK = RotL64((aOrbiterK * 9033771197242493699U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 21U)) + aOrbiterC) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterE, 13U));
            aWandererK = aWandererK + ((((RotL64(aCross, 38U) + aOrbiterG) + RotL64(aOrbiterE, 38U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterE, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 38U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // grow_key_b loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aInvestLaneB
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15636U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 12847U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8623U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16082U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8364U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 10712U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 58U) + RotL64(aIngress, 41U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererK + RotL64(aCross, 56U)) + 15904465836916519864U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 17725629806317789307U) + aPhaseHOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 13794170125914914828U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 2149055907476874332U;
            aOrbiterE = (aWandererB + RotL64(aCross, 39U)) + 5342047776745074649U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8268148484060546838U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10821151364028563719U;
            aOrbiterI = RotL64((aOrbiterI * 13626634259250509711U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4294213820894407378U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10884726101307943090U;
            aOrbiterF = RotL64((aOrbiterF * 1116128870387229159U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16432210042202444824U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15196602644336228055U;
            aOrbiterJ = RotL64((aOrbiterJ * 12680438355124070237U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14117787670220328165U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 219833877949480215U;
            aOrbiterH = RotL64((aOrbiterH * 10736293047771972173U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3326396981881473962U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14918513066311426279U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14269763278564574663U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 26U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 56U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + aPhaseHWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 38U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_b loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aInvestLaneC
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20539U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((aIndex + 16701U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 17660U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19354U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23436U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 20099U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererD + RotL64(aCross, 13U)) + 9914837590440975587U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 6706125076401958051U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 16570817772679258409U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 4U)) + 6843705658115186948U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 16099930446791572351U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5420550009556030459U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5729549069420177477U;
            aOrbiterJ = RotL64((aOrbiterJ * 7842192631021712569U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15590601126188675834U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13044027390998620029U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16845199115313444123U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11068338135659636772U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6584988841809544332U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1683336180438945439U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8516813219883915404U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10647314042912492785U;
            aOrbiterE = RotL64((aOrbiterE * 15559481057047148785U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 201691689889605304U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15512161798401184003U;
            aOrbiterB = RotL64((aOrbiterB * 11473219183982564709U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 19U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aIngress, 36U) + RotL64(aOrbiterA, 5U)) + aOrbiterE) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 27U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 42U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // grow_key_b loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32036U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 28663U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 27813U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26223U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26069U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 25420U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 4U)) ^ (RotL64(aCross, 19U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererD + RotL64(aIngress, 13U)) + 6521330037475130256U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 12611880456055428940U) + aPhaseHOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 24U)) + RotL64(aCarry, 23U)) + 12061611078130934708U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 1558112410801116984U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + 10509115227850160786U) + aPhaseHOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4045915960688792066U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1196541286513243082U;
            aOrbiterI = RotL64((aOrbiterI * 5454309408259753479U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 15564991032722373702U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4897765238703641798U;
            aOrbiterD = RotL64((aOrbiterD * 9693901276712946763U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12327429514907752733U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6189189797708711636U;
            aOrbiterB = RotL64((aOrbiterB * 9017615866338877651U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6374267075282018852U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1888758503831341439U;
            aOrbiterF = RotL64((aOrbiterF * 74387714918264257U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14956857689299491800U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14879361107223331957U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9166712966729591953U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterF, 44U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterD, 53U));
            aWandererB = aWandererB + ((((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 5U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 57U);
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
