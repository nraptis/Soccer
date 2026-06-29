#include "TwistExpander_FootBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_FootBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF3AB6EEA6ADCA411ULL + 0x94C3EE369A397325ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE019D36C44AEAA27ULL + 0xD66C1FB237CA3564ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCB371E1B2CF9792DULL + 0x833706600770EA7DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAB8060B23033F985ULL + 0xE5315DD030FE60BDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8BE0FDD0D05FEE6BULL + 0xD84941C6E92C7518ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDA88C81107B193C3ULL + 0xD2621748AECB2643ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA444CDA5DF3E5F35ULL + 0x86CB20F603F2ECB7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCD91873904B52875ULL + 0x82A3FD8ED1BC48FFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC360421328C84103ULL + 0x873C8815AF15A0F8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x840B970F78DB752FULL + 0xE81CF1780340E373ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEF7AAF3F3EE9C383ULL + 0xC8FAECBCEA2F4AF1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xED9185D27E52BEABULL + 0xCF32A6057B584349ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAC1BD800533B994FULL + 0xE2BF7977D0A25FBEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEB9CB76F8CAA5589ULL + 0x97972169E717624BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCCC65BCAB7B4A2EDULL + 0xD48A87B10A7EA574ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA7E89C99C314A2F1ULL + 0x916E54B4DD56ECF7ULL);
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
            aIngress = RotL64(mSource[((aIndex + 3040U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((aIndex + 4034U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2256U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((aIndex + 1116U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (aWandererE + RotL64(aIngress, 27U)) + 7651355040951791298U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 51U)) + 13988210277931659312U;
            aOrbiterG = (aWandererD + RotL64(aCross, 13U)) + 9846849412579537783U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 37U)) + 12746719939495876158U) + aNonceWordF;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 21U)) + 11498066185182895284U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 11101058955193080232U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 3U)) + 15513734459555672046U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 5U)) + 15711108675349394643U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 4771231759949468556U) + aNonceWordK;
            aOrbiterH = (aWandererK + RotL64(aScatter, 47U)) + 11449258010811305256U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 34U)) + 17036938391509986723U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6999245666776654250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2106819066263369528U;
            aOrbiterG = RotL64((aOrbiterG * 13005885810757743129U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12716183358903477216U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16752724547046059889U;
            aOrbiterB = RotL64((aOrbiterB * 11475905692393034141U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17623077680983093163U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 6726003022297274986U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 14709385877103232653U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2842410225096524740U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9235178377537910514U;
            aOrbiterF = RotL64((aOrbiterF * 11813751114775673845U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2619888019860844610U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6295481948199619613U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15429161806953951205U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9724921158061115570U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4070976180958458679U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6080566609081811453U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5864247978960125554U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7771249710071026757U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 4787660062590737657U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15006900854988166845U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2755659268987119046U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8043939381186802359U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1922321482806966418U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13910818219761929659U;
            aOrbiterC = RotL64((aOrbiterC * 8895973123729951173U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7540972911473176026U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5419023469522423893U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1380429266266313945U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2349651834739320824U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7651355040951791298U;
            aOrbiterK = RotL64((aOrbiterK * 3713776056028698433U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 30U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 28U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + aNonceWordG);
            aWandererK = aWandererK + ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterB, 37U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 42U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 24U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterK, 53U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 14U)) + aOrbiterG) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterF, 27U));
            aWandererC = aWandererC + ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterK, 5U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 54U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 10154U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((aIndex + 6192U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7083U)) & S_BLOCK1], 24U) ^ RotL64(pSnow[((aIndex + 10031U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 40U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 35U)) + 6654158889644956636U) + aNonceWordL;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 9045779659363991870U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 41U)) + 3888897662136993491U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 50U)) + 6882016842864459345U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 19U)) + 15601891715956172291U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 23U)) + 5176811598629335350U) + aNonceWordB;
            aOrbiterC = (aWandererD + RotL64(aScatter, 5U)) + 12519945150889074325U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 4552583214397603278U) + aNonceWordO;
            aOrbiterH = (aWandererI + RotL64(aIngress, 21U)) + 14225482701804864688U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 26U)) + RotL64(aCarry, 29U)) + 5485298070606280363U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 57U)) + 11237713257388094289U) + aNonceWordC;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14340345895626142788U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16275167270553643347U;
            aOrbiterA = RotL64((aOrbiterA * 7308578867128951199U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14041860597556520250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1436068974197066343U;
            aOrbiterG = RotL64((aOrbiterG * 3938460345031496843U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 11483155566419547004U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4608508534724289325U;
            aOrbiterF = RotL64((aOrbiterF * 13461385011638899485U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2389196334288832895U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4062682330273866602U;
            aOrbiterK = RotL64((aOrbiterK * 8787682133271101901U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5655656046585592034U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7977947821249746880U;
            aOrbiterD = RotL64((aOrbiterD * 10082104644185964787U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11653718118543974168U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5456429682072377614U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12504180638665296649U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12457179652004203574U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 445821754230182952U;
            aOrbiterJ = RotL64((aOrbiterJ * 16043092621697786393U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12429505513284703263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12480745784412363537U;
            aOrbiterI = RotL64((aOrbiterI * 643617210585287593U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6952219750393303609U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13965647644550998416U;
            aOrbiterB = RotL64((aOrbiterB * 5395755018020115073U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 5602193483992512507U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 9593414134773695959U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2186313187456153775U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16469843418561148995U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6654158889644956636U;
            aOrbiterE = RotL64((aOrbiterE * 17490973872858383001U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 58U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterE, 10U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aNonceWordA) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 10U) + aOrbiterJ) + RotL64(aOrbiterB, 41U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + aNonceWordH);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 53U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 20U) + aOrbiterJ) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 39U)) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 60U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 15542U)) & S_BLOCK1], 46U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13364U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 12421U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16099U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 13U)) + (RotL64(aCarry, 29U) + RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 53U)) + 11177787645248006236U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 41U)) + 3808340254579817169U) + aNonceWordI;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 48U)) + 828030667598518279U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 16177835921238398371U) + aNonceWordK;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 5U)) + 5518747735458708741U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 39U)) + 17346319082399995165U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 6397156921893030937U) + aNonceWordC;
            aOrbiterB = (aWandererG + RotL64(aCross, 23U)) + 15559381654710713582U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 940404446491415088U;
            aOrbiterA = (aWandererK + RotL64(aCross, 27U)) + 8047166032048732645U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 46U)) + 4688468645859470491U) + aNonceWordL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3710878044770337260U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 116343189456629220U;
            aOrbiterJ = RotL64((aOrbiterJ * 5637725064169289339U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 883908030159391659U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 18058691521694880482U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3132200449123497619U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17521015077103586117U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3668332225435714918U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 12658899101297839881U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12229480388278883300U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16206524049491531816U;
            aOrbiterI = RotL64((aOrbiterI * 11122340196620859805U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5743265849441077466U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2812293020719282236U;
            aOrbiterA = RotL64((aOrbiterA * 8903956475200417109U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13718364781538837074U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 861529717259766236U;
            aOrbiterE = RotL64((aOrbiterE * 17019744777211266685U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4862687502126693872U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7722024283321020761U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18086944039541060829U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8205803118233399853U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15130160926615050422U;
            aOrbiterG = RotL64((aOrbiterG * 1454552751453996765U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 667469191899263617U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 18048970185163843471U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1800698970568737425U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 508102841337488721U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3803840516662727630U;
            aOrbiterH = RotL64((aOrbiterH * 8477778555284121637U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17055028117762299436U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11177787645248006236U;
            aOrbiterK = RotL64((aOrbiterK * 12457019014051206805U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 54U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 50U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + aNonceWordH) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 51U)) + aOrbiterB) + aNonceWordO);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 53U)) + aOrbiterH) + aNonceWordA);
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterJ, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterF, 44U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 47U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 20U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterC, 37U));
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 41U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 30U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 17908U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 20360U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 16391U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 20048U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 19372U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 10U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 5088525177670191619U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 9966456257813932112U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 30U)) + 7707646574027146307U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 43U)) + 75480203757681173U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 384659134071835163U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 23U)) + 3158769775373307778U) + aNonceWordB;
            aOrbiterK = (aWandererB + RotL64(aCross, 53U)) + 17360830943513941272U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 19U)) + 5317278822721604586U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 27U)) + 1371427105215954781U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aScatter, 58U)) + 3162710551223553423U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 3U)) + 5332921933853550756U) + aNonceWordL;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 10572462410297815854U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10234389605554817892U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2130374833440291193U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13421365517991380605U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 10186643614984034083U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8554471709467808453U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 4742438973260817120U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6081590345899008846U;
            aOrbiterD = RotL64((aOrbiterD * 7069396301823124931U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15360092808493795340U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12186413069553132646U;
            aOrbiterK = RotL64((aOrbiterK * 3815981440611914267U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16756221656224451552U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12232880965861373143U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 14196910735715726471U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10090954323470840557U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15615770271463853537U;
            aOrbiterF = RotL64((aOrbiterF * 13544181592829027283U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 556029032505658411U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13311879111583579039U;
            aOrbiterA = RotL64((aOrbiterA * 3924744868168749003U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8646360871497847336U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2064833941982069154U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 10016546852137913163U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1701847261278886621U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9654208200019718374U;
            aOrbiterE = RotL64((aOrbiterE * 4398089490129603677U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14276143262844412074U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10738184916176200661U;
            aOrbiterJ = RotL64((aOrbiterJ * 8940267914440361883U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2966052720680305600U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5088525177670191619U;
            aOrbiterH = RotL64((aOrbiterH * 11621585388684456139U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 60U)) + aOrbiterB) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 37U));
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterG, 43U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterG, 5U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 44U) + aOrbiterD) + RotL64(aOrbiterH, 14U)) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 47U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 21961U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 25351U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25367U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((aIndex + 24531U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27030U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 22759U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (aWandererA + RotL64(aPrevious, 57U)) + 4634399531433127141U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 10U)) + RotL64(aCarry, 37U)) + 16961792729406903200U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 35U)) + 4105280732301137738U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 15692013501147331191U) + aNonceWordE;
            aOrbiterE = (aWandererH + RotL64(aCross, 3U)) + 1252216715968780587U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 37U)) + 7958289043012473752U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 29U)) + 6611577301818896615U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 24U)) + 8506226754305949140U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aWandererB + RotL64(aScatter, 13U)) + 3648813120449403353U;
            aOrbiterA = (aWandererG + RotL64(aCross, 51U)) + 5195245426245535735U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 542948051600803051U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11974253551208964789U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10596463592332655367U;
            aOrbiterI = RotL64((aOrbiterI * 10941161258815714641U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12015129484061440159U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8254944355710109060U;
            aOrbiterJ = RotL64((aOrbiterJ * 3233697992479357615U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2754858806943915419U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5007802002906662779U;
            aOrbiterH = RotL64((aOrbiterH * 15613733948331639723U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 6262190752136523216U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10528977986487821428U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 1184258264034585525U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8511097226098211854U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12091864735686692582U;
            aOrbiterA = RotL64((aOrbiterA * 6128140528141411237U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4970966265236842566U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10728884018459718341U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18205183219769602827U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13760057185629905360U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6590269178744829056U;
            aOrbiterK = RotL64((aOrbiterK * 14482684769712170123U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 765826377665103262U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9364759196106579706U;
            aOrbiterB = RotL64((aOrbiterB * 10315111163659289329U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4629303338428087146U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15107221579712215172U;
            aOrbiterE = RotL64((aOrbiterE * 14410837138199304663U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9407987092859067074U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13589362515507116096U;
            aOrbiterG = RotL64((aOrbiterG * 4544198075069052713U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 2236921538387014026U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4634399531433127141U;
            aOrbiterF = RotL64((aOrbiterF * 13132011613143486575U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 3U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 60U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 27U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aIngress, 58U) + aOrbiterJ) + RotL64(aOrbiterI, 37U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + aNonceWordM) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 39U) + RotL64(aOrbiterC, 22U)) + aOrbiterA) + aNonceWordO) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 28786U)) & S_BLOCK1], 58U) ^ RotL64(pSnow[((aIndex + 27688U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30742U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 32103U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31960U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31660U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 43U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 30U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 35U)) + 13687218104610230596U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 3U)) + 6841550124960692709U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 5U)) + 17418968668458764131U) + aNonceWordG;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 54U)) + RotL64(aCarry, 39U)) + 8303537912696948204U;
            aOrbiterD = (aWandererI + RotL64(aCross, 47U)) + 12376614417285936537U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 11U)) + 14215749063579232654U) + aNonceWordP;
            aOrbiterA = (aWandererK + RotL64(aScatter, 19U)) + 4111736931433665347U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 37U)) + 11250375934571631522U) + aNonceWordJ;
            aOrbiterB = (aWandererC + RotL64(aScatter, 21U)) + 5367367837773331275U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 14U)) + RotL64(aCarry, 35U)) + 15514089192382674434U) + aNonceWordO;
            aOrbiterC = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 1475991716685034960U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 5531622777788629748U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8363822215908303335U;
            aOrbiterK = RotL64((aOrbiterK * 17850203366840994883U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3741256932685720414U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11634667238062155772U;
            aOrbiterD = RotL64((aOrbiterD * 15925089729784547403U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18180546911210417155U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5123234656838556335U;
            aOrbiterE = RotL64((aOrbiterE * 15362857462853398025U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11215734271189250284U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16863747802158398092U;
            aOrbiterJ = RotL64((aOrbiterJ * 1828035970246160023U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9859050606636646323U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9331300036643654675U;
            aOrbiterI = RotL64((aOrbiterI * 2502263410556166281U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15028845665427209759U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8916444839488901676U;
            aOrbiterG = RotL64((aOrbiterG * 6646561894156038791U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8024631140949068570U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1116378858490660031U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4247798531910227367U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5066486214537899212U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9346312092322423057U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 13443190089768875191U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11651011617027950122U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11308862427412671711U;
            aOrbiterH = RotL64((aOrbiterH * 12167147966934334703U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3850136281462840708U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13461307727665667424U;
            aOrbiterA = RotL64((aOrbiterA * 10788040812090673421U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17824744996404571928U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 13687218104610230596U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 325803029547254631U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterC, 37U)) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterD, 48U));
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterJ, 19U)) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 24U) + aOrbiterD) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 53U)) + aOrbiterF) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterH, 22U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_FootBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x90F59097E8A9C1CBULL + 0xA2D756E6364047A6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x820AF43BC9FA5997ULL + 0x86E961BD718DADEFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA1220D9538AABF0FULL + 0xE56F436A594FDE8DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE08C909BA87B23DFULL + 0xAA648AA49281B4ABULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x83F6886E9C17DBDDULL + 0x95936A1A364FD51AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD44DC779E416A62DULL + 0xEBCF404B7C1B53CBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB14ACC61569C0771ULL + 0x8CFB8FDE893B821AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC2ED31E23D4765E7ULL + 0xC48CADF819AC8B37ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9382CBFD205E3375ULL + 0xBA1747FDC1674A22ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x84E8B6486BE0E6BDULL + 0xE10556963369A472ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFDA8D3EBEC61561BULL + 0xD823567F8BFEF692ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA9ADB23F391A5485ULL + 0x93A5AA9A2D9F3F2FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCD10CD27ADB8C323ULL + 0xEE6F9DD0B2F89E05ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB9AC0F0FDF4CFCD7ULL + 0xEBE21F1181F209B0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC49C9873373B1E75ULL + 0xA06599C05AC1ADD7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC2EB0C63EB9C5877ULL + 0xCA861644F9330E4CULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3341U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneB[((aIndex + 5947U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 388U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7079U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 42U)) ^ (RotL64(aIngress, 29U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererF + RotL64(aIngress, 34U)) + RotL64(aCarry, 29U)) + 10038936806177516123U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 51U)) + 1773168435195292638U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aCross, 23U)) + 10655711161526628072U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 39U)) + 14422295664639740437U) + aNonceWordG;
            aOrbiterI = (aWandererH + RotL64(aCross, 3U)) + 4125228715513159576U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 13U)) + 3670449653158650845U) + aNonceWordI;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 17553727567180813057U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 28U)) + RotL64(aCarry, 37U)) + 5111401772713882743U) + aNonceWordC;
            aOrbiterA = (aWandererE + RotL64(aCross, 19U)) + 7688573124662314413U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9438375825507814395U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 14177477039902118886U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 6467406626985022537U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16329942595859623928U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3990536794006836672U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 579024714339065373U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5072881436583180756U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16789727877867289997U;
            aOrbiterK = RotL64((aOrbiterK * 8766246302636197905U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17313956922306689438U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11530878396329822041U;
            aOrbiterJ = RotL64((aOrbiterJ * 11356860047841383129U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3612616532321160196U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4172189825359187763U;
            aOrbiterB = RotL64((aOrbiterB * 12938945495299393177U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8677279703778052804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1912172980909479362U;
            aOrbiterD = RotL64((aOrbiterD * 10053289257955474143U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1460085850227494500U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12116763868122868147U;
            aOrbiterA = RotL64((aOrbiterA * 6076945628020280957U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17571840610366424432U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15581362592611080868U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1129054058044872003U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14434700039977611666U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4534294602623329152U;
            aOrbiterF = RotL64((aOrbiterF * 5860911553425182045U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + aNonceWordM);
            aWandererH = aWandererH + ((((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterC, 18U)) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterD, 57U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterK) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterF, 51U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 3U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterI, 12U)) + aOrbiterD) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererE, 40U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8565U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 8632U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10839U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16009U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((aIndex + 13177U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 58U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererE + RotL64(aIngress, 12U)) + 8101351470141807662U) + aNonceWordC;
            aOrbiterK = ((aWandererB + RotL64(aCross, 3U)) + 6965474099521076705U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 37U)) + 6803828268885684784U) + aNonceWordJ;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 47U)) + 13454235922950972488U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 11678091885751244777U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 5307134544628507141U;
            aOrbiterE = (aWandererH + RotL64(aCross, 29U)) + 4873703518950429353U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 8542156221858586039U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 42U)) + 3993726182905296513U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12113047622035464386U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1944244448665721151U;
            aOrbiterH = RotL64((aOrbiterH * 7010050836758762003U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12914188029425467576U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2486762763475327024U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 12319769994433811617U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14580191602982245481U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12093414832400135066U;
            aOrbiterD = RotL64((aOrbiterD * 12720286833215690663U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13623906997320021065U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9977356009806428696U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 2005536391712733499U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3694954095397810851U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11453812627797091638U;
            aOrbiterF = RotL64((aOrbiterF * 13730420725113907161U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 542311345544726351U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3024285045990499484U;
            aOrbiterG = RotL64((aOrbiterG * 5153745952148205645U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15397664082460849530U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10716856680110815056U;
            aOrbiterE = RotL64((aOrbiterE * 13947203772929252823U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 833342121331428547U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1111339940097269219U;
            aOrbiterC = RotL64((aOrbiterC * 17991642769781175473U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9312963978841402871U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8225496710723213204U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 894499195498817065U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterG, 60U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterC, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterK, 23U));
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterG, 46U)) + aOrbiterI);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 37U)) + aOrbiterH) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17701U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneD[((aIndex + 16980U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 20858U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16647U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22109U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 19980U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 3U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = (aWandererB + RotL64(aPrevious, 35U)) + 12775735908960052604U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 4U)) + 11791373812080296887U) + aNonceWordD;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 5537362877706057303U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 2023912048504189380U) + aNonceWordK;
            aOrbiterF = ((aWandererG + RotL64(aCross, 57U)) + 17668828109963766893U) + aNonceWordN;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 28U)) + 558908629933941224U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 43U)) + 1479633119685446888U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 15460320397843364063U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 13U)) + 10059749397555469054U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9987633811929693924U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10087337844580228269U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13817142288940843815U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4446204415503364254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9430197906134676162U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1226048679997253363U;
            aOrbiterF = RotL64((aOrbiterF * 14247538885252664127U), 47U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 10611580584157624739U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3137391249289641509U;
            aOrbiterG = RotL64((aOrbiterG * 5462682413239873181U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9327201928815412810U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7890659377013147073U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13827717178378062047U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10675114832750356941U) + aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8804440385852327267U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 8520671775587260601U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12871947817782057116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11015991745792051390U;
            aOrbiterI = RotL64((aOrbiterI * 17152451500505815031U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6320437975845673731U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 702457937087191287U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 17491257114676739589U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16629064896250312921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6054107387816339103U;
            aOrbiterE = RotL64((aOrbiterE * 6983767878966747219U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterC, 4U)) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterE, 47U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 43U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 53U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 58U)) + aOrbiterC) + aNonceWordC);
            aWandererC = aWandererC + (((((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 39U)) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 18U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28683U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((aIndex + 30492U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 27942U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28387U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27075U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 31565U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 18U)) + (RotL64(aCross, 37U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 18180797995100240808U) + aNonceWordC;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 27U)) + 6585906608223552885U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 5U)) + 14088708930575939855U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 18U)) + 468974153311516044U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 12481951025619894110U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 41U)) + 17227987923860711763U) + aNonceWordL;
            aOrbiterG = (aWandererK + RotL64(aIngress, 13U)) + 4373962756657477139U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 34U)) + 2077576476565420951U) + aNonceWordM;
            aOrbiterD = ((((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 17435011300234663764U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 4118039398293246896U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13724716599855216683U;
            aOrbiterI = RotL64((aOrbiterI * 17556333902751079677U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12391461204689596339U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9900605191533799627U;
            aOrbiterK = RotL64((aOrbiterK * 13553565332531046301U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 972946858824366125U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17247681919694541215U;
            aOrbiterH = RotL64((aOrbiterH * 2974639094630445643U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15442851427306771601U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7303586227288294037U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 15406402525021428799U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12650358753454105119U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1483710933373510492U;
            aOrbiterG = RotL64((aOrbiterG * 6531763256577221891U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18065810162229740788U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11311677121338794007U;
            aOrbiterA = RotL64((aOrbiterA * 15116367961682119467U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2355285311890287611U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1287783821903407734U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8054011680932255985U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9282654686791135654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15488608017745542551U;
            aOrbiterC = RotL64((aOrbiterC * 7858866274035085123U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13296835576073421802U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7127700236018338741U;
            aOrbiterF = RotL64((aOrbiterF * 11246173563106014149U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 54U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterK) + aNonceWordK);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 18U)) + aOrbiterI) + aNonceWordB) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 53U)) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 23U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aScatter, 28U) + aOrbiterF) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 60U)) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_FootBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB9FF0D0E6647CD71ULL + 0xEE42F899CB526B34ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x85F16BBCFA3E9AE7ULL + 0x9F8895175C2B2B65ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA514999B0ACD5293ULL + 0x943E9341B17B315BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA131B8E696DE8D4DULL + 0xAAC0C06B20380A9AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x87CA7F63FCBFD741ULL + 0x9B5EF29DB8D9EF33ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x81FD825A5238D93DULL + 0xDD298462C886591FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB3CB8C72CE40308BULL + 0xDB594659A22E65EBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF1E87237681416C9ULL + 0xBBBA14F842630892ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x87E86A4BA79BA6C9ULL + 0xC8F1174C34A2B861ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x855DF19EAF19229BULL + 0x8F90B66BBE12F46CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x99154DB794C32625ULL + 0xE484A9AD18FF61F9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD53A3FEC5A749B39ULL + 0xD0A9785CC181C785ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCAD5C34D331ABB67ULL + 0xE571E7E89E97187FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB1296918D1C0A3F1ULL + 0xBC340FFB9E6C7E49ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEFDE6E38BA87AA15ULL + 0xA3392C45ED809E99ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA7083D9591BD856BULL + 0xC743DDCB6B43DDCBULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneB, aWorkLaneB, aFireLaneC, aWorkLaneC, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5326U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((aIndex + 4211U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6546U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1374U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 408U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 54U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 4634399531433127141U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 16961792729406903200U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 3U)) + 4105280732301137738U) + aNonceWordM;
            aOrbiterC = ((aWandererA + RotL64(aCross, 11U)) + 15692013501147331191U) + aNonceWordE;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 20U)) + RotL64(aCarry, 5U)) + 1252216715968780587U) + aNonceWordH;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7958289043012473752U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6611577301818896615U;
            aOrbiterG = RotL64((aOrbiterG * 2757493607265637973U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8506226754305949140U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3648813120449403353U;
            aOrbiterJ = RotL64((aOrbiterJ * 9521367946879238849U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5195245426245535735U) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 542948051600803051U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4631106308856448475U), 23U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 11974253551208964789U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10596463592332655367U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 10941161258815714641U), 11U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 12015129484061440159U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8254944355710109060U;
            aOrbiterH = RotL64((aOrbiterH * 3233697992479357615U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterI, 21U)) + aNonceWordD);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 48U) + aOrbiterC) + RotL64(aOrbiterG, 3U)) + aNonceWordO);
            aWandererC = aWandererC + (((((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 35U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11237U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 10745U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14621U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14031U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10586U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 12660U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 1393781663398437180U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 17414594746688585273U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 58U)) + RotL64(aCarry, 3U)) + 2823888497053071250U) + aNonceWordP;
            aOrbiterE = (aWandererH + RotL64(aScatter, 37U)) + 17032631958617884859U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 5U)) + 15222697630461125019U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 15737414920751551780U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1357196111055783001U;
            aOrbiterI = RotL64((aOrbiterI * 8225423829221938165U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 5315122321649251691U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 7893744655508595974U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 17863000246694319149U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16721939414324611738U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3444375866323610848U;
            aOrbiterB = RotL64((aOrbiterB * 10874157227815775661U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1825716513674511632U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15582066843912467318U;
            aOrbiterE = RotL64((aOrbiterE * 12765146555943757373U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15673590949193923915U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13887365046280406413U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3169061375011420121U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 26U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterI, 39U)) + aNonceWordH);
            aWandererB = aWandererB + (((((RotL64(aScatter, 52U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordD) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 26U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 39U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22162U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 22281U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 18398U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20696U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17949U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 17358U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 43U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (((aWandererD + RotL64(aIngress, 4U)) + 12692813903177772178U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 7112496446691277899U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 2112247138290568813U;
            aOrbiterA = ((((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 3699421080882855947U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 29U)) + 13761832028354380922U) + aNonceWordB;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9243822514887600214U) + aNonceWordF;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 6863833516853046129U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 775478131159266165U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8863897995943098018U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 13346785686701467520U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18074843497158380703U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15309543066305531619U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17515530938817919111U;
            aOrbiterH = RotL64((aOrbiterH * 16625193986319048245U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 760493237816424254U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7282586354117620860U;
            aOrbiterJ = RotL64((aOrbiterJ * 2327153408185290635U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4129706068526969105U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7020175432730888755U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10095158356907592239U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aCross, 52U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 44U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26683U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 25351U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31498U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26090U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24918U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24680U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 30783U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 37U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 8506388683755208267U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 2179323259055019735U) + aNonceWordL;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 35U)) + 3345902531140983016U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 17456139311481306584U) + aNonceWordP;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 46U)) + 14587864088462311164U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 13178947246650647057U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12866578138946916962U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 121991325166969319U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 13098524333655118173U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15451329483787541982U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 13580376920467431451U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9494299579678389385U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15581954810375490643U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13670002280188424825U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 4487042505730624892U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2774455928791636186U;
            aOrbiterC = RotL64((aOrbiterC * 15847933919136777451U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12435319582397755819U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10077180055177766823U;
            aOrbiterE = RotL64((aOrbiterE * 3924363471701748703U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 27U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 57U)) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aIngress, 58U) + aOrbiterE) + RotL64(aOrbiterH, 54U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_FootBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8DA6069A031E271DULL + 0xD97EA3BD7144B74CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9FB92E11984EBD4FULL + 0xA6523C77941C0B21ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB9D04E4C903EAB99ULL + 0xB186FD660F68E2A3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9ABAEA04BA9722C3ULL + 0xDCC893A242D0A567ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF399F2D3FE1D91CBULL + 0xE0826D38988FCF91ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF1DC4FCAC6614535ULL + 0xD9D430B1C2CDCA20ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF50EF455E8BC7ECDULL + 0xDEFA8202490E2DFBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB458AEF411F13D93ULL + 0x8308BE9AA12C6FD5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC121B6930DF8287DULL + 0xA6C61B4E1ADF7078ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDF9D7FD3FD534175ULL + 0xDCD482D52C53681DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAABBCBB74498992DULL + 0xBE00582A4008D930ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC928EC0397DF73B9ULL + 0xCFD11476980C2737ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEEAC7C083CDABD8BULL + 0xDEBE3C9B7B52E68CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEB69715D034C90E7ULL + 0xC7B13C3D5073FEA7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD0BB2B80441CF1DDULL + 0xC3F5E7E987BD61B4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC4FA9902772E9CFDULL + 0xCC8FB673468734D0ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aOperationLaneC, aWorkLaneA, aOperationLaneA, aOperationLaneB, aWorkLaneB, aFireLaneA, aOperationLaneD, aWorkLaneC, aFireLaneB, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4353U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 7199U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 4428U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2539U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7285U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 3505U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 60U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 13333509828310369865U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 7645352517103840797U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 60U)) + 5310766306660062655U;
            aOrbiterF = ((((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 5165635069832352932U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aWandererH + RotL64(aCross, 53U)) + 15684141764734281849U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 21U)) + 3327963374225061738U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 47U)) + 8625811794878848871U) + aNonceWordO;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7598657468430485291U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2881171216276746485U;
            aOrbiterB = RotL64((aOrbiterB * 3331350584102843605U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10237691227222918101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6419254255884834497U;
            aOrbiterG = RotL64((aOrbiterG * 3816625473642865305U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4238455444646479956U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14936613353493061492U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 3544216916806292273U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15324699725208372627U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9506640480601832011U;
            aOrbiterD = RotL64((aOrbiterD * 12819564111348390227U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3709149613660215641U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1724290199312754307U;
            aOrbiterK = RotL64((aOrbiterK * 12597580418257897965U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13191172833570139194U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3686087945377837886U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 10883609557429936283U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10418330386245397022U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5383531313632347245U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2987755379396160073U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 60U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 47U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 53U)) + aOrbiterB) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aIngress, 50U) + aOrbiterA) + RotL64(aOrbiterF, 19U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 38U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10957U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 13216U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 12132U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15931U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11588U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 8433U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 5U)) + 13650869943246163567U) + aNonceWordO;
            aOrbiterI = (aWandererE + RotL64(aScatter, 19U)) + 3435284932011770999U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 12388155658186776579U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 2374345913955712039U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aCross, 48U)) + 6095094526980292156U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 4965147025852444174U) + aNonceWordG;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 41U)) + 3261881216269075298U) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4939780217097329222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3019862009792676287U;
            aOrbiterJ = RotL64((aOrbiterJ * 2452316208025448747U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 901910626217143974U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3647055146712366383U;
            aOrbiterH = RotL64((aOrbiterH * 1792602402476450009U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 7731765438957392967U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13409819457393479741U;
            aOrbiterC = RotL64((aOrbiterC * 3345078200262410715U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 5415832109107794258U) + aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8876738832313114471U;
            aOrbiterA = RotL64((aOrbiterA * 1304277600444504135U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17135570542519390359U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2373193062766802082U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4213691513185791519U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16318403285501718552U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8456043288604687045U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10556964529144571683U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10572534930284516528U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14616251186735204677U;
            aOrbiterG = RotL64((aOrbiterG * 2048651204265459805U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterI, 3U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 28U) + aOrbiterG) + RotL64(aOrbiterC, 35U)) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterH, 53U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 28U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23885U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 17818U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17555U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23221U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21920U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 17896U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 47U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 17019646486641172469U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 12276141179299971572U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 60U)) + 3617241694029841555U) + aNonceWordB;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 23U)) + 6967963401259371737U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 5U)) + 6340709284279891017U) + aNonceWordI;
            aOrbiterD = ((((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 456065368903896482U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererH + RotL64(aCross, 13U)) + 17686765719908116203U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1322045955429785736U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5163772703302372887U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3193272189179082313U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13268431135020363252U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6538789950366849332U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5352960308459065837U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10390344544314544893U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5087084271300584267U;
            aOrbiterI = RotL64((aOrbiterI * 15149302947570776165U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13423071121590981727U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 18324443012024134729U;
            aOrbiterC = RotL64((aOrbiterC * 15814349432207734533U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4129091815978464507U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17024797553831962245U;
            aOrbiterD = RotL64((aOrbiterD * 3137753479364378175U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6501545108779991661U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11930037791867597447U;
            aOrbiterK = RotL64((aOrbiterK * 4904739567549702851U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4667298703308315851U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6315980380900062127U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 12080555704907924637U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 40U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + aNonceWordH);
            aWandererI = aWandererI + ((((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 50U)) + aNonceWordP) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterF, 19U)) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneC
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28889U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 30983U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 31560U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32256U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26971U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 30604U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 51U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 57U)) + 4970414922752555648U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererB + RotL64(aCross, 11U)) + 9462756592787669327U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 41U)) + 3948790686662213095U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aWandererE + RotL64(aIngress, 5U)) + 14542857212241578311U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 21U)) + 3387479009827029547U) + aNonceWordN;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 1411421370057797877U) + aNonceWordJ;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 16894451466895681236U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12727136462290223542U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4625389198191960525U;
            aOrbiterC = RotL64((aOrbiterC * 5726474430977810191U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3471881403786164913U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 6433115856048534831U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 9363233870194144053U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9825592965466157982U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1553125767261293088U;
            aOrbiterH = RotL64((aOrbiterH * 411535191177308781U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9951616357109647617U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 11231080382787286889U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 14024961994986659187U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13419663264017317947U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4835055642466215566U;
            aOrbiterA = RotL64((aOrbiterA * 17898065852351759171U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14558747666410946768U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13120938960926874504U;
            aOrbiterF = RotL64((aOrbiterF * 5681766019285559739U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11910501376797343986U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15074100100781785300U;
            aOrbiterD = RotL64((aOrbiterD * 228976960937473851U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 12U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterF, 19U));
            aWandererE = aWandererE + ((((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 57U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterF, 41U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterF) + aNonceWordP) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterA, 5U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 58U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
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

void TwistExpander_FootBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE2C96FADE21563DFULL + 0xB07A4D8DFEDC63F5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9A55C202DE1FCD47ULL + 0xCD15A72C62686BF8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB01854B8870EF1DDULL + 0xF3D2C9141D14AE49ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x951A3A5D7FCD3775ULL + 0xB3502C088A2E0C67ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD5A522E118138AC1ULL + 0xD9A12700A6368EA9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x838CB0A8FB8F3F8BULL + 0xBCAE2943EFBB75B3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD9D8F86A4524BEEBULL + 0xF7498F9F3468894AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF02B8E34CF865301ULL + 0xEB029C12B36F5A30ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8B7FD7FEA12A2F55ULL + 0xD4745C835A9119F3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC0C53EBB4EFDDAC7ULL + 0x8CD32EA18761BC72ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBD8CCA8692EB15FBULL + 0xEA7DA8637E0AC5EBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEF1EB9A34D8E1651ULL + 0xC8EB5B624300F7E5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFF5E6CD307952713ULL + 0xA610EC0B09959846ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB6F738B01B378A2BULL + 0xA29374F283A14411ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD97C478F97286D55ULL + 0xE61FF61CD3C34455ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAE3D27D31C6C14C1ULL + 0x99C22C8DF0ED44B6ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aFireLaneC, aExpandLaneA, aOperationLaneC, aFireLaneD, aExpandLaneB, aOperationLaneB, aFireLaneB, aExpandLaneC, aOperationLaneD, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 887U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 7118U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 2236U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4584U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5370U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 279U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 48U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = (aWandererF + RotL64(aScatter, 3U)) + 4848316479321533394U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 6919360256662636195U) + aNonceWordE;
            aOrbiterH = (aWandererG + RotL64(aIngress, 41U)) + 9897013582181108544U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 13U)) + 7319353809896158678U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aPrevious, 60U)) + 2848175435514849859U;
            aOrbiterJ = ((((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 6967780718720437934U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 10143884766603388136U) + aNonceWordA;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 8675965006150972051U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16350117755560994281U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15072308930382994425U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17976597517118423760U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1399631141355370237U;
            aOrbiterC = RotL64((aOrbiterC * 16537788276543236833U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3590613762034716792U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5134624314245932157U;
            aOrbiterB = RotL64((aOrbiterB * 13077589037975283371U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10082236952942943654U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4015535035905433450U;
            aOrbiterJ = RotL64((aOrbiterJ * 4961808568701908559U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 611474103801573800U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5786708483794098001U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 7694007039340089267U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5201943497363274455U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9282160506938328489U;
            aOrbiterG = RotL64((aOrbiterG * 5368182164239021367U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4932320527498940158U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11576526341731392916U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1712051774729439363U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + aNonceWordC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 13U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterH, 51U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + aNonceWordL);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterH, 24U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13313U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 16229U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 12835U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12581U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8834U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 14341U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((aWandererB + RotL64(aScatter, 51U)) + 15383045568644941552U) + aNonceWordG;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 19U)) + 17452811657750910067U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 15660117718455155603U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 10396441207743665753U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 3U)) + 3708971058200841442U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 35U)) + 7000673057768598750U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 10U)) + RotL64(aCarry, 29U)) + 9886354469011131596U) + aNonceWordN;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16018065329058043467U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5024756166109352320U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 11660932185479046483U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6587818720728886652U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3652672354944162319U;
            aOrbiterD = RotL64((aOrbiterD * 10807121230791716109U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6307315649915348048U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16405347331742979258U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7183142442906743699U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5427299664054601957U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 4983381733483185898U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14646556236306407673U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10182995521328377487U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8694282877540593550U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 14614602561910403893U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4085927978153269932U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6176195962815240877U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16792916528959579875U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6966742100601433005U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9920952446921247521U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 1879821050131820933U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + aNonceWordF) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterD, 42U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            aWandererC = aWandererC + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 35U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24299U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneD[((aIndex + 20038U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17272U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23312U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24331U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 18056U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 52U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (aWandererJ + RotL64(aScatter, 29U)) + 13481227414590594621U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 17425964381118918026U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 4792004356135956581U) + aNonceWordK;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 11926849936000639098U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 13U)) + 990697329347742142U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aCross, 35U)) + 9307721505373076588U) + aNonceWordO;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 52U)) + 17605732738841908719U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13110764518634187439U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17970109897810645911U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10395095143998920213U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10273133817644703654U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11239046688920468137U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 5197802934333553327U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8355821483275763145U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 15522151127786049345U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4844278537850520413U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5381663179722418112U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9551368011768104906U;
            aOrbiterB = RotL64((aOrbiterB * 14202470972121732997U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16264476585232221270U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 7721417776432288282U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 10267770327791051869U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 339418090653475277U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3247926250495935511U;
            aOrbiterK = RotL64((aOrbiterK * 16824669543765729097U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3390560045236418590U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3894024951542543635U;
            aOrbiterH = RotL64((aOrbiterH * 10599637790900418767U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 29U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 11U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 35U)) + aNonceWordD) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 4U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30951U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((aIndex + 26212U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25388U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29251U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32256U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 25468U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 38U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererB + RotL64(aCross, 5U)) + 15920462086654025436U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 487844076858004017U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 60U)) + 14502883786442630566U) + aNonceWordB;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 3787107318658233674U) + aNonceWordI;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 51U)) + 12548777544693755491U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 11U)) + 4907309444075181683U) + aNonceWordP;
            aOrbiterK = ((((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 18342396700266492072U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13503051997624242670U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17845742460521374571U;
            aOrbiterB = RotL64((aOrbiterB * 1366356786138085155U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8640887211877858169U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5273913123709097537U;
            aOrbiterJ = RotL64((aOrbiterJ * 1661149444148461791U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17756844173695563883U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6713055830729302951U;
            aOrbiterI = RotL64((aOrbiterI * 2832836748513174311U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5106468334224035972U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10228769728713526172U;
            aOrbiterG = RotL64((aOrbiterG * 9760310686414358435U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7687649520668883142U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7757480627354711605U;
            aOrbiterH = RotL64((aOrbiterH * 7222553727737349209U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 10876291698508634557U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8149278085586014186U;
            aOrbiterD = RotL64((aOrbiterD * 8577133863470695381U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15592893988925610485U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8639028256640537165U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1880655276432963955U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 34U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + aNonceWordM);
            aWandererA = aWandererA + ((((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + aNonceWordJ);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterB, 28U)) + RotL64(aCarry, 11U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterK, 53U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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

void TwistExpander_FootBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF4DFF9827D1AD7F9ULL + 0xEE46C6064C2EED5EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA8EB41A23874B16FULL + 0xC08B995287A4FDEAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB6EA864E2FE25BA1ULL + 0xC9D6EEE7493CDABBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEB4197C4FCA03657ULL + 0xAC894375AFD42316ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE59E2611ADF6BCC3ULL + 0xD603DFA6A990D4FAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD716C35AA955AFE5ULL + 0xDE6BDB69571C3919ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB8F4E836A441CD6DULL + 0xDDCDA8A230BADBF3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBF4FB93DA4183603ULL + 0xB103DAA4B2DCB150ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCFEC7597EF3F952BULL + 0x98526E1E91501971ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF5943B65D78EC091ULL + 0xACD1FB47AA26D37AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAEF19DBE0372EBDFULL + 0x9BC2C68B2D11B599ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE47229B05077F8F1ULL + 0xA4C7F75A187FB7E4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC85D5B848D05C01DULL + 0x9D54E654A9BD5A02ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFF37079A442166BBULL + 0x9B7DFEC7417C247CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE68F153857682161ULL + 0x8DE7049598D51242ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9F604724EE8BAEF7ULL + 0xD14093FC3A4A119CULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aWorkLaneA, aOperationLaneA, aWorkLaneB, aFireLaneA, aOperationLaneB, aFireLaneB, aFireLaneD, aOperationLaneC, aWorkLaneD, aWorkLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3485U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 1006U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 5297U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2980U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1862U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 4823U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 52U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (aWandererE + RotL64(aIngress, 47U)) + 13350544654542863236U;
            aOrbiterK = (aWandererF + RotL64(aCross, 29U)) + 12364346790125404372U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 41U)) + 9738750172849512764U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 21U)) + 3781373837635491421U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 43U)) + 16635020317512702337U) + aNonceWordM;
            aOrbiterI = (((aWandererI + RotL64(aCross, 60U)) + 5383653921676231276U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 39U)) + 10181959815492056493U) + aNonceWordA;
            aOrbiterB = ((((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 10005510924273927017U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 9524687662265740565U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 19U)) + 4259138552009771014U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 6U)) + RotL64(aCarry, 57U)) + 8973051213213726023U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17602611840127337490U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8218984546932905269U;
            aOrbiterH = RotL64((aOrbiterH * 17504305273683304231U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 18102186122213487888U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2629927500298092976U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 6983280164448292723U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2491581597835795234U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9506602492971620955U;
            aOrbiterF = RotL64((aOrbiterF * 9559829640915637163U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13422942713680612924U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15037354693234876601U;
            aOrbiterB = RotL64((aOrbiterB * 12692376075738621447U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12896066842192894694U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2202952306291905855U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6779368532763429997U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12160313482450599313U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10812986281270407756U;
            aOrbiterA = RotL64((aOrbiterA * 7786608700746771809U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 12474638293190144525U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5882870951276225224U;
            aOrbiterG = RotL64((aOrbiterG * 15532427302173572457U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3782896138051179209U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10965680631059882311U;
            aOrbiterI = RotL64((aOrbiterI * 14060923998307082385U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15650420683333746952U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4110674660963676864U;
            aOrbiterE = RotL64((aOrbiterE * 11724979274890265275U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 694817156953099464U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4402927404825116007U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 579586789292520113U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6849178151532923489U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13350544654542863236U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2416097748778941523U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 10U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterF, 53U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 11U)) + aOrbiterI) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterE, 39U)) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterB, 56U));
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + aNonceWordJ);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + aNonceWordN) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterJ, 36U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12858U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 13914U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15686U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10945U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15784U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 11305U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (aWandererD + RotL64(aCross, 53U)) + 2330952702412094686U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 47U)) + 7820188225935060799U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 41U)) + 9347644591709839145U) + aNonceWordP;
            aOrbiterG = (aWandererG + RotL64(aIngress, 22U)) + 2288624878446846870U;
            aOrbiterH = (aWandererI + RotL64(aCross, 5U)) + 9358977729492824128U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 43U)) + 1858511275052455039U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 13715478509322292552U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 16413396625604260455U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 11U)) + 17714322215518432705U;
            aOrbiterB = (aWandererB + RotL64(aCross, 57U)) + 16188315436202861122U;
            aOrbiterK = ((((aWandererK + RotL64(aScatter, 36U)) + RotL64(aCarry, 19U)) + 5564445841368207813U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13717068949900594673U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14143659432287313765U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17281441046722262917U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5729546141908425670U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4297827922736712074U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13631630436759768885U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 829520109395163673U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11547160328525174295U;
            aOrbiterJ = RotL64((aOrbiterJ * 4759690159673049775U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2907177944512117206U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11100346409065275671U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17927994356809011637U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1344592529249949068U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6470438516791143572U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 13339390828725370475U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5217751823741520847U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5371275223586938039U;
            aOrbiterA = RotL64((aOrbiterA * 12318403075523724125U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14218103150268532919U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1367628876596800571U;
            aOrbiterD = RotL64((aOrbiterD * 13777531272321533137U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 2372041991018455610U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9870744274890595581U;
            aOrbiterE = RotL64((aOrbiterE * 12093443117747395585U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15531376915156611594U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11166549148968363252U;
            aOrbiterK = RotL64((aOrbiterK * 10024372567841218915U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8555942275137258839U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3304132937209624841U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7965093976633155809U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14825330575158830172U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2330952702412094686U;
            aOrbiterC = RotL64((aOrbiterC * 9146641978165131495U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 22U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterK, 14U));
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterJ, 29U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 10U) + aOrbiterA) + RotL64(aOrbiterJ, 51U));
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterB, 21U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 44U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 35U)) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterD, 23U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneB
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24007U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 23503U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 21450U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24349U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19636U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 16998U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 4U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 4773124477323378268U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 35U)) + 16848723289435796005U;
            aOrbiterB = ((((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 13846642134917107058U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aWandererG + RotL64(aScatter, 21U)) + 6472057872482789939U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 41U)) + 2747019500690707226U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 46U)) + 9003965289739733880U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 3U)) + 3013390651936257377U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 37U)) + 3331004709895625067U) + aNonceWordC;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 15355010435553517129U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 44U)) + 7709870658004280052U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 51U)) + 13568728443963926564U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12409548853419307131U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 969183352023661537U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5549220554838837145U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15370309834426476775U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3896803894396631184U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 11018830202891911603U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10848873633291935766U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12885336509190543440U;
            aOrbiterA = RotL64((aOrbiterA * 1487357252619221365U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 8252290890093788010U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9201553615601641350U;
            aOrbiterD = RotL64((aOrbiterD * 420321130559162915U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14014209645503188472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4015071464301844550U;
            aOrbiterG = RotL64((aOrbiterG * 17444195018239904971U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16173085647514027347U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16916627014974363360U;
            aOrbiterJ = RotL64((aOrbiterJ * 7699587344277490953U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1591680303404522110U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16499606051269327916U;
            aOrbiterC = RotL64((aOrbiterC * 814405848002794813U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6932673635509444619U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8745681160108707944U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14565255558668084787U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10387263947888920455U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 2553335462317280031U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 7253573275397985211U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17449861295444216249U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15716408844914738774U;
            aOrbiterE = RotL64((aOrbiterE * 10132631423215542589U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16974370193820578179U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4773124477323378268U;
            aOrbiterK = RotL64((aOrbiterK * 8982190762960590543U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 12U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 37U)) + aOrbiterI) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterK, 6U)) + aNonceWordF);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererG = aWandererG + ((RotL64(aScatter, 56U) + RotL64(aOrbiterH, 39U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 23U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterG, 56U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneC
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26919U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 30851U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 26349U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31280U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29667U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31155U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 20U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 60U)) + 15036852811491820366U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 57U)) + 305637140752898475U) + aNonceWordC;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 41U)) + 11948631574496129610U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 35U)) + 5321623592482991426U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 23U)) + 4075270159062690728U) + aNonceWordN;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 48U)) + RotL64(aCarry, 41U)) + 15111580500356908928U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 7244150695504160363U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 5131563519577488862U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 3U)) + 5881954992088651371U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 19U)) + 12780935808751507998U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 39U)) + 12599159643925470226U) + aNonceWordI;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9466589929741834066U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6093158735705189789U;
            aOrbiterK = RotL64((aOrbiterK * 7453778295800853653U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17461243886150519249U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 15456408913739900718U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 16093292401746174671U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11260643903290392780U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7870342756041882616U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2431528656086173419U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 134484990005888936U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10626896209992890407U;
            aOrbiterI = RotL64((aOrbiterI * 12034131076645285597U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14031164129515132292U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1771835705730244212U;
            aOrbiterG = RotL64((aOrbiterG * 186981668443596623U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16395472745067254664U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1455944290845294254U;
            aOrbiterF = RotL64((aOrbiterF * 6757824754363319079U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17866422769075350837U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10226884082632410805U;
            aOrbiterC = RotL64((aOrbiterC * 206035536985843815U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14474587247775371703U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8501763445324525303U;
            aOrbiterE = RotL64((aOrbiterE * 5298694643596784007U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 222650368553738561U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3901452368735982094U;
            aOrbiterJ = RotL64((aOrbiterJ * 18347115513126660483U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3063093906728331146U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9026710562384443411U;
            aOrbiterD = RotL64((aOrbiterD * 8411243802199203035U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11282041925238364080U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15036852811491820366U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18185121326941087841U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 6U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aIngress, 18U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 40U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterD, 11U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 44U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 30U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_FootBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAB06B8674A637211ULL + 0xC60D8D96A49F28BDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9C50244FB57FACBDULL + 0xE7AE917CB37A712FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFCAE70BC7956CB57ULL + 0x8C65D0476FF728B9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB7304A701D3D31BDULL + 0xFA810D7624B5C354ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE1A6C967C6B2FB19ULL + 0xAC8C69055BD5CA42ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x81CEA00122604245ULL + 0x87BFCA2123D6D524ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x81A6C4B25A972111ULL + 0xCDE6C2431AC202ECULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBB81926387461789ULL + 0xAC690AD1EB091EDDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9F3A4E995B6F9BC1ULL + 0xF3736C2455325684ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFB01B572A2941B01ULL + 0xCB5A6F9D232E95B0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8AD783A89E64900FULL + 0x87D59866AC387E80ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE3246723CAD6AF81ULL + 0xDCF0ADA73E7E55EBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE180880CF17BC45FULL + 0xB4EA0D732C8344ABULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9B278C6F87DAAC13ULL + 0xD87032D507AB89EAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x844D9C750350465FULL + 0x94CCCE55E43668A9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDCC0496583EB9C4FULL + 0xCC4C0F4649161ACCULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneD, aExpandLaneA, aFireLaneB, aWorkLaneC, aExpandLaneB, aFireLaneA, aWorkLaneA, aExpandLaneC, aWorkLaneB, aFireLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5513U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 66U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 166U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1804U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3335U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 4428U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 24U)) + 16160838483846078448U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 35U)) + 15404960896190227946U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 29U)) + 16904160594024977199U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 17790460246821031802U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 3U)) + 16395168254086971959U) + aNonceWordM;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 7484373204039901786U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 20U)) + 18026814691322913510U) + aNonceWordH;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 57U)) + 15244817793136966450U) + aNonceWordE;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 5795491730356335666U) + aNonceWordI;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3163873518027801504U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2690791759507349172U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 16677948635136515083U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17898067251167087906U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8028010015006604239U;
            aOrbiterG = RotL64((aOrbiterG * 5601629670521300241U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7304739457289910555U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6476837815096530043U;
            aOrbiterF = RotL64((aOrbiterF * 16380545138701113267U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14242499233467960602U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17305645693017634630U) ^ aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14442976693206929569U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9772864059444171908U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7897200728282156408U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 816306719390807411U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 4890999319172950996U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8165132649356094963U;
            aOrbiterC = RotL64((aOrbiterC * 17297706071263690189U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9342923520083533265U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7213639583505088067U;
            aOrbiterJ = RotL64((aOrbiterJ * 1349251979649428909U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4079475132684197272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3350998022472827283U;
            aOrbiterE = RotL64((aOrbiterE * 948841791460066265U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2479140576609216238U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7703147534931674972U;
            aOrbiterD = RotL64((aOrbiterD * 11419116495223970801U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 48U) + RotL64(aOrbiterD, 22U)) + aOrbiterF) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterC, 28U)) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aCross, 35U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterG, 43U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererA, 50U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15779U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 8334U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 12688U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12734U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11732U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 13508U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 54U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 39U)) + 9133751643283278896U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 27U)) + 8971581804375380408U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 5U)) + 12559650383714566592U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 57U)) + 15753206088872859163U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 7640756270450762350U) + aNonceWordE;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 29U)) + 7340073357551376125U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 43U)) + 5270256573644196046U) + aNonceWordG;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 10U)) + RotL64(aCarry, 35U)) + 3567367996479995928U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 53U)) + 11939634537492733738U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7051817732424527120U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1730487669951837941U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15191634337956285841U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18009252467909454817U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 2361024272031696442U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 15215151562500226027U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15902755877642960397U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12243517544704116184U;
            aOrbiterI = RotL64((aOrbiterI * 2576071074148141447U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16846181962302186187U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 636121425116506681U;
            aOrbiterF = RotL64((aOrbiterF * 17075030673338779993U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6887385655828217318U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3705834550934775862U;
            aOrbiterD = RotL64((aOrbiterD * 11275428284929594435U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11165142437077969438U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6426659930331618269U;
            aOrbiterK = RotL64((aOrbiterK * 17170640810530893705U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12629082390899315789U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4277510580069574724U;
            aOrbiterG = RotL64((aOrbiterG * 9829125163412708305U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13814834144170469978U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3698381854100295826U;
            aOrbiterH = RotL64((aOrbiterH * 5126359230872258015U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11623170635983579937U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7247413650388803796U;
            aOrbiterA = RotL64((aOrbiterA * 3403219499465560059U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 44U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 12U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 36U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 21U)) + aOrbiterF) + aNonceWordB);
            aWandererA = aWandererA + ((((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterI, 42U)) + RotL64(aCarry, 27U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aPrevious, 18U) + aOrbiterA) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22802U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 17948U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23759U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20944U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20722U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 17317U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 43U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = ((aWandererF + RotL64(aIngress, 19U)) + 2915859148137000694U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 12U)) + 210680583721444425U) + aNonceWordK;
            aOrbiterD = (aWandererI + RotL64(aScatter, 47U)) + 6668118118775650387U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 23U)) + 15794200818099010989U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 57U)) + 6565076707062828369U) + aNonceWordD;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 39U)) + 16323164497808856719U) + aNonceWordA;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 7965435318816716560U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 7390281030573369017U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 30U)) + RotL64(aCarry, 37U)) + 2269738866911824875U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 9664014216039993873U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18284857398028357633U;
            aOrbiterD = RotL64((aOrbiterD * 8402008251343393737U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 367667619795303009U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7935945060956274197U;
            aOrbiterE = RotL64((aOrbiterE * 5481786693511955209U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16683666162337789540U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10655658270998102390U;
            aOrbiterA = RotL64((aOrbiterA * 15231596813382239841U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8307037916581540297U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3247742749860703524U;
            aOrbiterC = RotL64((aOrbiterC * 15052136713218656641U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10446792483683818139U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16374602929344972364U;
            aOrbiterF = RotL64((aOrbiterF * 12599903932725787599U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2411334498322777183U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1093701164116833765U;
            aOrbiterK = RotL64((aOrbiterK * 13129220206835381729U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 17018480952982840635U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 17348395690080029814U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 6212591395713433257U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16111252311283623152U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12776492920397785951U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 6136009241593081821U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12214538600808144816U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10043377462096783363U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14639467375095185877U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 54U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 11U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterG, 30U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 21U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 37U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 42U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27008U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 29411U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 29561U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30468U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29697U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 27775U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 40U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 17264605017518259932U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 12U)) + 15209184354580778643U) + aNonceWordC;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 35U)) + 3299527965014731384U) + aNonceWordB;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 43U)) + 16293096431816127821U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 51U)) + 11031983436878828337U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 9188018632448236358U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 23U)) + 13420816400363406556U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 18U)) + 2485063384097917101U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 3089135816938128264U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10730544971770435788U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10431767565618874806U;
            aOrbiterJ = RotL64((aOrbiterJ * 4723078464590561545U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14883796491656899074U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13465877783538483706U;
            aOrbiterF = RotL64((aOrbiterF * 14311686051108108503U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13322163435314643713U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3307316600284371955U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 12337846092069506365U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4950101626975919939U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2596253994220103666U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7181706961838582889U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17961706029559914243U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10321902557977495175U;
            aOrbiterA = RotL64((aOrbiterA * 16189559888625084711U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 18146616411403012772U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8414050129421955787U;
            aOrbiterG = RotL64((aOrbiterG * 14879448948196182863U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11739172334166341121U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7936637782633487291U;
            aOrbiterC = RotL64((aOrbiterC * 14940929920543800413U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3160044627483874242U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16816384076887379704U;
            aOrbiterI = RotL64((aOrbiterI * 5052772186568301951U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8101560104988710226U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8851416379738817624U;
            aOrbiterH = RotL64((aOrbiterH * 16767420038937389027U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 14U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 52U) + RotL64(aOrbiterD, 53U)) + aOrbiterF) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterC, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 12U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterC, 5U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 29U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterA, 48U)) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_FootBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE55CE6D1D5BA2909ULL + 0xDAD9FE0C2F1F5BD9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB683AF8DB96EEF53ULL + 0x960D591C4B3AE149ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE96F87FE27E3F57DULL + 0xFACF6E27564A1896ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x89F6BE46ED0D6951ULL + 0xC4ADDC362368EC62ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE263F60C442B8405ULL + 0xD251A53228A6374AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBA9E1202C052C261ULL + 0xF76CF3EC0BA1E126ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAA058C43DFDF79B5ULL + 0xB2455DB8E94118CDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF7E067AE207D63EBULL + 0x9F6D6C28B6F56308ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA55811AC2ED2B8BBULL + 0xF9E2A7E850F910BDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC8F6BCB4882B7C7DULL + 0xC006FC0444BAC7F2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9DB3FF62291822F5ULL + 0xBA791DE18FB1D234ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB4AC35E07CB7D07BULL + 0xA1FE417F8B71B458ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x89868EEB57033EC3ULL + 0xE3C2B789322DE860ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFE939E9B4EE0D9C9ULL + 0xD1ECB1D147A90A14ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x97FCCBD211BE62BBULL + 0x8208BF597480E52BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x921DA1DD91BC42DDULL + 0xCFFC355057696156ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneD, aWorkLaneC, aWorkLaneD, aFireLaneB, aExpandLaneA, aFireLaneD, aOperationLaneC, aExpandLaneB, aFireLaneC, aOperationLaneA, aExpandLaneC, aFireLaneA, aOperationLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1289U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 3066U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 4757U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6930U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2954U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6860U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 43U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 2617613537256538553U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 11U)) + 16642868916835132715U) + aNonceWordO;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 27U)) + 10860291124337073254U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 5U)) + 6432511273906902472U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 7505375005848241910U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 18U)) + 11086616004678821329U) + aNonceWordN;
            aOrbiterC = ((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 37U)) + 3298830587569881951U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9775143140064220979U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4147601326580823120U;
            aOrbiterD = RotL64((aOrbiterD * 13462244678782260871U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12245920269898100415U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8391940489176734499U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 9119606167674098007U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17876893379544668477U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 18301882058180370541U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 16680384667098921309U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6869225862715140102U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15404118372589259800U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5766851935950389915U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17757381020518233814U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17677969146092374455U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3469432916562405063U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15783378556632870114U) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 5792858258663697864U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12008981883482080427U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11737803388202260296U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16001927091970715330U;
            aOrbiterI = RotL64((aOrbiterI * 3062030309852922061U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 5U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterF, 50U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererD, 44U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11819U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneC[((aIndex + 11206U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12123U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16053U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13521U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15911U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererB + RotL64(aIngress, 43U)) + 8767379393098711499U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 7168159491580816433U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aPrevious, 60U)) + 9879279829061883406U;
            aOrbiterB = ((((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 10537167136053399303U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 29U)) + 2839070018069188936U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 13844278063968429732U) + aNonceWordO;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 37U)) + 11278946626186474646U) + aNonceWordC;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 11798425216660557799U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7618446090703335192U;
            aOrbiterC = RotL64((aOrbiterC * 7168757300685156779U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 695423597006983660U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14344728202803488813U;
            aOrbiterJ = RotL64((aOrbiterJ * 5168825904902285909U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11656100506575697086U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10384358779985773937U;
            aOrbiterG = RotL64((aOrbiterG * 247494692039140973U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17585001605131977341U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9964478171465522911U;
            aOrbiterA = RotL64((aOrbiterA * 13484044854790175315U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2710943171829692624U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17809072853457153057U;
            aOrbiterF = RotL64((aOrbiterF * 16341884203303271365U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12814092033910687774U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1743186323268668740U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11150822630624332557U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10750472346626754704U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15925901217078035356U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9276504171291801637U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 50U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 12U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterI, 26U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterB) + aNonceWordF) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20918U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneD[((aIndex + 20603U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21161U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23132U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21092U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19923U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererF + RotL64(aCross, 37U)) + 1364174714924216027U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 13561796874229506613U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 11845572344206238305U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 44U)) + 15762708240326773763U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 1157119665207900473U) + aNonceWordG;
            aOrbiterF = (aWandererA + RotL64(aIngress, 29U)) + 6823546624372055260U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 53U)) + 14465564210523945121U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10667464548080807531U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13445737493224316575U;
            aOrbiterK = RotL64((aOrbiterK * 12137295000900795711U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3009837893785957665U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2886920524111083752U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15308180928967762543U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10886177449328249656U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15067759884678100433U;
            aOrbiterC = RotL64((aOrbiterC * 5724566815989860041U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 18307930462682331536U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8791864377579255801U;
            aOrbiterA = RotL64((aOrbiterA * 9265158882471421767U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 805797468642992351U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5743305867058244964U;
            aOrbiterF = RotL64((aOrbiterF * 16263000753351131717U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 17102025528234481273U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1841579177327486899U;
            aOrbiterG = RotL64((aOrbiterG * 3841603385577825265U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2189493507896508972U) + aNonceWordL;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 18209567010094914374U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 3737080408976852351U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterD, 37U));
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterI, 6U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 50U) + aOrbiterA) + RotL64(aOrbiterK, 43U)) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 3U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28897U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 31456U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32294U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28233U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25627U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 28614U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 52U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (aWandererF + RotL64(aPrevious, 39U)) + 13880995121909552664U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 14534942818069300546U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 14U)) + RotL64(aCarry, 5U)) + 17745973100886007133U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 21U)) + 2249805580771946872U) + aNonceWordO;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 5U)) + 4460116116396439410U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererG + RotL64(aCross, 29U)) + 3378683994078106878U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 3992996501048809123U) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12057768808864451929U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4115362079047921130U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12263015903331031345U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15297384955502206698U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17623548383481905636U;
            aOrbiterD = RotL64((aOrbiterD * 7487278217901483685U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3559213898000162417U) + aNonceWordD;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 12311605719074507335U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 3982199462062847697U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14807313864347885885U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11222085523291581822U;
            aOrbiterH = RotL64((aOrbiterH * 12580941911587215653U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 916681229436292462U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2441350114032314686U;
            aOrbiterJ = RotL64((aOrbiterJ * 7336079498999018067U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7361470539894653271U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 12153585147213579808U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 3040327545467672961U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13566300726101613579U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14875254144748509128U;
            aOrbiterC = RotL64((aOrbiterC * 13699179902908972403U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 18U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 11U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 43U));
            aWandererG = aWandererG + ((RotL64(aScatter, 12U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererK, 42U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_FootBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDDBBA351CE778CABULL + 0x8E536F39EB735962ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDAD5A5E2CB68A0AFULL + 0xBB45C182054F7250ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x95868C7249FECFB3ULL + 0xE0F9364E1FE3C242ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD447839E122EE4E3ULL + 0xDC50E65D18522B28ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9A1BE85DC911782FULL + 0xC1905CD9641A7645ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE35F2EC3BCBABD4FULL + 0xB47CC338914961FEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAC4C607338FDF68FULL + 0xA669B6F2E9608E5EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAA65A4E98AA0794DULL + 0xCC562683E34FEED4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD6A43DED2ED74109ULL + 0xDE4EFD0A320DB3DBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC310813ADBEE0F39ULL + 0xA7D82011214BA363ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9B3E39A8DEA8ADA7ULL + 0xAD4F0B450BC895D7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBB634126E1B4555BULL + 0xFA591D71648DFEA4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC9D6BCB084331181ULL + 0xDBD3871D892C0FD5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x87DA9E25E1B7EFCBULL + 0xA4F42A5604831AF5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCB50D8C787A1041FULL + 0xBCEE25E22D4C5568ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF13E8E6F7DFB90CDULL + 0xCB42AD8E8B70B30AULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1151U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 464U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 102U)) & W_KEY1], 27U) ^ RotL64(mSource[((aIndex + 2045U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 8020711767807230555U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 29U)) + 15368693777246341570U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 5117523734225562401U) + aNonceWordN;
            aOrbiterI = (aWandererG + RotL64(aCross, 51U)) + 13155269151097507808U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 51U)) + 9879303753623578272U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 13U)) + 1165799257173794826U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 43U)) + 930641942062732091U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11330571332221123153U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2862963158282518899U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 13782195862525974199U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6019186399361476659U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1924419843785161958U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 9485557122500346869U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12618629043591380461U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9334176504266512405U;
            aOrbiterA = RotL64((aOrbiterA * 18239109235362925739U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16829692481030013551U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5604784396927022709U;
            aOrbiterI = RotL64((aOrbiterI * 2833893610883508353U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16124030106598549644U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 16571659812830230677U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4668250364992383549U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15171089673591843703U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2826755560293849328U;
            aOrbiterF = RotL64((aOrbiterF * 9397017963457655287U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 9976785768283589291U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11845100564714691809U;
            aOrbiterK = RotL64((aOrbiterK * 4935139932585319251U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 43U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + aNonceWordA) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterH, 57U));
            aWandererG = aWandererG + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordM) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterG, 36U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 46U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5282U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadA[((aIndex + 3494U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4942U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4149U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 28U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 34U)) + RotL64(aCarry, 57U)) + 5171470532667965920U;
            aOrbiterH = (aWandererK + RotL64(aCross, 3U)) + 750549462358682403U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 47U)) + 3325689257577120525U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 27U)) + 18031575461559790826U) + aPhaseEOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 53U)) + 13874739537012288677U) + aNonceWordD;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 4250029868785016865U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 8211158803112611161U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 1083939790236786027U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3446525462376962464U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 13603702473750888213U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6973817815000417325U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15230876489676945543U;
            aOrbiterJ = RotL64((aOrbiterJ * 7737039082964537651U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9359727659738755880U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8775170107816327654U;
            aOrbiterK = RotL64((aOrbiterK * 6910680458261008653U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11958941755525038545U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16966819714283167348U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16363457661846050749U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14556087985619763243U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 17915047508377045221U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 6727635453185130109U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8578745677485367222U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7002181668717618866U;
            aOrbiterC = RotL64((aOrbiterC * 12329703532414955235U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3569939503066735457U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2956247934282522184U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 9946650822131152531U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 28U) + aOrbiterE) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 11U)) + aOrbiterK);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 30U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordF) + aPhaseEWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 37U)) + aOrbiterH) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterC, 21U)) + aPhaseEWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6281U)) & S_BLOCK1], 36U) ^ RotL64(aKeyRowReadB[((aIndex + 6502U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7719U)) & W_KEY1], 26U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7125U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6952U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (((aWandererF + RotL64(aIngress, 58U)) + RotL64(aCarry, 3U)) + 2974056819475622600U) + aPhaseEOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 7345051759236356098U) + aNonceWordE;
            aOrbiterD = ((aWandererE + RotL64(aCross, 13U)) + 12738468816846628882U) + aNonceWordO;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 3U)) + 7694520596043297922U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 39U)) + 5530753590015084774U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 3776309161718383105U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aIngress, 27U)) + 784780304358106404U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8999942326995036509U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5194986506064092779U;
            aOrbiterD = RotL64((aOrbiterD * 15070787038006135963U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7920040007459652762U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11311997270710107937U;
            aOrbiterB = RotL64((aOrbiterB * 6227571709361790209U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5365231114813547251U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8630110234623825263U;
            aOrbiterH = RotL64((aOrbiterH * 2735881715888325759U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2358235238039571072U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 18059414891616491807U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 17150786106857185467U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14526050556461782864U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 6937282036603272474U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 14954512365270028029U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10105832250694931310U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3884223553012098137U;
            aOrbiterC = RotL64((aOrbiterC * 16340956813003906195U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10385284339549648087U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1257633893341505930U;
            aOrbiterJ = RotL64((aOrbiterJ * 2669950791270500977U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 60U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 44U) + aOrbiterI) + RotL64(aOrbiterC, 41U)) + aNonceWordN);
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + RotL64(aOrbiterF, 21U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9383U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 10353U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(mSource[((aIndex + 9973U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 8979U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9593U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8329U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 43U)) + 3561491146322798260U) + aPhaseFOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 7075025056181885339U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 9230910887904171613U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 4119781172609908917U) + aNonceWordF;
            aOrbiterB = (aWandererJ + RotL64(aCross, 26U)) + 17155609083870983149U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 13U)) + 2423018561430181695U) + aNonceWordJ;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 19U)) + 12957280305617615744U) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2461704174772065813U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 7907123257849391997U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 9416171962847312179U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 7257868138318960007U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16425903703085702285U;
            aOrbiterE = RotL64((aOrbiterE * 7996935869077231999U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2990822664594079467U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5654819006718953817U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4465096036756887801U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12183676471235678779U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15026286960542123922U;
            aOrbiterF = RotL64((aOrbiterF * 17199049329995315279U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12169080607071830522U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2906296852254787499U;
            aOrbiterD = RotL64((aOrbiterD * 6754514406846040163U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3029858695410344584U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14406410317495954566U;
            aOrbiterJ = RotL64((aOrbiterJ * 9663780721657983421U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11048818178401163861U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13622063920319445043U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2516025554421589857U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 48U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterD, 12U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + aNonceWordB);
            aWandererI = aWandererI + ((((RotL64(aIngress, 10U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 19U)) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 41U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11224U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 11834U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12401U)) & W_KEY1], 43U) ^ RotL64(mSource[((aIndex + 12508U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13048U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13019U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 12106U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 58U) + RotL64(aIngress, 23U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 12535417189990029950U) + aPhaseFOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 11U)) + 6204401443676390273U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 29U)) + 869613505613154672U) + aNonceWordF;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 15053590879563855802U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 19U)) + 13338989605204591428U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 53U)) + 18306470022403825392U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 39U)) + 1150696349434090218U) + aNonceWordP;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13549541786420596437U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14302878430259588461U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16813606782134305513U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4660437084477165225U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1653628537860912069U;
            aOrbiterI = RotL64((aOrbiterI * 2624835201155303123U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5594199757006711631U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11008472193138708891U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13645764762027798301U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3668516817279364310U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 128159531749679984U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 4523246859249826987U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6378674346113979108U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11438762460659123362U;
            aOrbiterA = RotL64((aOrbiterA * 2733309638158283953U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10624263004446482910U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12546839706919241411U;
            aOrbiterC = RotL64((aOrbiterC * 11468326687628079347U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 8466639576503293921U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5828694979857951504U;
            aOrbiterH = RotL64((aOrbiterH * 7835487310289634515U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 35U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterC, 57U)) + aPhaseFWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterH, 43U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + aNonceWordL);
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 28U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 6U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15183U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 14085U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15367U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13953U)) & W_KEY1], 21U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14851U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14034U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13729U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 21U)) + 380024772508948442U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 56U)) + 7649029098162567210U) + aNonceWordE;
            aOrbiterB = ((((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 5329304598870421851U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 3U)) + 12306118665045151326U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 960751560457324256U) + aNonceWordK;
            aOrbiterF = (aWandererK + RotL64(aScatter, 47U)) + 3244070254386191876U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 15733408571609521746U) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17623448932647018544U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8787759896149035829U;
            aOrbiterB = RotL64((aOrbiterB * 7092515868845497573U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 14741681792348288162U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8801731213568307302U;
            aOrbiterK = RotL64((aOrbiterK * 12127126999570616489U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9872248187499779222U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15407371518644528235U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1245102406469471673U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4242060317152943062U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9942784962409917541U;
            aOrbiterH = RotL64((aOrbiterH * 888649755587764533U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7296348796484458631U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15061417216070157797U;
            aOrbiterG = RotL64((aOrbiterG * 10349554676953256231U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3233185810644297433U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9241229457641024287U;
            aOrbiterE = RotL64((aOrbiterE * 2728237515724597517U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 8464051359381554575U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3307872165699029375U;
            aOrbiterF = RotL64((aOrbiterF * 4859663401033023433U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 60U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + aNonceWordO);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 3U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 3U)) + aNonceWordC) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterG, 10U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16811U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 16810U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(mSource[((aIndex + 16722U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17279U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17267U)) & W_KEY1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16432U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17879U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (aWandererA + RotL64(aScatter, 13U)) + 4634399531433127141U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 16961792729406903200U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 23U)) + 4105280732301137738U) + aNonceWordA;
            aOrbiterG = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 15692013501147331191U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 29U)) + 1252216715968780587U) + aNonceWordO;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 7958289043012473752U) + aPhaseGOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 54U)) + 6611577301818896615U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8506226754305949140U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3648813120449403353U;
            aOrbiterH = RotL64((aOrbiterH * 9521367946879238849U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5195245426245535735U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 542948051600803051U;
            aOrbiterD = RotL64((aOrbiterD * 4631106308856448475U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11974253551208964789U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10596463592332655367U;
            aOrbiterG = RotL64((aOrbiterG * 10941161258815714641U), 23U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 12015129484061440159U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8254944355710109060U;
            aOrbiterI = RotL64((aOrbiterI * 3233697992479357615U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2754858806943915419U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5007802002906662779U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 15613733948331639723U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6262190752136523216U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10528977986487821428U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1184258264034585525U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8511097226098211854U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12091864735686692582U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 6128140528141411237U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 51U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 60U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterC, 27U)) + aNonceWordH);
            aWandererH = aWandererH + (((((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordE) + aPhaseGWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20645U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 21226U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21412U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21598U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20823U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21795U)) & W_KEY1], 13U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21135U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 20782U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 4U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 3612110001869385068U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 29U)) + 16340824141280225936U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 15222338965130765231U) + aPhaseGOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 3U)) + 6649270508107155041U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 51U)) + 768217258655426384U) + aNonceWordE;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 4481855259658861851U) + aNonceWordB;
            aOrbiterA = ((aWandererG + RotL64(aCross, 42U)) + 18318041934562434016U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4212457153804401807U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16143621095636987628U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6576072860505961427U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 2095664232866642086U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4339527736737366572U;
            aOrbiterB = RotL64((aOrbiterB * 17503569508822244125U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13679353177869884790U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11582168502846418236U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 135539430034462861U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10451330452898542191U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12951448817640617841U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 4141870904192742091U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15389161934419370747U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4754886272708253014U;
            aOrbiterH = RotL64((aOrbiterH * 16638243718191281597U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11746389873929280688U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12042680172517298768U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3814780289755857543U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2648103752465009244U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 451594673632597973U;
            aOrbiterI = RotL64((aOrbiterI * 8496763663271072425U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 24U)) + aOrbiterH) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + aPhaseGWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 5U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22002U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 21868U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22079U)) & W_KEY1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23918U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 21859U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23228U)) & S_BLOCK1], 22U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22597U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23120U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 56U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 23U)) + 13924571355038625040U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 16328300979357156658U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 11U)) + 3947771961206012461U) + aNonceWordI;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 15428284250569311285U) + aPhaseGOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 5777369485254032486U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 54U)) + 16813320300717644673U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 47U)) + 16689933050200758251U) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1856422419049390708U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 18214498743831925517U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10744120577560529379U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 18278550878494094923U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 797712062039591797U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 7212998747080137625U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15854849439012341347U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 996882939768167773U;
            aOrbiterB = RotL64((aOrbiterB * 14936703950807908575U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3005829974130671692U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8793495343509953906U;
            aOrbiterK = RotL64((aOrbiterK * 14065479348374612031U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7710453029930631112U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 9511995836117707047U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 7250766204781428201U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 670902975693341744U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9045820304668279777U;
            aOrbiterH = RotL64((aOrbiterH * 18373074917532639027U), 21U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 12417212387607119470U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12816983560669985622U;
            aOrbiterA = RotL64((aOrbiterA * 8406003970221889847U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 50U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 42U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + aNonceWordF) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterA, 48U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + aNonceWordC) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 39U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26338U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 26865U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 27211U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26467U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26470U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26105U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25837U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneD[((aIndex + 25546U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 37U)) + (RotL64(aCross, 4U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 51U)) + 16200278595895089008U) + aNonceWordJ;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 1029614154810465897U) + aNonceWordB;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 58U)) + RotL64(aCarry, 47U)) + 7129562468705441295U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 35U)) + 14388903902433951274U) + aPhaseHOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 29U)) + 1013568949315967455U) + aPhaseHOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 3128823373497815651U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 21U)) + 14525694606889470589U) + aNonceWordM;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14443983602196782887U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12244220415328641190U;
            aOrbiterH = RotL64((aOrbiterH * 15052949098014803181U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10477159225338766614U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2842870123078131566U;
            aOrbiterE = RotL64((aOrbiterE * 11522265477555954071U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8621138818955849917U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5038396344400303181U;
            aOrbiterA = RotL64((aOrbiterA * 14636756322207385447U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2768613802894372496U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2027754864051410015U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 2461322540050569287U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2848088309172056399U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15017458513904884651U;
            aOrbiterB = RotL64((aOrbiterB * 9926904679902843055U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9079797279596336139U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15424866642305110811U;
            aOrbiterJ = RotL64((aOrbiterJ * 12912331089970158845U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13751764050290602740U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7694557131324740282U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14980807690491467023U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 12U)) + aOrbiterA) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterB, 23U)) + aPhaseHWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 37U)) + aOrbiterH) + aNonceWordG);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 29U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29935U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((aIndex + 29444U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28333U)) & W_KEY1], 48U) ^ RotL64(aFireLaneC[((aIndex + 29552U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28748U)) & W_KEY1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29080U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27531U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27979U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 19U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 43U)) + 16651241552253078315U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 4558144676982478003U) + aNonceWordN;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 8814884320080367550U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 37U)) + 16011579668555672117U) + aNonceWordB;
            aOrbiterD = (aWandererE + RotL64(aCross, 14U)) + 4738918668759862438U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 12526083125540985108U) + aNonceWordD;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 29U)) + 8048723561746000552U) + aNonceWordM;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1082218464034639039U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8432043246965946816U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7801965585991025451U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9982080524048636852U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6720069955755215919U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 1025046364205332059U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 1019035028070247757U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7360619079463870467U;
            aOrbiterF = RotL64((aOrbiterF * 6623074813047915863U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10893918488381348474U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 1390297670907738019U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 11909657437658597735U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12512200589031203480U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14741471280748399540U;
            aOrbiterG = RotL64((aOrbiterG * 3012135242889901095U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8543897248359826770U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8545972622733791272U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11793879362775346821U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7049384618581928664U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 14730773807906925408U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 10711566871536755073U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterA, 37U)) + aPhaseHWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + aNonceWordL);
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 47U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 3U)) + aOrbiterF) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 56U)) + aOrbiterI) + aPhaseHWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 19U)) + aOrbiterG) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30969U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 31002U)) & W_KEY1], 24U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30232U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30317U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31847U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 30095U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 9888431329297626900U;
            aOrbiterH = (aWandererK + RotL64(aCross, 47U)) + 2937735167534624403U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 10U)) + RotL64(aCarry, 39U)) + 17626022970343789617U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 19U)) + 5665660859333693743U) + aNonceWordL;
            aOrbiterF = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 1060537034632076669U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 39U)) + 743777763907175800U) + aPhaseHOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 29U)) + 5744905970181808845U) + aNonceWordJ;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 3545351394494002180U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4877547088414106007U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5416792889338547109U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11669378338379598445U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2961072441706158212U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2677988507090705371U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13984945589234919765U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1433097875470903205U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 451996840039906781U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 716415411025451152U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8542286150858297810U;
            aOrbiterJ = RotL64((aOrbiterJ * 9139015340823332449U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12932391786479661299U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 14005503313299177013U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 802663466907819743U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9382792812676318046U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5138554251079724724U;
            aOrbiterH = RotL64((aOrbiterH * 6386016499265056247U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8522380066269546172U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11825536408101906458U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 17042837108792016849U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH) + aNonceWordA);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterC, 21U)) + aNonceWordP);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + aNonceWordI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 50U)) + aOrbiterC) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 13U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_FootBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEC4E33DC894154E1ULL + 0xE2DAC6AF24C5681AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB88431FCCF1913A1ULL + 0x928CC4E37E163D38ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA843CDAF67B80C13ULL + 0xD396D2010C3984A6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC5359C75823F15B7ULL + 0xC0C470B7A2E2E391ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x973E08B6007BDA5FULL + 0xBD3604D69CC38F83ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFBC48D383EB5AA6FULL + 0x81781F7EAB902730ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9987542BF0C51F89ULL + 0x89DC6AC0E7D17D04ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB345906FE4988703ULL + 0xB49BC9A5E0CEA1DEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAA9FC57352905BD5ULL + 0x858AE8D3E6CCAE37ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD8FC912785B36CB7ULL + 0xEB85DE09047F8697ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8A056585D43A3DF1ULL + 0x866799B26682B55CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9A856955468CE4A1ULL + 0xBD8A91C82BEF9B0CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC547340D3EFC731DULL + 0xDD5D942E5E715EDEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x943750F506A699B5ULL + 0x9B50893185F10275ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEA1EA573CBA6AF2BULL + 0x9AB40A20B1C82D92ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x95B14DFFA5060CFDULL + 0x9439F86F19773D0BULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneC, aInvestLaneB, aFireLaneA, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5040U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 5350U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 4879U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1242U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 3959U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 53U)) + 6469584119078165548U) + aNonceWordG;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 44U)) + RotL64(aCarry, 57U)) + 14329756366517987910U) + aNonceWordJ;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 12890831797059772123U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aScatter, 35U)) + 3164503807500018990U) + aPhaseAOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 177531431387646836U) + aNonceWordL;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3167421392893561015U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2813174781844753460U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9760688894575305115U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10953270419153249857U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16911518309710356951U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13162785997686570445U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6616750447844893150U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10276741398025985982U;
            aOrbiterI = RotL64((aOrbiterI * 6824712685896987133U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6206043608461213208U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12021552904553405793U;
            aOrbiterE = RotL64((aOrbiterE * 10023362889960174909U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15283586234744144846U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5923238786775948571U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8200882393521882651U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 56U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 39U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ) + aNonceWordB);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 11U)) + aNonceWordK) + aPhaseAWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9091U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 6793U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 8103U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8826U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 6651U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 21U)) + 3448371607470865612U) + aPhaseAOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 3743742913651580573U) + aNonceWordK;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 13069491287948807280U) + aNonceWordN;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 16872779275586545632U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 48U)) + 17945792656755062795U) + aPhaseAOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 18199747196793731853U) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15953311878379809513U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 5476802169152352897U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 941268763494588338U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10090221530365796809U;
            aOrbiterJ = RotL64((aOrbiterJ * 14035236086292997613U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8335698093307607001U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6147498804734306100U;
            aOrbiterE = RotL64((aOrbiterE * 6904444049941211327U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5980246079567570090U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4152167624425912978U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10019421651535123573U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 14990418790239735916U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3418668387496597219U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12814077238529863119U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterG, 41U)) + aNonceWordI);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aCross, 20U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 41U)) + aNonceWordG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 20U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererK, 30U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12069U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 12845U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15587U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12322U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12638U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 12508U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 380024772508948442U) + aPhaseAOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 7649029098162567210U) + aPhaseAOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 20U)) + RotL64(aCarry, 27U)) + 5329304598870421851U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 3U)) + 12306118665045151326U) + aNonceWordA;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 57U)) + 960751560457324256U) + aNonceWordP;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3244070254386191876U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 15733408571609521746U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 11280008313548121407U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17623448932647018544U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8787759896149035829U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 7092515868845497573U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14741681792348288162U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8801731213568307302U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12127126999570616489U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9872248187499779222U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15407371518644528235U;
            aOrbiterD = RotL64((aOrbiterD * 1245102406469471673U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4242060317152943062U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 9942784962409917541U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 888649755587764533U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 42U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterF, 54U)) + aNonceWordC) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16888U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneA[((aIndex + 17211U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17219U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21370U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19980U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17531U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 22U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 6733949564325516029U;
            aOrbiterD = ((((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 7304098437143918796U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 35U)) + 3923949518391777800U) + aPhaseAOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aIngress, 20U)) + RotL64(aCarry, 53U)) + 14243591003388927124U) + aNonceWordM;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 53U)) + 18329498724605410406U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13118172167747037249U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5272025143849174212U;
            aOrbiterA = RotL64((aOrbiterA * 9935990954321437743U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16075917179214318424U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15263590648674658399U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9918239923411740337U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13730046728289525921U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 7703141464499623408U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 5886009900621521987U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1382279753822135359U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2973369221699098292U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7440242040663550631U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 11578274119583013219U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3419411247737896674U;
            aOrbiterI = RotL64((aOrbiterI * 17814942652262802991U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aNonceWordF);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 58U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + aPhaseAWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 37U)) + aOrbiterK) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27135U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 25253U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 23993U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25434U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26928U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 22435U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = (((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 1866656689936219099U) + aNonceWordB;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 53U)) + 2312314528139448289U) + aNonceWordD;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 43U)) + 3554037526469185237U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 405707755060974111U) + aPhaseAOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aScatter, 22U)) + RotL64(aCarry, 23U)) + 1862976326004007697U) + aNonceWordF;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12992483065443288263U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3793854946371595197U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 1819119223110966487U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4244007978867369382U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10280867500312580308U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 13729899124177931289U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 472563452959164242U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12041770406895816553U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 17811798500132002631U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6118634015704900486U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13637107920449233307U;
            aOrbiterB = RotL64((aOrbiterB * 17712028184714868053U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16673735670669318830U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8602681273646630496U;
            aOrbiterJ = RotL64((aOrbiterJ * 6995213887710749241U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterB, 30U)) + aPhaseAWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + aNonceWordA);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ) + aNonceWordH);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 11U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28775U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 29708U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31408U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28957U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32010U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 30457U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (aWandererD + RotL64(aIngress, 56U)) + 826930775230515406U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 5137814617363250861U;
            aOrbiterH = ((((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 14761561947426681616U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 12773023438753662590U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 47U)) + 7331345852207096322U) + aNonceWordN;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 3899381212671247460U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10072004147620068599U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 5663583566047763435U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 3424585039401897560U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8246760141625966321U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11478879365443736383U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3655992860610853290U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11154618022505863898U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 4791494171286145231U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15629361991059709973U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10842068502278489664U;
            aOrbiterE = RotL64((aOrbiterE * 17223002513104960799U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5571312349016336686U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 589313823745748879U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1356685926549786027U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 54U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + aNonceWordM) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 30U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_FootBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAA075F176B3FC7F3ULL + 0xA56BAF4C5285E64CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE0B063F80B12B101ULL + 0xA25D17AEAAA06720ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFFB1A6C5D27116EBULL + 0xFCE51F6E03B25495ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8EABBC7CD0860857ULL + 0x91E51D97038DEB97ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD556F2E02903D323ULL + 0xB440BB9F0D5BD88AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8626A13E7064A3ABULL + 0xF34E191BA21D5CAEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF9A1CC3EB7FC0E9DULL + 0xAEB88F759C3BDA49ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBBBEB238D023636BULL + 0xA2E0127E7E9223C7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFC01A45146F375CBULL + 0xCC36723BD05F82C1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA0357DBA9D19407FULL + 0xC32FCE590A80CA7AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCA03F6578CE3A679ULL + 0xF9A28E7F83990E7FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF0120B5F0941D9C5ULL + 0xD4411D93AE08BE5AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x875E40D8568F239DULL + 0xE08B53F067D87DEFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBF02D8B14BDCAC6BULL + 0xE64AF1827AFCCC09ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC6865014CB960A39ULL + 0xFF6392795EED9405ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8607244EACA20B17ULL + 0xD05FABC17A6AB648ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneD, aOperationLaneC, aOperationLaneD, aFireLaneB, aInvestLaneC, aFireLaneA, aFireLaneD, aInvestLaneD, aExpandLaneC, aWorkLaneA, aExpandLaneA, aWorkLaneB, aExpandLaneB, aWorkLaneC, aFireLaneC
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 801U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 836U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2645U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 620U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4045U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 42U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 58U)) + RotL64(aCarry, 11U)) + 10404808878585437255U) + aNonceWordM;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 10587858736301591439U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 47U)) + 1430530909801644435U;
            aOrbiterK = ((((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 9090938022430118902U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererE + RotL64(aScatter, 39U)) + 12936604311751121235U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 5U)) + 1000583006020232032U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 20U)) + 12352532088997042232U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 53U)) + 16723410947058502564U;
            aOrbiterI = (aWandererB + RotL64(aCross, 13U)) + 16614089235313154270U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 4245553025593349277U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3353146318549477494U;
            aOrbiterH = RotL64((aOrbiterH * 14246377408238318091U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5935727336135635196U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10312187090293319667U;
            aOrbiterG = RotL64((aOrbiterG * 1395964500396711899U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12192843181244744484U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2542570124502586365U;
            aOrbiterC = RotL64((aOrbiterC * 17222847847573534963U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3315472769469002444U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17512858811783071174U;
            aOrbiterB = RotL64((aOrbiterB * 9070400454074283765U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16633218007427888082U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2502077714838858460U;
            aOrbiterK = RotL64((aOrbiterK * 970762420815997725U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14792910273226469214U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15739513291150783151U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11896279674116906915U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2192903544350345992U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 844428341223009295U;
            aOrbiterF = RotL64((aOrbiterF * 4768368713974002539U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2998511458298901402U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7790789639864783373U;
            aOrbiterA = RotL64((aOrbiterA * 9173097618440495497U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4540735375055164995U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13700342877362633034U;
            aOrbiterI = RotL64((aOrbiterI * 14730797752841670505U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 10U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ) + aNonceWordC);
            aWandererE = aWandererE + ((((RotL64(aScatter, 22U) + aOrbiterB) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 36U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + aNonceWordK);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 48U) + aOrbiterH) + RotL64(aOrbiterF, 6U)) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterA, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneA
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 7859U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 9684U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10008U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneA[((aIndex + 7565U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9772U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6789U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6082U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererB + RotL64(aCross, 57U)) + 439898681482066326U) + aPhaseBOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 12U)) + 17362083676671776094U) + aNonceWordK;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 29U)) + 6418499837265155024U) + aNonceWordG;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 17262244253027454972U) + aNonceWordE;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 3U)) + 2382066162993139503U;
            aOrbiterK = (aWandererE + RotL64(aCross, 38U)) + 14345808395587174135U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 47U)) + 7534743166385552851U) + aNonceWordI;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 16994453324688523966U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 7079553728544045092U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3562822704508440641U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13990892681975857821U;
            aOrbiterB = RotL64((aOrbiterB * 8352929306654078795U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1796728922368577238U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6605161260520067178U;
            aOrbiterK = RotL64((aOrbiterK * 8147537646591674091U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13994083795942328918U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6144523182899107711U;
            aOrbiterG = RotL64((aOrbiterG * 4153879991344611283U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12247462325297436642U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1065809332002012789U;
            aOrbiterF = RotL64((aOrbiterF * 5496601177032953251U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10147919864511540753U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17138553441127273354U;
            aOrbiterD = RotL64((aOrbiterD * 5773875596275267871U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 2653924016109573974U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6254416952351699582U;
            aOrbiterC = RotL64((aOrbiterC * 12756861659704947257U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 813046408080197079U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9624466135414123483U;
            aOrbiterE = RotL64((aOrbiterE * 6960320253124395015U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 972586705850825744U) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 155283774901960223U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9928051687724257041U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 18200100644751360406U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1168426822045686004U;
            aOrbiterJ = RotL64((aOrbiterJ * 5867027156069481313U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 56U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterA, 51U)) + aOrbiterF) + aNonceWordD);
            aWandererB = aWandererB + (((((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 14U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordN) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + aNonceWordP) + aPhaseBWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterE, 21U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterF, 36U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 3U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 6U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 54U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 16133U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 14154U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 11125U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13663U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11425U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 28U)) + 6068543441070417854U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 2995980468193441856U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 47U)) + 18020277482171594003U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 4293807434721230702U) + aNonceWordO;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 5U)) + 7980599111583893156U) + aNonceWordA;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 21U)) + 8593141111851052016U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 51U)) + 5903487523900084325U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 13U)) + 15112035513447930209U) + aPhaseBOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 9854037263057006439U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16759760289688823193U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12622628933030601390U;
            aOrbiterK = RotL64((aOrbiterK * 2151912984825538321U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1264668857268123425U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16302812053619101593U;
            aOrbiterH = RotL64((aOrbiterH * 18291400055836111547U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 16087995784896123610U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7970269262800468363U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 14924752223305807461U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5331477046030959632U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16534913204255550893U;
            aOrbiterC = RotL64((aOrbiterC * 1013433634373673565U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11042821902537871209U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8069677512345031660U;
            aOrbiterI = RotL64((aOrbiterI * 13622218526054132397U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5737130058129936372U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1076627182956662997U;
            aOrbiterB = RotL64((aOrbiterB * 14342191224014199929U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13911061091801078190U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15397603151098990373U;
            aOrbiterG = RotL64((aOrbiterG * 1802890451633592245U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15137326716738637972U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11248737008959896786U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 90789374131547005U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1847847987633923657U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10560748778679145431U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2919333327817231099U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 38U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 14U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + aNonceWordP) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 44U) + aOrbiterG) + RotL64(aOrbiterF, 41U));
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 23U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterG, 46U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 38U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18073U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneC[((aIndex + 19352U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19907U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19908U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneD[((aIndex + 19022U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 12U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 12262991801139086177U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 7963038771924890197U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 19U)) + 15540520327933568896U) + aPhaseBOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 60U)) + 8745565892055020722U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 23U)) + 16619329199683755286U) + aPhaseBOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 10865705026433867260U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 11U)) + 2743368697984518059U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 56U)) + 5556006271515473135U) + aNonceWordP;
            aOrbiterF = (aWandererG + RotL64(aScatter, 39U)) + 5355833281353498588U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8313616108963479829U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 16657121016801866434U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 331533349428472477U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16532226425013000833U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5800465874932467232U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 5966395771690704577U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17882948163883121328U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15029375310296563175U;
            aOrbiterG = RotL64((aOrbiterG * 17021415832288477713U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10170682648007918739U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11829089574189398773U;
            aOrbiterD = RotL64((aOrbiterD * 15755874363488568849U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1746524867389196322U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 10217423427886742775U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 9166162099575333519U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1338457710729082656U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1319981417675542556U;
            aOrbiterB = RotL64((aOrbiterB * 9518448254565489715U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3985281993069194761U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7281264481139915593U;
            aOrbiterK = RotL64((aOrbiterK * 13498446162967276739U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17394503335338855566U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1430703546991948227U;
            aOrbiterF = RotL64((aOrbiterF * 1623206122475721175U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 472559435062214929U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8065899137826178995U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13287499768933229539U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 54U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterI, 10U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 19U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterG, 29U));
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 47U)) + aOrbiterK) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterH, 5U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 20U) + aOrbiterH) + RotL64(aOrbiterA, 52U));
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aExpandLaneB
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 27003U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneD[((aIndex + 24874U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22999U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23685U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneC[((aIndex + 23478U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 18U)) + RotL64(aCarry, 39U)) + 1457104756581596530U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 29U)) + 6127240317844622874U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 57U)) + 16492290056044189421U) + aNonceWordJ;
            aOrbiterE = (aWandererF + RotL64(aCross, 23U)) + 10963676850938416468U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 13U)) + 4872917367399752405U;
            aOrbiterI = ((((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 15218882377875616148U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aWandererG + RotL64(aCross, 36U)) + RotL64(aCarry, 47U)) + 5934166612122118251U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 53U)) + 14215280930872003003U) + aNonceWordB;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 43U)) + 11428034799044600979U) + aNonceWordM;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5453003654321728726U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14273775120265649389U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5139018128323795309U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 328723770018440271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13032190719588211088U;
            aOrbiterA = RotL64((aOrbiterA * 13363368478932798315U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2386881543033598494U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1649501123340887116U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11148976582360499033U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16462401546754210583U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1510579201823042227U;
            aOrbiterF = RotL64((aOrbiterF * 16287912400104043275U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 6889066000014251983U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11324594596597724357U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 15344987814648586023U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12237796033168436537U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17306069670330000343U;
            aOrbiterH = RotL64((aOrbiterH * 3167451351403385259U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14197284538008811658U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4754134852883071927U;
            aOrbiterC = RotL64((aOrbiterC * 3484427259538998699U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17201907781639753736U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8318419319239859855U;
            aOrbiterE = RotL64((aOrbiterE * 10320390501983802091U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16012488623961565780U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15583721012865354925U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10656414363201743961U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 54U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 58U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 57U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 53U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 42U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + aNonceWordF) + aPhaseBWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterC, 23U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterC, 30U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 10U) + aOrbiterE) + RotL64(aOrbiterF, 5U)) + aNonceWordD) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32314U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 28425U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28210U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32091U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31654U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 18180797995100240808U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 47U)) + 6585906608223552885U) + aNonceWordO;
            aOrbiterE = (aWandererE + RotL64(aScatter, 23U)) + 14088708930575939855U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 18U)) + RotL64(aCarry, 21U)) + 468974153311516044U) + aNonceWordC;
            aOrbiterF = (aWandererI + RotL64(aScatter, 43U)) + 12481951025619894110U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 17227987923860711763U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 53U)) + 4373962756657477139U;
            aOrbiterA = (aWandererK + RotL64(aCross, 30U)) + 2077576476565420951U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 11U)) + 17435011300234663764U) + aPhaseBOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4118039398293246896U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13724716599855216683U;
            aOrbiterE = RotL64((aOrbiterE * 17556333902751079677U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12391461204689596339U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9900605191533799627U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 13553565332531046301U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 972946858824366125U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17247681919694541215U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2974639094630445643U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15442851427306771601U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7303586227288294037U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15406402525021428799U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12650358753454105119U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 1483710933373510492U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 6531763256577221891U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18065810162229740788U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11311677121338794007U;
            aOrbiterH = RotL64((aOrbiterH * 15116367961682119467U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2355285311890287611U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1287783821903407734U;
            aOrbiterF = RotL64((aOrbiterF * 8054011680932255985U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9282654686791135654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15488608017745542551U;
            aOrbiterC = RotL64((aOrbiterC * 7858866274035085123U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13296835576073421802U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7127700236018338741U;
            aOrbiterA = RotL64((aOrbiterA * 11246173563106014149U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 10U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 14U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + aPhaseBWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 4U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + aNonceWordP);
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 18U) + aOrbiterB) + RotL64(aOrbiterK, 28U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 53U));
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_FootBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE1BCAE9741D3CDFBULL + 0xBF6D77DC6095F5DDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA0EDB177D05F1F4DULL + 0xD858AD43F7A0EF6FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9E067FA164E32079ULL + 0xD9325F8F68F84C57ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD917C6B05E8F126DULL + 0xFEF688D09A2A47D9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD0AE96B66A1DA6B9ULL + 0xC5C4E90B2D6C8293ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB5663837EB772E03ULL + 0xD175242FB189617BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEDC5E4A57291F48BULL + 0xBAAD1453723EFCE6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA007711738CEF257ULL + 0xD41FB90AE2F34F50ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB544BFCBF0AA9383ULL + 0xCE584AB3F040C275ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x93A0FA2DB940FEC1ULL + 0xDADA6564F696B496ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBD0A111A9E44265FULL + 0x920613AE33726BD3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8013B2CA713C55CFULL + 0xD3AA0B4DC8130192ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xED7930E32856552FULL + 0xBB91F08BC3378DE6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x926A6316DD2BEFDDULL + 0x91C79F6842EF4B98ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD72846A2792BFCD1ULL + 0xC4EDDB9368FC6A35ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8617C2080759E8FDULL + 0x96790A249EC752B9ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3643U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 5366U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 614U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4079U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3439U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 3227U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 52U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (((aWandererG + RotL64(aIngress, 20U)) + RotL64(aCarry, 23U)) + 2330952702412094686U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 11U)) + 7820188225935060799U) + aNonceWordM;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 53U)) + 9347644591709839145U) + aPhaseDOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 2288624878446846870U) + aNonceWordH;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 47U)) + 9358977729492824128U) + aNonceWordI;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 1858511275052455039U;
            aOrbiterC = (aWandererF + RotL64(aCross, 3U)) + 13715478509322292552U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16413396625604260455U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17714322215518432705U;
            aOrbiterE = RotL64((aOrbiterE * 1904184102419934333U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16188315436202861122U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5564445841368207813U;
            aOrbiterD = RotL64((aOrbiterD * 14125834616162835983U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13717068949900594673U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14143659432287313765U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5729546141908425670U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4297827922736712074U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13631630436759768885U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 829520109395163673U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11547160328525174295U;
            aOrbiterK = RotL64((aOrbiterK * 4759690159673049775U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2907177944512117206U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11100346409065275671U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17927994356809011637U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 1344592529249949068U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6470438516791143572U;
            aOrbiterG = RotL64((aOrbiterG * 13339390828725370475U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterC, 13U));
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 3U)) + aNonceWordO) + aPhaseDWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + aNonceWordB) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 58U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 30U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8802U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 8859U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10101U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 7422U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6191U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8218U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 7282U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 3U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 47U)) + 16160838483846078448U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 15404960896190227946U) + aNonceWordJ;
            aOrbiterE = (((aWandererB + RotL64(aCross, 19U)) + 16904160594024977199U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 21U)) + 17790460246821031802U) + aNonceWordL;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 3U)) + 16395168254086971959U;
            aOrbiterG = (aWandererE + RotL64(aCross, 41U)) + 7484373204039901786U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 18026814691322913510U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15244817793136966450U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5795491730356335666U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 13253529465289332171U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3163873518027801504U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2690791759507349172U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16677948635136515083U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 17898067251167087906U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8028010015006604239U;
            aOrbiterB = RotL64((aOrbiterB * 5601629670521300241U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7304739457289910555U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 6476837815096530043U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 16380545138701113267U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14242499233467960602U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17305645693017634630U;
            aOrbiterK = RotL64((aOrbiterK * 14442976693206929569U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 9772864059444171908U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7897200728282156408U;
            aOrbiterH = RotL64((aOrbiterH * 816306719390807411U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4890999319172950996U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8165132649356094963U;
            aOrbiterG = RotL64((aOrbiterG * 17297706071263690189U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 36U) + RotL64(aOrbiterH, 29U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 19U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterK, 6U)) + aNonceWordA) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 11U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12627U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 12440U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12150U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15999U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 13391U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCarry, 37U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererK + RotL64(aIngress, 40U)) + 13583136155674166402U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 12830472187484919497U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 29U)) + 18081197909484522509U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aWandererI + RotL64(aCross, 57U)) + 8680634051297891550U) + aNonceWordN;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 51U)) + 13939998767458656823U) + aNonceWordE;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 1795730579103692594U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 17369751719734069999U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 224769585901248068U) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4133547085925268180U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2611561365156544735U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7022512056309567391U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10319484359046945495U;
            aOrbiterG = RotL64((aOrbiterG * 3400140531307001933U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 10483878349412282069U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6481381149199985736U;
            aOrbiterE = RotL64((aOrbiterE * 9701719367082506253U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13721077228796934509U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9704818014314175007U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 760445624027740287U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6253040047758584339U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16890211690273641226U;
            aOrbiterF = RotL64((aOrbiterF * 5622534399866057841U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6216227831265032436U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 2023609047004658739U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 3252332895698310147U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9201669637050388263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5106927540934338576U;
            aOrbiterH = RotL64((aOrbiterH * 6368134569042291431U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterF) + aNonceWordG);
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterH, 14U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 37U)) + aOrbiterC) + aNonceWordO);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ) + aNonceWordB) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 27U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 16801U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneA[((aIndex + 21009U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18902U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19894U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16560U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 60U)) + (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 3U)) + 6243113109470883144U) + aNonceWordP;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 46U)) + RotL64(aCarry, 5U)) + 3891552123999605832U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 35U)) + 8758797898587019128U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 21U)) + 1005891374086408851U) + aNonceWordJ;
            aOrbiterC = ((((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 3713426782180050764U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 18358143862391573534U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 27U)) + 17504394029693712404U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5312729289027417014U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2560873623431186029U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16843728573219210173U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16309322822806704211U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10195513918020652600U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14569219741824123715U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2552116263258744287U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7732784879810980089U;
            aOrbiterG = RotL64((aOrbiterG * 15041929399477790999U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16499127570665381507U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 10890036715535519036U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 9065115450010475187U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16288944603478791554U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14542766121469312846U;
            aOrbiterA = RotL64((aOrbiterA * 8435383464425875209U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 5973595239494084696U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1820492719977197097U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16164917159141304405U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10489529555776381736U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6392552206958240484U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 11761477994533503307U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterA, 3U)) + aNonceWordG);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterG, 27U)) + aNonceWordB) + aPhaseDWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterK, 14U)) + aNonceWordO);
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererB, 58U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24205U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((aIndex + 23685U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23634U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24409U)) & S_BLOCK1], 34U) ^ RotL64(aSnowLaneA[((aIndex + 26196U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 964165145848253292U;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 10645976767204934746U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 8241612229349212650U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 30U)) + 4159196033256913347U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 43U)) + 7194795864620233507U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 21U)) + 7638928444536778384U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 51U)) + 11819105916503968109U) + aNonceWordB;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18052213302858186237U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8663575313970041570U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 14131073322476609161U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 16644136720439299786U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16930316530442679864U;
            aOrbiterC = RotL64((aOrbiterC * 2650922074098320859U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16251107616988250593U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7171986193609401665U;
            aOrbiterA = RotL64((aOrbiterA * 3543709971414550087U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17885046834432626644U) + aNonceWordF;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 7757069274715713557U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 15766885299397923879U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2212805322061155615U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6368539134638838822U;
            aOrbiterK = RotL64((aOrbiterK * 13383744883433594259U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5264326094252925613U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6126345334815012938U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17180934809764905307U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13826731214018407061U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6621261811613643620U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2823596473596114171U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 12U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 37U)) + aPhaseDWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 30U)) + aOrbiterD) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31010U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneA[((aIndex + 27912U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28119U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31639U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 31232U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 18U)) + 1888427424966603593U) + aPhaseDOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 5436761445660415091U) + aNonceWordG;
            aOrbiterF = (aWandererI + RotL64(aIngress, 35U)) + 17322876217962143270U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 43U)) + 9728299982740564979U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 301720335271716921U;
            aOrbiterI = ((((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 8069685428854814396U) + aPhaseDOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 51U)) + 1973715500949100991U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 87666408799854155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12195436904339035245U;
            aOrbiterF = RotL64((aOrbiterF * 15427739165893738105U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4578742069143400295U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7828776048774876484U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4047964518501081039U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 17203146364542781833U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16913369550858890466U;
            aOrbiterI = RotL64((aOrbiterI * 13534417587921978507U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9632761514552265402U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9106637671877341286U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9073709119482640391U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15423680889126750876U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6087310684583331882U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8964465129744898619U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 5420955876411796789U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14166807419730848032U;
            aOrbiterD = RotL64((aOrbiterD * 442659738632823751U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8118312450347026824U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4253043584558403086U;
            aOrbiterG = RotL64((aOrbiterG * 5651748455190536467U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterI, 10U)) + aPhaseDWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 50U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + aNonceWordL);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 23U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterD, 41U)) + aNonceWordA);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 43U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + aPhaseDWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_FootBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEF5A7182A5296193ULL + 0xB88FA28431FA5177ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9E0982DA6B814B97ULL + 0x8AC3D0AC6E4DD3C9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9459C5F3E0DC5585ULL + 0xE2DC0543B442634DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x97DB126BE2F7E1BDULL + 0x8F05770FE3C42C33ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE224C1BE5433B0EDULL + 0xFA09AD9F2DE01695ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEDFB00A9D60BE1A3ULL + 0xB5B3CE3300275EEDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA82B98C9F676F6D7ULL + 0x91DF7B82459EE0A8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF4E0A30BED2A0711ULL + 0xBE38ACE0528CC7A2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9413115C5E46AF5BULL + 0x8442AE39BF5C83F3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8B7E62D1EBCE57C1ULL + 0xDDECB3B419DBA56CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE51642B2609FC175ULL + 0xF99E4AE52D567005ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDD8DFAC81AB8E891ULL + 0xA2EE2B4E1CB929CEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x85B628A5DEF0B7DFULL + 0x807325802490AA72ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDD210F0FD925B8AFULL + 0xE0A9C5B7E77A671BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xECB92E2E0FD0D72FULL + 0xADAE9EADFEDF4EBEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8B15E6169E958B79ULL + 0xB782985FB68A80AAULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 2697U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneB[((aIndex + 2117U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4531U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1757U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2509U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5039U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 60U)) + (RotL64(aPrevious, 47U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 15920462086654025436U) + aNonceWordF;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 487844076858004017U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 43U)) + 14502883786442630566U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 53U)) + 3787107318658233674U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 37U)) + 12548777544693755491U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 4907309444075181683U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 50U)) + 18342396700266492072U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 3U)) + 13503051997624242670U) + aNonceWordO;
            aOrbiterG = (aWandererA + RotL64(aCross, 41U)) + 17845742460521374571U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 47U)) + 8640887211877858169U) + aNonceWordE;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 24U)) + 5273913123709097537U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17756844173695563883U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6713055830729302951U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2832836748513174311U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5106468334224035972U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10228769728713526172U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9760310686414358435U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7687649520668883142U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7757480627354711605U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 7222553727737349209U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10876291698508634557U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8149278085586014186U;
            aOrbiterG = RotL64((aOrbiterG * 8577133863470695381U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15592893988925610485U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 8639028256640537165U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 1880655276432963955U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 475660347892196219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1903736092401853832U;
            aOrbiterB = RotL64((aOrbiterB * 8486318978769094799U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12463250192809450953U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7253918448601703982U;
            aOrbiterA = RotL64((aOrbiterA * 3821034106528009129U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5171661020093804486U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11627344933828324146U;
            aOrbiterE = RotL64((aOrbiterE * 5388047063152043277U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6206801139131132815U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9221302203943031377U;
            aOrbiterC = RotL64((aOrbiterC * 12912049016813367241U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1798857939965423979U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5476854168685641232U;
            aOrbiterJ = RotL64((aOrbiterJ * 3884216989250294213U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2816659151953455230U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15920462086654025436U;
            aOrbiterI = RotL64((aOrbiterI * 17843161654734820613U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 10U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + aNonceWordG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterG, 21U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterH, 44U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aPrevious, 6U) + aOrbiterJ) + RotL64(aOrbiterH, 52U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 5608U)) & S_BLOCK1], 54U) ^ RotL64(aInvestLaneC[((aIndex + 10150U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 6496U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 8355U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 8472U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9086U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 7601U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 9654059367478508868U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 26U)) + 6473006635864677427U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 6944184481315853243U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 4061496421939102306U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 47U)) + 15791809275719085463U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 3U)) + 14050798802646323055U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 57U)) + 12072905924741758266U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 23U)) + 17639076509231343896U) + aNonceWordL;
            aOrbiterF = (aWandererI + RotL64(aIngress, 21U)) + 12195388285571234715U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 60U)) + 4325404419499496529U) + aNonceWordB;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 11U)) + 5910567888204238382U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13092940059929942699U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13381962590820308761U;
            aOrbiterJ = RotL64((aOrbiterJ * 6345904465930943295U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15622862439323440527U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14027151901132249793U;
            aOrbiterE = RotL64((aOrbiterE * 2273573821630510087U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4584410023907605157U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15763755180625487157U;
            aOrbiterI = RotL64((aOrbiterI * 6755736130607297639U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17023059745666559199U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5298529579288492971U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2483562793328357721U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2870152867331654736U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12017191100173748848U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 9958191466506480519U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15899529176182436062U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16482713846343388735U;
            aOrbiterA = RotL64((aOrbiterA * 719465695044265601U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12943393531812774449U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9881108254540483225U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8011108108007885059U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3532054586199716750U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7142230313294797435U;
            aOrbiterH = RotL64((aOrbiterH * 14154176174768868421U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 733958394016131587U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2060800099014517137U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 12988885554457108631U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2278498033811574812U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15342071118593803929U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7842196613533603835U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12987212219357101955U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9654059367478508868U;
            aOrbiterB = RotL64((aOrbiterB * 11796100167917742307U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 42U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterG, 50U)) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 56U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 23U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + aNonceWordA) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + aNonceWordN);
            aWandererH = aWandererH + ((RotL64(aIngress, 20U) + aOrbiterI) + RotL64(aOrbiterJ, 5U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 21U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterK, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterC, 52U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterF, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 11098U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 11589U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 14699U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13568U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15601U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 3U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererB + RotL64(aCross, 3U)) + 8402620908307642697U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 11347672014525086047U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 13U)) + 2816462912503401876U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 39U)) + 6940159795470696093U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 23U)) + 9134692490095883851U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 56U)) + 4999455497008026526U) + aNonceWordP;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 47U)) + 5992451460350651332U) + aNonceWordM;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 29U)) + 3417087346651371924U) + aNonceWordD;
            aOrbiterD = (aWandererI + RotL64(aScatter, 37U)) + 3612773820086198270U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 10U)) + RotL64(aCarry, 53U)) + 463398077083428570U) + aNonceWordN;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 11249391303705089012U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17027535139825739501U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 568131384979596481U;
            aOrbiterH = RotL64((aOrbiterH * 5683451044852895957U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4793712537158004047U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10415170179135963622U;
            aOrbiterE = RotL64((aOrbiterE * 13729564030210361415U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2391473979460065630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4240058362680064261U;
            aOrbiterA = RotL64((aOrbiterA * 12375884373396400889U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9963957011090031698U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3325305624067445525U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 3128542681461806309U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2094945647665114693U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10703615640774042674U;
            aOrbiterB = RotL64((aOrbiterB * 12641986098450423751U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3768738815518590289U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15021301790376706827U;
            aOrbiterK = RotL64((aOrbiterK * 14445850924223550339U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10571246886181608316U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5130325144599151793U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 3185251943547657467U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8617523421720966373U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16574597770835250074U;
            aOrbiterF = RotL64((aOrbiterF * 1759209403428937799U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17474733286551120355U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17914672092861237776U;
            aOrbiterD = RotL64((aOrbiterD * 13657291990878792267U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12856557371623447773U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1636296609747335898U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9286345529656087313U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12588848560509679821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8402620908307642697U;
            aOrbiterC = RotL64((aOrbiterC * 2269772223506258147U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 44U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterH, 20U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aCross, 42U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterF, 39U)) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + aNonceWordH);
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterK, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterG, 57U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterI, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19268U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((aIndex + 18462U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 19102U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19175U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneD[((aIndex + 19588U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 36U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (aWandererA + RotL64(aPrevious, 5U)) + 6467297102954816305U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 51U)) + 7921154109831114952U) + aNonceWordK;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 5701131763215638919U) + aNonceWordB;
            aOrbiterI = (aWandererE + RotL64(aIngress, 14U)) + 10022999076719002684U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 4367135243038982316U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 29U)) + 14445846824810383592U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 7683697954545773253U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 39U)) + 17517006750428030899U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 56U)) + 2052484792684025476U) + aNonceWordP;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 53U)) + 6279463052085808926U) + aPhaseEOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 27U)) + 679280153651813684U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2939516520188460569U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1960616434964712325U;
            aOrbiterK = RotL64((aOrbiterK * 15145998415466343039U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12273819390719947361U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5685033154709449397U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 9845666295874714959U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9314494172199500653U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 15757631834636427621U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 15483543888965744529U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10878078046389399574U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3583495913766365232U;
            aOrbiterI = RotL64((aOrbiterI * 2913540984990155225U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7385544065754622301U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16839599460207922881U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 240651605910592561U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13038163804940349251U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2587538594933924000U;
            aOrbiterE = RotL64((aOrbiterE * 3091149760401278671U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13109518583364738004U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2447689055742474261U;
            aOrbiterJ = RotL64((aOrbiterJ * 12100180201235703193U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5752044906692668618U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6637725371036522120U;
            aOrbiterC = RotL64((aOrbiterC * 6021986525167161115U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16549229877442298618U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12825651879441561108U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 9079931351967033993U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16088338999978085987U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12584648360998154782U;
            aOrbiterF = RotL64((aOrbiterF * 2109996837220975261U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7526256599938771686U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6467297102954816305U;
            aOrbiterA = RotL64((aOrbiterA * 9289442676936248653U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 40U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 28U) + RotL64(aOrbiterC, 53U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterK, 5U)) + aPhaseEWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 51U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aCross, 54U) + RotL64(aOrbiterC, 30U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 37U)) + aNonceWordO) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 18U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 35U));
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25900U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((aIndex + 22635U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 23562U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25942U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24792U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22026U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 54U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (((aWandererB + RotL64(aScatter, 26U)) + 5573188770530340913U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aWandererH + RotL64(aCross, 37U)) + 1431772230889897111U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 4809192776429682319U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 5576603692574369341U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 5U)) + 2720143226007220386U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 11U)) + 17220328778565331629U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 29U)) + 9629485808442089423U) + aNonceWordP;
            aOrbiterC = (aWandererE + RotL64(aScatter, 56U)) + 1136998437010390983U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 11893390497814523841U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 41U)) + 1764986431917532370U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 19U)) + 1741014798007010376U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12221368453236547044U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7694538641172350430U;
            aOrbiterK = RotL64((aOrbiterK * 8439120733670016501U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17472344518811560603U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3308740700728172984U;
            aOrbiterG = RotL64((aOrbiterG * 15290400462887712083U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9535358833412446771U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11192312491731312451U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17405609148475445743U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14850451970047190039U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11932493299452443256U;
            aOrbiterE = RotL64((aOrbiterE * 7964808728820467795U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5972619895614731870U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17174497535809891690U;
            aOrbiterB = RotL64((aOrbiterB * 15471084511364572533U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17412894714378898351U) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14675615208706549810U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7864845089606499769U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16116792108013658523U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9702262005960966336U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 970452849653781703U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17337264966818542841U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7004462033775827275U;
            aOrbiterA = RotL64((aOrbiterA * 11943575980344402681U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17499850384482055438U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1839357713256560566U;
            aOrbiterH = RotL64((aOrbiterH * 12943750650487416281U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 8144238113917577524U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 888195876227325908U;
            aOrbiterI = RotL64((aOrbiterI * 7941506708630993709U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5081763359501717653U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5573188770530340913U;
            aOrbiterD = RotL64((aOrbiterD * 9699901099898698965U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 20U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterE, 5U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 54U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + aNonceWordA) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterC, 42U));
            aWandererA = aWandererA + ((((RotL64(aCross, 43U) + RotL64(aOrbiterC, 21U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 53U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterC, 27U));
            aWandererC = aWandererC + (((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 44U)) + aOrbiterK) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 51U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30973U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 29417U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 28060U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28562U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneB[((aIndex + 27800U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCross, 29U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 23U)) + 17470880031634374199U) + aNonceWordJ;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 52U)) + RotL64(aCarry, 27U)) + 757565846006937746U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 35U)) + 9419282475801345674U;
            aOrbiterD = (aWandererA + RotL64(aCross, 19U)) + 2014248014107898196U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 57U)) + 15113928519446490441U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 13U)) + 7346126964886259935U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 3U)) + 5594123113093162359U) + aNonceWordG;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 21U)) + 5659237263369402005U) + aNonceWordL;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 54U)) + RotL64(aCarry, 37U)) + 11565709683423969703U) + aPhaseEOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 47U)) + 16782863743534856287U) + aPhaseEOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 13499100900072115907U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11414447651044205242U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 7545993795121430538U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 10758488381206257261U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11778229237616454988U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2544793391976514665U;
            aOrbiterH = RotL64((aOrbiterH * 4021060413798523299U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9972156716619459164U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17651030383827445664U;
            aOrbiterJ = RotL64((aOrbiterJ * 6742914240706775487U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17439147296849134543U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10021926927948343656U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 18139540407315440909U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9309867875882669289U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14951424455944346337U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10569523948169951309U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2166343974068770659U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11386993629011562026U;
            aOrbiterC = RotL64((aOrbiterC * 3091639433512536097U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5747849744680120960U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4019290369160113026U;
            aOrbiterF = RotL64((aOrbiterF * 5567515306039646735U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3820540009554769592U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8210747198363020939U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16215133106542452509U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3006494852696036003U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2736305345451919450U;
            aOrbiterI = RotL64((aOrbiterI * 11993452696344358247U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6148431711118275178U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6986633012691940738U;
            aOrbiterB = RotL64((aOrbiterB * 15672039482523804893U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7837859154831245165U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 17470880031634374199U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 2153299273348512243U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 6U) + aOrbiterK) + RotL64(aOrbiterF, 53U)) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterK, 13U)) + aPhaseEWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 41U));
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterF, 6U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterD, 43U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 37U)) + aOrbiterE) + aNonceWordK);
            aWandererK = aWandererK + ((((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + aNonceWordA);
            aWandererD = aWandererD + ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterH, 30U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_FootBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA98CB32EFC4234B3ULL + 0x93158C7A437CA897ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEC8686B24297CA67ULL + 0xC34F5A9D4400F79FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEBD8549CD54D8739ULL + 0xD8052144F6D941D0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA05330C33BCD65E3ULL + 0xCEE1C81F17586711ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCAC12D5C7BB88DCDULL + 0xC2DCDE46A51F6FD6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAA4312064721D16FULL + 0x86D49771E758046AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD3D52A59FDB35039ULL + 0x8C58C0CA61C84E3BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEBFEB2070FCD8D0FULL + 0xEA60B4C7D451310EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDDB3D0D4DD739673ULL + 0xD3A3237A44FBB628ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCD577FB2EBDE2EC1ULL + 0x911EA98C111B0BC0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD1E565D446CED83FULL + 0x914B81A44824785EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8C165258B5CC9E2DULL + 0xD744E890F9CD9E84ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x90F3D817FA810BCBULL + 0xFB2576DD53BB2B73ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEE0E18A0682640E9ULL + 0x863C5A3596065CF9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD20A41D7EDC506ADULL + 0xED16314DAD40960DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCE9D1AEA1CADD9F9ULL + 0x9D5845F2FFF92108ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneA, aOperationLaneC, aOperationLaneD, aSnowLaneB, aSnowLaneC, aWorkLaneC, aInvestLaneB, aSnowLaneD, aSnowLaneA, aExpandLaneA, aInvestLaneC, aExpandLaneB, aWorkLaneD, aExpandLaneC, aInvestLaneD
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 547U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 569U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 3543U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 835U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4756U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 762U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 44U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = (aWandererE + RotL64(aIngress, 13U)) + 5573188770530340913U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 5U)) + 1431772230889897111U) + aNonceWordP;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 42U)) + 4809192776429682319U) + aPhaseFOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 37U)) + 5576603692574369341U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 2720143226007220386U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 19U)) + 17220328778565331629U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 58U)) + 9629485808442089423U) + aNonceWordM;
            aOrbiterG = ((((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 1136998437010390983U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 11893390497814523841U) + aNonceWordG;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 1764986431917532370U) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 1741014798007010376U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 13414914086049500731U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12221368453236547044U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7694538641172350430U;
            aOrbiterB = RotL64((aOrbiterB * 8439120733670016501U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17472344518811560603U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3308740700728172984U;
            aOrbiterE = RotL64((aOrbiterE * 15290400462887712083U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9535358833412446771U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11192312491731312451U;
            aOrbiterF = RotL64((aOrbiterF * 17405609148475445743U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14850451970047190039U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11932493299452443256U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7964808728820467795U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5972619895614731870U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17174497535809891690U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15471084511364572533U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17412894714378898351U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14675615208706549810U;
            aOrbiterJ = RotL64((aOrbiterJ * 7864845089606499769U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 16116792108013658523U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9702262005960966336U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 970452849653781703U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17337264966818542841U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7004462033775827275U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11943575980344402681U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 42U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aIngress, 28U) + aOrbiterA) + RotL64(aOrbiterD, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 24U)) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 4U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterB, 10U)) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterF, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererI, 26U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneC
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6475U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 6051U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9396U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 9788U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7837U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9231U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 8664U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 14U)) + 1042610313571524121U) + aNonceWordE;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 3505725321008825582U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 12584654563843782991U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 47U)) + 6645399144515770935U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 3U)) + 3608978423753715584U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 60U)) + 8089198857670370983U) + aNonceWordB;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 35U)) + 15207251813516399879U) + aNonceWordF;
            aOrbiterF = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 9579268660105824516U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 53U)) + 16055044469473802812U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 583811872609805949U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7027491967970873942U;
            aOrbiterC = RotL64((aOrbiterC * 12686754713465826139U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18256061823189677508U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12708429127816136937U;
            aOrbiterA = RotL64((aOrbiterA * 12593886633108075321U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12169216645156306078U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12694325407567795065U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3711789483877261899U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16109994660203297503U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 4234704064165718913U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 730085881474787681U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14119541943554602878U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8777769004811352951U;
            aOrbiterJ = RotL64((aOrbiterJ * 2556957257736134223U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15642663488392549609U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11594468530833278624U;
            aOrbiterF = RotL64((aOrbiterF * 6639306656361601143U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7365350535791499871U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5965170981970155956U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 1898702752753066851U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9115232101451815522U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9433983580038990072U;
            aOrbiterD = RotL64((aOrbiterD * 1951249217843992179U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8810565477444156140U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12081286530401844859U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1991383259486140229U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 24U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterH, 5U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 37U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 53U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 52U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 14095U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 12168U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 14639U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12001U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12379U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererA + RotL64(aScatter, 51U)) + 10812151398716051703U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 18202551453336003710U) + aNonceWordK;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 6U)) + 9434410809101973752U) + aNonceWordC;
            aOrbiterF = (aWandererE + RotL64(aIngress, 19U)) + 12955829998028534045U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 43U)) + 12271740641929640181U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 29U)) + 14009351527014534752U;
            aOrbiterK = (aWandererG + RotL64(aCross, 57U)) + 4316296955679133450U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 34U)) + RotL64(aCarry, 19U)) + 16473324966997442872U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 15735123324965019802U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17656375090484080236U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16066325053456055298U;
            aOrbiterI = RotL64((aOrbiterI * 17912970706985130327U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12908968778503516903U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12761433987676836197U;
            aOrbiterA = RotL64((aOrbiterA * 1023329467480907925U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12737513138040664509U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14535795767570998392U;
            aOrbiterD = RotL64((aOrbiterD * 15560519667062222269U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14370908061811284364U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7001358781208669795U;
            aOrbiterJ = RotL64((aOrbiterJ * 11641248025734015835U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7298578161120090849U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10498302152357484629U;
            aOrbiterF = RotL64((aOrbiterF * 13144110412179037175U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11447343228638006767U) + aNonceWordH;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 18284143620422655675U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 572862190073605651U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5918253208127360199U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 3910541329178205943U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4550654545328228103U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10357053096941367910U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5610891501128498748U;
            aOrbiterH = RotL64((aOrbiterH * 8676370811772047449U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9049881176058575811U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6307599924966452216U;
            aOrbiterB = RotL64((aOrbiterB * 5551444450572055895U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 44U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterF, 24U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 6U) + aOrbiterA) + RotL64(aOrbiterB, 13U)) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterA, 40U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + aOrbiterK) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aInvestLaneC
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18688U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneC[((aIndex + 19953U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 17105U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18328U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((aIndex + 17363U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 11U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (aWandererI + RotL64(aPrevious, 23U)) + 3550722402315312207U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 52U)) + 16724184551669522754U) + aPhaseFOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 981751330116773021U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 57U)) + 7891159229704944868U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 29U)) + 13618396711464799841U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 5969291018449003648U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 14595540413313640042U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 18U)) + 3287990436916111762U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 35U)) + 12534369400200483704U) + aNonceWordA;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2277312067930392274U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10026320559261334353U;
            aOrbiterF = RotL64((aOrbiterF * 11020464940995912637U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11258082063135659551U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1445958517675746990U;
            aOrbiterI = RotL64((aOrbiterI * 10062265337488757971U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 1011298251290970844U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6487834862470043744U;
            aOrbiterH = RotL64((aOrbiterH * 15477913837027179675U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9966279022928268335U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10285993486057704393U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15965714363201157535U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16005362468813966136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 223843444699390781U;
            aOrbiterE = RotL64((aOrbiterE * 665392038954573081U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 18178876294968532775U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12490136112181806806U;
            aOrbiterC = RotL64((aOrbiterC * 16380841616662993709U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8775696166557913635U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16464340319444310842U;
            aOrbiterJ = RotL64((aOrbiterJ * 18111632334728200721U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6296039992673546227U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7152939277656436037U;
            aOrbiterK = RotL64((aOrbiterK * 15183918431501487319U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14066791413416223271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5026743227399908016U;
            aOrbiterA = RotL64((aOrbiterA * 5891343232759075675U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 44U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterD, 24U)) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 34U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterH, 12U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterH, 35U));
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ) + aNonceWordG);
            aWandererA = aWandererA + ((((RotL64(aCross, 30U) + RotL64(aOrbiterI, 3U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aWorkLaneD
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26706U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneD[((aIndex + 25340U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 26074U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22256U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 24800U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 19U)) ^ (RotL64(aCross, 40U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 2974056819475622600U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 7345051759236356098U) + aNonceWordD;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 60U)) + 12738468816846628882U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 3U)) + 7694520596043297922U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 5530753590015084774U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 29U)) + 3776309161718383105U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 19U)) + 784780304358106404U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 35U)) + 8999942326995036509U) + aNonceWordO;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 44U)) + 5194986506064092779U) + aNonceWordJ;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7920040007459652762U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11311997270710107937U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6227571709361790209U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5365231114813547251U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8630110234623825263U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2735881715888325759U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2358235238039571072U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 18059414891616491807U;
            aOrbiterF = RotL64((aOrbiterF * 17150786106857185467U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14526050556461782864U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6937282036603272474U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14954512365270028029U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10105832250694931310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3884223553012098137U;
            aOrbiterG = RotL64((aOrbiterG * 16340956813003906195U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 10385284339549648087U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 1257633893341505930U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 2669950791270500977U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5528890519572824318U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15664241747527713256U;
            aOrbiterI = RotL64((aOrbiterI * 16670884497088220497U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14264122979415331887U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17985061405540198036U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 2729487440173395133U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1663986734997903415U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3706166884286400587U;
            aOrbiterA = RotL64((aOrbiterA * 10549736618301955745U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 39U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 24U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 58U)) + aOrbiterI) + aNonceWordB);
            aWandererF = aWandererF + ((RotL64(aIngress, 52U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterA, 22U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterD, 43U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterB, 29U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27890U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 31786U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 30569U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29252U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31586U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 19U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 9751314027302668907U) + aPhaseFOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 39U)) + 12175450995523107056U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 10U)) + 17519694958730119552U) + aNonceWordJ;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 9093525527925682263U) + aNonceWordB;
            aOrbiterG = (aWandererA + RotL64(aIngress, 47U)) + 3713831321786810138U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 53U)) + 10108355209191835040U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aPrevious, 19U)) + 12956307447311314768U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 5U)) + 1904298513945877359U) + aNonceWordP;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 58U)) + 4658049993308574460U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9826333658248851902U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 12058666914724365134U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 964233873188373939U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2516574707110528099U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13335308331049750235U;
            aOrbiterF = RotL64((aOrbiterF * 5880227828760598587U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8230749255538495304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16536559486797811486U;
            aOrbiterE = RotL64((aOrbiterE * 7097036838156464969U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12387639130570188998U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8459259798142872020U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8001346480955847013U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16083784052002800300U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1957284290736468379U;
            aOrbiterK = RotL64((aOrbiterK * 5046501301740813065U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7349538179311335863U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16395170077006105258U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 4230485452156662763U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3317652065873784068U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5517155804799120700U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9789270651974719183U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5568525912112200094U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9334250662962319598U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 5034887614541768961U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5641394627075994165U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13524971148931512745U;
            aOrbiterC = RotL64((aOrbiterC * 3699457147759854357U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 36U) + aOrbiterI) + RotL64(aOrbiterE, 47U)) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterD, 53U));
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterH, 6U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterI, 35U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 37U)) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_FootBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD48FE4253FEDC2A9ULL + 0x8899950131BDFCD1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x83AA89C88010923BULL + 0xC7FF1637264B25A3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9C9841806C6152BDULL + 0x9F35FACC661CC934ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8246BC7136FDF0F1ULL + 0x92E7B7631A114245ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x95DE6CD52E49BCBBULL + 0xAC26DFF04B26D008ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF68C92D002CC2B77ULL + 0xFE59567D0B661DF1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA245B3A9A9387415ULL + 0xC6545357CFFB4933ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9DFAB86FB7C9594BULL + 0xB7471B92972C955DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB6CFAC474E8B6941ULL + 0xBF19036C2CA7EA41ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x869836281FB4F487ULL + 0x8C1C48D8D84646E2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x96CB4FF38A48D0A7ULL + 0xEE6D19E749C83905ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFE8331D6F915BCBDULL + 0xB06146EAEE806A31ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x91384B169825CF81ULL + 0xC6910C323B127415ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAD0F6A6F2B010CADULL + 0xAAFD93B97F8C4900ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBD9DCA13AEE82CADULL + 0xF2282D9E1661A1C1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8C6E275395A6F089ULL + 0x8D2642F09C95264BULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneC, aWorkLaneA, aFireLaneC, aFireLaneB, aWorkLaneB, aInvestLaneD, aExpandLaneA, aFireLaneD, aExpandLaneB, aFireLaneA, aExpandLaneC, aInvestLaneB
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneA
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneC
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 619U)) & S_BLOCK1], 24U) ^ RotL64(aSnowLaneB[((aIndex + 2468U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 1368U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 4140U)) & S_BLOCK1], 46U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 5131U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 3272U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 41U)) + 6973892330986118220U) + aPhaseHOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 10U)) + 9886813896272094864U) + aNonceWordF;
            aOrbiterG = ((((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 10996306582517553173U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 3U)) + 8490648283899856223U;
            aOrbiterK = (aWandererH + RotL64(aCross, 29U)) + 105141713530704655U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 3114337422810562588U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 980857684690886131U) + aNonceWordE;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6562042345807072665U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15665371138706353619U;
            aOrbiterG = RotL64((aOrbiterG * 8086237578564620623U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 18113013571374375028U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17405346422601997299U;
            aOrbiterK = RotL64((aOrbiterK * 11162604605443005253U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5130876096426182506U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1813821672299154629U;
            aOrbiterF = RotL64((aOrbiterF * 15478100342425611875U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15793814882743306728U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13925299440495476399U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12049601510660117401U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9924458846049579438U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7810034662781768090U;
            aOrbiterC = RotL64((aOrbiterC * 10310594595026622513U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 12812586478656872854U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5709576448057435237U;
            aOrbiterB = RotL64((aOrbiterB * 9101555233909853025U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 7839807649914541516U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 4717944526755429647U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 8515229146471335721U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterB, 56U)) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + aPhaseHWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterF, 5U)) + aPhaseHWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterD, 35U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 35U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneB
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10748U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneC[((aIndex + 8024U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 9514U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6496U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7316U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 10527U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7834U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 50U)) + RotL64(aCarry, 53U)) + 12849591986267890852U) + aNonceWordM;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 8232614804696815750U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 12141567259210877281U) + aNonceWordK;
            aOrbiterB = (aWandererD + RotL64(aCross, 23U)) + 2928641981037885644U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 57U)) + 980733350554783938U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 5U)) + 2683985177993350746U) + aPhaseHOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 29U)) + 14532148403815527355U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7736296629433884203U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 10428437770166310549U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 326634742742373401U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18327174144859461029U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6810436935194432002U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2715987179577753597U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 12606153309690753435U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17123256945895150555U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 13469111258504672565U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9057777759026189541U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16478485918911194442U;
            aOrbiterG = RotL64((aOrbiterG * 11054247078884894131U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18064460487552100483U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11477276762421684083U;
            aOrbiterK = RotL64((aOrbiterK * 3886501230380184395U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 18318375441973295081U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 13849305985380030986U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12962140243967824959U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10240409420338313641U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 18360586077779529086U;
            aOrbiterC = RotL64((aOrbiterC * 18196875422391501927U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 58U) + RotL64(aOrbiterC, 23U)) + aOrbiterB) + aPhaseHWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterG, 60U)) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 37U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + aNonceWordJ);
            aWandererF = aWandererF + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 3U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11482U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((aIndex + 12058U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 14939U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12841U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15485U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (aWandererK + RotL64(aScatter, 27U)) + 11450949896247900941U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 3905542253538116335U) + aNonceWordC;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 57U)) + 9529740545977785305U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 6U)) + 1856876631533143492U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 84253466320181686U) + aNonceWordL;
            aOrbiterK = ((((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 12577480918745432444U) + aPhaseHOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 37U)) + 5625703170397704029U) + aNonceWordB;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 694608607323629282U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3993981243536262204U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 2502835860198146381U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4119215953484892051U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8785040118556157146U;
            aOrbiterK = RotL64((aOrbiterK * 17113521266125471625U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16234403619456882890U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10398727475672860610U;
            aOrbiterF = RotL64((aOrbiterF * 5086871400049644715U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 18327987141759096769U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2645964788056875452U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8778681366114628045U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2859452497983106129U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7196557924940881076U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 14415389907490256711U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 930127943984174668U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15673596916054795749U;
            aOrbiterJ = RotL64((aOrbiterJ * 7505660488733199479U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16673140529110941163U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2258448294877833760U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1821550319748977445U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 28U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 47U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 53U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 34U)) + aOrbiterI) + aNonceWordO) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordG) + aPhaseHWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18189U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 19996U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17071U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19399U)) & S_BLOCK1], 14U) ^ RotL64(aSnowLaneD[((aIndex + 19373U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 22U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 27U)) + 1557680213571812384U) + aNonceWordN;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 11U)) + 7387349725778021121U) + aPhaseHOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 46U)) + RotL64(aCarry, 19U)) + 15379264067601586976U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 3730195724576043708U) + aNonceWordE;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 21U)) + 9637070085323827066U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 1170865717363676184U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 5U)) + 2750833653175252030U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15118992811225568305U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4974092922102988451U;
            aOrbiterA = RotL64((aOrbiterA * 10575977398702460975U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10625719096296719514U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 855167122475471865U;
            aOrbiterB = RotL64((aOrbiterB * 7441090331293158773U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11322911068958340262U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4334591909425429835U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 10059025861172038183U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14263701737208936392U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 678723206735649084U;
            aOrbiterI = RotL64((aOrbiterI * 10823239851733632227U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 15652053114252065230U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1705225940224061401U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3626023093533713579U), 27U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 6826394665732900206U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11902946775066981141U;
            aOrbiterJ = RotL64((aOrbiterJ * 18300629262162694137U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 9802212958998591310U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14001358545610206524U;
            aOrbiterG = RotL64((aOrbiterG * 13172645840788327099U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + aNonceWordO) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 47U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + aNonceWordK);
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 27U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 6U)) + aOrbiterA) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23333U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((aIndex + 26284U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 23100U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26304U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 26634U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 21U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 18087125778766689269U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 41U)) + 13710545066503235196U) + aNonceWordA;
            aOrbiterE = ((((aWandererI + RotL64(aIngress, 50U)) + RotL64(aCarry, 53U)) + 1701939704736254645U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 8064093611384019909U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 19U)) + 16623332751533885431U) + aNonceWordP;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 57U)) + 15590129153794910109U) + aPhaseHOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 11U)) + 7413312683079107383U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4186064478651458810U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5501191643940735954U;
            aOrbiterE = RotL64((aOrbiterE * 14254804649177125269U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11064645242200570835U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13825922087298055833U;
            aOrbiterB = RotL64((aOrbiterB * 7529317892716108867U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5944980709887369970U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8181136916070569646U;
            aOrbiterC = RotL64((aOrbiterC * 395183021205661827U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 15442336949157292482U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11580554435240641337U;
            aOrbiterA = RotL64((aOrbiterA * 6654637892858767739U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11240018128174598322U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2027565596050777471U;
            aOrbiterG = RotL64((aOrbiterG * 18048186560314431815U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16425887196883725233U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16828683527588834095U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 17746289103235902485U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9923829146479008804U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6669171007279929454U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 681823450939955099U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterH, 37U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 60U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 47U)) + aOrbiterB) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterB, 29U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterA, 3U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32064U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 32682U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30940U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31661U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 30844U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 40U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (aWandererB + RotL64(aIngress, 28U)) + 3236820517816085022U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 741288875914097926U) + aNonceWordJ;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 8417246926007729580U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 19U)) + 9715717805774537170U) + aNonceWordB;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 57U)) + 14360243844821619482U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 10760908100206775334U) + aPhaseHOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 51U)) + 3434641779946167811U) + aNonceWordD;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 7885568822756234567U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3041563437672051294U;
            aOrbiterK = RotL64((aOrbiterK * 11440300917533482297U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15761355327564963516U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1158633562785937421U;
            aOrbiterG = RotL64((aOrbiterG * 15511324886867188235U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9338581575871970653U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9172038894262857354U;
            aOrbiterI = RotL64((aOrbiterI * 3110871165285625807U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14653924713599790081U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3854497592598563309U;
            aOrbiterB = RotL64((aOrbiterB * 11737111068815795303U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16286980180327600557U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5092583772591249756U;
            aOrbiterC = RotL64((aOrbiterC * 13955105624639442903U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4288397994175567333U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15584236478994873104U;
            aOrbiterH = RotL64((aOrbiterH * 1860480595862755379U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5557463939827483792U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2659814275753280856U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17702430405693184643U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 42U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + aNonceWordO);
            aWandererA = aWandererA + ((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 30U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterC, 13U)) + aNonceWordP);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_FootBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2102U)) & W_KEY1], 34U) ^ RotL64(aKeyRowReadB[((aIndex + 2554U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 24U)) & W_KEY1], 22U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 748U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 30U) + RotL64(aCross, 43U)) ^ (RotL64(aCarry, 13U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 56U)) + 4970414922752555648U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 9462756592787669327U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 3948790686662213095U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 14542857212241578311U;
            aOrbiterK = (aWandererD + RotL64(aCross, 5U)) + 3387479009827029547U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 34U)) + 1411421370057797877U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 23U)) + 16894451466895681236U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 27U)) + 12727136462290223542U) + aPhaseAOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 11U)) + 4625389198191960525U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3471881403786164913U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6433115856048534831U;
            aOrbiterI = RotL64((aOrbiterI * 9363233870194144053U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9825592965466157982U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1553125767261293088U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 411535191177308781U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9951616357109647617U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11231080382787286889U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14024961994986659187U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13419663264017317947U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4835055642466215566U;
            aOrbiterJ = RotL64((aOrbiterJ * 17898065852351759171U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14558747666410946768U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13120938960926874504U;
            aOrbiterB = RotL64((aOrbiterB * 5681766019285559739U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11910501376797343986U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15074100100781785300U;
            aOrbiterD = RotL64((aOrbiterD * 228976960937473851U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12415377930578091821U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14882039078390681802U;
            aOrbiterC = RotL64((aOrbiterC * 13855446647753150713U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8094338361713756895U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5478280604704108822U;
            aOrbiterF = RotL64((aOrbiterF * 18062931724700600993U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6977017654546871841U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4131602217285988962U;
            aOrbiterA = RotL64((aOrbiterA * 11865422227883712419U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + aPhaseAWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterA, 38U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 27U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 60U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3441U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4569U)) & W_KEY1], 24U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4291U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4674U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 54U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererC + RotL64(aScatter, 53U)) + 13296600294247799698U;
            aOrbiterF = (aWandererI + RotL64(aCross, 13U)) + 5818503518080877515U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 19U)) + 6735784238734173597U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 6U)) + 7368398209488856201U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 961734029066455638U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 35U)) + 797011946660892011U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 12841876018396622350U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 16213253970483895623U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 28U)) + 15186950557113470375U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5117930310827477341U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12265429373166094162U;
            aOrbiterD = RotL64((aOrbiterD * 1522823535151532249U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13920531346698601568U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14695405206998211456U;
            aOrbiterJ = RotL64((aOrbiterJ * 13950964363414164279U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7851960904825938443U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9501511171732550190U;
            aOrbiterF = RotL64((aOrbiterF * 5614164120361489613U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5663365182245722077U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9607860124321315555U;
            aOrbiterC = RotL64((aOrbiterC * 3461820361914280601U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18171052650586819280U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3442698321538580861U;
            aOrbiterA = RotL64((aOrbiterA * 6317525514963824829U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1491052813469258970U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3956599824067616133U;
            aOrbiterH = RotL64((aOrbiterH * 2928600779267623085U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10963841237346073453U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2303020125591252534U;
            aOrbiterI = RotL64((aOrbiterI * 9969099842343321981U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14503856057958162356U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11147548150090597694U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11856382308792700441U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9191681438318311481U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13556072770381999852U;
            aOrbiterK = RotL64((aOrbiterK * 18316231099054203683U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 36U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterK, 11U));
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterH, 54U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterI, 39U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + aPhaseAWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 34U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 36U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7755U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6827U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7909U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8111U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5662U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 36U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererB + RotL64(aIngress, 57U)) + 1457104756581596530U;
            aOrbiterK = (aWandererC + RotL64(aCross, 53U)) + 6127240317844622874U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 38U)) + RotL64(aCarry, 23U)) + 16492290056044189421U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 10963676850938416468U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 5U)) + 4872917367399752405U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 27U)) + 15218882377875616148U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 13U)) + 5934166612122118251U) + aPhaseAOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 43U)) + 14215280930872003003U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 48U)) + RotL64(aCarry, 37U)) + 11428034799044600979U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5453003654321728726U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14273775120265649389U;
            aOrbiterA = RotL64((aOrbiterA * 5139018128323795309U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 328723770018440271U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13032190719588211088U;
            aOrbiterE = RotL64((aOrbiterE * 13363368478932798315U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 2386881543033598494U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1649501123340887116U;
            aOrbiterF = RotL64((aOrbiterF * 11148976582360499033U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16462401546754210583U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1510579201823042227U;
            aOrbiterG = RotL64((aOrbiterG * 16287912400104043275U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6889066000014251983U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11324594596597724357U;
            aOrbiterJ = RotL64((aOrbiterJ * 15344987814648586023U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12237796033168436537U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17306069670330000343U;
            aOrbiterB = RotL64((aOrbiterB * 3167451351403385259U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14197284538008811658U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4754134852883071927U;
            aOrbiterC = RotL64((aOrbiterC * 3484427259538998699U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17201907781639753736U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8318419319239859855U;
            aOrbiterI = RotL64((aOrbiterI * 10320390501983802091U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16012488623961565780U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15583721012865354925U;
            aOrbiterK = RotL64((aOrbiterK * 10656414363201743961U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 40U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 14U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 24U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 37U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterK, 57U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + aPhaseAWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 51U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 30U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 41U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererK, 54U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10534U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 10509U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(mSource[((aIndex + 9218U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 9169U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10297U)) & W_KEY1], 36U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8726U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 22U)) + 14179205183062705133U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 210032324058740920U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 51U)) + 7387115089142500152U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 17583362781238061430U) + aPhaseBOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 4991442849150005943U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 60U)) + 2891376254689854555U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 43U)) + 10523274382407446239U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 3U)) + 3861893764676218667U) + aPhaseBOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 11U)) + 3366674459852093746U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5898492634386601145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7047353571244768721U;
            aOrbiterH = RotL64((aOrbiterH * 2257518291062508467U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14374108805453186316U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8763667021501226510U;
            aOrbiterE = RotL64((aOrbiterE * 7694695426430267863U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 18261523829316379575U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 650477532238860965U;
            aOrbiterC = RotL64((aOrbiterC * 8291758490821819851U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2162326554604894042U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5776546692501825278U;
            aOrbiterJ = RotL64((aOrbiterJ * 14911545784585246537U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3501863793638415049U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14853789267425352958U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10590325397179928739U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15399673014671329743U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12253428583438990426U;
            aOrbiterD = RotL64((aOrbiterD * 12052855472196447849U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13202953937621953839U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7547616636832698398U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9533399972562428073U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15709801946594868318U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12458677982746610971U;
            aOrbiterG = RotL64((aOrbiterG * 6662570874316418993U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6957370791367530127U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10511379961344950861U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15551333099264031337U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 36U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 4U) + aOrbiterB) + RotL64(aOrbiterD, 60U)) + aPhaseBWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterC, 13U));
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 39U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 48U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 36U) + aOrbiterG) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterH, 21U));
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12332U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 12770U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12661U)) & W_KEY1], 5U) ^ RotL64(mSource[((aIndex + 12977U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13410U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13454U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12517U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 12632404972795375757U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 51U)) + 5351879979055988456U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 39U)) + 3597737727467443413U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 14U)) + 2830846754917852318U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 17311925960294518018U) + aPhaseBOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 29U)) + 2083584640523695383U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 15049343611387010158U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 19U)) + 6443050378205811147U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 34U)) + 6021965178697344070U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5080289878758029976U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 576927745306972983U;
            aOrbiterJ = RotL64((aOrbiterJ * 16008958833683246115U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4728489691382690859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6184355840165758855U;
            aOrbiterI = RotL64((aOrbiterI * 1515043910404156423U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11220539885798595450U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11091438724966718214U;
            aOrbiterG = RotL64((aOrbiterG * 8225347114759391961U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17184210490020062419U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2150997767099116408U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8058553821648892499U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7021953562676903717U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17159676348343312834U;
            aOrbiterC = RotL64((aOrbiterC * 13877284519668483549U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10367891770525239784U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11922478487264201233U;
            aOrbiterF = RotL64((aOrbiterF * 9195137452661956029U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17815162358981720634U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9582631251085100284U;
            aOrbiterH = RotL64((aOrbiterH * 11838992994130850483U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 872593750259572264U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17832330100262167302U;
            aOrbiterA = RotL64((aOrbiterA * 1114416841510028467U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16601139856969287418U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14931287111691324985U;
            aOrbiterD = RotL64((aOrbiterD * 16757174577841001179U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 50U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 12U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 27U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 18U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 40U));
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterF, 35U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 22U) + aOrbiterF) + RotL64(aOrbiterB, 51U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15109U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15822U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15814U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15310U)) & W_KEY1], 3U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 16157U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14977U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14132U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 51U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererK + RotL64(aCross, 30U)) + 6469584119078165548U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 39U)) + 14329756366517987910U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 57U)) + 12890831797059772123U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 3164503807500018990U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 5U)) + 177531431387646836U) + aPhaseBOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aScatter, 47U)) + 3167421392893561015U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 2813174781844753460U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 10U)) + 10953270419153249857U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 16911518309710356951U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6616750447844893150U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10276741398025985982U;
            aOrbiterC = RotL64((aOrbiterC * 6824712685896987133U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6206043608461213208U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12021552904553405793U;
            aOrbiterF = RotL64((aOrbiterF * 10023362889960174909U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15283586234744144846U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 5923238786775948571U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8200882393521882651U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11044014510971660078U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9351141024085076044U;
            aOrbiterJ = RotL64((aOrbiterJ * 13316079344614432317U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17703395981862992420U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10154548848376027087U;
            aOrbiterG = RotL64((aOrbiterG * 12324478347590509035U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8836420852291617425U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10193385413543886344U;
            aOrbiterH = RotL64((aOrbiterH * 824935982418585449U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8248580084535685190U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3910083671888152974U;
            aOrbiterA = RotL64((aOrbiterA * 17825311776715895927U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12350341628569930642U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2565977481575002842U;
            aOrbiterD = RotL64((aOrbiterD * 18233446879833776677U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9271041067874027417U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14289254596554201861U;
            aOrbiterE = RotL64((aOrbiterE * 7985522692852251413U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 50U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 36U) + RotL64(aOrbiterG, 57U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterC, 6U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterK, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aPrevious, 50U) + aOrbiterC) + RotL64(aOrbiterA, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 47U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + RotL64(aOrbiterE, 26U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18988U)) & S_BLOCK1], 36U) ^ RotL64(aKeyRowReadA[((aIndex + 16996U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 18746U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 18167U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18074U)) & W_KEY1], 21U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18277U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 19077U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 36U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererI + RotL64(aIngress, 41U)) + 2177539223979303669U;
            aOrbiterH = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 3962004686551521471U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 37U)) + 8457602312617147662U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 23U)) + 18011802451816510632U) + aPhaseCOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 47U)) + 9046101759168876832U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 5U)) + 11135620637431969597U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 18U)) + 15913029940697999701U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 16304193109948135982U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 13U)) + 13208892298820080981U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4182377898949419225U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13970137023071326151U;
            aOrbiterB = RotL64((aOrbiterB * 9075061559681739865U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8402396284835248583U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8859190834060657829U;
            aOrbiterE = RotL64((aOrbiterE * 13552418608113716117U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9760005337757990392U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14108277760135744897U;
            aOrbiterJ = RotL64((aOrbiterJ * 4474681104256093885U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12226316121949012350U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3456392186754113960U;
            aOrbiterA = RotL64((aOrbiterA * 8704729827929941215U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5004087958637038973U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7176881295123125567U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15272157962928021009U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10889800478505074438U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13728832441482547824U;
            aOrbiterK = RotL64((aOrbiterK * 17588477761978646139U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17345665880706866772U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 301139993853297566U;
            aOrbiterD = RotL64((aOrbiterD * 5812445396758354505U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2061389844760610160U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13631862266139238355U;
            aOrbiterH = RotL64((aOrbiterH * 143613352104722701U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10767186080827509622U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4893486019456886013U;
            aOrbiterC = RotL64((aOrbiterC * 5194746459545610901U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 12U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 34U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + aPhaseCWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterA, 36U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19336U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 20009U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21740U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20604U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19127U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21628U)) & W_KEY1], 47U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21628U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21748U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCross, 11U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererH + RotL64(aIngress, 58U)) + 15904465836916519864U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 17725629806317789307U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 41U)) + 13794170125914914828U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 2149055907476874332U;
            aOrbiterI = (aWandererD + RotL64(aCross, 19U)) + 5342047776745074649U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 34U)) + 8268148484060546838U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 10821151364028563719U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 3U)) + 4294213820894407378U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 13U)) + 10884726101307943090U) + aPhaseCOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16432210042202444824U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15196602644336228055U;
            aOrbiterK = RotL64((aOrbiterK * 12680438355124070237U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14117787670220328165U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 219833877949480215U;
            aOrbiterI = RotL64((aOrbiterI * 10736293047771972173U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3326396981881473962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14918513066311426279U;
            aOrbiterH = RotL64((aOrbiterH * 14269763278564574663U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11795234681370163206U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3068267285352664813U;
            aOrbiterA = RotL64((aOrbiterA * 15746255933920904619U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 245233356957999496U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 709926406353796673U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13627039596842073595U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5378105439430271038U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10114555061122044430U;
            aOrbiterC = RotL64((aOrbiterC * 5351295043424885549U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13233010815716769713U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8231291294833548389U;
            aOrbiterD = RotL64((aOrbiterD * 10840516135212753869U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7160760224172419829U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14767926435411546785U;
            aOrbiterJ = RotL64((aOrbiterJ * 1643485739468851073U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4464245330038080103U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15778166658285494712U;
            aOrbiterF = RotL64((aOrbiterF * 13980891936095282989U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterA, 43U));
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 30U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterF, 11U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 58U) + aOrbiterH) + RotL64(aOrbiterD, 19U));
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 24U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 53U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterF, 47U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 28U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23649U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 23162U)) & W_KEY1], 48U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22953U)) & W_KEY1], 27U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22399U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23066U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23060U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22531U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22563U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 37U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aPrevious, 51U)) + 5906639480605353429U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 5293518570213287605U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 19U)) + 15383185501428521377U) + aPhaseCOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 38U)) + RotL64(aCarry, 41U)) + 15364072512743978902U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 5U)) + 4525473357144014271U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 10400911938125603074U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 47U)) + 16417506293824627550U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 23U)) + 2419329331753341815U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 56U)) + 14929222427923332069U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16771573504983922586U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1863466450051787622U;
            aOrbiterE = RotL64((aOrbiterE * 2585626547126027053U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12895350137096692415U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3700979086526298327U;
            aOrbiterK = RotL64((aOrbiterK * 10279730254867618193U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1977099106211282426U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6144698304096915742U;
            aOrbiterI = RotL64((aOrbiterI * 5039822990560519609U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3858895556659724975U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1283646340363435327U;
            aOrbiterF = RotL64((aOrbiterF * 11622421841377018069U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6240532051889108891U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 757364889381634634U;
            aOrbiterJ = RotL64((aOrbiterJ * 943852137901972945U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5272945693977418174U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6850528198786172283U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1966383079897679953U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14431587733859573714U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16124590257870999553U;
            aOrbiterC = RotL64((aOrbiterC * 7755796211433191143U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14912695018110241411U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11098623474413346520U;
            aOrbiterA = RotL64((aOrbiterA * 15167688959990872051U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3484847683376368686U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2295388097292719800U;
            aOrbiterG = RotL64((aOrbiterG * 1240808318176106909U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 38U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterA, 6U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterI, 23U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 39U)) + aOrbiterA) + aPhaseCWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB + ((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 53U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 13U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26640U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 26443U)) & W_KEY1], 56U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26693U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 26450U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26197U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25186U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27094U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneB[((aIndex + 25721U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 40U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 11039986441331892533U) + aPhaseDOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aCross, 56U)) + 6256024955965426119U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 35U)) + 9857443189988995666U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 11900944813380998208U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 23U)) + 8422577734978875541U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 52U)) + 3100835100713928724U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 11871553509810206993U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 39U)) + 17614749493763417027U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 11U)) + 3638372131856199916U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6582275259281025770U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17016882418498941958U;
            aOrbiterF = RotL64((aOrbiterF * 4269869255230867823U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1747214688658984715U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9356088987044015278U;
            aOrbiterA = RotL64((aOrbiterA * 16221733545319753695U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4056238112133473456U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16013150119949532998U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12913648646318115315U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16076621211111834889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9940824359571581765U;
            aOrbiterG = RotL64((aOrbiterG * 11624767861336495331U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15624084004784515753U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7630989544834680335U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12261063237156822067U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18003586430673313786U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1654118743290334161U;
            aOrbiterH = RotL64((aOrbiterH * 1153250137357176071U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3254189676528343910U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15629083361573065165U;
            aOrbiterD = RotL64((aOrbiterD * 17024833368570949107U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10056859810555674806U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15976683222786846254U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2801754232182942635U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11872378594829637933U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7633773773528713489U;
            aOrbiterC = RotL64((aOrbiterC * 8218288492011593353U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 12U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 60U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterD, 39U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterG, 27U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterJ, 20U)) + aOrbiterH);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterD, 11U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterH, 53U));
            aWandererB = aWandererB + ((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29167U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneD[((aIndex + 28585U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28657U)) & W_KEY1], 22U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28714U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27921U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27695U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27806U)) & S_BLOCK1], 50U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27417U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 27U)) + (RotL64(aCarry, 60U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aScatter, 29U)) + 16124889768301047791U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 11912338587186717280U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 24U)) + RotL64(aCarry, 3U)) + 8594012868813114354U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aPrevious, 43U)) + 18281043566156682815U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 19U)) + 16853106130200942302U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 57U)) + 2611212958619673086U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 50U)) + RotL64(aCarry, 47U)) + 18039472325066855180U;
            aOrbiterH = (aWandererG + RotL64(aCross, 35U)) + 14495785571345122046U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 13U)) + 4556063793412832418U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14896419970271244358U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 880028529183500036U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14228281807461251361U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2379557167489415783U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11854373946064529806U;
            aOrbiterF = RotL64((aOrbiterF * 150755294320438887U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1487252775956449964U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12777924204511625545U;
            aOrbiterJ = RotL64((aOrbiterJ * 1366019527386994789U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15998631485222477969U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8864212892296191613U;
            aOrbiterE = RotL64((aOrbiterE * 579242788050369815U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17069347835763226743U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7443008171694679791U;
            aOrbiterH = RotL64((aOrbiterH * 748894368884566607U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17334256152350782002U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8986626119086556393U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2258172145924120235U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8528180968228358674U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12702290928064582589U;
            aOrbiterG = RotL64((aOrbiterG * 15673603224146737631U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7742438100860023610U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3729687240959702198U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3756794766163746783U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 426129097367382096U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16782175452274911213U;
            aOrbiterK = RotL64((aOrbiterK * 1041477289638333659U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 48U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 14U) + aOrbiterH) + RotL64(aOrbiterK, 48U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 43U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aScatter, 10U) + RotL64(aOrbiterI, 39U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + aPhaseDWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterE, 18U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 48U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31597U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32617U)) & W_KEY1], 22U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31110U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32378U)) & S_BLOCK1], 28U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32431U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31580U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 51U)) + 3339283916456813609U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 30U)) + RotL64(aCarry, 21U)) + 11339086426180649584U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 16819191669329316585U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 43U)) + 8361916937762630725U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 23U)) + 18031328374429899857U) + aPhaseDOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 5U)) + 18261756894092897276U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 19U)) + 4250319792907645666U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 38U)) + RotL64(aCarry, 3U)) + 1492411503643460886U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 57U)) + 17369549067879344180U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7301713524358676722U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2985193736033012535U;
            aOrbiterJ = RotL64((aOrbiterJ * 7473297294949338265U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14086975808140927408U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10390516547834639800U;
            aOrbiterF = RotL64((aOrbiterF * 11441293212275890819U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 18205555540941493267U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16967799565443938873U;
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9209505304067579944U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3522631966146762306U;
            aOrbiterD = RotL64((aOrbiterD * 3441982898533162599U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8811497120829041188U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14707301680850257294U;
            aOrbiterK = RotL64((aOrbiterK * 11383709499376464085U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10080595991787801029U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6822892187784299166U;
            aOrbiterA = RotL64((aOrbiterA * 7417016898027778287U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1981637172055758689U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16463077485583119324U;
            aOrbiterI = RotL64((aOrbiterI * 2876782050665869121U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8383837717361569465U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2788511294985017326U;
            aOrbiterE = RotL64((aOrbiterE * 2809163242875130677U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3529607472855930041U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8850940802020173766U;
            aOrbiterH = RotL64((aOrbiterH * 7821450253655655943U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 24U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterG, 52U));
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterH, 47U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterH, 19U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aPrevious, 48U) + aOrbiterI) + RotL64(aOrbiterE, 56U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 20U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_FootBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneC, aInvestLaneD, aFireLaneD, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 492U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 36U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1597U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5087U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 3632U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 13U)) ^ (RotL64(aCarry, 42U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 12692813903177772178U;
            aOrbiterK = (aWandererH + RotL64(aCross, 39U)) + 7112496446691277899U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 47U)) + 2112247138290568813U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 5U)) + 3699421080882855947U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 22U)) + RotL64(aCarry, 39U)) + 13761832028354380922U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 11U)) + 9243822514887600214U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 6863833516853046129U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8863897995943098018U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13346785686701467520U;
            aOrbiterH = RotL64((aOrbiterH * 18074843497158380703U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15309543066305531619U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17515530938817919111U;
            aOrbiterI = RotL64((aOrbiterI * 16625193986319048245U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 760493237816424254U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7282586354117620860U;
            aOrbiterD = RotL64((aOrbiterD * 2327153408185290635U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4129706068526969105U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7020175432730888755U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10095158356907592239U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9102258982216515596U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10822031305361453690U;
            aOrbiterK = RotL64((aOrbiterK * 2036205056490578491U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12571477440964330246U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8436347026653095199U;
            aOrbiterA = RotL64((aOrbiterA * 17930734781213681573U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14214789872073941940U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12915911919403385001U;
            aOrbiterF = RotL64((aOrbiterF * 13161681603528031511U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 27U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 21U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneC
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9126U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 7338U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 7518U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9913U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 5584U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 35U)) + 16451272412693907816U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 10099485419723255462U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 17668900099534923192U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 10U)) + 5497093724143181753U) + aPhaseEOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 27U)) + 10354044773550071706U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 12728258851198019099U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 47U)) + 4144050505314242618U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14133805325480076530U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 308863673210602899U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2672613556981540433U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11741180130160569753U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12926863156769180448U;
            aOrbiterF = RotL64((aOrbiterF * 9726030996091054939U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 211920854786494259U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13234608842479411078U;
            aOrbiterE = RotL64((aOrbiterE * 2556747209733759467U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9164711974854618892U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6667377062281954219U;
            aOrbiterB = RotL64((aOrbiterB * 2603737166987437649U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4559040002406721850U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1749875480850675109U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15822640067349481089U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9555365165561936366U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 18289733999504213574U;
            aOrbiterJ = RotL64((aOrbiterJ * 14156217554673229429U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8727162691639622461U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 291406782452963706U;
            aOrbiterK = RotL64((aOrbiterK * 8413500075082350243U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 52U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterA, 13U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 50U)) + aOrbiterA) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 10U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneD
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14785U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 11476U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 14799U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 16287U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11278U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13878U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 12U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 2168513956284366370U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 35U)) + 10290361969974613111U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 11U)) + 15673836275828498050U;
            aOrbiterK = (aWandererA + RotL64(aCross, 21U)) + 16600540024145812236U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 29U)) + 9428052101528111892U) + aPhaseEOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 12763657928312763377U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 54U)) + RotL64(aCarry, 51U)) + 10751286982008662485U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1708230173038057979U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4011389705422783816U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11692237130784795961U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11704428328093077714U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2055336619674699284U;
            aOrbiterI = RotL64((aOrbiterI * 6374289210096410907U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1870865272102705804U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3574214263751923179U;
            aOrbiterA = RotL64((aOrbiterA * 13132083406834413563U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 984611970726966186U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15207945449947643672U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9539470161576639981U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4181398506373973169U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15222345431506025949U;
            aOrbiterD = RotL64((aOrbiterD * 6925143692628659467U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15023513452326240962U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14965669361708810699U;
            aOrbiterJ = RotL64((aOrbiterJ * 587008860996713147U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7985755518735406360U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 225592097619240187U;
            aOrbiterG = RotL64((aOrbiterG * 2313509354133400439U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterG, 44U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterI, 11U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterD, 37U));
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 51U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterA, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19343U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((aIndex + 17366U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19393U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16414U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20911U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 21272U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 4U)) + (RotL64(aPrevious, 27U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 12311607308490066301U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 13100864684740679846U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 41U)) + 13697304189274329704U) + aPhaseEOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 9047976902871216732U) + aPhaseEOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 47U)) + 2147897579538537888U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 56U)) + 2072444829390996142U;
            aOrbiterB = (aWandererA + RotL64(aCross, 27U)) + 2129307836981020908U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10663145333751112064U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15019844390503785459U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7442321463110790449U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5460865577557928142U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15806522559993224197U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8722932687972240099U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6361113778657833389U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8306013884615042570U;
            aOrbiterB = RotL64((aOrbiterB * 8234258702656728667U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4038420580499706912U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11908091484457158973U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3964111175645156719U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11133912466611921250U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2469227904206936928U;
            aOrbiterD = RotL64((aOrbiterD * 2704438771198001599U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13234017916788297295U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9061117693840451988U;
            aOrbiterK = RotL64((aOrbiterK * 3637440416741459419U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12013423690843812324U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14371779015144617412U;
            aOrbiterC = RotL64((aOrbiterC * 3359568073302062667U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + aPhaseEWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterC, 48U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 21U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterK, 3U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 30U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26615U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((aIndex + 26329U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 26893U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25942U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 24057U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 24856U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 54U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererA + RotL64(aIngress, 57U)) + 3236820517816085022U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 741288875914097926U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 8417246926007729580U) + aPhaseEOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aPrevious, 35U)) + 9715717805774537170U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 5U)) + 14360243844821619482U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 10760908100206775334U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 42U)) + 3434641779946167811U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7885568822756234567U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3041563437672051294U;
            aOrbiterB = RotL64((aOrbiterB * 11440300917533482297U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15761355327564963516U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1158633562785937421U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15511324886867188235U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9338581575871970653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9172038894262857354U;
            aOrbiterC = RotL64((aOrbiterC * 3110871165285625807U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14653924713599790081U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3854497592598563309U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11737111068815795303U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16286980180327600557U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5092583772591249756U;
            aOrbiterE = RotL64((aOrbiterE * 13955105624639442903U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4288397994175567333U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 15584236478994873104U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1860480595862755379U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5557463939827483792U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2659814275753280856U;
            aOrbiterI = RotL64((aOrbiterI * 17702430405693184643U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 27U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 19U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 39U)) + aOrbiterA) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterI, 58U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31827U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((aIndex + 27910U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31455U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28940U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30352U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 28318U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 51U)) + 12426357877879529292U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 5U)) + 12604900366173639176U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 11U)) + 13511119007338929401U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 35U)) + 9878720081166788060U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 18U)) + RotL64(aCarry, 11U)) + 15463195409806395076U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 6407922778852833423U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 7690427254160734016U) + aPhaseEOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18030974031722143619U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17983938038322737041U;
            aOrbiterB = RotL64((aOrbiterB * 12479365337221685413U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16605512170117753884U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 681802273302348322U;
            aOrbiterI = RotL64((aOrbiterI * 14608920184802647123U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15550312921312083819U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17824154101711884508U;
            aOrbiterJ = RotL64((aOrbiterJ * 7358612830654795357U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1939207786756735430U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3132864634777826569U;
            aOrbiterF = RotL64((aOrbiterF * 13606281919426730325U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12822929773923954849U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16576106045887115660U;
            aOrbiterG = RotL64((aOrbiterG * 16370914370769903051U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2398825881649235260U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13700821892926092479U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10830623703416956043U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2439833784883391606U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15870638514107637833U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3797380922767479287U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + aPhaseEWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 11U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 58U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 20U) + aOrbiterI) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_FootBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneD, aSnowLaneA, aInvestLaneC, aInvestLaneA, aSnowLaneB, aExpandLaneB, aWorkLaneA, aInvestLaneD, aWorkLaneB, aInvestLaneB, aWorkLaneC, aExpandLaneA
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneD backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3609U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 5114U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1574U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2058U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3639U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 512U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 7722279280863371124U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 10U)) + 11584220561732385598U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 7834679350105534657U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 13U)) + 11347994382444180879U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 29U)) + 9449903188047063431U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 52U)) + RotL64(aCarry, 37U)) + 6516243976652795170U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 39U)) + 8420815253991184777U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 21U)) + 9081386852515170937U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 23U)) + 14375955191735286867U) + aPhaseFOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aPrevious, 5U)) + 880757589768436072U;
            aOrbiterE = (aWandererK + RotL64(aCross, 47U)) + 3349856625725164229U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7826309957607577207U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8057435761214313635U;
            aOrbiterH = RotL64((aOrbiterH * 4718430712767038607U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9565237500443303103U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15893066735310588501U;
            aOrbiterB = RotL64((aOrbiterB * 8457633439171452397U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3276844534476430842U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6828644383891274120U;
            aOrbiterA = RotL64((aOrbiterA * 979580351653410157U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2815676923011504251U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5030251870850928417U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7075653570570819253U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13464083008377887034U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8994560761846897590U;
            aOrbiterD = RotL64((aOrbiterD * 9892839554658865143U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8398813387154468736U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8136429428340910892U;
            aOrbiterG = RotL64((aOrbiterG * 3348811490733577295U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 418587250696862341U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4111667833838312094U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 860949442143849147U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6075478294190926371U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2208124955874142264U;
            aOrbiterE = RotL64((aOrbiterE * 15741988616251072075U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4726538724576443010U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6524078248882840425U;
            aOrbiterI = RotL64((aOrbiterI * 9784875566721689069U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14521003220464811621U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16916247868211621303U;
            aOrbiterK = RotL64((aOrbiterK * 1911638054294853877U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 18207293125461843123U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7722279280863371124U;
            aOrbiterC = RotL64((aOrbiterC * 14303108475807941791U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 24U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 29U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 12U) + aOrbiterH) + RotL64(aOrbiterF, 53U));
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 58U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 23U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterH, 41U)) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 51U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 60U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterF, 43U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8712U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 5711U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8621U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((aIndex + 9842U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5740U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9477U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 7522U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 34U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 43U)) + 15910560457440369082U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 13U)) + 17953072986407436888U;
            aOrbiterD = (aWandererK + RotL64(aCross, 35U)) + 15446940721193538669U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 37U)) + 3020785262774422009U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 23U)) + 7001288645424994404U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 13385250665458462689U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 26U)) + RotL64(aCarry, 11U)) + 4841895644623005949U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 13053476783239482065U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 41U)) + 641996979335975244U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 53U)) + 16211238020928688299U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 46U)) + 12715448751323279480U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17784406727699995290U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16626339815786580778U;
            aOrbiterD = RotL64((aOrbiterD * 13940754474750138041U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9035070625716345139U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6085848172494001945U;
            aOrbiterE = RotL64((aOrbiterE * 10405728912339646693U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1177103851507561053U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2281901691017816407U;
            aOrbiterC = RotL64((aOrbiterC * 3142197009403602497U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9040984343694325070U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13334258224023902365U;
            aOrbiterB = RotL64((aOrbiterB * 4782523727707164869U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1079824790138592518U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14024082692012948652U;
            aOrbiterG = RotL64((aOrbiterG * 3219489374333737903U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2966776524421278970U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5510281854029308547U;
            aOrbiterH = RotL64((aOrbiterH * 9275402927591867297U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7126632329316720048U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1476827035602733472U;
            aOrbiterK = RotL64((aOrbiterK * 2217671289726794033U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6470212302133184965U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4172257438373147415U;
            aOrbiterF = RotL64((aOrbiterF * 4449314239630366533U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11445212164224402184U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1779825157413363285U;
            aOrbiterJ = RotL64((aOrbiterJ * 15393425495668107155U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7561888690947559866U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14440989817038856852U;
            aOrbiterI = RotL64((aOrbiterI * 5799807036762859679U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10618807050937260814U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15910560457440369082U;
            aOrbiterA = RotL64((aOrbiterA * 10902491688248464465U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 50U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 24U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterA, 21U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 36U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 53U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 58U) + RotL64(aOrbiterE, 4U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterE, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterC, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererK, 52U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneB
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14751U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((aIndex + 14057U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 14651U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11132U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneC[((aIndex + 11013U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererB + RotL64(aCross, 41U)) + 16651241552253078315U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 39U)) + 4558144676982478003U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 8814884320080367550U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 16011579668555672117U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 27U)) + 4738918668759862438U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 56U)) + RotL64(aCarry, 3U)) + 12526083125540985108U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 13U)) + 8048723561746000552U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 35U)) + 1082218464034639039U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 43U)) + 8432043246965946816U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 23U)) + 9982080524048636852U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 18U)) + 6720069955755215919U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1019035028070247757U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7360619079463870467U;
            aOrbiterG = RotL64((aOrbiterG * 6623074813047915863U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10893918488381348474U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1390297670907738019U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11909657437658597735U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12512200589031203480U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14741471280748399540U;
            aOrbiterA = RotL64((aOrbiterA * 3012135242889901095U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8543897248359826770U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8545972622733791272U;
            aOrbiterC = RotL64((aOrbiterC * 11793879362775346821U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7049384618581928664U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14730773807906925408U;
            aOrbiterB = RotL64((aOrbiterB * 10711566871536755073U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11480717275652449986U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1135397594974536859U;
            aOrbiterK = RotL64((aOrbiterK * 6347492892938856497U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6897207625849516702U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10920630712550287148U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4140705091806993359U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1094056478999931332U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6784487144549717207U;
            aOrbiterJ = RotL64((aOrbiterJ * 6295177724167067891U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2224992798329560875U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11486442570446223696U;
            aOrbiterD = RotL64((aOrbiterD * 5680065455032616591U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14681556190496625711U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1809388635055225841U;
            aOrbiterI = RotL64((aOrbiterI * 3449474313001177557U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4480846057441948619U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16651241552253078315U;
            aOrbiterF = RotL64((aOrbiterF * 10628778876898064085U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 39U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 58U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterG, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 35U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 44U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 38U) + aOrbiterF) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aInvestLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16602U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneA[((aIndex + 19909U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 20642U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17510U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17776U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererA + RotL64(aCross, 21U)) + 7790166497945719700U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 39U)) + 7136208896846119188U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 27U)) + 12123156943355100886U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 13U)) + 5095546037880875199U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 19U)) + 17642705393916765992U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 9918479837334416990U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 46U)) + 4890009823843176466U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 17652590786213674124U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 53U)) + 870002527644696135U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 3U)) + 12545429703552643682U) + aPhaseFOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 50U)) + RotL64(aCarry, 27U)) + 5310272867406182581U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3264719049050179440U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1967241238180278937U;
            aOrbiterJ = RotL64((aOrbiterJ * 13004319774269457957U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 773883832927040736U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12766817190261232485U;
            aOrbiterB = RotL64((aOrbiterB * 7448864556802318431U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 260069382395598265U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15462103891287350123U;
            aOrbiterA = RotL64((aOrbiterA * 5029268763635635753U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4072032867513289827U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17153061419083897076U;
            aOrbiterH = RotL64((aOrbiterH * 11934532169271718913U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6207264270332656966U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 18048064697837314947U;
            aOrbiterG = RotL64((aOrbiterG * 13632594619404208489U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14484617445340272026U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16160443600497652026U;
            aOrbiterE = RotL64((aOrbiterE * 1988599349457831597U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5873314228291583482U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16418290052752166515U;
            aOrbiterI = RotL64((aOrbiterI * 18270363452003213317U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9158414409987627714U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8205937960146492168U;
            aOrbiterK = RotL64((aOrbiterK * 14008398661393344261U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16386126219854809263U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12418021156683187869U;
            aOrbiterF = RotL64((aOrbiterF * 13897930566207284517U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5427232681451476584U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 18237670074497382745U;
            aOrbiterC = RotL64((aOrbiterC * 15528665160297906195U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8330262458028468513U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7790166497945719700U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6001280767763971107U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 58U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 42U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterH, 54U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterB, 21U));
            aWandererG = aWandererG + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 39U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 50U) + aOrbiterE) + RotL64(aOrbiterD, 47U)) + aPhaseFWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 12U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 20U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aInvestLaneB
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23166U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneB[((aIndex + 23601U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23380U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26616U)) & S_BLOCK1], 54U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24973U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 8367680518550579791U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 47U)) + 11491674725611181241U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 27U)) + 16673861720782164214U;
            aOrbiterF = (aWandererC + RotL64(aCross, 36U)) + 9786610124108350855U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 23U)) + 5745080601557577637U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 1959402215131684684U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 21U)) + 6121650036079196522U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 51U)) + 12016309761037342392U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 19U)) + 5986936646177049603U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 58U)) + 1000367700904043468U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 17425288243569101032U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4856917474950325209U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16312111093223166419U;
            aOrbiterH = RotL64((aOrbiterH * 11046477664487805241U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 456110002032422270U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11393724374787795662U;
            aOrbiterC = RotL64((aOrbiterC * 1176984359123668389U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8378176867715697176U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8086186452345234815U;
            aOrbiterD = RotL64((aOrbiterD * 8450438271765985235U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8470349167474173245U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 2528229938740192694U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8717790851266520943U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13247168811545753141U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8745293957516815264U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14270617180621072619U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6165915500564961987U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12015407798844173213U;
            aOrbiterG = RotL64((aOrbiterG * 3913451986559154153U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 545006684939922156U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16366753936267185001U;
            aOrbiterI = RotL64((aOrbiterI * 6495185976430013201U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3097605623436091728U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15950167830259022926U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4415538963984293323U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8356327899232213426U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10183421678251169945U;
            aOrbiterA = RotL64((aOrbiterA * 9474380650337109299U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16327340177970834683U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7086901180933495535U;
            aOrbiterK = RotL64((aOrbiterK * 1276521829484494857U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13421211370092080006U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8367680518550579791U;
            aOrbiterJ = RotL64((aOrbiterJ * 12256662446176946163U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 41U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 14U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 39U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterH, 57U));
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterA, 37U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27506U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 28927U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30164U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31356U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31346U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 43U)) + (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererH + RotL64(aCross, 51U)) + 3612110001869385068U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 13U)) + 16340824141280225936U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 44U)) + 15222338965130765231U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 57U)) + 6649270508107155041U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 768217258655426384U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 4481855259658861851U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 18318041934562434016U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 21U)) + 4212457153804401807U) + aPhaseFOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aCross, 11U)) + 16143621095636987628U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 5U)) + 2095664232866642086U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 38U)) + 4339527736737366572U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13679353177869884790U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11582168502846418236U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 135539430034462861U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10451330452898542191U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12951448817640617841U;
            aOrbiterK = RotL64((aOrbiterK * 4141870904192742091U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15389161934419370747U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4754886272708253014U;
            aOrbiterG = RotL64((aOrbiterG * 16638243718191281597U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11746389873929280688U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12042680172517298768U;
            aOrbiterE = RotL64((aOrbiterE * 3814780289755857543U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2648103752465009244U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 451594673632597973U;
            aOrbiterJ = RotL64((aOrbiterJ * 8496763663271072425U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5696534794094099710U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14609435045257077395U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14658408563237468407U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11599395126850950133U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12699598504604446664U;
            aOrbiterF = RotL64((aOrbiterF * 14313494063098111823U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9398465148537154745U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12139736860648011256U;
            aOrbiterD = RotL64((aOrbiterD * 15257503229375247987U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5390816291244486383U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2797988892316486895U;
            aOrbiterA = RotL64((aOrbiterA * 14668138881285892065U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18356290434261054712U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16582824574485822826U;
            aOrbiterB = RotL64((aOrbiterB * 7207935384746719969U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9858803484150150915U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3612110001869385068U;
            aOrbiterC = RotL64((aOrbiterC * 2862887443435821143U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 20U);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 39U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 35U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 24U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 42U) + aOrbiterE) + RotL64(aOrbiterA, 51U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 56U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_FootBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4525U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 3212U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2294U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3707U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4983U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 1312U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 37U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 12775735908960052604U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 57U)) + 11791373812080296887U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 5537362877706057303U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 48U)) + 2023912048504189380U) + aPhaseGOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 17668828109963766893U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 558908629933941224U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1479633119685446888U;
            aOrbiterE = RotL64((aOrbiterE * 4447153373540811385U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15460320397843364063U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10059749397555469054U;
            aOrbiterJ = RotL64((aOrbiterJ * 8671817118586065469U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9987633811929693924U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10087337844580228269U;
            aOrbiterD = RotL64((aOrbiterD * 13817142288940843815U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4446204415503364254U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15106063243302192717U;
            aOrbiterH = RotL64((aOrbiterH * 13273756657334709803U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9430197906134676162U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1226048679997253363U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 11U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 19U));
            aWandererG = aWandererG + (((RotL64(aScatter, 18U) + RotL64(aOrbiterI, 48U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10063U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 11032U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 10572U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14856U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14969U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 9280U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 17912271996338180948U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 13259276608841847058U) + aPhaseGOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 19U)) + 16225936008657276089U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 43U)) + 2243058962151834071U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 41U)) + 10637439274127347861U) + aPhaseGOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15312219216405992627U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2393933972129878613U;
            aOrbiterI = RotL64((aOrbiterI * 13147717214387593761U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 4327069337247976513U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 8307656353434167837U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11386588389133096705U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17299145556933889336U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14458100581172798164U;
            aOrbiterD = RotL64((aOrbiterD * 16543734663677070509U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6410095654927998067U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6168964796264687686U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16218071040190475953U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3667999465041020730U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16021552859323602007U;
            aOrbiterC = RotL64((aOrbiterC * 6427266472526362663U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 28U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 48U) + RotL64(aOrbiterC, 21U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + aPhaseGWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterC, 46U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterE, 29U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 22U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17465U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 17876U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 18341U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22031U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18827U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 23516U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 4U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 11698283336767769359U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 4U)) + RotL64(aCarry, 39U)) + 13297826354831483872U) + aPhaseGOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 57U)) + 15254999058287530795U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 17474166585085346567U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 41U)) + 15684783498452840289U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5061229733465216486U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15370981279168377944U;
            aOrbiterK = RotL64((aOrbiterK * 15893028157665379361U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17966672773619554092U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14685092893994491068U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1627758964162892429U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12798804186209406389U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2848444181474221574U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13730480364920876877U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8551142075919636146U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8833198159158950723U;
            aOrbiterB = RotL64((aOrbiterB * 7650289040764974737U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 7351473160893666232U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14204899612487622222U;
            aOrbiterD = RotL64((aOrbiterD * 6317485031956448029U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 18U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 40U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 24U) + aOrbiterD) + RotL64(aOrbiterE, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24821U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 29055U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 26611U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26503U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25093U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32045U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 43U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererB + RotL64(aCross, 28U)) + 1393781663398437180U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 17414594746688585273U) + aPhaseGOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 2823888497053071250U) + aPhaseGOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 17032631958617884859U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 11U)) + 15222697630461125019U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15737414920751551780U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1357196111055783001U;
            aOrbiterC = RotL64((aOrbiterC * 8225423829221938165U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5315122321649251691U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7893744655508595974U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17863000246694319149U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 16721939414324611738U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3444375866323610848U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10874157227815775661U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1825716513674511632U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15582066843912467318U;
            aOrbiterF = RotL64((aOrbiterF * 12765146555943757373U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15673590949193923915U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13887365046280406413U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3169061375011420121U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 51U));
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 24U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 26U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + aPhaseGWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_FootBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7206U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((aIndex + 1561U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 333U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4476U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7945U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 2219U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 38U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 48U)) + 2783898056762489197U) + aPhaseHOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 5U)) + 7177192902873343053U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 12254703232691980774U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 15446547245691219559U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 888475203006174856U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3649183529366307877U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4642631047518805167U;
            aOrbiterD = RotL64((aOrbiterD * 14791564497487717167U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6108329730724782250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8334054653023816636U;
            aOrbiterG = RotL64((aOrbiterG * 9352516059501924393U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5891895375031474350U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3176720746238477862U;
            aOrbiterH = RotL64((aOrbiterH * 1869961473768307911U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6111038696865301675U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11914998302228682704U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11738924766359642853U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17005063057791320948U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 18333780598768130670U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5416759844884107303U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterC, 46U));
            aWandererE = aWandererE + ((RotL64(aCross, 12U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + aPhaseHWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11146U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 9961U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9308U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14655U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11740U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 10519U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 57U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (((aWandererI + RotL64(aCross, 20U)) + RotL64(aCarry, 43U)) + 6069475454765660321U) + aPhaseHOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 11483704742497268068U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 11055697447388986418U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 35U)) + 10897095046039997004U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 43U)) + 4731637118230457840U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13855839187084986751U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5328208115460188239U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3800417611141123383U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12479538544291412985U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10740165998792608231U;
            aOrbiterI = RotL64((aOrbiterI * 14046827922294477379U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6492798157284955373U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13056825957483891921U;
            aOrbiterD = RotL64((aOrbiterD * 14882112110627751751U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2068184064919194657U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5656302738780746294U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16493021179127646345U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11193756120230763294U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17306750816837208999U;
            aOrbiterC = RotL64((aOrbiterC * 7949360041241439741U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterB, 19U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 56U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24433U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 17071U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 16633U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18876U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17771U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18276U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 21U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 18319689184146942855U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 8041304130090501019U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 52U)) + 11347064191990897738U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 15242243470024447468U) + aPhaseHOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 19U)) + 10619749107163611105U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14795614276221947128U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1578095288886372393U;
            aOrbiterD = RotL64((aOrbiterD * 9953192041564147241U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13593906305770501684U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8919815528334599172U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2033810402808238127U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17425548324720065145U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11125018338392347335U;
            aOrbiterF = RotL64((aOrbiterF * 4377887040461528587U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3779189180734244399U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10958224663276134041U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6206963519509783781U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4317305352561612995U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4891139433808505355U;
            aOrbiterA = RotL64((aOrbiterA * 11507024985663120317U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + RotL64(aOrbiterF, 53U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI + ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 34U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 26U) + aOrbiterA) + RotL64(aOrbiterB, 19U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28009U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 28617U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 28000U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30910U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29066U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27171U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 18U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererD + RotL64(aScatter, 40U)) + RotL64(aCarry, 53U)) + 11039986441331892533U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 6256024955965426119U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 29U)) + 9857443189988995666U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 51U)) + 11900944813380998208U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 8422577734978875541U) + aPhaseHOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3100835100713928724U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11871553509810206993U;
            aOrbiterB = RotL64((aOrbiterB * 15501681886909921677U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17614749493763417027U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3638372131856199916U;
            aOrbiterJ = RotL64((aOrbiterJ * 480683274898147025U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6582275259281025770U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17016882418498941958U;
            aOrbiterC = RotL64((aOrbiterC * 4269869255230867823U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 1747214688658984715U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9356088987044015278U;
            aOrbiterG = RotL64((aOrbiterG * 16221733545319753695U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4056238112133473456U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16013150119949532998U;
            aOrbiterA = RotL64((aOrbiterA * 12913648646318115315U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + aPhaseHWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 39U)) + aPhaseHWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 18U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterC, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
