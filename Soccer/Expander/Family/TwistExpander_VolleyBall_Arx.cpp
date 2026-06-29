#include "TwistExpander_VolleyBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_VolleyBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDA8C976B3809B1B1ULL + 0xB5D91EE219E2EB03ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC5FED468C7F7E385ULL + 0xDD5231EEFEC18E33ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x92C56EC69C1D19BFULL + 0xD68B5FD4CFB9A693ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8EF2A1B4B55D460DULL + 0x8342129EFF499FFFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEA6671C176B3D92BULL + 0xEF086C15080B3E0AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA8EC1A1D660A3141ULL + 0xF317AFC43EE665F5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAE1958CC1A33BDB7ULL + 0xC8AD298B80C6CDC0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA612416D74BDCAF5ULL + 0x98054AB172A3D6C6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA8B56015C4079255ULL + 0xD738D967618A6F18ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x95C88030CB8AB883ULL + 0xF2F59BAE386E000AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8DD7B2E068A2E64FULL + 0xEB8C9EB147D0FAA9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA01E9AC443955829ULL + 0x89321B5E6F9100E9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA7B93CEBC336D03BULL + 0xD834B522B5EBB06EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF9597AEA529CEE13ULL + 0xDB6782A4CA9CA727ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF460D61E469EDFA5ULL + 0xD67245481547EBC3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x976ED50125B619E9ULL + 0xEA57D546A69D4872ULL);
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
            aIngress = RotL64(mSource[((aIndex + 3197U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1917U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4052U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 2490U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 12027839670755583592U;
            aOrbiterK = (aWandererE + RotL64(aCross, 29U)) + 15380130703509859843U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 5U)) + 4590907433867798074U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 51U)) + 1754574023602519724U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 47U)) + 9832756659564903767U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 57U)) + 5035088494491470403U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 27U)) + 14199170923323644638U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aWandererH + RotL64(aCross, 23U)) + 8325619421264440438U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 57U)) + 969534320779067977U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 37U)) + 270575869402913847U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 54U)) + RotL64(aCarry, 27U)) + 13344806516599578910U) + aNonceWordK;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15143147951139409101U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14425582489214169238U;
            aOrbiterE = RotL64((aOrbiterE * 16893787086337916355U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13951127523239064584U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14177925225918293579U;
            aOrbiterF = RotL64((aOrbiterF * 13079514031864998485U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8258920744278218901U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7408161179397242453U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 975737128100519169U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8581481606764773468U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10078416198417433133U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 1102721083915858247U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 18299772198826189580U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 18304668908084397946U;
            aOrbiterH = RotL64((aOrbiterH * 10589455451200578687U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16729632621573817223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13362300981585573239U;
            aOrbiterI = RotL64((aOrbiterI * 9824473895535518785U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8629682832849915380U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6852852009091469641U;
            aOrbiterK = RotL64((aOrbiterK * 11912646687050011915U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7433098156961745198U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10931806208899417308U;
            aOrbiterJ = RotL64((aOrbiterJ * 14699197041038067483U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 629604718211675247U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1487372736719237118U;
            aOrbiterC = RotL64((aOrbiterC * 705192821277928909U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3567439893461603384U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11143068753134694333U;
            aOrbiterD = RotL64((aOrbiterD * 15529326960229305389U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14242098279913980463U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12027839670755583592U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 6630014752150544153U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 54U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 54U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 41U));
            aWandererI = aWandererI + ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterC, 21U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterI, 23U)) + aNonceWordH) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 52U) + aOrbiterJ) + RotL64(aOrbiterI, 60U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterF) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterE, 5U));
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 26U)) + aOrbiterD) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 22U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 24U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 9123U)) & S_BLOCK1], 37U) ^ RotL64(pSnow[((aIndex + 9712U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10821U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6188U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 38U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 6U)) + RotL64(aCarry, 11U)) + 15045917390223766480U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 10763054007033668758U) + aNonceWordD;
            aOrbiterG = ((aWandererK + RotL64(aCross, 35U)) + 13190170142593666607U) + aNonceWordB;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 13U)) + 9657025731441167065U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererG + RotL64(aIngress, 44U)) + 11433367178975954211U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 27U)) + 17904920143996810366U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 53U)) + 3244383020512113283U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 47U)) + 6538815775171139091U) + aNonceWordL;
            aOrbiterA = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 7195368312757976343U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 3U)) + 18134430713910279374U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 51U)) + 6571776588427107976U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11830778129647517758U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9793702760907767365U;
            aOrbiterG = RotL64((aOrbiterG * 4096246227968677179U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2287235876793192036U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8951959188326141794U;
            aOrbiterF = RotL64((aOrbiterF * 9968356718110753845U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7583061790273240157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3571364625022806085U;
            aOrbiterE = RotL64((aOrbiterE * 6238360922735480669U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13869345563551689212U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 277480328952975002U;
            aOrbiterJ = RotL64((aOrbiterJ * 1057564597096163085U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4983735092494677578U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9490022869381030928U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 12926352917961703123U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7928039573014765566U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6504190875809407084U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14648214826494826711U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2787985600176307413U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16308785053443116826U;
            aOrbiterD = RotL64((aOrbiterD * 17867565986311256691U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 12788128335006767824U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1187040019537798339U;
            aOrbiterI = RotL64((aOrbiterI * 10834905007658184183U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10771230162770496645U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6542421559654716320U;
            aOrbiterC = RotL64((aOrbiterC * 16829492790597069373U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 702458690970201679U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2806140783487813070U;
            aOrbiterA = RotL64((aOrbiterA * 7415398198842270381U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 950611302199732036U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15045917390223766480U;
            aOrbiterH = RotL64((aOrbiterH * 9358017420417979347U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 60U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterH, 41U)) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 52U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterG, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 14U) + aOrbiterD) + RotL64(aOrbiterB, 57U));
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterB, 37U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterH, 50U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterF, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 14704U)) & S_BLOCK1], 10U) ^ RotL64(mSource[((aIndex + 11280U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12113U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((aIndex + 12394U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 43U)) + 1457104756581596530U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 56U)) + 6127240317844622874U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 16492290056044189421U) + aNonceWordE;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 10963676850938416468U) + aNonceWordL;
            aOrbiterG = (aWandererJ + RotL64(aCross, 47U)) + 4872917367399752405U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 39U)) + 15218882377875616148U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 11U)) + 5934166612122118251U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 53U)) + 14215280930872003003U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 51U)) + 11428034799044600979U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 5453003654321728726U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 28U)) + 14273775120265649389U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 328723770018440271U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13032190719588211088U;
            aOrbiterF = RotL64((aOrbiterF * 13363368478932798315U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2386881543033598494U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1649501123340887116U;
            aOrbiterC = RotL64((aOrbiterC * 11148976582360499033U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16462401546754210583U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1510579201823042227U;
            aOrbiterG = RotL64((aOrbiterG * 16287912400104043275U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6889066000014251983U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11324594596597724357U;
            aOrbiterE = RotL64((aOrbiterE * 15344987814648586023U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12237796033168436537U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17306069670330000343U;
            aOrbiterB = RotL64((aOrbiterB * 3167451351403385259U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14197284538008811658U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4754134852883071927U;
            aOrbiterD = RotL64((aOrbiterD * 3484427259538998699U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17201907781639753736U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8318419319239859855U;
            aOrbiterA = RotL64((aOrbiterA * 10320390501983802091U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16012488623961565780U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15583721012865354925U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10656414363201743961U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14680351201973315018U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 14483973292275372321U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 9279222721410811027U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16324317860030681248U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7038506963317910910U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 2960451734542956767U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12767672960346001218U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 1457104756581596530U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1560375242310194691U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 48U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 38U) + aOrbiterK) + RotL64(aOrbiterC, 37U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterC, 41U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterB, 53U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 30U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aIngress, 14U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 23U)) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 57U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterI, 14U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterK, 11U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 36U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17575U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((aIndex + 18508U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17560U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 19447U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((aIndex + 20488U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 21U)) + (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 27U)) + 1557680213571812384U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 7387349725778021121U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 37U)) + 15379264067601586976U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 41U)) + 3730195724576043708U) + aNonceWordD;
            aOrbiterH = (aWandererF + RotL64(aCross, 54U)) + 9637070085323827066U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 3U)) + 1170865717363676184U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 5U)) + 2750833653175252030U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 15118992811225568305U) + aNonceWordK;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 50U)) + RotL64(aCarry, 19U)) + 4974092922102988451U;
            aOrbiterB = (aWandererB + RotL64(aCross, 21U)) + 10625719096296719514U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 57U)) + 855167122475471865U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 11322911068958340262U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 4334591909425429835U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 10059025861172038183U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14263701737208936392U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 678723206735649084U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10823239851733632227U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15652053114252065230U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1705225940224061401U;
            aOrbiterC = RotL64((aOrbiterC * 3626023093533713579U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6826394665732900206U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11902946775066981141U;
            aOrbiterF = RotL64((aOrbiterF * 18300629262162694137U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9802212958998591310U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14001358545610206524U;
            aOrbiterD = RotL64((aOrbiterD * 13172645840788327099U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4299184726135884309U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7288757011999872416U;
            aOrbiterK = RotL64((aOrbiterK * 16806027820468277393U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 233801262480580205U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14208660347238680268U;
            aOrbiterG = RotL64((aOrbiterG * 6299693448313154603U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9217797359740446104U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 18165073197136050838U;
            aOrbiterA = RotL64((aOrbiterA * 11677479094709512887U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9101905235436427482U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2884224555227870272U;
            aOrbiterH = RotL64((aOrbiterH * 12085235281782370391U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13118509728421714433U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1385390888603164704U;
            aOrbiterB = RotL64((aOrbiterB * 6927424835779289199U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9621084561183039538U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1557680213571812384U;
            aOrbiterE = RotL64((aOrbiterE * 3202327770291862207U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 22U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 10U) + aOrbiterK) + RotL64(aOrbiterF, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterB, 30U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterG, 23U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 6U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 53U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 28U)) + aOrbiterC) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26046U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 24768U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(pSnow[((aIndex + 22593U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneA[((aIndex + 25232U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22916U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 24127U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 15726877954695761686U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 6U)) + 14187652171881943587U) + aNonceWordA;
            aOrbiterA = (aWandererD + RotL64(aScatter, 35U)) + 8420423151313882782U;
            aOrbiterD = (aWandererA + RotL64(aCross, 39U)) + 14942322692433259283U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 3U)) + 7272331475919796255U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 19U)) + 154504365041805840U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aIngress, 14U)) + RotL64(aCarry, 37U)) + 17475491222554948786U;
            aOrbiterF = ((((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 5759181483165339605U) + aOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 57U)) + 5993060214499322845U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 43U)) + 10901786237875941844U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 53U)) + 17135786595614068473U) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5208202073886811165U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6821452921018900631U;
            aOrbiterA = RotL64((aOrbiterA * 13119330055184115669U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13348064837402206969U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8967943922403445136U) ^ aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 300168481725373093U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8130283784171430891U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6351113882502502876U;
            aOrbiterG = RotL64((aOrbiterG * 15960622823993072903U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6894708729226455769U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12065058511247133944U;
            aOrbiterB = RotL64((aOrbiterB * 5432601727436935831U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17138279326229372741U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12987698199066890628U;
            aOrbiterI = RotL64((aOrbiterI * 12665716655177320977U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13688833537574196675U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4211971980434000618U;
            aOrbiterK = RotL64((aOrbiterK * 1374411763361518851U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10376917117582537592U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 4807742522197923516U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 15257251453302090961U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 18038296468177121243U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6879666349379745258U;
            aOrbiterC = RotL64((aOrbiterC * 15819475269715810555U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5193656664432659624U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 680899397323387963U;
            aOrbiterD = RotL64((aOrbiterD * 9857476056194621321U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1851929589073547860U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 13093101559415170218U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 13950928576652143737U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13695333301427028607U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15726877954695761686U;
            aOrbiterF = RotL64((aOrbiterF * 960063676226172027U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 46U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterB, 18U)) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 47U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 57U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 39U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 29U)) + aOrbiterA) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 23U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterH, 43U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 34U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28530U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 29304U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28994U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30131U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27312U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 28584U)) & S_BLOCK1], 34U) ^ RotL64(aFireLaneB[((aIndex + 29482U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 54U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = (aWandererF + RotL64(aIngress, 51U)) + 3105313968748067810U;
            aOrbiterJ = ((((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 9977249451119627064U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aWandererI + RotL64(aScatter, 11U)) + 17941392803495349366U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 44U)) + RotL64(aCarry, 39U)) + 4279533326705471133U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 47U)) + 13983828966811580039U) + aNonceWordD;
            aOrbiterB = (aWandererB + RotL64(aIngress, 23U)) + 3983490984234810378U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 57U)) + 308786542215259956U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 53U)) + 8443607695364427037U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 19U)) + 14939626441464340668U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 42U)) + 9350693577306121110U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 1717071159396961752U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 15911765265202100610U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14898546272333182767U;
            aOrbiterG = RotL64((aOrbiterG * 2674900543810733067U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3560903518513465868U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5367062725726860234U;
            aOrbiterI = RotL64((aOrbiterI * 8521908836601319553U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15233321480618877327U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9288449812290126074U;
            aOrbiterE = RotL64((aOrbiterE * 6815298520404038519U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5504840529511585676U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6825598386801620046U;
            aOrbiterJ = RotL64((aOrbiterJ * 11666542445846250077U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6433024450721339470U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 97934156644929458U;
            aOrbiterF = RotL64((aOrbiterF * 8630530773006923215U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3260053604798744515U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16539416623243059076U;
            aOrbiterA = RotL64((aOrbiterA * 12199577351166064503U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9814290051339038920U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 13280156404507444041U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15269010043398910061U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11853942590993546833U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13207869904312989977U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 15503461937625795969U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14536032167989376750U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3693282775047432356U;
            aOrbiterH = RotL64((aOrbiterH * 5290349323647887877U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5803176485246280271U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16702526675475954730U;
            aOrbiterD = RotL64((aOrbiterD * 13695676754973145769U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16454171963808313625U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3105313968748067810U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16572687178789102843U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterC, 21U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterI, 14U));
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterC, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 20U) + aOrbiterJ) + RotL64(aOrbiterD, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterC, 47U));
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterI, 26U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterG, 5U));
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + aNonceWordB) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_VolleyBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x87806CD83401F64DULL + 0xCDE2EB28F51BACC7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEC388E1C1DC4C855ULL + 0xB0F97FC4E678BB3EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xADE8DFDAFFC513CBULL + 0xC2EEF4E185977A7BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBAC907AA8CD62069ULL + 0xF9612B219D869A44ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA5FD58F6B0D1F465ULL + 0xE236F295992E9881ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB2A7B296255E43F5ULL + 0x9D0C8F97A81A37F8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCA28D9830716DA53ULL + 0x849DF3244855F4B3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFCD33ACBDB47C037ULL + 0xCABD29F82B8B7C05ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF84E948177EE949BULL + 0xA9E38DC8AC1BF1FBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9FF6C1F384AAAD3BULL + 0xC2D8E90DF0D642DAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB2FB4C1EB60F55BBULL + 0xA7B7CF81DC3BBC18ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA20F1D38960A9243ULL + 0x9096C68C7A4D65D6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFAD3864C916E7F0DULL + 0xB190D0CB230B8A97ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA28BA85D81F8BE2BULL + 0xAD9CDAE83EA29D71ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBAA4BD1EB44F7EB5ULL + 0x870ACE1FAFB8ED0AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x96BF6E1F817BFB89ULL + 0xA8FEE62EE7CA65A6ULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 4993U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 5254U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3551U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 4847U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 21U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 11177787645248006236U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 3808340254579817169U) + aNonceWordJ;
            aOrbiterB = ((aWandererE + RotL64(aCross, 4U)) + 828030667598518279U) + aNonceWordN;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 16177835921238398371U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 23U)) + 5518747735458708741U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 47U)) + 17346319082399995165U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 18U)) + 6397156921893030937U) + aNonceWordC;
            aOrbiterD = (aWandererA + RotL64(aIngress, 51U)) + 15559381654710713582U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 43U)) + 940404446491415088U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8047166032048732645U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4688468645859470491U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 14383536431614496369U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3710878044770337260U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 116343189456629220U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5637725064169289339U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 883908030159391659U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 18058691521694880482U;
            aOrbiterC = RotL64((aOrbiterC * 3132200449123497619U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17521015077103586117U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3668332225435714918U;
            aOrbiterI = RotL64((aOrbiterI * 12658899101297839881U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12229480388278883300U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16206524049491531816U;
            aOrbiterJ = RotL64((aOrbiterJ * 11122340196620859805U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5743265849441077466U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2812293020719282236U;
            aOrbiterD = RotL64((aOrbiterD * 8903956475200417109U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13718364781538837074U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 861529717259766236U;
            aOrbiterK = RotL64((aOrbiterK * 17019744777211266685U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4862687502126693872U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7722024283321020761U;
            aOrbiterF = RotL64((aOrbiterF * 18086944039541060829U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 8205803118233399853U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15130160926615050422U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1454552751453996765U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 20U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 4U) + aOrbiterK) + RotL64(aOrbiterC, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterF, 23U));
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + RotL64(aOrbiterD, 34U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 13U));
            aWandererI = aWandererI + (((RotL64(aCross, 42U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + aNonceWordM);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 41U)) + aOrbiterE) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterB, 4U)) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 7579U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 6234U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 6361U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8497U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 7048U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 22U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = (aWandererG + RotL64(aIngress, 41U)) + 6467297102954816305U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 7921154109831114952U) + aNonceWordA;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 5701131763215638919U;
            aOrbiterG = (aWandererH + RotL64(aCross, 53U)) + 10022999076719002684U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 30U)) + 4367135243038982316U) + aNonceWordD;
            aOrbiterI = ((aWandererC + RotL64(aCross, 5U)) + 14445846824810383592U) + aNonceWordG;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 13U)) + 7683697954545773253U) + aNonceWordB;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 57U)) + 17517006750428030899U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aIngress, 18U)) + RotL64(aCarry, 5U)) + 2052484792684025476U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6279463052085808926U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 679280153651813684U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3047031560593583881U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2939516520188460569U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1960616434964712325U;
            aOrbiterC = RotL64((aOrbiterC * 15145998415466343039U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12273819390719947361U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5685033154709449397U;
            aOrbiterA = RotL64((aOrbiterA * 9845666295874714959U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 9314494172199500653U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15757631834636427621U;
            aOrbiterG = RotL64((aOrbiterG * 15483543888965744529U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10878078046389399574U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3583495913766365232U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2913540984990155225U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7385544065754622301U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16839599460207922881U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 240651605910592561U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13038163804940349251U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2587538594933924000U;
            aOrbiterE = RotL64((aOrbiterE * 3091149760401278671U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13109518583364738004U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2447689055742474261U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 12100180201235703193U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5752044906692668618U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6637725371036522120U;
            aOrbiterJ = RotL64((aOrbiterJ * 6021986525167161115U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 30U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 57U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterF, 13U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 44U)) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + aNonceWordF);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 29U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterE, 39U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 27U) + RotL64(aOrbiterA, 6U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 10984U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 14520U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 11199U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14860U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((aIndex + 14709U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 60U)) + RotL64(aCarry, 57U)) + 16451272412693907816U;
            aOrbiterC = (aWandererD + RotL64(aCross, 29U)) + 10099485419723255462U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 47U)) + 17668900099534923192U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 5497093724143181753U;
            aOrbiterA = (((aWandererK + RotL64(aCross, 18U)) + RotL64(aCarry, 37U)) + 10354044773550071706U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 43U)) + 12728258851198019099U) + aNonceWordK;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 11U)) + 4144050505314242618U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 23U)) + 14133805325480076530U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 37U)) + 308863673210602899U) + aNonceWordE;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11741180130160569753U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12926863156769180448U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 9726030996091054939U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 211920854786494259U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13234608842479411078U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 2556747209733759467U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9164711974854618892U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6667377062281954219U;
            aOrbiterD = RotL64((aOrbiterD * 2603737166987437649U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4559040002406721850U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1749875480850675109U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 15822640067349481089U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9555365165561936366U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 18289733999504213574U;
            aOrbiterF = RotL64((aOrbiterF * 14156217554673229429U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8727162691639622461U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 291406782452963706U;
            aOrbiterG = RotL64((aOrbiterG * 8413500075082350243U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 8294911802626492257U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15853578397277298548U;
            aOrbiterE = RotL64((aOrbiterE * 13256191781365357747U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11535146194939658681U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2177540476748375661U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15791341922007841029U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2705306323728084136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17617871830709148043U;
            aOrbiterB = RotL64((aOrbiterB * 3449981219502809255U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 26U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 11U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 20U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterC, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterB, 53U));
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aNonceWordP);
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterA, 48U)) + aNonceWordI) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 28U) + aOrbiterE) + RotL64(aOrbiterC, 43U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17882U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 21793U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21066U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20743U)) & S_BLOCK1], 50U) ^ RotL64(aFireLaneD[((aIndex + 19781U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 48U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 11U)) + 15188686795415908074U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 19U)) + 17310049041983079779U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 34U)) + 8246925977992441471U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 8644260919918112781U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 47U)) + 13401663736874819483U) + aNonceWordA;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 39U)) + 7940358935238314973U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 43U)) + 13278990328548007839U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 11346868298353840706U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 52U)) + 2374077904806833579U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6978903378645019166U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11951633297870965212U;
            aOrbiterJ = RotL64((aOrbiterJ * 12778236598654492185U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17398460995357409673U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1215437945597836770U;
            aOrbiterG = RotL64((aOrbiterG * 9322970054123481621U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1878751468043972239U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5343002808239712390U;
            aOrbiterF = RotL64((aOrbiterF * 11878640995447558811U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9884918450053276861U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15894599082080422550U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8359936745539546131U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13917339232771145459U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 18101134009493720683U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 15835859435306756387U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3830086372356903769U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15894394599564584010U;
            aOrbiterK = RotL64((aOrbiterK * 9513921913446609263U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5127590955274245812U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9410946933309720054U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 14507476989423060561U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15544384157294987085U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 998801294460434123U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 5946968142746472745U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16442095194965452163U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14294936349037516932U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 14655345374740882581U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 10U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 46U) + RotL64(aOrbiterG, 37U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 52U)) + aOrbiterK) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 10U)) + aNonceWordD) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 23U)) + aOrbiterD) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 26252U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneD[((aIndex + 24242U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23997U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25897U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 54U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 44U)) + 5171470532667965920U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 57U)) + 750549462358682403U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 19U)) + 3325689257577120525U) + aNonceWordF;
            aOrbiterI = (aWandererA + RotL64(aIngress, 13U)) + 18031575461559790826U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 27U)) + 13874739537012288677U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 40U)) + RotL64(aCarry, 57U)) + 4250029868785016865U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 8211158803112611161U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 1083939790236786027U) + aNonceWordJ;
            aOrbiterG = (aWandererK + RotL64(aScatter, 53U)) + 3446525462376962464U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6973817815000417325U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15230876489676945543U;
            aOrbiterE = RotL64((aOrbiterE * 7737039082964537651U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9359727659738755880U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8775170107816327654U;
            aOrbiterD = RotL64((aOrbiterD * 6910680458261008653U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11958941755525038545U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16966819714283167348U;
            aOrbiterI = RotL64((aOrbiterI * 16363457661846050749U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 14556087985619763243U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17915047508377045221U;
            aOrbiterB = RotL64((aOrbiterB * 6727635453185130109U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8578745677485367222U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7002181668717618866U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12329703532414955235U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3569939503066735457U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 2956247934282522184U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 9946650822131152531U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4285180013402474041U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5976239869535619811U;
            aOrbiterA = RotL64((aOrbiterA * 3458095419039067465U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2424524955161695463U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6849595426583763537U;
            aOrbiterC = RotL64((aOrbiterC * 12727902040238318101U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11414890686374886716U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5668287266836153445U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 8011885266143066285U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 13U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterB, 53U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 24U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterD, 43U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 60U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 26U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 29661U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 29037U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32322U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28639U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 27U)) + (RotL64(aCarry, 52U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 27U)) + 1297415699043177788U) + aNonceWordH;
            aOrbiterD = (aWandererA + RotL64(aCross, 35U)) + 17583786534509260153U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 50U)) + RotL64(aCarry, 53U)) + 643197858925708798U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 5062653766915694874U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 7034273638367180511U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 43U)) + 2026909726972916996U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 39U)) + 2785690475553211646U) + aNonceWordA;
            aOrbiterK = (aWandererD + RotL64(aIngress, 54U)) + 2910341716302991892U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 19U)) + 2834181605200829791U) + aNonceWordC;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13323052600571281928U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10434901530315760460U;
            aOrbiterJ = RotL64((aOrbiterJ * 2042210188346767033U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 247903955625194782U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5196515747387257163U;
            aOrbiterG = RotL64((aOrbiterG * 1799024689023272275U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7196305682377987476U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14777739876892587484U;
            aOrbiterK = RotL64((aOrbiterK * 95220583948241581U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10609060796540136671U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8386027207212484155U;
            aOrbiterF = RotL64((aOrbiterF * 4855610536246556893U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 729659744301903424U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2350564261412606157U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16713856782349084977U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 16611987556673864177U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1525195188708550503U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10045858602151004553U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4654808490980989596U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8189569777087686263U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 17278657566389299577U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10932857495004451792U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 1833880112534916813U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 8004341577533825681U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13100236350175516423U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2773759534195186313U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 3194954066097323161U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterK, 58U));
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterF) + aNonceWordP);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 22U) + aOrbiterF) + RotL64(aOrbiterG, 43U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 54U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_VolleyBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEB32B5CABA9D56D9ULL + 0xC08A717867C4A9BEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC6C3EF40660A7E61ULL + 0xD3A4F0CE75EA0031ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC4DDC27828DABE29ULL + 0xAD05672F9A5B4F55ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x95139DCE33147339ULL + 0x8D2287BFD36769CEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCD9445208903DD9DULL + 0xFC3307580A820B37ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC2FBF14E962CD9DDULL + 0xC9F00FA273DD9F4FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x857A74D7E49B2C83ULL + 0xF00E33AF5DAB7E29ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x87A3390C546E6B23ULL + 0xF43A42EB24CABA5BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB50AA10394E968AFULL + 0xBA56AD005D172146ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD44D05FB8048230DULL + 0x9FBE78EF6512BAE3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB29F8F068B1262EDULL + 0xCA96EA3B3A8FC26AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB00B1745F8447B1DULL + 0xFBB4337EE78FCCABULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC1FC4EAA8BFB7B5BULL + 0x9D83E88D0BA5E962ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFC86F849247C7881ULL + 0xAFC4A16B5A49827EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEE43AFDCCA04BC8DULL + 0xA38C7F9743502E1BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB90E20891F2098DFULL + 0xC56C438E9C10F7ABULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6991U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 8042U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6699U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 554U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 452U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7735U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 50U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 9914837590440975587U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 54U)) + 6706125076401958051U) + aNonceWordN;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 16570817772679258409U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 35U)) + 6843705658115186948U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 16099930446791572351U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 5420550009556030459U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5729549069420177477U;
            aOrbiterA = RotL64((aOrbiterA * 7842192631021712569U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15590601126188675834U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 13044027390998620029U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16845199115313444123U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11068338135659636772U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6584988841809544332U;
            aOrbiterG = RotL64((aOrbiterG * 1683336180438945439U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8516813219883915404U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10647314042912492785U;
            aOrbiterH = RotL64((aOrbiterH * 15559481057047148785U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 201691689889605304U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15512161798401184003U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11473219183982564709U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + aNonceWordJ);
            aWandererK = aWandererK + (((((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 51U)) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 40U)) + aOrbiterA) + aNonceWordP) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterG, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16153U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 8985U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 16184U)) & S_BLOCK1], 18U) ^ RotL64(aFireLaneC[((aIndex + 14731U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14331U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14424U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8931U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 5U)) + 14157904117287696136U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 52U)) + 7369512677371640676U) + aNonceWordA;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 8411250745902073798U) + aNonceWordG;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 5002041814539710275U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 9538041410816283124U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5210700103927513061U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7600709399101287982U;
            aOrbiterH = RotL64((aOrbiterH * 6777896926889560889U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2366369466696580499U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 5544575244203019109U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 16231219246786333057U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8710073749110329779U) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15998211310115361630U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15275657696897688955U), 29U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 15354357553877376422U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10657523549259276169U;
            aOrbiterI = RotL64((aOrbiterI * 13695239532898311073U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10405750198355464768U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3465819693133515142U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14678343718277562799U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 3U)) + aNonceWordM) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 56U) + aOrbiterI) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterB, 30U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19158U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 21649U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 20636U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16814U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19570U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20182U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19207U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 39U)) + 1557680213571812384U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 48U)) + RotL64(aCarry, 13U)) + 7387349725778021121U) + aNonceWordC;
            aOrbiterE = ((aWandererC + RotL64(aCross, 57U)) + 15379264067601586976U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 3730195724576043708U) + aNonceWordE;
            aOrbiterF = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 9637070085323827066U) + aNonceWordG;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1170865717363676184U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2750833653175252030U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 1937822982381882775U), 3U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 15118992811225568305U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 4974092922102988451U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10575977398702460975U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10625719096296719514U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 855167122475471865U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7441090331293158773U), 23U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 11322911068958340262U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4334591909425429835U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 10059025861172038183U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14263701737208936392U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 678723206735649084U;
            aOrbiterF = RotL64((aOrbiterF * 10823239851733632227U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 43U)) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + aNonceWordK);
            aWandererH = aWandererH + ((((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 57U)) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 28U) + aOrbiterJ) + RotL64(aOrbiterE, 4U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28359U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 25016U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 25020U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25038U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26979U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28389U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29921U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 18144572925667544139U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 5659758077574059728U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 34U)) + RotL64(aCarry, 37U)) + 6343330616999166392U) + aNonceWordB;
            aOrbiterK = (aWandererA + RotL64(aIngress, 3U)) + 17754639838410839447U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 19U)) + 9451843819849581729U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7957854457197462212U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1461994799722205010U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13431080873536691809U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 18002214276252170177U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14689869073147027164U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12242482963989582191U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3978104368003440293U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8512135845221335386U;
            aOrbiterF = RotL64((aOrbiterF * 10506667163729414667U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 1477533446382953439U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2166717790929947990U;
            aOrbiterK = RotL64((aOrbiterK * 6538884492418324461U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 8082437060686606995U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4363687722464700362U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 7199165810993478887U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + aNonceWordJ);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 36U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 4U)) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_VolleyBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA411C8F72AA46367ULL + 0xE08CA7709817D7FBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE08D927260FB929FULL + 0x9233E221B156A837ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB3FF8DDAAF7A3F53ULL + 0xEC7363CD47C4BC18ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCD08078033AA5DE7ULL + 0xAE6A500CA9F70AE4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBA9257C63AF8C9C9ULL + 0x8D1F02AEC14F186AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBB426D74CB2F9121ULL + 0x8E3B560153FE9C21ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB2F4E1FCF18BFBE5ULL + 0xD0DC2D3E76F895ABULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF91D04F55482AF71ULL + 0xE0A82CA2A411846FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA96FF61E21E9D2BFULL + 0xC1A28DE85DA75972ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFF4A77E719B45581ULL + 0x806CB118F1B2563AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA5BCAC37A84A4CC1ULL + 0xEF7C48E480920CC1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA7355680C0A90169ULL + 0xB7E86FB0ADDEE24BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAB07A8CFEB566429ULL + 0x8248BB9B708A198FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDF58333307C91D45ULL + 0xEFAF0C609E558C10ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDB5B2D34E098B8A3ULL + 0xA69A1A7EC254B97DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x837D1D893ED0C59DULL + 0xBA37673BA6A65539ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7176U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 1693U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3922U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7980U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6166U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3439U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 26U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 41U)) + 16189787374324972735U) + aNonceWordH;
            aOrbiterF = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 17563763730956242224U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 11U)) + 10572803498593789385U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 7713105232072974166U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 19U)) + 10760839534772718139U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 13397069448391230253U) + aNonceWordC;
            aOrbiterA = ((aWandererE + RotL64(aCross, 58U)) + 4569255679998375682U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9888769350817876949U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11351796060878856300U;
            aOrbiterJ = RotL64((aOrbiterJ * 13356749147334008399U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18153775071965707204U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1282846411145853435U;
            aOrbiterF = RotL64((aOrbiterF * 12294455920906257823U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16457743979262460660U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 173493260775251032U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4935807229040883505U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3927345926316409630U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 5158769729850853623U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 2446452358663812945U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12331351600010165154U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3940794200348684050U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13248997263062075043U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11248514843822945425U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1391497323278226522U;
            aOrbiterG = RotL64((aOrbiterG * 8376841806072565005U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13265623528678787307U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2802033745265647317U;
            aOrbiterH = RotL64((aOrbiterH * 3437626962562016147U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterC, 20U));
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 40U) + aOrbiterH) + RotL64(aOrbiterF, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterA, 13U)) + aNonceWordG) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8460U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 10367U)) & S_BLOCK1], 18U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 14966U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((aIndex + 13515U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12192U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12970U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15124U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 27U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererD + RotL64(aIngress, 19U)) + 13204735390996728477U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 851171359595647173U) + aNonceWordP;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 16745304202825290723U) + aNonceWordH;
            aOrbiterK = (aWandererF + RotL64(aCross, 37U)) + 562392736584913979U;
            aOrbiterJ = ((((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 3244267012529053918U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aWandererH + RotL64(aCross, 5U)) + 17282536111067869133U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 60U)) + 14851130066471729068U) + aNonceWordL;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 5256130407952363129U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2904742485828362001U;
            aOrbiterC = RotL64((aOrbiterC * 12941135856735075457U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 3723346325449225387U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5344621093694027341U;
            aOrbiterF = RotL64((aOrbiterF * 9044881458629673499U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12919263300833603026U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17989801264160996071U;
            aOrbiterJ = RotL64((aOrbiterJ * 15468293047311883751U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5022175042377172157U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16684822380107847758U;
            aOrbiterK = RotL64((aOrbiterK * 2834049270263837537U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2740326510600876682U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 13981423865219318820U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 14593082145080056441U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 231945878229848395U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14139797734944312580U;
            aOrbiterI = RotL64((aOrbiterI * 6492256080432266407U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16704102101387552373U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8506734780526852552U;
            aOrbiterA = RotL64((aOrbiterA * 4684566118627414659U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 12U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 50U) + aOrbiterF) + RotL64(aOrbiterC, 51U)) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterK, 21U));
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterH, 11U)) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 37U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21501U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 20880U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 22141U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21783U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24563U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19667U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 21630U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 20U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 27U)) + 8506388683755208267U) + aNonceWordH;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 11U)) + 2179323259055019735U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 3345902531140983016U) + aNonceWordE;
            aOrbiterD = (aWandererK + RotL64(aCross, 43U)) + 17456139311481306584U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 14587864088462311164U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 57U)) + 13178947246650647057U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 50U)) + RotL64(aCarry, 51U)) + 12866578138946916962U) + aNonceWordB;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13098524333655118173U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15451329483787541982U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13580376920467431451U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9494299579678389385U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15581954810375490643U;
            aOrbiterJ = RotL64((aOrbiterJ * 13670002280188424825U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4487042505730624892U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2774455928791636186U;
            aOrbiterE = RotL64((aOrbiterE * 15847933919136777451U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12435319582397755819U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 10077180055177766823U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3924363471701748703U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10391963896910956455U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6149237416725301794U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 10115917698918612823U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15673402771629639978U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14729117178956592426U) ^ aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9070464269215820531U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14492001279368870240U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6278248084483259952U;
            aOrbiterB = RotL64((aOrbiterB * 16731228350971263873U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterA, 37U)) + aNonceWordA) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterB, 43U)) + aNonceWordI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterE, 5U));
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterE, 60U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 28U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27508U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 30423U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25873U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 26578U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32468U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28021U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31287U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (aWandererC + RotL64(aCross, 13U)) + 6469584119078165548U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 48U)) + 14329756366517987910U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 12890831797059772123U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 3164503807500018990U) + aNonceWordM;
            aOrbiterH = ((aWandererF + RotL64(aCross, 29U)) + 177531431387646836U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 3167421392893561015U) + aNonceWordA;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 57U)) + 2813174781844753460U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10953270419153249857U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16911518309710356951U;
            aOrbiterJ = RotL64((aOrbiterJ * 13162785997686570445U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 6616750447844893150U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10276741398025985982U;
            aOrbiterE = RotL64((aOrbiterE * 6824712685896987133U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6206043608461213208U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12021552904553405793U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10023362889960174909U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15283586234744144846U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5923238786775948571U;
            aOrbiterB = RotL64((aOrbiterB * 8200882393521882651U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11044014510971660078U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 9351141024085076044U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 13316079344614432317U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17703395981862992420U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10154548848376027087U;
            aOrbiterC = RotL64((aOrbiterC * 12324478347590509035U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8836420852291617425U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10193385413543886344U;
            aOrbiterG = RotL64((aOrbiterG * 824935982418585449U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterC, 4U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 58U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterE, 3U)) + aNonceWordK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 36U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_VolleyBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF7F767247833E6A7ULL + 0x84271C96A2865E38ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA885765747002307ULL + 0xBD06AA4768FC1B30ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8D71EF5B5DC1E07BULL + 0xF686FAB6FF4918A4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x889E577AABA86667ULL + 0xA5122565EE58FE7EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB6426092D11273A9ULL + 0xA565341D8DEB9A42ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF17D240301758865ULL + 0x96D496C211012BBEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC9EDBBB1D91C30C7ULL + 0x9466B977FD26BA69ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD28F56F10FE98A99ULL + 0x81FA9926DB22E63CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF2D8C7BCEE65C913ULL + 0xE1CB389C62432E1DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC8B336DBC8039E15ULL + 0x8839F00A5C5049E3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE0C5F41FCFCC88F9ULL + 0xF5C9AEE3536958F5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE7A88A637A45F075ULL + 0xD0261BC140F79C5FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x82638407CF554F4FULL + 0xDAE053BF83FD433EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x82EDA06E95CE6E17ULL + 0xEFC61440C991205AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB920EF4CA8C4DCE1ULL + 0xEF1A621751EB9247ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD515F8B3A92B44C3ULL + 0xD2D21A1C786D545EULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1617U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 1895U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 3638U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4470U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3716U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 40U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = (aWandererF + RotL64(aScatter, 41U)) + 2672739400294801233U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 27U)) + 8475624545015101850U) + aNonceWordI;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 1252755112289831257U) + aNonceWordK;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 13U)) + 7938039507649183387U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 58U)) + 8167413146948861022U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 17712313989694374353U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 7637042279892596975U) + aNonceWordA;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 15770412950033467341U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3951812021898608685U;
            aOrbiterE = RotL64((aOrbiterE * 6623127125223204737U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8656983621098246507U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17943342344730687317U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16495519451034883813U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3087677463651608668U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 16493240011924342788U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 16898479041530771871U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7750923317452683057U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2185924841611106546U;
            aOrbiterF = RotL64((aOrbiterF * 708072658250726381U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14676868738946722416U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6849098251696302393U;
            aOrbiterI = RotL64((aOrbiterI * 2599806275837778069U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17817755047153606419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9900465270314068757U;
            aOrbiterD = RotL64((aOrbiterD * 9267925873983176685U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 11380000891112113701U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 15930503831156546113U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 14450535035065393845U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 60U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterK, 43U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 21U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 10329U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 7237U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 10617U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9737U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7855U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 6122U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 10U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 10038936806177516123U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 1773168435195292638U) + aNonceWordK;
            aOrbiterE = ((aWandererA + RotL64(aCross, 41U)) + 10655711161526628072U) + aNonceWordJ;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 3U)) + 14422295664639740437U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 12U)) + 4125228715513159576U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 57U)) + 3670449653158650845U) + aNonceWordO;
            aOrbiterK = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 17553727567180813057U) + aNonceWordH;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5111401772713882743U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7688573124662314413U;
            aOrbiterE = RotL64((aOrbiterE * 10846442063022821393U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9438375825507814395U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14177477039902118886U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6467406626985022537U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16329942595859623928U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3990536794006836672U;
            aOrbiterD = RotL64((aOrbiterD * 579024714339065373U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5072881436583180756U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16789727877867289997U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8766246302636197905U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 17313956922306689438U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11530878396329822041U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 11356860047841383129U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3612616532321160196U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4172189825359187763U;
            aOrbiterK = RotL64((aOrbiterK * 12938945495299393177U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8677279703778052804U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1912172980909479362U;
            aOrbiterC = RotL64((aOrbiterC * 10053289257955474143U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterC, 3U));
            aWandererE = aWandererE + (((((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 44U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterK, 29U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterD, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 23U)) + aOrbiterG) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 22U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 11967U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 15464U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 16079U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12423U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14241U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 19U)) ^ (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererK + RotL64(aIngress, 12U)) + 4259993311776766595U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 35U)) + 2857813330021126753U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aCross, 29U)) + 1345396841329442896U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 43U)) + 320992148982301024U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 5619109532065293074U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 10380157329426706345U;
            aOrbiterC = ((((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 12449831150625409695U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7847096607042268396U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11707184096803214678U;
            aOrbiterJ = RotL64((aOrbiterJ * 1959476948106553973U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9893643746186827088U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 333687403830908774U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17911256836121454271U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13837360705077441580U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 4367119682175710689U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 10295744669174603401U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1193493435041306784U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15062951612027370606U;
            aOrbiterK = RotL64((aOrbiterK * 2509383510565136549U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16000173839235429105U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15294482444605409961U;
            aOrbiterD = RotL64((aOrbiterD * 1031800997944302665U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5720749055549773527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17248674962996093668U;
            aOrbiterC = RotL64((aOrbiterC * 15730637462755795591U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16956840483882091059U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9637715107943515594U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 8878362378343603463U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterC, 50U)) + aNonceWordP) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 48U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 51U)) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterD, 21U)) + aNonceWordA);
            aWandererB = aWandererB + ((((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 20U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20591U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 17337U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 20583U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20994U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 20773U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 50U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (aWandererI + RotL64(aIngress, 58U)) + 7960325128608297381U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 12773836012104052042U) + aNonceWordP;
            aOrbiterD = ((aWandererC + RotL64(aCross, 51U)) + 3173972621347773016U) + aNonceWordI;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 3708401356314308171U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 5U)) + 950774285720019449U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 4170092315705438265U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 37U)) + 17000449130864980747U) + aNonceWordG;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8793910540062893860U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 520277969543516469U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 4150613128885828229U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12762214857389827271U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2932451184340207695U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7513337346940091655U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11062179998786293839U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7919119215271524178U;
            aOrbiterJ = RotL64((aOrbiterJ * 9053677007180081359U), 21U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 1774988449597115155U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3799792889466518953U;
            aOrbiterI = RotL64((aOrbiterI * 17512791286490623455U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1815062051307896589U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15260373951371654483U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2208604434669491625U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12867546628945676853U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7772820973895846946U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 7581704643538761985U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14213957831821966834U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16561105721170419454U;
            aOrbiterK = RotL64((aOrbiterK * 2540533987337175367U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterA, 42U)) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 23093U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneB[((aIndex + 22460U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24144U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25594U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = ((aWandererF + RotL64(aScatter, 29U)) + 8604208734152026945U) + aNonceWordC;
            aOrbiterI = (aWandererD + RotL64(aIngress, 41U)) + 1374329953253889829U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 5779278910548228339U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 21U)) + 17670451230882805140U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 37U)) + 8193848740764866860U;
            aOrbiterA = (aWandererH + RotL64(aCross, 5U)) + 15801168428145650104U;
            aOrbiterH = ((((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 2584718176087499066U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14950366247822737997U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9779293225265670135U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 11625969538497982117U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8688968319288372383U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13665723186950342601U;
            aOrbiterD = RotL64((aOrbiterD * 292035540396910837U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9395428688359973510U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2152719218018108418U;
            aOrbiterJ = RotL64((aOrbiterJ * 15271961483518392671U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1350324137411377992U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8729317951386057921U;
            aOrbiterF = RotL64((aOrbiterF * 6008790836417785083U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 6317310451893678411U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10175620379041384281U;
            aOrbiterA = RotL64((aOrbiterA * 14079679617394330781U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1203082119358827708U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 523869107818193101U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 4629501113595689157U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4028324959540432983U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15447631947468213912U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6037306615787729185U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 38U) + aOrbiterI) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 50U)) + aOrbiterF) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterH, 19U));
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 35U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 28318U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31623U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28681U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27329U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 22U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 15383045568644941552U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 57U)) + 17452811657750910067U;
            aOrbiterG = ((((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 15660117718455155603U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 11U)) + 10396441207743665753U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aWandererE + RotL64(aCross, 29U)) + 3708971058200841442U) + aNonceWordL;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 7000673057768598750U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 22U)) + 9886354469011131596U) + aNonceWordP;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16018065329058043467U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5024756166109352320U;
            aOrbiterG = RotL64((aOrbiterG * 11660932185479046483U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6587818720728886652U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 3652672354944162319U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 10807121230791716109U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6307315649915348048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16405347331742979258U;
            aOrbiterJ = RotL64((aOrbiterJ * 7183142442906743699U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5427299664054601957U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4983381733483185898U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14646556236306407673U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10182995521328377487U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8694282877540593550U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 14614602561910403893U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4085927978153269932U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6176195962815240877U;
            aOrbiterC = RotL64((aOrbiterC * 16792916528959579875U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6966742100601433005U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9920952446921247521U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1879821050131820933U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterA, 34U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 41U)) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 23U)) + aOrbiterD) + aNonceWordB);
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 57U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterC, 51U)) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBB4CB9BB73FE1B35ULL + 0xF5625F8AE4E680A2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC0608EBF04E80241ULL + 0xA1CF1021465A084CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8AF663B9743413C7ULL + 0xF95EB80FFD41E900ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFD0B832248D1CFD7ULL + 0xC821E6D4FB038CBCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCA96F6A35D8D6B77ULL + 0xEEA7DCB03D1C1196ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xED98CA91AFCA32E5ULL + 0x93CBC2406F6D1F20ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8161158E0B3A2235ULL + 0x969F1F21C4307285ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC308D24C18C37491ULL + 0xA54B3ABCEB042E5EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x95E05A442F86EB6FULL + 0xA8736854024EE470ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF321EE586D268BD7ULL + 0xC7DC2265BCB16E63ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB26890C7F925D5FFULL + 0xE743517E980AD0D1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFBC6445541E1147FULL + 0x9D8C430E4FC41EE2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x87CADEC75675BC0FULL + 0xC3B29E8CF576BDE3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF1DA5F151264ACE1ULL + 0xBADF7C061A6888C0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA4918D07C45DD21BULL + 0xF9B2110D7912BD2FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA2E6DB468113E4F5ULL + 0xCB3C5F05583A8A39ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7691U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 4644U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3429U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2153U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5354U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6472U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 4970414922752555648U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 11U)) + 9462756592787669327U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 34U)) + 3948790686662213095U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 14542857212241578311U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 3U)) + 3387479009827029547U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 1411421370057797877U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 21U)) + 16894451466895681236U) + aNonceWordG;
            aOrbiterD = ((aWandererG + RotL64(aCross, 46U)) + 12727136462290223542U) + aNonceWordL;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 19U)) + 4625389198191960525U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = ((aWandererF + RotL64(aCross, 39U)) + 3471881403786164913U) + aNonceWordD;
            aOrbiterA = (aWandererH + RotL64(aScatter, 5U)) + 6433115856048534831U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9825592965466157982U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1553125767261293088U;
            aOrbiterC = RotL64((aOrbiterC * 411535191177308781U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9951616357109647617U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11231080382787286889U;
            aOrbiterI = RotL64((aOrbiterI * 14024961994986659187U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13419663264017317947U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4835055642466215566U;
            aOrbiterK = RotL64((aOrbiterK * 17898065852351759171U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14558747666410946768U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13120938960926874504U;
            aOrbiterE = RotL64((aOrbiterE * 5681766019285559739U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11910501376797343986U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15074100100781785300U;
            aOrbiterD = RotL64((aOrbiterD * 228976960937473851U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12415377930578091821U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14882039078390681802U;
            aOrbiterG = RotL64((aOrbiterG * 13855446647753150713U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8094338361713756895U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5478280604704108822U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18062931724700600993U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6977017654546871841U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4131602217285988962U;
            aOrbiterJ = RotL64((aOrbiterJ * 11865422227883712419U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9619228479582032318U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13506679497441415586U;
            aOrbiterA = RotL64((aOrbiterA * 5789932662418992799U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 10180259475831448124U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4721628773773094283U;
            aOrbiterB = RotL64((aOrbiterB * 10834196399754443771U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7898137727558813688U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4970414922752555648U;
            aOrbiterF = RotL64((aOrbiterF * 6651835668618579479U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 24U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 58U) + RotL64(aOrbiterG, 23U)) + aOrbiterC) + aNonceWordA) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 18U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            aWandererB = aWandererB + (((RotL64(aIngress, 26U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterH, 28U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererC, 26U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9329U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 10929U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 14411U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13721U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9718U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14133U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12205U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 12U) + RotL64(aPrevious, 29U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 48U)) + 380024772508948442U) + aNonceWordF;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 5U)) + 7649029098162567210U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (aWandererE + RotL64(aScatter, 23U)) + 5329304598870421851U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 13U)) + 12306118665045151326U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 51U)) + 960751560457324256U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 3244070254386191876U;
            aOrbiterK = (aWandererD + RotL64(aCross, 29U)) + 15733408571609521746U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 53U)) + 17623448932647018544U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 8787759896149035829U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 57U)) + 14741681792348288162U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 18U)) + RotL64(aCarry, 13U)) + 8801731213568307302U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9872248187499779222U) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15407371518644528235U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 1245102406469471673U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4242060317152943062U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9942784962409917541U;
            aOrbiterA = RotL64((aOrbiterA * 888649755587764533U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 7296348796484458631U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15061417216070157797U;
            aOrbiterK = RotL64((aOrbiterK * 10349554676953256231U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3233185810644297433U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9241229457641024287U;
            aOrbiterF = RotL64((aOrbiterF * 2728237515724597517U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8464051359381554575U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3307872165699029375U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4859663401033023433U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5482617843966711997U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4442149210462943872U;
            aOrbiterC = RotL64((aOrbiterC * 8979352218576515647U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10591636597580147381U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14925122230279312217U;
            aOrbiterG = RotL64((aOrbiterG * 15038171961638724013U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9772367878232735350U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15800661165607190092U;
            aOrbiterI = RotL64((aOrbiterI * 10493976952980533589U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1571665862499272194U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3162847040693387901U;
            aOrbiterJ = RotL64((aOrbiterJ * 2747235335326991399U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4868791925868749848U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13134549226315884613U;
            aOrbiterD = RotL64((aOrbiterD * 3551955270718495869U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7830447320021657240U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 380024772508948442U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5143324968958616357U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 24U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 48U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 20U)) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterB, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 10U) + aOrbiterH) + RotL64(aOrbiterG, 35U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterG, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + aNonceWordN);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 18U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 50U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21960U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 21876U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 24253U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 16617U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21895U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21546U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21007U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 48U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 3U)) + 7948891781097675369U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 47U)) + 13928362874228230226U) + aNonceWordJ;
            aOrbiterC = (aWandererI + RotL64(aScatter, 10U)) + 10776180542602258926U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 41U)) + 5735115172149470447U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 39U)) + 5353591822981766987U) + aNonceWordI;
            aOrbiterB = (aWandererK + RotL64(aIngress, 23U)) + 562301708107268570U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 10467810247578364868U) + aNonceWordB;
            aOrbiterH = (aWandererA + RotL64(aCross, 37U)) + 14541630141152308564U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 2350076897065139429U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 20U)) + RotL64(aCarry, 21U)) + 17519109078651162228U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 5U)) + 6061035173339902910U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15654836633731000065U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13723521735153718904U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14459516479283070563U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2849680038315532197U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17336102435576647923U;
            aOrbiterK = RotL64((aOrbiterK * 10984689101753586739U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7671010488872356142U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11485114338165600777U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 4162584865462407791U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8759060657343458985U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11009137869375286581U;
            aOrbiterJ = RotL64((aOrbiterJ * 8741417343929809115U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15792999392743144135U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6180808423175992479U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13681230339693676907U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 361487389591183005U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15292753806514404853U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 17478232597253311153U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14929153438443362045U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7904556383593914086U;
            aOrbiterH = RotL64((aOrbiterH * 2484130486635511403U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3793180909904286848U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10391957637467171320U;
            aOrbiterD = RotL64((aOrbiterD * 505484041943467117U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11648765065563798353U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 17601185776537566611U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 4753179291885740011U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2907499704986356444U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17048858067202291241U;
            aOrbiterF = RotL64((aOrbiterF * 2607549567999666889U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4340465159886930775U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7948891781097675369U;
            aOrbiterE = RotL64((aOrbiterE * 12913104720552907335U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 36U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterK, 21U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterD, 51U)) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aCross, 12U) + aOrbiterE) + RotL64(aOrbiterG, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterF, 23U));
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterK, 30U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 19U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterI, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 10U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 39U) + RotL64(aOrbiterE, 37U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererE, 50U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31846U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 25250U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25438U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 25316U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30433U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29081U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 30169U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = (aWandererH + RotL64(aScatter, 3U)) + 7270044678408187242U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 11U)) + 10192278965379756766U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 17568666746676060748U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 35U)) + 14312927531124963037U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 26U)) + RotL64(aCarry, 3U)) + 9825825726152087706U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 9696778570255265896U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 51U)) + 17657841352013417228U) + aNonceWordJ;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 29U)) + 16207815085909628439U) + aNonceWordD;
            aOrbiterK = (aWandererE + RotL64(aIngress, 19U)) + 1752979206374514227U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 54U)) + 10456310689643905854U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 21U)) + 16127830548663742550U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2940917376003930842U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7353596864777649953U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 7499468723171042005U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12725092740446150705U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5791296650856037010U;
            aOrbiterB = RotL64((aOrbiterB * 760379251950502133U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1200130368046206150U) + aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16689604428598558547U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 13815324235939996623U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14359561591103730856U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3975025843599045263U;
            aOrbiterJ = RotL64((aOrbiterJ * 5025047888533298617U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14017901732955607601U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10431526786489555196U;
            aOrbiterD = RotL64((aOrbiterD * 10181915874476132407U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7320527073559849223U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15333411223710709907U;
            aOrbiterA = RotL64((aOrbiterA * 3488684905528068775U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14302474063321663801U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2104154521019935187U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12944382959742278055U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5167600586916325228U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 4566823109447208716U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9997799807454267443U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12475580453805083495U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15461491763911887974U;
            aOrbiterE = RotL64((aOrbiterE * 13548865386159287481U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11000532703581114393U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7815822789941347770U;
            aOrbiterH = RotL64((aOrbiterH * 1476638214324946775U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2166336159928211562U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 7270044678408187242U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 10648564933168714815U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 42U) + aOrbiterH) + RotL64(aOrbiterJ, 57U));
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordF) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + aNonceWordC);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 42U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterA, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterF, 19U));
            aWandererB = aWandererB + ((((RotL64(aCross, 26U) + RotL64(aOrbiterI, 37U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterB, 46U));
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB59E5F8AA1FF6455ULL + 0xD2568E3A6D74FF9EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFC080F81738B0409ULL + 0xE30AE6E30B8187DFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE680DA2892AD8D93ULL + 0xFC71AFCFC0EF3DAAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB8E00F338F0A528FULL + 0xF21A868FF449DF3CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE90C8DC6A7E465EDULL + 0x8D199D7CAF7C77CAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB3DB9019EC45ECE9ULL + 0xA9BC1447329632C5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBED0DE07D28F207BULL + 0x9DC3B02D666CBC88ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x89FCE9C3CCA7F05FULL + 0xEE1812A6B43B5BB8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAC87C51D92609EDDULL + 0xBDBE6E661E7E0823ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAF36CDBA6424B093ULL + 0xC5EFC74BBEDC2ED4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCFA2D57055A8B167ULL + 0x83D32DC22D5662D0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xACF91580CF4A39B5ULL + 0xEC012E5F9B4C9C36ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB46DA0AAB1A19581ULL + 0xE8CCE3E23F226734ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAAD9678FBFB8A675ULL + 0xFD514BD7BC9AD800ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAE2E940541239F0BULL + 0xCAEBEBB45D598E3BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9446A94AB57159DFULL + 0xB8686E7E3EA7B2E5ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5465U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 6087U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4932U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1475U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2201U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4708U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 60U)) + 6243113109470883144U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 23U)) + 3891552123999605832U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 27U)) + 8758797898587019128U) + aNonceWordP;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 1005891374086408851U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 11U)) + 3713426782180050764U;
            aOrbiterC = ((((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 18358143862391573534U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 17504394029693712404U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 35U)) + 5312729289027417014U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 48U)) + 2560873623431186029U) + aNonceWordE;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16309322822806704211U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10195513918020652600U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14569219741824123715U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2552116263258744287U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7732784879810980089U;
            aOrbiterC = RotL64((aOrbiterC * 15041929399477790999U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16499127570665381507U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10890036715535519036U;
            aOrbiterH = RotL64((aOrbiterH * 9065115450010475187U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16288944603478791554U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14542766121469312846U;
            aOrbiterB = RotL64((aOrbiterB * 8435383464425875209U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5973595239494084696U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1820492719977197097U;
            aOrbiterE = RotL64((aOrbiterE * 16164917159141304405U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10489529555776381736U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6392552206958240484U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11761477994533503307U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10163241948999404556U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 16054678853554707148U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10570418210789350091U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3606021702108590330U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 16920568417324295852U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5222656554577625385U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13889995689147406315U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7908387312354285092U;
            aOrbiterA = RotL64((aOrbiterA * 7995682580514280949U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 6U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterB, 41U));
            aWandererB = aWandererB + (((RotL64(aIngress, 56U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterH, 14U)) + RotL64(aCarry, 11U)) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterE) + aNonceWordO);
            aWandererD = aWandererD + ((RotL64(aCross, 10U) + RotL64(aOrbiterG, 51U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 60U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16380U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 12635U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13929U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneC[((aIndex + 12562U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9866U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14734U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10619U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 53U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (aWandererK + RotL64(aScatter, 23U)) + 4179952823252098240U;
            aOrbiterD = (aWandererC + RotL64(aCross, 13U)) + 3745613452332101749U;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 58U)) + RotL64(aCarry, 13U)) + 2955689793395307176U) + aNonceWordK;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 5639060180251322019U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 7901969163853586463U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 19U)) + 2242166787816318119U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 51U)) + 5239936443960750064U) + aNonceWordE;
            aOrbiterI = (aWandererE + RotL64(aCross, 43U)) + 13939136954732185558U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 38U)) + 17058884136712717463U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 18148618660054585941U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7022023484530327814U;
            aOrbiterB = RotL64((aOrbiterB * 650100011311048589U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7722084537340095637U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11764151879690934182U;
            aOrbiterK = RotL64((aOrbiterK * 12264384877711365655U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16412785901758144708U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9666718667728274824U;
            aOrbiterE = RotL64((aOrbiterE * 10865799822751771795U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4307127540152109364U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2457646804702647606U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 6340030928007058595U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3179394870088602208U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 504977947273774249U;
            aOrbiterI = RotL64((aOrbiterI * 16190282058883481551U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16182729401018310837U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7110817020445860609U;
            aOrbiterF = RotL64((aOrbiterF * 13371352088428584087U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12960656706837391973U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7103806893724395904U;
            aOrbiterH = RotL64((aOrbiterH * 14365984439655979791U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1248300178080633527U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7195473175424961337U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 4633558992739305045U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13007951568242991449U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10296811247653636372U;
            aOrbiterJ = RotL64((aOrbiterJ * 16469682651380549395U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterD, 43U));
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 19U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 28U)) + aOrbiterF) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aIngress, 46U) + aOrbiterK) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24112U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 24315U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 17097U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16557U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18474U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22395U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 23169U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 19U)) + (RotL64(aCross, 54U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 30U)) + 4751694786009671052U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 41U)) + 16362725160370844224U) + aOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 23U)) + 6360885380915941057U) + aNonceWordL;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 35U)) + 5154536007972297036U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 9362540581874808253U;
            aOrbiterC = (aWandererE + RotL64(aCross, 47U)) + 13902493871525612934U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 10208452885367546542U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 3117030377279160998U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 54U)) + 17286247690414027870U) + aNonceWordN;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3930314320040949141U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7289525252391668404U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 15452162299105112187U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3434167955466809185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17852573095128575663U;
            aOrbiterC = RotL64((aOrbiterC * 1485660158767033425U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6137259687928853253U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13992510605237574698U;
            aOrbiterB = RotL64((aOrbiterB * 15346263295995333395U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6470556523400123474U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4333255670390099293U;
            aOrbiterH = RotL64((aOrbiterH * 11089933812030082647U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7700424876430257995U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16920736951239453071U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8920407493132380497U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1635071690430295730U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9966700845966398620U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 17210048121896546867U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9833458070123027075U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1990346556486746432U;
            aOrbiterI = RotL64((aOrbiterI * 8704943923474148699U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13339523466436517327U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5018264760406215603U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 2769197961801783627U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 123427497520755346U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4535841104215792886U;
            aOrbiterD = RotL64((aOrbiterD * 1417676310539177131U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 54U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterB, 60U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 37U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 4U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 11U)) + aOrbiterD) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterD, 26U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28463U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 28597U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 30679U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32230U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25872U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26912U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 29537U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (aWandererC + RotL64(aScatter, 43U)) + 9654059367478508868U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 26U)) + 6473006635864677427U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 51U)) + 6944184481315853243U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 4061496421939102306U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 15791809275719085463U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 5U)) + 14050798802646323055U) + aNonceWordG;
            aOrbiterH = (aWandererA + RotL64(aScatter, 39U)) + 12072905924741758266U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 22U)) + 17639076509231343896U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 12195388285571234715U) + aNonceWordI;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4325404419499496529U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5910567888204238382U;
            aOrbiterB = RotL64((aOrbiterB * 11503787177122206937U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 13092940059929942699U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13381962590820308761U;
            aOrbiterG = RotL64((aOrbiterG * 6345904465930943295U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 15622862439323440527U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14027151901132249793U;
            aOrbiterH = RotL64((aOrbiterH * 2273573821630510087U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4584410023907605157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15763755180625487157U;
            aOrbiterE = RotL64((aOrbiterE * 6755736130607297639U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17023059745666559199U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5298529579288492971U;
            aOrbiterF = RotL64((aOrbiterF * 2483562793328357721U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2870152867331654736U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12017191100173748848U;
            aOrbiterC = RotL64((aOrbiterC * 9958191466506480519U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15899529176182436062U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16482713846343388735U;
            aOrbiterK = RotL64((aOrbiterK * 719465695044265601U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 12943393531812774449U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9881108254540483225U;
            aOrbiterA = RotL64((aOrbiterA * 8011108108007885059U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3532054586199716750U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7142230313294797435U;
            aOrbiterJ = RotL64((aOrbiterJ * 14154176174768868421U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 48U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 42U)) + aOrbiterC);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 37U)) + aNonceWordE) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCE31220DDA2CF9D7ULL + 0xC0C4DC3D4A5E9357ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD0B0F747F1B0DFE5ULL + 0xB9452D28172DC72FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEA6CE3FE41A19443ULL + 0x86AFBA81B9DA8C25ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDB9ABA9D2B3FBDBDULL + 0x893B4ABA8515FFD1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF79CF59658ADBE85ULL + 0xD6EE0ECE53954B49ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC468F76A606E7561ULL + 0xBF071B42BE764F9DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9BD4769289E8963BULL + 0xD8ACBD16F2BCC92DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9BE4779234F38097ULL + 0xAE60804EA64240B0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9F7B7224F6016ED3ULL + 0x8647183EF176EC40ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF4AA2BB7EC782B37ULL + 0xBE801B888C201A1DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC778717B1D237A99ULL + 0xAF45515EED712151ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8C60E45C954A44BDULL + 0x9D2ACB82BBCF799FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFE1A1FDBCE4305DBULL + 0xA476CEA209FFF540ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE79341F2F0928FB1ULL + 0x9F3D28F48A1F9978ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBCD0B32ED985FA85ULL + 0xE238940B368E721DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD9E148A951947FC1ULL + 0xAFD204DCA1FD8AE5ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4163U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 4559U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7446U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5278U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5060U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5380U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 56U)) + (RotL64(aCarry, 13U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 1393781663398437180U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 35U)) + 17414594746688585273U) + aNonceWordF;
            aOrbiterG = (aWandererI + RotL64(aCross, 41U)) + 2823888497053071250U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 18U)) + 17032631958617884859U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 15222697630461125019U) + aNonceWordE;
            aOrbiterD = (aWandererK + RotL64(aCross, 5U)) + 15737414920751551780U;
            aOrbiterK = ((((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 1357196111055783001U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5315122321649251691U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 7893744655508595974U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 17863000246694319149U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 16721939414324611738U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3444375866323610848U;
            aOrbiterF = RotL64((aOrbiterF * 10874157227815775661U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1825716513674511632U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15582066843912467318U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 12765146555943757373U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15673590949193923915U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13887365046280406413U;
            aOrbiterE = RotL64((aOrbiterE * 3169061375011420121U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12730414371734709356U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4819112390640821927U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 8782547948627685451U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3089925954422937464U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7180179304678622530U;
            aOrbiterB = RotL64((aOrbiterB * 16118051565147747413U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17030269962085008657U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6675917351883004046U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14134335325316949687U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 21U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 51U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterF, 4U)) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 41U)) + aOrbiterD) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 52U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8280U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((aIndex + 12475U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 10865U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11483U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11420U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10925U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9169U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 50U)) + (RotL64(aIngress, 19U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 9041099828460168106U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 12883711604096848454U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 13U)) + 17420968786226443079U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((((aWandererH + RotL64(aCross, 38U)) + RotL64(aCarry, 39U)) + 3448213891716125104U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 47U)) + 11866455977445336560U) + aNonceWordI;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 53U)) + 4119356835384495905U) + aNonceWordH;
            aOrbiterF = (aWandererD + RotL64(aCross, 23U)) + 2186212599698637068U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6506144898969301620U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12556800923644051626U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15961043406612913121U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4075551535185182945U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17877694808492008749U;
            aOrbiterG = RotL64((aOrbiterG * 901315308379887473U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5553428900598223316U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14362304852277160675U;
            aOrbiterC = RotL64((aOrbiterC * 11415103199856419303U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 9174200302876075831U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16110739511917638547U;
            aOrbiterE = RotL64((aOrbiterE * 7004356839428657949U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10189881974519849402U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2128076632642616677U;
            aOrbiterK = RotL64((aOrbiterK * 8860453653433114929U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 18133523799074400083U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9916472958834153766U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 3454601168808001733U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10274457562795569227U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 14134814273275356425U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15912501063665343159U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 6U)) + aNonceWordB) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterC, 13U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 40U) + aOrbiterK) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK + ((((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 35U)) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterK) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterG, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21086U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 24031U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 23616U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19339U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16618U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16475U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20927U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 47U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 21U)) + 17711946802293254150U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 16652362590489569378U) + aNonceWordN;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 6972810344198183097U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 5U)) + 13117100889782940546U) + aNonceWordE;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 37U)) + 13199305696782626591U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 27U)) + 992156184392760945U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 43U)) + 13791265442074543880U) + aNonceWordO;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17057087245252294859U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13444195995883541046U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13067044288608808777U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6723678233676059420U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7913379431208430475U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 2295062944289127123U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4481887195529300665U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 11892724101424384078U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 3468639499716604111U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7700902083270424194U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1888001433557140271U;
            aOrbiterG = RotL64((aOrbiterG * 8975562955027025349U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14996753906788986929U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 939004845422123765U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 2507090308972292313U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11922230289291941807U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15681187459741147199U;
            aOrbiterD = RotL64((aOrbiterD * 10124947739653819101U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9119043713532718155U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8327697433992362166U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11157657162184304567U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 28U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterA, 5U)) + aNonceWordH);
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterG, 39U)) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28275U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 26682U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 29600U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30094U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30751U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29042U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27137U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 57U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 17019646486641172469U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 12276141179299971572U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 23U)) + 3617241694029841555U) + aNonceWordJ;
            aOrbiterF = (aWandererH + RotL64(aIngress, 30U)) + 6967963401259371737U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 53U)) + 6340709284279891017U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 456065368903896482U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 3U)) + 17686765719908116203U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1322045955429785736U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5163772703302372887U;
            aOrbiterG = RotL64((aOrbiterG * 3193272189179082313U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13268431135020363252U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6538789950366849332U;
            aOrbiterI = RotL64((aOrbiterI * 5352960308459065837U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10390344544314544893U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5087084271300584267U;
            aOrbiterF = RotL64((aOrbiterF * 15149302947570776165U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 13423071121590981727U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18324443012024134729U;
            aOrbiterE = RotL64((aOrbiterE * 15814349432207734533U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4129091815978464507U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17024797553831962245U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3137753479364378175U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6501545108779991661U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11930037791867597447U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 4904739567549702851U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4667298703308315851U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6315980380900062127U;
            aOrbiterH = RotL64((aOrbiterH * 12080555704907924637U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 10U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordP) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterG, 46U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 6U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + aNonceWordF);
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + RotL64(aOrbiterB, 23U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 56U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_VolleyBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA4669D61EE2730E7ULL + 0x9871210AE742B3A0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF389758A21FDE075ULL + 0xDFD8F3E6575B7E84ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x87967C019658D737ULL + 0xD795CA076139FC22ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEA8DE06356698F81ULL + 0xF0D3431C90435C88ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9262B3454B44AB7BULL + 0x951DCD16F1963E62ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE9D5F72046CE69ADULL + 0xD8D25C99743813BFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB97B4DBFDC944FA9ULL + 0xF9302AE54B9AD44AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCFDBF6A32693D339ULL + 0x9154280E241B667BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB868B47954E16781ULL + 0xB7326BBB97A336CCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC889DF01F3635613ULL + 0xC16F33AC33BA5FE6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x85766F774387CEE1ULL + 0xFF79C606AF958F60ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCCCC6B6B0095DF2BULL + 0xBDB9E51618D495D9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC3FEA84CE2E318D5ULL + 0xC1F7C9678DC7C34AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF40C0D26F7DEB249ULL + 0x8AA06FB7211F3142ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x89A913469F1DDF37ULL + 0xD5339AA1ECF2EBD2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x94BDB8280137BF83ULL + 0xFEE2DF45A63B48C5ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2160U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 364U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1304U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 345U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 15549114274303128055U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 11U)) + 16466750056388063241U;
            aOrbiterA = ((((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 12209449840836787142U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aWandererF + RotL64(aIngress, 35U)) + 14551496099734294336U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 21U)) + 6266576428679808622U;
            aOrbiterB = ((((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 16892841575635668152U) + aPhaseEOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aWandererH + RotL64(aCross, 54U)) + 7375966221423362125U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11926105302821753530U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16219253791550461124U;
            aOrbiterA = RotL64((aOrbiterA * 2117550758226173419U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7299056065319248160U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15234001484933728439U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8182244796017018911U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6615802589932632120U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5481176858895819247U;
            aOrbiterB = RotL64((aOrbiterB * 3604590158551984877U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17220507586542139380U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14137921473739415340U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10634645686035907603U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16981960446540932787U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10897565927079518588U;
            aOrbiterD = RotL64((aOrbiterD * 418843936329303571U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2746889569299593263U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4894117146736361379U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 2656750612042673191U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 18294823016957137777U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 86828501068883383U;
            aOrbiterE = RotL64((aOrbiterE * 11432686669235402365U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 42U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aNonceWordH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + aNonceWordF);
            aWandererB = aWandererB + ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 11U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 44U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 37U)) + aOrbiterJ) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3558U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 4951U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4520U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4178U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aCross, 13U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 48U)) + RotL64(aCarry, 53U)) + 11998579547770778580U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 57U)) + 8409465187298704610U) + aNonceWordL;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 3470222286110333500U;
            aOrbiterI = (aWandererF + RotL64(aCross, 27U)) + 5704486785203069994U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 10334944660253279633U) + aNonceWordG;
            aOrbiterE = (((aWandererC + RotL64(aCross, 19U)) + 7626852700722567477U) + aPhaseEOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 3U)) + 14631310754943209743U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 807160297237854120U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5624154783624196107U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 2404066593958052159U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4971444394698940423U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6340057638461027062U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12027586111086798629U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9003019862787819481U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13632057463595873033U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12575202147280216765U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12766104026871797746U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4062118445824915939U;
            aOrbiterD = RotL64((aOrbiterD * 13130770039048080701U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5258212525426469978U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9956946981015983939U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 8106382657040497669U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10837606223056473999U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13292864885504191134U;
            aOrbiterE = RotL64((aOrbiterE * 4445739587553669471U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 166087925900318658U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6786842221885441388U;
            aOrbiterG = RotL64((aOrbiterG * 4411147600413147773U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 4U) + RotL64(aOrbiterI, 35U)) + aOrbiterG) + aNonceWordA) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 52U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7993U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 7774U)) & W_KEY1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6629U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5678U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7730U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 42U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 8866844335448071821U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 29U)) + 15159698739856430085U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 35U)) + 9582805772989594633U) + aNonceWordE;
            aOrbiterA = ((((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 1438538239931588373U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aWandererC + RotL64(aCross, 41U)) + 10862044156620436139U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 18U)) + 13682173320058164615U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 8351013291045977592U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 15777857431516633916U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16178966745333885377U;
            aOrbiterE = RotL64((aOrbiterE * 7545129923202147703U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9031889187993001617U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6308472367425865347U;
            aOrbiterC = RotL64((aOrbiterC * 17118710301967158153U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 642109145903321046U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9186268569255318035U;
            aOrbiterB = RotL64((aOrbiterB * 10714674348507516749U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6091345356803675860U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13218507921880873749U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 15415157927185637717U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4266652275234474616U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4391422098164506195U;
            aOrbiterI = RotL64((aOrbiterI * 17634679403195085867U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 5160682323243635577U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10351728852161347404U;
            aOrbiterF = RotL64((aOrbiterF * 11105410036471745951U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3950932176454814023U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 9536466386833427441U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 18064984243491293435U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 4U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 13U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterH, 51U));
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 58U)) + aOrbiterI) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aNonceWordD);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterB, 41U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + aNonceWordA) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 30U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 8741U)) & S_BLOCK1], 36U) ^ RotL64(aKeyRowReadB[((aIndex + 9009U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 10109U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((aIndex + 9491U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9851U)) & W_KEY1], 41U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 9241U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 50U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererB + RotL64(aScatter, 11U)) + 1364174714924216027U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 22U)) + 13561796874229506613U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 11845572344206238305U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 15762708240326773763U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 1157119665207900473U) + aNonceWordC;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 57U)) + 6823546624372055260U) + aPhaseFOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 43U)) + 14465564210523945121U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10667464548080807531U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13445737493224316575U;
            aOrbiterG = RotL64((aOrbiterG * 12137295000900795711U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3009837893785957665U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2886920524111083752U;
            aOrbiterD = RotL64((aOrbiterD * 15308180928967762543U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10886177449328249656U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15067759884678100433U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 5724566815989860041U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 18307930462682331536U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 8791864377579255801U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 9265158882471421767U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 805797468642992351U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5743305867058244964U;
            aOrbiterH = RotL64((aOrbiterH * 16263000753351131717U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17102025528234481273U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1841579177327486899U;
            aOrbiterC = RotL64((aOrbiterC * 3841603385577825265U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2189493507896508972U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 18209567010094914374U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3737080408976852351U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterC, 43U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 37U)) + aOrbiterD) + aNonceWordP) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 36U) + aOrbiterG) + RotL64(aOrbiterJ, 14U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12275U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 12379U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12026U)) & W_KEY1], 19U) ^ RotL64(mSource[((aIndex + 12058U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11144U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11409U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((aIndex + 13610U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 53U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 9751314027302668907U) + aNonceWordL;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 41U)) + 12175450995523107056U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 21U)) + 17519694958730119552U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aCross, 35U)) + 9093525527925682263U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 28U)) + RotL64(aCarry, 21U)) + 3713831321786810138U) + aNonceWordE;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 10108355209191835040U;
            aOrbiterB = (aWandererH + RotL64(aCross, 47U)) + 12956307447311314768U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1904298513945877359U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4658049993308574460U;
            aOrbiterJ = RotL64((aOrbiterJ * 10482422152074338611U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9826333658248851902U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12058666914724365134U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 964233873188373939U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2516574707110528099U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 13335308331049750235U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 5880227828760598587U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8230749255538495304U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16536559486797811486U;
            aOrbiterH = RotL64((aOrbiterH * 7097036838156464969U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12387639130570188998U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8459259798142872020U;
            aOrbiterB = RotL64((aOrbiterB * 8001346480955847013U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16083784052002800300U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1957284290736468379U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 5046501301740813065U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 7349538179311335863U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 16395170077006105258U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 4230485452156662763U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH) + aNonceWordB) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 37U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 20U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 38U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 16162U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((aIndex + 15117U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15232U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15917U)) & W_KEY1], 39U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13696U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14869U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14111U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 12222235191147985484U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 35U)) + 16367317014523328414U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 11U)) + 3511378091284703789U) + aNonceWordC;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 50U)) + RotL64(aCarry, 11U)) + 15247492830966725949U) + aNonceWordI;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 43U)) + 7745995913390407897U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererE + RotL64(aCross, 5U)) + 6463593307540108810U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 1101669311005268630U) + aNonceWordO;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12988052764067518580U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 17717179747434679772U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 10820310705487638793U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11662190906682400416U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6563014073547628748U;
            aOrbiterA = RotL64((aOrbiterA * 16967910471722117761U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13099094932059419219U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16342730862261868847U;
            aOrbiterK = RotL64((aOrbiterK * 10988124108686164829U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16855346813127524624U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6570063128502306944U;
            aOrbiterC = RotL64((aOrbiterC * 4571570049463124831U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11328352033809240501U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 11640986648833160901U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 2895830492089678919U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2675226158571501666U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17700531248266458165U;
            aOrbiterI = RotL64((aOrbiterI * 2231403813970188657U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7729597396731910874U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15172374484412053756U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 149009041406406517U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 12U);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + aNonceWordP) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 10U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 19U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterC, 10U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 42U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16967U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 18916U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 18500U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17751U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16663U)) & W_KEY1], 27U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 19113U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18613U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 8988572360732005217U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 17889613225105985335U) + aPhaseGOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 5U)) + 15563478320513948626U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 19U)) + 3441351228410524816U) + aNonceWordL;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 47U)) + 4425592689451435346U) + aNonceWordF;
            aOrbiterK = ((aWandererI + RotL64(aCross, 30U)) + 12733160231627305928U) + aNonceWordD;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 3574152157304607854U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15167631896729808783U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15822667973915417055U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 5155661648455308057U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17181685481076577637U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9979204751408873468U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8244434774754786565U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1334240485667164762U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9190066751460137016U;
            aOrbiterF = RotL64((aOrbiterF * 14585141844653660363U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15465215829109246336U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2305208282453624419U;
            aOrbiterE = RotL64((aOrbiterE * 10257861974108363283U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16951510027310993926U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11117938943423526901U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7805486716716924787U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12461379120662979432U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11719697049048823897U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14880996802304818757U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6843357278142933570U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12727898578324702374U;
            aOrbiterJ = RotL64((aOrbiterJ * 9786435451654365097U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + aNonceWordI) + aPhaseGWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 47U)) + aOrbiterC) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterK, 39U));
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 60U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 21609U)) & S_BLOCK1], 12U) ^ RotL64(mSource[((aIndex + 21089U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 21282U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneA[((aIndex + 19114U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21676U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20108U)) & W_KEY1], 56U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21758U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 19827U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 7722279280863371124U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 24U)) + RotL64(aCarry, 39U)) + 11584220561732385598U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 3U)) + 7834679350105534657U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 41U)) + 11347994382444180879U) + aNonceWordG;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 47U)) + 9449903188047063431U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 6516243976652795170U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 11U)) + 8420815253991184777U) + aPhaseGOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9081386852515170937U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 14375955191735286867U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2772840314542262283U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 880757589768436072U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3349856625725164229U;
            aOrbiterD = RotL64((aOrbiterD * 681514212582331781U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7826309957607577207U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8057435761214313635U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 4718430712767038607U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9565237500443303103U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15893066735310588501U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8457633439171452397U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3276844534476430842U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6828644383891274120U;
            aOrbiterF = RotL64((aOrbiterF * 979580351653410157U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2815676923011504251U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5030251870850928417U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7075653570570819253U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13464083008377887034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8994560761846897590U;
            aOrbiterC = RotL64((aOrbiterC * 9892839554658865143U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 35U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 37U)) + aNonceWordL) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 12U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 43U)) + aOrbiterF) + aNonceWordA) + aPhaseGWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 51U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 40U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23737U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 23344U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22309U)) & W_KEY1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 24222U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23274U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24046U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22674U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((aIndex + 23569U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 13915875634607599122U) + aPhaseGOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 1695770381382411673U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 3709105579778295511U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 3U)) + 7673376335333251804U) + aNonceWordK;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 51U)) + 8814147709738503518U) + aNonceWordH;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 60U)) + 13451412605350381172U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 13U)) + 6447870234069609538U) + aNonceWordC;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13419487997946496825U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 5478309847615220345U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 12953043149543448765U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3635184969215610049U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12527903812035294828U;
            aOrbiterB = RotL64((aOrbiterB * 12540800512035534967U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1684685110885338814U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12860354576326835090U;
            aOrbiterF = RotL64((aOrbiterF * 12743745087733307255U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9081823570147481835U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14369321778210049109U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 17865953349448767035U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11518132079084873250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11893535026126957389U;
            aOrbiterG = RotL64((aOrbiterG * 15751374986135615095U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7084079180579206226U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2999676609847603277U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14602698397511266403U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17683445810614029153U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11576460512964896969U;
            aOrbiterK = RotL64((aOrbiterK * 5243651036457051155U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 54U) + aOrbiterK) + RotL64(aOrbiterJ, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 60U)) + aOrbiterG) + aNonceWordB);
            aWandererH = aWandererH + ((((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 39U)) + aNonceWordN) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + aNonceWordO);
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterF, 11U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25836U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadA[((aIndex + 26007U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26554U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25824U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24584U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26232U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26549U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26336U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (((aWandererE + RotL64(aIngress, 5U)) + 5697928251815176134U) + aPhaseHOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 337587740689259575U;
            aOrbiterK = (aWandererG + RotL64(aCross, 53U)) + 4927686903263973950U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 37U)) + 3742409032569801033U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 23U)) + 1608092659172197650U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 12U)) + 15848744267145717509U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 15300174177963339253U) + aNonceWordG;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 14162868453323648628U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12020167069983729869U;
            aOrbiterK = RotL64((aOrbiterK * 2071080217680099017U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16259538291658723956U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8516686212464112245U;
            aOrbiterA = RotL64((aOrbiterA * 4731296903548893627U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3722184575520553132U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5663609293306386784U;
            aOrbiterF = RotL64((aOrbiterF * 14364218128780764749U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15265344442454471986U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3050323350098829515U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1093356813820599238U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15167726103772238440U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5719466863561311069U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 15170797965325981472U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17826286701992981628U;
            aOrbiterD = RotL64((aOrbiterD * 11186808881726573677U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14710892030473425181U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 397194787697553904U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14368930300818752833U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 10U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterA, 35U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + aNonceWordB);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 39U)) + aNonceWordD) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27492U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 29292U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29178U)) & W_KEY1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 28332U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27849U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29200U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28153U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 28825U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCarry, 48U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 4739486756133131180U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 16089707555501328184U) + aNonceWordE;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 15310047330238536453U) + aPhaseHOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aCross, 29U)) + 7901411596386834955U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 41U)) + 4357555491060982163U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 53U)) + 15667085602825720102U) + aPhaseHOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 60U)) + 8520635334382269253U) + aNonceWordG;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1772509779231068315U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 15336170957886025677U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 10996880551392077399U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8628770833489469980U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 15469234024247246228U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 8905266995119987947U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10796430900884288328U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10660110397012853289U;
            aOrbiterB = RotL64((aOrbiterB * 9140007610912037461U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11202284258711214794U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17509491802893182994U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 9329107599972703671U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16212572740740103554U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2190030203761579226U;
            aOrbiterE = RotL64((aOrbiterE * 3101886685668871045U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12014337082293041909U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3733531010807001506U;
            aOrbiterJ = RotL64((aOrbiterJ * 5797362244066062299U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7100994963061975529U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17837541162838600258U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 8745987361678166553U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterD, 27U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 43U)) + aOrbiterB) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 54U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 12U)) + aOrbiterJ) + aNonceWordF);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterI, 53U)) + aNonceWordC);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterE, 21U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30471U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30587U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30181U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31096U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31350U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30945U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 9080426856729228705U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 44U)) + 7851218321653539276U) + aNonceWordP;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 7023344692919298036U) + aNonceWordH;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 19U)) + 9772846154227440734U) + aNonceWordB;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 51U)) + 12008298632429608431U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 5U)) + 12201090455849562875U) + aPhaseHOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 9498721803411445471U) + aPhaseHOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 351203764023093632U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4966360430644539250U;
            aOrbiterA = RotL64((aOrbiterA * 10138518378274592739U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9194167899071345693U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4922477697284269116U;
            aOrbiterH = RotL64((aOrbiterH * 8444814161720407881U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 15742625291642356429U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7528703106518431730U;
            aOrbiterK = RotL64((aOrbiterK * 11530049278751507567U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15279053574704935317U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2425839793660355555U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11486964816849830667U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13209849392400008898U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9041500097716231309U;
            aOrbiterJ = RotL64((aOrbiterJ * 340661035700748739U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 7885423750878814599U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1992993999902904603U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 1478629826632201617U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 6120758615019314102U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8529621625846992066U;
            aOrbiterF = RotL64((aOrbiterF * 8485991471612862467U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 37U)) + aOrbiterA) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 5U)) + aOrbiterA) + aNonceWordO) + aPhaseHWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + aNonceWordK) + aPhaseHWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 20U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_VolleyBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE256802DDB737FB9ULL + 0xF3B6005F68DEEE27ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x972893B7A5FCA791ULL + 0xF6B24AA93D58DEBFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD760D5B8C8F4C3DDULL + 0xCFC2434A49184660ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDACC5E6E367B77B7ULL + 0x9686A03878A85866ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAC8C89BECD49E39DULL + 0xD0E03FCED08F63B0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA05B255833778EF1ULL + 0xC72313EF8343128CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF9B8F5C67F1B8021ULL + 0xE2F6412056249CFDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAAEF3E6F8A3641B5ULL + 0xC6C9B1013EC8A22DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF5E0BA681F888B77ULL + 0xC3CC238804995CE0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x83BF1F12295884D7ULL + 0xF7B1F6E7743CE2AAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC90F85F85B4C9885ULL + 0xF13D0C4FCFF45209ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCA792BEA12D15A7DULL + 0xEEE84A18342C6C8AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAE33465B93C6689DULL + 0x84932408A40E46EFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x93FB952CA76DF095ULL + 0xD37C09DB12DBBE07ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDEF6DA4741329CAFULL + 0x9E610FB52C251BA4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD8FEB42C7A1DFFDBULL + 0x8AB61760634424E7ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3145U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 5322U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2364U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 930U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 844U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4394U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 41U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = ((((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 12426357877879529292U) + aPhaseAOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 14U)) + RotL64(aCarry, 41U)) + 12604900366173639176U) + aNonceWordD;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 23U)) + 13511119007338929401U) + aNonceWordI;
            aOrbiterB = ((((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 9878720081166788060U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 37U)) + 15463195409806395076U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6407922778852833423U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7690427254160734016U;
            aOrbiterI = RotL64((aOrbiterI * 11841396512731990295U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 18030974031722143619U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17983938038322737041U;
            aOrbiterD = RotL64((aOrbiterD * 12479365337221685413U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16605512170117753884U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 681802273302348322U;
            aOrbiterK = RotL64((aOrbiterK * 14608920184802647123U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15550312921312083819U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17824154101711884508U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 7358612830654795357U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1939207786756735430U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 3132864634777826569U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 13606281919426730325U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 46U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterI, 50U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 30U) + aOrbiterH) + RotL64(aOrbiterK, 21U));
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterB) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 23U)) + aNonceWordO) + aPhaseAWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5599U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 8166U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10646U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((aIndex + 9637U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8459U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9446U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8073U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 60U)) + (RotL64(aPrevious, 43U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 2786079456995203065U) + aNonceWordJ;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 57U)) + 7237256119153857253U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 36U)) + 9310834010563647604U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 17361734905706517877U) + aNonceWordA;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 15837111231884647451U) + aNonceWordL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18065431964418026445U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3029123922999952652U;
            aOrbiterD = RotL64((aOrbiterD * 16309219658285890145U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5166926595573507837U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1918425684273807598U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16616641579714896719U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4724551751012661440U) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1818014487579644390U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14904092108647864911U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 6670090372241084216U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 8485757110007268693U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 11876760095108618363U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4928130251509514742U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2528788422725346792U;
            aOrbiterF = RotL64((aOrbiterF * 1855982047967756661U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 4U)) + aOrbiterB) + aNonceWordB) + aPhaseAWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + aNonceWordG);
            aWandererA = aWandererA + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 39U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + aNonceWordP) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11773U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 12312U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13643U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15138U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16007U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 37U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (aWandererJ + RotL64(aCross, 40U)) + 12775735908960052604U;
            aOrbiterC = ((((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 11791373812080296887U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 5537362877706057303U) + aNonceWordA;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 2023912048504189380U) + aPhaseAOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 23U)) + 17668828109963766893U) + aNonceWordG;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 558908629933941224U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1479633119685446888U;
            aOrbiterI = RotL64((aOrbiterI * 4447153373540811385U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 15460320397843364063U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10059749397555469054U;
            aOrbiterK = RotL64((aOrbiterK * 8671817118586065469U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9987633811929693924U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10087337844580228269U;
            aOrbiterC = RotL64((aOrbiterC * 13817142288940843815U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4446204415503364254U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 15106063243302192717U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 13273756657334709803U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9430197906134676162U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 1226048679997253363U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14247538885252664127U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 37U)) + aOrbiterB) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 47U)) + aOrbiterB) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 56U)) + aOrbiterC) + aNonceWordI) + aPhaseAWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19728U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneA[((aIndex + 18122U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20696U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18757U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17310U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 36U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 9630214189402543339U) + aNonceWordK;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 27U)) + 4072576573737526819U) + aPhaseAOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 15994787452709618869U) + aPhaseAOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 46U)) + RotL64(aCarry, 47U)) + 6403240137132259482U;
            aOrbiterB = (aWandererA + RotL64(aCross, 35U)) + 10229266900170507720U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5025294577989748989U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16696461238217956883U;
            aOrbiterF = RotL64((aOrbiterF * 15993828976234917577U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9878318855341719119U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16086635438116177346U;
            aOrbiterH = RotL64((aOrbiterH * 5585682357395705671U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12295437783084203730U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7681150419912842402U;
            aOrbiterC = RotL64((aOrbiterC * 7289497379725191451U), 41U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 2639104034287637448U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12298170009332243573U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 9397919591171238575U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3485932317267669626U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 16569551670038752475U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8139802826402217631U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 44U) + RotL64(aOrbiterC, 53U)) + aOrbiterF) + aNonceWordC) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 35U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterH, 11U)) + aNonceWordE);
            aWandererA = aWandererA + (((((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 24U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordB) + aPhaseAWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24642U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneB[((aIndex + 22660U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23723U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25983U)) & S_BLOCK1], 26U) ^ RotL64(aInvestLaneA[((aIndex + 24999U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 40U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 15920462086654025436U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((((aWandererK + RotL64(aPrevious, 4U)) + RotL64(aCarry, 53U)) + 487844076858004017U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 14502883786442630566U) + aNonceWordO;
            aOrbiterC = (aWandererF + RotL64(aIngress, 47U)) + 3787107318658233674U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 23U)) + 12548777544693755491U) + aNonceWordK;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 4907309444075181683U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18342396700266492072U;
            aOrbiterK = RotL64((aOrbiterK * 14842961036061482089U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13503051997624242670U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17845742460521374571U;
            aOrbiterE = RotL64((aOrbiterE * 1366356786138085155U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 8640887211877858169U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5273913123709097537U;
            aOrbiterA = RotL64((aOrbiterA * 1661149444148461791U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17756844173695563883U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 6713055830729302951U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 2832836748513174311U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5106468334224035972U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10228769728713526172U;
            aOrbiterC = RotL64((aOrbiterC * 9760310686414358435U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 37U)) + aOrbiterE) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterA) + aNonceWordM);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 22U) + aOrbiterK) + RotL64(aOrbiterC, 14U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterC) + aPhaseAWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 48U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29308U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((aIndex + 27751U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28009U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28107U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 32523U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 36U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 12U)) + 7075016829833562104U) + aNonceWordM;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 3U)) + 8783765886115517036U) + aPhaseAOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 2996723892384565829U) + aNonceWordN;
            aOrbiterB = ((((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 9494134707342189476U) + aPhaseAOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 5052642981395679904U) + aNonceWordJ;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 8766787055127962238U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4467211954388738079U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8599295330343804047U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8030255604633658608U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16962408063455702251U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 11171737929747471631U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3768222186567699076U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14930990410207899871U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10930005786146268241U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14179761938395502502U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1879084742719898108U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16783034788172670121U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5535012408925981515U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12792553516710295939U;
            aOrbiterG = RotL64((aOrbiterG * 8577530993755159329U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + aNonceWordL) + aPhaseAWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 30U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + aNonceWordH) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterE, 41U)) + aOrbiterK) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_VolleyBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE23F3915DA9C2EC5ULL + 0xAE8CF8CA6FC0DBC3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD664A2CA5A0151D5ULL + 0xD3532A96BB9472E7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC3B0AA4F37DFD35FULL + 0xED92A5A0E765B6CCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC22BCE1EC6630977ULL + 0xBBF7223B3D8A4696ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB7B030F426625C03ULL + 0x81D3EA6AFB7636AFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC7CA5667B16DC84FULL + 0xCC18B851F008971EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD16D19EE80F3997FULL + 0xAE250EF861846021ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8A7707449B161D13ULL + 0xD5CD354E5B5163C6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFF0EF277B827CFF5ULL + 0xBB82D0BDFAA14A5DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x86BCF6F1F1E0466BULL + 0x80D3CA3BB35471E4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB98DFD0B5EA4861FULL + 0x81CE1EC11B2EC5E8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xABE035A382DE8401ULL + 0xE18D3FF42F2900D9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDFF82DF88D94F0FBULL + 0x90043FB391C685A3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF9016AD82B2362CFULL + 0xD0B86252C3DBA132ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF3A9EF22CF65DF67ULL + 0xDE341951422920B9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFA787281287C29CDULL + 0xF8A7DF1F657D3FC3ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3743U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 4640U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3528U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 289U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1790U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1404U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((aWandererD + RotL64(aIngress, 3U)) + 9914837590440975587U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aCross, 58U)) + RotL64(aCarry, 27U)) + 6706125076401958051U) + aNonceWordI;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 29U)) + 16570817772679258409U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 19U)) + 6843705658115186948U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 43U)) + 16099930446791572351U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 23U)) + 5420550009556030459U) + aNonceWordK;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 5729549069420177477U;
            aOrbiterJ = ((((aWandererJ + RotL64(aScatter, 12U)) + RotL64(aCarry, 3U)) + 15590601126188675834U) + aPhaseBOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aWandererC + RotL64(aCross, 37U)) + 13044027390998620029U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11068338135659636772U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6584988841809544332U;
            aOrbiterA = RotL64((aOrbiterA * 1683336180438945439U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8516813219883915404U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10647314042912492785U;
            aOrbiterH = RotL64((aOrbiterH * 15559481057047148785U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 201691689889605304U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15512161798401184003U;
            aOrbiterK = RotL64((aOrbiterK * 11473219183982564709U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3883760518944464145U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13861805129175491145U;
            aOrbiterG = RotL64((aOrbiterG * 17194438894492581181U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 12019138626550801486U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13030350224959652248U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11724200983306280107U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2643807255422544248U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4127143302485631794U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5441038881111578487U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14602951930809633069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4555737199162278494U;
            aOrbiterE = RotL64((aOrbiterE * 12415825635220991865U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6343143902997169834U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10404783711336491985U;
            aOrbiterC = RotL64((aOrbiterC * 6235474458879439079U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7406959231434835393U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6684368109277850196U;
            aOrbiterF = RotL64((aOrbiterF * 8760360417572331159U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterI, 3U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterK, 60U));
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 21U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 51U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 30U) + aOrbiterF) + RotL64(aOrbiterH, 14U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 39U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12158U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 11861U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10699U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15326U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13436U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14696U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 15164U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 34U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = ((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 27U)) + 12222235191147985484U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 13U)) + 16367317014523328414U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 47U)) + 3511378091284703789U) + aNonceWordH;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 5U)) + 15247492830966725949U;
            aOrbiterI = ((((aWandererG + RotL64(aScatter, 28U)) + RotL64(aCarry, 13U)) + 7745995913390407897U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 19U)) + 6463593307540108810U) + aNonceWordB;
            aOrbiterK = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 1101669311005268630U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 43U)) + 12988052764067518580U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 35U)) + 17717179747434679772U) + aPhaseBOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11662190906682400416U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6563014073547628748U;
            aOrbiterH = RotL64((aOrbiterH * 16967910471722117761U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13099094932059419219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16342730862261868847U;
            aOrbiterB = RotL64((aOrbiterB * 10988124108686164829U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16855346813127524624U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6570063128502306944U;
            aOrbiterC = RotL64((aOrbiterC * 4571570049463124831U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11328352033809240501U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11640986648833160901U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 2895830492089678919U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2675226158571501666U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17700531248266458165U;
            aOrbiterG = RotL64((aOrbiterG * 2231403813970188657U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 7729597396731910874U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15172374484412053756U;
            aOrbiterE = RotL64((aOrbiterE * 149009041406406517U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9178769489257842683U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9020154972097834926U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8910504667566521429U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1317403761217790562U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 17151528554929201571U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3735945655450625203U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11621882033959669977U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10289504450815075623U;
            aOrbiterK = RotL64((aOrbiterK * 13365982786836243195U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 42U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterE, 11U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 52U)) + aOrbiterA) + aNonceWordJ) + aPhaseBWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 60U) + RotL64(aOrbiterB, 43U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 18U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16908U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 19962U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 21625U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17049U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21196U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20140U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17363U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = ((aWandererG + RotL64(aScatter, 34U)) + RotL64(aCarry, 47U)) + 15383045568644941552U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 13U)) + 17452811657750910067U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 27U)) + 15660117718455155603U) + aPhaseBOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 41U)) + 10396441207743665753U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 3708971058200841442U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 20U)) + 7000673057768598750U) + aNonceWordJ;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 5U)) + 9886354469011131596U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 57U)) + 16018065329058043467U) + aNonceWordM;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 5024756166109352320U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6587818720728886652U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3652672354944162319U;
            aOrbiterD = RotL64((aOrbiterD * 10807121230791716109U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6307315649915348048U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16405347331742979258U;
            aOrbiterB = RotL64((aOrbiterB * 7183142442906743699U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5427299664054601957U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4983381733483185898U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 14646556236306407673U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10182995521328377487U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8694282877540593550U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14614602561910403893U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4085927978153269932U) + aNonceWordK;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6176195962815240877U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16792916528959579875U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6966742100601433005U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9920952446921247521U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1879821050131820933U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11958734477518336014U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2058335903640404380U;
            aOrbiterC = RotL64((aOrbiterC * 6986170159285417789U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 77366119537297816U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12072894199692855000U;
            aOrbiterF = RotL64((aOrbiterF * 9083781120514635987U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11874297832446385377U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13715562531763053196U;
            aOrbiterG = RotL64((aOrbiterG * 12822488258322963187U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterH, 22U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + aNonceWordP);
            aWandererB = aWandererB + ((RotL64(aCross, 12U) + aOrbiterJ) + RotL64(aOrbiterI, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterH, 57U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 46U) + RotL64(aOrbiterE, 27U)) + aOrbiterI) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 36U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31128U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 30245U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 30860U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 25556U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31610U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24679U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25466U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 12426357877879529292U) + aPhaseBOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 48U)) + 12604900366173639176U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 11U)) + 13511119007338929401U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 19U)) + 9878720081166788060U) + aPhaseBOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 41U)) + 15463195409806395076U) + aNonceWordE;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 23U)) + 6407922778852833423U) + aNonceWordF;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 27U)) + 7690427254160734016U) + aNonceWordH;
            aOrbiterK = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 37U)) + 18030974031722143619U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 54U)) + RotL64(aCarry, 29U)) + 17983938038322737041U) + aNonceWordO;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16605512170117753884U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 681802273302348322U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14608920184802647123U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15550312921312083819U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17824154101711884508U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 7358612830654795357U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1939207786756735430U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3132864634777826569U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 13606281919426730325U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12822929773923954849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16576106045887115660U;
            aOrbiterA = RotL64((aOrbiterA * 16370914370769903051U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2398825881649235260U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 13700821892926092479U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10830623703416956043U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2439833784883391606U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15870638514107637833U;
            aOrbiterF = RotL64((aOrbiterF * 3797380922767479287U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9165457123134229670U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8736642509192659417U;
            aOrbiterK = RotL64((aOrbiterK * 16219277537523484065U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9232719746484835693U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7826680628853322541U;
            aOrbiterD = RotL64((aOrbiterD * 12578050118133526187U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14323652326982518782U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2254524512851399313U;
            aOrbiterG = RotL64((aOrbiterG * 4119339547645451149U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 48U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 34U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 20U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + aNonceWordA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 23U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 60U)) + aOrbiterD) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 13U)) + aOrbiterA) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_VolleyBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC4B09C0591DCBB1FULL + 0xA8DAB4193C16C414ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA11FDC40BE7E6605ULL + 0x91FDB42ECEF578A0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDB5E24933F1CC6F3ULL + 0xDAAEBDCDCF2C1555ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCD47FA7F24EF69B9ULL + 0x904943AAB2CF28E4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFC579B417C45D693ULL + 0xDBA120660ADCC486ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF440B0E90A920C89ULL + 0xCAFF968370A8EFC6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x919442EFCF399021ULL + 0xCEEAA68502F3B7A6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE2DFA7852A38D019ULL + 0x98B127BB7CDF31DAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xADB0177833475A4DULL + 0xFD6301464BC61842ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9283EC09856AFB4DULL + 0xFA9EBC9704B5F49AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA7E1CD04361CE783ULL + 0xC1F4CB26C34AE157ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x96CB6B3655F48B17ULL + 0x8B170D2F4E976619ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x82B2F392CCAB0B41ULL + 0x803B0699B2991525ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA554368B314FA21BULL + 0xCCFCDA58356439A4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD98C34D4221E6139ULL + 0x9189D82604D7D3C2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC1C6359D2891D55DULL + 0xD349919C2DF329D4ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4915U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 5362U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 443U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5023U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2163U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1888U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererI + RotL64(aCross, 41U)) + 4848316479321533394U) + aNonceWordH;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 6919360256662636195U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 30U)) + 9897013582181108544U) + aNonceWordN;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 7319353809896158678U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 2848175435514849859U) + aNonceWordC;
            aOrbiterE = ((aWandererH + RotL64(aCross, 3U)) + 6967780718720437934U) + aPhaseDOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 23U)) + 10143884766603388136U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8675965006150972051U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16350117755560994281U;
            aOrbiterC = RotL64((aOrbiterC * 15072308930382994425U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17976597517118423760U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1399631141355370237U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16537788276543236833U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3590613762034716792U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5134624314245932157U;
            aOrbiterB = RotL64((aOrbiterB * 13077589037975283371U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10082236952942943654U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4015535035905433450U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4961808568701908559U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 611474103801573800U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5786708483794098001U;
            aOrbiterF = RotL64((aOrbiterF * 7694007039340089267U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5201943497363274455U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9282160506938328489U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 5368182164239021367U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4932320527498940158U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11576526341731392916U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1712051774729439363U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 35U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererH = aWandererH + (((((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 46U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordF) + aPhaseDWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterB, 27U));
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 19U)) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 36U) + RotL64(aOrbiterB, 13U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5855U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 7108U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9740U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 9038U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10554U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6315U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5854U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aIngress, 47U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 35U)) + 12380376990224645149U;
            aOrbiterI = ((((aWandererC + RotL64(aIngress, 22U)) + RotL64(aCarry, 5U)) + 18296928500297384014U) + aPhaseDOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 3550626816361145100U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 2667792936946706027U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 29U)) + 12020969779370926953U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 43U)) + 737340727886903447U) + aNonceWordK;
            aOrbiterK = (aWandererI + RotL64(aCross, 51U)) + 1681797651799760502U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2956186342689489064U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1876852870402977177U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 8875540081346621757U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6433205819353555071U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9065076854974222998U;
            aOrbiterD = RotL64((aOrbiterD * 5459675878087242021U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3254410578766789992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2005081975473815576U;
            aOrbiterC = RotL64((aOrbiterC * 9947701153722014085U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15992999234834560419U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 3458344156815120948U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 1668460113964608051U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17069783053664877727U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1260234710193913099U;
            aOrbiterK = RotL64((aOrbiterK * 4561226779897414381U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3825186451876061335U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2905344294992827535U;
            aOrbiterH = RotL64((aOrbiterH * 2469896090698580795U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 18141402347899180617U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8760129857609925066U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2507999156108123047U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 14U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterK, 57U)) + aNonceWordP);
            aWandererC = aWandererC + ((((RotL64(aCross, 5U) + RotL64(aOrbiterA, 27U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + aNonceWordL) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterA, 37U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterI, 4U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15099U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 15423U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11873U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12273U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14019U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCross, 21U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererC + RotL64(aCross, 11U)) + 439898681482066326U) + aNonceWordB;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 19U)) + 17362083676671776094U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 3U)) + 6418499837265155024U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 41U)) + 17262244253027454972U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 35U)) + 2382066162993139503U) + aPhaseDOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 14345808395587174135U) + aNonceWordL;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 7534743166385552851U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16994453324688523966U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7079553728544045092U;
            aOrbiterC = RotL64((aOrbiterC * 10104892188895367489U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3562822704508440641U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13990892681975857821U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8352929306654078795U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1796728922368577238U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6605161260520067178U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 8147537646591674091U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13994083795942328918U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6144523182899107711U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4153879991344611283U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12247462325297436642U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1065809332002012789U;
            aOrbiterJ = RotL64((aOrbiterJ * 5496601177032953251U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 10147919864511540753U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17138553441127273354U;
            aOrbiterI = RotL64((aOrbiterI * 5773875596275267871U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2653924016109573974U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6254416952351699582U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12756861659704947257U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 46U) + aOrbiterI) + RotL64(aOrbiterC, 53U)) + aNonceWordA);
            aWandererD = aWandererD + (((((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 35U)) + aNonceWordM) + aPhaseDWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterA, 40U)) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 5U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20800U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 21529U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19689U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21456U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21033U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 24U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 3U)) + 6469584119078165548U) + aNonceWordI;
            aOrbiterB = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 14329756366517987910U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aIngress, 51U)) + 12890831797059772123U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 3164503807500018990U) + aNonceWordH;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 58U)) + RotL64(aCarry, 5U)) + 177531431387646836U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 37U)) + 3167421392893561015U) + aNonceWordJ;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 19U)) + 2813174781844753460U) + aNonceWordA;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10953270419153249857U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16911518309710356951U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13162785997686570445U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6616750447844893150U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10276741398025985982U;
            aOrbiterE = RotL64((aOrbiterE * 6824712685896987133U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6206043608461213208U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12021552904553405793U;
            aOrbiterG = RotL64((aOrbiterG * 10023362889960174909U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15283586234744144846U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5923238786775948571U;
            aOrbiterD = RotL64((aOrbiterD * 8200882393521882651U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11044014510971660078U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9351141024085076044U;
            aOrbiterJ = RotL64((aOrbiterJ * 13316079344614432317U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17703395981862992420U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10154548848376027087U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 12324478347590509035U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8836420852291617425U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10193385413543886344U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 824935982418585449U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 28U)) + aOrbiterB) + aNonceWordD);
            aWandererH = aWandererH + (((((RotL64(aScatter, 4U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordP) + aPhaseDWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 57U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 29U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 41U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25541U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((aIndex + 25137U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 24523U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22766U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24606U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 12U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 11998579547770778580U) + aNonceWordP;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 5U)) + 8409465187298704610U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 19U)) + 3470222286110333500U) + aNonceWordH;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 51U)) + 5704486785203069994U) + aNonceWordM;
            aOrbiterA = (aWandererK + RotL64(aCross, 13U)) + 10334944660253279633U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 7626852700722567477U) + aNonceWordN;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 27U)) + 14631310754943209743U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 807160297237854120U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5624154783624196107U;
            aOrbiterC = RotL64((aOrbiterC * 2404066593958052159U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4971444394698940423U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6340057638461027062U;
            aOrbiterI = RotL64((aOrbiterI * 12027586111086798629U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9003019862787819481U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13632057463595873033U;
            aOrbiterE = RotL64((aOrbiterE * 12575202147280216765U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12766104026871797746U) + aNonceWordE;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 4062118445824915939U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 13130770039048080701U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5258212525426469978U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9956946981015983939U;
            aOrbiterJ = RotL64((aOrbiterJ * 8106382657040497669U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10837606223056473999U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13292864885504191134U;
            aOrbiterA = RotL64((aOrbiterA * 4445739587553669471U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 166087925900318658U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6786842221885441388U;
            aOrbiterF = RotL64((aOrbiterF * 4411147600413147773U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 36U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 43U)) + aOrbiterF) + aNonceWordC);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterI, 51U));
            aWandererF = aWandererF + (((RotL64(aIngress, 38U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + aPhaseDWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29213U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneA[((aIndex + 28035U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31209U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32120U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 31574U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 5U)) + (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = ((aWandererD + RotL64(aCross, 35U)) + 5295352595333316211U) + aPhaseDOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 18U)) + 2341795367042042605U) + aNonceWordL;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 10122175780504033663U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 10084612804696198554U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 29U)) + 16470424309851045971U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 43U)) + 656016130975227994U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 15313268829659834317U) + aNonceWordA;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3795220914993923394U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14044442220988813825U;
            aOrbiterK = RotL64((aOrbiterK * 3270650852546606835U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3804224626734584802U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7980006306010255693U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 13958505239726088561U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13746830564584711549U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11852212099729274845U;
            aOrbiterG = RotL64((aOrbiterG * 2164880979318247855U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9083223471018084847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13706723820703853346U;
            aOrbiterC = RotL64((aOrbiterC * 11361854103656219887U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1713819986642275223U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1382000168233902914U;
            aOrbiterA = RotL64((aOrbiterA * 3894160765130198157U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4540474625764565485U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1756168174375757220U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12739160208010092017U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1409297070183609309U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6082750101445444357U;
            aOrbiterJ = RotL64((aOrbiterJ * 17438740230251860935U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 36U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 51U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 19U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterG, 11U)) + aPhaseDWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 50U) + aOrbiterI) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterH, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_VolleyBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC41DDFF5B7980315ULL + 0xE98C4F3052E7663CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC553C71A6ABCED81ULL + 0x902E8723312250AAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x93EE23AA738A7FC3ULL + 0xD3DCF06F9A860381ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x912965581279C155ULL + 0xA88D99644ECAAE45ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x88F0A0BD0DD5F245ULL + 0xC774B12800C58918ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9E76168AA3A9BA33ULL + 0xFB78D682591DAB13ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBCCC1A43763D0835ULL + 0xB8280748437C4D70ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC33C9939C194C7C3ULL + 0x817E52F92516C6A9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9297C2560FA62E6BULL + 0xB1F0E600C214557FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEC44D6BA5D694445ULL + 0xE246B616F4EFB1B3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x83027A9CFFDE2F4FULL + 0xE1659E11FA3D45C5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEDD0603664A7F4B7ULL + 0x814D05BC3C8FF232ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA9873309C5670285ULL + 0xEA700ACA95FD8B2FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFF2AECCAFA516127ULL + 0xE76EE701DC1CE799ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x89113B2224928DABULL + 0xFFBABA2920B6A843ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC49BF69D0B0FABF5ULL + 0xD3DFF877A9C26061ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 2517U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 5391U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2180U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1977U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3488U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3731U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 39U)) + 4751694786009671052U) + aPhaseEOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aScatter, 43U)) + 16362725160370844224U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 21U)) + 6360885380915941057U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 50U)) + 5154536007972297036U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 35U)) + 9362540581874808253U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 13902493871525612934U) + aNonceWordC;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 47U)) + 10208452885367546542U) + aPhaseEOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aWandererC + RotL64(aCross, 6U)) + RotL64(aCarry, 19U)) + 3117030377279160998U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 17286247690414027870U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 27U)) + 3930314320040949141U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 11U)) + 7289525252391668404U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3434167955466809185U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17852573095128575663U;
            aOrbiterF = RotL64((aOrbiterF * 1485660158767033425U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6137259687928853253U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13992510605237574698U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 15346263295995333395U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6470556523400123474U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 4333255670390099293U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 11089933812030082647U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 7700424876430257995U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16920736951239453071U;
            aOrbiterG = RotL64((aOrbiterG * 8920407493132380497U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 1635071690430295730U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 9966700845966398620U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17210048121896546867U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9833458070123027075U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1990346556486746432U;
            aOrbiterI = RotL64((aOrbiterI * 8704943923474148699U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13339523466436517327U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5018264760406215603U;
            aOrbiterC = RotL64((aOrbiterC * 2769197961801783627U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 123427497520755346U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4535841104215792886U;
            aOrbiterB = RotL64((aOrbiterB * 1417676310539177131U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3525925567359163763U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3273741481392187986U;
            aOrbiterD = RotL64((aOrbiterD * 16116160744647235811U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6230742908784102407U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7578784912496239362U;
            aOrbiterA = RotL64((aOrbiterA * 2614448818452560369U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14669810330213234082U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4751694786009671052U;
            aOrbiterH = RotL64((aOrbiterH * 9583151676882991817U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 4U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 23U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterK, 46U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterF) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 37U)) + aOrbiterH) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 41U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterI, 35U)) + aNonceWordI);
            aWandererA = aWandererA + ((((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterC, 56U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 10U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9034U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 6329U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 6518U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((aIndex + 6598U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 8690U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8183U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7715U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 39U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 15549114274303128055U;
            aOrbiterD = (aWandererD + RotL64(aCross, 43U)) + 16466750056388063241U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 6U)) + 12209449840836787142U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 14551496099734294336U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 39U)) + 6266576428679808622U) + aNonceWordF;
            aOrbiterF = (aWandererI + RotL64(aIngress, 53U)) + 16892841575635668152U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 37U)) + 7375966221423362125U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 35U)) + 11926105302821753530U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 10U)) + 16219253791550461124U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 7299056065319248160U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 57U)) + 15234001484933728439U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6615802589932632120U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5481176858895819247U;
            aOrbiterI = RotL64((aOrbiterI * 3604590158551984877U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17220507586542139380U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14137921473739415340U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 10634645686035907603U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16981960446540932787U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10897565927079518588U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 418843936329303571U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2746889569299593263U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4894117146736361379U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2656750612042673191U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18294823016957137777U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 86828501068883383U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 11432686669235402365U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6322053762209547826U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6754524552483363820U;
            aOrbiterK = RotL64((aOrbiterK * 1746163087826694641U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7306452650619361017U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12717201204443785828U;
            aOrbiterC = RotL64((aOrbiterC * 6121251603905574991U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10422327053543898585U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14786413282036348183U;
            aOrbiterJ = RotL64((aOrbiterJ * 8713024293107068275U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4599182534559908397U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5080179685914177581U;
            aOrbiterA = RotL64((aOrbiterA * 14984675846207762951U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6527649204956325409U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8327234966110052920U;
            aOrbiterB = RotL64((aOrbiterB * 9343969092668123661U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7845497893651522069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15549114274303128055U;
            aOrbiterE = RotL64((aOrbiterE * 15263427406359082909U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterG, 38U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterB, 13U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterE, 21U));
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterF, 46U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 41U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 53U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterE, 5U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterA, 51U)) + aOrbiterK) + aNonceWordP) + aPhaseEWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12484U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneA[((aIndex + 15202U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 12031U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15810U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13255U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 27U)) + (RotL64(aPrevious, 42U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererE + RotL64(aScatter, 21U)) + 6771552164800695068U) + aNonceWordN;
            aOrbiterB = ((aWandererA + RotL64(aCross, 58U)) + 12131763371571322040U) + aPhaseEOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 13U)) + 3326182381395522013U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 11U)) + 12288775097697156383U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 5195948373449796741U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 19U)) + 14404044002250137144U) + aNonceWordF;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 3U)) + 11142382920035825426U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 2967149520256475485U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 53U)) + 1470907369577818097U) + aNonceWordM;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 9231668148004163910U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 6U)) + 13078929163913892386U) + aNonceWordC;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9485274692075657877U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12216951187543631673U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6571066246507310805U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6933334652581744234U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17260276102423580920U;
            aOrbiterG = RotL64((aOrbiterG * 7796879893790990605U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 387767848169714392U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8597538259308082638U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 4888054690557707241U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7996708724489146033U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 15357384191688149939U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 9827691726832491373U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17739222908739454637U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1614322333281471170U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7063116837752240891U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4531604274893197209U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3453280714992341288U;
            aOrbiterF = RotL64((aOrbiterF * 8390029711127907805U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 116623650872661533U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6565636510115095988U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 9691897067492501177U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10303258439817808058U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10917642773040237611U;
            aOrbiterD = RotL64((aOrbiterD * 10232856828372963363U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2087058228468680821U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3691125545393861889U;
            aOrbiterJ = RotL64((aOrbiterJ * 1768745056298937903U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9240209357066002219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7645250700232422804U;
            aOrbiterB = RotL64((aOrbiterB * 6762116797395687607U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9859862257084218280U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6771552164800695068U;
            aOrbiterE = RotL64((aOrbiterE * 11063630807191661109U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 30U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 58U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterG, 39U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 20U) + aOrbiterA) + RotL64(aOrbiterD, 52U)) + aPhaseEWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterC, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterC, 43U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 41U));
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19155U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 21051U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 17948U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19333U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18141U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 3U) + RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 54U)) + 17470880031634374199U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 41U)) + 757565846006937746U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 43U)) + 9419282475801345674U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 2014248014107898196U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 37U)) + 15113928519446490441U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 21U)) + 7346126964886259935U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 51U)) + 5594123113093162359U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 29U)) + 5659237263369402005U) + aNonceWordC;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 11565709683423969703U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 18U)) + 16782863743534856287U) + aPhaseEOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 13499100900072115907U) + aNonceWordJ;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11414447651044205242U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7545993795121430538U;
            aOrbiterA = RotL64((aOrbiterA * 10758488381206257261U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11778229237616454988U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2544793391976514665U;
            aOrbiterF = RotL64((aOrbiterF * 4021060413798523299U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9972156716619459164U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 17651030383827445664U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 6742914240706775487U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17439147296849134543U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10021926927948343656U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 18139540407315440909U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9309867875882669289U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14951424455944346337U;
            aOrbiterB = RotL64((aOrbiterB * 10569523948169951309U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2166343974068770659U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11386993629011562026U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3091639433512536097U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5747849744680120960U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4019290369160113026U;
            aOrbiterK = RotL64((aOrbiterK * 5567515306039646735U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3820540009554769592U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8210747198363020939U;
            aOrbiterG = RotL64((aOrbiterG * 16215133106542452509U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3006494852696036003U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2736305345451919450U;
            aOrbiterD = RotL64((aOrbiterD * 11993452696344358247U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 6148431711118275178U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6986633012691940738U;
            aOrbiterJ = RotL64((aOrbiterJ * 15672039482523804893U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7837859154831245165U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17470880031634374199U;
            aOrbiterC = RotL64((aOrbiterC * 2153299273348512243U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + aNonceWordP);
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterB, 37U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterB, 48U));
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterE, 23U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 48U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ) + aNonceWordE);
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + RotL64(aOrbiterA, 6U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + aNonceWordL);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 41U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22077U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((aIndex + 24499U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 23407U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25461U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 23437U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aIngress, 19U)) + (RotL64(aCarry, 39U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (aWandererI + RotL64(aPrevious, 29U)) + 3561491146322798260U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 7075025056181885339U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 4U)) + 9230910887904171613U) + aNonceWordE;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 21U)) + 4119781172609908917U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 17155609083870983149U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 13U)) + 2423018561430181695U) + aNonceWordB;
            aOrbiterD = (aWandererB + RotL64(aCross, 60U)) + 12957280305617615744U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 23U)) + 2461704174772065813U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 47U)) + 7907123257849391997U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 7257868138318960007U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 35U)) + 16425903703085702285U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2990822664594079467U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5654819006718953817U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 4465096036756887801U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12183676471235678779U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15026286960542123922U;
            aOrbiterG = RotL64((aOrbiterG * 17199049329995315279U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12169080607071830522U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2906296852254787499U;
            aOrbiterC = RotL64((aOrbiterC * 6754514406846040163U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3029858695410344584U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14406410317495954566U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 9663780721657983421U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11048818178401163861U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13622063920319445043U;
            aOrbiterK = RotL64((aOrbiterK * 2516025554421589857U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2642646089141233277U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12761571777929273548U;
            aOrbiterA = RotL64((aOrbiterA * 5518252696078700127U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7753802695131502382U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8510425459525030222U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12412361423636026483U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13522645164493316722U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1437430302489702713U;
            aOrbiterE = RotL64((aOrbiterE * 14019316635365783545U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14745189473423751499U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16968328257002103715U;
            aOrbiterD = RotL64((aOrbiterD * 17915588590593471981U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5001838243344386314U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13506188720092630563U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7010027510838271877U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16902624500530747723U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3561491146322798260U;
            aOrbiterJ = RotL64((aOrbiterJ * 95761172090277669U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 60U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 24U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterE, 19U));
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterC, 41U)) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterF, 10U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aNonceWordM) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 37U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterH, 39U)) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28838U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((aIndex + 29043U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30405U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29287U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30248U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 58U)) + (RotL64(aCarry, 43U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 4739486756133131180U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 13U)) + 16089707555501328184U) + aNonceWordF;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 15310047330238536453U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 51U)) + 7901411596386834955U) + aNonceWordI;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 18U)) + RotL64(aCarry, 41U)) + 4357555491060982163U) + aNonceWordE;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 43U)) + 15667085602825720102U) + aPhaseEOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 3U)) + 8520635334382269253U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 57U)) + 1772509779231068315U) + aPhaseEOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 21U)) + 15336170957886025677U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 38U)) + 8628770833489469980U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 27U)) + 15469234024247246228U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10796430900884288328U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10660110397012853289U;
            aOrbiterJ = RotL64((aOrbiterJ * 9140007610912037461U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11202284258711214794U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17509491802893182994U;
            aOrbiterF = RotL64((aOrbiterF * 9329107599972703671U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16212572740740103554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2190030203761579226U;
            aOrbiterG = RotL64((aOrbiterG * 3101886685668871045U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12014337082293041909U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3733531010807001506U;
            aOrbiterE = RotL64((aOrbiterE * 5797362244066062299U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7100994963061975529U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17837541162838600258U;
            aOrbiterI = RotL64((aOrbiterI * 8745987361678166553U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3311518938023146951U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7709505172646831553U;
            aOrbiterC = RotL64((aOrbiterC * 7121143171245765213U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4979968094554018443U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16822214821463034107U;
            aOrbiterB = RotL64((aOrbiterB * 8618262120451291765U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8376124175020587079U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11084586282092424876U;
            aOrbiterK = RotL64((aOrbiterK * 5835632742522563537U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7816368455027681621U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10893292019060642422U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 3995821210667317677U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13602875505184178486U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5425735673005681983U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 12667085597129312079U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5995385043278810987U) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4739486756133131180U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15709273328685013399U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterI, 13U)) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterD, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterC, 50U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 41U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 54U) + RotL64(aOrbiterC, 21U)) + aOrbiterA) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 23U));
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 37U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 28U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterF, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_VolleyBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD424AD4D2512401BULL + 0xA1A5B69ABDDF5BEDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF3BB47A7E218407FULL + 0x91B4AC0A56871135ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDEE09B945868E34DULL + 0xF5C7C0CB677ABB0AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8CDA19D7874CCA61ULL + 0xB676474EFF1F46D6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD24B27E1CB80FF8BULL + 0x930C185A167D8C45ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x91374C4B4619F105ULL + 0xACB96430AD10B4E8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x81A310D90B00B147ULL + 0x82AA3AB2F7A9A03CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD9F4F6BC35467B21ULL + 0x8EC8874FDC4FBE5FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x99D0EC91DEE8E8BBULL + 0x8C9296119EE9762EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAB71EA060B2F8D11ULL + 0xFECD582605834A0CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC1A847C83D6B79F1ULL + 0xD6DAEB595BE8685DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF0BEBBB0546FF621ULL + 0xB1F453D60BD33686ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFC5E52D13D7E0045ULL + 0xA4FD968300CA9D48ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xED5B37E03A5F55CBULL + 0x952BA65A61A283B3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDFE609DA7D4ADB8DULL + 0xEFF97D630AA4928CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD45416699FCEA29BULL + 0x9680BCC70DE805E5ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3766U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 117U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 279U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3097U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3211U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3480U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 42U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 29U)) + 4980738603982643969U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 40U)) + 17660278413018470020U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 57U)) + 17598114429859543466U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 13U)) + 10993929335279994739U) + aNonceWordC;
            aOrbiterA = (aWandererF + RotL64(aCross, 19U)) + 17967203122976322481U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 1872290205549034384U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 16607778671782810797U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 35U)) + 4895226930754394376U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 4U)) + RotL64(aCarry, 21U)) + 14960359005982301383U) + aNonceWordG;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9921642352377700630U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 893281964367208693U;
            aOrbiterI = RotL64((aOrbiterI * 2345509157333444217U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8232519988397858732U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4433022122758913407U;
            aOrbiterC = RotL64((aOrbiterC * 834240393225479419U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12689609831247168353U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 404535388957472176U;
            aOrbiterH = RotL64((aOrbiterH * 14534020545479806593U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3349108201964013155U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4386449511297371730U;
            aOrbiterE = RotL64((aOrbiterE * 9596273264321140229U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 14314587717949070586U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10923886625271054985U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 7838969002623486809U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17634909585329833520U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 2021301459918350372U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 1388242915918642741U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5219599112498224367U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10641339455385046206U;
            aOrbiterG = RotL64((aOrbiterG * 1022283727595400719U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5003342156562330058U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10951027475628404336U;
            aOrbiterF = RotL64((aOrbiterF * 17836928292555158461U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13040991872592235460U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11149099984302782267U;
            aOrbiterD = RotL64((aOrbiterD * 4248667283139686251U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 50U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 57U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 44U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterI, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + aNonceWordO);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterD, 50U)) + aNonceWordF) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 4U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7579U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 7296U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8663U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8310U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5551U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10666U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 6301U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 20U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 53U)) + 11480359716598965890U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 60U)) + 15431182525482873419U) + aNonceWordL;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 21U)) + 11360504974812776707U) + aNonceWordC;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 47U)) + 9292576416573382769U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 1549257414531028975U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 5347769463033129317U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 3U)) + 17019199177478377234U) + aNonceWordF;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 16558106007323125094U) + aNonceWordM;
            aOrbiterI = (aWandererC + RotL64(aIngress, 36U)) + 3976182233825939422U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2889047161195954395U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2241831345026962605U;
            aOrbiterA = RotL64((aOrbiterA * 5757458560979927857U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12850802412140579294U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13541744735436450160U;
            aOrbiterG = RotL64((aOrbiterG * 906089290000537439U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2085863085516538212U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2969034221711544086U;
            aOrbiterH = RotL64((aOrbiterH * 7768528124408400403U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 6482666944512391472U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16969153556875844613U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 9483462388353216219U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5161314086757363678U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7150282484670673211U;
            aOrbiterI = RotL64((aOrbiterI * 8522427002337918663U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5465304381272305847U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 2344610773390354017U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 17010258514288089191U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8335906578006588582U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13668796013474193793U;
            aOrbiterE = RotL64((aOrbiterE * 8228000547141147777U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9663362594301419686U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3683773739120343413U;
            aOrbiterJ = RotL64((aOrbiterJ * 8319320803406104749U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2538583190438044942U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4454069062219406996U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 16329554225309389599U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterI, 54U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 58U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordG) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 37U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 53U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterE, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterI, 14U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 36U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14069U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 13774U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 10948U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12444U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 14341U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 29U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 14U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererK + RotL64(aPrevious, 35U)) + 2558105147674438050U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 5U)) + 15856662514774702561U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererF + RotL64(aCross, 53U)) + 13346869226246584582U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 11U)) + 7632111846116243973U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 2102101361626976279U) + aNonceWordD;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 47U)) + 5605968705067851563U) + aNonceWordA;
            aOrbiterA = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 6842483186584326681U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 18U)) + 5559797213819425064U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 23U)) + 12422313931331576759U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2751024420047872601U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11031320239359798610U;
            aOrbiterB = RotL64((aOrbiterB * 8607639453141148025U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14366375309473793217U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11971479429768505316U;
            aOrbiterE = RotL64((aOrbiterE * 10063001532313098203U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3947595951884469542U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17882767922372770896U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 3361906348965810211U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 513871456983509223U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5951677013597794294U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8508629569649935293U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 437626309049021931U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 466674061172005705U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 1310502572084891157U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12362602809233133718U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10525852878882195702U;
            aOrbiterG = RotL64((aOrbiterG * 17755022180514914325U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17927000184308583095U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 566723721423470052U;
            aOrbiterA = RotL64((aOrbiterA * 17710534355278632573U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9504585484034413577U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4614306037721859929U;
            aOrbiterK = RotL64((aOrbiterK * 170807293799483539U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1463218357720031588U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4036696102163560633U;
            aOrbiterF = RotL64((aOrbiterF * 15389914226155130065U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 26U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 5U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 6U) + aOrbiterH) + RotL64(aOrbiterB, 57U));
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterC, 52U));
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterK, 23U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + aNonceWordC);
            aWandererH = aWandererH + ((((RotL64(aCross, 30U) + RotL64(aOrbiterC, 28U)) + aOrbiterH) + aNonceWordP) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17212U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((aIndex + 17542U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 21285U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18563U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21208U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aIngress, 60U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 46U)) + 18087125778766689269U) + aNonceWordM;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 13710545066503235196U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 1701939704736254645U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 8064093611384019909U) + aNonceWordO;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 14U)) + 16623332751533885431U) + aNonceWordC;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 57U)) + 15590129153794910109U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 27U)) + 7413312683079107383U) + aPhaseFOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 21U)) + 4186064478651458810U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 35U)) + 5501191643940735954U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11064645242200570835U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 13825922087298055833U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7529317892716108867U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5944980709887369970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8181136916070569646U;
            aOrbiterB = RotL64((aOrbiterB * 395183021205661827U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15442336949157292482U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11580554435240641337U;
            aOrbiterA = RotL64((aOrbiterA * 6654637892858767739U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11240018128174598322U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2027565596050777471U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 18048186560314431815U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16425887196883725233U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16828683527588834095U;
            aOrbiterE = RotL64((aOrbiterE * 17746289103235902485U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9923829146479008804U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6669171007279929454U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 681823450939955099U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3902430046523165149U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6739998149289590041U;
            aOrbiterK = RotL64((aOrbiterK * 2675037435528416821U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16014401255534234075U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14741857638680634564U;
            aOrbiterJ = RotL64((aOrbiterJ * 8723611021403369393U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 5064807861673260054U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 968747317273200299U;
            aOrbiterD = RotL64((aOrbiterD * 14122304002722582329U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterE, 34U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 30U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + aNonceWordH);
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterK, 29U)) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterD, 23U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 18U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26038U)) & S_BLOCK1], 28U) ^ RotL64(aSnowLaneB[((aIndex + 26969U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 27163U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24785U)) & S_BLOCK1], 52U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25336U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 12U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 47U)) + 7632760812370906911U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 53U)) + 6007174525479723089U;
            aOrbiterF = ((((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 3362829642521821048U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererE + RotL64(aCross, 21U)) + 18009548556107978286U) + aNonceWordL;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 34U)) + 17880909432272697327U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 43U)) + 15961567935420752568U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 57U)) + 10136559064656837921U) + aNonceWordB;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 17622019364405410277U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 26U)) + RotL64(aCarry, 37U)) + 6927494824421416306U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 7125170407794874847U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12342273503071032250U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 867417849555857179U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14997696377476124836U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14874498694181230698U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 4026127545746010937U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2549397729130885686U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4217995818662767955U;
            aOrbiterC = RotL64((aOrbiterC * 5525525344485251063U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4706089044415442525U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17983900172670031015U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 541552737180932879U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1904937798143929988U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10620877287033139483U;
            aOrbiterA = RotL64((aOrbiterA * 16711012562024287213U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15681091173163181525U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2655543246639000084U;
            aOrbiterH = RotL64((aOrbiterH * 16686375598149755947U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2647895110857289213U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5581609212017175954U;
            aOrbiterG = RotL64((aOrbiterG * 15330263616699031311U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13609076329627787987U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6244266279516622070U;
            aOrbiterJ = RotL64((aOrbiterJ * 12488345779236971095U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5289624364508923581U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16351476803965903112U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9012522724650442597U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 40U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterF, 46U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 11U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterC, 42U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterC) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27707U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 30884U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 31787U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28018U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27360U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererG + RotL64(aCross, 26U)) + 16519040829220310189U) + aNonceWordP;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 35U)) + 6888002778416941825U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 1310832187746534025U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aIngress, 43U)) + 5890888009051281674U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 20U)) + 5143864838362464857U) + aNonceWordK;
            aOrbiterA = (aWandererK + RotL64(aCross, 53U)) + 15591534069452660003U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 3U)) + 1466867671765325096U) + aNonceWordI;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 13931443680107902488U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 15400747367673245552U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2836975369734495759U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2370720358274970117U;
            aOrbiterC = RotL64((aOrbiterC * 4615571902817575375U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3470677184188006133U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7175584278499266723U;
            aOrbiterH = RotL64((aOrbiterH * 10067096593682482345U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6095078817776863055U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2176637999243513070U;
            aOrbiterK = RotL64((aOrbiterK * 12215701810843975501U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5580391239754903129U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15196125567953871184U;
            aOrbiterE = RotL64((aOrbiterE * 12686361960729564519U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12787014151503209931U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1523153207064063495U;
            aOrbiterG = RotL64((aOrbiterG * 3113907543551927561U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12973289026485937829U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9087439766232078173U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5817029335999350327U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16318022893068674015U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11089160685103562409U;
            aOrbiterJ = RotL64((aOrbiterJ * 17087834321385147603U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8680037953925067235U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3112588943274158119U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9214011370307670371U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16749015684369649821U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 9419550535891334966U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 5421312787569114811U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 12U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 29U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 23U)) + aOrbiterI) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterK, 52U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterK, 37U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + aNonceWordG) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 12U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aIngress, 28U) + aOrbiterG) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_VolleyBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9A029F13010C9723ULL + 0xA7F9D6468ECE0EE6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCF85E70AE12A6379ULL + 0xAA0349A1C3FEA153ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE3597E870C2DDED7ULL + 0x8E010CA987F19278ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8E4AE3DB764F9AE1ULL + 0x9F592400A8794556ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD5E34431F4C52DD5ULL + 0xAF26ECC80C09AB42ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA003C8C4861372EBULL + 0xD4A94B99C0377E4BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9391C03210F3E21BULL + 0xD9963AB82D7C37BCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF559A1F76ED0548DULL + 0xF0A1FB89AFE0A826ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB86FA07DC15226B5ULL + 0x9111E13201165F0AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDFF5282FED13E2F9ULL + 0xF120AF842FFA0E89ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFFE5388C406D994BULL + 0xD430C3F1F7CAE02BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA4E04119ADB4DDF1ULL + 0xE9AE97243284CCD0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xED73D89581BDA407ULL + 0xCB96AE1CCC0DAB7CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC296594EAF02860DULL + 0xFFF6CA72C9F6BDBEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAF61AE69A223A1DDULL + 0xFE8310A1E4A8B044ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA3C0476E1368AC11ULL + 0x888025F9BA77F2C4ULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3054U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((aIndex + 4014U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1595U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1766U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 2067U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2244U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 9041099828460168106U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 3U)) + 12883711604096848454U) + aPhaseHOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 17420968786226443079U) + aNonceWordH;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 43U)) + 3448213891716125104U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 27U)) + 11866455977445336560U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 58U)) + 4119356835384495905U) + aNonceWordN;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 21U)) + 2186212599698637068U) + aNonceWordJ;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 6506144898969301620U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12556800923644051626U;
            aOrbiterB = RotL64((aOrbiterB * 15961043406612913121U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4075551535185182945U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 17877694808492008749U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 901315308379887473U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5553428900598223316U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 14362304852277160675U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 11415103199856419303U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9174200302876075831U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16110739511917638547U;
            aOrbiterF = RotL64((aOrbiterF * 7004356839428657949U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10189881974519849402U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2128076632642616677U;
            aOrbiterJ = RotL64((aOrbiterJ * 8860453653433114929U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 18133523799074400083U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9916472958834153766U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3454601168808001733U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10274457562795569227U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14134814273275356425U;
            aOrbiterI = RotL64((aOrbiterI * 15912501063665343159U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 41U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + aNonceWordD) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 21U)) + aOrbiterF) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterG, 28U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 20U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8420U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneC[((aIndex + 10564U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 6547U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneC[((aIndex + 5817U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6896U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7070U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7294U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 52U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererD + RotL64(aScatter, 56U)) + 785861751704720606U) + aNonceWordD;
            aOrbiterC = ((aWandererK + RotL64(aCross, 47U)) + 15968088718435606299U) + aPhaseHOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 1393976526590347151U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 17240750947292745884U;
            aOrbiterB = (aWandererB + RotL64(aCross, 27U)) + 4921576136163183137U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 19U)) + 3334047873553153032U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 15086509978458408698U) + aNonceWordI;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 892391205397581998U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2965686403183767521U;
            aOrbiterA = RotL64((aOrbiterA * 709160942482770225U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14632215393655706170U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15740589515342377322U;
            aOrbiterB = RotL64((aOrbiterB * 15677716942904794913U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 11131164813943086445U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6988080581278900960U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 6412189142344044255U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16021254613117657178U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6183615599897921154U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9976411093264211033U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12533992547026652747U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3104325358982904219U;
            aOrbiterI = RotL64((aOrbiterI * 14977348108778147265U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3878525937957474644U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 2120435259884368445U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 15964718652193073177U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14928658302694194856U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9121310461310309348U;
            aOrbiterE = RotL64((aOrbiterE * 17304439784647477491U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 28U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 27U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + aNonceWordC) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aIngress, 6U) + aOrbiterI) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 48U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12901U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 12371U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15504U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11783U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneC[((aIndex + 16007U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 4752759164691497960U) + aPhaseHOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 12088872623537639782U) + aNonceWordB;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 47U)) + 3734943577379734227U) + aNonceWordC;
            aOrbiterG = (aWandererD + RotL64(aScatter, 60U)) + 8854778183012444234U;
            aOrbiterF = (aWandererE + RotL64(aCross, 39U)) + 16948373492893967275U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 19U)) + 7962415690046184385U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 1872682375669714454U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7776801806943853566U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16665439117257230732U;
            aOrbiterD = RotL64((aOrbiterD * 6866375628213114965U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11088186766134265676U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10850237991780969350U;
            aOrbiterI = RotL64((aOrbiterI * 7547414856143095121U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6464817712131305812U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 244557182884209844U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 2394270354887582889U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13261563971157415841U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 2323811103717827362U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11483723582415081925U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12338803568475493422U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2811342930111104982U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5020981755203607757U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5554497011738996057U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12712169745460598698U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1985586486150377769U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17415058661427002973U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9430421222715343818U;
            aOrbiterE = RotL64((aOrbiterE * 10321140659099470811U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + aNonceWordP) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterA, 20U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterK, 43U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterK, 13U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 22U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16767U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 19343U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17937U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19717U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneD[((aIndex + 19881U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 14U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 12849591986267890852U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aWandererB + RotL64(aCross, 11U)) + 8232614804696815750U) + aPhaseHOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 57U)) + 12141567259210877281U) + aNonceWordA;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 2928641981037885644U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 4U)) + RotL64(aCarry, 23U)) + 980733350554783938U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 47U)) + 2683985177993350746U) + aNonceWordG;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 19U)) + 14532148403815527355U) + aNonceWordP;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 7736296629433884203U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 10428437770166310549U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 326634742742373401U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18327174144859461029U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6810436935194432002U;
            aOrbiterI = RotL64((aOrbiterI * 2715987179577753597U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12606153309690753435U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17123256945895150555U;
            aOrbiterC = RotL64((aOrbiterC * 13469111258504672565U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9057777759026189541U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16478485918911194442U;
            aOrbiterG = RotL64((aOrbiterG * 11054247078884894131U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 18064460487552100483U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11477276762421684083U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3886501230380184395U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 18318375441973295081U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13849305985380030986U;
            aOrbiterA = RotL64((aOrbiterA * 12962140243967824959U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10240409420338313641U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18360586077779529086U;
            aOrbiterJ = RotL64((aOrbiterJ * 18196875422391501927U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 36U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterE, 41U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterE, 13U)) + aNonceWordD);
            aWandererE = aWandererE + (((((RotL64(aCross, 51U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordN) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 60U)) + aOrbiterA) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterK, 21U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23982U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 24701U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24827U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22118U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26217U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 20U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 5697928251815176134U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 54U)) + 337587740689259575U) + aNonceWordH;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 11U)) + 4927686903263973950U) + aPhaseHOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 3742409032569801033U) + aNonceWordI;
            aOrbiterF = ((aWandererK + RotL64(aCross, 37U)) + 1608092659172197650U) + aPhaseHOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 43U)) + 15848744267145717509U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 15300174177963339253U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 14162868453323648628U) + aNonceWordJ;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12020167069983729869U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2071080217680099017U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16259538291658723956U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8516686212464112245U;
            aOrbiterF = RotL64((aOrbiterF * 4731296903548893627U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3722184575520553132U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5663609293306386784U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14364218128780764749U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15265344442454471986U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3050323350098829515U;
            aOrbiterD = RotL64((aOrbiterD * 5890624677162388135U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1093356813820599238U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15167726103772238440U;
            aOrbiterK = RotL64((aOrbiterK * 5719466863561311069U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15170797965325981472U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17826286701992981628U;
            aOrbiterC = RotL64((aOrbiterC * 11186808881726573677U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14710892030473425181U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 397194787697553904U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14368930300818752833U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + aNonceWordC) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterD, 6U)) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + aNonceWordP) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32730U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 29237U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 28227U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29825U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 28035U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 38U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 53U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = ((((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 15652862298542575895U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((aWandererA + RotL64(aCross, 54U)) + RotL64(aCarry, 19U)) + 16925323928418184554U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 4413861484961668394U) + aNonceWordI;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 27U)) + 2215946422098155969U) + aPhaseHOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (aWandererG + RotL64(aCross, 41U)) + 14975185533513111110U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 5U)) + 9711613814905834552U) + aNonceWordP;
            aOrbiterH = (aWandererF + RotL64(aScatter, 35U)) + 13154957291850149471U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5058313016418534840U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15011423472941211620U;
            aOrbiterA = RotL64((aOrbiterA * 6125316151731105673U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2030053257469580168U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 150530795186791193U;
            aOrbiterF = RotL64((aOrbiterF * 11106050063717096073U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10878237472104183427U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11724672539469573109U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 16158741837357985395U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9589700906445846956U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1367381624958248949U;
            aOrbiterC = RotL64((aOrbiterC * 8459515089081211977U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12003215666757518106U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11232479330848006729U;
            aOrbiterD = RotL64((aOrbiterD * 10993290955464593033U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 13013910456628561621U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6092509838924105265U;
            aOrbiterK = RotL64((aOrbiterK * 805601154718006061U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 11999225836250312801U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14421271973875748413U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9529010940887430157U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 28U)) + aOrbiterH);
            aWandererA = aWandererA + (((((RotL64(aCross, 20U) + RotL64(aOrbiterG, 41U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aNonceWordH) + aPhaseHWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + aNonceWordA) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 52U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_VolleyBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 537U)) & W_KEY1], 60U) ^ RotL64(aKeyRowReadB[((aIndex + 137U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 263U)) & W_KEY1], 38U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1254U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 43U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 18U)) + 1210605127156905516U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 35U)) + 11964595428173569519U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 57U)) + 16277319029916258482U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 12369497463101824572U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 24U)) + 6201248574067068202U;
            aOrbiterC = (aWandererG + RotL64(aCross, 51U)) + 1727477025667206661U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 47U)) + 1404510627789806851U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 6948213591282018925U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 6688865181284421478U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3351130769402360855U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12681032488906270823U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3680893896579741263U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3591412591193726763U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16153817571210878589U;
            aOrbiterI = RotL64((aOrbiterI * 4165137036092246349U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3808228354421006630U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1427373776207504205U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4534374093769595531U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1831554180932501132U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1114853085120949215U;
            aOrbiterE = RotL64((aOrbiterE * 4264176108298812905U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2080935638828366835U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16104777999646489828U;
            aOrbiterF = RotL64((aOrbiterF * 15205199362011777473U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9782806013673440791U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3721620299829386454U;
            aOrbiterA = RotL64((aOrbiterA * 6286765834910272409U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4013706412064296527U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5751022780695158579U;
            aOrbiterJ = RotL64((aOrbiterJ * 13766736471646116397U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17684546333240329338U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1106947111128020920U;
            aOrbiterC = RotL64((aOrbiterC * 3158839453318658951U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11564229705849500598U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1585817314460274286U;
            aOrbiterB = RotL64((aOrbiterB * 12687162159791577431U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 38U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 52U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterE, 39U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 4U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 43U)) + aOrbiterG) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererH, 14U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 5067U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[((aIndex + 5422U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4371U)) & W_KEY1], 46U) ^ RotL64(mSource[((aIndex + 4326U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 3U)) ^ (RotL64(aCross, 54U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererK + RotL64(aScatter, 3U)) + 8506388683755208267U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 39U)) + 2179323259055019735U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 13U)) + 3345902531140983016U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 17456139311481306584U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 14587864088462311164U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 47U)) + 13178947246650647057U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 12866578138946916962U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 56U)) + 13098524333655118173U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 43U)) + 15451329483787541982U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9494299579678389385U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15581954810375490643U;
            aOrbiterF = RotL64((aOrbiterF * 13670002280188424825U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4487042505730624892U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2774455928791636186U;
            aOrbiterB = RotL64((aOrbiterB * 15847933919136777451U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12435319582397755819U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10077180055177766823U;
            aOrbiterD = RotL64((aOrbiterD * 3924363471701748703U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10391963896910956455U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6149237416725301794U;
            aOrbiterK = RotL64((aOrbiterK * 10115917698918612823U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15673402771629639978U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14729117178956592426U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9070464269215820531U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14492001279368870240U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6278248084483259952U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16731228350971263873U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15727518866499740411U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8652631010810965473U;
            aOrbiterH = RotL64((aOrbiterH * 9508484121620912715U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13660890300188313775U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14699253534935936300U;
            aOrbiterI = RotL64((aOrbiterI * 3978135617259934869U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1621689916308271346U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5651399428852950385U;
            aOrbiterJ = RotL64((aOrbiterJ * 12220143634120124133U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 14U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterB, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 34U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 47U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 10U) + aOrbiterD) + RotL64(aOrbiterI, 10U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 24U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7302U)) & S_BLOCK1], 46U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7450U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6733U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5614U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6773U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererB + RotL64(aScatter, 23U)) + 3255291173184001106U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 13U)) + 15308468160116255528U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 58U)) + 18186972408589866656U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 39U)) + 4439324265978331914U) + aPhaseAOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 13099263173016322486U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 5U)) + 7041561081767500660U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 6196422612687812971U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 34U)) + RotL64(aCarry, 23U)) + 7664260932541281413U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 29U)) + 17802347823020441056U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4253107484061190446U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13799496534030645312U;
            aOrbiterG = RotL64((aOrbiterG * 9167675060053848207U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14252892847595951926U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5663527578664291422U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18314294235895182465U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11148755959699137661U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17036900929333594592U;
            aOrbiterC = RotL64((aOrbiterC * 16041243617369003291U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2403828181385259549U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17813580350434928194U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13666780980793857831U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5623611126885414523U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7293224381174846969U;
            aOrbiterA = RotL64((aOrbiterA * 7032561584670788117U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10602620906929686163U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 18015916257203385982U;
            aOrbiterJ = RotL64((aOrbiterJ * 10684090189688871993U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13592915735376305773U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13995866908043417505U;
            aOrbiterD = RotL64((aOrbiterD * 3802175869395887331U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8200465989447697618U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9866671660800629464U;
            aOrbiterH = RotL64((aOrbiterH * 2138851839905326265U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11557528777230608777U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 131060617338185060U;
            aOrbiterE = RotL64((aOrbiterE * 11068705423012265209U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 22U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 18U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 42U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + aPhaseAWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9143U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 9664U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 9698U)) & S_BLOCK1], 34U) ^ RotL64(aFireLaneA[((aIndex + 10270U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10517U)) & W_KEY1], 40U) ^ RotL64(aFireLaneB[((aIndex + 10079U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 27U)) ^ (RotL64(aCross, 42U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 52U)) + 9080426856729228705U) + aPhaseBOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 19U)) + 7851218321653539276U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 47U)) + 7023344692919298036U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 9772846154227440734U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 28U)) + 12008298632429608431U) + aPhaseBOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 12201090455849562875U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 5U)) + 9498721803411445471U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 351203764023093632U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 35U)) + 4966360430644539250U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9194167899071345693U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4922477697284269116U;
            aOrbiterD = RotL64((aOrbiterD * 8444814161720407881U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15742625291642356429U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7528703106518431730U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11530049278751507567U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15279053574704935317U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2425839793660355555U;
            aOrbiterG = RotL64((aOrbiterG * 11486964816849830667U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13209849392400008898U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9041500097716231309U;
            aOrbiterA = RotL64((aOrbiterA * 340661035700748739U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7885423750878814599U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1992993999902904603U;
            aOrbiterE = RotL64((aOrbiterE * 1478629826632201617U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6120758615019314102U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8529621625846992066U;
            aOrbiterI = RotL64((aOrbiterI * 8485991471612862467U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9125182130757385320U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15691232622970220043U;
            aOrbiterF = RotL64((aOrbiterF * 16517916951054758147U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11413090085435424697U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11563151001080914939U;
            aOrbiterH = RotL64((aOrbiterH * 16828196274450408201U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1778975369262558069U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3232132443557192010U;
            aOrbiterC = RotL64((aOrbiterC * 17132823737792200981U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 39U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterA, 22U)) + aPhaseBWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 47U)) + aOrbiterH) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterH, 57U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterD, 10U));
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 30U) + aOrbiterF) + RotL64(aOrbiterI, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11813U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 11080U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12493U)) & W_KEY1], 47U) ^ RotL64(mSource[((aIndex + 11194U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11324U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12133U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12965U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 30U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 37U)) + 9107326720193244489U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 47U)) + 10868585484401664145U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 23U)) + 13637736741437846622U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 27U)) + 6130725216183918844U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 2063834478521338187U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 19U)) + 8564870627911949158U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 6524015751064086390U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 53U)) + 9874937766875388236U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 14U)) + 14723718409522680894U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13767059954741528279U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6387608251033722169U;
            aOrbiterG = RotL64((aOrbiterG * 6601902195707980693U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5391425980008431000U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11524218415655093779U;
            aOrbiterB = RotL64((aOrbiterB * 12508457981779189389U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 155510463350385905U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10554591788433641311U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5412084824127934293U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8662160162966241542U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5092555636369853727U;
            aOrbiterI = RotL64((aOrbiterI * 433807340167635499U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7163345798448796101U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 695089002178413267U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17302689458565434475U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5409173939213468972U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15349690077393827541U;
            aOrbiterH = RotL64((aOrbiterH * 10984681254001609841U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12376011890751302027U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7809614158898158383U;
            aOrbiterD = RotL64((aOrbiterD * 13845113198736843629U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 13031938699536449576U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3983178190194056516U;
            aOrbiterA = RotL64((aOrbiterA * 1341678482929213405U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5567935037909671790U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17137042627663349797U;
            aOrbiterK = RotL64((aOrbiterK * 13535586899620672373U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 48U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 4U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 56U) + aOrbiterI) + RotL64(aOrbiterK, 23U));
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterH, 13U)) + aPhaseBWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterG, 58U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterF, 53U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 15257U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 15479U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14695U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14800U)) & W_KEY1], 35U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13859U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15558U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 14058U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 23U)) + 17470880031634374199U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 43U)) + 757565846006937746U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 9419282475801345674U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 3U)) + 2014248014107898196U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 28U)) + 15113928519446490441U) + aPhaseBOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 7346126964886259935U;
            aOrbiterA = (aWandererH + RotL64(aCross, 35U)) + 5594123113093162359U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 5659237263369402005U;
            aOrbiterD = (aWandererD + RotL64(aCross, 58U)) + 11565709683423969703U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16782863743534856287U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13499100900072115907U;
            aOrbiterF = RotL64((aOrbiterF * 5567729598873214433U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 11414447651044205242U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7545993795121430538U;
            aOrbiterK = RotL64((aOrbiterK * 10758488381206257261U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11778229237616454988U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2544793391976514665U;
            aOrbiterA = RotL64((aOrbiterA * 4021060413798523299U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9972156716619459164U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17651030383827445664U;
            aOrbiterJ = RotL64((aOrbiterJ * 6742914240706775487U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17439147296849134543U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10021926927948343656U;
            aOrbiterB = RotL64((aOrbiterB * 18139540407315440909U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9309867875882669289U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 14951424455944346337U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10569523948169951309U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2166343974068770659U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11386993629011562026U;
            aOrbiterD = RotL64((aOrbiterD * 3091639433512536097U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5747849744680120960U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4019290369160113026U;
            aOrbiterI = RotL64((aOrbiterI * 5567515306039646735U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3820540009554769592U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8210747198363020939U;
            aOrbiterC = RotL64((aOrbiterC * 16215133106542452509U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + aPhaseBWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 57U)) + aOrbiterF) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 30U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 43U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 22U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16817U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 16507U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(mSource[((aIndex + 17342U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((aIndex + 17813U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17880U)) & W_KEY1], 24U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17618U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 17511U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 54U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 3550722402315312207U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 30U)) + 16724184551669522754U) + aPhaseCOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 19U)) + 981751330116773021U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 7891159229704944868U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 13618396711464799841U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 47U)) + 5969291018449003648U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 51U)) + 14595540413313640042U) + aPhaseCOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 6U)) + 3287990436916111762U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 41U)) + 12534369400200483704U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2277312067930392274U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10026320559261334353U;
            aOrbiterB = RotL64((aOrbiterB * 11020464940995912637U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11258082063135659551U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 1445958517675746990U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10062265337488757971U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1011298251290970844U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6487834862470043744U;
            aOrbiterJ = RotL64((aOrbiterJ * 15477913837027179675U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9966279022928268335U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10285993486057704393U;
            aOrbiterH = RotL64((aOrbiterH * 15965714363201157535U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16005362468813966136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 223843444699390781U;
            aOrbiterE = RotL64((aOrbiterE * 665392038954573081U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 18178876294968532775U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12490136112181806806U;
            aOrbiterC = RotL64((aOrbiterC * 16380841616662993709U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8775696166557913635U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16464340319444310842U;
            aOrbiterF = RotL64((aOrbiterF * 18111632334728200721U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6296039992673546227U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7152939277656436037U;
            aOrbiterI = RotL64((aOrbiterI * 15183918431501487319U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14066791413416223271U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5026743227399908016U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5891343232759075675U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 50U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterI, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 34U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + aPhaseCWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aIngress, 28U) + aOrbiterF) + RotL64(aOrbiterA, 4U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 30U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19837U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 19991U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 20641U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneA[((aIndex + 20831U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21419U)) & W_KEY1], 14U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20882U)) & W_KEY1], 27U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21586U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((aIndex + 19442U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 24U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 51U)) + 6318740973868639425U) + aPhaseCOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 56U)) + 5487840061430920881U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 35U)) + 10258706763248072672U;
            aOrbiterD = (aWandererA + RotL64(aCross, 19U)) + 18356875269730338208U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 12883160282903147010U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 11U)) + 1010140474942697730U;
            aOrbiterH = (aWandererE + RotL64(aCross, 11U)) + 17733939421700898293U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 13693055887924981201U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 5U)) + 14574732452793385269U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10832873941223609012U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8212600587135328040U;
            aOrbiterF = RotL64((aOrbiterF * 5334613996794796145U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5312744319781971178U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6173741211706546923U;
            aOrbiterA = RotL64((aOrbiterA * 12854414066390848249U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3693249147883790810U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 18365859989736602556U;
            aOrbiterD = RotL64((aOrbiterD * 3348463719324104997U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10645056678337549771U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1175668356822251045U;
            aOrbiterI = RotL64((aOrbiterI * 6579675292775345579U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13556844570541823717U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4790355739411849736U;
            aOrbiterB = RotL64((aOrbiterB * 4083544011788850307U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14905575502272644116U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17047244574558476634U;
            aOrbiterC = RotL64((aOrbiterC * 2356386971503880047U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10161614295718414869U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13413914082651612468U;
            aOrbiterK = RotL64((aOrbiterK * 16224039093981079491U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6072693130156927774U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4333656233793103787U;
            aOrbiterH = RotL64((aOrbiterH * 9374745547133955709U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17209776289202130250U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11752001118070361543U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4416523594812872339U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 18U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterC, 13U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 36U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 41U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterH) + aPhaseCWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 4U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterD, 18U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22923U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 24279U)) & W_KEY1], 36U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22692U)) & W_KEY1], 23U) ^ RotL64(aWorkLaneC[((aIndex + 23054U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22464U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21964U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22861U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 23215U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 12122689833405846292U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 27U)) + 9640400270962766788U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 43U)) + 9141937998266739071U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 12U)) + 12899395770434090537U;
            aOrbiterF = (aWandererE + RotL64(aCross, 53U)) + 13457918115408031842U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 47U)) + 15134784483576000943U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 5U)) + 12540961268790055438U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 18U)) + RotL64(aCarry, 27U)) + 6306886773092764230U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 13573343491337243121U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8545588657348974413U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10891410570357275120U;
            aOrbiterE = RotL64((aOrbiterE * 5399310978367842841U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2877137119767060151U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9178097682386595144U;
            aOrbiterC = RotL64((aOrbiterC * 3524486002084427513U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15528007881855616978U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11368419529245281435U;
            aOrbiterD = RotL64((aOrbiterD * 12433207037378339309U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5932738914934356645U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5551842263864055419U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16093776759971522681U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3824433359595690603U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17184628855571662441U;
            aOrbiterB = RotL64((aOrbiterB * 691208053136187317U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8724462245014132623U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7481349499528092352U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8212182934509617583U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6908362960248294718U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5354057969992655314U;
            aOrbiterI = RotL64((aOrbiterI * 16586084885820679343U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11138301629323903147U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14164180536320940750U;
            aOrbiterA = RotL64((aOrbiterA * 9099767681053390287U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 709942920176922902U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17128241237359414945U;
            aOrbiterK = RotL64((aOrbiterK * 14063385518459963529U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 10U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterB, 43U));
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 18U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterC, 51U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterB, 39U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterC, 60U));
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25243U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[((aIndex + 26867U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25057U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 25870U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26749U)) & W_KEY1], 4U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25249U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26035U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 26309U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 12U) ^ RotL64(aCross, 41U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererG + RotL64(aScatter, 54U)) + RotL64(aCarry, 11U)) + 2177539223979303669U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 41U)) + 3962004686551521471U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 8457602312617147662U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 18011802451816510632U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 5U)) + 9046101759168876832U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 29U)) + 11135620637431969597U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 37U)) + 15913029940697999701U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 11U)) + 16304193109948135982U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 48U)) + 13208892298820080981U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4182377898949419225U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13970137023071326151U;
            aOrbiterH = RotL64((aOrbiterH * 9075061559681739865U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8402396284835248583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8859190834060657829U;
            aOrbiterD = RotL64((aOrbiterD * 13552418608113716117U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9760005337757990392U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14108277760135744897U;
            aOrbiterE = RotL64((aOrbiterE * 4474681104256093885U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12226316121949012350U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3456392186754113960U;
            aOrbiterJ = RotL64((aOrbiterJ * 8704729827929941215U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5004087958637038973U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7176881295123125567U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15272157962928021009U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10889800478505074438U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13728832441482547824U;
            aOrbiterA = RotL64((aOrbiterA * 17588477761978646139U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 17345665880706866772U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 301139993853297566U;
            aOrbiterF = RotL64((aOrbiterF * 5812445396758354505U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2061389844760610160U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13631862266139238355U;
            aOrbiterC = RotL64((aOrbiterC * 143613352104722701U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10767186080827509622U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4893486019456886013U;
            aOrbiterB = RotL64((aOrbiterB * 5194746459545610901U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 46U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 4U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 19U));
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 27U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + aPhaseDWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 14U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27644U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 27743U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27851U)) & W_KEY1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 29034U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29886U)) & W_KEY1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29295U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29372U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29879U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 36U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 28U)) + RotL64(aCarry, 35U)) + 9133751643283278896U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 8971581804375380408U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aIngress, 37U)) + 12559650383714566592U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 43U)) + 15753206088872859163U;
            aOrbiterD = (aWandererE + RotL64(aCross, 51U)) + 7640756270450762350U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 19U)) + 7340073357551376125U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 11U)) + 5270256573644196046U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 60U)) + 3567367996479995928U) + aPhaseDOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 11939634537492733738U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7051817732424527120U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1730487669951837941U;
            aOrbiterC = RotL64((aOrbiterC * 15191634337956285841U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 18009252467909454817U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2361024272031696442U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15215151562500226027U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15902755877642960397U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12243517544704116184U;
            aOrbiterI = RotL64((aOrbiterI * 2576071074148141447U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16846181962302186187U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 636121425116506681U;
            aOrbiterF = RotL64((aOrbiterF * 17075030673338779993U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6887385655828217318U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3705834550934775862U;
            aOrbiterE = RotL64((aOrbiterE * 11275428284929594435U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11165142437077969438U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6426659930331618269U;
            aOrbiterG = RotL64((aOrbiterG * 17170640810530893705U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12629082390899315789U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4277510580069574724U;
            aOrbiterB = RotL64((aOrbiterB * 9829125163412708305U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13814834144170469978U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3698381854100295826U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5126359230872258015U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11623170635983579937U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7247413650388803796U;
            aOrbiterH = RotL64((aOrbiterH * 3403219499465560059U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 18U) + aOrbiterB) + RotL64(aOrbiterD, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 39U)) + aOrbiterK) + aPhaseDWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 54U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 6U) + RotL64(aOrbiterI, 35U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterE, 29U));
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterK, 4U));
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30219U)) & S_BLOCK1], 46U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31346U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30303U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31343U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31755U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 31385U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 47U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererD + RotL64(aScatter, 19U)) + 479672811032092393U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 12U)) + RotL64(aCarry, 37U)) + 18061121631394564425U) + aPhaseDOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 14237400452740566065U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 6723123812257706134U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 35U)) + 4247997188026499248U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 40U)) + 1939107415066134869U) + aPhaseDOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 23U)) + 3912640123546395979U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 47U)) + 8295478436553964298U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 27U)) + 3218960600711526885U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5874096203353388890U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10294536533673023358U;
            aOrbiterD = RotL64((aOrbiterD * 15561710414949058923U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11268561953904130747U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16693201256788898423U;
            aOrbiterH = RotL64((aOrbiterH * 16291987237693567209U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7550969634681894654U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 9501647424602245869U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11265865222096866605U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8881869255994319423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16770136406906800016U;
            aOrbiterE = RotL64((aOrbiterE * 1782039587385512923U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16185384746435761363U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13841034186650721627U;
            aOrbiterI = RotL64((aOrbiterI * 12000155593277035447U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15229062695864608309U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3576122704615303733U;
            aOrbiterB = RotL64((aOrbiterB * 2433987493885779279U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13898167174453181224U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 12878032061609524049U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18104665741338251495U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12719156051299028649U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8640980843376950769U;
            aOrbiterJ = RotL64((aOrbiterJ * 10242616778390983333U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12133332160916004365U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8743563985229104484U;
            aOrbiterF = RotL64((aOrbiterF * 4575129690615054691U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 40U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 38U) + RotL64(aOrbiterH, 37U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterD, 48U));
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterF, 57U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterI, 43U));
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 53U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 14U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_VolleyBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5438U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 4187U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7156U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 491U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4616U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8094U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 5U)) + 6163290588946759209U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 41U)) + 7342672468560105447U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 29U)) + 11574563167017282321U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 2254820206194758964U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 50U)) + RotL64(aCarry, 37U)) + 1469783447473099498U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 14174828900676165088U) + aPhaseEOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 23U)) + 16277954291890598132U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14845750668693136766U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 150099699692047766U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7644895634421086357U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1200784917165131703U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9469982764806754302U;
            aOrbiterF = RotL64((aOrbiterF * 17851969334511301943U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10956702761701710182U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7915506894975487807U;
            aOrbiterH = RotL64((aOrbiterH * 8874108311712727983U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17335794183733623213U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 557028996286989506U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3993359298602424281U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 1597385667771002414U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4376417959915162639U;
            aOrbiterJ = RotL64((aOrbiterJ * 4626236858205178149U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 549770198518993876U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 756554555648070919U;
            aOrbiterC = RotL64((aOrbiterC * 16272320259614325355U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 7298557532533152193U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3336802611342112013U;
            aOrbiterE = RotL64((aOrbiterE * 14679103452120080499U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 26U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 60U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterC, 13U));
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterA, 53U)) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10103U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 10114U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 14290U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneC[((aIndex + 13712U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13077U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14000U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10188U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 4U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 7075016829833562104U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 5U)) + 8783765886115517036U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 29U)) + 2996723892384565829U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 9494134707342189476U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 57U)) + 5052642981395679904U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 18U)) + RotL64(aCarry, 47U)) + 8766787055127962238U) + aPhaseEOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 11U)) + 4467211954388738079U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8030255604633658608U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16962408063455702251U;
            aOrbiterC = RotL64((aOrbiterC * 11171737929747471631U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3768222186567699076U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14930990410207899871U;
            aOrbiterD = RotL64((aOrbiterD * 10930005786146268241U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14179761938395502502U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1879084742719898108U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16783034788172670121U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5535012408925981515U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12792553516710295939U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8577530993755159329U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8979253163346099252U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5559189896063990740U;
            aOrbiterH = RotL64((aOrbiterH * 8832485423727331621U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13937564337299044079U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2393376759689394948U;
            aOrbiterE = RotL64((aOrbiterE * 2352815657830413941U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12647519563697356479U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10946871249960389549U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6272580371881237173U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterE, 13U));
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 28U)) + aOrbiterC) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterB, 53U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH + (((RotL64(aScatter, 12U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19418U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 17807U)) & S_BLOCK1], 26U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 19642U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 23799U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19413U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24162U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 17218U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aScatter, 12U)) + RotL64(aCarry, 5U)) + 11480359716598965890U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 35U)) + 15431182525482873419U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 23U)) + 11360504974812776707U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 41U)) + 9292576416573382769U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 1549257414531028975U) + aPhaseEOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 5U)) + 5347769463033129317U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 17019199177478377234U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16558106007323125094U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3976182233825939422U;
            aOrbiterC = RotL64((aOrbiterC * 4392162052317572289U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2889047161195954395U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2241831345026962605U;
            aOrbiterK = RotL64((aOrbiterK * 5757458560979927857U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12850802412140579294U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13541744735436450160U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 906089290000537439U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2085863085516538212U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2969034221711544086U;
            aOrbiterJ = RotL64((aOrbiterJ * 7768528124408400403U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6482666944512391472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16969153556875844613U;
            aOrbiterD = RotL64((aOrbiterD * 9483462388353216219U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5161314086757363678U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7150282484670673211U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8522427002337918663U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5465304381272305847U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2344610773390354017U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17010258514288089191U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterA, 47U));
            aWandererE = aWandererE + ((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 14U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterH, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 24981U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 31689U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 30544U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28931U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30979U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29236U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 30622U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererD + RotL64(aIngress, 43U)) + 9471546960258473684U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 23U)) + 18050235435948942244U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 3005107102671544641U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 17898396434573801850U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 11U)) + 15071602525497771648U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 37U)) + 5780119462702672108U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 50U)) + RotL64(aCarry, 39U)) + 13301326224151025687U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18129323022260575961U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1199228670638790709U;
            aOrbiterI = RotL64((aOrbiterI * 1780426336211781025U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1839199978088021020U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4999517042246790165U;
            aOrbiterD = RotL64((aOrbiterD * 4585813675677234577U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8788607633376516299U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15143903839930468749U;
            aOrbiterG = RotL64((aOrbiterG * 12735914889325422675U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16674732686428431869U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 15908873150953195581U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18049755517524334107U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11204775359756474667U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2525984309543939465U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3988529812023791571U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4566345170476825512U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14876612901557406267U;
            aOrbiterC = RotL64((aOrbiterC * 9047956948845135339U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14926290877038883931U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12710203178186614846U;
            aOrbiterF = RotL64((aOrbiterF * 14841163494801662515U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterA, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 41U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterG, 58U));
            aWandererK = aWandererK + ((RotL64(aIngress, 44U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_VolleyBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4030U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 8157U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3389U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 787U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2209U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1761U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 53U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 35U)) + 7075016829833562104U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 43U)) + 8783765886115517036U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 41U)) + 2996723892384565829U;
            aOrbiterD = (aWandererB + RotL64(aCross, 5U)) + 9494134707342189476U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 47U)) + 5052642981395679904U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 8766787055127962238U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 50U)) + 4467211954388738079U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 35U)) + 8030255604633658608U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aPrevious, 11U)) + 16962408063455702251U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 37U)) + 3768222186567699076U) + aPhaseFOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 14930990410207899871U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 14179761938395502502U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1879084742719898108U;
            aOrbiterB = RotL64((aOrbiterB * 16783034788172670121U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5535012408925981515U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12792553516710295939U;
            aOrbiterF = RotL64((aOrbiterF * 8577530993755159329U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8979253163346099252U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5559189896063990740U;
            aOrbiterH = RotL64((aOrbiterH * 8832485423727331621U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13937564337299044079U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2393376759689394948U;
            aOrbiterG = RotL64((aOrbiterG * 2352815657830413941U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12647519563697356479U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10946871249960389549U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6272580371881237173U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13376798695582123147U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10958115913599631271U;
            aOrbiterD = RotL64((aOrbiterD * 18233981473003345217U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4283914227806672773U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 910842005516235816U;
            aOrbiterI = RotL64((aOrbiterI * 6722229871617873429U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1509644316619370324U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 165987596716078174U;
            aOrbiterA = RotL64((aOrbiterA * 13600064054240185123U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12491315345199091186U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5982431705686495125U;
            aOrbiterE = RotL64((aOrbiterE * 2547243804779022665U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 231183123382412440U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2872632389683254396U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1972278820468847241U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15259314110008210315U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7075016829833562104U;
            aOrbiterK = RotL64((aOrbiterK * 8350093877370898869U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 40U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterK, 5U));
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 39U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterI, 58U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterD, 13U));
            aWandererB = aWandererB + ((RotL64(aScatter, 22U) + RotL64(aOrbiterF, 37U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 60U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 4U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13759U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 10027U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12381U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9733U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9260U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11940U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10236U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 56U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 9630214189402543339U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 14U)) + RotL64(aCarry, 11U)) + 4072576573737526819U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 27U)) + 15994787452709618869U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 43U)) + 6403240137132259482U;
            aOrbiterG = (aWandererH + RotL64(aCross, 29U)) + 10229266900170507720U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 3U)) + 5025294577989748989U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 57U)) + 16696461238217956883U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 5U)) + 9878318855341719119U;
            aOrbiterH = (aWandererA + RotL64(aCross, 12U)) + 16086635438116177346U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 12295437783084203730U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 39U)) + 7681150419912842402U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2639104034287637448U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12298170009332243573U;
            aOrbiterI = RotL64((aOrbiterI * 9397919591171238575U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3485932317267669626U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16569551670038752475U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8139802826402217631U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4448490103784103954U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14510534073046885941U;
            aOrbiterJ = RotL64((aOrbiterJ * 7777192047386438305U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4286195398675733451U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15790355933840266463U;
            aOrbiterD = RotL64((aOrbiterD * 13342257823027075501U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6362891510370156055U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15121822034579983174U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7268045994574844937U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13817341015719915628U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14113474087906143783U;
            aOrbiterE = RotL64((aOrbiterE * 12838910141533126059U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9988301252236121106U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11287477288382171758U;
            aOrbiterH = RotL64((aOrbiterH * 4979297247881426383U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9491727010910328644U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7961202721830514030U;
            aOrbiterG = RotL64((aOrbiterG * 16300364540313620767U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10058066852293995222U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 541563830282750968U;
            aOrbiterB = RotL64((aOrbiterB * 1516823517052019845U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7791201128863372861U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8334318157449352359U;
            aOrbiterA = RotL64((aOrbiterA * 2924838607279239375U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6861081455774799715U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9630214189402543339U;
            aOrbiterK = RotL64((aOrbiterK * 10837610668580336781U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 22U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 53U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 12U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 27U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 39U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aCross, 36U) + aOrbiterB) + RotL64(aOrbiterE, 43U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18904U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 19648U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 17033U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 20562U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24419U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19513U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21332U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 43U)) + (RotL64(aPrevious, 30U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 47U)) + 4848316479321533394U;
            aOrbiterH = (aWandererB + RotL64(aCross, 50U)) + 6919360256662636195U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 35U)) + 9897013582181108544U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 7319353809896158678U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 2848175435514849859U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 29U)) + 6967780718720437934U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 10143884766603388136U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 54U)) + 8675965006150972051U;
            aOrbiterC = (aWandererC + RotL64(aCross, 19U)) + 16350117755560994281U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 3U)) + 17976597517118423760U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 57U)) + 1399631141355370237U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3590613762034716792U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5134624314245932157U;
            aOrbiterK = RotL64((aOrbiterK * 13077589037975283371U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10082236952942943654U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4015535035905433450U;
            aOrbiterG = RotL64((aOrbiterG * 4961808568701908559U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 611474103801573800U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5786708483794098001U;
            aOrbiterH = RotL64((aOrbiterH * 7694007039340089267U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5201943497363274455U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9282160506938328489U;
            aOrbiterC = RotL64((aOrbiterC * 5368182164239021367U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 4932320527498940158U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11576526341731392916U;
            aOrbiterI = RotL64((aOrbiterI * 1712051774729439363U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10790691517638887125U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16280649213607464422U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10756733801499471873U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9553716940667712810U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11827518270964003341U;
            aOrbiterF = RotL64((aOrbiterF * 1322489827908132831U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16777463701235809321U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3375489084588454149U;
            aOrbiterA = RotL64((aOrbiterA * 3335010977457647307U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8129898095524287632U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14496406641486541929U;
            aOrbiterJ = RotL64((aOrbiterJ * 10077246205532940301U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17968163292907132345U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2431407778543471402U;
            aOrbiterB = RotL64((aOrbiterB * 407105842057624537U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 18330313613898211889U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4848316479321533394U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3462735144109152811U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 4U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 50U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 5U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 37U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 19U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 48U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererK, 58U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29487U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 28201U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 30231U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((aIndex + 25389U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28264U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30549U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 29148U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 38U)) + (RotL64(aPrevious, 3U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 13U)) + 16424657151168221875U;
            aOrbiterF = (aWandererG + RotL64(aCross, 35U)) + 17150123681886380361U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 16041993588694572757U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 9871185846434828537U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 11227236398354430757U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 6U)) + 5399325217402192631U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 57U)) + 9248828789282890454U;
            aOrbiterG = (aWandererD + RotL64(aCross, 29U)) + 9041370494203701062U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 41U)) + 14944424084524970764U) + aPhaseFOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 43U)) + 5481938174456671041U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 52U)) + 14783648629543752715U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12355573914530445723U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9863991559011968318U;
            aOrbiterJ = RotL64((aOrbiterJ * 8495251211794343179U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16149688605937250965U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 106041828692026825U;
            aOrbiterA = RotL64((aOrbiterA * 12199934305374582599U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8076098639554567792U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11155119311895580013U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1495180896564818647U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6847612160595917702U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16094377920388017367U;
            aOrbiterD = RotL64((aOrbiterD * 4875801863643206333U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13584719866672696684U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13446209321646234607U;
            aOrbiterF = RotL64((aOrbiterF * 9945349065094781529U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15829806645369560988U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12573767256739062550U;
            aOrbiterE = RotL64((aOrbiterE * 5649504278826069077U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 3850030870300393809U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11857593987748189858U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15942863910931814193U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5505918410521728373U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12949653497121247860U;
            aOrbiterI = RotL64((aOrbiterI * 90944913639560027U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2448323375614082955U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4386059032042654583U;
            aOrbiterC = RotL64((aOrbiterC * 11730132905525317201U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 108129028178045299U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 18292666533864994149U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2599590507178673531U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10771402979550786312U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16424657151168221875U;
            aOrbiterG = RotL64((aOrbiterG * 6255743082177474607U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 21U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterE, 12U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterA, 35U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 48U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + aPhaseFWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterE, 54U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterC, 23U));
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 37U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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

void TwistExpander_VolleyBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6915U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 4584U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7479U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2379U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4391U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 799U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 4U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererG + RotL64(aCross, 29U)) + 5041131702736607991U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 9295010428212681446U) + aPhaseGOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 6235875895358766017U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 18U)) + RotL64(aCarry, 11U)) + 2622227802531866918U;
            aOrbiterG = (aWandererA + RotL64(aCross, 57U)) + 3888894734834524972U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 241682012014701753U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15758000422451568079U;
            aOrbiterD = RotL64((aOrbiterD * 14719166949665416221U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2061944548396976912U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8177144990755754531U;
            aOrbiterG = RotL64((aOrbiterG * 12702392689484397947U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 554978075608818497U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 250408260560714933U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1295379390497107727U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8700027645880997552U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10026130047465480902U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12417270861933696623U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9785843014096326696U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9998582683258411251U;
            aOrbiterI = RotL64((aOrbiterI * 7197956237569462269U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 44U) + aOrbiterK) + RotL64(aOrbiterH, 57U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 48U)) + aOrbiterI) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 23U)) + aOrbiterH) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererG, 24U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13298U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 15835U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 9039U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10058U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14454U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 9896U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 12U) + RotL64(aIngress, 43U)) + (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 4751694786009671052U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 16362725160370844224U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 11U)) + 6360885380915941057U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 34U)) + RotL64(aCarry, 21U)) + 5154536007972297036U) + aPhaseGOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 3U)) + 9362540581874808253U) + aPhaseGOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13902493871525612934U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 10208452885367546542U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12067703239567933105U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3117030377279160998U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17286247690414027870U;
            aOrbiterD = RotL64((aOrbiterD * 4896931759653832095U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3930314320040949141U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7289525252391668404U;
            aOrbiterJ = RotL64((aOrbiterJ * 15452162299105112187U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3434167955466809185U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17852573095128575663U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1485660158767033425U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6137259687928853253U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13992510605237574698U;
            aOrbiterI = RotL64((aOrbiterI * 15346263295995333395U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 40U) + aOrbiterB) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterD, 38U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + aPhaseGWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21374U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 21856U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16927U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22087U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23633U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21520U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 20U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 12849591986267890852U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 57U)) + 8232614804696815750U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 3U)) + 12141567259210877281U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 36U)) + RotL64(aCarry, 3U)) + 2928641981037885644U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 980733350554783938U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2683985177993350746U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14532148403815527355U;
            aOrbiterD = RotL64((aOrbiterD * 15985362037094864225U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7736296629433884203U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10428437770166310549U;
            aOrbiterC = RotL64((aOrbiterC * 326634742742373401U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 18327174144859461029U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6810436935194432002U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2715987179577753597U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12606153309690753435U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17123256945895150555U;
            aOrbiterE = RotL64((aOrbiterE * 13469111258504672565U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9057777759026189541U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16478485918911194442U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11054247078884894131U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterD, 13U));
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 28U)) + aOrbiterD) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29397U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 25821U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26336U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25631U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27264U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24783U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 10881271196314989997U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 11U)) + 6406461249988567558U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aPrevious, 38U)) + 17255067918280095959U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 16690850682497718411U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 5576201059361086866U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11991259685693687554U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14652535244217836909U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18283959577075524171U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1701789037170782122U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 953429054903473833U;
            aOrbiterA = RotL64((aOrbiterA * 13482379459700651427U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12064513610469714211U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7993881398822002424U;
            aOrbiterF = RotL64((aOrbiterF * 11572884842788918377U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 14421313768013320050U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11112386845630998889U;
            aOrbiterD = RotL64((aOrbiterD * 11771526352030371669U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 17069630896535699015U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3308240081138623373U;
            aOrbiterG = RotL64((aOrbiterG * 10449509484417835159U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 58U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_VolleyBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // ingress from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneB backward forced, aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1978U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 1972U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5557U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6888U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3561U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 7952U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 30U)) + 701291026547470433U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 17283292650462111643U) + aPhaseHOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 9969124091931303406U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 889176772718046988U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 47U)) + 6054541844643748084U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14703226235143028132U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7977975878522921062U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9030855800028448469U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16894322614172266274U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12160451749345900570U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18055355572903901749U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10870847008043897470U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8159920947172520247U;
            aOrbiterI = RotL64((aOrbiterI * 4833194641611011805U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2440099120969517932U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2428396147731468007U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9363073341539598441U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2213226274394673479U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7079731443427765333U;
            aOrbiterE = RotL64((aOrbiterE * 16918930776877030559U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterI, 37U));
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 46U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 29U)) + aOrbiterA) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14318U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 11621U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10667U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13448U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13285U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13771U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 3U)) + 12136097566601676613U) + aPhaseHOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 27U)) + 7969431322248040056U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 56U)) + RotL64(aCarry, 51U)) + 10530676021510553889U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 8740777303075445264U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 13249434169895564739U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15529577005925628472U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 344627093687331562U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3226087371456521323U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8824277416519988893U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5636276438449709875U;
            aOrbiterJ = RotL64((aOrbiterJ * 222817930773618893U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2079413361031851552U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7807998179168655561U;
            aOrbiterD = RotL64((aOrbiterD * 961456853699784753U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13589392896232029112U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10733011474804473996U;
            aOrbiterB = RotL64((aOrbiterB * 361749145931578805U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15934162328347805968U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7573511217796245232U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10694563909931636155U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 4U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterA, 27U)) + aOrbiterG) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 11U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16484U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 20591U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 22089U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20721U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18623U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17887U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 20U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 3612110001869385068U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 44U)) + 16340824141280225936U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 15222338965130765231U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 6649270508107155041U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 27U)) + 768217258655426384U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4481855259658861851U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 18318041934562434016U;
            aOrbiterB = RotL64((aOrbiterB * 14913761339765234979U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4212457153804401807U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16143621095636987628U;
            aOrbiterG = RotL64((aOrbiterG * 6576072860505961427U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2095664232866642086U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4339527736737366572U;
            aOrbiterK = RotL64((aOrbiterK * 17503569508822244125U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13679353177869884790U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11582168502846418236U;
            aOrbiterC = RotL64((aOrbiterC * 135539430034462861U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10451330452898542191U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12951448817640617841U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4141870904192742091U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 28U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 52U)) + aOrbiterK) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 44U) + aOrbiterG) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + aPhaseHWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 39U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 19U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 24794U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 27887U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24637U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28592U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27230U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 25497U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 58U) ^ RotL64(aCross, 13U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 19U)) + 2974056819475622600U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 3U)) + 7345051759236356098U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 12738468816846628882U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 30U)) + RotL64(aCarry, 35U)) + 7694520596043297922U) + aPhaseHOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 5530753590015084774U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3776309161718383105U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 784780304358106404U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1503119308251871519U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8999942326995036509U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5194986506064092779U;
            aOrbiterE = RotL64((aOrbiterE * 15070787038006135963U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 7920040007459652762U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11311997270710107937U;
            aOrbiterD = RotL64((aOrbiterD * 6227571709361790209U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5365231114813547251U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8630110234623825263U;
            aOrbiterG = RotL64((aOrbiterG * 2735881715888325759U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2358235238039571072U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 18059414891616491807U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17150786106857185467U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 56U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 37U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterH, 57U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterD, 20U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 47U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
