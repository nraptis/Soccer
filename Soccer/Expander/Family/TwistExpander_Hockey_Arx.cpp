#include "TwistExpander_Hockey_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Hockey_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x995A28B1365A2025ULL + 0x84A605890B2A45C4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA7EA4086E3031697ULL + 0x93A846601CF7538AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCA470FAD2F2B4C69ULL + 0x862411463268150BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFCE88B5AACC7D18FULL + 0x869EF80BBFB23798ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE43AAC0480626F0BULL + 0x8606D182A7F7D203ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8322994921D43199ULL + 0xFD2DE8DDE258B266ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB2C315232DEB2FBBULL + 0xB8A1DA1B288D5248ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA2595A7DE6C96F6FULL + 0xCA5FE119CC561CE0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB850834B691767B3ULL + 0xBBCDCA00CB9FAB09ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD098B9639EE5B18DULL + 0x84DF9F3251CF4EE6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8A47CA093EE53F1BULL + 0xBDF639C7F436B87AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC679991BB0A66A21ULL + 0xDACB709DF799A740ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBC77878ECB633B27ULL + 0xA00EA914B3B2D8A3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9D8694A5B3930301ULL + 0x9BC9A0C0F26CCDFBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x83CCB318B0D2953BULL + 0xA7D32C0ED91F9528ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA879F177C563F369ULL + 0xD8042EAF150D33BBULL);
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
            aIngress = RotL64(mSource[((aIndex + 3063U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1248U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2245U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 3025U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 19U)) + (RotL64(aPrevious, 52U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 18U)) + RotL64(aCarry, 19U)) + 8506388683755208267U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 21U)) + 2179323259055019735U) + aNonceWordF;
            aOrbiterE = (aWandererI + RotL64(aScatter, 39U)) + 3345902531140983016U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 17456139311481306584U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 57U)) + 14587864088462311164U) + aNonceWordP;
            aOrbiterG = (aWandererH + RotL64(aCross, 37U)) + 13178947246650647057U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 35U)) + 12866578138946916962U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 13098524333655118173U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 3U)) + 15451329483787541982U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 14U)) + 9494299579678389385U) + aNonceWordK;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 11U)) + 15581954810375490643U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 4487042505730624892U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2774455928791636186U;
            aOrbiterE = RotL64((aOrbiterE * 15847933919136777451U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12435319582397755819U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10077180055177766823U;
            aOrbiterB = RotL64((aOrbiterB * 3924363471701748703U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10391963896910956455U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6149237416725301794U;
            aOrbiterC = RotL64((aOrbiterC * 10115917698918612823U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15673402771629639978U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14729117178956592426U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 9070464269215820531U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14492001279368870240U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6278248084483259952U;
            aOrbiterK = RotL64((aOrbiterK * 16731228350971263873U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15727518866499740411U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8652631010810965473U;
            aOrbiterA = RotL64((aOrbiterA * 9508484121620912715U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13660890300188313775U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14699253534935936300U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3978135617259934869U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1621689916308271346U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5651399428852950385U;
            aOrbiterG = RotL64((aOrbiterG * 12220143634120124133U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9833573729127477238U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11171647423058940388U;
            aOrbiterH = RotL64((aOrbiterH * 9692915620701425697U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10346908196429120039U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11972183669378621435U;
            aOrbiterJ = RotL64((aOrbiterJ * 12364429258926549335U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11063215816236490488U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8506388683755208267U;
            aOrbiterD = RotL64((aOrbiterD * 11514304191652750181U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 18U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterG, 21U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 47U)) + aOrbiterG) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 11U));
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 56U)) + aOrbiterJ) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterE, 13U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + aNonceWordC) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 6581U)) & S_BLOCK1], 24U) ^ RotL64(pSnow[((aIndex + 8801U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5853U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 9992U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 24U)) ^ (RotL64(aCross, 37U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 47U)) + 8685374557928800912U) + aNonceWordF;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 3482312691892161229U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 35U)) + 6948130297389161165U) + aNonceWordP;
            aOrbiterK = ((aWandererH + RotL64(aCross, 26U)) + RotL64(aCarry, 37U)) + 5506385663788942690U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 53U)) + 17859982009307397161U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aCross, 11U)) + 9178488809207094043U) + aNonceWordL;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 29U)) + 1835479501226057169U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 13U)) + 5368101733632614939U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 37U)) + 9050459666576835422U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 4U)) + RotL64(aCarry, 47U)) + 9042186993119635078U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 23U)) + 17528342580198295025U) + aNonceWordM;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6495418332558436882U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8834495762667327342U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 10783141541937645995U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4364314196965690905U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6357485231062120459U;
            aOrbiterB = RotL64((aOrbiterB * 289429584586504995U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3321488322626415347U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10817330671781848737U;
            aOrbiterF = RotL64((aOrbiterF * 15875919466358823335U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 17974092279281611763U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2871472057292789157U;
            aOrbiterG = RotL64((aOrbiterG * 16104199340711015181U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15187929795092006849U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13482063681546475923U;
            aOrbiterJ = RotL64((aOrbiterJ * 14466266308157364963U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6232152545071397380U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17488906002621373262U;
            aOrbiterA = RotL64((aOrbiterA * 4719340606442742577U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12444819880507588549U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13808941689757772497U;
            aOrbiterD = RotL64((aOrbiterD * 6541360905282412317U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8049361354387692374U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7137831335606542401U;
            aOrbiterE = RotL64((aOrbiterE * 11022231291507235007U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7230759462019420058U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3923744511976096944U;
            aOrbiterK = RotL64((aOrbiterK * 9953869624243563101U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15967667946023263856U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8677583624693910669U;
            aOrbiterC = RotL64((aOrbiterC * 10737731876339973717U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1604347321263511013U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8685374557928800912U;
            aOrbiterH = RotL64((aOrbiterH * 14103365695918844461U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 28U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterC, 37U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterF, 6U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + aNonceWordA) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 27U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterD, 19U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 14U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + aNonceWordD);
            aWandererD = aWandererD + (((((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 14U) + aOrbiterA) + RotL64(aOrbiterI, 53U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 12785U)) & S_BLOCK1], 20U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 11069U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15060U)) & S_BLOCK1], 6U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 13691U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 26U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 41U)) + 14499676118633326000U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 56U)) + 17191273593018552288U) + aNonceWordC;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 29U)) + 4085176294948097737U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 51U)) + 11112671474158908186U) + aNonceWordO;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 8745787969012266485U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 18074049663777707948U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 2543758649719164688U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 18U)) + 4659584749412700523U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aCross, 53U)) + 974639159259871273U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 13U)) + 9211220687971081987U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 47U)) + 8567024626862182714U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5803002132294840900U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11968489432878148467U;
            aOrbiterH = RotL64((aOrbiterH * 4501441062617123165U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9470807228394903442U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1692347973120388469U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17433393164156231575U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16510815732690193145U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 755159406833096510U;
            aOrbiterB = RotL64((aOrbiterB * 14091736464659561165U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1518824876475937620U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 701225390867330446U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12264618860580199927U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8425976693733003889U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 7182176375442410367U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 8860605703761731859U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4546566785167467924U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2593340999038753749U;
            aOrbiterJ = RotL64((aOrbiterJ * 10152461487764567563U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9756331608356622299U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5511625814747641978U;
            aOrbiterK = RotL64((aOrbiterK * 4806076157539829529U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8694400787420160733U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12648969491371382682U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5346585704222643759U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15261238546696118531U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14236129054778329471U;
            aOrbiterD = RotL64((aOrbiterD * 11789581469516267749U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16251500056378064213U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 790320176607605195U;
            aOrbiterI = RotL64((aOrbiterI * 15706130623435648555U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17114773669444878655U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14499676118633326000U;
            aOrbiterE = RotL64((aOrbiterE * 8095707555083587081U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 30U));
            aWandererC = aWandererC + (((RotL64(aIngress, 24U) + aOrbiterB) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterI, 57U));
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 51U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterF) + aNonceWordN);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 46U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 53U)) + aOrbiterA) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 44U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterK, 37U)) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 14U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20778U)) & S_BLOCK1], 34U) ^ RotL64(pSnow[((aIndex + 17394U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 18611U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 19677U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((aIndex + 18726U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 22U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererE + RotL64(aIngress, 43U)) + 380024772508948442U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 53U)) + 7649029098162567210U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 5U)) + 5329304598870421851U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 12306118665045151326U) + aNonceWordK;
            aOrbiterG = (((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 39U)) + 960751560457324256U) + aNonceWordP;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 51U)) + 3244070254386191876U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 47U)) + 15733408571609521746U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 17623448932647018544U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 11U)) + 8787759896149035829U;
            aOrbiterE = (aWandererB + RotL64(aCross, 14U)) + 14741681792348288162U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 23U)) + 8801731213568307302U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9872248187499779222U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15407371518644528235U;
            aOrbiterI = RotL64((aOrbiterI * 1245102406469471673U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4242060317152943062U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9942784962409917541U;
            aOrbiterB = RotL64((aOrbiterB * 888649755587764533U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7296348796484458631U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15061417216070157797U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 10349554676953256231U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3233185810644297433U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9241229457641024287U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2728237515724597517U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8464051359381554575U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3307872165699029375U;
            aOrbiterG = RotL64((aOrbiterG * 4859663401033023433U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5482617843966711997U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4442149210462943872U;
            aOrbiterE = RotL64((aOrbiterE * 8979352218576515647U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10591636597580147381U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14925122230279312217U;
            aOrbiterD = RotL64((aOrbiterD * 15038171961638724013U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 9772367878232735350U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15800661165607190092U;
            aOrbiterH = RotL64((aOrbiterH * 10493976952980533589U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1571665862499272194U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3162847040693387901U;
            aOrbiterC = RotL64((aOrbiterC * 2747235335326991399U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4868791925868749848U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13134549226315884613U;
            aOrbiterK = RotL64((aOrbiterK * 3551955270718495869U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7830447320021657240U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 380024772508948442U;
            aOrbiterJ = RotL64((aOrbiterJ * 5143324968958616357U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 28U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 22U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 24U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterA, 53U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 24U) + RotL64(aOrbiterB, 27U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterK, 44U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27169U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 25903U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(pSnow[((aIndex + 23705U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((aIndex + 22397U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22405U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 25591U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 44U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 48U)) + RotL64(aCarry, 19U)) + 9914837590440975587U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 43U)) + 6706125076401958051U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 39U)) + 16570817772679258409U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 6843705658115186948U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 23U)) + 16099930446791572351U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 37U)) + 5420550009556030459U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 5729549069420177477U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 35U)) + 15590601126188675834U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 46U)) + 13044027390998620029U) + aNonceWordI;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 27U)) + 11068338135659636772U) + aNonceWordJ;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 57U)) + 6584988841809544332U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8516813219883915404U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10647314042912492785U;
            aOrbiterF = RotL64((aOrbiterF * 15559481057047148785U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 201691689889605304U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15512161798401184003U;
            aOrbiterG = RotL64((aOrbiterG * 11473219183982564709U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 3883760518944464145U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13861805129175491145U;
            aOrbiterK = RotL64((aOrbiterK * 17194438894492581181U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12019138626550801486U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13030350224959652248U;
            aOrbiterD = RotL64((aOrbiterD * 11724200983306280107U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2643807255422544248U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4127143302485631794U;
            aOrbiterC = RotL64((aOrbiterC * 5441038881111578487U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14602951930809633069U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4555737199162278494U;
            aOrbiterJ = RotL64((aOrbiterJ * 12415825635220991865U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6343143902997169834U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10404783711336491985U;
            aOrbiterE = RotL64((aOrbiterE * 6235474458879439079U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7406959231434835393U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6684368109277850196U;
            aOrbiterH = RotL64((aOrbiterH * 8760360417572331159U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4835889355927954728U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7917682889852676712U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9045350756570117327U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10268055422944417055U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5563744562922937643U;
            aOrbiterI = RotL64((aOrbiterI * 12442484191329795173U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17244672945880141679U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9914837590440975587U;
            aOrbiterA = RotL64((aOrbiterA * 12269340309792850489U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 48U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 40U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 29U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 52U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterI, 6U)) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterI, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30839U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 29248U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30639U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29449U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32337U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 29096U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28321U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 29U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (aWandererB + RotL64(aPrevious, 23U)) + 4751694786009671052U;
            aOrbiterC = (aWandererK + RotL64(aCross, 53U)) + 16362725160370844224U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 47U)) + 6360885380915941057U) + aNonceWordI;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 40U)) + RotL64(aCarry, 11U)) + 5154536007972297036U) + aNonceWordH;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 27U)) + 9362540581874808253U;
            aOrbiterF = (aWandererE + RotL64(aCross, 13U)) + 13902493871525612934U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 19U)) + 10208452885367546542U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 36U)) + RotL64(aCarry, 5U)) + 3117030377279160998U) + aNonceWordK;
            aOrbiterA = (aWandererD + RotL64(aCross, 3U)) + 17286247690414027870U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 3930314320040949141U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aScatter, 5U)) + 7289525252391668404U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3434167955466809185U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 17852573095128575663U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1485660158767033425U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6137259687928853253U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 13992510605237574698U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 15346263295995333395U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6470556523400123474U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4333255670390099293U;
            aOrbiterI = RotL64((aOrbiterI * 11089933812030082647U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7700424876430257995U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16920736951239453071U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8920407493132380497U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1635071690430295730U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9966700845966398620U;
            aOrbiterC = RotL64((aOrbiterC * 17210048121896546867U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9833458070123027075U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1990346556486746432U;
            aOrbiterD = RotL64((aOrbiterD * 8704943923474148699U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 13339523466436517327U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5018264760406215603U;
            aOrbiterA = RotL64((aOrbiterA * 2769197961801783627U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 123427497520755346U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4535841104215792886U;
            aOrbiterE = RotL64((aOrbiterE * 1417676310539177131U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3525925567359163763U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3273741481392187986U;
            aOrbiterH = RotL64((aOrbiterH * 16116160744647235811U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6230742908784102407U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7578784912496239362U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2614448818452560369U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14669810330213234082U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4751694786009671052U;
            aOrbiterB = RotL64((aOrbiterB * 9583151676882991817U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 4U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 38U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aCross, 34U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 41U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterB, 24U)) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 24U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Hockey_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA8E0A613B7D9424DULL + 0xF8824F2F3451E0CFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE0F5824CE5E81C27ULL + 0xAF2B3AC12D4D0A7CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA0D87819D4461757ULL + 0xB01CD5A50BB886BEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8BBE6780E71C7FB1ULL + 0xAD0D3C81AF51742AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB025E99E082BFE77ULL + 0xED05573CB3B09C1FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC323C1B18A426E19ULL + 0xCC5C0F510F4FCDCCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFDAE5E281BA31F0DULL + 0xCB57424A680F392DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEEFDBD9BD3C8BB3BULL + 0xD34F2A33294E8185ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA32B78E1747D548BULL + 0xAAAF842F767A2C36ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBE3A8047D1CCF2CBULL + 0xE775BD6C05A219C6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEE6B521CF304AF69ULL + 0xBA02FD2E54098908ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xADFD1B66F18194D5ULL + 0x88F3AC9C2A2E0AA6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEA8880988D7113A5ULL + 0xDEF43F0CAF858E69ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC591E230CE1051F1ULL + 0xC32E4322D4A5D1C7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD83E25F9B2AE9BFBULL + 0x8F7428C55309D57EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x96BC4EED01CA7013ULL + 0xE02AC53B5553FFC4ULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 4188U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 2586U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2534U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 3444U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (((aWandererF + RotL64(aScatter, 43U)) + 252059974543142812U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 58U)) + 11690823093681457368U) + aNonceWordM;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 47U)) + 13282189752890971123U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 53U)) + 9507416294305708435U) + aNonceWordD;
            aOrbiterI = (aWandererE + RotL64(aScatter, 29U)) + 14053038174390776539U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 14605253312318725009U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 20U)) + RotL64(aCarry, 39U)) + 18138286582677863671U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 8530091235978489988U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 39U)) + 14381731677571170073U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13316413456378978456U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3910529530149320706U;
            aOrbiterF = RotL64((aOrbiterF * 16000139333493588429U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6302070286831566901U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12324134652758551396U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 17136438281540250165U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4773478557638475048U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4031153435446078944U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3876928995240982769U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3114794895962903899U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3552936509969106796U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 16823186892738820299U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5828754613946145627U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17985241114076114558U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 1986669631395606833U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11319331046368072261U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6104267020171882160U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12525117969211576177U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7662668379725735125U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6583034411403600735U;
            aOrbiterH = RotL64((aOrbiterH * 262095656452193889U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5569865728026310280U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4176065898330374039U;
            aOrbiterA = RotL64((aOrbiterA * 11305749530796963967U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13677146592276526676U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2734371113158117596U;
            aOrbiterD = RotL64((aOrbiterD * 13146444882662731975U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 18U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 27U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 20U)) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 51U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + aNonceWordA);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterC, 56U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 7744U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 5759U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6003U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9029U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6653U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 50U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 12136097566601676613U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 26U)) + RotL64(aCarry, 19U)) + 7969431322248040056U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 10530676021510553889U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 37U)) + 8740777303075445264U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 5U)) + 13249434169895564739U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererH + RotL64(aCross, 30U)) + 15529577005925628472U) + aNonceWordG;
            aOrbiterC = (aWandererC + RotL64(aIngress, 57U)) + 344627093687331562U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 51U)) + 8824277416519988893U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 19U)) + 5636276438449709875U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2079413361031851552U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7807998179168655561U;
            aOrbiterK = RotL64((aOrbiterK * 961456853699784753U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13589392896232029112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10733011474804473996U;
            aOrbiterF = RotL64((aOrbiterF * 361749145931578805U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15934162328347805968U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7573511217796245232U;
            aOrbiterC = RotL64((aOrbiterC * 10694563909931636155U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4828475187337891975U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13284974329890393113U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10831075817642374287U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13173869918669643112U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15841507674783398167U;
            aOrbiterB = RotL64((aOrbiterB * 15632933198136963277U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14168272451055700516U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11134471485501999898U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 8019507184494591705U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2611858916687822610U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 17863271539727513641U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4987884722174985677U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8874401993454249066U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5131480593493950665U;
            aOrbiterG = RotL64((aOrbiterG * 8585874663602346121U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9366563022381918996U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7890729519928340296U;
            aOrbiterA = RotL64((aOrbiterA * 11428572374057899517U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 54U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterC, 53U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 11U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterB, 28U)) + aOrbiterI) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 48U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 35U)) + aOrbiterG) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterK, 23U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 14084U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 13558U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 13796U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11594U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13118U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 60U)) + 1393781663398437180U) + aNonceWordF;
            aOrbiterF = (aWandererC + RotL64(aIngress, 47U)) + 17414594746688585273U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 2823888497053071250U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 41U)) + 17032631958617884859U) + aNonceWordI;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 6U)) + RotL64(aCarry, 13U)) + 15222697630461125019U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 13U)) + 15737414920751551780U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 1357196111055783001U;
            aOrbiterC = (aWandererA + RotL64(aCross, 35U)) + 5315122321649251691U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 29U)) + 7893744655508595974U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16721939414324611738U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3444375866323610848U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10874157227815775661U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1825716513674511632U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15582066843912467318U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12765146555943757373U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15673590949193923915U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13887365046280406413U;
            aOrbiterH = RotL64((aOrbiterH * 3169061375011420121U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12730414371734709356U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4819112390640821927U;
            aOrbiterC = RotL64((aOrbiterC * 8782547948627685451U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3089925954422937464U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7180179304678622530U;
            aOrbiterG = RotL64((aOrbiterG * 16118051565147747413U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17030269962085008657U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6675917351883004046U;
            aOrbiterI = RotL64((aOrbiterI * 14134335325316949687U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12572022803491077491U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 2801421744689267375U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 315045745990934023U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4335148696780313055U) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12526298573395110141U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 11276803410698178607U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6984239833558496091U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12195433952105336808U;
            aOrbiterE = RotL64((aOrbiterE * 8642600547427664495U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 22U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 34U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterD, 18U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 39U)) + aOrbiterD) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20169U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 20564U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21718U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20796U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneD[((aIndex + 17750U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 52U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (aWandererA + RotL64(aIngress, 43U)) + 11698283336767769359U;
            aOrbiterH = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 13297826354831483872U) + aNonceWordM;
            aOrbiterK = (aWandererD + RotL64(aScatter, 34U)) + 15254999058287530795U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 53U)) + 17474166585085346567U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 19U)) + 15684783498452840289U) + aNonceWordD;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 23U)) + 5061229733465216486U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 15370981279168377944U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 17966672773619554092U) + aNonceWordK;
            aOrbiterF = ((aWandererF + RotL64(aCross, 10U)) + 14685092893994491068U) + aNonceWordB;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12798804186209406389U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2848444181474221574U;
            aOrbiterK = RotL64((aOrbiterK * 13730480364920876877U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8551142075919636146U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8833198159158950723U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7650289040764974737U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7351473160893666232U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14204899612487622222U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 6317485031956448029U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 7008985178526543258U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13576796403863120356U;
            aOrbiterG = RotL64((aOrbiterG * 13745839827679114077U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5769784656937900699U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14075925808204936705U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5844894088757604713U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17818667502858010896U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16016922065572683130U;
            aOrbiterB = RotL64((aOrbiterB * 7525645833898085373U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1582458237855075977U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10830440354527138227U;
            aOrbiterC = RotL64((aOrbiterC * 10499386926982228251U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10653964151654643772U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11218475491129483859U;
            aOrbiterF = RotL64((aOrbiterF * 3338108067044357141U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9863649760189649255U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13790281439048354358U;
            aOrbiterH = RotL64((aOrbiterH * 4682098083538482849U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterF, 6U)) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 57U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + aNonceWordP);
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterE, 18U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterH, 39U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 27157U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneD[((aIndex + 26796U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26353U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23649U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 53U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (aWandererB + RotL64(aScatter, 10U)) + 2177539223979303669U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 3962004686551521471U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 47U)) + 8457602312617147662U) + aNonceWordG;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 18011802451816510632U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 51U)) + 9046101759168876832U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 5U)) + 11135620637431969597U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 57U)) + 15913029940697999701U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 16304193109948135982U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 42U)) + 13208892298820080981U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4182377898949419225U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13970137023071326151U;
            aOrbiterH = RotL64((aOrbiterH * 9075061559681739865U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8402396284835248583U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8859190834060657829U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13552418608113716117U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9760005337757990392U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14108277760135744897U;
            aOrbiterD = RotL64((aOrbiterD * 4474681104256093885U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12226316121949012350U) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3456392186754113960U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 8704729827929941215U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5004087958637038973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7176881295123125567U;
            aOrbiterC = RotL64((aOrbiterC * 15272157962928021009U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10889800478505074438U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 13728832441482547824U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 17588477761978646139U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17345665880706866772U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 301139993853297566U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5812445396758354505U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2061389844760610160U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13631862266139238355U;
            aOrbiterJ = RotL64((aOrbiterJ * 143613352104722701U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10767186080827509622U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4893486019456886013U;
            aOrbiterI = RotL64((aOrbiterI * 5194746459545610901U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + aNonceWordK);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 18U) + aOrbiterJ) + RotL64(aOrbiterI, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterB, 6U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 51U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 46U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterC, 10U)) + aNonceWordM) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 27988U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30041U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27386U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 31608U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 18087125778766689269U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 13710545066503235196U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 13U)) + 1701939704736254645U) + aNonceWordA;
            aOrbiterI = (aWandererK + RotL64(aCross, 22U)) + 8064093611384019909U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 5U)) + 16623332751533885431U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 29U)) + 15590129153794910109U) + aNonceWordP;
            aOrbiterD = (aWandererH + RotL64(aCross, 57U)) + 7413312683079107383U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 18U)) + 4186064478651458810U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 5501191643940735954U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11064645242200570835U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13825922087298055833U;
            aOrbiterB = RotL64((aOrbiterB * 7529317892716108867U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5944980709887369970U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8181136916070569646U;
            aOrbiterK = RotL64((aOrbiterK * 395183021205661827U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15442336949157292482U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11580554435240641337U;
            aOrbiterJ = RotL64((aOrbiterJ * 6654637892858767739U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11240018128174598322U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2027565596050777471U;
            aOrbiterA = RotL64((aOrbiterA * 18048186560314431815U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16425887196883725233U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16828683527588834095U;
            aOrbiterH = RotL64((aOrbiterH * 17746289103235902485U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9923829146479008804U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 6669171007279929454U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 681823450939955099U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3902430046523165149U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6739998149289590041U;
            aOrbiterC = RotL64((aOrbiterC * 2675037435528416821U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16014401255534234075U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14741857638680634564U;
            aOrbiterD = RotL64((aOrbiterD * 8723611021403369393U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5064807861673260054U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 968747317273200299U;
            aOrbiterI = RotL64((aOrbiterI * 14122304002722582329U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterK, 28U)) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 28U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterH, 6U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterI, 47U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 24U) + aOrbiterG) + RotL64(aOrbiterK, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererF, 46U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Hockey_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAB4D0068E88E1C6DULL + 0x861FA1A45B5536BBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF79D8B38CE5CB79FULL + 0xAA3F2F2B03A8A1BDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC0EEDAEEDE513EA7ULL + 0xEF1029E179E0E9A4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x822ABE222AB54B11ULL + 0xB1DAF082C02EB586ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x89CFF42531C2289DULL + 0x98FDD682DFC44FF8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9172A45BEB21FC83ULL + 0x85B93BA9627DD87FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8491410704F9B257ULL + 0xA1CF8A54A2EF7DF0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE192ADE5BDD571A3ULL + 0xF22F1F1B69B67AA0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x835295810B8F8337ULL + 0xD6C6A9CC528B1CA0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC736D12E9DF2AE35ULL + 0xE494564F64EA1078ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC4377D859FF27A79ULL + 0xD191B00DC45D59B6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC80BA51E0ECCADCFULL + 0xDC0968B343DDDB05ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE87869F463E8D257ULL + 0x9218FC4A7340F8FCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEF5C97EE9CAEA633ULL + 0xA1D751F1E7A932AFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9485D742DE840FF9ULL + 0xBB66EC212F6F0913ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x96EE38C3706A2A03ULL + 0xA8D44260F62597FDULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1039U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((aIndex + 5369U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 219U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2148U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3192U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5967U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 22U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = (((aWandererC + RotL64(aCross, 24U)) + RotL64(aCarry, 23U)) + 7825479804710770560U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 5298124167101358123U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 3U)) + 17774541024369233726U) + aNonceWordF;
            aOrbiterK = ((((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 7679371833537454082U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 47U)) + 5385914900748772224U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3879781930908486531U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 659110346638873236U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 17439162088869824407U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10749021728538539749U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3631252455767429457U;
            aOrbiterB = RotL64((aOrbiterB * 8552825360915119613U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2271978810960685021U) + aNonceWordN;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 5963558780692551176U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 4772055335210781149U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 974909966119198104U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 9296998242911152296U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 2613629915877957661U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2245318466901521959U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13391076374843288568U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18094558036982107419U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererF = aWandererF + (((((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aNonceWordG) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterD, 4U));
            aWandererK = aWandererK + ((((RotL64(aCross, 10U) + RotL64(aOrbiterD, 39U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterA, 19U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10757U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 16164U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12753U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15852U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8377U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14952U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 13396U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 16183871922837164759U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 48U)) + 7002058258090219055U;
            aOrbiterG = ((((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 5650868611888303705U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 11899839660943876690U) + aNonceWordA;
            aOrbiterB = ((aWandererD + RotL64(aCross, 35U)) + 15349649504488111111U) + aNonceWordJ;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14060149569086744970U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12920917574225030112U;
            aOrbiterG = RotL64((aOrbiterG * 6552626684290469367U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2831994965175330135U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 18312543585028439192U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 11618182708195744321U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11657562205118394239U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10850792819281246052U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 10663100544207879337U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17810371216216125323U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 7963413941144223128U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 534217972450595401U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5498715358793875584U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9256727548911651373U;
            aOrbiterB = RotL64((aOrbiterB * 10498848323914000989U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterB, 11U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + aNonceWordD);
            aWandererD = aWandererD + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 42U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererF, 46U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18131U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 18903U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 23723U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 22711U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23093U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17523U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22968U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 1898718075389870739U) + aNonceWordL;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 5631794889237247403U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 18219714659484524607U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 56U)) + 15419581386225732921U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 5U)) + 9125575431710198210U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12205871520544965505U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7617534300497343422U;
            aOrbiterK = RotL64((aOrbiterK * 10052675719887595625U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 18017579105368135814U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10693882161946020042U;
            aOrbiterE = RotL64((aOrbiterE * 2326507900303932855U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11669615701700895306U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11045110212889232165U;
            aOrbiterJ = RotL64((aOrbiterJ * 5965171269273719849U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 18019107802806469913U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12315940560472528716U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4505122470351404065U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4899009736070044310U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17412253404253730364U;
            aOrbiterI = RotL64((aOrbiterI * 10791901166391946485U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 56U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + aNonceWordN);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordD) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 46U) + RotL64(aOrbiterK, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26902U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 27935U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 28063U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27419U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29768U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27773U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31024U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 58U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 57U)) + 12849591986267890852U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 8232614804696815750U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 47U)) + 12141567259210877281U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 34U)) + RotL64(aCarry, 41U)) + 2928641981037885644U) + aNonceWordG;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 980733350554783938U) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2683985177993350746U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 14532148403815527355U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 15985362037094864225U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7736296629433884203U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10428437770166310549U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 326634742742373401U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18327174144859461029U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6810436935194432002U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2715987179577753597U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 12606153309690753435U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17123256945895150555U;
            aOrbiterF = RotL64((aOrbiterF * 13469111258504672565U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9057777759026189541U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16478485918911194442U;
            aOrbiterK = RotL64((aOrbiterK * 11054247078884894131U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aCross, 35U) + RotL64(aOrbiterG, 12U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 20U) + RotL64(aOrbiterK, 47U)) + aOrbiterE) + aNonceWordB) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + aNonceWordO);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Hockey_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8552DA2D0C8DDD1DULL + 0x937E7E84E82E380FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x96D530F8211373A7ULL + 0xA9B1F87B915AD97EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x859B0C527D55179FULL + 0xAC939548A1897640ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC49C89E84133FEE3ULL + 0xB8FB38128B5B1B48ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC70CA41B82902EA7ULL + 0xD6DD9B91FBFDAEDFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDAF52829616A6FB9ULL + 0x90A83479BA403241ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x87E60D0DF5342EF1ULL + 0xD455EF25F7449491ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB8E41DE0ADAF89F7ULL + 0xD9941A43B2247618ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA1745C27E67D82CFULL + 0xEAA7F83C8D0BD8EEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEFE9E82FD21EA469ULL + 0xDDE1C9EA00B6DC35ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x97780E2BEE8CB8A7ULL + 0x9E2AD35B20055D04ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB782C61C6B716AB1ULL + 0xF68E914F2D51AB2CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x88BBE510A8CBAA0FULL + 0xB79F35395ACB62B6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF4F74999AFCF9979ULL + 0x873EC1B29577280FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB530B5F03A4D6D21ULL + 0xB31B4E5A01A34B7EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA29D78A663FFD9D1ULL + 0xFEC0453FB80AF459ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3987U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 1109U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5188U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5412U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4634U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2489U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = (aWandererJ + RotL64(aScatter, 60U)) + 12311607308490066301U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 37U)) + 13100864684740679846U) + aNonceWordK;
            aOrbiterE = ((aWandererG + RotL64(aCross, 47U)) + 13697304189274329704U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 9047976902871216732U;
            aOrbiterC = ((((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 2147897579538537888U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (aWandererB + RotL64(aScatter, 53U)) + 2072444829390996142U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 2129307836981020908U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10663145333751112064U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15019844390503785459U;
            aOrbiterE = RotL64((aOrbiterE * 7442321463110790449U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5460865577557928142U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15806522559993224197U;
            aOrbiterC = RotL64((aOrbiterC * 8722932687972240099U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6361113778657833389U) + aNonceWordI;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 8306013884615042570U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 8234258702656728667U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4038420580499706912U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11908091484457158973U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3964111175645156719U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11133912466611921250U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2469227904206936928U;
            aOrbiterK = RotL64((aOrbiterK * 2704438771198001599U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13234017916788297295U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9061117693840451988U;
            aOrbiterB = RotL64((aOrbiterB * 3637440416741459419U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12013423690843812324U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 14371779015144617412U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 3359568073302062667U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 57U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + aNonceWordD) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterI, 46U)) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 27U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14499U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 14246U)) & S_BLOCK1], 22U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8281U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((aIndex + 14760U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15609U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15300U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12985U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 52U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 9023059520606551446U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 5U)) + 662441755115638133U;
            aOrbiterJ = ((((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 16957253361196144712U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 26U)) + RotL64(aCarry, 47U)) + 7840955025765308605U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 41U)) + 346855809270395799U) + aNonceWordH;
            aOrbiterD = (aWandererD + RotL64(aCross, 53U)) + 16099139781586668343U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 47U)) + 3706457327118322098U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12166825885547622870U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7792658665720344200U;
            aOrbiterJ = RotL64((aOrbiterJ * 16305542632794270697U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7128477606152986326U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11116533962780290084U;
            aOrbiterA = RotL64((aOrbiterA * 11993485572912492297U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10443889548568288532U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4402387036946561017U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 9032964741841833277U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13002706161178447654U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13929727277530310708U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7005639090871200285U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10949073760696935106U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 15405923432006783533U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 17989565878445202495U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 18096057968822208905U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3032155040484574973U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 448597307502544605U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 17462076466907467134U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15471015427013701406U;
            aOrbiterF = RotL64((aOrbiterF * 6113474000571976139U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 6U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 35U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 51U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 19U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22594U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 24104U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 18023U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21016U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19850U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22384U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 18821U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 4U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (((aWandererD + RotL64(aScatter, 43U)) + 5088525177670191619U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 27U)) + 9966456257813932112U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 7707646574027146307U) + aNonceWordM;
            aOrbiterI = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 75480203757681173U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 384659134071835163U) + aNonceWordE;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 12U)) + 3158769775373307778U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 37U)) + 17360830943513941272U) + aNonceWordA;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5317278822721604586U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1371427105215954781U;
            aOrbiterD = RotL64((aOrbiterD * 10956603063464438611U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3162710551223553423U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5332921933853550756U;
            aOrbiterK = RotL64((aOrbiterK * 11709546145149357887U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10572462410297815854U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10234389605554817892U;
            aOrbiterI = RotL64((aOrbiterI * 2130374833440291193U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13421365517991380605U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10186643614984034083U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8554471709467808453U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4742438973260817120U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6081590345899008846U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7069396301823124931U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15360092808493795340U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 12186413069553132646U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 3815981440611914267U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16756221656224451552U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12232880965861373143U;
            aOrbiterH = RotL64((aOrbiterH * 14196910735715726471U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + aNonceWordD);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 20U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31948U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 28142U)) & S_BLOCK1], 26U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 28504U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30108U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24732U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26229U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 32537U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 43U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 50U)) + 16519040829220310189U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 6888002778416941825U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 1310832187746534025U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 13U)) + 5890888009051281674U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aScatter, 5U)) + 5143864838362464857U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 15591534069452660003U) + aNonceWordE;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 43U)) + 1466867671765325096U) + aNonceWordM;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13931443680107902488U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15400747367673245552U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 7011651369456453127U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2836975369734495759U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2370720358274970117U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 4615571902817575375U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3470677184188006133U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7175584278499266723U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10067096593682482345U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6095078817776863055U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2176637999243513070U;
            aOrbiterH = RotL64((aOrbiterH * 12215701810843975501U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 5580391239754903129U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15196125567953871184U;
            aOrbiterK = RotL64((aOrbiterK * 12686361960729564519U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12787014151503209931U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1523153207064063495U;
            aOrbiterG = RotL64((aOrbiterG * 3113907543551927561U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 12973289026485937829U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9087439766232078173U;
            aOrbiterD = RotL64((aOrbiterD * 5817029335999350327U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 12U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterD, 6U)) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 47U)) + aOrbiterH) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 5U);
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

void TwistExpander_Hockey_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFEA0A6AB0331569DULL + 0xAFB7DF19506F5FE7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEC24F8EC750D3931ULL + 0xFDACC07B5A733287ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x807E9700F6A06FDFULL + 0x8D121C7B3CE39D54ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC0FDDD6A342C1E19ULL + 0xA602663FBCC0058AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE15CBB9F8541CD25ULL + 0xF36A494222E33496ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA59293D4C632B981ULL + 0xF191E483F1E22994ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9B32280FEDC1D023ULL + 0xAD02AD18C80F7F5FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE0E0B38EB2168EABULL + 0x99D948D5CA529F9EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE2FBDCFF4F32FE7DULL + 0xD91C37C003E81A43ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCA6F24D231127597ULL + 0xBBFDAFF9C360B83DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCCEAB114497D5D9BULL + 0xD2CBC1B8B733F731ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFADF4006DD274D99ULL + 0x8EB51F9D1ECC87B1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA606D56AFB635087ULL + 0x9110D3AE891BC2FFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA7DEBD5E847E92D7ULL + 0xF85CC49D4F2C5F30ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9F81BFC68AA38179ULL + 0x82BA464705DCD9FDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDEC262A66F2796F5ULL + 0xB8BB1505D03AB8C4ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2880U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((aIndex + 5013U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 1262U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4078U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 2246U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 28U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = ((aWandererF + RotL64(aIngress, 47U)) + 15549114274303128055U) + aNonceWordA;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 16466750056388063241U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 35U)) + 12209449840836787142U) + aNonceWordE;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 11U)) + 14551496099734294336U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 6266576428679808622U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 28U)) + RotL64(aCarry, 51U)) + 16892841575635668152U) + aNonceWordN;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 53U)) + 7375966221423362125U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11926105302821753530U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16219253791550461124U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 2117550758226173419U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7299056065319248160U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15234001484933728439U;
            aOrbiterC = RotL64((aOrbiterC * 8182244796017018911U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6615802589932632120U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5481176858895819247U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3604590158551984877U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17220507586542139380U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14137921473739415340U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 10634645686035907603U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16981960446540932787U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10897565927079518588U;
            aOrbiterH = RotL64((aOrbiterH * 418843936329303571U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 2746889569299593263U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 4894117146736361379U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2656750612042673191U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 18294823016957137777U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 86828501068883383U;
            aOrbiterI = RotL64((aOrbiterI * 11432686669235402365U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 20U);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterI, 5U));
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterG, 60U)) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterJ, 41U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 26U) + aOrbiterC) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 6524U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 8449U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9125U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9627U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7853U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 9646U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 40U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 12669015908335980355U) + aNonceWordF;
            aOrbiterA = (((aWandererF + RotL64(aCross, 35U)) + 5438715179868613192U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aWandererH + RotL64(aScatter, 41U)) + 13172104448184536460U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 13421421503244744803U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 28U)) + 13327113302994856582U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 3U)) + 4671768205922454413U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 5355759962838579929U) + aNonceWordG;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6691720614265406851U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7063906424700911378U;
            aOrbiterH = RotL64((aOrbiterH * 17091734375516280675U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17328616394166672263U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1542940602574207068U;
            aOrbiterA = RotL64((aOrbiterA * 8981679306319627975U), 51U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 7203866278803132454U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 993485696233139264U;
            aOrbiterE = RotL64((aOrbiterE * 11609009908810366447U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15659679028507488331U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 18321361454094675842U;
            aOrbiterD = RotL64((aOrbiterD * 3966860765622641843U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9633319822696783352U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3496559332232402963U;
            aOrbiterG = RotL64((aOrbiterG * 7772060229838162977U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1918349708324205526U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 7701088402761359134U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 9649485438465644795U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6006824348814439686U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 18088375375347012557U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12801082943086128385U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 12U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aNonceWordA) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + aNonceWordH);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 18U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 11U)) + aOrbiterH) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 19U)) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 35U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16042U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 12648U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12051U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13372U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneA[((aIndex + 12717U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 10726035965553989335U) + aNonceWordK;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 51U)) + 967354339530195662U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 10834593005478605624U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 20U)) + RotL64(aCarry, 57U)) + 1012888282838656933U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 57U)) + 15283530351725183253U) + aNonceWordI;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 35U)) + 11724495956731703750U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aPrevious, 29U)) + 4288330117317505776U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10894778070022873473U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15563886747621617467U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 17884709931569040065U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11182488628562891937U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10420140066310588580U;
            aOrbiterI = RotL64((aOrbiterI * 13898299782819948719U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11775138062167543111U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16545391898578161683U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14588306527161321535U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1550144656312299266U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14903504853138279883U;
            aOrbiterB = RotL64((aOrbiterB * 8003033561266164387U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 309935535526750396U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13991265868040011411U;
            aOrbiterC = RotL64((aOrbiterC * 2887531132228588441U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1755976294857114222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2259275858478396846U;
            aOrbiterJ = RotL64((aOrbiterJ * 7416165760067878161U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4838175912944552936U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12307900457200936013U;
            aOrbiterF = RotL64((aOrbiterF * 14719363144850838805U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 34U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 20U) + RotL64(aOrbiterA, 18U)) + aOrbiterB) + aNonceWordD) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20750U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 18962U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 20507U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17500U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 17904U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 4U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 7948891781097675369U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 5U)) + 13928362874228230226U) + aNonceWordB;
            aOrbiterI = ((((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 10776180542602258926U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 5735115172149470447U) + aNonceWordE;
            aOrbiterF = (aWandererG + RotL64(aIngress, 35U)) + 5353591822981766987U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 41U)) + 562301708107268570U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 60U)) + 10467810247578364868U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14541630141152308564U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2350076897065139429U;
            aOrbiterI = RotL64((aOrbiterI * 12222554362482034393U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17519109078651162228U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6061035173339902910U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10021905773432907835U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 15654836633731000065U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13723521735153718904U;
            aOrbiterH = RotL64((aOrbiterH * 14459516479283070563U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2849680038315532197U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17336102435576647923U;
            aOrbiterG = RotL64((aOrbiterG * 10984689101753586739U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7671010488872356142U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11485114338165600777U;
            aOrbiterJ = RotL64((aOrbiterJ * 4162584865462407791U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8759060657343458985U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11009137869375286581U;
            aOrbiterD = RotL64((aOrbiterD * 8741417343929809115U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15792999392743144135U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6180808423175992479U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13681230339693676907U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 48U) + aOrbiterG) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 53U)) + aNonceWordN);
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 4U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterF, 35U)) + aNonceWordK) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 11U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterH) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 26322U)) & S_BLOCK1], 18U) ^ RotL64(aFireLaneB[((aIndex + 21908U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22618U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25886U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 44U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = ((((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 9080426856729228705U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 5U)) + 7851218321653539276U;
            aOrbiterC = ((((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 7023344692919298036U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 9772846154227440734U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 23U)) + 12008298632429608431U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 37U)) + 12201090455849562875U) + aNonceWordA;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 47U)) + 9498721803411445471U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 351203764023093632U) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4966360430644539250U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10138518378274592739U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9194167899071345693U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4922477697284269116U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8444814161720407881U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15742625291642356429U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7528703106518431730U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11530049278751507567U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15279053574704935317U) + aNonceWordK;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2425839793660355555U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 11486964816849830667U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13209849392400008898U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9041500097716231309U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 340661035700748739U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7885423750878814599U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1992993999902904603U;
            aOrbiterD = RotL64((aOrbiterD * 1478629826632201617U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6120758615019314102U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8529621625846992066U;
            aOrbiterA = RotL64((aOrbiterA * 8485991471612862467U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 56U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 11U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 28360U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 28304U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32745U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 32372U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 35U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 29U)) + 16200278595895089008U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 5U)) + 1029614154810465897U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 18U)) + 7129562468705441295U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 14388903902433951274U) + aNonceWordO;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 41U)) + 1013568949315967455U) + aNonceWordE;
            aOrbiterD = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 3128823373497815651U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 14525694606889470589U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14443983602196782887U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12244220415328641190U;
            aOrbiterH = RotL64((aOrbiterH * 15052949098014803181U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10477159225338766614U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 2842870123078131566U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 11522265477555954071U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8621138818955849917U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5038396344400303181U;
            aOrbiterB = RotL64((aOrbiterB * 14636756322207385447U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2768613802894372496U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2027754864051410015U;
            aOrbiterD = RotL64((aOrbiterD * 2461322540050569287U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2848088309172056399U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15017458513904884651U;
            aOrbiterK = RotL64((aOrbiterK * 9926904679902843055U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 9079797279596336139U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15424866642305110811U;
            aOrbiterI = RotL64((aOrbiterI * 12912331089970158845U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13751764050290602740U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7694557131324740282U;
            aOrbiterA = RotL64((aOrbiterA * 14980807690491467023U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 37U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterI, 10U)) + RotL64(aCarry, 51U)) + aNonceWordK) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 20U) + aOrbiterD) + RotL64(aOrbiterF, 47U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Hockey_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9AE3D404C2F99BE1ULL + 0xD6F26B4DCC41B721ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8B29D0318CC67C8DULL + 0x9E5E583EBD76D928ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF11809B17DCCD9B7ULL + 0xF766E047D9F5116BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x81987452ED0019EFULL + 0xEE9060775C2C6219ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDB42FAF55614F5C7ULL + 0xB71282189AE19C8CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8A95BCE25CA9C42FULL + 0xB23614378230873FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB0A84B172E53EB91ULL + 0xFD9F93FD6AAD5DACULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE97B13447BE0049DULL + 0xE3C5452B9D9C23B0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB4FA384480036CFDULL + 0xDD1F2DB889429C79ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x99CE07D3BE95816FULL + 0x80464634C05D2D5AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC730F0415B62FF89ULL + 0x818324ECB447FF9BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9FBD9E7341FDBD5FULL + 0x999743B04078DD81ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9F5B5CAC57FCC7BBULL + 0xEEF341189B015EFDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB8A17AE3BA7893D9ULL + 0x84321A144597026CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD643E782C861AD49ULL + 0xB17113C69085B87DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE231D4DB990A5339ULL + 0xC3B3ABE42C4AB4AFULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6268U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 6708U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1466U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3935U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6842U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2150U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 29U)) + 16160838483846078448U) + aNonceWordE;
            aOrbiterB = ((aWandererF + RotL64(aCross, 36U)) + 15404960896190227946U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 11U)) + 16904160594024977199U) + aNonceWordP;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 53U)) + 17790460246821031802U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 16395168254086971959U;
            aOrbiterC = (aWandererA + RotL64(aCross, 23U)) + 7484373204039901786U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 60U)) + 18026814691322913510U) + aNonceWordO;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 41U)) + 15244817793136966450U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 47U)) + 5795491730356335666U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 3163873518027801504U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 2690791759507349172U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17898067251167087906U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8028010015006604239U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5601629670521300241U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7304739457289910555U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6476837815096530043U;
            aOrbiterC = RotL64((aOrbiterC * 16380545138701113267U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14242499233467960602U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17305645693017634630U;
            aOrbiterF = RotL64((aOrbiterF * 14442976693206929569U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9772864059444171908U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7897200728282156408U;
            aOrbiterK = RotL64((aOrbiterK * 816306719390807411U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4890999319172950996U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8165132649356094963U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 17297706071263690189U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9342923520083533265U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7213639583505088067U;
            aOrbiterJ = RotL64((aOrbiterJ * 1349251979649428909U), 51U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 4079475132684197272U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3350998022472827283U;
            aOrbiterD = RotL64((aOrbiterD * 948841791460066265U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2479140576609216238U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 7703147534931674972U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 11419116495223970801U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9050277787914448469U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13295888852307317371U;
            aOrbiterB = RotL64((aOrbiterB * 3027097172772140975U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15380254190549884741U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17653690414528791774U;
            aOrbiterH = RotL64((aOrbiterH * 15923958179714368315U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6825072759468337036U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16160838483846078448U;
            aOrbiterI = RotL64((aOrbiterI * 11690325563580492415U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 51U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 34U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterH, 43U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 39U)) + aOrbiterF) + aNonceWordD) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 6U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 13U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 23U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 58U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9157U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 16105U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10368U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12191U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11899U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13830U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13317U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 14U)) + 5160910997561396461U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 47U)) + 14920764751058512062U;
            aOrbiterA = (aWandererI + RotL64(aCross, 3U)) + 6080952401749660022U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 39U)) + 17667234330526298627U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 760630072638686756U) + aNonceWordE;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 3504157162816997476U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 9489022223422585882U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 51U)) + 1149898536879968964U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 11U)) + 10492284328940025310U) + aNonceWordG;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 35U)) + 13213275606286399312U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 58U)) + 10557118912847180413U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15618980209023994776U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5268600749854045564U;
            aOrbiterA = RotL64((aOrbiterA * 3849660559223919613U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8011552687609649990U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3148133096349525066U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5245156554959620007U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12032847944237867285U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14999005703490824673U;
            aOrbiterD = RotL64((aOrbiterD * 6631584955208646049U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5426735969392906710U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3593177531650386729U;
            aOrbiterH = RotL64((aOrbiterH * 12997284886192717043U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1701444719333347373U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15928731228196894960U;
            aOrbiterC = RotL64((aOrbiterC * 1919318226904213433U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5960179456039157036U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 5716434224061596483U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3731976564761202801U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2136841536293340279U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12969550408652728526U;
            aOrbiterB = RotL64((aOrbiterB * 7612191387451455137U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3641997570461447114U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4677572491523684525U;
            aOrbiterF = RotL64((aOrbiterF * 2730358077882211651U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2741372094325164504U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4998631511811832690U;
            aOrbiterI = RotL64((aOrbiterI * 10619395395977372695U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6260464862798783617U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 16489087874167346533U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 11278053967185244867U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7043760915859224327U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5160910997561396461U;
            aOrbiterE = RotL64((aOrbiterE * 15260149870590431675U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 18U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 6U)) + aOrbiterK) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 51U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 29U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 27U) + RotL64(aOrbiterG, 37U)) + aOrbiterB) + aNonceWordP) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 57U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 10U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterD, 27U));
            aWandererA = aWandererA + ((RotL64(aCross, 48U) + aOrbiterF) + RotL64(aOrbiterH, 29U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 39U)) + aOrbiterI) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 56U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18263U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 22924U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 19600U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20304U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16624U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18441U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 20706U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 41U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (aWandererJ + RotL64(aIngress, 14U)) + 5480870806135400132U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 47U)) + 8034874599430768743U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 43U)) + 4006919843736863767U) + aNonceWordO;
            aOrbiterH = ((aWandererE + RotL64(aCross, 23U)) + 2988069748674633718U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 3U)) + 12347295651973135786U) + aNonceWordN;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 14152683894431568192U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 15765143815254196598U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 56U)) + RotL64(aCarry, 3U)) + 10473067082331244233U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 11U)) + 1089466925383677249U;
            aOrbiterK = (aWandererC + RotL64(aCross, 35U)) + 13215039929873682230U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 21U)) + 3957997712247961479U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10023907397941685546U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14593012591254614353U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17111300092082154687U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13353797968154036726U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9259966668512102858U;
            aOrbiterF = RotL64((aOrbiterF * 8326732574268308221U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10757861831070349321U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10530223113483866178U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11269177745265396583U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7554320926405521865U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 6978052067277966996U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 18020134738536217801U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1053695861967171420U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15980734683539854451U;
            aOrbiterJ = RotL64((aOrbiterJ * 3208466640010555357U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17041258393808061556U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12846551858751995530U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 9303891433380993639U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14617434286683320666U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3999309956180741302U;
            aOrbiterC = RotL64((aOrbiterC * 15037707937050015205U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13452627760403094126U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2633241575260427158U;
            aOrbiterI = RotL64((aOrbiterI * 2638570213290747581U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15575035993965639421U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7829837426112185905U;
            aOrbiterB = RotL64((aOrbiterB * 17059814556114938275U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12565466096663867876U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4845209979900289818U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 14990494169374347835U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13472490162287247012U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5480870806135400132U;
            aOrbiterD = RotL64((aOrbiterD * 9150331893094034245U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 48U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 39U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterK, 21U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 26U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterK, 43U)) + aNonceWordC);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 60U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25904U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 27546U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 26399U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32386U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25308U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25050U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32298U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 35U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 24U)) + 9471546960258473684U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 53U)) + 18050235435948942244U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 43U)) + 3005107102671544641U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 17898396434573801850U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 19U)) + 15071602525497771648U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 3U)) + 5780119462702672108U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 13301326224151025687U;
            aOrbiterJ = ((((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 37U)) + 18129323022260575961U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 22U)) + 1199228670638790709U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 29U)) + 1839199978088021020U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 13U)) + 4999517042246790165U) + aNonceWordM;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8788607633376516299U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15143903839930468749U;
            aOrbiterK = RotL64((aOrbiterK * 12735914889325422675U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16674732686428431869U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15908873150953195581U;
            aOrbiterI = RotL64((aOrbiterI * 18049755517524334107U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11204775359756474667U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2525984309543939465U;
            aOrbiterF = RotL64((aOrbiterF * 3988529812023791571U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4566345170476825512U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14876612901557406267U;
            aOrbiterB = RotL64((aOrbiterB * 9047956948845135339U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14926290877038883931U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12710203178186614846U;
            aOrbiterA = RotL64((aOrbiterA * 14841163494801662515U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7315094513967387996U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11050116830482816766U;
            aOrbiterC = RotL64((aOrbiterC * 3702999495721152019U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4505368486032503953U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17905748055257551092U;
            aOrbiterH = RotL64((aOrbiterH * 14775870175093453197U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5728886950801376350U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17998141690182325170U;
            aOrbiterE = RotL64((aOrbiterE * 16008599930125391379U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4325978018819134558U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13526905108565989379U;
            aOrbiterJ = RotL64((aOrbiterJ * 14121321495714166291U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10597169665474269506U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7500801022830471869U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3702717219742363777U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17063616328548689935U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 9471546960258473684U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 3029748230803396737U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 29U)) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 30U) + aOrbiterA) + RotL64(aOrbiterI, 44U)) + aNonceWordJ);
            aWandererC = aWandererC + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterH) + aNonceWordH) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterE, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterF, 57U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 19U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterE, 12U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 23U)) + aOrbiterA) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 41U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Hockey_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xADB5D7FCC695D7C3ULL + 0xAB8B0F9DD9EE99F6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA023F828895808B3ULL + 0xC13ED4609E861160ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE631DB9AB5B9F6D5ULL + 0xCDA3D7C2660C380EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF160AD75EF66E17DULL + 0xCD22076B26AE9E94ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFD19696D27F2B651ULL + 0xA496CFD951C7BA54ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x809AD44767932ED9ULL + 0xA0EB5533B5B30CC5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x978DF20CAE4ED673ULL + 0x831591A485FEA3A6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x897F567D85D9A61BULL + 0x85E181C572322B79ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8D0172FF64BECE49ULL + 0xD831B42B145F5107ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x96035CCB663BE8FBULL + 0xC22E36A1E80E8404ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD3D66E6B50B0883BULL + 0xE25BE0B0BE62E093ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB039CEB7EC7AE853ULL + 0xABEA52E752598912ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDA42BDE676267CC9ULL + 0xAD8186826467351BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCCE7E36FEA5309ADULL + 0xDFE67BF9164F73E0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF528073BE6E2E9CBULL + 0xE5EC325657431B63ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAACA0B0476CDC8E1ULL + 0x84CA3BF750512FA6ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3054U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((aIndex + 2561U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3864U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7759U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5007U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5276U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 35U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 58U)) + 12029393034357490020U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 11U)) + 4526754731580694987U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 17060419646421271853U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 35U)) + 4128488893837059683U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 40U)) + 12706894827547160110U) + aNonceWordP;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 12506324593645825056U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 12581344490649250025U) + aNonceWordA;
            aOrbiterI = ((aWandererH + RotL64(aCross, 53U)) + 14357032418199130132U) + aNonceWordH;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 19U)) + 15341977701796331249U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7086602307544733241U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12398300065276832486U;
            aOrbiterC = RotL64((aOrbiterC * 18157408831225635333U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2499745046076601988U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7249361592814001829U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 14597139848072319685U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3254456186337366437U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3472973415969046680U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14583566953969168353U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7905718972111691591U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15941413652144021522U;
            aOrbiterI = RotL64((aOrbiterI * 3473779492962783565U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10583964125960308762U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13659925272340853715U;
            aOrbiterB = RotL64((aOrbiterB * 16708294803316630743U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9487054537489454887U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13287757570441887517U;
            aOrbiterE = RotL64((aOrbiterE * 17351439045329892107U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15279245465808571942U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12424999114621745879U;
            aOrbiterG = RotL64((aOrbiterG * 2274918760256527137U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13915392738892970475U) + aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13797668053788805126U;
            aOrbiterK = RotL64((aOrbiterK * 13752161103680525317U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14344766585550401077U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 13727554194373146727U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17164450431362670223U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 34U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 24U) + RotL64(aOrbiterK, 43U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterC, 12U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 18U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 53U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9177U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 10799U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9286U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15810U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11529U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12969U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10843U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 43U)) + (RotL64(aIngress, 10U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 11U)) + 826930775230515406U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 3U)) + 5137814617363250861U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 51U)) + 14761561947426681616U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 12773023438753662590U) + aNonceWordG;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 7331345852207096322U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 41U)) + 3899381212671247460U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 10072004147620068599U) + aNonceWordF;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 46U)) + 3424585039401897560U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 23U)) + 8246760141625966321U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3655992860610853290U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11154618022505863898U;
            aOrbiterD = RotL64((aOrbiterD * 4791494171286145231U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15629361991059709973U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 10842068502278489664U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 17223002513104960799U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5571312349016336686U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 589313823745748879U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 1356685926549786027U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13633457935771935260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12684602052812183096U;
            aOrbiterB = RotL64((aOrbiterB * 4689206269919806711U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5711307583717354204U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7181854170553728211U;
            aOrbiterF = RotL64((aOrbiterF * 9835601115561325911U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1884620014396115821U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1471516373272364262U;
            aOrbiterE = RotL64((aOrbiterE * 5126319375714848029U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 742739371092077733U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8075893317715227838U;
            aOrbiterJ = RotL64((aOrbiterJ * 11208274111743259795U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8179547722249281263U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 15305282712174742323U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7951986906055462929U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1430543231751281079U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14585341768267283387U;
            aOrbiterG = RotL64((aOrbiterG * 313213844964269133U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 4U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterA, 34U));
            aWandererA = aWandererA + (((RotL64(aCross, 24U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 3U)) + aOrbiterB) + aNonceWordC) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 60U) + RotL64(aOrbiterG, 44U)) + aOrbiterA) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + aNonceWordL);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterF, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 20U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19370U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 24301U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 23228U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19985U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16734U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20000U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 21579U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 24U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = ((aWandererI + RotL64(aScatter, 22U)) + RotL64(aCarry, 37U)) + 5041131702736607991U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 41U)) + 9295010428212681446U;
            aOrbiterE = (aWandererF + RotL64(aCross, 27U)) + 6235875895358766017U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 3U)) + 2622227802531866918U) + aNonceWordM;
            aOrbiterA = (aWandererG + RotL64(aCross, 48U)) + 3888894734834524972U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 35U)) + 241682012014701753U) + aNonceWordN;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 57U)) + 15758000422451568079U) + aNonceWordE;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 2061944548396976912U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 8177144990755754531U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 554978075608818497U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 250408260560714933U;
            aOrbiterE = RotL64((aOrbiterE * 1295379390497107727U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8700027645880997552U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10026130047465480902U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12417270861933696623U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9785843014096326696U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9998582683258411251U;
            aOrbiterI = RotL64((aOrbiterI * 7197956237569462269U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13817734599383455151U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6647207154174092691U;
            aOrbiterK = RotL64((aOrbiterK * 1578528131687283531U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4957715980509035719U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4994885315786213197U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5676683798126497011U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5072908311783966503U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5535039946192891515U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 2989412783482309753U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6594577050344146271U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8750154123258714856U;
            aOrbiterD = RotL64((aOrbiterD * 6942158167127532003U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3514769314840874873U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8626045200273524281U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 4315441782689789689U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8524870284841706517U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1841819423572964209U;
            aOrbiterA = RotL64((aOrbiterA * 9802481758007234681U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 10U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterD, 51U)) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterH, 30U)) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 5U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aCross, 10U) + RotL64(aOrbiterE, 47U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + aNonceWordD);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterF, 23U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 56U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 22U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31949U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 31935U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 32010U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((aIndex + 31775U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26869U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29211U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31225U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 20U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 13U)) + 16451272412693907816U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 30U)) + 10099485419723255462U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 3U)) + 17668900099534923192U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 57U)) + 5497093724143181753U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 19U)) + 10354044773550071706U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 12728258851198019099U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 4144050505314242618U) + aNonceWordA;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 14133805325480076530U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 50U)) + 308863673210602899U) + aNonceWordL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11741180130160569753U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12926863156769180448U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 9726030996091054939U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 211920854786494259U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13234608842479411078U;
            aOrbiterG = RotL64((aOrbiterG * 2556747209733759467U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9164711974854618892U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6667377062281954219U;
            aOrbiterI = RotL64((aOrbiterI * 2603737166987437649U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4559040002406721850U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1749875480850675109U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15822640067349481089U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9555365165561936366U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 18289733999504213574U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14156217554673229429U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8727162691639622461U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 291406782452963706U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 8413500075082350243U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8294911802626492257U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15853578397277298548U;
            aOrbiterC = RotL64((aOrbiterC * 13256191781365357747U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11535146194939658681U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2177540476748375661U;
            aOrbiterF = RotL64((aOrbiterF * 15791341922007841029U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2705306323728084136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17617871830709148043U;
            aOrbiterE = RotL64((aOrbiterE * 3449981219502809255U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 22U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterG, 28U));
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 22U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 58U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterI, 41U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ) + aNonceWordJ);
            aWandererB = aWandererB + ((((RotL64(aScatter, 18U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 21U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Hockey_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD4BC173178B4D06BULL + 0xDA80FD2B6B2BA92EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBD710C39F8952EC7ULL + 0x86089648D94A084AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD0CEB7755E716203ULL + 0xD4650AD6599BAA48ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8A52D7390CC3B6C7ULL + 0xF9DAF3F34AF0ADC9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9327853E30E391F3ULL + 0xE5BA16B5F6CBC4DAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC1D94B678BF8997DULL + 0xFB9250E7F6F654D3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA73560E1DFDD8DF5ULL + 0x8F57A26CF4EF8E65ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA31592BCC7881C31ULL + 0xB8376323F6DFEF5CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAF3C9A26C2D5DE21ULL + 0xD84C6D3A6A2D4F22ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD0400CBC59D2A825ULL + 0xB3BDF7F61AEE65D0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF2931357656FBD8DULL + 0xA4B6965630A2737BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA8AA66D4CC146C09ULL + 0xA442E1179BA7741AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFE11DDE88D51F91DULL + 0xF780DBAF2050499FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA1EF6E5909C77E43ULL + 0x9DE239B78A7B54AAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBD0353D067D287B1ULL + 0xF89259ABB048608DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE79823D4628FFECBULL + 0xD97EE03116100B9EULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4997U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 6259U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7641U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6609U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1716U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2064U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 11U)) + 3621877681473089725U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 4451752751536414717U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 22U)) + RotL64(aCarry, 41U)) + 11371625415377772117U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 6046792758881150619U;
            aOrbiterG = (aWandererI + RotL64(aCross, 29U)) + 8213166120394461682U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 5U)) + 4343156661140422645U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 51U)) + 11105271483234947905U) + aNonceWordD;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 348904609985341372U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12924652822526858767U;
            aOrbiterD = RotL64((aOrbiterD * 2801892489296408735U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7461211697358520287U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16551553555297890558U;
            aOrbiterG = RotL64((aOrbiterG * 16432952324635746293U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11908056404140782995U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9147367258259948715U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10777628928376261667U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8876461054692728610U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 10546855952702525404U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10071104785895309677U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4748636139110443794U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 783046909529525098U;
            aOrbiterH = RotL64((aOrbiterH * 8969157702460927215U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16683965945838696665U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 12385412690177109575U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 10795062772707143187U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8210546822184469023U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13146493623236979963U;
            aOrbiterI = RotL64((aOrbiterI * 13199947810161148155U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 48U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + aNonceWordN);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordO) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aIngress, 42U) + RotL64(aOrbiterD, 14U)) + aOrbiterI) + aNonceWordH);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15030U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 9388U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 12440U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14815U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9434U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8702U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9311U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 3U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 8020711767807230555U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 40U)) + 15368693777246341570U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 51U)) + 5117523734225562401U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 13155269151097507808U) + aNonceWordP;
            aOrbiterH = ((((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 9879303753623578272U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 11U)) + 1165799257173794826U) + aNonceWordK;
            aOrbiterC = (aWandererD + RotL64(aCross, 57U)) + 930641942062732091U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11330571332221123153U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2862963158282518899U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13782195862525974199U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6019186399361476659U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 1924419843785161958U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 9485557122500346869U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12618629043591380461U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9334176504266512405U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18239109235362925739U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16829692481030013551U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5604784396927022709U;
            aOrbiterF = RotL64((aOrbiterF * 2833893610883508353U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16124030106598549644U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16571659812830230677U;
            aOrbiterC = RotL64((aOrbiterC * 4668250364992383549U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15171089673591843703U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2826755560293849328U;
            aOrbiterA = RotL64((aOrbiterA * 9397017963457655287U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9976785768283589291U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11845100564714691809U;
            aOrbiterH = RotL64((aOrbiterH * 4935139932585319251U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterE, 20U)) + aNonceWordE);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + aNonceWordB) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterK, 29U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21047U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 19574U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 24482U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 19297U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21024U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18092U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 18840U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 18U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 3561491146322798260U) + aNonceWordJ;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 41U)) + 7075025056181885339U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 9230910887904171613U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 3U)) + 4119781172609908917U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 27U)) + 17155609083870983149U) + aNonceWordD;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 21U)) + 2423018561430181695U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 51U)) + 12957280305617615744U) + aNonceWordC;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 2461704174772065813U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7907123257849391997U;
            aOrbiterE = RotL64((aOrbiterE * 9416171962847312179U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7257868138318960007U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16425903703085702285U;
            aOrbiterJ = RotL64((aOrbiterJ * 7996935869077231999U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2990822664594079467U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5654819006718953817U;
            aOrbiterH = RotL64((aOrbiterH * 4465096036756887801U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12183676471235678779U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15026286960542123922U;
            aOrbiterD = RotL64((aOrbiterD * 17199049329995315279U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12169080607071830522U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2906296852254787499U;
            aOrbiterG = RotL64((aOrbiterG * 6754514406846040163U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3029858695410344584U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14406410317495954566U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9663780721657983421U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11048818178401163861U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13622063920319445043U;
            aOrbiterK = RotL64((aOrbiterK * 2516025554421589857U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 14U) + aOrbiterE) + RotL64(aOrbiterD, 27U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterA, 53U)) + aNonceWordG) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 11U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 21U)) + aOrbiterH) + aNonceWordF) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterK, 34U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 3U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27182U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 32314U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 32038U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 32113U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31995U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29905U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30728U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 6U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 16922357079016918108U;
            aOrbiterI = (aWandererI + RotL64(aCross, 3U)) + 11771749797137599131U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 27U)) + 4635668433708036077U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((((aWandererA + RotL64(aIngress, 20U)) + RotL64(aCarry, 39U)) + 15827952719230577008U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 57U)) + 1495675306110023086U) + aNonceWordD;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 13U)) + 7294835466949728365U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 179122461212041978U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 545981421632236251U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15338259639814630535U;
            aOrbiterB = RotL64((aOrbiterB * 14895421566334357871U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12924313840290895215U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17846785921286020610U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18309347016029917133U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5721472794107057875U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16359630793856870319U;
            aOrbiterC = RotL64((aOrbiterC * 14186771515526698907U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10614102110239037308U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16421992251278236531U;
            aOrbiterF = RotL64((aOrbiterF * 2561232904676068089U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8668149834861244963U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12699331834360948734U;
            aOrbiterI = RotL64((aOrbiterI * 2249360824172616357U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4470693178142950471U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 526000656022724741U;
            aOrbiterE = RotL64((aOrbiterE * 16688501462334673493U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6880246132270094141U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 7126466778855297013U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 5692237926830293205U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 10U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + aNonceWordE);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterC, 46U)) + RotL64(aCarry, 19U)) + aNonceWordH) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + aNonceWordB);
            aWandererG = aWandererG + ((((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 28U) + aOrbiterF) + RotL64(aOrbiterK, 29U)) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 53U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 19U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Hockey_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC82605DAACAC48F3ULL + 0xB90619B883C0605EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA8EC01EFC67E73C9ULL + 0x92963527FC332B9EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDDA99CC1C0D6BA4DULL + 0xCC08926FA3D19D52ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9C407B3E6B98EED3ULL + 0x8C716BA408B41B51ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDE9270447F6203DBULL + 0xE2DEC349F32DF522ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA535DCE63921F175ULL + 0xA20AAA91D808CF3AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC1507C54D064FB0FULL + 0xDB154ED00521B82EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEF79B34C66A06F3FULL + 0xA53700A3D263CB6EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x86E6FE44C511D415ULL + 0xAD48E9952E3C1222ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCD2D01F66B44D587ULL + 0xE8A2B08062BA8DE9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA180B71D72EDF7A7ULL + 0xC1CD469ED7D80578ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF549087CEE042EA7ULL + 0xD4E531DFB97AA0D2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC5782DE96CC5FD11ULL + 0xBF65BA69404D142BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x94E61F65E9C14A07ULL + 0xD8FE8E72EEA29511ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE552A8B97B30338FULL + 0xB2325CDE59B21080ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF5A3A776E3B64369ULL + 0x84445C4D4FF39ACEULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1909U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 598U)) & W_KEY1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2369U)) & W_KEY1], 18U) ^ RotL64(mSource[((aIndex + 2241U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 1888427424966603593U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 5436761445660415091U) + aNonceWordA;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 53U)) + 17322876217962143270U) + aNonceWordJ;
            aOrbiterK = (((aWandererG + RotL64(aCross, 11U)) + 9728299982740564979U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 27U)) + 301720335271716921U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 39U)) + 8069685428854814396U) + aPhaseEOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 1973715500949100991U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 87666408799854155U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12195436904339035245U;
            aOrbiterI = RotL64((aOrbiterI * 15427739165893738105U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4578742069143400295U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7828776048774876484U;
            aOrbiterD = RotL64((aOrbiterD * 4047964518501081039U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17203146364542781833U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16913369550858890466U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 13534417587921978507U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9632761514552265402U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9106637671877341286U;
            aOrbiterG = RotL64((aOrbiterG * 9073709119482640391U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15423680889126750876U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6087310684583331882U;
            aOrbiterE = RotL64((aOrbiterE * 8964465129744898619U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5420955876411796789U) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14166807419730848032U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 442659738632823751U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8118312450347026824U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4253043584558403086U;
            aOrbiterH = RotL64((aOrbiterH * 5651748455190536467U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 48U) + aOrbiterH) + RotL64(aOrbiterK, 20U)) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 47U)) + aOrbiterD) + aNonceWordF);
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 53U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 27U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3796U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3063U)) & W_KEY1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5161U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 5196U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCross, 42U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (aWandererB + RotL64(aScatter, 3U)) + 6654158889644956636U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 51U)) + 9045779659363991870U) + aNonceWordG;
            aOrbiterG = (aWandererF + RotL64(aCross, 41U)) + 3888897662136993491U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 6882016842864459345U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 15601891715956172291U) + aPhaseEOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 58U)) + 5176811598629335350U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 12519945150889074325U) + aNonceWordC;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4552583214397603278U) + aNonceWordO;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 14225482701804864688U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 8526052833180466359U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5485298070606280363U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11237713257388094289U;
            aOrbiterJ = RotL64((aOrbiterJ * 11032429223099413011U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 14340345895626142788U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16275167270553643347U;
            aOrbiterF = RotL64((aOrbiterF * 7308578867128951199U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14041860597556520250U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1436068974197066343U;
            aOrbiterB = RotL64((aOrbiterB * 3938460345031496843U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11483155566419547004U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4608508534724289325U;
            aOrbiterK = RotL64((aOrbiterK * 13461385011638899485U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2389196334288832895U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4062682330273866602U;
            aOrbiterA = RotL64((aOrbiterA * 8787682133271101901U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5655656046585592034U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 7977947821249746880U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10082104644185964787U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 41U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterK, 28U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 21U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB) + aNonceWordK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 35U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 22U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 5602U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 6224U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7723U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5742U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8000U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 6361545377408870615U;
            aOrbiterH = ((((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 2967245486744774933U) + aPhaseEOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aWandererH + RotL64(aCross, 46U)) + 3836634268482850139U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 57U)) + 7691642115360086297U) + aPhaseEOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aWandererK + RotL64(aCross, 39U)) + 16479280384178279281U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 2901468732552539249U) + aNonceWordJ;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 11U)) + 2600353867755647475U) + aNonceWordB;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5666596904781510956U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16108791609267427553U;
            aOrbiterG = RotL64((aOrbiterG * 8904649663479834199U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 8389926875737312112U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1689501721163024426U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6517194895779049139U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11721701506949917719U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3963842745030140473U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6692473494944919373U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8510538243472109368U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 18281865214102080387U;
            aOrbiterJ = RotL64((aOrbiterJ * 1351546966368884609U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 2259725140963665123U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11652011949557979650U;
            aOrbiterC = RotL64((aOrbiterC * 11260100762113295037U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1116085424226174473U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4725260319270802912U;
            aOrbiterI = RotL64((aOrbiterI * 4697109059565450269U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7348945429843437036U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1249234309180653260U;
            aOrbiterK = RotL64((aOrbiterK * 3136745255820405881U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 42U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + aNonceWordC);
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 21U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 27U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 18U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + aNonceWordF);
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 52U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9036U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 10011U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 9131U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8273U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9460U)) & W_KEY1], 43U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10272U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 43U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 27U)) + 15726877954695761686U) + aNonceWordA;
            aOrbiterB = (aWandererI + RotL64(aIngress, 47U)) + 14187652171881943587U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 8420423151313882782U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 57U)) + 14942322692433259283U) + aPhaseFOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererC + RotL64(aCross, 27U)) + 7272331475919796255U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 19U)) + 154504365041805840U) + aNonceWordI;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 17475491222554948786U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5759181483165339605U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5993060214499322845U;
            aOrbiterF = RotL64((aOrbiterF * 10799489831896153301U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10901786237875941844U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17135786595614068473U;
            aOrbiterG = RotL64((aOrbiterG * 15923538730142047043U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 5208202073886811165U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6821452921018900631U;
            aOrbiterC = RotL64((aOrbiterC * 13119330055184115669U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13348064837402206969U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8967943922403445136U;
            aOrbiterB = RotL64((aOrbiterB * 300168481725373093U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8130283784171430891U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6351113882502502876U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15960622823993072903U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6894708729226455769U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12065058511247133944U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5432601727436935831U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17138279326229372741U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12987698199066890628U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 12665716655177320977U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 42U)) + aOrbiterF) + aNonceWordK);
            aWandererC = aWandererC + ((((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterF, 57U));
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 13U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11474U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 13438U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 10925U)) & W_KEY1], 39U) ^ RotL64(mSource[((aIndex + 11572U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11751U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12584U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12151U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 6771552164800695068U) + aNonceWordH;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 12131763371571322040U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 13U)) + 3326182381395522013U) + aNonceWordG;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 36U)) + RotL64(aCarry, 53U)) + 12288775097697156383U) + aNonceWordL;
            aOrbiterC = ((aWandererK + RotL64(aCross, 51U)) + 5195948373449796741U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 57U)) + 14404044002250137144U) + aNonceWordN;
            aOrbiterD = (aWandererF + RotL64(aIngress, 21U)) + 11142382920035825426U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 2967149520256475485U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1470907369577818097U;
            aOrbiterI = RotL64((aOrbiterI * 9398653295177725883U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9231668148004163910U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13078929163913892386U;
            aOrbiterC = RotL64((aOrbiterC * 7509829068700523627U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9485274692075657877U) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12216951187543631673U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 6571066246507310805U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6933334652581744234U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17260276102423580920U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7796879893790990605U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 387767848169714392U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8597538259308082638U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4888054690557707241U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7996708724489146033U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15357384191688149939U;
            aOrbiterD = RotL64((aOrbiterD * 9827691726832491373U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17739222908739454637U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1614322333281471170U;
            aOrbiterH = RotL64((aOrbiterH * 7063116837752240891U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterE, 29U)) + aNonceWordA);
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 13U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 36U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + aNonceWordC) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 23U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 14809U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15188U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15155U)) & W_KEY1], 60U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13845U)) & W_KEY1], 23U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14630U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16210U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13804U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 38U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 19U)) + 8020711767807230555U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 15368693777246341570U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 27U)) + 5117523734225562401U) + aNonceWordJ;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 13155269151097507808U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 6U)) + 9879303753623578272U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 1165799257173794826U;
            aOrbiterB = (aWandererD + RotL64(aCross, 51U)) + 930641942062732091U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11330571332221123153U) + aNonceWordN;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2862963158282518899U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13782195862525974199U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 6019186399361476659U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1924419843785161958U;
            aOrbiterE = RotL64((aOrbiterE * 9485557122500346869U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12618629043591380461U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9334176504266512405U;
            aOrbiterA = RotL64((aOrbiterA * 18239109235362925739U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16829692481030013551U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5604784396927022709U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 2833893610883508353U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 16124030106598549644U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16571659812830230677U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 4668250364992383549U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15171089673591843703U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2826755560293849328U;
            aOrbiterJ = RotL64((aOrbiterJ * 9397017963457655287U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9976785768283589291U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11845100564714691809U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4935139932585319251U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 36U) + RotL64(aOrbiterA, 43U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterF, 11U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterB, 29U)) + aNonceWordO);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 50U)) + RotL64(aCarry, 57U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18744U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 18197U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(mSource[((aIndex + 16938U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneA[((aIndex + 16938U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17632U)) & W_KEY1], 21U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17018U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18925U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = (((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 4773124477323378268U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 42U)) + 16848723289435796005U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 13846642134917107058U) + aNonceWordI;
            aOrbiterB = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 6472057872482789939U) + aNonceWordO;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 3U)) + 2747019500690707226U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 51U)) + 9003965289739733880U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 11U)) + 3013390651936257377U) + aPhaseGOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 3331004709895625067U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15355010435553517129U;
            aOrbiterA = RotL64((aOrbiterA * 8322759117004876831U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7709870658004280052U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13568728443963926564U;
            aOrbiterF = RotL64((aOrbiterF * 6736090830113688981U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12409548853419307131U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 969183352023661537U;
            aOrbiterK = RotL64((aOrbiterK * 5549220554838837145U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15370309834426476775U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3896803894396631184U;
            aOrbiterD = RotL64((aOrbiterD * 11018830202891911603U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10848873633291935766U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12885336509190543440U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 1487357252619221365U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 8252290890093788010U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9201553615601641350U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 420321130559162915U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14014209645503188472U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 4015071464301844550U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17444195018239904971U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterA, 12U));
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 5U)) + aOrbiterK) + aNonceWordK) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 41U)) + aOrbiterA) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 38U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19850U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 20376U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 20835U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19994U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20739U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20404U)) & W_KEY1], 43U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19955U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19734U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 20U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 4068921616130916949U) + aPhaseGOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 12077715273915151726U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 58U)) + 16047546802670596833U;
            aOrbiterI = ((((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 9690277462716999763U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererH + RotL64(aIngress, 5U)) + 14484814700447992628U;
            aOrbiterB = (aWandererC + RotL64(aCross, 51U)) + 17089267243053958210U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 29U)) + 9138746214446211147U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10181001536979097045U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6657458969093373191U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4311019792293202747U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 7515983477876590988U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3039935555863947600U;
            aOrbiterE = RotL64((aOrbiterE * 12511160550780270119U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16209389224740851136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 725253312098083182U;
            aOrbiterB = RotL64((aOrbiterB * 17535989492095522597U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13307041115748941383U) + aNonceWordK;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7159572004825238263U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4855009895002398449U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12027236743251643820U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8717826175991286553U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 1175614802543098451U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4769096034227659937U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11201226563992939616U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 15595355978388159931U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17295978531215563256U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11850923890626719833U;
            aOrbiterG = RotL64((aOrbiterG * 3854851059897397075U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 37U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aIngress, 18U) + RotL64(aOrbiterI, 3U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 30U)) + aOrbiterJ) + aNonceWordI) + aPhaseGWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + aPhaseGWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 36U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22690U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 23836U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23104U)) & W_KEY1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22160U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 21897U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22969U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22630U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((aIndex + 23759U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 19U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 9888431329297626900U) + aNonceWordH;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 2937735167534624403U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 17626022970343789617U) + aNonceWordD;
            aOrbiterA = (aWandererF + RotL64(aIngress, 19U)) + 5665660859333693743U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 4U)) + 1060537034632076669U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererK + RotL64(aCross, 27U)) + 743777763907175800U) + aPhaseGOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 43U)) + 5744905970181808845U) + aNonceWordP;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3545351394494002180U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4877547088414106007U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5416792889338547109U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11669378338379598445U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2961072441706158212U;
            aOrbiterK = RotL64((aOrbiterK * 2677988507090705371U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13984945589234919765U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1433097875470903205U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 451996840039906781U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 716415411025451152U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8542286150858297810U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9139015340823332449U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12932391786479661299U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14005503313299177013U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 802663466907819743U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9382792812676318046U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5138554251079724724U;
            aOrbiterC = RotL64((aOrbiterC * 6386016499265056247U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8522380066269546172U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11825536408101906458U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 17042837108792016849U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 4U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + aNonceWordM) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterF, 53U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterK, 35U)) + aNonceWordI);
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 10U)) + aNonceWordB);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 12U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordK) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24645U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 27019U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26630U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 26908U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26530U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25158U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26242U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25134U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 38U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = ((aWandererI + RotL64(aScatter, 43U)) + 9855743441035905047U) + aNonceWordC;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 27U)) + 8426286937143990276U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 11U)) + 7146752367170267002U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 20U)) + 12947210066678101726U) + aNonceWordG;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 15902163559925328965U;
            aOrbiterC = ((((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 8506649889346449469U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 8226286036430263052U) + aNonceWordK;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2703047093452420216U) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6769351326360139560U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 5318104980014706265U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9857025533281333281U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 238297452132277585U;
            aOrbiterB = RotL64((aOrbiterB * 12974709749856065985U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7203572312072908931U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12497027346166575632U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1703586436725662307U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 473851890609048879U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1664484956453886047U;
            aOrbiterG = RotL64((aOrbiterG * 8566500756326590209U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4635095143004754116U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17695676150967345793U;
            aOrbiterC = RotL64((aOrbiterC * 5780416541584439301U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15628965269863402796U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9190117464399730235U;
            aOrbiterD = RotL64((aOrbiterD * 5586437438425999715U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17835918238346011086U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4398005402429282682U;
            aOrbiterK = RotL64((aOrbiterK * 14828737209913317463U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 46U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterK, 53U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterD, 27U)) + aNonceWordP) + aPhaseHWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aScatter, 44U) + aOrbiterG) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 11U)) + aNonceWordH) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28330U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 28234U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27325U)) & W_KEY1], 30U) ^ RotL64(aWorkLaneC[((aIndex + 28881U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29264U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27618U)) & S_BLOCK1], 26U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28074U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 27324U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 27U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 14U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (aWandererJ + RotL64(aIngress, 29U)) + 13499155707765393469U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 3740324981823726185U) + aNonceWordE;
            aOrbiterA = (((aWandererI + RotL64(aCross, 14U)) + RotL64(aCarry, 53U)) + 5470765363949735652U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 3446436171274452326U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 47U)) + 1778929412631211933U) + aNonceWordF;
            aOrbiterC = (aWandererK + RotL64(aIngress, 53U)) + 14666308799855220954U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 41U)) + 4548410236791175055U) + aPhaseHOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5829739767694190372U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14319231414903675748U;
            aOrbiterA = RotL64((aOrbiterA * 4966501102515775601U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1513851750246111405U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1685620217748986019U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9286548037413609445U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 16284162182006054402U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6271539598462003309U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 13923286694131331137U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12669312437565969473U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11894755313393001665U;
            aOrbiterE = RotL64((aOrbiterE * 12556759675372354075U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6315983824634946566U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 17106616474222892782U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 167205520766791073U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13350266700180455548U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4608846311203767162U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2504857468837437365U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14195866746143604365U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7917977448256795054U;
            aOrbiterB = RotL64((aOrbiterB * 5927771378657284557U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 28U) + RotL64(aOrbiterB, 37U)) + aOrbiterK) + aNonceWordC) + aPhaseHWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterK, 51U)) + aNonceWordH) + aPhaseHWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterA) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterG, 29U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32519U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32070U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30887U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30697U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31491U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 30637U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 966899917801652720U) + aNonceWordI;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 10996327672320748649U) + aNonceWordE;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 19U)) + 4188171566846621107U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 41U)) + 5886209243097387959U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 35U)) + 14940428957136728111U) + aPhaseHOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 28U)) + 179187285531914832U;
            aOrbiterF = ((((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 6685351948936817752U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1894506461704029700U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4182760368636977082U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 972988091869133921U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12523318028514940790U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5059306166973366892U;
            aOrbiterD = RotL64((aOrbiterD * 2857409765717296483U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 5890872367917643851U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17747338389865221534U;
            aOrbiterC = RotL64((aOrbiterC * 5306740664798049267U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13906227834259884100U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7152105382899756368U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 6772157117358310485U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17868101884759619240U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11758843266314148347U;
            aOrbiterA = RotL64((aOrbiterA * 5919135169337501485U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13950566197090324859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17278105609930477854U;
            aOrbiterI = RotL64((aOrbiterI * 11431842718945107359U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9556785965646738355U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 841298436857932987U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15077843186688841797U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            aWandererC = aWandererC + (((((RotL64(aCross, 53U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordA) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 41U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterG, 58U)) + aNonceWordH) + aPhaseHWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 51U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 4U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Hockey_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBFA541F2887411EBULL + 0xF3F3341495E13CB4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA782010E319880EBULL + 0xDFFDAE6C9B88348BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAB9DB1CED2456059ULL + 0x8CFFC2F1E635972AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x811E7EB187403DEDULL + 0xCDB627CBE52A3963ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDF44B2741FA4476BULL + 0xFDA55AED6850C619ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE4A6E0715BAB60D7ULL + 0xDCA8BEC5830DD39EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA3710DB21F2E386DULL + 0xEFCB14F95629C33AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCCCB6F44A3C6FD17ULL + 0xD46F83B2CB7F5268ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD509AD82E3ACD04FULL + 0xBBAB6080323F3EB6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCEFF2B7CB1811997ULL + 0xB867FC32EFFADCB7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEA00D818F7FFBEFDULL + 0x969A430F8BADE8DCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA4AA40A8B4BA2CF3ULL + 0xF4504825CAF3A47AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAC9E272654661581ULL + 0xE7237D09ECBD4D8BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB5AEEE7EAF638AC1ULL + 0xC25BC9A5101E16EBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBE3ADEE1F87B1593ULL + 0x818BA7B18CA2B621ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE79592E320B2C457ULL + 0xD4FDE05329D049EDULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 428U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 1223U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3515U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1345U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1411U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 874U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((((aWandererH + RotL64(aPrevious, 56U)) + RotL64(aCarry, 41U)) + 11039986441331892533U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = ((((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 6256024955965426119U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aWandererA + RotL64(aScatter, 47U)) + 9857443189988995666U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 11900944813380998208U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 35U)) + 8422577734978875541U) + aNonceWordK;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3100835100713928724U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11871553509810206993U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15501681886909921677U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 17614749493763417027U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 3638372131856199916U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 480683274898147025U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6582275259281025770U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17016882418498941958U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 4269869255230867823U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 1747214688658984715U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 9356088987044015278U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 16221733545319753695U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4056238112133473456U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16013150119949532998U;
            aOrbiterE = RotL64((aOrbiterE * 12913648646318115315U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 44U) + aOrbiterD) + RotL64(aOrbiterG, 41U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + aPhaseAWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 21U)) + aOrbiterK) + aNonceWordH) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10525U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 8771U)) & S_BLOCK1], 20U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10909U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 9903U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7801U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5627U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8149U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 51U)) + (RotL64(aPrevious, 19U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 5721224134332887360U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 57U)) + 6892749729775049095U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 28U)) + RotL64(aCarry, 53U)) + 3884839462099556836U) + aNonceWordE;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 3U)) + 4365431706830216193U;
            aOrbiterA = ((((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 15501528746571578773U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4505911326320650606U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1865129050927879580U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9198152644404068721U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2011737665969640369U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 611672935827062688U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 12873671551304596619U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 663547038310431047U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 5468932264754299556U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 11968657455484578525U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17920294117231191705U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 486058453837528110U;
            aOrbiterK = RotL64((aOrbiterK * 8851102552244026737U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2789178451938129313U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 420772587981211184U;
            aOrbiterD = RotL64((aOrbiterD * 17402987842294006667U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 58U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aNonceWordK);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + aNonceWordA) + aPhaseAWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 57U)) + aNonceWordB) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 58U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14651U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 13734U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12511U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12684U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 15244U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 18255347001097480328U;
            aOrbiterB = ((((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 13679246790311505735U) + aPhaseAOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 5U)) + 10565839529765027116U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 41U)) + 14327172566224769901U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aWandererC + RotL64(aCross, 5U)) + 16239024612038195174U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13800012174212131890U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13900288860157577583U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13177682776510523095U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4144386119777112740U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3154558262670631372U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13236911910092437063U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7456728543137614001U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11709519851158935384U;
            aOrbiterB = RotL64((aOrbiterB * 7016689518570071587U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 15607438907832240304U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9276575329661725624U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 8879744070762412745U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6459435969129449226U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6442382118416542275U;
            aOrbiterD = RotL64((aOrbiterD * 2921027306686588233U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 37U)) + aNonceWordF) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + aNonceWordA);
            aWandererK = aWandererK + (((((RotL64(aIngress, 30U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 47U)) + aNonceWordO) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterB, 22U)) + RotL64(aCarry, 21U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20992U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((aIndex + 17273U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18867U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20747U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16681U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 43U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererH + RotL64(aScatter, 28U)) + 16016931609704150191U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 14511433515861302636U) + aNonceWordO;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 51U)) + 11691237442613269593U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 16383220587320484649U) + aNonceWordL;
            aOrbiterD = ((((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 14293015313458219868U) + aPhaseAOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4407695248205526670U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1158323195324398372U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7489061637031434357U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6577683409653864555U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 171080079472863843U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3063978974927752653U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5766333425872228205U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16173508656917582960U;
            aOrbiterG = RotL64((aOrbiterG * 12187968015372936695U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11781450063402219202U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13033139686637576694U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4331137994135472025U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4006310759400926020U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13156817947481574467U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 563189239835001483U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 56U) + aOrbiterF) + RotL64(aOrbiterD, 56U)) + aPhaseAWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + aNonceWordF);
            aWandererE = aWandererE + (((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 29U)) + aNonceWordE) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26470U)) & S_BLOCK1], 26U) ^ RotL64(aInvestLaneB[((aIndex + 26441U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 24394U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24535U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 21873U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = (((aWandererE + RotL64(aCross, 12U)) + 10404808878585437255U) + aPhaseAOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (aWandererC + RotL64(aIngress, 29U)) + 10587858736301591439U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 1430530909801644435U) + aPhaseAOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 9090938022430118902U) + aNonceWordJ;
            aOrbiterK = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 12936604311751121235U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1000583006020232032U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12352532088997042232U;
            aOrbiterH = RotL64((aOrbiterH * 494418029883239087U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16723410947058502564U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16614089235313154270U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 11530998303573027827U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4245553025593349277U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3353146318549477494U;
            aOrbiterI = RotL64((aOrbiterI * 14246377408238318091U), 43U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 5935727336135635196U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10312187090293319667U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1395964500396711899U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12192843181244744484U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2542570124502586365U;
            aOrbiterD = RotL64((aOrbiterD * 17222847847573534963U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterH, 3U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterI, 53U)) + aOrbiterD) + aNonceWordO);
            aWandererA = aWandererA + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordC) + aPhaseAWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 18U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28593U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 27617U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30382U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32012U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 32582U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 41U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 4204560462077827182U) + aPhaseAOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 6572370199668594039U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 15958999876732622825U) + aNonceWordF;
            aOrbiterH = ((aWandererD + RotL64(aCross, 38U)) + 9969349486879280377U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 51U)) + 15450238998293956181U) + aNonceWordL;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9128619863683138259U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 5691270563628979565U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 2170424734274640859U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5901029710568933106U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 10442738941988588834U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 7386621444831603817U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3508116020325721993U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13221917083569767259U;
            aOrbiterA = RotL64((aOrbiterA * 6845108555710135357U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11627915460377128176U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 17858261365514253433U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 7535577636975884641U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4294837988806295989U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11242915481585070249U;
            aOrbiterK = RotL64((aOrbiterK * 17540688242763829319U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterD, 11U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterA) + aNonceWordM) + aPhaseAWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 46U) + aOrbiterI) + RotL64(aOrbiterH, 34U)) + aNonceWordG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Hockey_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBF119B2DC299A751ULL + 0x96094AF8EA01C767ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9D1F7D7F4051526DULL + 0xF648343A85D103A2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDD09C13B870DA3A7ULL + 0xC8C77238E2D8A243ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF08673DC5DC96A97ULL + 0xA69957435FF27AE6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF5A4FF2A300F64DDULL + 0xFBB28490C396C60FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF448005E63D4F5E3ULL + 0x92F4D7AAD5E6142CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8818B8F5CBAF2B0FULL + 0xEC93D71EE888C4D5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDA21401D4D8CF93DULL + 0x9AAF9572508108D8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8BAC9BA009C22103ULL + 0xEECC8240FEC5EDD4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x96EB4E558780FA5DULL + 0x951B0F11834E15A5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE881CAFF58129D47ULL + 0xA030A590640C803CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x896B94C1B8C20B47ULL + 0xDF7614B0E970D4DDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEC8420E3F42B8F63ULL + 0x967D85EE280D5CDEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCDCD76A538C83025ULL + 0xFBFDBA9E4C7DD64EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF34AC89F0F25F1C5ULL + 0xE154C1326CA34988ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBCCAD97D7069EF57ULL + 0x85475C168152C31CULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2484U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 5670U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 6466U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6216U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 714U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 126U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 13U)) + (RotL64(aCarry, 43U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 18087125778766689269U) + aPhaseBOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 13U)) + 13710545066503235196U;
            aOrbiterE = (aWandererH + RotL64(aCross, 51U)) + 1701939704736254645U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 4U)) + 8064093611384019909U) + aNonceWordG;
            aOrbiterC = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 16623332751533885431U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 19U)) + 15590129153794910109U) + aNonceWordE;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 43U)) + 7413312683079107383U) + aPhaseBOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 58U)) + RotL64(aCarry, 3U)) + 4186064478651458810U) + aNonceWordJ;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 39U)) + 5501191643940735954U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11064645242200570835U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13825922087298055833U;
            aOrbiterE = RotL64((aOrbiterE * 7529317892716108867U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5944980709887369970U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8181136916070569646U;
            aOrbiterC = RotL64((aOrbiterC * 395183021205661827U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 15442336949157292482U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11580554435240641337U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6654637892858767739U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11240018128174598322U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2027565596050777471U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18048186560314431815U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16425887196883725233U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16828683527588834095U;
            aOrbiterB = RotL64((aOrbiterB * 17746289103235902485U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9923829146479008804U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 6669171007279929454U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 681823450939955099U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3902430046523165149U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6739998149289590041U;
            aOrbiterK = RotL64((aOrbiterK * 2675037435528416821U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16014401255534234075U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14741857638680634564U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8723611021403369393U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5064807861673260054U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 968747317273200299U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 14122304002722582329U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 28U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterC, 53U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 23U)) + aOrbiterE) + aNonceWordL) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 44U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterE, 35U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterI, 39U));
            aWandererK = aWandererK + ((RotL64(aIngress, 58U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterH, 48U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9038U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 11614U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12112U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15958U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15536U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9576U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12010U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aCross, 54U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (aWandererB + RotL64(aPrevious, 58U)) + 2915859148137000694U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 39U)) + 210680583721444425U;
            aOrbiterJ = ((((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 6668118118775650387U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = ((aWandererC + RotL64(aCross, 53U)) + 15794200818099010989U) + aPhaseBOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 6565076707062828369U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 47U)) + 16323164497808856719U) + aNonceWordO;
            aOrbiterI = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 7965435318816716560U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 34U)) + 7390281030573369017U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 11U)) + 2269738866911824875U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9664014216039993873U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 18284857398028357633U;
            aOrbiterJ = RotL64((aOrbiterJ * 8402008251343393737U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 367667619795303009U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7935945060956274197U;
            aOrbiterC = RotL64((aOrbiterC * 5481786693511955209U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16683666162337789540U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10655658270998102390U;
            aOrbiterH = RotL64((aOrbiterH * 15231596813382239841U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8307037916581540297U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3247742749860703524U;
            aOrbiterI = RotL64((aOrbiterI * 15052136713218656641U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10446792483683818139U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16374602929344972364U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 12599903932725787599U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2411334498322777183U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1093701164116833765U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 13129220206835381729U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17018480952982840635U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17348395690080029814U;
            aOrbiterA = RotL64((aOrbiterA * 6212591395713433257U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16111252311283623152U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12776492920397785951U;
            aOrbiterG = RotL64((aOrbiterG * 6136009241593081821U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 12214538600808144816U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10043377462096783363U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14639467375095185877U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 10U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 28U) + RotL64(aOrbiterH, 43U)) + aOrbiterG) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + aPhaseBWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 39U)) + aOrbiterD) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterK, 22U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aScatter, 4U) + RotL64(aOrbiterH, 53U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 34U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22277U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 17323U)) & S_BLOCK1], 24U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 20184U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17318U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16938U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21601U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 21773U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 56U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererC + RotL64(aScatter, 18U)) + 2168513956284366370U) + aNonceWordM;
            aOrbiterF = (aWandererG + RotL64(aIngress, 23U)) + 10290361969974613111U;
            aOrbiterG = (aWandererB + RotL64(aCross, 53U)) + 15673836275828498050U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 16600540024145812236U) + aNonceWordC;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 43U)) + 9428052101528111892U) + aNonceWordG;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 29U)) + 12763657928312763377U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 39U)) + 10751286982008662485U) + aPhaseBOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 35U)) + 1708230173038057979U) + aNonceWordO;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 6U)) + RotL64(aCarry, 57U)) + 4011389705422783816U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11704428328093077714U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 2055336619674699284U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6374289210096410907U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1870865272102705804U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3574214263751923179U;
            aOrbiterA = RotL64((aOrbiterA * 13132083406834413563U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 984611970726966186U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15207945449947643672U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 9539470161576639981U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4181398506373973169U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15222345431506025949U;
            aOrbiterF = RotL64((aOrbiterF * 6925143692628659467U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15023513452326240962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14965669361708810699U;
            aOrbiterH = RotL64((aOrbiterH * 587008860996713147U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7985755518735406360U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 225592097619240187U;
            aOrbiterI = RotL64((aOrbiterI * 2313509354133400439U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3659537916566939383U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 17043668033610689611U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10797634709118100773U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10217321522161675848U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8013663869536146842U;
            aOrbiterD = RotL64((aOrbiterD * 2293233079384777175U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13762445330867496042U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2692400019659269106U;
            aOrbiterC = RotL64((aOrbiterC * 167704184292219399U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 10U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterA, 18U));
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + aPhaseBWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterE, 37U));
            aWandererC = aWandererC + ((RotL64(aScatter, 36U) + aOrbiterD) + RotL64(aOrbiterC, 52U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + aNonceWordK) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 10U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27869U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 28494U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27200U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 30448U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31875U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30327U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28532U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererK + RotL64(aIngress, 58U)) + 3255291173184001106U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 27U)) + 15308468160116255528U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 19U)) + 18186972408589866656U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 4439324265978331914U) + aNonceWordA;
            aOrbiterA = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 13099263173016322486U) + aNonceWordH;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 13U)) + 7041561081767500660U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 6196422612687812971U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 39U)) + 7664260932541281413U) + aNonceWordL;
            aOrbiterD = ((aWandererE + RotL64(aCross, 6U)) + 17802347823020441056U) + aNonceWordM;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4253107484061190446U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13799496534030645312U;
            aOrbiterC = RotL64((aOrbiterC * 9167675060053848207U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14252892847595951926U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5663527578664291422U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 18314294235895182465U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11148755959699137661U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17036900929333594592U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16041243617369003291U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2403828181385259549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17813580350434928194U;
            aOrbiterK = RotL64((aOrbiterK * 13666780980793857831U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5623611126885414523U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7293224381174846969U;
            aOrbiterD = RotL64((aOrbiterD * 7032561584670788117U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 10602620906929686163U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 18015916257203385982U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 10684090189688871993U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13592915735376305773U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13995866908043417505U;
            aOrbiterE = RotL64((aOrbiterE * 3802175869395887331U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8200465989447697618U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9866671660800629464U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2138851839905326265U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11557528777230608777U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 131060617338185060U;
            aOrbiterJ = RotL64((aOrbiterJ * 11068705423012265209U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 24U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 52U) + aOrbiterI) + RotL64(aOrbiterF, 47U)) + aNonceWordB) + aPhaseBWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 5U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 12U)) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterA, 23U)) + aPhaseBWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 18U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Hockey_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x88ACC570D576DC63ULL + 0xE9A2CBED540082F4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x84703D13843F8A2DULL + 0xA3AA79DC9D02C012ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD44BB9158453C247ULL + 0xE8217E10ED7D72EFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFC1E7E66DFDAC551ULL + 0x8779D08D8C7F0335ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xABA1CB79CA7EC283ULL + 0xB7806B20996FC111ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBB5FAC59F8FB530FULL + 0x822A9280E43A4158ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE6C29CC83866D873ULL + 0xCB6497F9C52A934CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE41087AD8F2B1625ULL + 0xD513389B9EA6B6E2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBB5EF7381D23ECEBULL + 0x932A8642EFBFE98FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB2D0DAC7A7A519A7ULL + 0xA97823500DD9152FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC2050C0AFCBB8B6BULL + 0xBDF2893266627661ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE190676F54DDF4F3ULL + 0xD5D5A111AFDF0205ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9DE7281FE728635FULL + 0xBDD9A5495A140F38ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE795600581159097ULL + 0xEF478E108D40734BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA3F6A63C8209C195ULL + 0xCECF245DB84AB3BDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA264AFCF319B4095ULL + 0xDEF738D9D04977B1ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2096U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 5215U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4077U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2264U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1367U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5389U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = (aWandererB + RotL64(aCross, 27U)) + 7948891781097675369U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 13928362874228230226U) + aNonceWordJ;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 10776180542602258926U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 37U)) + 5735115172149470447U) + aNonceWordF;
            aOrbiterG = (((aWandererD + RotL64(aCross, 5U)) + 5353591822981766987U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 562301708107268570U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 60U)) + 10467810247578364868U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 14541630141152308564U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2350076897065139429U;
            aOrbiterK = RotL64((aOrbiterK * 12222554362482034393U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17519109078651162228U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6061035173339902910U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10021905773432907835U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15654836633731000065U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 13723521735153718904U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 14459516479283070563U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2849680038315532197U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 17336102435576647923U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 10984689101753586739U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7671010488872356142U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11485114338165600777U;
            aOrbiterG = RotL64((aOrbiterG * 4162584865462407791U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8759060657343458985U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11009137869375286581U;
            aOrbiterD = RotL64((aOrbiterD * 8741417343929809115U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 15792999392743144135U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6180808423175992479U;
            aOrbiterB = RotL64((aOrbiterB * 13681230339693676907U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 48U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 41U)) + aOrbiterK) + aPhaseDWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aNonceWordM);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterH, 19U)) + aPhaseDWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterG, 10U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5787U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 9492U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8944U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneC[((aIndex + 9992U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6331U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8173U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10854U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 4384716820085860551U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 9715780315942116888U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 15963520052789178632U) + aNonceWordF;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 58U)) + 14346700690686392938U;
            aOrbiterB = (aWandererC + RotL64(aCross, 3U)) + 6005518012489966643U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 21U)) + 2506732930310252119U) + aNonceWordA;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 35U)) + 16782163084851775826U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 823673076571076303U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1634084509064077736U;
            aOrbiterE = RotL64((aOrbiterE * 1128407326773234517U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1288134975466877686U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2998220403162908444U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4321412662318298283U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 220430672180734911U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10223923547068528867U;
            aOrbiterI = RotL64((aOrbiterI * 12577370238343872139U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11696469696177647608U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6545430420379636963U;
            aOrbiterA = RotL64((aOrbiterA * 8387163146257553773U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 79691451831797107U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8971444023498649419U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7148919880477390009U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5624403902454498793U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9468064161002030997U;
            aOrbiterJ = RotL64((aOrbiterJ * 8243560528100864595U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4619361544913629805U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12682446273369750704U;
            aOrbiterD = RotL64((aOrbiterD * 10879074713156075641U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterH, 12U)) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + aPhaseDWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 3U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15468U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 15397U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 14266U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11668U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12947U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 19U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 13714409587461539863U) + aPhaseDOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 14101156723903265839U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 11U)) + 7063754562895369001U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 12320578575245519386U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 18U)) + 11744826789631008424U) + aNonceWordF;
            aOrbiterD = (((aWandererG + RotL64(aCross, 41U)) + 8744816505096675597U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aWandererE + RotL64(aScatter, 29U)) + 10405435520084528645U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1463157688070683543U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12379603577919617703U;
            aOrbiterB = RotL64((aOrbiterB * 14858901470015109311U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1343439118031348146U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 16118850268070235540U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 11184386483735388257U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14116264435819277136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5251698273012432109U;
            aOrbiterC = RotL64((aOrbiterC * 1495818611622063967U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14806408656041403829U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11569345414052398227U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9913158908301414861U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17063874769147888574U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9927420478679581917U;
            aOrbiterH = RotL64((aOrbiterH * 9042782809534196563U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2550285599827162167U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17801534123304996448U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2160836889363614721U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6456685241021762041U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 17064208177372969289U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 13726627607233302493U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 41U)) + aOrbiterG) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterI, 19U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterC, 60U)) + aPhaseDWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20125U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 21558U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20988U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19567U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 18644U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (aWandererC + RotL64(aPrevious, 57U)) + 12849591986267890852U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 4U)) + RotL64(aCarry, 19U)) + 8232614804696815750U) + aPhaseDOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 12141567259210877281U) + aNonceWordA;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 2928641981037885644U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 13U)) + 980733350554783938U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 47U)) + 2683985177993350746U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 35U)) + 14532148403815527355U) + aPhaseDOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7736296629433884203U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10428437770166310549U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 326634742742373401U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 18327174144859461029U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6810436935194432002U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 2715987179577753597U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12606153309690753435U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17123256945895150555U;
            aOrbiterA = RotL64((aOrbiterA * 13469111258504672565U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9057777759026189541U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16478485918911194442U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 11054247078884894131U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 18064460487552100483U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11477276762421684083U;
            aOrbiterH = RotL64((aOrbiterH * 3886501230380184395U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18318375441973295081U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13849305985380030986U;
            aOrbiterK = RotL64((aOrbiterK * 12962140243967824959U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10240409420338313641U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 18360586077779529086U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 18196875422391501927U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 28U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterK, 50U)) + RotL64(aCarry, 41U)) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 21U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterF, 5U)) + aNonceWordE) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 23375U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 22507U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 26777U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 21867U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24185U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 1898718075389870739U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aWandererF + RotL64(aCross, 23U)) + 5631794889237247403U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 5U)) + 18219714659484524607U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 15419581386225732921U) + aNonceWordH;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 44U)) + 9125575431710198210U) + aNonceWordL;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 12205871520544965505U) + aNonceWordN;
            aOrbiterH = (aWandererH + RotL64(aCross, 13U)) + 7617534300497343422U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18017579105368135814U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 10693882161946020042U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 2326507900303932855U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11669615701700895306U) + aNonceWordF;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 11045110212889232165U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 5965171269273719849U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18019107802806469913U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12315940560472528716U;
            aOrbiterH = RotL64((aOrbiterH * 4505122470351404065U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4899009736070044310U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17412253404253730364U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 10791901166391946485U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4826286251927854181U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4523455921321845084U;
            aOrbiterJ = RotL64((aOrbiterJ * 14534103906736598099U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4132514462154182215U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7164745605985109269U;
            aOrbiterK = RotL64((aOrbiterK * 14107325508977225261U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6297434295807635654U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8813887638672996646U;
            aOrbiterA = RotL64((aOrbiterA * 17495632530773158201U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + aNonceWordD) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 48U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 23U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 44U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aNonceWordK) + aPhaseDWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterK, 11U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31893U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((aIndex + 30456U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29726U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31402U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27610U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 43U)) + 3621877681473089725U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 4451752751536414717U) + aNonceWordL;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 11371625415377772117U) + aPhaseDOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aScatter, 3U)) + 6046792758881150619U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 11U)) + 8213166120394461682U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 60U)) + 4343156661140422645U) + aNonceWordI;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 11105271483234947905U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 348904609985341372U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12924652822526858767U;
            aOrbiterJ = RotL64((aOrbiterJ * 2801892489296408735U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7461211697358520287U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16551553555297890558U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 16432952324635746293U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11908056404140782995U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9147367258259948715U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10777628928376261667U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8876461054692728610U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10546855952702525404U;
            aOrbiterG = RotL64((aOrbiterG * 10071104785895309677U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4748636139110443794U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 783046909529525098U;
            aOrbiterC = RotL64((aOrbiterC * 8969157702460927215U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16683965945838696665U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12385412690177109575U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 10795062772707143187U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8210546822184469023U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13146493623236979963U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 13199947810161148155U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererF = aWandererF + (((RotL64(aIngress, 40U) + aOrbiterC) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 54U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 29U)) + aPhaseDWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + aNonceWordG) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterB, 35U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 29U);
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

void TwistExpander_Hockey_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFB1DE255F44B6743ULL + 0x871ECA386E8E017CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x88CA95A8874A195DULL + 0xF569A1C0A072AFE2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFE67F45E4F30E901ULL + 0x975B6464E9144353ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC17240E1FC318D09ULL + 0xAFB578B6C222F95EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF213F47DB5B4DFE7ULL + 0x824672418FFE58C6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC2BB3A5BAC810317ULL + 0xCA123DFAA1DA1E02ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9E2F6346A500F5FDULL + 0x955F9FC5EDCDC520ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x94886F8ECECC119FULL + 0xFAB236630F2F1FAEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA3E6DCBFDF2934B9ULL + 0xB4561CB7594E6BA4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8F5DD10D16467AC7ULL + 0xD295103233E9E5B6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC89B55F2C05E9439ULL + 0xBECD3C69C7AD82E5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF84D6899CC8B680BULL + 0x9AFEFF9168DD5A04ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8B3F2D2666BCB3B3ULL + 0x8864752C91F8B775ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x987BAA709AE35149ULL + 0xF206E7B5912948C1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD4AAF6C83B4AA22DULL + 0xDC9D4AF7D983E926ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB481360513C3E3CBULL + 0xA9EC646870E6FF18ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 1110U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneB[((aIndex + 1741U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 36U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3870U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 35U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1732U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 4U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 28U)) + RotL64(aCarry, 43U)) + 4848316479321533394U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 21U)) + 6919360256662636195U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aWandererF + RotL64(aCross, 23U)) + 9897013582181108544U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 13U)) + 7319353809896158678U) + aNonceWordJ;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 43U)) + 2848175435514849859U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 35U)) + 6967780718720437934U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 10143884766603388136U) + aNonceWordF;
            aOrbiterG = (aWandererD + RotL64(aScatter, 47U)) + 8675965006150972051U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 39U)) + 16350117755560994281U) + aNonceWordB;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 60U)) + RotL64(aCarry, 47U)) + 17976597517118423760U;
            aOrbiterK = (aWandererE + RotL64(aCross, 53U)) + 1399631141355370237U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3590613762034716792U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5134624314245932157U;
            aOrbiterH = RotL64((aOrbiterH * 13077589037975283371U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10082236952942943654U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4015535035905433450U;
            aOrbiterJ = RotL64((aOrbiterJ * 4961808568701908559U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 611474103801573800U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5786708483794098001U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7694007039340089267U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5201943497363274455U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9282160506938328489U;
            aOrbiterF = RotL64((aOrbiterF * 5368182164239021367U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4932320527498940158U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 11576526341731392916U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 1712051774729439363U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10790691517638887125U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16280649213607464422U;
            aOrbiterD = RotL64((aOrbiterD * 10756733801499471873U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9553716940667712810U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11827518270964003341U;
            aOrbiterA = RotL64((aOrbiterA * 1322489827908132831U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16777463701235809321U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3375489084588454149U;
            aOrbiterG = RotL64((aOrbiterG * 3335010977457647307U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 8129898095524287632U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14496406641486541929U;
            aOrbiterB = RotL64((aOrbiterB * 10077246205532940301U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17968163292907132345U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2431407778543471402U;
            aOrbiterK = RotL64((aOrbiterK * 407105842057624537U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 18330313613898211889U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4848316479321533394U;
            aOrbiterI = RotL64((aOrbiterI * 3462735144109152811U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 37U)) + aOrbiterE) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 5U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 13U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aPhaseEWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterA, 24U)) + RotL64(aCarry, 29U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + aNonceWordM);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK + ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterC, 22U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 22U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererD, 52U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6742U)) & S_BLOCK1], 36U) ^ RotL64(aInvestLaneC[((aIndex + 9970U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 10295U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((aIndex + 5809U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6588U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6676U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8579U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 13U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 5U)) + 6163290588946759209U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 24U)) + RotL64(aCarry, 41U)) + 7342672468560105447U) + aNonceWordB;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 11574563167017282321U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 35U)) + 2254820206194758964U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 11U)) + 1469783447473099498U) + aNonceWordM;
            aOrbiterF = (aWandererB + RotL64(aScatter, 41U)) + 14174828900676165088U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 22U)) + RotL64(aCarry, 23U)) + 16277954291890598132U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 37U)) + 14845750668693136766U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 57U)) + 150099699692047766U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 29U)) + 1200784917165131703U) + aNonceWordE;
            aOrbiterB = (aWandererD + RotL64(aCross, 39U)) + 9469982764806754302U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10956702761701710182U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7915506894975487807U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8874108311712727983U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17335794183733623213U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 557028996286989506U;
            aOrbiterF = RotL64((aOrbiterF * 3993359298602424281U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1597385667771002414U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4376417959915162639U;
            aOrbiterI = RotL64((aOrbiterI * 4626236858205178149U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 549770198518993876U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 756554555648070919U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16272320259614325355U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7298557532533152193U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3336802611342112013U;
            aOrbiterE = RotL64((aOrbiterE * 14679103452120080499U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 2314938232094714365U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12215066333571149153U;
            aOrbiterB = RotL64((aOrbiterB * 10747052773052630601U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7762752719356805046U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6519429915769040078U;
            aOrbiterJ = RotL64((aOrbiterJ * 15548676502167938513U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7556691736109752918U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 13731245903412646404U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 15581965016668635409U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5910925625723735162U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16037704866415841869U;
            aOrbiterG = RotL64((aOrbiterG * 11628217027073824759U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12605882248192797360U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9579778913978981884U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5372577227818787957U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6063171520266734946U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6163290588946759209U;
            aOrbiterK = RotL64((aOrbiterK * 291843698316138251U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 22U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterA, 21U)) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 56U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterC, 39U));
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 51U)) + aOrbiterA) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD + ((RotL64(aIngress, 36U) + aOrbiterJ) + RotL64(aOrbiterH, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterD, 37U));
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterB, 26U)) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterE) + aNonceWordA) + aPhaseEWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12080U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 11464U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13589U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13578U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneC[((aIndex + 15576U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 6U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererD + RotL64(aPrevious, 5U)) + 18180797995100240808U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 57U)) + 6585906608223552885U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 43U)) + 14088708930575939855U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 38U)) + RotL64(aCarry, 47U)) + 468974153311516044U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 12481951025619894110U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 19U)) + 17227987923860711763U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 21U)) + 4373962756657477139U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 29U)) + 2077576476565420951U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 47U)) + 17435011300234663764U) + aNonceWordE;
            aOrbiterF = (aWandererB + RotL64(aCross, 23U)) + 4118039398293246896U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 26U)) + RotL64(aCarry, 13U)) + 13724716599855216683U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12391461204689596339U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9900605191533799627U;
            aOrbiterC = RotL64((aOrbiterC * 13553565332531046301U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 972946858824366125U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17247681919694541215U;
            aOrbiterA = RotL64((aOrbiterA * 2974639094630445643U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15442851427306771601U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7303586227288294037U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15406402525021428799U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 12650358753454105119U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1483710933373510492U;
            aOrbiterB = RotL64((aOrbiterB * 6531763256577221891U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18065810162229740788U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11311677121338794007U;
            aOrbiterF = RotL64((aOrbiterF * 15116367961682119467U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2355285311890287611U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1287783821903407734U;
            aOrbiterE = RotL64((aOrbiterE * 8054011680932255985U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9282654686791135654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15488608017745542551U;
            aOrbiterH = RotL64((aOrbiterH * 7858866274035085123U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13296835576073421802U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7127700236018338741U;
            aOrbiterG = RotL64((aOrbiterG * 11246173563106014149U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1365928843264598789U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7777790578813003657U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10121688100505628161U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2104270617375082523U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13363764449819651164U;
            aOrbiterJ = RotL64((aOrbiterJ * 2685452132715528975U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2008038686059197988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 18180797995100240808U;
            aOrbiterI = RotL64((aOrbiterI * 8978998151475372047U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 20U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aScatter, 56U) + RotL64(aOrbiterB, 41U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 35U)) + aOrbiterB);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 23U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordK) + aPhaseEWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 37U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 24U) + aOrbiterE) + RotL64(aOrbiterH, 60U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererG, 6U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16600U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneA[((aIndex + 16731U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16802U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20369U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17099U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 20U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 14U)) + 2330952702412094686U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 47U)) + 7820188225935060799U) + aNonceWordE;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 9347644591709839145U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 2288624878446846870U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 35U)) + 9358977729492824128U;
            aOrbiterH = (aWandererE + RotL64(aCross, 3U)) + 1858511275052455039U;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 13715478509322292552U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aScatter, 21U)) + 16413396625604260455U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 19U)) + 17714322215518432705U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 11U)) + 16188315436202861122U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 6U)) + 5564445841368207813U) + aNonceWordJ;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13717068949900594673U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14143659432287313765U;
            aOrbiterE = RotL64((aOrbiterE * 17281441046722262917U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5729546141908425670U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 4297827922736712074U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 13631630436759768885U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 829520109395163673U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11547160328525174295U;
            aOrbiterI = RotL64((aOrbiterI * 4759690159673049775U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2907177944512117206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11100346409065275671U;
            aOrbiterF = RotL64((aOrbiterF * 17927994356809011637U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1344592529249949068U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6470438516791143572U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 13339390828725370475U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5217751823741520847U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5371275223586938039U;
            aOrbiterD = RotL64((aOrbiterD * 12318403075523724125U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 14218103150268532919U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1367628876596800571U;
            aOrbiterG = RotL64((aOrbiterG * 13777531272321533137U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2372041991018455610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9870744274890595581U;
            aOrbiterJ = RotL64((aOrbiterJ * 12093443117747395585U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15531376915156611594U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11166549148968363252U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10024372567841218915U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8555942275137258839U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3304132937209624841U;
            aOrbiterK = RotL64((aOrbiterK * 7965093976633155809U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14825330575158830172U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2330952702412094686U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9146641978165131495U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 58U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 43U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 22U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 50U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aCross, 44U) + aOrbiterC) + RotL64(aOrbiterB, 39U));
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 18U)) + aOrbiterF) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterC, 37U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26597U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((aIndex + 26935U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23774U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26628U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25545U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 26U)) + 3612110001869385068U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 21U)) + 16340824141280225936U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 15222338965130765231U) + aNonceWordC;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 53U)) + 6649270508107155041U) + aPhaseEOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 768217258655426384U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 37U)) + 4481855259658861851U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 34U)) + 18318041934562434016U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 29U)) + 4212457153804401807U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 16143621095636987628U) + aNonceWordM;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 57U)) + 2095664232866642086U) + aNonceWordF;
            aOrbiterB = ((aWandererG + RotL64(aCross, 51U)) + 4339527736737366572U) + aNonceWordN;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13679353177869884790U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11582168502846418236U;
            aOrbiterA = RotL64((aOrbiterA * 135539430034462861U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10451330452898542191U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12951448817640617841U;
            aOrbiterJ = RotL64((aOrbiterJ * 4141870904192742091U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 15389161934419370747U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 4754886272708253014U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16638243718191281597U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11746389873929280688U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12042680172517298768U;
            aOrbiterE = RotL64((aOrbiterE * 3814780289755857543U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2648103752465009244U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 451594673632597973U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8496763663271072425U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5696534794094099710U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14609435045257077395U;
            aOrbiterK = RotL64((aOrbiterK * 14658408563237468407U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11599395126850950133U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12699598504604446664U;
            aOrbiterB = RotL64((aOrbiterB * 14313494063098111823U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9398465148537154745U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12139736860648011256U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 15257503229375247987U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5390816291244486383U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2797988892316486895U;
            aOrbiterC = RotL64((aOrbiterC * 14668138881285892065U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 18356290434261054712U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16582824574485822826U;
            aOrbiterH = RotL64((aOrbiterH * 7207935384746719969U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9858803484150150915U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3612110001869385068U;
            aOrbiterG = RotL64((aOrbiterG * 2862887443435821143U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            aWandererE = aWandererE + ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 51U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + aPhaseEWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterG, 41U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterD, 36U)) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterG, 43U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 44U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 24U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererB, 46U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27972U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 31835U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27927U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29918U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29611U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 4476099022490972343U) + aNonceWordF;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 23U)) + 16836423700375760429U) + aPhaseEOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aWandererH + RotL64(aCross, 44U)) + 8850577488928703557U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 57U)) + 7091631824560042743U) + aNonceWordA;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 5U)) + 12560498899956759494U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 7797973377112012161U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 35U)) + 6173820673874805794U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 10805025132310245348U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 26U)) + 7139216143268029968U) + aNonceWordD;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 13U)) + 8241544862261635722U) + aPhaseEOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 21U)) + 4735527016563596150U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5166171126690294033U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11117641762075368393U;
            aOrbiterB = RotL64((aOrbiterB * 4980156869201219393U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6312932356458415421U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1304139291184508668U;
            aOrbiterD = RotL64((aOrbiterD * 90744653170922319U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10085025354842771067U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16745854428789531080U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1945983905747274355U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2497187958708890337U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16069701876646548995U;
            aOrbiterI = RotL64((aOrbiterI * 16606039730973709495U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17242004368025978091U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12334315722243232121U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 16528598396696346719U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8007042082518126895U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5665686359038811484U;
            aOrbiterC = RotL64((aOrbiterC * 11289316305875751813U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3913477186958600592U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16918984318564170343U;
            aOrbiterE = RotL64((aOrbiterE * 5128293326494417281U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10227611546502931418U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7187623463085447228U;
            aOrbiterJ = RotL64((aOrbiterJ * 8479839369622163181U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 16655159122037336519U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9844145011519243346U;
            aOrbiterK = RotL64((aOrbiterK * 16512883184116277583U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8660130685326542506U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16192687259641294851U;
            aOrbiterH = RotL64((aOrbiterH * 2882649237163668499U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15208432734447317310U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4476099022490972343U;
            aOrbiterF = RotL64((aOrbiterF * 7447168142776253041U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 11U)) + aNonceWordK) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterA, 13U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 11U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 48U)) + aOrbiterH) + aNonceWordM);
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 5U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterA, 37U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterH, 21U)) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 39U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 18U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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

void TwistExpander_Hockey_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEF2A351719DDF8B3ULL + 0xC2F1B7F8B9CE0C93ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD8B79B5B41309F7DULL + 0xF4569F1DFFC34BB0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x98A6A9C0C08CAF7DULL + 0xCFD4C17F1D4B4209ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBB109A05FF524C81ULL + 0xCFAFCAA4D77D8675ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x906CBC6838C2F4DFULL + 0xCDD08606EE0B51CAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB942644917738843ULL + 0xC4C8BE9E033434CDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x893FA4D3A6E26F7BULL + 0xC4355097C0F6BCD5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x968D845750529DAFULL + 0xC4144FE3871EC6F4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBF0A3D97D26E5885ULL + 0x913F835F7A5F8CEDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x90FB05C1F21CC5ADULL + 0xB84C529A55E270C0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9896DC3E701D1B83ULL + 0xCEB1E7931BED072FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD8E33BCE604A229FULL + 0xFF9A6930ED020F30ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x80931E49F86F5D9FULL + 0xA118D30E15AC9AC7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCC74722D449895C1ULL + 0xD00A7F34CB2B8854ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF731B90C9F0FE32BULL + 0xE8E2B1F5BE75C263ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA402C159E1419669ULL + 0xBCE2EDB1FD06F87AULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 978U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 2739U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3067U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4900U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2274U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 92U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 37U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 19U)) + 17225673071833726819U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 10301458382103627331U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 4U)) + RotL64(aCarry, 39U)) + 3960233050857362414U) + aNonceWordA;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 39U)) + 17768665685046605837U) + aNonceWordO;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 29U)) + 14471018461213959767U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 10730597892721340453U;
            aOrbiterF = (aWandererD + RotL64(aCross, 57U)) + 14863394003122760542U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 23U)) + 9948587274816688296U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 50U)) + 3573569431435100993U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8153670675740450590U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16438856577722561424U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 4689247488336908827U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15765587867581925041U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1082039522061775213U;
            aOrbiterD = RotL64((aOrbiterD * 17023740047246402641U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4202521649260798876U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15877659681260461141U;
            aOrbiterF = RotL64((aOrbiterF * 11369910758551088173U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2551560426129646123U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3005102326163906320U;
            aOrbiterK = RotL64((aOrbiterK * 4241583192662435107U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 1675501058857208089U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12774812270956702043U;
            aOrbiterB = RotL64((aOrbiterB * 5488437008504905105U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1044886020922563597U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 4857445127457225171U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13223560654459705259U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11548725551787560962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2434677823189765161U;
            aOrbiterH = RotL64((aOrbiterH * 4283026044563670969U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9606875320524736294U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13732615866277657704U;
            aOrbiterA = RotL64((aOrbiterA * 3905528919281629775U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13921743663803299567U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13350829301153929899U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 11858642286713079795U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 34U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 5U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterI, 34U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + aNonceWordM);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 41U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterA, 58U)) + aNonceWordL) + aPhaseFWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterA, 47U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9006U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 9206U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10465U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6975U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8452U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9703U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7759U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 24U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererI + RotL64(aIngress, 23U)) + 16462052553719977502U;
            aOrbiterD = (aWandererK + RotL64(aCross, 43U)) + 12337064059566619581U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 60U)) + 15801005007094515447U;
            aOrbiterH = ((((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 8228706742665081656U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 11006723027845190869U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 47U)) + 18173765337829177450U) + aNonceWordP;
            aOrbiterI = (aWandererB + RotL64(aCross, 39U)) + 530215083653542558U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 35U)) + 6608611827035564511U) + aPhaseFOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 18U)) + RotL64(aCarry, 21U)) + 2246051826221626809U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5228575308895381421U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 10999213210689606857U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 5467601259546342925U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 3773371037240485696U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8887985779436152504U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 698713082830739677U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11150566414723818350U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8336366151003049546U;
            aOrbiterD = RotL64((aOrbiterD * 9033771197242493699U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13233968794237090787U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8172558473508478819U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17837070423649268435U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 133564480283347997U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15104810248883567064U;
            aOrbiterA = RotL64((aOrbiterA * 706802420642303533U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9138629520201127075U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13993086066341664080U;
            aOrbiterG = RotL64((aOrbiterG * 4875046427147105077U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6547273508580516932U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9838727018769865759U;
            aOrbiterI = RotL64((aOrbiterI * 11395273371936839815U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11685694999526122626U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8945983172566303116U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 17791527981004597623U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17606249889617356327U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9296903152000480008U;
            aOrbiterJ = RotL64((aOrbiterJ * 18066622289408024413U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 10U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterB, 46U));
            aWandererG = aWandererG + ((RotL64(aScatter, 4U) + RotL64(aOrbiterA, 41U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererF = aWandererF + ((((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterA, 19U)) + aNonceWordA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterF, 11U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 28U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12430U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneA[((aIndex + 15857U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 15818U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14652U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15926U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 1087148170018530502U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 60U)) + 15530846874509311414U) + aNonceWordC;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 16987358651515511212U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 11U)) + 12504143181007924259U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 51U)) + 393322117322732418U) + aPhaseFOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 3U)) + 14325937299241887166U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 36U)) + RotL64(aCarry, 51U)) + 9395262907017475742U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 19U)) + 13658510441418344769U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 43U)) + 6410754322737005336U) + aNonceWordH;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9257290738538818434U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7489828960857692286U;
            aOrbiterB = RotL64((aOrbiterB * 16519674788777989043U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4118778591214588387U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16619215231168796563U;
            aOrbiterE = RotL64((aOrbiterE * 14876884956536265157U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11326283811003573430U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1865401866017614604U;
            aOrbiterF = RotL64((aOrbiterF * 8378326058282460073U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 670150121105733604U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1499331510641068749U;
            aOrbiterI = RotL64((aOrbiterI * 16623742535540383107U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 1116410848560838532U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2696841341036281779U;
            aOrbiterD = RotL64((aOrbiterD * 9598953298074904869U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5487352391229549881U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12008243050943342979U;
            aOrbiterC = RotL64((aOrbiterC * 9087261224804582459U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 552859665927882960U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8426942688524814473U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 10916963622695549105U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1613287981244830815U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15592897923468694288U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6600750586743893303U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7629853970631002676U) + aNonceWordL;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 13778028957247561272U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 4063798788229605659U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 4U);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 36U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 41U)) + aOrbiterH) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterK, 29U)) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 18U));
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterI, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18294U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 18168U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 20543U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21404U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17643U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererF + RotL64(aScatter, 20U)) + RotL64(aCarry, 53U)) + 12535417189990029950U;
            aOrbiterI = (aWandererH + RotL64(aCross, 5U)) + 6204401443676390273U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 43U)) + 869613505613154672U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 39U)) + 15053590879563855802U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 3U)) + 13338989605204591428U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 35U)) + 18306470022403825392U) + aNonceWordO;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 1150696349434090218U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 29U)) + 13549541786420596437U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 51U)) + 14302878430259588461U) + aNonceWordK;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4660437084477165225U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1653628537860912069U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 2624835201155303123U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5594199757006711631U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11008472193138708891U;
            aOrbiterG = RotL64((aOrbiterG * 13645764762027798301U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3668516817279364310U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 128159531749679984U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4523246859249826987U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6378674346113979108U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11438762460659123362U;
            aOrbiterE = RotL64((aOrbiterE * 2733309638158283953U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10624263004446482910U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12546839706919241411U;
            aOrbiterI = RotL64((aOrbiterI * 11468326687628079347U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8466639576503293921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5828694979857951504U;
            aOrbiterB = RotL64((aOrbiterB * 7835487310289634515U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16496305151014092976U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 589464613876410567U;
            aOrbiterJ = RotL64((aOrbiterJ * 13190816610718051897U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4168532743415647825U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 15944887793736489375U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 17273403561158196717U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 11642456814106259483U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1609897693632334867U;
            aOrbiterC = RotL64((aOrbiterC * 12912773555616819941U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 40U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterA, 10U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterG, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 14U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 53U)) + aOrbiterI) + aNonceWordG);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 30U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 52U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22346U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((aIndex + 26417U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 27164U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24202U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((aIndex + 24450U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 50U)) + (RotL64(aIngress, 35U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 13650869943246163567U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 5U)) + 3435284932011770999U) + aNonceWordO;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 58U)) + 12388155658186776579U) + aPhaseFOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererE + RotL64(aCross, 13U)) + 2374345913955712039U) + aNonceWordB;
            aOrbiterA = (aWandererG + RotL64(aIngress, 43U)) + 6095094526980292156U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 19U)) + 4965147025852444174U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 51U)) + 3261881216269075298U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 30U)) + RotL64(aCarry, 51U)) + 4939780217097329222U) + aNonceWordJ;
            aOrbiterI = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 3019862009792676287U) + aPhaseFOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 901910626217143974U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3647055146712366383U;
            aOrbiterF = RotL64((aOrbiterF * 1792602402476450009U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7731765438957392967U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13409819457393479741U;
            aOrbiterA = RotL64((aOrbiterA * 3345078200262410715U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5415832109107794258U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8876738832313114471U;
            aOrbiterH = RotL64((aOrbiterH * 1304277600444504135U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 17135570542519390359U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2373193062766802082U;
            aOrbiterB = RotL64((aOrbiterB * 4213691513185791519U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16318403285501718552U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8456043288604687045U;
            aOrbiterI = RotL64((aOrbiterI * 10556964529144571683U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10572534930284516528U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14616251186735204677U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2048651204265459805U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2837006243817205610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5315917323622194254U;
            aOrbiterG = RotL64((aOrbiterG * 4080522050089666599U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12084676282761185907U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7922080344175593788U;
            aOrbiterE = RotL64((aOrbiterE * 7603522302708937379U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17620847289789547792U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12140386059533463650U;
            aOrbiterJ = RotL64((aOrbiterJ * 1443266480620969535U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 56U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterH, 30U)) + aNonceWordA);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterG, 43U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterD, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 20U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 20U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32462U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 28420U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 31991U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28694U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 32130U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 50U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererH + RotL64(aIngress, 10U)) + 17081642665820489793U) + aNonceWordO;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 39U)) + 14468854040067229623U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 29U)) + 2249450222593057429U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 23U)) + 14964389079511378664U) + aNonceWordF;
            aOrbiterA = (aWandererC + RotL64(aIngress, 47U)) + 17003491054252360650U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 12710882240582032588U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 9887078182156755359U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 7665284531810584704U) + aNonceWordH;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 4U)) + 7304284015511876717U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5517927023543751734U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17704756310857362759U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15826832172923213591U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11347400363019508578U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11696395232760991243U;
            aOrbiterA = RotL64((aOrbiterA * 9725231749679442003U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10875780291242873583U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7808740614343437672U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8889516201913716283U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3145390996141902032U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16080636485642732615U;
            aOrbiterJ = RotL64((aOrbiterJ * 7445756373012217305U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3929263288176983844U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 18210228766683996806U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 13178080076505449091U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13948962323541421431U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3037683309790156893U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 13406672352222636739U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17827265198532699474U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7270895262023504864U;
            aOrbiterI = RotL64((aOrbiterI * 13467417362477308167U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6431243064980879185U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6680205390976259885U;
            aOrbiterF = RotL64((aOrbiterF * 10421386694108590789U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15910655919164357152U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8046213498216027383U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18061867495824063553U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 34U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 60U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 10U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterC, 36U));
            aWandererG = aWandererG + (((RotL64(aCross, 58U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Hockey_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xACEF20E337EB12CBULL + 0xEF43F3F464CBA432ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC7DB50524BE0CF03ULL + 0xD89EF61C5B332021ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF61A6C48F974C92DULL + 0xBD993ADCE2941229ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA6D3F8019C50DC11ULL + 0x8C78541F9303F3F2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB505313C749ADD13ULL + 0xCCBEB662F9544DFAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x95BC83D0FE95CED3ULL + 0xFC6C40AC23C74D64ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x928362FF49BE601DULL + 0xF269DE2D072A49E0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF0984F298DA7F70FULL + 0xD7F22118F69F3681ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD25C525F61FAD8D5ULL + 0x91E9977D79BFE547ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD073D1C75786D653ULL + 0x93D9534910CDCB81ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x85472A608E7C020FULL + 0xA9008E83BD7E948BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD4748BA8E3C4AF31ULL + 0xEFBB5117F11FE43FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB633F6BBF610F46BULL + 0xE9325999A3865FF0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC93CE4A222BE3B8FULL + 0xF345B6F9AD2E31BEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9C21B9DBEBDF8C4DULL + 0xD179C36A009BACEFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC294EC4BDCCF7399ULL + 0xC17F31BD838A6053ULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3671U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneB[((aIndex + 4999U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2312U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3832U)) & S_BLOCK1], 26U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 4240U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 765U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 18U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (aWandererD + RotL64(aCross, 11U)) + 898812731947995389U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 8677347622525527167U) + aNonceWordE;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 37U)) + 770321564027567654U) + aPhaseHOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 19U)) + 11020474858081526395U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 5U)) + 17289793580414993470U) + aNonceWordD;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 44U)) + RotL64(aCarry, 19U)) + 10111912559295118444U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 8083622125544542011U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7149858558922988240U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5919683821379905699U;
            aOrbiterA = RotL64((aOrbiterA * 16705119888884231567U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6860902846079238714U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15083517836867542075U;
            aOrbiterE = RotL64((aOrbiterE * 4686657139237578325U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14852868368708376381U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9860233289028878323U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 13418143547952204667U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 772406119079116272U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7971141501337627589U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10168120622976358617U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8478568022896691911U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4027604850785607101U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 4826627523578901467U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17199331557841535430U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7515957656979776361U;
            aOrbiterB = RotL64((aOrbiterB * 5468950152869656599U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17138249294921502391U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16236812863923234668U;
            aOrbiterK = RotL64((aOrbiterK * 2925542836624164807U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 20U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 53U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + aPhaseHWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 21U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 30U)) + aOrbiterK) + aNonceWordC);
            aWandererD = aWandererD + ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6043U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneC[((aIndex + 5847U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 8298U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9308U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 10448U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7902U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10281U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 22U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 8604208734152026945U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 1374329953253889829U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 19U)) + 5779278910548228339U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 47U)) + 17670451230882805140U) + aPhaseHOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aWandererC + RotL64(aIngress, 28U)) + 8193848740764866860U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 53U)) + 15801168428145650104U) + aNonceWordE;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 2584718176087499066U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14950366247822737997U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9779293225265670135U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11625969538497982117U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8688968319288372383U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13665723186950342601U;
            aOrbiterE = RotL64((aOrbiterE * 292035540396910837U), 41U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 9395428688359973510U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2152719218018108418U;
            aOrbiterH = RotL64((aOrbiterH * 15271961483518392671U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1350324137411377992U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8729317951386057921U;
            aOrbiterD = RotL64((aOrbiterD * 6008790836417785083U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6317310451893678411U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10175620379041384281U;
            aOrbiterJ = RotL64((aOrbiterJ * 14079679617394330781U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1203082119358827708U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 523869107818193101U;
            aOrbiterF = RotL64((aOrbiterF * 4629501113595689157U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 4028324959540432983U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15447631947468213912U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 6037306615787729185U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + aPhaseHWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterI, 14U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 19U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + aNonceWordF);
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 53U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13611U)) & S_BLOCK1], 24U) ^ RotL64(aSnowLaneA[((aIndex + 11870U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 13237U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11311U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 10959U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 12U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (aWandererK + RotL64(aPrevious, 35U)) + 5960680319644404115U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 16050752633567034185U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 54U)) + RotL64(aCarry, 5U)) + 8447503223226854741U;
            aOrbiterA = (((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 14176813813397917591U) + aNonceWordP;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 13U)) + 10534915376130006644U) + aNonceWordF;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 41U)) + 6866224454375302514U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 29U)) + 16506374165041008396U) + aPhaseHOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 7167814023968794098U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13870852197416596664U;
            aOrbiterG = RotL64((aOrbiterG * 17015971222069856463U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 18064038854848993105U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9869630811507771691U;
            aOrbiterK = RotL64((aOrbiterK * 13723164383800461387U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 863613100452759380U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16597969741225436529U;
            aOrbiterJ = RotL64((aOrbiterJ * 2680793528887208903U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 6575347108051310653U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17062262265485019063U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 7601045488473620019U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7193399224636409133U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14146747818810433849U;
            aOrbiterA = RotL64((aOrbiterA * 5273185769989530041U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9441449106442431427U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4303295336545399503U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8829695296836242587U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12604760768543193458U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 15779327512379787715U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 14000905201441272597U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterB, 19U));
            aWandererF = aWandererF + (((((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterB, 46U)) + RotL64(aCarry, 37U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + aNonceWordO);
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterG, 27U)) + aPhaseHWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererH, 46U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16761U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 20712U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 20308U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18402U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 21062U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 26U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 2786079456995203065U) + aNonceWordC;
            aOrbiterA = (aWandererB + RotL64(aCross, 13U)) + 7237256119153857253U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 29U)) + 9310834010563647604U) + aNonceWordL;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 29U)) + 17361734905706517877U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 3U)) + 15837111231884647451U;
            aOrbiterD = ((((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 18065431964418026445U) + aPhaseHOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 19U)) + 3029123922999952652U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 5166926595573507837U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1918425684273807598U;
            aOrbiterK = RotL64((aOrbiterK * 16616641579714896719U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4724551751012661440U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1818014487579644390U;
            aOrbiterA = RotL64((aOrbiterA * 14904092108647864911U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 6670090372241084216U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 8485757110007268693U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 11876760095108618363U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4928130251509514742U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2528788422725346792U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1855982047967756661U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2860387120895147503U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12927802338151379368U;
            aOrbiterB = RotL64((aOrbiterB * 8876144125458603029U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 18029699867733207083U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13361836994951253312U;
            aOrbiterC = RotL64((aOrbiterC * 5349767426256597073U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11957294454794128079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3755417922063414648U;
            aOrbiterD = RotL64((aOrbiterD * 13896364063651241401U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 21U)) + aOrbiterD) + aNonceWordD);
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterG, 35U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 23U)) + aNonceWordA) + aPhaseHWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterC, 3U));
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 27U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22955U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 22843U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 22144U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24382U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24369U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 20U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (aWandererC + RotL64(aCross, 43U)) + 6381335981879993247U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 50U)) + 15595429101600023172U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 5449234297249826461U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 11213734849329731168U) + aNonceWordK;
            aOrbiterB = ((((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 16438473952464514248U) + aPhaseHOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 21U)) + 7357872882115186976U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 29U)) + 394402075160738643U) + aPhaseHOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11112941985410283532U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 14955125011182736212U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 10711684773326395603U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14770727009821304070U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11286366598129204910U;
            aOrbiterB = RotL64((aOrbiterB * 15884310771003021989U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7358400908565425780U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 15635109923749114761U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 12415152149408700329U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13826842523738623579U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1072811298828325231U;
            aOrbiterD = RotL64((aOrbiterD * 9662800288646215083U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4017334196009350776U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8812213572751410831U;
            aOrbiterC = RotL64((aOrbiterC * 12744171921566782795U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6723457786170634403U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9785583533999417673U;
            aOrbiterF = RotL64((aOrbiterF * 7776915427605471097U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10265132640322153964U) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8435670887514808087U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2706263045620662131U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 39U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 21U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + aNonceWordO) + aPhaseHWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 14U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 40U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 40U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30387U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 31641U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 31204U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27672U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((aIndex + 31755U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 21U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 3U)) + 2974056819475622600U) + aNonceWordM;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 7345051759236356098U) + aNonceWordB;
            aOrbiterA = (aWandererK + RotL64(aIngress, 47U)) + 12738468816846628882U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 53U)) + 7694520596043297922U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 5530753590015084774U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 40U)) + 3776309161718383105U) + aNonceWordP;
            aOrbiterK = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 784780304358106404U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8999942326995036509U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5194986506064092779U;
            aOrbiterA = RotL64((aOrbiterA * 15070787038006135963U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7920040007459652762U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11311997270710107937U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6227571709361790209U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5365231114813547251U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8630110234623825263U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2735881715888325759U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2358235238039571072U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 18059414891616491807U;
            aOrbiterD = RotL64((aOrbiterD * 17150786106857185467U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14526050556461782864U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6937282036603272474U;
            aOrbiterF = RotL64((aOrbiterF * 14954512365270028029U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10105832250694931310U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3884223553012098137U;
            aOrbiterI = RotL64((aOrbiterI * 16340956813003906195U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10385284339549648087U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1257633893341505930U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2669950791270500977U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 54U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + aPhaseHWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterF, 60U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterF, 3U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 5U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterC) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Hockey_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1705U)) & W_KEY1], 46U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 811U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2421U)) & W_KEY1], 54U) ^ RotL64(mSource[((aIndex + 1126U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 34U)) + RotL64(aCarry, 11U)) + 12849591986267890852U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 8232614804696815750U;
            aOrbiterI = (aWandererC + RotL64(aCross, 23U)) + 12141567259210877281U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 47U)) + 2928641981037885644U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 41U)) + 980733350554783938U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 18U)) + 2683985177993350746U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 5U)) + 14532148403815527355U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 27U)) + 7736296629433884203U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 10428437770166310549U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18327174144859461029U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6810436935194432002U;
            aOrbiterI = RotL64((aOrbiterI * 2715987179577753597U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12606153309690753435U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17123256945895150555U;
            aOrbiterF = RotL64((aOrbiterF * 13469111258504672565U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9057777759026189541U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16478485918911194442U;
            aOrbiterD = RotL64((aOrbiterD * 11054247078884894131U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18064460487552100483U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11477276762421684083U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3886501230380184395U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18318375441973295081U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13849305985380030986U;
            aOrbiterG = RotL64((aOrbiterG * 12962140243967824959U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10240409420338313641U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18360586077779529086U;
            aOrbiterK = RotL64((aOrbiterK * 18196875422391501927U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16801797158622424257U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4950305991208513887U;
            aOrbiterB = RotL64((aOrbiterB * 4437082499761416951U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15790878572843321918U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9808781805065559728U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9394280083159162953U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11974996650410830731U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4955004489435232515U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13301966529515483085U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterB, 11U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 34U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterC, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 51U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 56U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 46U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4815U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[((aIndex + 4561U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4924U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3692U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 29U)) + (RotL64(aPrevious, 12U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererC + RotL64(aCross, 57U)) + 2915859148137000694U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 3U)) + 210680583721444425U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 29U)) + 6668118118775650387U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 42U)) + 15794200818099010989U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 6565076707062828369U) + aPhaseAOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 19U)) + 16323164497808856719U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 7965435318816716560U) + aPhaseAOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 38U)) + RotL64(aCarry, 19U)) + 7390281030573369017U;
            aOrbiterC = (aWandererG + RotL64(aCross, 13U)) + 2269738866911824875U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9664014216039993873U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 18284857398028357633U;
            aOrbiterI = RotL64((aOrbiterI * 8402008251343393737U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 367667619795303009U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7935945060956274197U;
            aOrbiterJ = RotL64((aOrbiterJ * 5481786693511955209U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16683666162337789540U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10655658270998102390U;
            aOrbiterA = RotL64((aOrbiterA * 15231596813382239841U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8307037916581540297U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3247742749860703524U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15052136713218656641U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10446792483683818139U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16374602929344972364U;
            aOrbiterG = RotL64((aOrbiterG * 12599903932725787599U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2411334498322777183U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1093701164116833765U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13129220206835381729U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17018480952982840635U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17348395690080029814U;
            aOrbiterE = RotL64((aOrbiterE * 6212591395713433257U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16111252311283623152U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12776492920397785951U;
            aOrbiterH = RotL64((aOrbiterH * 6136009241593081821U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12214538600808144816U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10043377462096783363U;
            aOrbiterK = RotL64((aOrbiterK * 14639467375095185877U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 36U) + aOrbiterG) + RotL64(aOrbiterA, 43U)) + aPhaseAWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 30U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterE, 51U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 52U) + RotL64(aOrbiterK, 12U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 57U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7768U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadB[((aIndex + 6128U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7403U)) & W_KEY1], 50U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6596U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6796U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 38U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 4U)) + 15383045568644941552U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 17452811657750910067U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 37U)) + 15660117718455155603U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 10396441207743665753U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 3708971058200841442U) + aPhaseAOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 53U)) + 7000673057768598750U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 43U)) + 9886354469011131596U) + aPhaseAOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 60U)) + 16018065329058043467U;
            aOrbiterE = (aWandererH + RotL64(aCross, 47U)) + 5024756166109352320U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6587818720728886652U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3652672354944162319U;
            aOrbiterD = RotL64((aOrbiterD * 10807121230791716109U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6307315649915348048U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16405347331742979258U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7183142442906743699U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5427299664054601957U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4983381733483185898U;
            aOrbiterK = RotL64((aOrbiterK * 14646556236306407673U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10182995521328377487U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8694282877540593550U;
            aOrbiterE = RotL64((aOrbiterE * 14614602561910403893U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4085927978153269932U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6176195962815240877U;
            aOrbiterC = RotL64((aOrbiterC * 16792916528959579875U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6966742100601433005U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9920952446921247521U;
            aOrbiterB = RotL64((aOrbiterB * 1879821050131820933U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11958734477518336014U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 2058335903640404380U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6986170159285417789U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 77366119537297816U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12072894199692855000U;
            aOrbiterA = RotL64((aOrbiterA * 9083781120514635987U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11874297832446385377U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13715562531763053196U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12822488258322963187U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 52U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterD, 14U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterI, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterE, 53U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterB, 57U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 6U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 52U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9635U)) & S_BLOCK1], 44U) ^ RotL64(aKeyRowReadB[((aIndex + 9996U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(mSource[((aIndex + 8836U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((aIndex + 10363U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9554U)) & W_KEY1], 11U) ^ RotL64(aFireLaneB[((aIndex + 10673U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 14U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererD + RotL64(aPrevious, 52U)) + 13499155707765393469U;
            aOrbiterG = (aWandererH + RotL64(aCross, 43U)) + 3740324981823726185U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 5470765363949735652U) + aPhaseBOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 19U)) + 3446436171274452326U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 4U)) + 1778929412631211933U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 14666308799855220954U;
            aOrbiterB = (aWandererA + RotL64(aCross, 37U)) + 4548410236791175055U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 5829739767694190372U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 23U)) + 14319231414903675748U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1513851750246111405U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1685620217748986019U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9286548037413609445U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16284162182006054402U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6271539598462003309U;
            aOrbiterE = RotL64((aOrbiterE * 13923286694131331137U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12669312437565969473U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11894755313393001665U;
            aOrbiterA = RotL64((aOrbiterA * 12556759675372354075U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6315983824634946566U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17106616474222892782U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 167205520766791073U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13350266700180455548U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4608846311203767162U;
            aOrbiterG = RotL64((aOrbiterG * 2504857468837437365U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14195866746143604365U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7917977448256795054U;
            aOrbiterJ = RotL64((aOrbiterJ * 5927771378657284557U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10707336923305131629U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17122696159336995392U;
            aOrbiterK = RotL64((aOrbiterK * 13953518568670659191U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5182322763573586116U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6503754948502556246U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14749002194140663519U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14907832047832987341U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6258064448676621346U;
            aOrbiterH = RotL64((aOrbiterH * 4407960312705621487U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterC, 40U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 50U)) + aOrbiterB) + aPhaseBWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 27U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + aPhaseBWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 42U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 10U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererC, 52U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 13058U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 13156U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 10951U)) & W_KEY1], 36U) ^ RotL64(mSource[((aIndex + 13005U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11572U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12898U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneC[((aIndex + 11962U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 48U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 58U)) + 13915875634607599122U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 37U)) + 1695770381382411673U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 41U)) + 3709105579778295511U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 7673376335333251804U) + aPhaseBOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 30U)) + RotL64(aCarry, 57U)) + 8814147709738503518U;
            aOrbiterC = (aWandererE + RotL64(aCross, 13U)) + 13451412605350381172U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 3U)) + 6447870234069609538U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 13419487997946496825U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 47U)) + 5478309847615220345U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3635184969215610049U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12527903812035294828U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12540800512035534967U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1684685110885338814U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12860354576326835090U;
            aOrbiterG = RotL64((aOrbiterG * 12743745087733307255U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9081823570147481835U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 14369321778210049109U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17865953349448767035U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11518132079084873250U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11893535026126957389U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15751374986135615095U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7084079180579206226U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2999676609847603277U;
            aOrbiterE = RotL64((aOrbiterE * 14602698397511266403U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17683445810614029153U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11576460512964896969U;
            aOrbiterD = RotL64((aOrbiterD * 5243651036457051155U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13429800604736567949U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14661785761747367546U;
            aOrbiterF = RotL64((aOrbiterF * 4765843989277333421U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12837164345582888950U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6222666313184669392U;
            aOrbiterK = RotL64((aOrbiterK * 17402483466567712319U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5358647039491079457U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12459911673401497180U;
            aOrbiterC = RotL64((aOrbiterC * 13605465035256188065U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 4U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterK, 53U));
            aWandererF = aWandererF + ((RotL64(aScatter, 4U) + aOrbiterI) + RotL64(aOrbiterA, 39U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 48U)) + aOrbiterH) + aPhaseBWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterE, 35U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterK, 21U));
            aWandererC = aWandererC + (((RotL64(aIngress, 28U) + RotL64(aOrbiterI, 58U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 13993U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13966U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13749U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14246U)) & W_KEY1], 42U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15592U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13709U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 14843U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 2571116506511057880U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 30U)) + 13112435411509707292U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 10403251762787357256U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 8461951095541400405U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 3U)) + 9890793478557463815U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 23U)) + 3030229465991783707U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 51U)) + 7273848154043719247U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 47U)) + 10681774862516028276U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 60U)) + 7105082755586853104U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6588579345319551129U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14616333550242386092U;
            aOrbiterD = RotL64((aOrbiterD * 2934574715879306337U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15439666290229654921U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3360304356760164799U;
            aOrbiterG = RotL64((aOrbiterG * 5164191920584106237U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14438730801970761889U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14515616787452085729U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2041601927968559821U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4167853822635132419U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8950982233003320239U;
            aOrbiterK = RotL64((aOrbiterK * 887144270884244907U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12391327853728029953U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7100871010552394421U;
            aOrbiterI = RotL64((aOrbiterI * 16552349374101955967U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15381697462381887944U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6801677551341079401U;
            aOrbiterJ = RotL64((aOrbiterJ * 13325954438427340703U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 947011315719204867U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6356920162398333481U;
            aOrbiterB = RotL64((aOrbiterB * 5566721941682667419U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8910262020598577378U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8778455415977526457U;
            aOrbiterC = RotL64((aOrbiterC * 4092470497616637283U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5585696961453127223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9670655481681494412U;
            aOrbiterF = RotL64((aOrbiterF * 7863197168965036383U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterD, 50U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterI, 37U));
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterC, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 46U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 11U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 42U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17338U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 17241U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(mSource[((aIndex + 18922U)) & S_BLOCK1], 50U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18507U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16860U)) & W_KEY1], 27U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16593U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16407U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 4U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererJ + RotL64(aIngress, 53U)) + 12262991801139086177U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 7963038771924890197U) + aPhaseCOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 37U)) + 15540520327933568896U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 5U)) + 8745565892055020722U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 10U)) + 16619329199683755286U;
            aOrbiterC = (aWandererE + RotL64(aCross, 19U)) + 10865705026433867260U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 2743368697984518059U) + aPhaseCOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 43U)) + 5556006271515473135U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 3U)) + 5355833281353498588U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8313616108963479829U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16657121016801866434U;
            aOrbiterK = RotL64((aOrbiterK * 331533349428472477U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16532226425013000833U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5800465874932467232U;
            aOrbiterC = RotL64((aOrbiterC * 5966395771690704577U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17882948163883121328U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15029375310296563175U;
            aOrbiterJ = RotL64((aOrbiterJ * 17021415832288477713U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10170682648007918739U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11829089574189398773U;
            aOrbiterG = RotL64((aOrbiterG * 15755874363488568849U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 1746524867389196322U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10217423427886742775U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9166162099575333519U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1338457710729082656U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1319981417675542556U;
            aOrbiterI = RotL64((aOrbiterI * 9518448254565489715U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3985281993069194761U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7281264481139915593U;
            aOrbiterH = RotL64((aOrbiterH * 13498446162967276739U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17394503335338855566U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1430703546991948227U;
            aOrbiterA = RotL64((aOrbiterA * 1623206122475721175U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 472559435062214929U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8065899137826178995U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13287499768933229539U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 6U) + RotL64(aOrbiterC, 30U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterF, 11U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 43U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 34U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19267U)) & S_BLOCK1], 36U) ^ RotL64(mSource[((aIndex + 20436U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 21808U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21275U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21166U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21487U)) & W_KEY1], 19U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20862U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 20651U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 23U)) + (RotL64(aPrevious, 50U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 43U)) + 9855743441035905047U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 8426286937143990276U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 7146752367170267002U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 58U)) + RotL64(aCarry, 29U)) + 12947210066678101726U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 23U)) + 15902163559925328965U) + aPhaseCOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 13U)) + 8506649889346449469U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 47U)) + 8226286036430263052U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 54U)) + 2703047093452420216U;
            aOrbiterD = (aWandererF + RotL64(aCross, 35U)) + 6769351326360139560U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9857025533281333281U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 238297452132277585U;
            aOrbiterK = RotL64((aOrbiterK * 12974709749856065985U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7203572312072908931U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12497027346166575632U;
            aOrbiterH = RotL64((aOrbiterH * 1703586436725662307U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 473851890609048879U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1664484956453886047U;
            aOrbiterJ = RotL64((aOrbiterJ * 8566500756326590209U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4635095143004754116U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17695676150967345793U;
            aOrbiterF = RotL64((aOrbiterF * 5780416541584439301U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 15628965269863402796U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9190117464399730235U;
            aOrbiterA = RotL64((aOrbiterA * 5586437438425999715U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17835918238346011086U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4398005402429282682U;
            aOrbiterG = RotL64((aOrbiterG * 14828737209913317463U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10902589938246551273U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15124274429081385923U;
            aOrbiterD = RotL64((aOrbiterD * 13524180348258805367U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8747233520702236018U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5445611443463112371U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10294109295823410447U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16296005217836151910U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6468336224317602364U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7369779919748367133U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 4U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 58U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterA, 51U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 4U) + aOrbiterC) + RotL64(aOrbiterF, 43U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 28U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 23U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aScatter, 12U) + aOrbiterF) + RotL64(aOrbiterG, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23861U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 22782U)) & W_KEY1], 18U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22913U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 23241U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24370U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23073U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22190U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 22035U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 13U)) + 10336802574069791273U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 42U)) + RotL64(aCarry, 57U)) + 169025388197058936U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 6541354188379168846U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 47U)) + 16223920526599306104U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aPrevious, 21U)) + 12756613707692514808U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 60U)) + 5082475548176484035U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 4907435526952698526U) + aPhaseCOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aCross, 27U)) + 14236627073831834337U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 11502511046130497584U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3679044835550219497U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11254838916686736746U;
            aOrbiterC = RotL64((aOrbiterC * 8631695922983532915U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10582608424233200966U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10449735026385340313U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7363770199734997411U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4628253464169957835U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17664454668473204465U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4234720298731378527U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3798386391743884889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1379331161819246587U;
            aOrbiterA = RotL64((aOrbiterA * 13086160171095077295U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9816600392407327227U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16781971616348376878U;
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4807797577690520554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2492057261148595922U;
            aOrbiterF = RotL64((aOrbiterF * 9453302540675483005U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7909676419643119585U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 256053568910383007U;
            aOrbiterK = RotL64((aOrbiterK * 11965085163352053161U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16179914439220412472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3968867762761955845U;
            aOrbiterE = RotL64((aOrbiterE * 7473632378251893139U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7474832923901283742U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4736994731050735779U;
            aOrbiterI = RotL64((aOrbiterI * 9839654409121414047U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 20U) + aOrbiterA) + RotL64(aOrbiterB, 53U));
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 44U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterC) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 26U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 19U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterE, 39U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25108U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 24881U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25563U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27078U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25218U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24620U)) & S_BLOCK1], 58U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26321U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 25745U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 60U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 15036852811491820366U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 58U)) + 305637140752898475U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 11948631574496129610U) + aPhaseDOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 5321623592482991426U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 23U)) + 4075270159062690728U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 19U)) + 15111580500356908928U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 43U)) + 7244150695504160363U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 27U)) + 5131563519577488862U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 12U)) + 5881954992088651371U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12780935808751507998U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12599159643925470226U;
            aOrbiterA = RotL64((aOrbiterA * 17690046932587062701U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9466589929741834066U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6093158735705189789U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17461243886150519249U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15456408913739900718U;
            aOrbiterH = RotL64((aOrbiterH * 16093292401746174671U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11260643903290392780U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7870342756041882616U;
            aOrbiterE = RotL64((aOrbiterE * 2431528656086173419U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 134484990005888936U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10626896209992890407U;
            aOrbiterK = RotL64((aOrbiterK * 12034131076645285597U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14031164129515132292U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1771835705730244212U;
            aOrbiterG = RotL64((aOrbiterG * 186981668443596623U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16395472745067254664U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1455944290845294254U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6757824754363319079U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17866422769075350837U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10226884082632410805U;
            aOrbiterF = RotL64((aOrbiterF * 206035536985843815U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14474587247775371703U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8501763445324525303U;
            aOrbiterC = RotL64((aOrbiterC * 5298694643596784007U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 18U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterG, 39U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 58U)) + aOrbiterK) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterF, 35U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterE, 3U));
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterB, 46U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27471U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 28711U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27472U)) & W_KEY1], 12U) ^ RotL64(aWorkLaneC[((aIndex + 28945U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27518U)) & W_KEY1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27727U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28619U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28199U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 54U)) + (RotL64(aCarry, 3U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererD + RotL64(aPrevious, 19U)) + 12029393034357490020U;
            aOrbiterG = (aWandererH + RotL64(aCross, 3U)) + 4526754731580694987U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 27U)) + 17060419646421271853U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 60U)) + 4128488893837059683U) + aPhaseDOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 11U)) + 12706894827547160110U;
            aOrbiterD = (aWandererC + RotL64(aCross, 41U)) + 12506324593645825056U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 12581344490649250025U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 54U)) + RotL64(aCarry, 23U)) + 14357032418199130132U) + aPhaseDOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 15341977701796331249U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7086602307544733241U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12398300065276832486U;
            aOrbiterK = RotL64((aOrbiterK * 18157408831225635333U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2499745046076601988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7249361592814001829U;
            aOrbiterI = RotL64((aOrbiterI * 14597139848072319685U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3254456186337366437U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3472973415969046680U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14583566953969168353U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7905718972111691591U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15941413652144021522U;
            aOrbiterA = RotL64((aOrbiterA * 3473779492962783565U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10583964125960308762U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13659925272340853715U;
            aOrbiterG = RotL64((aOrbiterG * 16708294803316630743U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9487054537489454887U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13287757570441887517U;
            aOrbiterD = RotL64((aOrbiterD * 17351439045329892107U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15279245465808571942U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12424999114621745879U;
            aOrbiterC = RotL64((aOrbiterC * 2274918760256527137U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13915392738892970475U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13797668053788805126U;
            aOrbiterE = RotL64((aOrbiterE * 13752161103680525317U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14344766585550401077U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13727554194373146727U;
            aOrbiterB = RotL64((aOrbiterB * 17164450431362670223U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 44U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterI, 58U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 47U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 27U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterF, 6U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterC, 11U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30898U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30308U)) & W_KEY1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32117U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31343U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31152U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadB[((aIndex + 32720U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 6U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 53U)) + 2177539223979303669U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 57U)) + 3962004686551521471U) + aPhaseDOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 14U)) + RotL64(aCarry, 13U)) + 8457602312617147662U;
            aOrbiterD = (aWandererK + RotL64(aCross, 47U)) + 18011802451816510632U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 39U)) + 9046101759168876832U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 35U)) + 11135620637431969597U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 15913029940697999701U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 41U)) + 16304193109948135982U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 5U)) + 13208892298820080981U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4182377898949419225U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13970137023071326151U;
            aOrbiterC = RotL64((aOrbiterC * 9075061559681739865U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8402396284835248583U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8859190834060657829U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13552418608113716117U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9760005337757990392U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14108277760135744897U;
            aOrbiterE = RotL64((aOrbiterE * 4474681104256093885U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12226316121949012350U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3456392186754113960U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8704729827929941215U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5004087958637038973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7176881295123125567U;
            aOrbiterA = RotL64((aOrbiterA * 15272157962928021009U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10889800478505074438U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13728832441482547824U;
            aOrbiterH = RotL64((aOrbiterH * 17588477761978646139U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17345665880706866772U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 301139993853297566U;
            aOrbiterG = RotL64((aOrbiterG * 5812445396758354505U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2061389844760610160U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13631862266139238355U;
            aOrbiterI = RotL64((aOrbiterI * 143613352104722701U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10767186080827509622U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 4893486019456886013U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5194746459545610901U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 6U) + aOrbiterC) + RotL64(aOrbiterI, 12U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 56U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 26U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 40U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Hockey_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4707U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 6770U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7081U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3498U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5888U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7522U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 36U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 11177787645248006236U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 3808340254579817169U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 828030667598518279U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 60U)) + 16177835921238398371U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 51U)) + 5518747735458708741U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 21U)) + 17346319082399995165U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 5U)) + 6397156921893030937U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15559381654710713582U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 940404446491415088U;
            aOrbiterE = RotL64((aOrbiterE * 16401260971303026881U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8047166032048732645U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4688468645859470491U;
            aOrbiterG = RotL64((aOrbiterG * 14383536431614496369U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3710878044770337260U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 116343189456629220U;
            aOrbiterH = RotL64((aOrbiterH * 5637725064169289339U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 883908030159391659U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 18058691521694880482U;
            aOrbiterJ = RotL64((aOrbiterJ * 3132200449123497619U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17521015077103586117U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3668332225435714918U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12658899101297839881U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12229480388278883300U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16206524049491531816U;
            aOrbiterD = RotL64((aOrbiterD * 11122340196620859805U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5743265849441077466U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2812293020719282236U;
            aOrbiterK = RotL64((aOrbiterK * 8903956475200417109U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 28U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 34U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + aPhaseEWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 12U) + aOrbiterE) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9278U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 13782U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 11825U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((aIndex + 9934U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11430U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15368U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10134U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 28U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererI + RotL64(aPrevious, 47U)) + 1898718075389870739U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 5631794889237247403U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 18219714659484524607U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 21U)) + 15419581386225732921U) + aPhaseEOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 5U)) + 9125575431710198210U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 27U)) + 12205871520544965505U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 36U)) + RotL64(aCarry, 5U)) + 7617534300497343422U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18017579105368135814U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10693882161946020042U;
            aOrbiterH = RotL64((aOrbiterH * 2326507900303932855U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11669615701700895306U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11045110212889232165U;
            aOrbiterI = RotL64((aOrbiterI * 5965171269273719849U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18019107802806469913U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12315940560472528716U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4505122470351404065U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4899009736070044310U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17412253404253730364U;
            aOrbiterB = RotL64((aOrbiterB * 10791901166391946485U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4826286251927854181U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 4523455921321845084U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14534103906736598099U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4132514462154182215U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7164745605985109269U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14107325508977225261U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6297434295807635654U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8813887638672996646U;
            aOrbiterJ = RotL64((aOrbiterJ * 17495632530773158201U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 50U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterK, 60U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20331U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 18520U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 16709U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17927U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24522U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22859U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 22728U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 6U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererK + RotL64(aScatter, 35U)) + 5173905450211892891U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 11U)) + 3555542451908039957U;
            aOrbiterA = (aWandererI + RotL64(aCross, 26U)) + 11559884700283861559U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 1352524329968738673U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 8914206450420616349U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 43U)) + 2251523378498463946U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 9541575923299247038U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1239854507907214595U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17698101462598498934U;
            aOrbiterA = RotL64((aOrbiterA * 2304948713665996433U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12305566971683256060U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13804545036303215569U;
            aOrbiterI = RotL64((aOrbiterI * 10359543704152744971U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10239749097704329264U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4212214906286320308U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3661436621615751071U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12192418916967430783U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 4475514289326450361U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17497164630368757887U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17376102613298827459U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 18129393209955439341U;
            aOrbiterH = RotL64((aOrbiterH * 6404089025014118979U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4014763724300253568U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17325007199676828814U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1420888274815627083U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15480474849292388685U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14357924730184375449U;
            aOrbiterG = RotL64((aOrbiterG * 16723492259068034209U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 27U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterB, 4U)) + aPhaseEWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30239U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 30589U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 28129U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32587U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26217U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30551U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28699U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 34U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 3U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 3970829908171131502U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 7040283759419531991U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 13U)) + 11856292169397052901U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 35U)) + 819598588791819022U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 56U)) + 2176451710970866848U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 3U)) + 6454704928613390494U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 11792122387218053841U) + aPhaseEOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9254780213489752211U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16591812589999846482U;
            aOrbiterD = RotL64((aOrbiterD * 5425771603523423167U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1471246223935074832U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1424843083106386453U;
            aOrbiterK = RotL64((aOrbiterK * 15020536982657410783U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1856469958050891629U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6331743690452052712U;
            aOrbiterE = RotL64((aOrbiterE * 15327924647897459645U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10351075711345476487U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 9518585245330480185U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3792179827396760391U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17787514620244712033U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14182328067398162557U;
            aOrbiterA = RotL64((aOrbiterA * 18107337388659070197U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12798088948801072444U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9563215159275202323U;
            aOrbiterC = RotL64((aOrbiterC * 7058145016617349141U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9904919772580498232U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16579777394992143043U;
            aOrbiterF = RotL64((aOrbiterF * 10516761340320196661U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 50U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 21U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 51U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterE, 13U));
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterC, 57U)) + aPhaseEWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterF, 35U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 4U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 41U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Hockey_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7567U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 2758U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4016U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5693U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7874U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3749U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererA + RotL64(aIngress, 19U)) + 8975885703279267062U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 57U)) + 8664844915562660637U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 27U)) + 12281774799736296726U) + aPhaseFOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aCross, 41U)) + 15347461352311329726U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 53U)) + 12967500561828907834U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 43U)) + 5002833859280402726U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 3U)) + 11908257536954668983U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 51U)) + 17017174811949227162U;
            aOrbiterB = (aWandererI + RotL64(aCross, 23U)) + 16851323125613931180U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 38U)) + RotL64(aCarry, 11U)) + 13469326957728686706U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 5228638551056105241U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11945166198089308564U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16268645041872996022U;
            aOrbiterG = RotL64((aOrbiterG * 5391448793718370911U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14781204627695095701U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5365325354838101092U;
            aOrbiterD = RotL64((aOrbiterD * 8017284997946310807U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 563147416025715953U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14660867395395625851U;
            aOrbiterC = RotL64((aOrbiterC * 4769458126865307103U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3168989056355712105U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16179131669773665579U;
            aOrbiterI = RotL64((aOrbiterI * 5641461617066671723U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4160220074225527179U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8597134686962559111U;
            aOrbiterF = RotL64((aOrbiterF * 639572585431474015U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16811551552456811661U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5827323970423386301U;
            aOrbiterB = RotL64((aOrbiterB * 9328247349730652021U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15583234353262170227U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2950816254621717748U;
            aOrbiterA = RotL64((aOrbiterA * 1102417597476170143U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4426165025104306337U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11871220132164971152U;
            aOrbiterJ = RotL64((aOrbiterJ * 2366168050042802207U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3832424136113939717U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17673885217916768611U;
            aOrbiterK = RotL64((aOrbiterK * 10887063696370811871U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3479289844909914390U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9498461576098567546U;
            aOrbiterE = RotL64((aOrbiterE * 8734492074299676555U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10645314291190544864U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8975885703279267062U;
            aOrbiterH = RotL64((aOrbiterH * 16584086014947250551U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 37U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 51U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 52U) + aOrbiterB) + RotL64(aOrbiterA, 27U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterE, 19U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 58U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterH, 11U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterE, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterA, 56U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 24U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14102U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 9380U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13038U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12601U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14287U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15209U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15766U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererD + RotL64(aCross, 37U)) + 13714409587461539863U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 5U)) + 14101156723903265839U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 10U)) + 7063754562895369001U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 23U)) + 12320578575245519386U;
            aOrbiterC = (aWandererC + RotL64(aCross, 19U)) + 11744826789631008424U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 27U)) + 8744816505096675597U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 10405435520084528645U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 1463157688070683543U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 39U)) + 12379603577919617703U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aScatter, 46U)) + RotL64(aCarry, 11U)) + 1343439118031348146U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 13U)) + 16118850268070235540U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14116264435819277136U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5251698273012432109U;
            aOrbiterG = RotL64((aOrbiterG * 1495818611622063967U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14806408656041403829U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11569345414052398227U;
            aOrbiterC = RotL64((aOrbiterC * 9913158908301414861U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17063874769147888574U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9927420478679581917U;
            aOrbiterJ = RotL64((aOrbiterJ * 9042782809534196563U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 2550285599827162167U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17801534123304996448U;
            aOrbiterK = RotL64((aOrbiterK * 2160836889363614721U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6456685241021762041U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17064208177372969289U;
            aOrbiterI = RotL64((aOrbiterI * 13726627607233302493U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18279938244131982650U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8211002229712129419U;
            aOrbiterF = RotL64((aOrbiterF * 12931373380977640645U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12795832560781931767U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 286378504074349650U;
            aOrbiterD = RotL64((aOrbiterD * 85453101173293509U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5835304250436889513U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12704972686724379659U;
            aOrbiterB = RotL64((aOrbiterB * 1198789639656336053U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12555700587254295099U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6740149669657971715U;
            aOrbiterE = RotL64((aOrbiterE * 9376048577305482691U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1541392147096889431U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16891341703173286949U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 697452963711223355U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8811637585092392653U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13714409587461539863U;
            aOrbiterH = RotL64((aOrbiterH * 2578939920876994763U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 60U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 38U) + aOrbiterE) + RotL64(aOrbiterD, 5U));
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 50U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aCross, 36U) + RotL64(aOrbiterH, 13U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterF, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 39U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 37U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 42U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16767U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((aIndex + 24357U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 19447U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 18060U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21320U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21711U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18830U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 40U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 39U)) + 8866844335448071821U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 58U)) + 15159698739856430085U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 3U)) + 9582805772989594633U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 1438538239931588373U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 47U)) + 10862044156620436139U;
            aOrbiterE = (aWandererG + RotL64(aCross, 29U)) + 13682173320058164615U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 8351013291045977592U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aPrevious, 35U)) + 15777857431516633916U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 26U)) + 16178966745333885377U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 37U)) + 9031889187993001617U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 6308472367425865347U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 642109145903321046U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9186268569255318035U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10714674348507516749U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6091345356803675860U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13218507921880873749U;
            aOrbiterE = RotL64((aOrbiterE * 15415157927185637717U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4266652275234474616U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4391422098164506195U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17634679403195085867U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5160682323243635577U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10351728852161347404U;
            aOrbiterD = RotL64((aOrbiterD * 11105410036471745951U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3950932176454814023U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9536466386833427441U;
            aOrbiterK = RotL64((aOrbiterK * 18064984243491293435U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9927425919978776529U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6819384090527481081U;
            aOrbiterG = RotL64((aOrbiterG * 18032965969184368561U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1646274931424218507U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16166524473976135097U;
            aOrbiterJ = RotL64((aOrbiterJ * 11672192658072663849U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11252501968059485262U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16847854447987609067U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6326299154627028295U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16723218285355036446U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13870211254243048975U;
            aOrbiterH = RotL64((aOrbiterH * 10203222183774624097U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11401147367366049493U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4266628469244269926U;
            aOrbiterB = RotL64((aOrbiterB * 2409934496621365221U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11578385782347296942U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8866844335448071821U;
            aOrbiterI = RotL64((aOrbiterI * 6456956795450036515U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 54U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 21U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 41U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterK, 48U));
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29562U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 26846U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27910U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 29275U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28128U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30767U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25420U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 43U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererA + RotL64(aIngress, 39U)) + 3561491146322798260U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 57U)) + 7075025056181885339U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 20U)) + 9230910887904171613U;
            aOrbiterG = (aWandererC + RotL64(aCross, 53U)) + 4119781172609908917U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 17155609083870983149U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 3U)) + 2423018561430181695U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 11U)) + 12957280305617615744U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 2461704174772065813U;
            aOrbiterC = (aWandererE + RotL64(aCross, 29U)) + 7907123257849391997U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 7257868138318960007U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 6U)) + 16425903703085702285U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2990822664594079467U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5654819006718953817U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4465096036756887801U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12183676471235678779U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15026286960542123922U;
            aOrbiterD = RotL64((aOrbiterD * 17199049329995315279U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12169080607071830522U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2906296852254787499U;
            aOrbiterH = RotL64((aOrbiterH * 6754514406846040163U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3029858695410344584U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14406410317495954566U;
            aOrbiterC = RotL64((aOrbiterC * 9663780721657983421U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11048818178401163861U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13622063920319445043U;
            aOrbiterA = RotL64((aOrbiterA * 2516025554421589857U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 2642646089141233277U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12761571777929273548U;
            aOrbiterB = RotL64((aOrbiterB * 5518252696078700127U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7753802695131502382U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8510425459525030222U;
            aOrbiterK = RotL64((aOrbiterK * 12412361423636026483U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13522645164493316722U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1437430302489702713U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14019316635365783545U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14745189473423751499U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16968328257002103715U;
            aOrbiterF = RotL64((aOrbiterF * 17915588590593471981U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5001838243344386314U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13506188720092630563U;
            aOrbiterG = RotL64((aOrbiterG * 7010027510838271877U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16902624500530747723U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3561491146322798260U;
            aOrbiterE = RotL64((aOrbiterE * 95761172090277669U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 12U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterH, 24U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterC, 39U));
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 40U) + aOrbiterH) + RotL64(aOrbiterE, 53U));
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 14U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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

void TwistExpander_Hockey_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 852U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 5900U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1714U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6935U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5273U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1017U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 18U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 5088525177670191619U) + aPhaseGOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 13U)) + 9966456257813932112U) + aPhaseGOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 37U)) + 7707646574027146307U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 75480203757681173U;
            aOrbiterI = (aWandererE + RotL64(aCross, 47U)) + 384659134071835163U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3158769775373307778U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17360830943513941272U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9986023786908098621U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5317278822721604586U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1371427105215954781U;
            aOrbiterD = RotL64((aOrbiterD * 10956603063464438611U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3162710551223553423U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5332921933853550756U;
            aOrbiterG = RotL64((aOrbiterG * 11709546145149357887U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10572462410297815854U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10234389605554817892U;
            aOrbiterI = RotL64((aOrbiterI * 2130374833440291193U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13421365517991380605U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10186643614984034083U;
            aOrbiterA = RotL64((aOrbiterA * 8554471709467808453U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            aWandererI = aWandererI + ((((RotL64(aCross, 21U) + RotL64(aOrbiterD, 14U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 53U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterA, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 56U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9492U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 11315U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 16342U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11356U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10099U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15095U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 38U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 5295352595333316211U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 2341795367042042605U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 10122175780504033663U) + aPhaseGOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aIngress, 3U)) + 10084612804696198554U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 42U)) + 16470424309851045971U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 656016130975227994U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15313268829659834317U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3553315008401417123U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3795220914993923394U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14044442220988813825U;
            aOrbiterE = RotL64((aOrbiterE * 3270650852546606835U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3804224626734584802U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7980006306010255693U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13958505239726088561U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13746830564584711549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11852212099729274845U;
            aOrbiterK = RotL64((aOrbiterK * 2164880979318247855U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9083223471018084847U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 13706723820703853346U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11361854103656219887U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterK, 12U)) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterE, 47U)) + aPhaseGWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23579U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 23766U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 24186U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16682U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24558U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 23271U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 54U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererF + RotL64(aScatter, 27U)) + 14157904117287696136U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 7369512677371640676U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 8411250745902073798U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aIngress, 10U)) + RotL64(aCarry, 11U)) + 5002041814539710275U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 41U)) + 9538041410816283124U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5210700103927513061U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7600709399101287982U;
            aOrbiterK = RotL64((aOrbiterK * 6777896926889560889U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2366369466696580499U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5544575244203019109U;
            aOrbiterH = RotL64((aOrbiterH * 16231219246786333057U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8710073749110329779U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15998211310115361630U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15275657696897688955U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15354357553877376422U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10657523549259276169U;
            aOrbiterA = RotL64((aOrbiterA * 13695239532898311073U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10405750198355464768U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3465819693133515142U;
            aOrbiterB = RotL64((aOrbiterB * 14678343718277562799U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 14U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + RotL64(aOrbiterH, 50U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterB, 29U)) + aPhaseGWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 56U) + aOrbiterK) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25747U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 27614U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27634U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27668U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25821U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 27769U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 38U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 39U)) + 1557680213571812384U) + aPhaseGOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 7387349725778021121U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 20U)) + 15379264067601586976U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 3730195724576043708U) + aPhaseGOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 9637070085323827066U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1170865717363676184U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2750833653175252030U;
            aOrbiterB = RotL64((aOrbiterB * 1937822982381882775U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15118992811225568305U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4974092922102988451U;
            aOrbiterF = RotL64((aOrbiterF * 10575977398702460975U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 10625719096296719514U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 855167122475471865U;
            aOrbiterA = RotL64((aOrbiterA * 7441090331293158773U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11322911068958340262U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4334591909425429835U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10059025861172038183U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 14263701737208936392U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 678723206735649084U;
            aOrbiterI = RotL64((aOrbiterI * 10823239851733632227U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 58U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 30U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterF, 5U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterA, 51U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 12U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Hockey_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0;

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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3506U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 5908U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 670U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3679U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7375U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3424U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 4U)) + 1393781663398437180U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 21U)) + 17414594746688585273U) + aPhaseHOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 2823888497053071250U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 17032631958617884859U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 15222697630461125019U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15737414920751551780U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1357196111055783001U;
            aOrbiterD = RotL64((aOrbiterD * 8225423829221938165U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5315122321649251691U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7893744655508595974U;
            aOrbiterG = RotL64((aOrbiterG * 17863000246694319149U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16721939414324611738U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3444375866323610848U;
            aOrbiterJ = RotL64((aOrbiterJ * 10874157227815775661U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1825716513674511632U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15582066843912467318U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12765146555943757373U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15673590949193923915U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13887365046280406413U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3169061375011420121U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 29U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 37U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 46U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 13U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13995U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 16161U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 9812U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15697U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9774U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15832U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 56U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aCross, 43U)) + 1557680213571812384U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 27U)) + 7387349725778021121U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 15379264067601586976U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 52U)) + RotL64(aCarry, 21U)) + 3730195724576043708U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 9637070085323827066U) + aPhaseHOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1170865717363676184U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2750833653175252030U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1937822982381882775U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15118992811225568305U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4974092922102988451U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10575977398702460975U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10625719096296719514U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 855167122475471865U;
            aOrbiterF = RotL64((aOrbiterF * 7441090331293158773U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11322911068958340262U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4334591909425429835U;
            aOrbiterH = RotL64((aOrbiterH * 10059025861172038183U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14263701737208936392U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 678723206735649084U;
            aOrbiterJ = RotL64((aOrbiterJ * 10823239851733632227U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterD, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 39U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + aPhaseHWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 24U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22384U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 21848U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 21825U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19427U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18604U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 21008U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 14U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 7825479804710770560U) + aPhaseHOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 5298124167101358123U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 56U)) + RotL64(aCarry, 19U)) + 17774541024369233726U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 13U)) + 7679371833537454082U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 27U)) + 5385914900748772224U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3879781930908486531U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 659110346638873236U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17439162088869824407U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10749021728538539749U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3631252455767429457U;
            aOrbiterB = RotL64((aOrbiterB * 8552825360915119613U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2271978810960685021U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5963558780692551176U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4772055335210781149U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 974909966119198104U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9296998242911152296U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2613629915877957661U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2245318466901521959U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13391076374843288568U;
            aOrbiterH = RotL64((aOrbiterH * 18094558036982107419U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterH, 3U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterE, 48U)) + aPhaseHWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 24984U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 31713U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 28861U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29270U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27040U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25841U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aCross, 27U)) + 479672811032092393U) + aPhaseHOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 18061121631394564425U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 13U)) + 14237400452740566065U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 4U)) + RotL64(aCarry, 5U)) + 6723123812257706134U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 4247997188026499248U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1939107415066134869U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3912640123546395979U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9779626695085572877U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8295478436553964298U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3218960600711526885U;
            aOrbiterI = RotL64((aOrbiterI * 15443507655470278069U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5874096203353388890U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10294536533673023358U;
            aOrbiterB = RotL64((aOrbiterB * 15561710414949058923U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11268561953904130747U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16693201256788898423U;
            aOrbiterF = RotL64((aOrbiterF * 16291987237693567209U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7550969634681894654U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 9501647424602245869U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11265865222096866605U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 28U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
