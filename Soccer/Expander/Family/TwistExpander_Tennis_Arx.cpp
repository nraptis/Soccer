#include "TwistExpander_Tennis_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Tennis_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCEA9BAAEBD5D35DBULL + 0xC8F93AABAC50D16DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB7CED11336CD9F81ULL + 0xA3F72DAA39498D20ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF08D9E7AF1C118CDULL + 0xD88A06F83D9FBF6DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBAC5D46B4836A955ULL + 0xEB1D0D3BC25C0C9AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA0E9C42ADE3F133DULL + 0xBE0C692FEC887404ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA1A139991DC4D001ULL + 0xEB74869E66DEE8FFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF8BE216A3F426E95ULL + 0x9F8F430728BCDD08ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC943F8E4421A4D4BULL + 0x8F202A66FD97C6E1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE52A1FC672489B15ULL + 0xE772756C07E651F5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB36E7F302FCA5B93ULL + 0x91F303D60BB01250ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB8E431DFABB30C01ULL + 0x84FD85CB0A7B2825ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9FC4B19D22C0872DULL + 0xD146FA4AC173400EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDDA65B43984329CBULL + 0xE68F7327D5095ED5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE9ACF986D106ECF1ULL + 0xAC0C32BFC8CC919DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xED1F06AA43CDDB4BULL + 0xA90A2D94FC8D2F86ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x824B2E6B5727B8BFULL + 0xAE4039FA059290FBULL);
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
            aIngress = RotL64(mSource[((aIndex + 926U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4936U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4346U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1413U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = ((aWandererA + RotL64(aIngress, 19U)) + 12980104182836602177U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 3172622203188863995U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 43U)) + 1170974132219980203U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 50U)) + RotL64(aCarry, 41U)) + 6035201940965047490U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 21U)) + 18033907118424996722U) + aNonceWordH;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 53U)) + 14604813424800580304U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 41U)) + 13720232492851066035U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 34U)) + RotL64(aCarry, 19U)) + 3902659710585257448U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 37U)) + 8331560652661619868U) + aNonceWordO;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 23U)) + 4485014147538689794U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 39U)) + 168202636924512424U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16227825670092707848U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4792781933944671365U;
            aOrbiterF = RotL64((aOrbiterF * 15859849676231455283U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12636865372722601282U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18198291399585556632U;
            aOrbiterC = RotL64((aOrbiterC * 18155803890313399795U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3650053185419807206U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5897288963905408776U;
            aOrbiterD = RotL64((aOrbiterD * 3706949366974086151U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9922308113622901726U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13352279749091561510U;
            aOrbiterA = RotL64((aOrbiterA * 4025213180483632557U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14969461950939646117U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10231661776135056651U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11284575051455238501U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10621934544068320859U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6029116920305246887U;
            aOrbiterE = RotL64((aOrbiterE * 6087523725059376905U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12887482425168671195U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8351351557123783853U;
            aOrbiterB = RotL64((aOrbiterB * 3839381627914762245U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5405938210926464973U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 385145802287899406U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8330751480464271445U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7907749190875916461U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5138733192253468642U;
            aOrbiterK = RotL64((aOrbiterK * 17028325976353263843U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 14382272868178763187U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14354777100157531233U;
            aOrbiterG = RotL64((aOrbiterG * 7095764230272037767U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4390647647193363824U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12980104182836602177U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11124472075872147333U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 34U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 24U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterG, 43U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterG, 37U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 19U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 39U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 18U) + aOrbiterE) + RotL64(aOrbiterB, 6U));
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 5927U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 7280U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7917U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8640U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 13U)) + 3248574644570178787U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 52U)) + 4506961512959200024U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 29U)) + 8423739774540738590U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 5U)) + 6593975869641735337U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 3U)) + 16441716090557369103U;
            aOrbiterB = ((((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 7936601450453207914U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 47U)) + 13333752583560167065U) + aNonceWordL;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 8013703284795432973U) + aNonceWordE;
            aOrbiterK = ((aWandererK + RotL64(aCross, 10U)) + RotL64(aCarry, 37U)) + 2349852779887439236U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 43U)) + 5318539364763284138U) + aNonceWordH;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 39U)) + 11450957608502944376U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9058992558327552687U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 632095686920230926U;
            aOrbiterH = RotL64((aOrbiterH * 12460364388358520799U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14734218428913777098U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 16344357661370784442U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15049472842002138369U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2981145363531184308U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14176472085175714494U;
            aOrbiterF = RotL64((aOrbiterF * 2584623327412130939U), 47U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 11198457590069700889U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 952584436750426828U;
            aOrbiterK = RotL64((aOrbiterK * 1165713888651280355U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4311591763498985972U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16194341833989936369U;
            aOrbiterG = RotL64((aOrbiterG * 9997934560195932575U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7560794022401107431U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10683789740265711603U;
            aOrbiterI = RotL64((aOrbiterI * 15637823045351977883U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11614366395125937178U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10750771385100564416U;
            aOrbiterJ = RotL64((aOrbiterJ * 4987921274272444283U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2934697034132204529U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4646873794658020363U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10555456865641580175U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7913681837683568905U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17603563535330106340U;
            aOrbiterE = RotL64((aOrbiterE * 17882943067522319671U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15375641415139193079U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17059712718085411887U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 13722089235751208215U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14022558453716067200U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3248574644570178787U;
            aOrbiterD = RotL64((aOrbiterD * 15249135451439374621U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 40U);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 51U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterC, 54U));
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterE, 23U)) + aNonceWordJ) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterF, 39U)) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterH, 36U));
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 27U)) + aOrbiterA) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aIngress, 10U) + aOrbiterD) + RotL64(aOrbiterC, 13U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 15950U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((aIndex + 15926U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14547U)) & S_BLOCK1], 56U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 13522U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 26U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (aWandererB + RotL64(aIngress, 39U)) + 12222235191147985484U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 47U)) + 16367317014523328414U) + aNonceWordN;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 43U)) + 3511378091284703789U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 15247492830966725949U) + aNonceWordD;
            aOrbiterE = (aWandererE + RotL64(aCross, 35U)) + 7745995913390407897U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 41U)) + 6463593307540108810U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 22U)) + RotL64(aCarry, 3U)) + 1101669311005268630U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 11U)) + 12988052764067518580U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 17717179747434679772U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aScatter, 19U)) + 11662190906682400416U) + aNonceWordB;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 6U)) + 6563014073547628748U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13099094932059419219U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16342730862261868847U;
            aOrbiterA = RotL64((aOrbiterA * 10988124108686164829U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 16855346813127524624U) + aNonceWordJ;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 6570063128502306944U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 4571570049463124831U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11328352033809240501U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11640986648833160901U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2895830492089678919U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2675226158571501666U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17700531248266458165U;
            aOrbiterI = RotL64((aOrbiterI * 2231403813970188657U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7729597396731910874U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15172374484412053756U;
            aOrbiterD = RotL64((aOrbiterD * 149009041406406517U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9178769489257842683U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9020154972097834926U;
            aOrbiterF = RotL64((aOrbiterF * 8910504667566521429U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1317403761217790562U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17151528554929201571U;
            aOrbiterK = RotL64((aOrbiterK * 3735945655450625203U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11621882033959669977U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10289504450815075623U;
            aOrbiterB = RotL64((aOrbiterB * 13365982786836243195U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16178772981106335703U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16896130772325866910U;
            aOrbiterH = RotL64((aOrbiterH * 6993524735412868965U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9573223644675562575U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17552463713786507189U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16103431656424881779U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4801852246698369631U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12222235191147985484U;
            aOrbiterC = RotL64((aOrbiterC * 2835204872125428065U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 14U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterH, 43U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterK, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterG, 5U));
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterC, 47U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 58U)) + aOrbiterI) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterB, 29U));
            aWandererF = aWandererF + (((((RotL64(aScatter, 4U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 48U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17928U)) & S_BLOCK1], 41U) ^ RotL64(pSnow[((aIndex + 21139U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 18126U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 19893U)) & S_BLOCK1], 22U) ^ RotL64(aFireLaneB[((aIndex + 19175U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 48U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (aWandererK + RotL64(aCross, 27U)) + 16424657151168221875U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 5U)) + 17150123681886380361U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 60U)) + 16041993588694572757U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 35U)) + 9871185846434828537U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 41U)) + 11227236398354430757U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 29U)) + 5399325217402192631U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 52U)) + 9248828789282890454U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 9041370494203701062U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 57U)) + 14944424084524970764U) + aNonceWordK;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 5481938174456671041U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 14783648629543752715U) + aNonceWordD;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12355573914530445723U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9863991559011968318U;
            aOrbiterI = RotL64((aOrbiterI * 8495251211794343179U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16149688605937250965U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 106041828692026825U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12199934305374582599U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8076098639554567792U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11155119311895580013U;
            aOrbiterE = RotL64((aOrbiterE * 1495180896564818647U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6847612160595917702U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16094377920388017367U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4875801863643206333U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13584719866672696684U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13446209321646234607U;
            aOrbiterA = RotL64((aOrbiterA * 9945349065094781529U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15829806645369560988U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12573767256739062550U;
            aOrbiterK = RotL64((aOrbiterK * 5649504278826069077U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3850030870300393809U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11857593987748189858U;
            aOrbiterH = RotL64((aOrbiterH * 15942863910931814193U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5505918410521728373U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12949653497121247860U;
            aOrbiterB = RotL64((aOrbiterB * 90944913639560027U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2448323375614082955U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4386059032042654583U;
            aOrbiterF = RotL64((aOrbiterF * 11730132905525317201U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 108129028178045299U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18292666533864994149U;
            aOrbiterG = RotL64((aOrbiterG * 2599590507178673531U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10771402979550786312U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16424657151168221875U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6255743082177474607U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aIngress, 44U) + aOrbiterK) + RotL64(aOrbiterH, 53U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 24U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 3U)) + aNonceWordI) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 37U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            aWandererI = aWandererI + (((RotL64(aIngress, 30U) + aOrbiterB) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25515U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 23118U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(pSnow[((aIndex + 26051U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25034U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27176U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((aIndex + 27030U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 48U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererI + RotL64(aScatter, 34U)) + 2558105147674438050U) + aNonceWordB;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 51U)) + 15856662514774702561U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 19U)) + 13346869226246584582U) + aNonceWordN;
            aOrbiterC = ((aWandererC + RotL64(aCross, 41U)) + 7632111846116243973U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 27U)) + 2102101361626976279U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 5605968705067851563U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 6842483186584326681U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 13U)) + 5559797213819425064U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 21U)) + 12422313931331576759U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 58U)) + 2751024420047872601U) + aNonceWordJ;
            aOrbiterB = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 11031320239359798610U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14366375309473793217U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11971479429768505316U;
            aOrbiterA = RotL64((aOrbiterA * 10063001532313098203U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3947595951884469542U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17882767922372770896U;
            aOrbiterI = RotL64((aOrbiterI * 3361906348965810211U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 513871456983509223U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 5951677013597794294U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 8508629569649935293U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 437626309049021931U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 466674061172005705U;
            aOrbiterK = RotL64((aOrbiterK * 1310502572084891157U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12362602809233133718U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10525852878882195702U;
            aOrbiterF = RotL64((aOrbiterF * 17755022180514914325U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17927000184308583095U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 566723721423470052U;
            aOrbiterD = RotL64((aOrbiterD * 17710534355278632573U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9504585484034413577U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4614306037721859929U;
            aOrbiterJ = RotL64((aOrbiterJ * 170807293799483539U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1463218357720031588U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4036696102163560633U;
            aOrbiterC = RotL64((aOrbiterC * 15389914226155130065U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9907678911300898726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11804311892289601322U;
            aOrbiterG = RotL64((aOrbiterG * 13986106774841242253U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6514645538508331396U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17246364354815744899U;
            aOrbiterH = RotL64((aOrbiterH * 12800661037742526999U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6725706155285333764U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2558105147674438050U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6752457079901154727U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterA, 39U)) + aOrbiterF) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 42U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterI, 27U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterK, 13U)) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 22U) + RotL64(aOrbiterH, 3U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 51U)) + aOrbiterE) + aNonceWordM);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterA, 46U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 12U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30226U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 30478U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 32577U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29053U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31359U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 29063U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29488U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 29U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererC + RotL64(aCross, 19U)) + 5573188770530340913U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 1431772230889897111U) + aNonceWordE;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 58U)) + 4809192776429682319U) + aNonceWordD;
            aOrbiterB = (aWandererD + RotL64(aScatter, 5U)) + 5576603692574369341U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 53U)) + 2720143226007220386U) + aNonceWordH;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 17220328778565331629U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 23U)) + 9629485808442089423U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 41U)) + 1136998437010390983U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 11893390497814523841U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 27U)) + 1764986431917532370U) + aNonceWordA;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 10U)) + 1741014798007010376U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12221368453236547044U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7694538641172350430U;
            aOrbiterD = RotL64((aOrbiterD * 8439120733670016501U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17472344518811560603U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3308740700728172984U;
            aOrbiterE = RotL64((aOrbiterE * 15290400462887712083U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9535358833412446771U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11192312491731312451U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 17405609148475445743U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14850451970047190039U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11932493299452443256U;
            aOrbiterF = RotL64((aOrbiterF * 7964808728820467795U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5972619895614731870U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17174497535809891690U;
            aOrbiterB = RotL64((aOrbiterB * 15471084511364572533U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17412894714378898351U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14675615208706549810U;
            aOrbiterK = RotL64((aOrbiterK * 7864845089606499769U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16116792108013658523U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9702262005960966336U;
            aOrbiterC = RotL64((aOrbiterC * 970452849653781703U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17337264966818542841U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 7004462033775827275U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 11943575980344402681U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17499850384482055438U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1839357713256560566U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12943750650487416281U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8144238113917577524U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 888195876227325908U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7941506708630993709U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5081763359501717653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5573188770530340913U;
            aOrbiterJ = RotL64((aOrbiterJ * 9699901099898698965U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 56U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 11U)) + aOrbiterG) + aNonceWordI);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 27U)) + aOrbiterI) + aNonceWordO);
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterK, 56U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 39U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 21U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 36U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Tennis_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA0A61AC8456974B3ULL + 0xD21153527E7A05CCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8DE1B7D1E48B62A5ULL + 0xD207762F415B14FBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x954628510A551CADULL + 0xD7E6551B5FE60C3CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB644FA65E39BDFA1ULL + 0xD105B17F792283B0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFEB1CAC5D5303BD5ULL + 0xDE61C4C7FA121083ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8EB6D7B4DC1E4765ULL + 0xC2DFA8C7EA1A2303ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8D05F29DFBC41B3DULL + 0xF140CA1D31B8AB25ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF53454054573737DULL + 0x96354E521CE705F4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA921FC095128D3CFULL + 0x9EDFB68D4D7D0AEDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBA6775467C226CB5ULL + 0xBFD56789C8E7EF60ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB730B8247C6E4611ULL + 0xE72E730BC4035000ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF6D84B399E501549ULL + 0x9192A2D1CEC56635ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCAFEAACA733CD645ULL + 0x80D9FCDA7C0B0656ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA326519699B26E09ULL + 0xB3F37726495B304DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD26BDE3B7767FCBFULL + 0xEA7A681833119550ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9A3DE04DBFFC856BULL + 0xCF033293C1B430E0ULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 4075U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 439U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5425U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4626U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 19U)) + 9774364261626083532U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 18059001521926116420U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 10615626210406381148U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 34U)) + 10536484278007898620U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 51U)) + 13320663045139972700U;
            aOrbiterA = (aWandererB + RotL64(aCross, 29U)) + 17127001787268166583U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 16742574590844166551U) + aNonceWordI;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 11U)) + 8347719720758228053U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 24U)) + 13502468705946051986U) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3512687886188904904U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 495660316165795934U;
            aOrbiterG = RotL64((aOrbiterG * 6724596801190194913U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5092722552034477356U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15641128019608284015U;
            aOrbiterC = RotL64((aOrbiterC * 3621036395703527059U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15421873776811085458U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17978775513204574125U;
            aOrbiterD = RotL64((aOrbiterD * 18359600395119440183U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16617179197537669849U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1931805387534012528U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 3400139345857733775U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9544923119559308431U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12930999400470173353U;
            aOrbiterJ = RotL64((aOrbiterJ * 16791006919271490005U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13673733276226249890U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2032263473309124738U;
            aOrbiterB = RotL64((aOrbiterB * 3088728329261360607U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14868502349358414206U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10116495537187552321U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1380512121796709469U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5341113995358179244U) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8415417980279705731U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8521501372683793821U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2462819265072352463U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7657062767608441931U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15554638801273540163U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 12U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterI, 22U));
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 4U) + aOrbiterI) + RotL64(aOrbiterF, 57U)) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterD, 47U)) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF) + aNonceWordP);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 18U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 43U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aIngress, 24U) + aOrbiterC) + RotL64(aOrbiterH, 11U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 8353U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 5597U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7749U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8953U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((aIndex + 8877U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 4U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 8604208734152026945U) + aNonceWordO;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 11U)) + 1374329953253889829U) + aNonceWordH;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 27U)) + 5779278910548228339U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 20U)) + RotL64(aCarry, 37U)) + 17670451230882805140U) + aNonceWordD;
            aOrbiterG = (aWandererE + RotL64(aCross, 35U)) + 8193848740764866860U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 47U)) + 15801168428145650104U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 43U)) + 2584718176087499066U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aIngress, 52U)) + RotL64(aCarry, 53U)) + 14950366247822737997U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aCross, 5U)) + 9779293225265670135U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8688968319288372383U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13665723186950342601U;
            aOrbiterI = RotL64((aOrbiterI * 292035540396910837U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9395428688359973510U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2152719218018108418U;
            aOrbiterK = RotL64((aOrbiterK * 15271961483518392671U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1350324137411377992U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8729317951386057921U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6008790836417785083U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6317310451893678411U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10175620379041384281U;
            aOrbiterG = RotL64((aOrbiterG * 14079679617394330781U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1203082119358827708U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 523869107818193101U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4629501113595689157U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4028324959540432983U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15447631947468213912U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 6037306615787729185U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14225888694733041031U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 11925000696281947629U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4337022940520411253U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15015531024930608745U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16752579225076943550U;
            aOrbiterH = RotL64((aOrbiterH * 15551083683579981439U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2432733494869267901U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 10103430321388601485U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 18372919379972432569U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 54U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 57U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 4U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterA, 35U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterD, 10U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 21U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 3U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterI, 21U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aIngress, 30U) + RotL64(aOrbiterK, 30U)) + aOrbiterC) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 14937U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((aIndex + 14506U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15833U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15791U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((aIndex + 13927U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (((aWandererF + RotL64(aScatter, 11U)) + 17019646486641172469U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 51U)) + 12276141179299971572U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 24U)) + RotL64(aCarry, 3U)) + 3617241694029841555U) + aNonceWordF;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 29U)) + 6967963401259371737U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 6340709284279891017U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 456065368903896482U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 40U)) + 17686765719908116203U) + aNonceWordJ;
            aOrbiterF = (aWandererD + RotL64(aScatter, 35U)) + 1322045955429785736U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 57U)) + 5163772703302372887U) + aNonceWordB;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13268431135020363252U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6538789950366849332U;
            aOrbiterA = RotL64((aOrbiterA * 5352960308459065837U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10390344544314544893U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5087084271300584267U;
            aOrbiterJ = RotL64((aOrbiterJ * 15149302947570776165U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13423071121590981727U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 18324443012024134729U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 15814349432207734533U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4129091815978464507U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17024797553831962245U;
            aOrbiterF = RotL64((aOrbiterF * 3137753479364378175U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6501545108779991661U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11930037791867597447U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4904739567549702851U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4667298703308315851U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6315980380900062127U;
            aOrbiterK = RotL64((aOrbiterK * 12080555704907924637U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12732382340390769888U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7792095326183864547U;
            aOrbiterG = RotL64((aOrbiterG * 12645556660611824631U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17428384983571405782U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3193205313177048443U;
            aOrbiterE = RotL64((aOrbiterE * 14488006565106259731U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2813743367131107264U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2742138679703780981U;
            aOrbiterH = RotL64((aOrbiterH * 18356569025783532225U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterE, 58U)) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 39U)) + aOrbiterI) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterE, 30U)) + aNonceWordP);
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterH, 11U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21192U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 20691U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 20015U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19750U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16930U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((aWandererG + RotL64(aCross, 23U)) + 10805654776556844351U) + aNonceWordM;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 56U)) + RotL64(aCarry, 51U)) + 582794182442795335U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 51U)) + 2858343650974681068U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 8189584049022064284U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 35U)) + 1565100751996962893U) + aNonceWordA;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 19U)) + 8062028016947611891U) + aNonceWordL;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 8280504280578451745U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 6U)) + 11326869194491655350U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aWandererA + RotL64(aIngress, 43U)) + 1671695656567777163U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2349843105293943452U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13015545152052004254U;
            aOrbiterD = RotL64((aOrbiterD * 1316662811685429983U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16703354404749291869U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8713231044374305801U;
            aOrbiterF = RotL64((aOrbiterF * 9242480982197688625U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11118401674497783533U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14857556493734710364U;
            aOrbiterJ = RotL64((aOrbiterJ * 3452566050389715195U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12953419670951660965U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12666121730825089017U;
            aOrbiterI = RotL64((aOrbiterI * 14049925256934142519U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11075249639473053423U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 9374217688244187867U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 5261156325627117877U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17608340953291367867U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13159437499327086340U;
            aOrbiterE = RotL64((aOrbiterE * 4882100944453534805U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4304700511322366815U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10172544755256706767U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 4013006212154771797U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17340067939877432472U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14130447570008179105U;
            aOrbiterC = RotL64((aOrbiterC * 8178075071208718915U), 23U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 2652532710498072378U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10384945384238518296U;
            aOrbiterK = RotL64((aOrbiterK * 17137694272394304045U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 34U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 6U) + aOrbiterK) + RotL64(aOrbiterD, 57U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 30U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 41U)) + aOrbiterF);
            aWandererG = aWandererG + (((((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 14U) + aOrbiterI) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterB, 24U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterB, 53U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 24946U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((aIndex + 22831U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26578U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26610U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 54U)) + (RotL64(aIngress, 27U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (aWandererH + RotL64(aCross, 53U)) + 9023059520606551446U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 60U)) + 662441755115638133U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 16957253361196144712U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 7840955025765308605U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 346855809270395799U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 35U)) + 16099139781586668343U) + aNonceWordG;
            aOrbiterK = (aWandererK + RotL64(aIngress, 28U)) + 3706457327118322098U;
            aOrbiterA = (aWandererI + RotL64(aCross, 47U)) + 12166825885547622870U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 3U)) + 7792658665720344200U) + aNonceWordC;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7128477606152986326U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11116533962780290084U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 11993485572912492297U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10443889548568288532U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4402387036946561017U;
            aOrbiterI = RotL64((aOrbiterI * 9032964741841833277U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13002706161178447654U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 13929727277530310708U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 7005639090871200285U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10949073760696935106U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15405923432006783533U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17989565878445202495U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18096057968822208905U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3032155040484574973U;
            aOrbiterB = RotL64((aOrbiterB * 448597307502544605U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17462076466907467134U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15471015427013701406U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6113474000571976139U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3549031751266594344U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14243218483842508113U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9041601306479302047U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5803147589312920032U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5549470512227427855U;
            aOrbiterH = RotL64((aOrbiterH * 12592362489263862879U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10076661824293832189U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3196799148974716550U;
            aOrbiterA = RotL64((aOrbiterA * 8183276968961467775U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 18U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterI, 39U));
            aWandererF = aWandererF + ((RotL64(aIngress, 36U) + aOrbiterK) + RotL64(aOrbiterE, 50U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterB, 19U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterF, 57U)) + aNonceWordJ);
            aWandererK = aWandererK + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterC, 6U)) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 30610U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((aIndex + 28735U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31744U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 28228U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 19U)) ^ (RotL64(aCarry, 60U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 14214886793361825363U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 46U)) + RotL64(aCarry, 35U)) + 17267959031078766320U) + aNonceWordH;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 16436067429484887644U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 29U)) + 9885951769332633820U) + aNonceWordB;
            aOrbiterC = (aWandererA + RotL64(aScatter, 21U)) + 12971711341813893304U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 41U)) + 199970353398450154U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 35U)) + 1237341696444162094U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aWandererE + RotL64(aCross, 12U)) + 7991128854417613360U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 51U)) + 14809029847149045833U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2559509556915775947U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14336829730147834160U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15103242520064900873U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8853631886733610440U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13346159398673246914U;
            aOrbiterK = RotL64((aOrbiterK * 13660497151446983393U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12121095718571872976U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16239781125815589804U;
            aOrbiterE = RotL64((aOrbiterE * 5157009090454962231U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9051377033794324106U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13805815136723461780U;
            aOrbiterB = RotL64((aOrbiterB * 571129481747181357U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 14849157800322754413U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 18116651528452542634U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 3638480428016835537U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4105057226952948599U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 5911714320560994391U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1796514171654961389U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 4439149331729987587U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10278532228230163632U;
            aOrbiterD = RotL64((aOrbiterD * 17428224919864716517U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2342456582668741750U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2360578572554664800U;
            aOrbiterG = RotL64((aOrbiterG * 1108428466956691925U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12132934875391401246U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17213278726790245812U;
            aOrbiterF = RotL64((aOrbiterF * 11904899990681410419U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 24U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterC, 48U)) + aNonceWordO);
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterF, 39U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterG) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 12U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aIngress, 24U) + RotL64(aOrbiterE, 23U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterF, 53U)) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + aNonceWordJ) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererK, 6U);
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

void TwistExpander_Tennis_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD57FA94B0C37E9B1ULL + 0xD938C725E8306140ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x97E9005A7EA24A77ULL + 0xDFB19004A601E7B6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE4B3D76DC0704E7BULL + 0xA2DA39FC6ED70C0DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9C9433B50EB1677FULL + 0x9FC4C49CFE6187E3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA05AF6B559F0A9A9ULL + 0x973CE24A6FE274BBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA9343CD2F9A1DAE5ULL + 0x9A9D256D6B954063ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC895D819843AEF7DULL + 0xD560009145C0C144ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCD99E7EBE4370A3DULL + 0xD35C623C4C9A7ED2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9FFCFC23E28C0347ULL + 0xF2F0CDB7EB5CCEC6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x81B925A0676C144BULL + 0xA3581C3FAFCCE4BBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE1438CAC257258EDULL + 0x86F3C1DCCE9DE621ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9CE8AB2ADE9C0D1DULL + 0xA8B43F0EDF8BDEFFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD6BAF55E3C7F78F5ULL + 0xE372D3D771F73B0DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE7C2126470102CF9ULL + 0xCE773BC62509BA1AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8FBE59AA0CADCF93ULL + 0xAB043E5E7046258CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xED832590460A703BULL + 0x884C0F38612D9F25ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6501U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((aIndex + 2813U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7704U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7921U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6974U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5268U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 19U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 52U)) + RotL64(aCarry, 41U)) + 18087125778766689269U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 29U)) + 13710545066503235196U) + aNonceWordN;
            aOrbiterC = ((aWandererB + RotL64(aCross, 39U)) + 1701939704736254645U) + aNonceWordP;
            aOrbiterE = ((((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 8064093611384019909U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 16623332751533885431U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15590129153794910109U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7413312683079107383U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9496176571314516005U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 4186064478651458810U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5501191643940735954U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14254804649177125269U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11064645242200570835U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13825922087298055833U;
            aOrbiterD = RotL64((aOrbiterD * 7529317892716108867U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5944980709887369970U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8181136916070569646U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 395183021205661827U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15442336949157292482U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11580554435240641337U;
            aOrbiterI = RotL64((aOrbiterI * 6654637892858767739U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterI, 60U));
            aWandererA = aWandererA + (((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 39U)) + aOrbiterE) + aNonceWordA);
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 27U)) + aOrbiterC) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11919U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 13060U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13786U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12270U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15531U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15899U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 15322U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 28U)) + (RotL64(aIngress, 13U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 1708250618750199233U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aIngress, 4U)) + 12009147777553691142U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 8393982703399156592U) + aNonceWordN;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 3247327098356831221U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 57U)) + 3403590155376353737U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 18197244558104735044U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3096253642040701606U;
            aOrbiterG = RotL64((aOrbiterG * 6656168712438620783U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8012692688785412179U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17531946907545680745U;
            aOrbiterJ = RotL64((aOrbiterJ * 16510602981731506381U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 17687695944270225817U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16147773866007628769U;
            aOrbiterA = RotL64((aOrbiterA * 16926442582711557877U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 18244641303026196497U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8839160526348897457U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14268021129087663397U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 10599266240854068246U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2056723540756216155U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 13311591601230386375U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 56U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + aNonceWordD) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21721U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 17164U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 24344U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 21862U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24231U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17871U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 21063U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 12311607308490066301U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 13100864684740679846U) + aNonceWordM;
            aOrbiterF = (((aWandererD + RotL64(aCross, 19U)) + 13697304189274329704U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 58U)) + RotL64(aCarry, 21U)) + 9047976902871216732U) + aNonceWordO;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 27U)) + 2147897579538537888U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2072444829390996142U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2129307836981020908U;
            aOrbiterF = RotL64((aOrbiterF * 8065769537670939667U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10663145333751112064U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15019844390503785459U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 7442321463110790449U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5460865577557928142U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15806522559993224197U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8722932687972240099U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6361113778657833389U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 8306013884615042570U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8234258702656728667U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 4038420580499706912U) + aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11908091484457158973U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 3964111175645156719U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterF, 53U)) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 10U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterA, 27U)) + aNonceWordI) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 6U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 24999U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 25144U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 30948U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27213U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27004U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25629U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 32721U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 52U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((((aWandererK + RotL64(aScatter, 54U)) + RotL64(aCarry, 51U)) + 10336802574069791273U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 11U)) + 169025388197058936U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 6541354188379168846U) + aNonceWordJ;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 43U)) + 16223920526599306104U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 12756613707692514808U) + aNonceWordI;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5082475548176484035U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4907435526952698526U;
            aOrbiterA = RotL64((aOrbiterA * 1379692095754989215U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14236627073831834337U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11502511046130497584U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 3460330807286625917U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3679044835550219497U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11254838916686736746U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 47U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 10582608424233200966U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 10449735026385340313U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 7363770199734997411U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4628253464169957835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17664454668473204465U;
            aOrbiterD = RotL64((aOrbiterD * 4234720298731378527U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 60U)) + aNonceWordG) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            aWandererF = aWandererF + (((((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 21U)) + aNonceWordP) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 39U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Tennis_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD78D49F5BB51824BULL + 0xAA96FEAA1A884066ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD5D9E0052D1F1FDFULL + 0xDAC48141561D2950ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD667AE15F44ACDDBULL + 0xC74BFF99BD376817ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD499EFD99094C481ULL + 0xABEAED84E8A16136ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCD45A7EB345B6049ULL + 0xA1C90117AF891A7FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9D2E320140B2AEA5ULL + 0x87AC3CABC8C92DD2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBF45EC8F9B21D09BULL + 0xFF1A60397164BB2BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9CD116121097E247ULL + 0x97C3023AF6055306ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB460D9866A2C2B43ULL + 0xE89A9E0BA65FE196ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB84A73832B6376E7ULL + 0xD7CAA03EB34818C4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x81C38F3196EECA79ULL + 0x942823E5BB0A15A1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8990A88C0133939BULL + 0xB32FC24DB31D1C08ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9439321A18178857ULL + 0xA735A125764653ECULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF305F79A5F7C007FULL + 0xC36072FE4F65945BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA9C790C0FF0CA98DULL + 0xFC0FAF512BEF0566ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEB478C1B2B7D969BULL + 0xDB8ED77D5DF1AD95ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2670U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 3968U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4848U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2618U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7573U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 674U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 14U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (((aWandererG + RotL64(aIngress, 39U)) + 4980738603982643969U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 11U)) + 17660278413018470020U;
            aOrbiterC = (aWandererE + RotL64(aCross, 47U)) + 17598114429859543466U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 30U)) + RotL64(aCarry, 53U)) + 10993929335279994739U) + aNonceWordI;
            aOrbiterH = ((aWandererB + RotL64(aCross, 57U)) + 17967203122976322481U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 1872290205549034384U) + aNonceWordF;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 16607778671782810797U) + aNonceWordH;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4895226930754394376U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14960359005982301383U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8546231310054433721U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 9921642352377700630U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 893281964367208693U;
            aOrbiterJ = RotL64((aOrbiterJ * 2345509157333444217U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8232519988397858732U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4433022122758913407U;
            aOrbiterG = RotL64((aOrbiterG * 834240393225479419U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12689609831247168353U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 404535388957472176U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 14534020545479806593U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3349108201964013155U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4386449511297371730U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9596273264321140229U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14314587717949070586U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10923886625271054985U;
            aOrbiterD = RotL64((aOrbiterD * 7838969002623486809U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17634909585329833520U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2021301459918350372U;
            aOrbiterE = RotL64((aOrbiterE * 1388242915918642741U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 27U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 26U)) + aOrbiterC) + aNonceWordG) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 20U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 11U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11224U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 12967U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 11570U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8752U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15697U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9402U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 11791U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 54U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = (aWandererD + RotL64(aCross, 3U)) + 12535417189990029950U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 46U)) + RotL64(aCarry, 41U)) + 6204401443676390273U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 29U)) + 869613505613154672U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 23U)) + 15053590879563855802U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 13338989605204591428U) + aNonceWordO;
            aOrbiterD = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 18306470022403825392U) + aNonceWordJ;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 35U)) + 1150696349434090218U) + aNonceWordP;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13549541786420596437U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 14302878430259588461U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 16813606782134305513U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4660437084477165225U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1653628537860912069U;
            aOrbiterG = RotL64((aOrbiterG * 2624835201155303123U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5594199757006711631U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11008472193138708891U;
            aOrbiterI = RotL64((aOrbiterI * 13645764762027798301U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3668516817279364310U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 128159531749679984U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4523246859249826987U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6378674346113979108U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 11438762460659123362U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 2733309638158283953U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10624263004446482910U) + aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12546839706919241411U;
            aOrbiterK = RotL64((aOrbiterK * 11468326687628079347U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8466639576503293921U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5828694979857951504U;
            aOrbiterD = RotL64((aOrbiterD * 7835487310289634515U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 21U)) + aOrbiterB) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterB, 41U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 57U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 28U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 27U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20535U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 22228U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 20589U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 22297U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22378U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16944U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 23513U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCross, 47U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((aWandererI + RotL64(aCross, 43U)) + 6654158889644956636U) + aNonceWordD;
            aOrbiterC = ((((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 9045779659363991870U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 26U)) + 3888897662136993491U) + aNonceWordB;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 5U)) + 6882016842864459345U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 37U)) + 15601891715956172291U;
            aOrbiterF = ((((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 5176811598629335350U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 12519945150889074325U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 4552583214397603278U) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 14225482701804864688U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8526052833180466359U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5485298070606280363U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11237713257388094289U;
            aOrbiterC = RotL64((aOrbiterC * 11032429223099413011U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14340345895626142788U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16275167270553643347U;
            aOrbiterK = RotL64((aOrbiterK * 7308578867128951199U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14041860597556520250U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1436068974197066343U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3938460345031496843U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11483155566419547004U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4608508534724289325U;
            aOrbiterF = RotL64((aOrbiterF * 13461385011638899485U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2389196334288832895U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4062682330273866602U;
            aOrbiterJ = RotL64((aOrbiterJ * 8787682133271101901U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5655656046585592034U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7977947821249746880U;
            aOrbiterB = RotL64((aOrbiterB * 10082104644185964787U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterB) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterI, 54U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + aNonceWordJ);
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 21U)) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterK, 29U)) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 52U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26957U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 25802U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 31149U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30918U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26523U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26532U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25799U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 35U)) + 13278949403988203974U) + aNonceWordN;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 37U)) + 9213599924054673756U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 5U)) + 1255746482932381798U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 11U)) + 11575321997144516122U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 15881587525529432437U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 9846195809864862707U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 29U)) + 12319815691858217670U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16322617427294439587U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16332130810525887437U;
            aOrbiterH = RotL64((aOrbiterH * 7588076439690559343U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4920951156015336794U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16767126455124552329U;
            aOrbiterK = RotL64((aOrbiterK * 4440352337076842603U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12553595911087945223U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1437522202135436142U;
            aOrbiterI = RotL64((aOrbiterI * 2001992794165550905U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12313100454852227143U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2761983020631055729U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3874839760378039509U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17635303588421554367U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 788212489507463763U;
            aOrbiterC = RotL64((aOrbiterC * 17896475584538528059U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5192552894670654434U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6784748488807738811U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 8077237651953896479U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 16113417046719114943U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1096874945215225916U;
            aOrbiterF = RotL64((aOrbiterF * 17308604412622879833U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + aNonceWordK);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterA, 48U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE + (((((RotL64(aCross, 13U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 39U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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

void TwistExpander_Tennis_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x85D10EB3D72D014FULL + 0xEAAD1F94CCEF5FD9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA73C865EA9EB6AC7ULL + 0xE2C0B1945D553569ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEBD6423B34234C19ULL + 0xFC32F8772836AEC6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xABC213FF1A6FEB67ULL + 0xDC66F8CB0E4C5575ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFAAA87B46D805A93ULL + 0xC9DACC1089BF31C1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE0B135C9CF80A243ULL + 0xFB36FA731659D304ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD4215CFA6D075025ULL + 0xD8B5F766220EA57BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC5E8AA6DA732E5C1ULL + 0xF828A715E52FC924ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x84D4453C404AB35BULL + 0xF88DF48DC846147BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEC7E7365703FF999ULL + 0xFCDBEA0CCC23D21BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x811B4564424E5527ULL + 0x8261D7BBA88D93DBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF106BEAED7BF8DB1ULL + 0xC60DC66F3DEF92AAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE15F46A53E192257ULL + 0xFD9525F329D24D3EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEDB0765D3E3ABB99ULL + 0xD456C6749C652FE7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEC39C9D03B75CE89ULL + 0xE4FF4D012A588814ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB459FBA259590315ULL + 0xEBAFEB01724897E7ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4564U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 4989U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 3951U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 848U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1050U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 27U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 701291026547470433U;
            aOrbiterC = (aWandererA + RotL64(aCross, 53U)) + 17283292650462111643U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 9969124091931303406U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 5U)) + 889176772718046988U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 12U)) + 6054541844643748084U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 47U)) + 14703226235143028132U) + aNonceWordJ;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 7977975878522921062U) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16894322614172266274U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12160451749345900570U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 18055355572903901749U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10870847008043897470U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8159920947172520247U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4833194641611011805U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2440099120969517932U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2428396147731468007U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 9363073341539598441U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2213226274394673479U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7079731443427765333U;
            aOrbiterB = RotL64((aOrbiterB * 16918930776877030559U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 958896789550478970U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10788682955708075458U;
            aOrbiterH = RotL64((aOrbiterH * 913321215613559729U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 2003386579317564870U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8419686358774204999U;
            aOrbiterC = RotL64((aOrbiterC * 6547052526438697621U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6989167615157578904U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17636634003643824148U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 11038576417283732937U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aCross, 40U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 57U)) + aNonceWordK) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 41U)) + aNonceWordB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 50U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 5910U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((aIndex + 10732U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5575U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10193U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8876U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 10161U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 18U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 6467297102954816305U) + aNonceWordF;
            aOrbiterH = (aWandererI + RotL64(aScatter, 46U)) + 7921154109831114952U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 5701131763215638919U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 10022999076719002684U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 39U)) + 4367135243038982316U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 19U)) + 14445846824810383592U;
            aOrbiterF = (aWandererE + RotL64(aCross, 57U)) + 7683697954545773253U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17517006750428030899U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2052484792684025476U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12463117571122469643U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6279463052085808926U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 679280153651813684U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 3047031560593583881U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2939516520188460569U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1960616434964712325U;
            aOrbiterK = RotL64((aOrbiterK * 15145998415466343039U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12273819390719947361U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 5685033154709449397U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 9845666295874714959U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9314494172199500653U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15757631834636427621U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15483543888965744529U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10878078046389399574U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3583495913766365232U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2913540984990155225U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7385544065754622301U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16839599460207922881U;
            aOrbiterJ = RotL64((aOrbiterJ * 240651605910592561U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 12U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterA, 5U));
            aWandererF = aWandererF + ((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 35U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterF, 18U)) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 11799U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 15461U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12088U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16147U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneA[((aIndex + 11598U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (((aWandererK + RotL64(aCross, 6U)) + RotL64(aCarry, 29U)) + 1297415699043177788U) + aNonceWordH;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 13U)) + 17583786534509260153U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 41U)) + 643197858925708798U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 21U)) + 5062653766915694874U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 7034273638367180511U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 29U)) + 2026909726972916996U) + aNonceWordL;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 2785690475553211646U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2910341716302991892U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2834181605200829791U;
            aOrbiterJ = RotL64((aOrbiterJ * 1510617068750957651U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 13323052600571281928U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10434901530315760460U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2042210188346767033U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 247903955625194782U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5196515747387257163U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1799024689023272275U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7196305682377987476U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14777739876892587484U;
            aOrbiterH = RotL64((aOrbiterH * 95220583948241581U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10609060796540136671U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8386027207212484155U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 4855610536246556893U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 729659744301903424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2350564261412606157U;
            aOrbiterB = RotL64((aOrbiterB * 16713856782349084977U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16611987556673864177U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1525195188708550503U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 10045858602151004553U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 6U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + aNonceWordC);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + aNonceWordF) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 36U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterG, 13U));
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterB, 53U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21543U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 17502U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 19238U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16689U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneD[((aIndex + 19682U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 24U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 35U)) + 12692813903177772178U) + aNonceWordE;
            aOrbiterB = (aWandererA + RotL64(aScatter, 5U)) + 7112496446691277899U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 21U)) + 2112247138290568813U) + aNonceWordH;
            aOrbiterI = (aWandererJ + RotL64(aCross, 53U)) + 3699421080882855947U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 47U)) + 13761832028354380922U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 11U)) + 9243822514887600214U;
            aOrbiterD = ((((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 6863833516853046129U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8863897995943098018U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 13346785686701467520U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 18074843497158380703U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15309543066305531619U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17515530938817919111U;
            aOrbiterI = RotL64((aOrbiterI * 16625193986319048245U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 760493237816424254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7282586354117620860U;
            aOrbiterA = RotL64((aOrbiterA * 2327153408185290635U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4129706068526969105U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7020175432730888755U;
            aOrbiterB = RotL64((aOrbiterB * 10095158356907592239U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9102258982216515596U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10822031305361453690U;
            aOrbiterE = RotL64((aOrbiterE * 2036205056490578491U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12571477440964330246U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8436347026653095199U;
            aOrbiterK = RotL64((aOrbiterK * 17930734781213681573U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14214789872073941940U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12915911919403385001U;
            aOrbiterD = RotL64((aOrbiterD * 13161681603528031511U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 50U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 11U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterA, 4U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 21U)) + aOrbiterD) + aNonceWordC);
            aWandererD = aWandererD + ((((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 41U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordK) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 23410U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22898U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27252U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 21959U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 4739486756133131180U) + aNonceWordH;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 16089707555501328184U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 15310047330238536453U) + aNonceWordM;
            aOrbiterG = ((aWandererC + RotL64(aCross, 41U)) + 7901411596386834955U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 56U)) + 4357555491060982163U;
            aOrbiterI = (aWandererE + RotL64(aCross, 35U)) + 15667085602825720102U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 27U)) + 8520635334382269253U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 1772509779231068315U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15336170957886025677U;
            aOrbiterA = RotL64((aOrbiterA * 10996880551392077399U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8628770833489469980U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15469234024247246228U;
            aOrbiterJ = RotL64((aOrbiterJ * 8905266995119987947U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10796430900884288328U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10660110397012853289U;
            aOrbiterK = RotL64((aOrbiterK * 9140007610912037461U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11202284258711214794U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17509491802893182994U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 9329107599972703671U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16212572740740103554U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2190030203761579226U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3101886685668871045U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12014337082293041909U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3733531010807001506U;
            aOrbiterG = RotL64((aOrbiterG * 5797362244066062299U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7100994963061975529U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17837541162838600258U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8745987361678166553U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterD, 58U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 18U) + aOrbiterJ) + RotL64(aOrbiterI, 27U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterF, 58U)) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 27903U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 30017U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27340U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 31730U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 40U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererJ + RotL64(aCross, 41U)) + 15036852811491820366U) + aNonceWordI;
            aOrbiterD = (aWandererD + RotL64(aScatter, 13U)) + 305637140752898475U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 58U)) + 11948631574496129610U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 3U)) + 5321623592482991426U) + aNonceWordM;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 4075270159062690728U;
            aOrbiterE = ((((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 15111580500356908928U) + aOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 7244150695504160363U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5131563519577488862U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5881954992088651371U;
            aOrbiterB = RotL64((aOrbiterB * 2424421828597294607U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12780935808751507998U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12599159643925470226U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17690046932587062701U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9466589929741834066U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6093158735705189789U;
            aOrbiterE = RotL64((aOrbiterE * 7453778295800853653U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17461243886150519249U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15456408913739900718U;
            aOrbiterI = RotL64((aOrbiterI * 16093292401746174671U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11260643903290392780U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 7870342756041882616U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 2431528656086173419U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 134484990005888936U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10626896209992890407U;
            aOrbiterG = RotL64((aOrbiterG * 12034131076645285597U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 14031164129515132292U) + aNonceWordK;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 1771835705730244212U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 186981668443596623U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 54U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + aNonceWordO);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterE, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Tennis_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9499CD1C4D63E16BULL + 0xED86FF4D7D37C910ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC86713DD27B56471ULL + 0xB52965AD4FEE2C7FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC8709C824940C7C5ULL + 0xE5EFB3ABA1B15676ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDB5BC7709404B8D7ULL + 0x8AB5CE494EC95B01ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDA28DE1490332C7FULL + 0xDDB73249B1B93497ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xABA79768912DD2B9ULL + 0xE00D669EA6D37D54ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x942B570230530C33ULL + 0xEFAB9A7C1306A5EBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCA3F0565EF136007ULL + 0xC43DEEB47D1E93DEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x990E62323B917CC5ULL + 0xCAC856E457B798C8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA38314C242E9B0A5ULL + 0x962B36BB306A42F2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC1F91375D9FF5C45ULL + 0x8422A20743298189ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x95556C01C4614575ULL + 0xFA7D0CE281CD8197ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE7E8450B190D508BULL + 0x94E41743341F17D1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9E13294D205AC857ULL + 0xAC5B63BA47B7CBF2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x855A840E6ACD7A29ULL + 0xADD1197A0950A622ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFAC4226DD28D0469ULL + 0xB5B8A7965FD22A49ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7493U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 7887U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 518U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2977U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4747U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1206U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 37U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 26U)) + 1898718075389870739U) + aNonceWordG;
            aOrbiterK = (aWandererA + RotL64(aCross, 19U)) + 5631794889237247403U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 18219714659484524607U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 39U)) + 15419581386225732921U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 22U)) + 9125575431710198210U;
            aOrbiterC = (aWandererF + RotL64(aCross, 41U)) + 12205871520544965505U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 7617534300497343422U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 18017579105368135814U) + aNonceWordK;
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 10693882161946020042U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 5U)) + 11669615701700895306U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 53U)) + 11045110212889232165U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18019107802806469913U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12315940560472528716U;
            aOrbiterH = RotL64((aOrbiterH * 4505122470351404065U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4899009736070044310U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17412253404253730364U;
            aOrbiterG = RotL64((aOrbiterG * 10791901166391946485U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4826286251927854181U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4523455921321845084U;
            aOrbiterK = RotL64((aOrbiterK * 14534103906736598099U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4132514462154182215U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7164745605985109269U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 14107325508977225261U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6297434295807635654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8813887638672996646U;
            aOrbiterC = RotL64((aOrbiterC * 17495632530773158201U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11086381278955626084U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5660733992573928887U;
            aOrbiterI = RotL64((aOrbiterI * 11248164458720777889U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14851044686208609882U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12707776386060264479U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 4470919091467313071U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11508023384209716657U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11752973809740920034U;
            aOrbiterB = RotL64((aOrbiterB * 10212754472298834769U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16746821150860017820U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9659421716296641396U;
            aOrbiterJ = RotL64((aOrbiterJ * 7530071874978553673U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3192309064305104593U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11409078048681398061U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14991409124701807765U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 315359495275427324U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1898718075389870739U;
            aOrbiterE = RotL64((aOrbiterE * 13126661894614781343U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 60U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + aNonceWordM);
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterD, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterA, 13U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterD, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterG, 53U));
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterI, 4U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + aNonceWordO);
            aWandererG = aWandererG + (((((RotL64(aScatter, 52U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aNonceWordC) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterB, 39U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10231U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 10008U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 12548U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13529U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10396U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12442U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16264U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 10U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (aWandererI + RotL64(aCross, 27U)) + 701291026547470433U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 17283292650462111643U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 39U)) + 9969124091931303406U) + aNonceWordD;
            aOrbiterD = (aWandererC + RotL64(aScatter, 24U)) + 889176772718046988U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 6054541844643748084U) + aNonceWordC;
            aOrbiterC = (aWandererH + RotL64(aIngress, 21U)) + 14703226235143028132U;
            aOrbiterK = (aWandererF + RotL64(aCross, 43U)) + 7977975878522921062U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 46U)) + 16894322614172266274U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 11U)) + 12160451749345900570U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 10870847008043897470U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 19U)) + 8159920947172520247U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2440099120969517932U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2428396147731468007U;
            aOrbiterI = RotL64((aOrbiterI * 9363073341539598441U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2213226274394673479U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7079731443427765333U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16918930776877030559U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 958896789550478970U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10788682955708075458U;
            aOrbiterK = RotL64((aOrbiterK * 913321215613559729U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2003386579317564870U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8419686358774204999U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6547052526438697621U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6989167615157578904U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17636634003643824148U;
            aOrbiterH = RotL64((aOrbiterH * 11038576417283732937U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13824962118933907859U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9543912892587859646U;
            aOrbiterE = RotL64((aOrbiterE * 14736710162285997415U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15729878041027706114U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9542137475454825463U;
            aOrbiterG = RotL64((aOrbiterG * 11420547128115090491U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5327302277575009955U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2707383132257428583U;
            aOrbiterB = RotL64((aOrbiterB * 6120763309390182129U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9008601903853562620U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11050463189491777908U;
            aOrbiterF = RotL64((aOrbiterF * 9178386878636430553U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14683684132116778056U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5390271065690907120U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 17903005409098232619U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5183407290520277451U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 701291026547470433U;
            aOrbiterD = RotL64((aOrbiterD * 16329261100139524239U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 13U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aCross, 30U) + aOrbiterA) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterA, 23U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 50U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterF, 43U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterC) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 39U)) + aOrbiterB) + aNonceWordN);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 21U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterD, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20884U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 20343U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 20050U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 21401U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22711U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20400U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 19523U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererB + RotL64(aScatter, 21U)) + 5173905450211892891U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aCross, 5U)) + 3555542451908039957U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 53U)) + 11559884700283861559U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 1352524329968738673U) + aNonceWordC;
            aOrbiterG = (aWandererE + RotL64(aIngress, 60U)) + 8914206450420616349U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 23U)) + 2251523378498463946U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 9541575923299247038U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 43U)) + 1239854507907214595U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 57U)) + 17698101462598498934U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 12305566971683256060U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 40U)) + 13804545036303215569U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10239749097704329264U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4212214906286320308U;
            aOrbiterK = RotL64((aOrbiterK * 3661436621615751071U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12192418916967430783U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 4475514289326450361U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17497164630368757887U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 17376102613298827459U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 18129393209955439341U;
            aOrbiterC = RotL64((aOrbiterC * 6404089025014118979U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4014763724300253568U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17325007199676828814U;
            aOrbiterE = RotL64((aOrbiterE * 1420888274815627083U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15480474849292388685U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14357924730184375449U;
            aOrbiterJ = RotL64((aOrbiterJ * 16723492259068034209U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4335731868597970070U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8296023680394303015U;
            aOrbiterB = RotL64((aOrbiterB * 14027415401430120543U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2807312426993262800U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15510369660839648501U;
            aOrbiterI = RotL64((aOrbiterI * 18207954408298333959U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12597844696606519907U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 7231012798553551535U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2841306785994479299U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 849663631945232360U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4002310581470781194U;
            aOrbiterH = RotL64((aOrbiterH * 2148877014350721479U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16067735571435654555U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4607980694199923842U;
            aOrbiterD = RotL64((aOrbiterD * 10401780756830017477U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5346879191913449715U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5173905450211892891U;
            aOrbiterF = RotL64((aOrbiterF * 15360571827429301833U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 28U);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + aNonceWordL);
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterD, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 26U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 47U)) + aOrbiterD) + aNonceWordO);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterD, 29U)) + aNonceWordH) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterI, 57U));
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 60U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31656U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 30999U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 29133U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 27702U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29593U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27045U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 29280U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 43U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (aWandererJ + RotL64(aCross, 13U)) + 8375305456876489425U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 11U)) + 16193562952772453047U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 18U)) + 18088652458594816223U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 767344788620249944U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 7705194930396368752U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 21U)) + 3829736891311272834U) + aNonceWordI;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 51U)) + 9881681671347640061U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 53U)) + 1721196560190164264U) + aNonceWordN;
            aOrbiterD = (aWandererF + RotL64(aScatter, 23U)) + 3002652618388454213U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 38U)) + 9811621464004005202U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 5652598941069986530U) + aNonceWordP;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6250499348327316328U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16025054277615264530U;
            aOrbiterK = RotL64((aOrbiterK * 16446892258704281903U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13800298546867243172U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12256104592865905782U;
            aOrbiterB = RotL64((aOrbiterB * 16983140179497142713U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17817225416918329229U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17738671327352776217U;
            aOrbiterF = RotL64((aOrbiterF * 393488251327705063U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6816031224188400541U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16989563985059237014U;
            aOrbiterD = RotL64((aOrbiterD * 8677884225771717797U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16891524847268207549U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1833508573940405571U;
            aOrbiterI = RotL64((aOrbiterI * 9709196587703979539U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12729999421507068973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6839758643521968957U;
            aOrbiterE = RotL64((aOrbiterE * 16350557395881283975U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8524167125469267428U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 14741523560290472617U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4367850822282205897U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10983798459868424892U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5649250846622078964U;
            aOrbiterH = RotL64((aOrbiterH * 7149612714806023987U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 8587302028325090061U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17457129226030333666U;
            aOrbiterC = RotL64((aOrbiterC * 18107356450566915215U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15600113588474915690U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6595247491374683783U;
            aOrbiterA = RotL64((aOrbiterA * 1432432381540098765U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13246325856585534283U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8375305456876489425U;
            aOrbiterG = RotL64((aOrbiterG * 8331406038795786099U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 54U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 26U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterK, 56U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 37U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 10U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterE, 18U));
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 5U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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

void TwistExpander_Tennis_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA9F593410949FD53ULL + 0xAC5700A5BF745B0FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC7D69B8C9E499501ULL + 0xCC7767DD78CEDE24ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9D11754A8B219471ULL + 0xC2E623A5EE2781F5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCD8AD7C92D5E1449ULL + 0xCBF6E38A286E2F73ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9667E19471C92087ULL + 0xEDFE7890F5EBE648ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF23E9C63581041A7ULL + 0x85D344E068645C57ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF542723C0F24B80BULL + 0xEB1F2154AF88993AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB595BF83A674D231ULL + 0x91058CBA1A4A80C8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD1EDABA6BF219997ULL + 0xC6666AE8EB38712FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x974EAE7380A8DDA5ULL + 0xB26CD1985D3CEBCEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDB81CE37614A2CE3ULL + 0xB02A888E128E4234ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA9BD174FD1267CE9ULL + 0xB1E0D0EE9F25DEA5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD7E39B3A11E15C07ULL + 0xD4A2966170548192ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAE299A76BE1A3F15ULL + 0xBC6C45F689E02BA7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC89821E4F7B6FBC1ULL + 0xEDF19C7D5F8F12ECULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA89F86808C67FC69ULL + 0xD297B80E6DCE0845ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7438U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((aIndex + 3919U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5100U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6141U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 976U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1073U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 10U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (aWandererI + RotL64(aCross, 19U)) + 8604208734152026945U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 58U)) + RotL64(aCarry, 29U)) + 1374329953253889829U) + aNonceWordP;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 5779278910548228339U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 13U)) + 17670451230882805140U) + aNonceWordM;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 5U)) + 8193848740764866860U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 15801168428145650104U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 23U)) + 2584718176087499066U) + aNonceWordA;
            aOrbiterI = (aWandererG + RotL64(aScatter, 38U)) + 14950366247822737997U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 51U)) + 9779293225265670135U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8688968319288372383U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13665723186950342601U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 292035540396910837U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 9395428688359973510U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2152719218018108418U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 15271961483518392671U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1350324137411377992U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8729317951386057921U;
            aOrbiterH = RotL64((aOrbiterH * 6008790836417785083U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6317310451893678411U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10175620379041384281U;
            aOrbiterI = RotL64((aOrbiterI * 14079679617394330781U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1203082119358827708U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 523869107818193101U;
            aOrbiterE = RotL64((aOrbiterE * 4629501113595689157U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4028324959540432983U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15447631947468213912U;
            aOrbiterC = RotL64((aOrbiterC * 6037306615787729185U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14225888694733041031U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11925000696281947629U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4337022940520411253U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 15015531024930608745U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16752579225076943550U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 15551083683579981439U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2432733494869267901U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10103430321388601485U;
            aOrbiterD = RotL64((aOrbiterD * 18372919379972432569U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 44U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterD, 13U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterC, 6U)) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 56U) + aOrbiterE) + RotL64(aOrbiterK, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 41U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterE, 60U)) + aNonceWordF) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 50U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11043U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 14286U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 15628U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12125U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13120U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9984U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8403U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 22U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = (((aWandererC + RotL64(aIngress, 30U)) + 6024062041314952357U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 18340757093658015585U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 35U)) + 11911120493880346751U) + aNonceWordB;
            aOrbiterB = ((((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 17428074353884654439U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 19U)) + 12790849760814795936U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 47U)) + 12633397052172117800U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 40U)) + RotL64(aCarry, 35U)) + 11946150433665237945U) + aNonceWordM;
            aOrbiterG = (aWandererE + RotL64(aScatter, 13U)) + 16842157900909419285U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 23U)) + 14186235783224155962U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13284904542579767591U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11609181965078844357U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 5455780554452453513U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9628562297095374984U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7850281529011259759U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 17611485102925470357U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 257458718073794527U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10693404545773519306U;
            aOrbiterA = RotL64((aOrbiterA * 14821443722828498323U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3430519236533871460U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6183054506953198055U;
            aOrbiterJ = RotL64((aOrbiterJ * 6121082743789970911U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2905610989884221654U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4472163910775333862U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7770678426310856745U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16870142883133769663U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1403692060594816451U;
            aOrbiterH = RotL64((aOrbiterH * 9740854430251597879U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16904169913507057108U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4773518591580333357U;
            aOrbiterB = RotL64((aOrbiterB * 5306070307776061267U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6528141733853494275U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11254806909313951442U;
            aOrbiterI = RotL64((aOrbiterI * 6316669786405548827U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6857506858448143407U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2855763534355983644U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 16881334940165182415U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 54U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 52U)) + aOrbiterG) + aNonceWordA) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aCross, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 6U) + aOrbiterH) + RotL64(aOrbiterE, 43U)) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 5U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 12U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 37U)) + aOrbiterA) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 36U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17161U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((aIndex + 22714U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 22482U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20628U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21878U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20112U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 19705U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 8793908991006073956U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 57U)) + 2932916283348441943U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 29U)) + 11069042087940968262U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 12U)) + RotL64(aCarry, 21U)) + 14369628676782894441U) + aNonceWordL;
            aOrbiterB = (aWandererB + RotL64(aIngress, 43U)) + 8602903272780978282U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 39U)) + 3827036107178568820U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 47U)) + 8905245209036772489U) + aNonceWordC;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 13331387530760017893U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 34U)) + 9880107580289737823U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10199619040626900278U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2466307560891374281U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 6295342978834217571U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13973403407981259448U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2851460278409385243U;
            aOrbiterB = RotL64((aOrbiterB * 11226902976321781743U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10365453393815690776U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2382382358987358791U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 481563628980705781U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5058198848163792422U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10500434740387593487U;
            aOrbiterI = RotL64((aOrbiterI * 5946747708776079787U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11289798395177667084U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14327152153231286666U;
            aOrbiterD = RotL64((aOrbiterD * 18155778059595245561U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8065137263811956313U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3865153574847924816U;
            aOrbiterJ = RotL64((aOrbiterJ * 9495741102667755161U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 18102279969722473375U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6306428427188742325U;
            aOrbiterK = RotL64((aOrbiterK * 17826782872351406167U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16953348204663693724U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11950791817032898613U;
            aOrbiterF = RotL64((aOrbiterF * 1498946055469611133U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11980823193543752994U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17845490308799454871U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16385153013485463791U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 6U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 39U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 56U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 24U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + aNonceWordP);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 13U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 20U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26336U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 28670U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 28471U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 30000U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27123U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32345U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 31070U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 5U)) + 9080426856729228705U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 7851218321653539276U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 44U)) + RotL64(aCarry, 51U)) + 7023344692919298036U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 19U)) + 9772846154227440734U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 23U)) + 12008298632429608431U) + aNonceWordM;
            aOrbiterC = (aWandererC + RotL64(aScatter, 27U)) + 12201090455849562875U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 11U)) + 9498721803411445471U) + aNonceWordK;
            aOrbiterH = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 351203764023093632U) + aNonceWordC;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 60U)) + 4966360430644539250U) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9194167899071345693U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4922477697284269116U;
            aOrbiterB = RotL64((aOrbiterB * 8444814161720407881U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15742625291642356429U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7528703106518431730U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11530049278751507567U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15279053574704935317U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2425839793660355555U;
            aOrbiterH = RotL64((aOrbiterH * 11486964816849830667U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13209849392400008898U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9041500097716231309U;
            aOrbiterD = RotL64((aOrbiterD * 340661035700748739U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7885423750878814599U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 1992993999902904603U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 1478629826632201617U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6120758615019314102U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8529621625846992066U;
            aOrbiterF = RotL64((aOrbiterF * 8485991471612862467U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9125182130757385320U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15691232622970220043U;
            aOrbiterE = RotL64((aOrbiterE * 16517916951054758147U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 11413090085435424697U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11563151001080914939U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16828196274450408201U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1778975369262558069U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3232132443557192010U;
            aOrbiterJ = RotL64((aOrbiterJ * 17132823737792200981U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 34U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 4U) + RotL64(aOrbiterF, 24U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 11U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 51U)) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aCross, 42U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 30U)) + aOrbiterF) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererG, 26U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Tennis_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC910E25EC629F37BULL + 0xFCE8898F1A15005CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAED605A3DD0E69CFULL + 0xEC654D259047E25CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD93257455042D573ULL + 0x84047E3D078A27EFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDF122EAF895461BBULL + 0xA4019F08920A3160ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD0680EBF5ECC6B63ULL + 0xA4906DE8C6E60490ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBF2CCAE409588023ULL + 0xF0CF631627C0A8D3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9D4B81C91AAC8961ULL + 0x84CDD98B19DED318ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA697B39ED0CE7D55ULL + 0xB02AEB5C784701FEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC73E63B150961131ULL + 0xAD7F55E0E0D6E616ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC007A199E6F71E39ULL + 0xA74AE5552F2104E7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB5A4271DAE388645ULL + 0xF69E336CFFF8E65DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAC04EBA37B4CE8F3ULL + 0x81BB343E69AF8B6FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD4A18E240865A361ULL + 0x9BA1A1F176B2C1C1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9822E283E5C015A5ULL + 0xB1CA4E97755A6F3BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA9017E9CD5EB8D55ULL + 0xF11A1BE17AE3B178ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8E596CEFA030B2CDULL + 0xE7AA4FD5B3A93C8BULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1587U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 7958U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2212U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7913U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3529U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2687U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 54U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 2571116506511057880U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 13U)) + 13112435411509707292U) + aNonceWordH;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 10403251762787357256U;
            aOrbiterI = (aWandererE + RotL64(aCross, 35U)) + 8461951095541400405U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 29U)) + 9890793478557463815U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 56U)) + 3030229465991783707U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 7273848154043719247U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10681774862516028276U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7105082755586853104U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12217705329504230357U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6588579345319551129U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14616333550242386092U;
            aOrbiterB = RotL64((aOrbiterB * 2934574715879306337U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 15439666290229654921U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3360304356760164799U;
            aOrbiterC = RotL64((aOrbiterC * 5164191920584106237U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14438730801970761889U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14515616787452085729U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2041601927968559821U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4167853822635132419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8950982233003320239U;
            aOrbiterD = RotL64((aOrbiterD * 887144270884244907U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 12391327853728029953U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7100871010552394421U;
            aOrbiterF = RotL64((aOrbiterF * 16552349374101955967U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15381697462381887944U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6801677551341079401U;
            aOrbiterI = RotL64((aOrbiterI * 13325954438427340703U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterC, 39U)) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 40U) + aOrbiterB) + RotL64(aOrbiterC, 53U));
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 4U)) + aOrbiterA) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12357U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 10755U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 10888U)) & S_BLOCK1], 34U) ^ RotL64(aFireLaneC[((aIndex + 10937U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12247U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15669U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8425U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 5U)) + 2330952702412094686U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 13U)) + 7820188225935060799U) + aNonceWordL;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 21U)) + 9347644591709839145U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 2288624878446846870U) + aNonceWordI;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 9358977729492824128U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 1858511275052455039U) + aNonceWordO;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 60U)) + 13715478509322292552U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16413396625604260455U) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17714322215518432705U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1904184102419934333U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16188315436202861122U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5564445841368207813U;
            aOrbiterG = RotL64((aOrbiterG * 14125834616162835983U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13717068949900594673U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14143659432287313765U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17281441046722262917U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5729546141908425670U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4297827922736712074U;
            aOrbiterI = RotL64((aOrbiterI * 13631630436759768885U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 829520109395163673U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 11547160328525174295U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4759690159673049775U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2907177944512117206U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11100346409065275671U;
            aOrbiterE = RotL64((aOrbiterE * 17927994356809011637U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1344592529249949068U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 6470438516791143572U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 13339390828725370475U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterI, 13U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + aNonceWordB);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 44U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17373U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 19674U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 16409U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19646U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20171U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 20895U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18722U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 38U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 5568146815535263910U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 28U)) + RotL64(aCarry, 13U)) + 7736084960873834666U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 11U)) + 1336413621817562093U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 5218462026934984692U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 19U)) + 7048890985969555935U) + aNonceWordK;
            aOrbiterA = (aWandererB + RotL64(aIngress, 3U)) + 13415955213864702118U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 43U)) + 5657023257021528548U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 14338310943137497116U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12305161641833950473U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11949964304435964395U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 14514226578370459131U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12692904083266024340U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14800805065279908839U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11012959130001327964U) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7106471380403489078U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 515626559384817223U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3718101961355280891U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13364192077222322664U;
            aOrbiterG = RotL64((aOrbiterG * 1411328915372590283U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6720867800318913440U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14497243926965866546U;
            aOrbiterJ = RotL64((aOrbiterJ * 13595058589060114653U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5789056168233262435U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14438482587495779937U;
            aOrbiterK = RotL64((aOrbiterK * 10593535547917767263U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 313917798940179945U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15241845511889502917U;
            aOrbiterA = RotL64((aOrbiterA * 16483477103771326107U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 4U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 14U) + aOrbiterC) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 57U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 41U)) + aNonceWordC);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 34U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31459U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 29456U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 30240U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 32099U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29200U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24801U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26537U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 13442819395490639310U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 57U)) + 8187292523194120936U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 36U)) + 11469697159823131388U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 3U)) + 13414083692375929653U) + aNonceWordK;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 19U)) + 11404010733687907517U) + aNonceWordH;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 6783212827186218247U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 8561131439340372614U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6252609642004429113U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12804867444200448952U;
            aOrbiterH = RotL64((aOrbiterH * 3114688959081972615U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2739648749603690781U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14808861217017399752U;
            aOrbiterF = RotL64((aOrbiterF * 373911885694012101U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 17588866502571268888U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5882260142735642980U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 7688252946143263869U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15493099088132862949U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5175647411532429582U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15226544495598541883U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14279707376173642767U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6826363572161275158U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 5263708315440161809U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13267185753040999992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9980987858092888720U;
            aOrbiterC = RotL64((aOrbiterC * 13210290848800728635U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3582972937645514549U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10140409019562890804U;
            aOrbiterI = RotL64((aOrbiterI * 6944490201647678479U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 19U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterK, 40U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + aNonceWordI) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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

void TwistExpander_Tennis_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDC7B206115407949ULL + 0xB10DF51722FF269AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA0C8BF804D78FEC1ULL + 0xEB3A27ABDA8B3F52ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCB2BF112535CB2BDULL + 0x948212C603AAE654ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE1E442F6D00ED7EBULL + 0xDE5E9BB02326F132ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x93206EB4B0206409ULL + 0xBAF654C3D1334396ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD70FA21DAB2B3B47ULL + 0xB894D8F3A29ED3ADULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA01EFBCAD084750FULL + 0xA4BF05C66C0A98D2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF38D9E86D83DF1F7ULL + 0xC08D7AB5117BF9F2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x85F0A920E0C06DCBULL + 0xE8E307B1A25E79CBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA0E86F4993F19863ULL + 0xD56F5150232C31FCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x89203F88F15F6D2DULL + 0xAB1792873B7D2AC6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD21AAB0FF3EC11FFULL + 0xE9D614742250AFF0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCC76A263903CB247ULL + 0xE00F9ABFA6083CC2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9E6F9114CE17B7B1ULL + 0xA2F1D88B469684CFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC0BB70FA631F43C5ULL + 0xB440D30CB869F62CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA99B372E76B15D15ULL + 0xD649719713086004ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2720U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 408U)) & W_KEY1], 28U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1670U)) & W_KEY1], 27U) ^ RotL64(mSource[((aIndex + 1143U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 40U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 27U)) + 1952750591494698524U) + aNonceWordJ;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 4488270851303332830U) + aNonceWordD;
            aOrbiterH = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 2738763375328927635U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 18U)) + 6728843649480454340U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 10490717875258865358U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 57U)) + 1429288737812910205U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 11U)) + 2761375016998907636U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1088988605204499835U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6829840407300289709U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 13101432880030791787U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9267240337867690471U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8120113021183975703U;
            aOrbiterD = RotL64((aOrbiterD * 14296504593187173107U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1340980511302566784U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11874452169979878835U;
            aOrbiterE = RotL64((aOrbiterE * 8638486178860092537U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1872314794140971426U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6013952618696225751U;
            aOrbiterA = RotL64((aOrbiterA * 7994863587373565715U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3644011378086236002U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8501867691997891731U;
            aOrbiterJ = RotL64((aOrbiterJ * 7115282675461711509U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 2493546555198066143U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5179240189571799179U;
            aOrbiterI = RotL64((aOrbiterI * 1267579130962756135U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11273348247858394197U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4577476419423118925U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8427261005061162673U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterA, 41U));
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 27U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 11U)) + aOrbiterD) + aNonceWordP) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterH) + aNonceWordL);
            aWandererH = aWandererH + ((((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aCross, 30U) + aOrbiterI) + RotL64(aOrbiterB, 60U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4724U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 3347U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2962U)) & W_KEY1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4177U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aPrevious, 19U)) + (RotL64(aCarry, 47U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 11U)) + 17019646486641172469U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 35U)) + 12276141179299971572U) + aNonceWordF;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 3617241694029841555U) + aNonceWordH;
            aOrbiterK = (((aWandererH + RotL64(aCross, 50U)) + RotL64(aCarry, 11U)) + 6967963401259371737U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 27U)) + 6340709284279891017U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 41U)) + 456065368903896482U) + aPhaseEOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 17686765719908116203U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1322045955429785736U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5163772703302372887U;
            aOrbiterF = RotL64((aOrbiterF * 3193272189179082313U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13268431135020363252U) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6538789950366849332U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5352960308459065837U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10390344544314544893U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5087084271300584267U;
            aOrbiterE = RotL64((aOrbiterE * 15149302947570776165U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13423071121590981727U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18324443012024134729U;
            aOrbiterK = RotL64((aOrbiterK * 15814349432207734533U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 4129091815978464507U) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17024797553831962245U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3137753479364378175U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6501545108779991661U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11930037791867597447U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4904739567549702851U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4667298703308315851U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6315980380900062127U;
            aOrbiterB = RotL64((aOrbiterB * 12080555704907924637U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 40U)) + aOrbiterE);
            aWandererG = aWandererG + (((((RotL64(aIngress, 44U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 43U)) + aNonceWordE) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + aNonceWordK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 6965U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadB[((aIndex + 7830U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5903U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6118U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 7488U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 47U)) + (RotL64(aIngress, 20U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 8367680518550579791U) + aPhaseEOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 41U)) + 11491674725611181241U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 4U)) + 16673861720782164214U) + aNonceWordA;
            aOrbiterE = (aWandererF + RotL64(aCross, 27U)) + 9786610124108350855U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 5745080601557577637U) + aNonceWordL;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 1959402215131684684U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 35U)) + 6121650036079196522U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 12016309761037342392U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5986936646177049603U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 3585650475703294895U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1000367700904043468U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17425288243569101032U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 2174614006719048535U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4856917474950325209U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16312111093223166419U;
            aOrbiterE = RotL64((aOrbiterE * 11046477664487805241U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 456110002032422270U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11393724374787795662U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1176984359123668389U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8378176867715697176U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8086186452345234815U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 8450438271765985235U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8470349167474173245U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2528229938740192694U;
            aOrbiterG = RotL64((aOrbiterG * 8717790851266520943U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13247168811545753141U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8745293957516815264U;
            aOrbiterB = RotL64((aOrbiterB * 14270617180621072619U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterB, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterE, 12U)) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG);
            aWandererG = aWandererG + (((((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 27U)) + aNonceWordI) + aPhaseEWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 42U) + aOrbiterJ) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9138U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 10019U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 8319U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10620U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10874U)) & W_KEY1], 42U) ^ RotL64(aFireLaneB[((aIndex + 9811U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 53U)) + (RotL64(aCross, 18U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 51U)) + 4980738603982643969U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 5U)) + 17660278413018470020U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 19U)) + 17598114429859543466U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 10993929335279994739U) + aNonceWordO;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 17967203122976322481U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 51U)) + 1872290205549034384U;
            aOrbiterC = (aWandererH + RotL64(aCross, 35U)) + 16607778671782810797U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4895226930754394376U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14960359005982301383U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 8546231310054433721U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9921642352377700630U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 893281964367208693U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2345509157333444217U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8232519988397858732U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4433022122758913407U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 834240393225479419U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12689609831247168353U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 404535388957472176U;
            aOrbiterG = RotL64((aOrbiterG * 14534020545479806593U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3349108201964013155U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4386449511297371730U;
            aOrbiterH = RotL64((aOrbiterH * 9596273264321140229U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14314587717949070586U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10923886625271054985U;
            aOrbiterE = RotL64((aOrbiterE * 7838969002623486809U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17634909585329833520U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 2021301459918350372U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 1388242915918642741U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterD, 39U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterF, 19U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterE, 12U)) + aNonceWordP) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11599U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[((aIndex + 11437U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11301U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 10998U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11137U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12265U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11490U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 44U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 13U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (((aWandererD + RotL64(aCross, 10U)) + RotL64(aCarry, 13U)) + 6654158889644956636U) + aNonceWordO;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 3U)) + 9045779659363991870U) + aNonceWordE;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 3888897662136993491U) + aNonceWordB;
            aOrbiterE = (aWandererI + RotL64(aIngress, 35U)) + 6882016842864459345U;
            aOrbiterD = (aWandererB + RotL64(aCross, 57U)) + 15601891715956172291U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 41U)) + 5176811598629335350U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 12519945150889074325U) + aPhaseFOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4552583214397603278U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14225482701804864688U;
            aOrbiterG = RotL64((aOrbiterG * 8526052833180466359U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5485298070606280363U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11237713257388094289U;
            aOrbiterD = RotL64((aOrbiterD * 11032429223099413011U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14340345895626142788U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16275167270553643347U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 7308578867128951199U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14041860597556520250U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1436068974197066343U;
            aOrbiterK = RotL64((aOrbiterK * 3938460345031496843U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11483155566419547004U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4608508534724289325U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 13461385011638899485U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2389196334288832895U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 4062682330273866602U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 8787682133271101901U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5655656046585592034U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7977947821249746880U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 10082104644185964787U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 22U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 57U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterG, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterF, 24U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aIngress, 26U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordK) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 11U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 37U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 15677U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13914U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16270U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14820U)) & W_KEY1], 46U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15814U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15687U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 13999U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (((aWandererK + RotL64(aScatter, 3U)) + 15726877954695761686U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 14187652171881943587U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 13U)) + 8420423151313882782U) + aNonceWordD;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 28U)) + 14942322692433259283U) + aNonceWordE;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 37U)) + 7272331475919796255U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 154504365041805840U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 17475491222554948786U) + aNonceWordM;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5759181483165339605U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5993060214499322845U;
            aOrbiterA = RotL64((aOrbiterA * 10799489831896153301U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10901786237875941844U) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 17135786595614068473U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15923538730142047043U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5208202073886811165U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6821452921018900631U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 13119330055184115669U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13348064837402206969U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8967943922403445136U;
            aOrbiterD = RotL64((aOrbiterD * 300168481725373093U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8130283784171430891U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6351113882502502876U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15960622823993072903U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6894708729226455769U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12065058511247133944U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5432601727436935831U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17138279326229372741U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12987698199066890628U;
            aOrbiterH = RotL64((aOrbiterH * 12665716655177320977U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 42U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + aNonceWordL);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 37U));
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 6U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 14U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17341U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 16567U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(mSource[((aIndex + 17929U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((aIndex + 17320U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17234U)) & W_KEY1], 52U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17588U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18402U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 54U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 7075016829833562104U) + aNonceWordI;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 12U)) + 8783765886115517036U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 51U)) + 2996723892384565829U) + aPhaseGOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 9494134707342189476U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 35U)) + 5052642981395679904U;
            aOrbiterH = (aWandererH + RotL64(aCross, 41U)) + 8766787055127962238U;
            aOrbiterF = ((((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 4467211954388738079U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 8030255604633658608U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16962408063455702251U;
            aOrbiterD = RotL64((aOrbiterD * 11171737929747471631U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3768222186567699076U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14930990410207899871U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 10930005786146268241U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14179761938395502502U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1879084742719898108U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16783034788172670121U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5535012408925981515U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12792553516710295939U;
            aOrbiterA = RotL64((aOrbiterA * 8577530993755159329U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8979253163346099252U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5559189896063990740U;
            aOrbiterF = RotL64((aOrbiterF * 8832485423727331621U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 13937564337299044079U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2393376759689394948U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2352815657830413941U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12647519563697356479U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10946871249960389549U;
            aOrbiterG = RotL64((aOrbiterG * 6272580371881237173U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + aPhaseGWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 50U)) + aOrbiterI) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 11U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterG, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 4U) + RotL64(aOrbiterI, 41U)) + aOrbiterA) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 54U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 21609U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 20393U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19983U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneA[((aIndex + 21163U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20008U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20641U)) & W_KEY1], 39U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20143U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 20655U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 24U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (aWandererJ + RotL64(aScatter, 41U)) + 12632404972795375757U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 5U)) + 5351879979055988456U) + aNonceWordP;
            aOrbiterE = (aWandererE + RotL64(aIngress, 35U)) + 3597737727467443413U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 2830846754917852318U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 53U)) + 17311925960294518018U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 2083584640523695383U) + aNonceWordJ;
            aOrbiterG = ((aWandererI + RotL64(aCross, 3U)) + 15049343611387010158U) + aNonceWordA;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 6443050378205811147U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 6021965178697344070U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 6054064448935006741U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5080289878758029976U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 576927745306972983U;
            aOrbiterB = RotL64((aOrbiterB * 16008958833683246115U), 41U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 4728489691382690859U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6184355840165758855U;
            aOrbiterD = RotL64((aOrbiterD * 1515043910404156423U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11220539885798595450U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11091438724966718214U;
            aOrbiterJ = RotL64((aOrbiterJ * 8225347114759391961U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17184210490020062419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2150997767099116408U;
            aOrbiterG = RotL64((aOrbiterG * 8058553821648892499U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7021953562676903717U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17159676348343312834U;
            aOrbiterC = RotL64((aOrbiterC * 13877284519668483549U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10367891770525239784U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11922478487264201233U;
            aOrbiterI = RotL64((aOrbiterI * 9195137452661956029U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 14U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + aPhaseGWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + aNonceWordC);
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 60U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23274U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 24004U)) & W_KEY1], 14U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22437U)) & W_KEY1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 24216U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23381U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23745U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22766U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneD[((aIndex + 23046U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCross, 51U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 5960680319644404115U) + aNonceWordO;
            aOrbiterC = (aWandererC + RotL64(aCross, 51U)) + 16050752633567034185U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 18U)) + RotL64(aCarry, 11U)) + 8447503223226854741U) + aPhaseGOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 14176813813397917591U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 35U)) + 10534915376130006644U;
            aOrbiterE = (aWandererG + RotL64(aCross, 11U)) + 6866224454375302514U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 43U)) + 16506374165041008396U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7167814023968794098U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13870852197416596664U;
            aOrbiterD = RotL64((aOrbiterD * 17015971222069856463U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 18064038854848993105U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9869630811507771691U;
            aOrbiterA = RotL64((aOrbiterA * 13723164383800461387U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 863613100452759380U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16597969741225436529U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2680793528887208903U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6575347108051310653U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17062262265485019063U;
            aOrbiterI = RotL64((aOrbiterI * 7601045488473620019U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7193399224636409133U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 14146747818810433849U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 5273185769989530041U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9441449106442431427U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 4303295336545399503U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 8829695296836242587U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12604760768543193458U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15779327512379787715U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 14000905201441272597U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 4U)) + aOrbiterI) + aPhaseGWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 20U) + RotL64(aOrbiterI, 19U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aNonceWordB) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterA) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aCross, 41U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterG, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24717U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 27096U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 27052U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 27090U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26996U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26271U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26462U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24606U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 4476099022490972343U) + aNonceWordI;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 53U)) + 16836423700375760429U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 11U)) + 8850577488928703557U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 5U)) + 7091631824560042743U) + aNonceWordG;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 35U)) + 12560498899956759494U) + aPhaseHOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 7797973377112012161U) + aNonceWordE;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 6173820673874805794U) + aNonceWordD;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10805025132310245348U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7139216143268029968U;
            aOrbiterH = RotL64((aOrbiterH * 8349754682635765573U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8241544862261635722U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4735527016563596150U;
            aOrbiterA = RotL64((aOrbiterA * 6621354217673598381U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5166171126690294033U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11117641762075368393U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4980156869201219393U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 6312932356458415421U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1304139291184508668U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 90744653170922319U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10085025354842771067U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16745854428789531080U;
            aOrbiterD = RotL64((aOrbiterD * 1945983905747274355U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 2497187958708890337U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16069701876646548995U;
            aOrbiterG = RotL64((aOrbiterG * 16606039730973709495U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17242004368025978091U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12334315722243232121U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16528598396696346719U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 34U)) + aOrbiterG) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aCross, 11U) + RotL64(aOrbiterA, 51U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordO) + aPhaseHWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterG) + aNonceWordH);
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 11U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterH, 43U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28313U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 29973U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29235U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 28891U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29266U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28453U)) & S_BLOCK1], 48U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29645U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29105U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = ((aWandererC + RotL64(aScatter, 27U)) + 7270044678408187242U) + aPhaseHOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 56U)) + 10192278965379756766U) + aNonceWordH;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 17568666746676060748U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 14312927531124963037U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 43U)) + 9825825726152087706U;
            aOrbiterF = ((((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 9696778570255265896U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 13U)) + 17657841352013417228U) + aNonceWordM;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16207815085909628439U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 1752979206374514227U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14182667540650694199U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10456310689643905854U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16127830548663742550U;
            aOrbiterH = RotL64((aOrbiterH * 4355938404839045417U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2940917376003930842U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7353596864777649953U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7499468723171042005U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12725092740446150705U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5791296650856037010U;
            aOrbiterK = RotL64((aOrbiterK * 760379251950502133U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1200130368046206150U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16689604428598558547U;
            aOrbiterD = RotL64((aOrbiterD * 13815324235939996623U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 14359561591103730856U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3975025843599045263U;
            aOrbiterJ = RotL64((aOrbiterJ * 5025047888533298617U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14017901732955607601U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10431526786489555196U;
            aOrbiterE = RotL64((aOrbiterE * 10181915874476132407U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterK, 34U));
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterE, 23U)) + aNonceWordB);
            aWandererB = aWandererB + ((((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + aNonceWordE) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32176U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31748U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31472U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30715U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30537U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31654U)) & W_KEY1], 38U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCarry, 52U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (aWandererF + RotL64(aIngress, 6U)) + 14214886793361825363U;
            aOrbiterK = ((((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 17267959031078766320U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aWandererD + RotL64(aCross, 21U)) + 16436067429484887644U) + aNonceWordB;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 9885951769332633820U) + aPhaseHOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aScatter, 13U)) + 12971711341813893304U) + aNonceWordP;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 47U)) + 199970353398450154U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 1237341696444162094U) + aNonceWordN;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7991128854417613360U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14809029847149045833U;
            aOrbiterA = RotL64((aOrbiterA * 5940857360838299105U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2559509556915775947U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14336829730147834160U;
            aOrbiterD = RotL64((aOrbiterD * 15103242520064900873U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8853631886733610440U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13346159398673246914U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 13660497151446983393U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12121095718571872976U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16239781125815589804U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5157009090454962231U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9051377033794324106U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13805815136723461780U;
            aOrbiterB = RotL64((aOrbiterB * 571129481747181357U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14849157800322754413U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 18116651528452542634U;
            aOrbiterE = RotL64((aOrbiterE * 3638480428016835537U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4105057226952948599U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5911714320560994391U;
            aOrbiterK = RotL64((aOrbiterK * 1796514171654961389U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 11U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterK, 44U)) + aOrbiterC) + aPhaseHWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 53U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterD, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterA, 3U));
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Tennis_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF3C727BA08097719ULL + 0xB413849679A63E91ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCB176E2AC4A8C9BFULL + 0x92737F5221142500ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA28A186E59246FE5ULL + 0x9ADE649594C269A7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD610BEEFDA4E6C69ULL + 0xA7525ABB2AEC0136ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x86FCE8CF0C38AB31ULL + 0xBC569336BE4C9998ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE42882A8269E6BB3ULL + 0x9D3E40EFA2220E5DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD94AE173B393C643ULL + 0xE2AE44EA061C07BFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD35F58FB2103DE65ULL + 0x8970526B6754C6FFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF5F6C4257AE2B3C7ULL + 0x9C7247387E1924FEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB83E0DF513B41CF7ULL + 0xD879A74D2F288ADCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB5BA706E1FC3FC11ULL + 0xE3D338A8FE66647CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA052D55CD9CD4849ULL + 0xFB01AAC0ADCA88C5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x98D319281BA28395ULL + 0xE074F568644AF33AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF0594E7CB4EAAFE7ULL + 0xFCC6D5985A573FA5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x82725AA3884FDCC5ULL + 0xE50542801F3F9B1BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x848BE0655FAAA535ULL + 0xAB0247BE3D71B471ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3560U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 4879U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3246U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3417U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3551U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2114U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 20U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 5U)) + 4259993311776766595U) + aNonceWordN;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 2857813330021126753U) + aNonceWordD;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 37U)) + 1345396841329442896U) + aNonceWordC;
            aOrbiterD = ((((aWandererF + RotL64(aIngress, 58U)) + RotL64(aCarry, 27U)) + 320992148982301024U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 5619109532065293074U) + aPhaseAOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10380157329426706345U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12449831150625409695U;
            aOrbiterH = RotL64((aOrbiterH * 3354095240459774437U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7847096607042268396U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11707184096803214678U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1959476948106553973U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9893643746186827088U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 333687403830908774U;
            aOrbiterC = RotL64((aOrbiterC * 17911256836121454271U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 13837360705077441580U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 4367119682175710689U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 10295744669174603401U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1193493435041306784U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15062951612027370606U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2509383510565136549U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 36U);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 14U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 12U) + aOrbiterH) + RotL64(aOrbiterG, 35U)) + aNonceWordO) + aPhaseAWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 27U)) + aOrbiterE);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aNonceWordF) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8873U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((aIndex + 7989U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6469U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 5932U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6431U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10769U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10086U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 26U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 29U)) + 12535417189990029950U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 6U)) + RotL64(aCarry, 27U)) + 6204401443676390273U) + aNonceWordH;
            aOrbiterA = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 869613505613154672U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 15053590879563855802U) + aNonceWordK;
            aOrbiterK = (((aWandererF + RotL64(aCross, 39U)) + 13338989605204591428U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 18306470022403825392U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1150696349434090218U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1099447646821052165U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13549541786420596437U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 14302878430259588461U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 16813606782134305513U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4660437084477165225U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1653628537860912069U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 2624835201155303123U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5594199757006711631U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11008472193138708891U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 13645764762027798301U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3668516817279364310U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 128159531749679984U;
            aOrbiterC = RotL64((aOrbiterC * 4523246859249826987U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 13U)) + aOrbiterE) + aNonceWordN) + aPhaseAWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 5U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterK, 54U)) + aNonceWordF) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14995U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 14793U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12296U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11087U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 14939U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aPrevious, 53U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = (((aWandererH + RotL64(aIngress, 13U)) + 6733949564325516029U) + aPhaseAOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 7304098437143918796U) + aPhaseAOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 23U)) + 3923949518391777800U) + aNonceWordD;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 14243591003388927124U) + aNonceWordF;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 44U)) + RotL64(aCarry, 53U)) + 18329498724605410406U) + aNonceWordA;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13118172167747037249U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5272025143849174212U;
            aOrbiterJ = RotL64((aOrbiterJ * 9935990954321437743U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16075917179214318424U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15263590648674658399U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9918239923411740337U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13730046728289525921U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7703141464499623408U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5886009900621521987U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1382279753822135359U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 2973369221699098292U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 7440242040663550631U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11578274119583013219U) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3419411247737896674U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 17814942652262802991U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 43U)) + aOrbiterA) + aNonceWordN) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aPhaseAWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterI, 52U)) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19005U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 17733U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 20340U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19215U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 16756U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 44U) + RotL64(aCarry, 19U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 18144572925667544139U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 30U)) + 5659758077574059728U) + aPhaseAOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 51U)) + 6343330616999166392U) + aNonceWordJ;
            aOrbiterJ = ((((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 17754639838410839447U) + aPhaseAOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 9451843819849581729U) + aNonceWordB;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 7957854457197462212U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1461994799722205010U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 13431080873536691809U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18002214276252170177U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 14689869073147027164U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12242482963989582191U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3978104368003440293U) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8512135845221335386U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10506667163729414667U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1477533446382953439U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2166717790929947990U;
            aOrbiterG = RotL64((aOrbiterG * 6538884492418324461U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8082437060686606995U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4363687722464700362U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7199165810993478887U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 60U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + aNonceWordC) + aPhaseAWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + aNonceWordH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27125U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneB[((aIndex + 21931U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25467U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23992U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26331U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (aWandererA + RotL64(aCross, 60U)) + 12027839670755583592U;
            aOrbiterC = ((((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 15380130703509859843U) + aPhaseAOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 4590907433867798074U) + aNonceWordI;
            aOrbiterE = ((((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 43U)) + 1754574023602519724U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 35U)) + 9832756659564903767U) + aNonceWordA;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5035088494491470403U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14199170923323644638U;
            aOrbiterK = RotL64((aOrbiterK * 4518257134117207121U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8325619421264440438U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 969534320779067977U;
            aOrbiterH = RotL64((aOrbiterH * 17767548306355264705U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 270575869402913847U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13344806516599578910U;
            aOrbiterC = RotL64((aOrbiterC * 10193544126281901579U), 53U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 15143147951139409101U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14425582489214169238U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16893787086337916355U), 3U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 13951127523239064584U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14177925225918293579U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 13079514031864998485U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterH, 46U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 13U)) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + aNonceWordJ);
            aWandererE = aWandererE + (((((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 39U)) + aNonceWordE) + aPhaseAWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29971U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 28197U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32104U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31402U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 30477U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 28U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = (aWandererG + RotL64(aIngress, 35U)) + 13583136155674166402U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 12830472187484919497U;
            aOrbiterD = ((((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 18081197909484522509U) + aPhaseAOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 8680634051297891550U) + aNonceWordI;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 56U)) + 13939998767458656823U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1795730579103692594U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 17369751719734069999U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 2633464694273697123U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 224769585901248068U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4133547085925268180U;
            aOrbiterJ = RotL64((aOrbiterJ * 2611561365156544735U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7022512056309567391U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10319484359046945495U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 3400140531307001933U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10483878349412282069U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6481381149199985736U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9701719367082506253U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13721077228796934509U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9704818014314175007U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 760445624027740287U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 56U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 11U)) + aOrbiterD) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + aNonceWordL);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 44U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aNonceWordK) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Tennis_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBAFF89A197CBB925ULL + 0xB68747FD0CDCBCC7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA50EC913355C3851ULL + 0x90068750E077DBA9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC4DE343E3480E299ULL + 0xD706B8DB3A67021BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDF1586690B11BBF1ULL + 0xF21334B4872B6D63ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC12DC66033E8AC01ULL + 0x9BB4B191D778196CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x90FA53BB8C35A37FULL + 0xCC53E86EB53E9F35ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB343B9DBA2114C41ULL + 0xB98399D7746EF3A5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8620BA87570669C5ULL + 0x8458E04D7DB4A278ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB1DC90204037753BULL + 0xC8187A10B4B74DD6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD249EDA03866AE1DULL + 0xDB8F0160760FDCF6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCF2B5423CF8DBD6DULL + 0xCED8BA24D1100AA0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCDD38FD4C14A92A1ULL + 0xB2043B561F18DB36ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB68AF7B7673C9A91ULL + 0xE04D045D1C54F702ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x913F130A1F8006AFULL + 0x889F435ED544F00BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF44EBEAC9BD49FA7ULL + 0x905A4BA1503559ADULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE928F374B6C3A637ULL + 0xCA1F949AC7102093ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4123U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 4742U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4983U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5352U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7088U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5486U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 54U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererE + RotL64(aCross, 39U)) + 3236820517816085022U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 741288875914097926U) + aNonceWordA;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 46U)) + RotL64(aCarry, 3U)) + 8417246926007729580U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 11U)) + 9715717805774537170U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 14360243844821619482U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 5U)) + 10760908100206775334U) + aNonceWordJ;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 53U)) + 3434641779946167811U) + aNonceWordN;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 57U)) + 7885568822756234567U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 18U)) + 3041563437672051294U) + aPhaseBOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15761355327564963516U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1158633562785937421U;
            aOrbiterG = RotL64((aOrbiterG * 15511324886867188235U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9338581575871970653U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9172038894262857354U;
            aOrbiterD = RotL64((aOrbiterD * 3110871165285625807U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14653924713599790081U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3854497592598563309U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11737111068815795303U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16286980180327600557U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5092583772591249756U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 13955105624639442903U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4288397994175567333U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15584236478994873104U;
            aOrbiterJ = RotL64((aOrbiterJ * 1860480595862755379U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5557463939827483792U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2659814275753280856U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17702430405693184643U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6941807963525063449U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2040598555191211307U;
            aOrbiterE = RotL64((aOrbiterE * 14750544987531722765U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 347572666231116258U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 779304821185302523U;
            aOrbiterB = RotL64((aOrbiterB * 14180254150318109855U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10632524582873079742U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9761308771280517212U;
            aOrbiterH = RotL64((aOrbiterH * 13926235411726048921U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 36U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + aNonceWordD);
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterC, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + aPhaseBWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 60U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 6U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12426U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 14589U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9977U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 11073U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15293U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12738U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12040U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererH + RotL64(aPrevious, 47U)) + 9107326720193244489U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 19U)) + 10868585484401664145U) + aPhaseBOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aWandererI + RotL64(aIngress, 27U)) + 13637736741437846622U;
            aOrbiterA = (aWandererB + RotL64(aCross, 52U)) + 6130725216183918844U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 57U)) + 2063834478521338187U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 3U)) + 8564870627911949158U) + aNonceWordN;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 6524015751064086390U) + aPhaseBOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 9874937766875388236U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 36U)) + RotL64(aCarry, 37U)) + 14723718409522680894U) + aNonceWordL;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13767059954741528279U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6387608251033722169U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6601902195707980693U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5391425980008431000U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11524218415655093779U;
            aOrbiterD = RotL64((aOrbiterD * 12508457981779189389U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 155510463350385905U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10554591788433641311U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 5412084824127934293U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8662160162966241542U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5092555636369853727U;
            aOrbiterK = RotL64((aOrbiterK * 433807340167635499U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7163345798448796101U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 695089002178413267U;
            aOrbiterC = RotL64((aOrbiterC * 17302689458565434475U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5409173939213468972U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15349690077393827541U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 10984681254001609841U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12376011890751302027U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7809614158898158383U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13845113198736843629U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13031938699536449576U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3983178190194056516U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 1341678482929213405U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 5567935037909671790U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17137042627663349797U;
            aOrbiterE = RotL64((aOrbiterE * 13535586899620672373U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 46U);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterD, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterB, 43U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterA, 60U)) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + aNonceWordH);
            aWandererC = aWandererC + (((((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 39U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordA) + aPhaseBWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterG, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 34U)) + aOrbiterE) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20486U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 21705U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 23089U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 21106U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23586U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20818U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 22063U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 47U)) ^ (RotL64(aIngress, 34U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 5173905450211892891U) + aNonceWordI;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 6U)) + RotL64(aCarry, 23U)) + 3555542451908039957U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 11559884700283861559U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 23U)) + 1352524329968738673U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 57U)) + 8914206450420616349U) + aPhaseBOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 48U)) + 2251523378498463946U) + aNonceWordN;
            aOrbiterA = (aWandererG + RotL64(aIngress, 53U)) + 9541575923299247038U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 13U)) + 1239854507907214595U) + aNonceWordL;
            aOrbiterJ = (aWandererF + RotL64(aCross, 19U)) + 17698101462598498934U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12305566971683256060U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13804545036303215569U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10359543704152744971U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10239749097704329264U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4212214906286320308U;
            aOrbiterK = RotL64((aOrbiterK * 3661436621615751071U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12192418916967430783U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4475514289326450361U;
            aOrbiterA = RotL64((aOrbiterA * 17497164630368757887U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 17376102613298827459U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 18129393209955439341U;
            aOrbiterB = RotL64((aOrbiterB * 6404089025014118979U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4014763724300253568U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17325007199676828814U;
            aOrbiterE = RotL64((aOrbiterE * 1420888274815627083U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15480474849292388685U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 14357924730184375449U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16723492259068034209U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4335731868597970070U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8296023680394303015U;
            aOrbiterI = RotL64((aOrbiterI * 14027415401430120543U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 2807312426993262800U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15510369660839648501U;
            aOrbiterC = RotL64((aOrbiterC * 18207954408298333959U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12597844696606519907U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7231012798553551535U;
            aOrbiterJ = RotL64((aOrbiterJ * 2841306785994479299U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 24U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 51U)) + aOrbiterK) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterE, 41U)) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterA, 18U)) + aPhaseBWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 6U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27252U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 32239U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 29880U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29116U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26294U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28697U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 29858U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 13U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererA + RotL64(aScatter, 58U)) + 3255291173184001106U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 15308468160116255528U) + aNonceWordJ;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 18186972408589866656U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 21U)) + 4439324265978331914U) + aPhaseBOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aCross, 37U)) + 13099263173016322486U) + aPhaseBOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 41U)) + 7041561081767500660U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 6196422612687812971U) + aNonceWordG;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 47U)) + 7664260932541281413U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 4U)) + 17802347823020441056U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4253107484061190446U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13799496534030645312U;
            aOrbiterE = RotL64((aOrbiterE * 9167675060053848207U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14252892847595951926U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 5663527578664291422U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 18314294235895182465U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11148755959699137661U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17036900929333594592U;
            aOrbiterG = RotL64((aOrbiterG * 16041243617369003291U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 2403828181385259549U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17813580350434928194U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13666780980793857831U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5623611126885414523U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7293224381174846969U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 7032561584670788117U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10602620906929686163U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18015916257203385982U;
            aOrbiterI = RotL64((aOrbiterI * 10684090189688871993U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13592915735376305773U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13995866908043417505U;
            aOrbiterJ = RotL64((aOrbiterJ * 3802175869395887331U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8200465989447697618U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9866671660800629464U;
            aOrbiterB = RotL64((aOrbiterB * 2138851839905326265U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11557528777230608777U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 131060617338185060U;
            aOrbiterC = RotL64((aOrbiterC * 11068705423012265209U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 40U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 56U)) + aOrbiterA) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aScatter, 48U) + aOrbiterE) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 39U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 40U) + aOrbiterI) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterF) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterH, 4U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Tennis_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA40C55899A1324AFULL + 0xDA00BF24E97D3F35ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFA76C8C29E6C3B0FULL + 0xAE0CE0A4C67E702EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF7B9115616A25201ULL + 0x87FF57B052733D44ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC357E128C7B3FE09ULL + 0x874C4DBD215E9634ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDE58C86C0141FA5BULL + 0xB3C3CD6433CD0818ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD6D4F3F29698059BULL + 0xADBFAA1D3EE56038ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBB7600D59560FC75ULL + 0xAE8AE4BA32F53F34ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB4F7CCFBDDAE08E3ULL + 0xF09A5A2394523AEFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA5E2473C5078ACABULL + 0xF2FBF25882AA3AA2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF2D9ABDC5E00D805ULL + 0xFFE60480C8DC29D1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9D5210DB26D4A09BULL + 0xB106ED186FB49ACBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9B0423C2692DAF05ULL + 0xBC061EBE9C1A41DBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9A55D4C5DF738EF5ULL + 0xAD9923E7795B7639ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEDE7DD67A3722281ULL + 0xB10CC32A1AAE85DCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCD1267676C196057ULL + 0xD842BEE5398D7BD4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x848E8D6AA09FC419ULL + 0xE9F4F47AE2F8FB02ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 969U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 3848U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 937U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3540U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1964U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1576U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 58U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 19U)) + 3255291173184001106U) + aNonceWordH;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 39U)) + 15308468160116255528U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 18186972408589866656U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 3U)) + 4439324265978331914U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 13099263173016322486U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 46U)) + 7041561081767500660U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 6196422612687812971U) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7664260932541281413U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17802347823020441056U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2220679459017369255U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4253107484061190446U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13799496534030645312U;
            aOrbiterH = RotL64((aOrbiterH * 9167675060053848207U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14252892847595951926U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5663527578664291422U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 18314294235895182465U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11148755959699137661U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17036900929333594592U;
            aOrbiterA = RotL64((aOrbiterA * 16041243617369003291U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2403828181385259549U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17813580350434928194U;
            aOrbiterF = RotL64((aOrbiterF * 13666780980793857831U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5623611126885414523U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7293224381174846969U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7032561584670788117U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10602620906929686163U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 18015916257203385982U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10684090189688871993U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterH, 60U)) + aNonceWordM) + aPhaseDWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + aNonceWordJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 54U) + aOrbiterJ) + RotL64(aOrbiterC, 51U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6785U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 10254U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8920U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8367U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9278U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9719U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 6456U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 10U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererB + RotL64(aCross, 48U)) + 14686411261024919129U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 7514582233957632005U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 6520710480103365552U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 41U)) + 1983621978676188036U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 57U)) + 9003524602590749672U) + aNonceWordO;
            aOrbiterC = ((((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 6428568234045228995U) + aPhaseDOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererA + RotL64(aCross, 21U)) + 8656552687136446989U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16916248288415922490U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9740237548002535784U;
            aOrbiterD = RotL64((aOrbiterD * 7970729853948983849U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 907561000814618339U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4751108900841197631U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 4545395964730641957U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 167774899400732287U) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11907484918310854962U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7213139491146402985U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14910318613649863924U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14882888155751455276U;
            aOrbiterG = RotL64((aOrbiterG * 11394136445442060201U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16175942562693781908U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11022373758481651102U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6836331461393816027U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12548405399045031548U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10850926364556828443U;
            aOrbiterC = RotL64((aOrbiterC * 16231561687709867431U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13391684887911141790U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 14648937281264822988U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 6533299316940026059U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 28U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterF, 19U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterK, 43U)) + aNonceWordH);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + aNonceWordK) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 6U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 37U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12586U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 13402U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 13047U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11773U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 15008U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 10805654776556844351U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 582794182442795335U) + aPhaseDOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aPrevious, 19U)) + 2858343650974681068U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 8189584049022064284U) + aNonceWordA;
            aOrbiterD = ((aWandererE + RotL64(aCross, 28U)) + 1565100751996962893U) + aNonceWordM;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 47U)) + 8062028016947611891U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 13U)) + 8280504280578451745U) + aPhaseDOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11326869194491655350U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1671695656567777163U;
            aOrbiterB = RotL64((aOrbiterB * 7511554500524257921U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2349843105293943452U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 13015545152052004254U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 1316662811685429983U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16703354404749291869U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8713231044374305801U;
            aOrbiterE = RotL64((aOrbiterE * 9242480982197688625U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11118401674497783533U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 14857556493734710364U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 3452566050389715195U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12953419670951660965U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12666121730825089017U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 14049925256934142519U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11075249639473053423U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9374217688244187867U;
            aOrbiterD = RotL64((aOrbiterD * 5261156325627117877U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17608340953291367867U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13159437499327086340U;
            aOrbiterA = RotL64((aOrbiterA * 4882100944453534805U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterA, 13U)) + aOrbiterB) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 58U)) + aOrbiterJ) + aNonceWordJ) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 21U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 17233U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 21556U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 20518U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19223U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20455U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 37U)) + (RotL64(aCross, 52U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 57U)) + 15045917390223766480U) + aNonceWordN;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 46U)) + RotL64(aCarry, 41U)) + 10763054007033668758U) + aNonceWordC;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 35U)) + 13190170142593666607U) + aNonceWordL;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 5U)) + 9657025731441167065U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 11U)) + 11433367178975954211U;
            aOrbiterA = ((((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 17904920143996810366U) + aPhaseDOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 3244383020512113283U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6538815775171139091U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7195368312757976343U;
            aOrbiterG = RotL64((aOrbiterG * 10515679176134176565U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18134430713910279374U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6571776588427107976U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 11916502085252589161U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11830778129647517758U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9793702760907767365U;
            aOrbiterK = RotL64((aOrbiterK * 4096246227968677179U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2287235876793192036U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8951959188326141794U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9968356718110753845U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7583061790273240157U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3571364625022806085U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6238360922735480669U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13869345563551689212U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 277480328952975002U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1057564597096163085U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4983735092494677578U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9490022869381030928U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 12926352917961703123U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterH, 11U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 21U));
            aWandererB = aWandererB + (((((RotL64(aCross, 12U) + aOrbiterA) + RotL64(aOrbiterF, 46U)) + RotL64(aCarry, 35U)) + aNonceWordH) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 5U)) + aOrbiterK) + aNonceWordI) + aPhaseDWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 29U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25658U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 22698U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 26252U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24476U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 21896U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((aWandererF + RotL64(aScatter, 23U)) + 18144572925667544139U) + aNonceWordO;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 4U)) + 5659758077574059728U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 6343330616999166392U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 13U)) + 17754639838410839447U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 57U)) + 9451843819849581729U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 7957854457197462212U) + aNonceWordE;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 1461994799722205010U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18002214276252170177U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14689869073147027164U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 12242482963989582191U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3978104368003440293U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8512135845221335386U;
            aOrbiterJ = RotL64((aOrbiterJ * 10506667163729414667U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1477533446382953439U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 2166717790929947990U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 6538884492418324461U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8082437060686606995U) + aNonceWordB;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 4363687722464700362U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 7199165810993478887U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15782763348014924206U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8572509150015960728U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3340528604891897779U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12248271773316742521U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9602078627638561949U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1860631869877427405U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17244849374768558859U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1030743048280579012U;
            aOrbiterD = RotL64((aOrbiterD * 10858949914285817051U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 12U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + aNonceWordD);
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + aNonceWordJ) + aPhaseDWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterK, 20U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 11U)) + aPhaseDWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 52U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 32119U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((aIndex + 29271U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30051U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32027U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 29746U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 58U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (aWandererD + RotL64(aCross, 13U)) + 14157904117287696136U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 7369512677371640676U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 35U)) + 8411250745902073798U) + aNonceWordN;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 60U)) + 5002041814539710275U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 9538041410816283124U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 5210700103927513061U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 53U)) + 7600709399101287982U) + aNonceWordP;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2366369466696580499U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5544575244203019109U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16231219246786333057U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8710073749110329779U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15998211310115361630U;
            aOrbiterF = RotL64((aOrbiterF * 15275657696897688955U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15354357553877376422U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10657523549259276169U;
            aOrbiterC = RotL64((aOrbiterC * 13695239532898311073U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10405750198355464768U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3465819693133515142U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14678343718277562799U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16724189641701408630U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3484340153620198872U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17247547677520703125U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7420442404884871126U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11138445997256757636U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11167543379937571127U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 1428191560884663125U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16950093140800653985U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 4423012306984814805U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 48U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + aNonceWordG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 51U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 13U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 44U)) + aOrbiterC) + aNonceWordB);
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + aNonceWordA) + aPhaseDWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Tennis_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE8F46D8CA0AA3497ULL + 0xA437EB6E8E6D09BEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8183F92FF713B5A7ULL + 0xC52F7BDC93AC8255ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xACFB1AD206ACC52FULL + 0xEDDDA8C04DFAE3CAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x99FD5F35476F6A9DULL + 0xFFFBC8AE6BF14E24ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE3B9722AF0F4AA55ULL + 0xD26549E8CB6A8A9AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEA32491EE6907DC9ULL + 0xA62A846450C19258ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCDAD3694582CC2EBULL + 0xC7881D020BD9FA54ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE35AAA2D39487189ULL + 0x8F9E0A36A323DCD2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x992E010EF8F80E17ULL + 0x9645146745390CB6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x894E3483FB7707F9ULL + 0xFB560E3324354ACAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF2EB924AA6D09271ULL + 0xDBAC93750625FB50ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBFB14349201B6DBBULL + 0x81608F5D2CF831C2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8F427736EDF08701ULL + 0xEAECD7918E0BB760ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC479641BB5CF2307ULL + 0xB1018D494A9B18D9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDF21615E259C26DFULL + 0xD89A56EBD865B0B1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8328C9C2D98D29A1ULL + 0xD8EED4756DBC6DE6ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 228U)) & S_BLOCK1], 18U) ^ RotL64(aInvestLaneB[((aIndex + 1543U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 693U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3596U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4151U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5009U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererE + RotL64(aScatter, 13U)) + 12583180859826261500U) + aNonceWordG;
            aOrbiterI = ((aWandererI + RotL64(aCross, 47U)) + 9067093488553721468U) + aNonceWordJ;
            aOrbiterC = (aWandererB + RotL64(aIngress, 21U)) + 12173106198862881754U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 11333491014394592654U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 38U)) + 3511883526940919554U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 51U)) + 7416810692106273044U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 8341174972619784110U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 35U)) + 2220852854836962979U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 60U)) + 8090781422229383825U) + aPhaseEOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 57U)) + 2338801236599102223U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 12484514711848308104U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13684861340589131816U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12796636819991873058U;
            aOrbiterC = RotL64((aOrbiterC * 5533508014234835669U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7634198650894837690U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10240326122201201762U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 8758703497719125901U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4162814763739453934U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2766504649149048469U;
            aOrbiterF = RotL64((aOrbiterF * 16731843453895178671U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11051393030148769655U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 17687055068651386665U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1042927176246229537U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3353615315436983420U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5971640796220306310U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15804313508835034807U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12299773092762384765U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7435804907797063411U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 9848139805288165965U), 37U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 8735783937125735699U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11903126115475835615U;
            aOrbiterG = RotL64((aOrbiterG * 16942088822124940265U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4427166023462475475U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6011733469446008137U;
            aOrbiterB = RotL64((aOrbiterB * 17298067225913923517U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18341473946127677319U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5423774915753911947U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14985099502923458523U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2384393657884193014U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2650593524388493958U;
            aOrbiterE = RotL64((aOrbiterE * 892985816665547945U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15991261431384033176U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12583180859826261500U;
            aOrbiterH = RotL64((aOrbiterH * 14394838775646875599U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 14U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 21U)) + aOrbiterC) + aNonceWordF) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 53U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 5U));
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 46U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 58U) + aOrbiterJ) + RotL64(aOrbiterC, 39U));
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 51U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 48U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterE, 3U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8724U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneC[((aIndex + 7155U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8925U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((aIndex + 6342U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 8474U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10833U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7255U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 47U)) + (RotL64(aPrevious, 34U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 46U)) + RotL64(aCarry, 43U)) + 15036852811491820366U) + aNonceWordP;
            aOrbiterC = (((aWandererI + RotL64(aCross, 57U)) + 305637140752898475U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aWandererD + RotL64(aScatter, 35U)) + 11948631574496129610U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 21U)) + 5321623592482991426U) + aNonceWordK;
            aOrbiterJ = (aWandererB + RotL64(aCross, 27U)) + 4075270159062690728U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 15111580500356908928U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 50U)) + RotL64(aCarry, 3U)) + 7244150695504160363U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 53U)) + 5131563519577488862U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 11U)) + 5881954992088651371U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 19U)) + 12780935808751507998U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 23U)) + 12599159643925470226U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9466589929741834066U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6093158735705189789U;
            aOrbiterB = RotL64((aOrbiterB * 7453778295800853653U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17461243886150519249U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15456408913739900718U;
            aOrbiterJ = RotL64((aOrbiterJ * 16093292401746174671U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11260643903290392780U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7870342756041882616U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2431528656086173419U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 134484990005888936U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10626896209992890407U;
            aOrbiterC = RotL64((aOrbiterC * 12034131076645285597U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14031164129515132292U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1771835705730244212U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 186981668443596623U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16395472745067254664U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1455944290845294254U;
            aOrbiterD = RotL64((aOrbiterD * 6757824754363319079U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17866422769075350837U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10226884082632410805U;
            aOrbiterA = RotL64((aOrbiterA * 206035536985843815U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14474587247775371703U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8501763445324525303U;
            aOrbiterI = RotL64((aOrbiterI * 5298694643596784007U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 222650368553738561U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3901452368735982094U;
            aOrbiterF = RotL64((aOrbiterF * 18347115513126660483U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3063093906728331146U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 9026710562384443411U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 8411243802199203035U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11282041925238364080U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15036852811491820366U;
            aOrbiterH = RotL64((aOrbiterH * 18185121326941087841U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 12U) + RotL64(aOrbiterI, 30U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aPhaseEWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 13U)) + aOrbiterE) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 40U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15789U)) & S_BLOCK1], 50U) ^ RotL64(aInvestLaneA[((aIndex + 11741U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 11956U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12029U)) & S_BLOCK1], 42U) ^ RotL64(aInvestLaneC[((aIndex + 15800U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 18U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 51U)) + 7651355040951791298U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 53U)) + 13988210277931659312U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 11U)) + 9846849412579537783U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 57U)) + 12746719939495876158U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 24U)) + 11498066185182895284U) + aPhaseEOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 11101058955193080232U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 15513734459555672046U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 47U)) + 15711108675349394643U) + aNonceWordO;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 35U)) + 4771231759949468556U) + aNonceWordI;
            aOrbiterE = (aWandererA + RotL64(aCross, 37U)) + 11449258010811305256U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 4U)) + 17036938391509986723U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6999245666776654250U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2106819066263369528U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13005885810757743129U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12716183358903477216U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16752724547046059889U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 11475905692393034141U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17623077680983093163U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6726003022297274986U;
            aOrbiterC = RotL64((aOrbiterC * 14709385877103232653U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2842410225096524740U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9235178377537910514U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 11813751114775673845U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2619888019860844610U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6295481948199619613U;
            aOrbiterD = RotL64((aOrbiterD * 15429161806953951205U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9724921158061115570U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4070976180958458679U;
            aOrbiterB = RotL64((aOrbiterB * 6080566609081811453U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5864247978960125554U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7771249710071026757U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 4787660062590737657U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15006900854988166845U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2755659268987119046U;
            aOrbiterI = RotL64((aOrbiterI * 8043939381186802359U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1922321482806966418U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 13910818219761929659U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 8895973123729951173U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7540972911473176026U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5419023469522423893U;
            aOrbiterE = RotL64((aOrbiterE * 1380429266266313945U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2349651834739320824U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7651355040951791298U;
            aOrbiterA = RotL64((aOrbiterA * 3713776056028698433U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 12U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterF, 30U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD) + aNonceWordK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterE, 18U)) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 3U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterH, 35U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterK, 43U)) + aPhaseEWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 42U) + aOrbiterG) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18559U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 17659U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 17916U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18780U)) & S_BLOCK1], 50U) ^ RotL64(aInvestLaneD[((aIndex + 19459U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 40U)) ^ (RotL64(aIngress, 13U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 27U)) + 13650869943246163567U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 21U)) + 3435284932011770999U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 11U)) + 12388155658186776579U) + aNonceWordD;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 58U)) + 2374345913955712039U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 51U)) + 6095094526980292156U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 4965147025852444174U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 19U)) + 3261881216269075298U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 39U)) + 4939780217097329222U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 47U)) + 3019862009792676287U;
            aOrbiterA = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 901910626217143974U) + aNonceWordF;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 6U)) + RotL64(aCarry, 3U)) + 3647055146712366383U) + aNonceWordB;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7731765438957392967U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13409819457393479741U;
            aOrbiterB = RotL64((aOrbiterB * 3345078200262410715U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5415832109107794258U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8876738832313114471U;
            aOrbiterF = RotL64((aOrbiterF * 1304277600444504135U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17135570542519390359U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2373193062766802082U;
            aOrbiterD = RotL64((aOrbiterD * 4213691513185791519U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16318403285501718552U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8456043288604687045U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10556964529144571683U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10572534930284516528U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14616251186735204677U;
            aOrbiterK = RotL64((aOrbiterK * 2048651204265459805U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2837006243817205610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5315917323622194254U;
            aOrbiterA = RotL64((aOrbiterA * 4080522050089666599U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12084676282761185907U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7922080344175593788U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 7603522302708937379U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17620847289789547792U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12140386059533463650U;
            aOrbiterH = RotL64((aOrbiterH * 1443266480620969535U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4006608081473218762U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3152507055132739011U;
            aOrbiterJ = RotL64((aOrbiterJ * 11929522909695002321U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10845720206369283181U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16572752872386133133U;
            aOrbiterI = RotL64((aOrbiterI * 2891952650448087211U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 15544908026178481075U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 13650869943246163567U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 1275090431127426217U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 26U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterF, 24U)) + aNonceWordN);
            aWandererH = aWandererH + (((RotL64(aCross, 60U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 53U)) + aOrbiterF) + aNonceWordO) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 29U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aPrevious, 40U) + aOrbiterB) + RotL64(aOrbiterD, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterI, 36U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24417U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((aIndex + 22958U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 25614U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23407U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25970U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (aWandererC + RotL64(aIngress, 53U)) + 17225673071833726819U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 10301458382103627331U) + aPhaseEOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 3960233050857362414U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 17768665685046605837U;
            aOrbiterB = (aWandererK + RotL64(aCross, 41U)) + 14471018461213959767U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 50U)) + 10730597892721340453U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 21U)) + 14863394003122760542U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 39U)) + 9948587274816688296U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aWandererA + RotL64(aIngress, 13U)) + 3573569431435100993U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 46U)) + 8153670675740450590U) + aNonceWordB;
            aOrbiterE = (aWandererD + RotL64(aCross, 57U)) + 16438856577722561424U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15765587867581925041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1082039522061775213U;
            aOrbiterG = RotL64((aOrbiterG * 17023740047246402641U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4202521649260798876U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15877659681260461141U;
            aOrbiterB = RotL64((aOrbiterB * 11369910758551088173U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2551560426129646123U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3005102326163906320U;
            aOrbiterF = RotL64((aOrbiterF * 4241583192662435107U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1675501058857208089U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12774812270956702043U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5488437008504905105U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1044886020922563597U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4857445127457225171U;
            aOrbiterD = RotL64((aOrbiterD * 13223560654459705259U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11548725551787560962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2434677823189765161U;
            aOrbiterH = RotL64((aOrbiterH * 4283026044563670969U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9606875320524736294U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13732615866277657704U;
            aOrbiterC = RotL64((aOrbiterC * 3905528919281629775U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 13921743663803299567U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13350829301153929899U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11858642286713079795U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9473349030551400156U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7446792050826434742U;
            aOrbiterK = RotL64((aOrbiterK * 6619682184124713031U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17970527747978977453U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2326714817603921480U;
            aOrbiterA = RotL64((aOrbiterA * 14581676978186226887U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7875511075130474136U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17225673071833726819U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 1196024136909896027U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + aNonceWordC);
            aWandererC = aWandererC + ((RotL64(aIngress, 26U) + aOrbiterI) + RotL64(aOrbiterK, 43U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + aNonceWordP);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterB, 6U));
            aWandererF = aWandererF + ((((RotL64(aCross, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 53U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 27U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aScatter, 54U) + RotL64(aOrbiterD, 4U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 46U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32627U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 28127U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 29288U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32119U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneB[((aIndex + 27517U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 47U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 60U)) + 3621877681473089725U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 27U)) + 4451752751536414717U) + aNonceWordC;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 57U)) + 11371625415377772117U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 29U)) + 6046792758881150619U;
            aOrbiterC = ((((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 8213166120394461682U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 4343156661140422645U) + aNonceWordP;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 11105271483234947905U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 39U)) + 348904609985341372U) + aNonceWordA;
            aOrbiterG = (aWandererB + RotL64(aScatter, 21U)) + 12924652822526858767U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 37U)) + 7461211697358520287U;
            aOrbiterD = (aWandererF + RotL64(aCross, 54U)) + 16551553555297890558U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11908056404140782995U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9147367258259948715U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10777628928376261667U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8876461054692728610U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 10546855952702525404U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 10071104785895309677U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4748636139110443794U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 783046909529525098U;
            aOrbiterK = RotL64((aOrbiterK * 8969157702460927215U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16683965945838696665U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 12385412690177109575U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10795062772707143187U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8210546822184469023U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13146493623236979963U;
            aOrbiterH = RotL64((aOrbiterH * 13199947810161148155U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13857628148804187115U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7241297989337473475U;
            aOrbiterE = RotL64((aOrbiterE * 16223448508809614229U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 773904571213804946U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7660676598236419707U;
            aOrbiterG = RotL64((aOrbiterG * 14467390638468925567U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16822672435156055469U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6514707119190640433U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 7097496727567460535U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17784153215885060832U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16027189961519690419U;
            aOrbiterI = RotL64((aOrbiterI * 3248782394761733169U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 821916530432611671U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8764650990196504963U;
            aOrbiterA = RotL64((aOrbiterA * 6269514974278082251U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5987370764866753332U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3621877681473089725U;
            aOrbiterF = RotL64((aOrbiterF * 14763908964222787377U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + aPhaseEWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterI, 44U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 40U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterI, 37U));
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterB, 10U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 42U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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

void TwistExpander_Tennis_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCC48761243E2CAEBULL + 0xC122265DD2ABC4D6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBCA6B9FBA1800387ULL + 0xF200F155C64098A4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFDD6F2E5C071D1A1ULL + 0xDC05BF56A9A0011FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD45BE7B905EF67FBULL + 0xC089331F7BC8E154ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9DBCA34D19664757ULL + 0xFC653FCA26FBBA1EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF79294B1C4831C73ULL + 0xA58FE0D1713AA283ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE2F06F122AF701EFULL + 0x8933E426EFBC295BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF0CF3269524DA325ULL + 0xB454F8C91B0AD802ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x86DDF54ADA478727ULL + 0xEE9367451715D157ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC0C72B381B6A69C1ULL + 0xEB7867072BCFCF30ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCAD56BA38977C6B9ULL + 0xAC60E9163BAB8653ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9E1802D54A537111ULL + 0xD1D47B3DA124C142ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBB877566B2E89A1BULL + 0x9EF66B9E7D22522AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA8C2D4DE49CD2207ULL + 0xC4F68A3ECAF8087EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF16118C108624EEFULL + 0x9BCE3D0C6A208D68ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBE9053816B70C8F9ULL + 0xF0BFBE8A479848DFULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2448U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 5230U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5385U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2779U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2254U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5206U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 34U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 47U)) + 2617613537256538553U) + aNonceWordG;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 16642868916835132715U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 24U)) + RotL64(aCarry, 29U)) + 10860291124337073254U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 51U)) + 6432511273906902472U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 3U)) + 7505375005848241910U) + aPhaseFOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 29U)) + 11086616004678821329U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 3298830587569881951U) + aNonceWordC;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 57U)) + 9775143140064220979U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 14U)) + 4147601326580823120U) + aNonceWordJ;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12245920269898100415U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8391940489176734499U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 9119606167674098007U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17876893379544668477U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 18301882058180370541U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16680384667098921309U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6869225862715140102U) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15404118372589259800U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5766851935950389915U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17757381020518233814U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17677969146092374455U;
            aOrbiterA = RotL64((aOrbiterA * 3469432916562405063U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15783378556632870114U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5792858258663697864U;
            aOrbiterG = RotL64((aOrbiterG * 12008981883482080427U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11737803388202260296U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16001927091970715330U;
            aOrbiterH = RotL64((aOrbiterH * 3062030309852922061U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1749586939123286632U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6169421068855905938U;
            aOrbiterE = RotL64((aOrbiterE * 12374789910763348695U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 10073586820719728062U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17744171227198661555U;
            aOrbiterD = RotL64((aOrbiterD * 10658375268803957647U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1149819647337612792U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7725598665625892006U;
            aOrbiterI = RotL64((aOrbiterI * 15097586655234391559U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 6U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 46U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 40U)) + aOrbiterE) + aNonceWordM) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterI, 19U));
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterF, 23U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterF, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 42U) + aOrbiterJ) + RotL64(aOrbiterF, 36U));
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5716U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 5913U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8228U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8966U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6950U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5843U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7836U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 30U)) + 14249093584376402677U) + aNonceWordC;
            aOrbiterK = ((aWandererE + RotL64(aCross, 51U)) + 8756965951816492264U) + aNonceWordA;
            aOrbiterF = ((((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 11221139480258176330U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 3U)) + 17218894445564194851U) + aPhaseFOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aWandererH + RotL64(aIngress, 43U)) + 8064642692524949490U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 5822093203710704646U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 26U)) + RotL64(aCarry, 3U)) + 3217799620158102238U;
            aOrbiterB = (aWandererF + RotL64(aCross, 39U)) + 2613757677892120843U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 57U)) + 13647481499551657237U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3545714196663685016U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9735422670576621521U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7276207208162697249U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3911046580637583767U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9315984027042049203U;
            aOrbiterK = RotL64((aOrbiterK * 12568550776487242469U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8926367674641729058U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11035347490524961446U;
            aOrbiterE = RotL64((aOrbiterE * 10948288997163592463U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10748158733051120339U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2467801787989056455U;
            aOrbiterB = RotL64((aOrbiterB * 12621934274702358977U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9244415080474351390U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8517784887959492079U;
            aOrbiterH = RotL64((aOrbiterH * 17022899813765884147U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 8409307332803038455U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11043806021873232950U;
            aOrbiterA = RotL64((aOrbiterA * 8294888329708842989U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 17512395828450251457U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16849067939795823992U;
            aOrbiterI = RotL64((aOrbiterI * 9361991804481514337U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17541946638063238056U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11430501673960586718U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15074409630605450091U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 78307505705383302U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4834528975263832983U;
            aOrbiterG = RotL64((aOrbiterG * 17245673681686752861U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 60U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterG, 10U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 5U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 52U) + aOrbiterC) + RotL64(aOrbiterK, 56U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 35U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14048U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((aIndex + 16049U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 16058U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12497U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 12703U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 20U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 34U)) + 15549114274303128055U) + aNonceWordF;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 3U)) + 16466750056388063241U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 12209449840836787142U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 57U)) + 14551496099734294336U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 6266576428679808622U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 53U)) + 16892841575635668152U) + aNonceWordE;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 43U)) + 7375966221423362125U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 11926105302821753530U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 14U)) + 16219253791550461124U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7299056065319248160U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15234001484933728439U;
            aOrbiterD = RotL64((aOrbiterD * 8182244796017018911U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6615802589932632120U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5481176858895819247U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 3604590158551984877U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 17220507586542139380U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14137921473739415340U;
            aOrbiterJ = RotL64((aOrbiterJ * 10634645686035907603U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16981960446540932787U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10897565927079518588U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 418843936329303571U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2746889569299593263U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4894117146736361379U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 2656750612042673191U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18294823016957137777U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 86828501068883383U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11432686669235402365U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6322053762209547826U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6754524552483363820U;
            aOrbiterC = RotL64((aOrbiterC * 1746163087826694641U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7306452650619361017U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12717201204443785828U;
            aOrbiterH = RotL64((aOrbiterH * 6121251603905574991U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10422327053543898585U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14786413282036348183U;
            aOrbiterG = RotL64((aOrbiterG * 8713024293107068275U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 34U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 6U)) + aOrbiterA) + aNonceWordA);
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterE, 43U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + aPhaseFWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 58U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20199U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((aIndex + 16733U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 18848U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18510U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16846U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 54U)) + 9107326720193244489U) + aPhaseFOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 10868585484401664145U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 19U)) + 13637736741437846622U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 23U)) + 6130725216183918844U) + aNonceWordA;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 50U)) + 2063834478521338187U) + aNonceWordL;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 39U)) + 8564870627911949158U) + aNonceWordP;
            aOrbiterD = (aWandererA + RotL64(aCross, 27U)) + 6524015751064086390U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 9874937766875388236U) + aNonceWordE;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 43U)) + 14723718409522680894U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13767059954741528279U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6387608251033722169U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6601902195707980693U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5391425980008431000U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11524218415655093779U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12508457981779189389U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 155510463350385905U) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 10554591788433641311U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5412084824127934293U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8662160162966241542U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5092555636369853727U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 433807340167635499U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7163345798448796101U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 695089002178413267U;
            aOrbiterH = RotL64((aOrbiterH * 17302689458565434475U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5409173939213468972U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 15349690077393827541U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 10984681254001609841U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12376011890751302027U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7809614158898158383U;
            aOrbiterE = RotL64((aOrbiterE * 13845113198736843629U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 13031938699536449576U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3983178190194056516U;
            aOrbiterB = RotL64((aOrbiterB * 1341678482929213405U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5567935037909671790U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17137042627663349797U;
            aOrbiterJ = RotL64((aOrbiterJ * 13535586899620672373U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 39U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 48U) + aOrbiterK) + RotL64(aOrbiterE, 60U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterA, 10U)) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterG, 23U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 24U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23067U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneB[((aIndex + 24933U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25250U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25785U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 23220U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (aWandererD + RotL64(aIngress, 39U)) + 1210605127156905516U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 11964595428173569519U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 16277319029916258482U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 12369497463101824572U) + aPhaseFOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 18U)) + 6201248574067068202U) + aNonceWordB;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 13U)) + 1727477025667206661U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 47U)) + 1404510627789806851U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 3U)) + 6948213591282018925U) + aNonceWordC;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 54U)) + 6688865181284421478U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3351130769402360855U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12681032488906270823U;
            aOrbiterH = RotL64((aOrbiterH * 3680893896579741263U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3591412591193726763U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16153817571210878589U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4165137036092246349U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3808228354421006630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1427373776207504205U;
            aOrbiterA = RotL64((aOrbiterA * 4534374093769595531U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1831554180932501132U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 1114853085120949215U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4264176108298812905U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2080935638828366835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16104777999646489828U;
            aOrbiterD = RotL64((aOrbiterD * 15205199362011777473U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9782806013673440791U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3721620299829386454U;
            aOrbiterC = RotL64((aOrbiterC * 6286765834910272409U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4013706412064296527U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5751022780695158579U;
            aOrbiterG = RotL64((aOrbiterG * 13766736471646116397U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17684546333240329338U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1106947111128020920U;
            aOrbiterF = RotL64((aOrbiterF * 3158839453318658951U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11564229705849500598U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1585817314460274286U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12687162159791577431U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 20U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            aWandererF = aWandererF + ((RotL64(aScatter, 52U) + aOrbiterD) + RotL64(aOrbiterI, 4U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + aNonceWordF);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterG, 27U)) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 23U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 42U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterD, 54U));
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27713U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 28722U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 27925U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29998U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 30086U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 56U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 3199575576585871314U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 2533378188975571824U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 30U)) + 6819782112558312658U) + aNonceWordM;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 39U)) + 12690060987724798497U;
            aOrbiterB = (aWandererI + RotL64(aCross, 11U)) + 7088375139715629606U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 57U)) + 17785618677423695666U) + aNonceWordO;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 18U)) + RotL64(aCarry, 3U)) + 1714999280296491277U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 23U)) + 17611338506932491624U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 3U)) + 6475727359297421201U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2347744591204119530U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2739317903351401068U;
            aOrbiterF = RotL64((aOrbiterF * 15435029315209475631U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8663535261373274338U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8205245127823536479U;
            aOrbiterA = RotL64((aOrbiterA * 13857005110466856439U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 8916510616749754516U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3944805940148512932U;
            aOrbiterB = RotL64((aOrbiterB * 18082271583211389701U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14094751253118853302U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14094299829196076311U;
            aOrbiterD = RotL64((aOrbiterD * 6370012560657108493U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3940673811518673802U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3015106523254484839U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9655401190755573379U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15404103131982599922U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1828655763233900875U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13024358077740310049U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1236981890899916502U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 18208975564570342697U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 4577109989465876801U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17882273895471449661U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16196010765612713713U;
            aOrbiterC = RotL64((aOrbiterC * 15624856645134182005U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14639250100311162559U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9139027997336903273U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 1853126389565574293U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 34U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 46U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 37U)) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterD, 51U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterG, 43U));
            aWandererG = aWandererG + ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 4U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 21U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 28U) + RotL64(aOrbiterD, 39U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 60U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Tennis_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8D4EE1D7C3FF6DB9ULL + 0xDBA2DE0BC9C9E91FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAD6B684F469D1859ULL + 0xB341A1D1D4E3A1DBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC7ADD7A3C0B9C457ULL + 0x91B6B21FC5D9108CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA877DF9A33A4E45FULL + 0xAF1AD1B12795A79AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE07D606D24C7BB75ULL + 0x9645BE11CA491F22ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD3EE56FD3E30CF17ULL + 0xFC49BFF3A252751AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE15AFC4E898B8C93ULL + 0xA585448498491818ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE16CC299E5A6DABFULL + 0xA7CCA4D07A8A3E21ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x911AD787949E3923ULL + 0xDF26EC202ABBDFA0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAAE7D79E26E85911ULL + 0xEE5C6D7587EB8407ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDF555D73EA1684D7ULL + 0xB4D417AA2F3B0B7CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC6C25F12D9E2ABB3ULL + 0xF0CC519637FA17D5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9991B87ADD95DE63ULL + 0xC3AB9731298C5419ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x96A5C8D04DF91899ULL + 0xC513AA21BFE1DD41ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC496B3B25C040BB7ULL + 0xF9EF914C51B53D4BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF5FBB2F0879FBB81ULL + 0x8AB7B8DD87473E66ULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4590U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((aIndex + 165U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5355U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 746U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 1642U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2944U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 23U)) + 8685374557928800912U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 3482312691892161229U) + aNonceWordE;
            aOrbiterI = (aWandererI + RotL64(aScatter, 29U)) + 6948130297389161165U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 5506385663788942690U) + aNonceWordI;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 17859982009307397161U) + aPhaseHOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 37U)) + 9178488809207094043U) + aNonceWordN;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 44U)) + 1835479501226057169U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5368101733632614939U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9050459666576835422U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 10351719549990259551U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9042186993119635078U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17528342580198295025U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14316671546614386775U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6495418332558436882U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8834495762667327342U;
            aOrbiterJ = RotL64((aOrbiterJ * 10783141541937645995U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4364314196965690905U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6357485231062120459U;
            aOrbiterG = RotL64((aOrbiterG * 289429584586504995U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3321488322626415347U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10817330671781848737U;
            aOrbiterA = RotL64((aOrbiterA * 15875919466358823335U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17974092279281611763U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2871472057292789157U;
            aOrbiterH = RotL64((aOrbiterH * 16104199340711015181U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15187929795092006849U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13482063681546475923U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 14466266308157364963U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterG, 57U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterD, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterK, 12U)) + aNonceWordP) + aPhaseHWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 52U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10872U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneC[((aIndex + 5888U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10276U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneC[((aIndex + 7889U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6249U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8275U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7571U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 29U) + RotL64(aCross, 44U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 37U)) + 8767379393098711499U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 7168159491580816433U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 11U)) + 9879279829061883406U) + aNonceWordA;
            aOrbiterJ = ((((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 10537167136053399303U) + aPhaseHOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aWandererF + RotL64(aIngress, 3U)) + 2839070018069188936U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 51U)) + 13844278063968429732U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 44U)) + RotL64(aCarry, 11U)) + 11278946626186474646U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11798425216660557799U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7618446090703335192U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7168757300685156779U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 695423597006983660U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14344728202803488813U;
            aOrbiterI = RotL64((aOrbiterI * 5168825904902285909U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11656100506575697086U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10384358779985773937U;
            aOrbiterE = RotL64((aOrbiterE * 247494692039140973U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17585001605131977341U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 9964478171465522911U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13484044854790175315U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 2710943171829692624U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17809072853457153057U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 16341884203303271365U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12814092033910687774U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1743186323268668740U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11150822630624332557U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10750472346626754704U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15925901217078035356U;
            aOrbiterG = RotL64((aOrbiterG * 9276504171291801637U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 41U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 13U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterG, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 11U));
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterB, 54U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16301U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneA[((aIndex + 14199U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 14514U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11764U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneC[((aIndex + 11926U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = ((((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 12262991801139086177U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 7963038771924890197U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 58U)) + 15540520327933568896U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 37U)) + 8745565892055020722U) + aNonceWordN;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 51U)) + 16619329199683755286U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 21U)) + 10865705026433867260U) + aNonceWordK;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 2743368697984518059U) + aPhaseHOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5556006271515473135U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5355833281353498588U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4190140212757841511U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8313616108963479829U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16657121016801866434U;
            aOrbiterC = RotL64((aOrbiterC * 331533349428472477U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16532226425013000833U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5800465874932467232U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 5966395771690704577U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17882948163883121328U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15029375310296563175U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 17021415832288477713U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10170682648007918739U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11829089574189398773U;
            aOrbiterH = RotL64((aOrbiterH * 15755874363488568849U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 1746524867389196322U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10217423427886742775U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9166162099575333519U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1338457710729082656U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1319981417675542556U;
            aOrbiterA = RotL64((aOrbiterA * 9518448254565489715U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 28U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 37U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterA, 29U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 58U) + aOrbiterA) + RotL64(aOrbiterJ, 22U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 39U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21797U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 17522U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 17685U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19188U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneD[((aIndex + 18331U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCarry, 41U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (((aWandererK + RotL64(aIngress, 44U)) + RotL64(aCarry, 41U)) + 11177787645248006236U) + aNonceWordP;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 57U)) + 3808340254579817169U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aWandererJ + RotL64(aCross, 3U)) + 828030667598518279U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 27U)) + 16177835921238398371U) + aNonceWordD;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 35U)) + 5518747735458708741U) + aPhaseHOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 17346319082399995165U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 6397156921893030937U) + aNonceWordL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15559381654710713582U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 940404446491415088U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16401260971303026881U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 8047166032048732645U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4688468645859470491U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 14383536431614496369U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3710878044770337260U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 116343189456629220U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 5637725064169289339U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 883908030159391659U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 18058691521694880482U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3132200449123497619U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17521015077103586117U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3668332225435714918U;
            aOrbiterE = RotL64((aOrbiterE * 12658899101297839881U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12229480388278883300U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16206524049491531816U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11122340196620859805U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5743265849441077466U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2812293020719282236U;
            aOrbiterA = RotL64((aOrbiterA * 8903956475200417109U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 43U)) + aOrbiterK) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 21U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 50U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 5U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23750U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 24410U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 25022U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25293U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 25386U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 2571116506511057880U) + aNonceWordK;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 13112435411509707292U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 43U)) + 10403251762787357256U) + aPhaseHOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 8461951095541400405U) + aPhaseHOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 14U)) + 9890793478557463815U) + aNonceWordL;
            aOrbiterC = (aWandererJ + RotL64(aCross, 37U)) + 3030229465991783707U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 51U)) + 7273848154043719247U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10681774862516028276U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7105082755586853104U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 12217705329504230357U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6588579345319551129U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14616333550242386092U;
            aOrbiterB = RotL64((aOrbiterB * 2934574715879306337U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15439666290229654921U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3360304356760164799U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5164191920584106237U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14438730801970761889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14515616787452085729U;
            aOrbiterA = RotL64((aOrbiterA * 2041601927968559821U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4167853822635132419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8950982233003320239U;
            aOrbiterG = RotL64((aOrbiterG * 887144270884244907U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12391327853728029953U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7100871010552394421U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 16552349374101955967U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15381697462381887944U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 6801677551341079401U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 13325954438427340703U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 47U)) + aOrbiterG) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterK, 28U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + aPhaseHWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31834U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 32512U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 29646U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27741U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 28691U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 22U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 51U)) + 10038936806177516123U) + aNonceWordA;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 57U)) + 1773168435195292638U) + aNonceWordD;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 11U)) + 10655711161526628072U) + aPhaseHOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 35U)) + 14422295664639740437U) + aNonceWordI;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 44U)) + RotL64(aCarry, 23U)) + 4125228715513159576U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 3670449653158650845U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aPrevious, 3U)) + 17553727567180813057U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5111401772713882743U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7688573124662314413U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 10846442063022821393U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9438375825507814395U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14177477039902118886U;
            aOrbiterC = RotL64((aOrbiterC * 6467406626985022537U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16329942595859623928U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3990536794006836672U;
            aOrbiterA = RotL64((aOrbiterA * 579024714339065373U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5072881436583180756U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16789727877867289997U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8766246302636197905U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 17313956922306689438U) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11530878396329822041U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11356860047841383129U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3612616532321160196U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4172189825359187763U;
            aOrbiterH = RotL64((aOrbiterH * 12938945495299393177U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8677279703778052804U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1912172980909479362U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10053289257955474143U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 41U)) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + aNonceWordB);
            aWandererG = aWandererG + (((((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordE) + aPhaseHWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterE) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 47U)) + aOrbiterE) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 35U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 34U) + RotL64(aOrbiterC, 26U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererG, 10U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Tennis_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1277U)) & W_KEY1], 12U) ^ RotL64(aKeyRowReadB[((aIndex + 250U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 76U)) & W_KEY1], 41U) ^ RotL64(mSource[((aIndex + 1933U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCross, 36U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererB + RotL64(aCross, 53U)) + 13296600294247799698U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 26U)) + 5818503518080877515U) + aPhaseAOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 3U)) + 6735784238734173597U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 7368398209488856201U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 961734029066455638U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 11U)) + 797011946660892011U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 34U)) + 12841876018396622350U) + aPhaseAOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 16213253970483895623U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 57U)) + 15186950557113470375U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5117930310827477341U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12265429373166094162U;
            aOrbiterB = RotL64((aOrbiterB * 1522823535151532249U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13920531346698601568U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14695405206998211456U;
            aOrbiterA = RotL64((aOrbiterA * 13950964363414164279U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7851960904825938443U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9501511171732550190U;
            aOrbiterC = RotL64((aOrbiterC * 5614164120361489613U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5663365182245722077U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9607860124321315555U;
            aOrbiterG = RotL64((aOrbiterG * 3461820361914280601U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18171052650586819280U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3442698321538580861U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6317525514963824829U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1491052813469258970U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3956599824067616133U;
            aOrbiterF = RotL64((aOrbiterF * 2928600779267623085U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10963841237346073453U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2303020125591252534U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9969099842343321981U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14503856057958162356U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11147548150090597694U;
            aOrbiterD = RotL64((aOrbiterD * 11856382308792700441U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9191681438318311481U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 13556072770381999852U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18316231099054203683U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 14U);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 38U) + RotL64(aOrbiterG, 6U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + aPhaseAWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterI, 11U));
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererG = aWandererG + (((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterH, 60U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 58U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4278U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3390U)) & W_KEY1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3920U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4205U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 58U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererI + RotL64(aIngress, 37U)) + 6381335981879993247U) + aPhaseAOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 15595429101600023172U;
            aOrbiterI = (aWandererC + RotL64(aCross, 56U)) + 5449234297249826461U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 47U)) + 11213734849329731168U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 19U)) + 16438473952464514248U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 23U)) + 7357872882115186976U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 14U)) + 394402075160738643U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 11112941985410283532U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 14955125011182736212U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 14770727009821304070U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11286366598129204910U;
            aOrbiterI = RotL64((aOrbiterI * 15884310771003021989U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7358400908565425780U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15635109923749114761U;
            aOrbiterK = RotL64((aOrbiterK * 12415152149408700329U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13826842523738623579U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1072811298828325231U;
            aOrbiterA = RotL64((aOrbiterA * 9662800288646215083U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4017334196009350776U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8812213572751410831U;
            aOrbiterJ = RotL64((aOrbiterJ * 12744171921566782795U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6723457786170634403U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9785583533999417673U;
            aOrbiterH = RotL64((aOrbiterH * 7776915427605471097U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10265132640322153964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8435670887514808087U;
            aOrbiterB = RotL64((aOrbiterB * 2706263045620662131U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4303823386961718326U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4214384238167491037U;
            aOrbiterG = RotL64((aOrbiterG * 8490707334221154005U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8740835037840799136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5988815405391206280U;
            aOrbiterE = RotL64((aOrbiterE * 17838555472135715929U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15539461383052981747U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3743772525784217714U;
            aOrbiterD = RotL64((aOrbiterD * 6352086797545969187U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 46U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 34U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterI, 12U));
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterH, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterE, 43U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 4U) + aOrbiterA) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 53U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 40U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 6645U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7858U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6678U)) & W_KEY1], 24U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5669U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6630U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 16922357079016918108U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 41U)) + 11771749797137599131U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 4635668433708036077U;
            aOrbiterC = (aWandererG + RotL64(aCross, 52U)) + 15827952719230577008U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 5U)) + 1495675306110023086U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 37U)) + 7294835466949728365U) + aPhaseAOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 179122461212041978U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 23U)) + 545981421632236251U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 58U)) + 15338259639814630535U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12924313840290895215U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17846785921286020610U;
            aOrbiterD = RotL64((aOrbiterD * 18309347016029917133U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5721472794107057875U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16359630793856870319U;
            aOrbiterF = RotL64((aOrbiterF * 14186771515526698907U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10614102110239037308U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16421992251278236531U;
            aOrbiterC = RotL64((aOrbiterC * 2561232904676068089U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8668149834861244963U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12699331834360948734U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2249360824172616357U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4470693178142950471U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 526000656022724741U;
            aOrbiterI = RotL64((aOrbiterI * 16688501462334673493U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6880246132270094141U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7126466778855297013U;
            aOrbiterJ = RotL64((aOrbiterJ * 5692237926830293205U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6436404501390442054U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1213633065612242699U;
            aOrbiterK = RotL64((aOrbiterK * 17604454985534439259U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8186529105901185854U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10607460957358250935U;
            aOrbiterE = RotL64((aOrbiterE * 17172191011625677861U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9743278964993305169U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14007577681873418075U;
            aOrbiterG = RotL64((aOrbiterG * 4231122580398039133U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 34U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterE, 4U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterG, 51U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 41U));
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 56U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 46U) + aOrbiterI) + RotL64(aOrbiterF, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 21U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterG, 27U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9900U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 10917U)) & W_KEY1], 4U));
            aIngress ^= (RotL64(mSource[((aIndex + 10492U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9832U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8819U)) & W_KEY1], 57U) ^ RotL64(aFireLaneB[((aIndex + 8838U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 34U)) + 9107326720193244489U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 10868585484401664145U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 13637736741437846622U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 6130725216183918844U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aScatter, 5U)) + 2063834478521338187U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 23U)) + 8564870627911949158U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 19U)) + 6524015751064086390U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 42U)) + 9874937766875388236U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 53U)) + 14723718409522680894U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13767059954741528279U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6387608251033722169U;
            aOrbiterJ = RotL64((aOrbiterJ * 6601902195707980693U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5391425980008431000U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11524218415655093779U;
            aOrbiterD = RotL64((aOrbiterD * 12508457981779189389U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 155510463350385905U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10554591788433641311U;
            aOrbiterG = RotL64((aOrbiterG * 5412084824127934293U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8662160162966241542U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5092555636369853727U;
            aOrbiterA = RotL64((aOrbiterA * 433807340167635499U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 7163345798448796101U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 695089002178413267U;
            aOrbiterI = RotL64((aOrbiterI * 17302689458565434475U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5409173939213468972U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15349690077393827541U;
            aOrbiterH = RotL64((aOrbiterH * 10984681254001609841U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12376011890751302027U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7809614158898158383U;
            aOrbiterK = RotL64((aOrbiterK * 13845113198736843629U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13031938699536449576U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3983178190194056516U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1341678482929213405U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5567935037909671790U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17137042627663349797U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13535586899620672373U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 34U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterF, 23U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 36U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterD, 46U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12454U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 11250U)) & W_KEY1], 28U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13555U)) & W_KEY1], 47U) ^ RotL64(mSource[((aIndex + 12041U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12350U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13062U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10929U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererH + RotL64(aIngress, 18U)) + 18144572925667544139U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 5659758077574059728U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 57U)) + 6343330616999166392U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 39U)) + 17754639838410839447U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 9451843819849581729U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 43U)) + 7957854457197462212U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 10U)) + 1461994799722205010U) + aPhaseBOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 18002214276252170177U;
            aOrbiterD = (aWandererB + RotL64(aCross, 29U)) + 14689869073147027164U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3978104368003440293U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8512135845221335386U;
            aOrbiterJ = RotL64((aOrbiterJ * 10506667163729414667U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1477533446382953439U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2166717790929947990U;
            aOrbiterA = RotL64((aOrbiterA * 6538884492418324461U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8082437060686606995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4363687722464700362U;
            aOrbiterG = RotL64((aOrbiterG * 7199165810993478887U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15782763348014924206U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8572509150015960728U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3340528604891897779U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12248271773316742521U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9602078627638561949U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1860631869877427405U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17244849374768558859U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 1030743048280579012U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10858949914285817051U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17722342363541914280U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15667504059789880034U;
            aOrbiterE = RotL64((aOrbiterE * 15872269872168533709U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12645332941998550794U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9938135244509986497U;
            aOrbiterF = RotL64((aOrbiterF * 16548185968987392957U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4024609904162105979U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6732064218696157303U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3815409766145891393U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 10U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 27U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 4U) + RotL64(aOrbiterE, 10U)) + aOrbiterA) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 39U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 14U)) + aOrbiterA) + aPhaseBWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 26U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 13769U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15252U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14491U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14813U)) & W_KEY1], 47U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14381U)) & S_BLOCK1], 18U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16265U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 15873U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 20U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aPrevious, 11U)) + 15904465836916519864U;
            aOrbiterE = (aWandererK + RotL64(aCross, 29U)) + 17725629806317789307U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 53U)) + 13794170125914914828U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 24U)) + RotL64(aCarry, 5U)) + 2149055907476874332U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 5342047776745074649U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 39U)) + 8268148484060546838U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 47U)) + 10821151364028563719U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 58U)) + 4294213820894407378U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 10884726101307943090U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16432210042202444824U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15196602644336228055U;
            aOrbiterH = RotL64((aOrbiterH * 12680438355124070237U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14117787670220328165U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 219833877949480215U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10736293047771972173U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3326396981881473962U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14918513066311426279U;
            aOrbiterK = RotL64((aOrbiterK * 14269763278564574663U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11795234681370163206U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3068267285352664813U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15746255933920904619U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 245233356957999496U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 709926406353796673U;
            aOrbiterI = RotL64((aOrbiterI * 13627039596842073595U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5378105439430271038U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10114555061122044430U;
            aOrbiterA = RotL64((aOrbiterA * 5351295043424885549U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13233010815716769713U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8231291294833548389U;
            aOrbiterG = RotL64((aOrbiterG * 10840516135212753869U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7160760224172419829U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14767926435411546785U;
            aOrbiterJ = RotL64((aOrbiterJ * 1643485739468851073U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4464245330038080103U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15778166658285494712U;
            aOrbiterE = RotL64((aOrbiterE * 13980891936095282989U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 50U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterE, 60U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 47U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 14U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + aPhaseBWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterH, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 4U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16686U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadA[((aIndex + 17496U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 17195U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((aIndex + 18231U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17654U)) & W_KEY1], 57U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18390U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 18927U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererE + RotL64(aCross, 58U)) + 13880995121909552664U) + aPhaseCOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 29U)) + 14534942818069300546U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 13U)) + 17745973100886007133U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 2249805580771946872U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 3U)) + 4460116116396439410U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 39U)) + 3378683994078106878U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 24U)) + RotL64(aCarry, 11U)) + 3992996501048809123U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 51U)) + 12057768808864451929U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 4115362079047921130U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15297384955502206698U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17623548383481905636U;
            aOrbiterB = RotL64((aOrbiterB * 7487278217901483685U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3559213898000162417U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12311605719074507335U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3982199462062847697U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14807313864347885885U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11222085523291581822U;
            aOrbiterK = RotL64((aOrbiterK * 12580941911587215653U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 916681229436292462U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2441350114032314686U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7336079498999018067U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7361470539894653271U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12153585147213579808U;
            aOrbiterC = RotL64((aOrbiterC * 3040327545467672961U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13566300726101613579U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14875254144748509128U;
            aOrbiterG = RotL64((aOrbiterG * 13699179902908972403U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9268158535644002904U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14144295981814993491U;
            aOrbiterJ = RotL64((aOrbiterJ * 12739937231684038161U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13861225650900541642U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12620513474052058164U;
            aOrbiterF = RotL64((aOrbiterF * 18141974182442267181U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14163773386433257965U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5725700029399455855U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10446930901088908809U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 56U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterB, 18U));
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 3U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 57U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 34U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 23U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 46U) + aOrbiterJ) + RotL64(aOrbiterG, 41U)) + aPhaseCWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterI, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 40U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19531U)) & S_BLOCK1], 30U) ^ RotL64(mSource[((aIndex + 20724U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19997U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((aIndex + 20262U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19149U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19195U)) & W_KEY1], 29U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21553U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20608U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 10U)) ^ (RotL64(aCross, 57U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 5U)) + 9914837590440975587U) + aPhaseCOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 43U)) + 6706125076401958051U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 53U)) + 16570817772679258409U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 10U)) + 6843705658115186948U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 16099930446791572351U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 5420550009556030459U;
            aOrbiterI = (aWandererB + RotL64(aCross, 29U)) + 5729549069420177477U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 15590601126188675834U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 14U)) + 13044027390998620029U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11068338135659636772U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6584988841809544332U;
            aOrbiterC = RotL64((aOrbiterC * 1683336180438945439U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8516813219883915404U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10647314042912492785U;
            aOrbiterF = RotL64((aOrbiterF * 15559481057047148785U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 201691689889605304U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15512161798401184003U;
            aOrbiterK = RotL64((aOrbiterK * 11473219183982564709U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3883760518944464145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13861805129175491145U;
            aOrbiterH = RotL64((aOrbiterH * 17194438894492581181U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12019138626550801486U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13030350224959652248U;
            aOrbiterA = RotL64((aOrbiterA * 11724200983306280107U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2643807255422544248U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4127143302485631794U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5441038881111578487U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14602951930809633069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4555737199162278494U;
            aOrbiterB = RotL64((aOrbiterB * 12415825635220991865U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6343143902997169834U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10404783711336491985U;
            aOrbiterI = RotL64((aOrbiterI * 6235474458879439079U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7406959231434835393U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6684368109277850196U;
            aOrbiterG = RotL64((aOrbiterG * 8760360417572331159U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 26U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterI, 60U));
            aWandererG = aWandererG + (((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterH, 51U));
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF + ((((RotL64(aCross, 43U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 36U) + aOrbiterF) + RotL64(aOrbiterE, 24U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23732U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadA[((aIndex + 22018U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24406U)) & W_KEY1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 24288U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22494U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24323U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23432U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((aIndex + 22042U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 36U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aScatter, 39U)) + 9630214189402543339U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aPrevious, 47U)) + 4072576573737526819U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 23U)) + 15994787452709618869U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 18U)) + RotL64(aCarry, 29U)) + 6403240137132259482U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 10229266900170507720U) + aPhaseCOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 11U)) + 5025294577989748989U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 5U)) + 16696461238217956883U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 34U)) + RotL64(aCarry, 39U)) + 9878318855341719119U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 29U)) + 16086635438116177346U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12295437783084203730U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7681150419912842402U;
            aOrbiterA = RotL64((aOrbiterA * 7289497379725191451U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2639104034287637448U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12298170009332243573U;
            aOrbiterB = RotL64((aOrbiterB * 9397919591171238575U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3485932317267669626U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16569551670038752475U;
            aOrbiterE = RotL64((aOrbiterE * 8139802826402217631U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4448490103784103954U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14510534073046885941U;
            aOrbiterD = RotL64((aOrbiterD * 7777192047386438305U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4286195398675733451U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15790355933840266463U;
            aOrbiterC = RotL64((aOrbiterC * 13342257823027075501U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6362891510370156055U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15121822034579983174U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7268045994574844937U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13817341015719915628U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14113474087906143783U;
            aOrbiterH = RotL64((aOrbiterH * 12838910141533126059U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9988301252236121106U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11287477288382171758U;
            aOrbiterJ = RotL64((aOrbiterJ * 4979297247881426383U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9491727010910328644U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7961202721830514030U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16300364540313620767U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 40U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterA, 56U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterB, 3U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 52U) + aOrbiterH) + RotL64(aOrbiterD, 34U)) + aPhaseCWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 19U));
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 27U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterI, 47U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26081U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[((aIndex + 24673U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25288U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26003U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27124U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24953U)) & S_BLOCK1], 12U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25158U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25982U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 38U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererB + RotL64(aScatter, 24U)) + 12380376990224645149U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 18296928500297384014U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 19U)) + 3550626816361145100U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 2667792936946706027U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 5U)) + 12020969779370926953U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 28U)) + 737340727886903447U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 57U)) + 1681797651799760502U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 2956186342689489064U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 43U)) + 1876852870402977177U) + aPhaseDOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6433205819353555071U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9065076854974222998U;
            aOrbiterE = RotL64((aOrbiterE * 5459675878087242021U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3254410578766789992U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2005081975473815576U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9947701153722014085U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15992999234834560419U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3458344156815120948U;
            aOrbiterJ = RotL64((aOrbiterJ * 1668460113964608051U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17069783053664877727U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1260234710193913099U;
            aOrbiterF = RotL64((aOrbiterF * 4561226779897414381U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3825186451876061335U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2905344294992827535U;
            aOrbiterA = RotL64((aOrbiterA * 2469896090698580795U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 18141402347899180617U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8760129857609925066U;
            aOrbiterB = RotL64((aOrbiterB * 2507999156108123047U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 594052473780678210U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13216719212966128379U;
            aOrbiterH = RotL64((aOrbiterH * 10691355329696722303U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10029948739466316169U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11912428807431992996U;
            aOrbiterK = RotL64((aOrbiterK * 85016510811938307U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8735634019801417287U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12785916159063273545U;
            aOrbiterD = RotL64((aOrbiterD * 1161917531260663357U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 26U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 48U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aPrevious, 30U) + aOrbiterK) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 36U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterE, 53U)) + aOrbiterC) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28277U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 27672U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27430U)) & W_KEY1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 29590U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28153U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28543U)) & S_BLOCK1], 6U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29676U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29278U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererI + RotL64(aIngress, 19U)) + 4751694786009671052U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 16362725160370844224U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 44U)) + RotL64(aCarry, 23U)) + 6360885380915941057U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 11U)) + 5154536007972297036U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 53U)) + 9362540581874808253U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 27U)) + 13902493871525612934U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 10208452885367546542U) + aPhaseDOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 60U)) + 3117030377279160998U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 35U)) + 17286247690414027870U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3930314320040949141U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7289525252391668404U;
            aOrbiterI = RotL64((aOrbiterI * 15452162299105112187U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3434167955466809185U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17852573095128575663U;
            aOrbiterH = RotL64((aOrbiterH * 1485660158767033425U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6137259687928853253U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13992510605237574698U;
            aOrbiterG = RotL64((aOrbiterG * 15346263295995333395U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6470556523400123474U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4333255670390099293U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11089933812030082647U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7700424876430257995U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16920736951239453071U;
            aOrbiterK = RotL64((aOrbiterK * 8920407493132380497U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1635071690430295730U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9966700845966398620U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17210048121896546867U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9833458070123027075U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1990346556486746432U;
            aOrbiterA = RotL64((aOrbiterA * 8704943923474148699U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13339523466436517327U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5018264760406215603U;
            aOrbiterB = RotL64((aOrbiterB * 2769197961801783627U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 123427497520755346U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4535841104215792886U;
            aOrbiterJ = RotL64((aOrbiterJ * 1417676310539177131U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 40U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 53U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 30U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aCross, 22U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 23U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 34U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterC, 13U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererI, 48U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30839U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30257U)) & W_KEY1], 44U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32059U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32510U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30643U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 31010U)) & W_KEY1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 10U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aIngress, 57U)) + 8685374557928800912U;
            aOrbiterG = (aWandererC + RotL64(aCross, 47U)) + 3482312691892161229U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 18U)) + RotL64(aCarry, 19U)) + 6948130297389161165U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 5506385663788942690U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 35U)) + 17859982009307397161U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 9178488809207094043U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 11U)) + 1835479501226057169U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 28U)) + 5368101733632614939U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 43U)) + 9050459666576835422U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9042186993119635078U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17528342580198295025U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14316671546614386775U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6495418332558436882U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8834495762667327342U;
            aOrbiterD = RotL64((aOrbiterD * 10783141541937645995U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4364314196965690905U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6357485231062120459U;
            aOrbiterK = RotL64((aOrbiterK * 289429584586504995U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3321488322626415347U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10817330671781848737U;
            aOrbiterC = RotL64((aOrbiterC * 15875919466358823335U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17974092279281611763U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2871472057292789157U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16104199340711015181U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15187929795092006849U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13482063681546475923U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14466266308157364963U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6232152545071397380U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17488906002621373262U;
            aOrbiterI = RotL64((aOrbiterI * 4719340606442742577U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12444819880507588549U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13808941689757772497U;
            aOrbiterH = RotL64((aOrbiterH * 6541360905282412317U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8049361354387692374U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7137831335606542401U;
            aOrbiterG = RotL64((aOrbiterG * 11022231291507235007U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 12U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 10U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterF, 21U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 26U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterD, 35U)) + aOrbiterI) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterG, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 6U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Tennis_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2521U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 5784U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 6806U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5704U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2788U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1857U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 12U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 51U)) + 16124889768301047791U) + aPhaseEOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 3U)) + 11912338587186717280U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 8594012868813114354U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 18281043566156682815U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 58U)) + 16853106130200942302U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 2611212958619673086U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 37U)) + 18039472325066855180U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14495785571345122046U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4556063793412832418U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13166927543135467627U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14896419970271244358U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 880028529183500036U;
            aOrbiterA = RotL64((aOrbiterA * 14228281807461251361U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2379557167489415783U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11854373946064529806U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 150755294320438887U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1487252775956449964U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12777924204511625545U;
            aOrbiterF = RotL64((aOrbiterF * 1366019527386994789U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15998631485222477969U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8864212892296191613U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 579242788050369815U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17069347835763226743U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7443008171694679791U;
            aOrbiterI = RotL64((aOrbiterI * 748894368884566607U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17334256152350782002U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8986626119086556393U;
            aOrbiterK = RotL64((aOrbiterK * 2258172145924120235U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 40U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterD, 35U));
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterH, 12U));
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8716U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 8798U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 12935U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((aIndex + 10637U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14505U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12399U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10204U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aIngress, 13U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 23U)) + 785861751704720606U;
            aOrbiterI = (aWandererD + RotL64(aCross, 43U)) + 15968088718435606299U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 37U)) + 1393976526590347151U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 17240750947292745884U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 57U)) + 4921576136163183137U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 13U)) + 3334047873553153032U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 15086509978458408698U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 892391205397581998U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2965686403183767521U;
            aOrbiterC = RotL64((aOrbiterC * 709160942482770225U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14632215393655706170U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15740589515342377322U;
            aOrbiterB = RotL64((aOrbiterB * 15677716942904794913U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11131164813943086445U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6988080581278900960U;
            aOrbiterG = RotL64((aOrbiterG * 6412189142344044255U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16021254613117657178U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6183615599897921154U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9976411093264211033U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12533992547026652747U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3104325358982904219U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14977348108778147265U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3878525937957474644U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2120435259884368445U;
            aOrbiterI = RotL64((aOrbiterI * 15964718652193073177U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14928658302694194856U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9121310461310309348U;
            aOrbiterJ = RotL64((aOrbiterJ * 17304439784647477491U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 37U));
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterH, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterC, 29U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 60U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 56U) + aOrbiterC) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19776U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 19823U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 16805U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 19489U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19635U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18950U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22904U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 21U)) + 5480870806135400132U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 60U)) + 8034874599430768743U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 47U)) + 4006919843736863767U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 35U)) + 2988069748674633718U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 12347295651973135786U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 14152683894431568192U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 15765143815254196598U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10473067082331244233U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1089466925383677249U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17334888609179149753U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13215039929873682230U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3957997712247961479U;
            aOrbiterC = RotL64((aOrbiterC * 7631186240013784703U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10023907397941685546U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14593012591254614353U;
            aOrbiterJ = RotL64((aOrbiterJ * 17111300092082154687U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13353797968154036726U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9259966668512102858U;
            aOrbiterI = RotL64((aOrbiterI * 8326732574268308221U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10757861831070349321U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10530223113483866178U;
            aOrbiterK = RotL64((aOrbiterK * 11269177745265396583U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7554320926405521865U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6978052067277966996U;
            aOrbiterA = RotL64((aOrbiterA * 18020134738536217801U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 1053695861967171420U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15980734683539854451U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3208466640010555357U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 6U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterE, 35U));
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aPhaseEWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterI, 29U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterH, 42U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 20U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25880U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 25114U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 24941U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26741U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29131U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32610U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25162U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 38U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 12U)) + 14008824488073394623U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 37U)) + 13317978415866411468U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 13209180141897453900U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 29U)) + 11870521586865233578U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 3U)) + 8052156380448047385U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 12158131176743680605U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 14674467487607719347U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18055496790566231147U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3838105585041578784U;
            aOrbiterI = RotL64((aOrbiterI * 1075709247574580091U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 2839568255183054418U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11933612922864258179U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7571964469321160347U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6289849094151630580U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2640344350528492271U;
            aOrbiterF = RotL64((aOrbiterF * 16197726750829369365U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16306175266267657791U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3339898380394883600U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7105436590182982373U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15017076663742800002U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8973064296077602496U;
            aOrbiterK = RotL64((aOrbiterK * 9309462227233615761U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17580319233338139859U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14063208878807603874U;
            aOrbiterD = RotL64((aOrbiterD * 16601475239075164585U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13326130855721009942U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12843186026737544416U;
            aOrbiterJ = RotL64((aOrbiterJ * 4975848122837321619U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 48U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterA, 21U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterD, 37U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterH, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Tennis_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1604U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 6305U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3987U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1091U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3022U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2670U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 13924571355038625040U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aIngress, 50U)) + 16328300979357156658U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 3947771961206012461U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 47U)) + 15428284250569311285U;
            aOrbiterG = (aWandererB + RotL64(aCross, 21U)) + 5777369485254032486U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 53U)) + 16813320300717644673U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aPrevious, 42U)) + 16689933050200758251U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 11U)) + 1856422419049390708U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 35U)) + 18214498743831925517U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 57U)) + 18278550878494094923U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 797712062039591797U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15854849439012341347U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 996882939768167773U;
            aOrbiterF = RotL64((aOrbiterF * 14936703950807908575U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3005829974130671692U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8793495343509953906U;
            aOrbiterB = RotL64((aOrbiterB * 14065479348374612031U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7710453029930631112U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9511995836117707047U;
            aOrbiterG = RotL64((aOrbiterG * 7250766204781428201U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 670902975693341744U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9045820304668279777U;
            aOrbiterJ = RotL64((aOrbiterJ * 18373074917532639027U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12417212387607119470U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12816983560669985622U;
            aOrbiterI = RotL64((aOrbiterI * 8406003970221889847U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17245432086377688540U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6806521945548502014U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11335859481858640857U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8947500746292365294U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4468060468522895852U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7022481284816599797U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9892975931958803992U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3042599331526937836U;
            aOrbiterA = RotL64((aOrbiterA * 3308512896171443645U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12991568221485810891U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8551331172836260315U;
            aOrbiterE = RotL64((aOrbiterE * 4509997595920847057U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 183547209633334407U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17275712817092769452U;
            aOrbiterK = RotL64((aOrbiterK * 15677355290000929085U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12743863879392372723U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13924571355038625040U;
            aOrbiterC = RotL64((aOrbiterC * 11966689345179279407U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 52U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 34U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 56U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 48U) + aOrbiterC) + RotL64(aOrbiterJ, 21U));
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 38U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterD, 13U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14901U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 10145U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 15477U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 13626U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8593U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10417U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12071U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 5131645209694953015U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 44U)) + 12070391048835379854U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 37U)) + 2604295836242338724U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 14042039029284001596U) + aPhaseFOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 23U)) + 8914654543854559327U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 51U)) + 2185619407969359869U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 27U)) + 5187406295103352574U;
            aOrbiterA = (aWandererB + RotL64(aCross, 42U)) + 8022832481290871217U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 53U)) + 8783061916740573472U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 10711028365596196301U;
            aOrbiterE = (aWandererF + RotL64(aCross, 3U)) + 13387065038269133571U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11187001318931801582U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 14191473173276034019U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2491253922434756431U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16207761776716426435U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9677408414452078760U;
            aOrbiterI = RotL64((aOrbiterI * 5487303383095129949U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17812460332794370649U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7736423148554132028U;
            aOrbiterG = RotL64((aOrbiterG * 15588733747232852555U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17293203944059014763U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 13487243633338010243U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9468688858740539095U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15979293016815060755U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17645215484691359547U;
            aOrbiterJ = RotL64((aOrbiterJ * 1449450767288733995U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11635961468586927692U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10530136578329059784U;
            aOrbiterE = RotL64((aOrbiterE * 8785021493374398437U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4900370530116992731U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15952900504821599445U;
            aOrbiterC = RotL64((aOrbiterC * 5413316082800365261U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9938000151832814778U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14170277411106520726U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5058343552974910737U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14091010427448547620U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13658560822164111421U;
            aOrbiterF = RotL64((aOrbiterF * 9523184040517290629U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13954269172267844623U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3921811946419945868U;
            aOrbiterA = RotL64((aOrbiterA * 6839440867046147039U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14296483810577739898U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5131645209694953015U;
            aOrbiterH = RotL64((aOrbiterH * 10190969526209064367U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 34U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 54U) + RotL64(aOrbiterI, 28U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 41U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterB, 3U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterF, 57U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 37U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterA, 60U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17645U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 16738U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 23798U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 18709U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18046U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24388U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17644U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aPrevious, 57U)) + 12131317914288566437U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 5672805657999385496U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 41U)) + 3581710244233124197U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 60U)) + 15251296040538489436U;
            aOrbiterB = (aWandererA + RotL64(aCross, 19U)) + 11295008604679904153U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 23U)) + 2230897493419504490U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 21U)) + 7109600123297458999U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 27U)) + 13119156643107683803U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 14755160867807355250U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 16829363373287496832U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 44U)) + 16981122946707720883U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8806000776958603317U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 16810923047720876014U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17872735050219539145U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8129657889554436328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8653100378491974463U;
            aOrbiterB = RotL64((aOrbiterB * 11395283153912468661U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17048985838727432415U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10892675550889823573U;
            aOrbiterC = RotL64((aOrbiterC * 976298937314081913U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15960158965421254346U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12290011578634850001U;
            aOrbiterK = RotL64((aOrbiterK * 9280475585104357745U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 16265047040311479093U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10312956912303656248U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3012584393253845131U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16706890352221352779U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10630955894218491929U;
            aOrbiterF = RotL64((aOrbiterF * 12675937483456206355U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4009352551041162434U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3043810773683888556U;
            aOrbiterA = RotL64((aOrbiterA * 4328135390387997315U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1398071019814944785U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16689766557488135301U;
            aOrbiterI = RotL64((aOrbiterI * 8403881916549404871U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15934647144489136524U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13521276033614992223U;
            aOrbiterD = RotL64((aOrbiterD * 18003640895553609933U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4281211055727414100U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11848150507497406421U;
            aOrbiterJ = RotL64((aOrbiterJ * 1107789990317433481U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12022829841608199449U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12131317914288566437U;
            aOrbiterH = RotL64((aOrbiterH * 13275753083882829973U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 28U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 18U));
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 41U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 43U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 6U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 39U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterB, 23U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterH, 53U));
            aWandererD = aWandererD + ((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 51U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32711U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 24903U)) & S_BLOCK1], 18U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 32456U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 25479U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31681U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27260U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 29876U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 47U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererJ + RotL64(aIngress, 43U)) + 12583180859826261500U;
            aOrbiterH = (aWandererB + RotL64(aCross, 4U)) + 9067093488553721468U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 13U)) + 12173106198862881754U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 27U)) + 11333491014394592654U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 3511883526940919554U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 35U)) + 7416810692106273044U;
            aOrbiterE = (aWandererE + RotL64(aCross, 21U)) + 8341174972619784110U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 39U)) + 2220852854836962979U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 8090781422229383825U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 52U)) + 2338801236599102223U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 12484514711848308104U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 13684861340589131816U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12796636819991873058U;
            aOrbiterK = RotL64((aOrbiterK * 5533508014234835669U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 7634198650894837690U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10240326122201201762U;
            aOrbiterG = RotL64((aOrbiterG * 8758703497719125901U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4162814763739453934U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2766504649149048469U;
            aOrbiterE = RotL64((aOrbiterE * 16731843453895178671U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11051393030148769655U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17687055068651386665U;
            aOrbiterF = RotL64((aOrbiterF * 1042927176246229537U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3353615315436983420U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5971640796220306310U;
            aOrbiterB = RotL64((aOrbiterB * 15804313508835034807U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12299773092762384765U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7435804907797063411U;
            aOrbiterA = RotL64((aOrbiterA * 9848139805288165965U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8735783937125735699U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11903126115475835615U;
            aOrbiterH = RotL64((aOrbiterH * 16942088822124940265U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4427166023462475475U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6011733469446008137U;
            aOrbiterJ = RotL64((aOrbiterJ * 17298067225913923517U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 18341473946127677319U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5423774915753911947U;
            aOrbiterI = RotL64((aOrbiterI * 14985099502923458523U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2384393657884193014U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2650593524388493958U;
            aOrbiterC = RotL64((aOrbiterC * 892985816665547945U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15991261431384033176U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12583180859826261500U;
            aOrbiterD = RotL64((aOrbiterD * 14394838775646875599U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 24U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 56U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterK, 29U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 46U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + aOrbiterD) + RotL64(aOrbiterH, 23U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 11U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + aPhaseFWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterC, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterB, 57U));
            aWandererC = aWandererC + ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 42U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterA, 39U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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

void TwistExpander_Tennis_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4525U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 7546U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 824U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5424U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7572U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4620U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 35U)) + (RotL64(aIngress, 4U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 12426357877879529292U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 12604900366173639176U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 4U)) + 13511119007338929401U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 9878720081166788060U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 29U)) + 15463195409806395076U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6407922778852833423U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7690427254160734016U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11841396512731990295U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18030974031722143619U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17983938038322737041U;
            aOrbiterB = RotL64((aOrbiterB * 12479365337221685413U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 16605512170117753884U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 681802273302348322U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14608920184802647123U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15550312921312083819U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17824154101711884508U;
            aOrbiterD = RotL64((aOrbiterD * 7358612830654795357U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1939207786756735430U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3132864634777826569U;
            aOrbiterC = RotL64((aOrbiterC * 13606281919426730325U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterD, 46U)) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 11U));
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC) + aPhaseGWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14125U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((aIndex + 13324U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9454U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12459U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13064U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9593U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 10U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 1457104756581596530U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 35U)) + 6127240317844622874U) + aPhaseGOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 13U)) + 16492290056044189421U) + aPhaseGOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 13U)) + 10963676850938416468U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 4872917367399752405U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15218882377875616148U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5934166612122118251U;
            aOrbiterF = RotL64((aOrbiterF * 10365045124180379919U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14215280930872003003U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11428034799044600979U;
            aOrbiterK = RotL64((aOrbiterK * 12162528943733976177U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5453003654321728726U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14273775120265649389U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5139018128323795309U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 328723770018440271U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13032190719588211088U;
            aOrbiterG = RotL64((aOrbiterG * 13363368478932798315U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2386881543033598494U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 1649501123340887116U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11148976582360499033U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterI, 11U));
            aWandererB = aWandererB + (((RotL64(aScatter, 38U) + aOrbiterK) + RotL64(aOrbiterD, 36U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererG, 44U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19342U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 19437U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23716U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24342U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22529U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 23984U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 34U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 13583136155674166402U) + aPhaseGOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 12830472187484919497U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 18081197909484522509U;
            aOrbiterH = (aWandererF + RotL64(aCross, 20U)) + 8680634051297891550U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 3U)) + 13939998767458656823U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1795730579103692594U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17369751719734069999U;
            aOrbiterE = RotL64((aOrbiterE * 2633464694273697123U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 224769585901248068U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 4133547085925268180U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2611561365156544735U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7022512056309567391U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10319484359046945495U;
            aOrbiterF = RotL64((aOrbiterF * 3400140531307001933U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10483878349412282069U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6481381149199985736U;
            aOrbiterI = RotL64((aOrbiterI * 9701719367082506253U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13721077228796934509U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9704818014314175007U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 760445624027740287U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 48U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterI, 57U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 42U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + aPhaseGWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29227U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 25531U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28971U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26468U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32028U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25858U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 50U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererH + RotL64(aScatter, 30U)) + 10726035965553989335U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 967354339530195662U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 10834593005478605624U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 1012888282838656933U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 5U)) + 15283530351725183253U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11724495956731703750U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 4288330117317505776U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2738997410474076757U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10894778070022873473U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15563886747621617467U;
            aOrbiterJ = RotL64((aOrbiterJ * 17884709931569040065U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11182488628562891937U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10420140066310588580U;
            aOrbiterH = RotL64((aOrbiterH * 13898299782819948719U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11775138062167543111U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16545391898578161683U;
            aOrbiterC = RotL64((aOrbiterC * 14588306527161321535U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1550144656312299266U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14903504853138279883U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8003033561266164387U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 6U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 23U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 52U) + aOrbiterG) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterC, 46U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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

void TwistExpander_Tennis_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 56U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 4277U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 8007U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7537U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4257U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 282U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 52U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 16424657151168221875U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 60U)) + 17150123681886380361U) + aPhaseHOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 16041993588694572757U) + aPhaseHOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 37U)) + 9871185846434828537U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 11227236398354430757U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5399325217402192631U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9248828789282890454U;
            aOrbiterF = RotL64((aOrbiterF * 6733832755349139621U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9041370494203701062U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14944424084524970764U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10283363059424655079U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5481938174456671041U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14783648629543752715U;
            aOrbiterH = RotL64((aOrbiterH * 7260164783191886395U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12355573914530445723U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9863991559011968318U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8495251211794343179U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16149688605937250965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 106041828692026825U;
            aOrbiterD = RotL64((aOrbiterD * 12199934305374582599U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + RotL64(aOrbiterF, 3U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 28U)) + aOrbiterH) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 58U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 37U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 10U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16134U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 12181U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10027U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11186U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9551U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 9458U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererJ + RotL64(aIngress, 13U)) + 11480359716598965890U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 28U)) + 15431182525482873419U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 11360504974812776707U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 9292576416573382769U) + aPhaseHOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 11U)) + 1549257414531028975U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5347769463033129317U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17019199177478377234U;
            aOrbiterB = RotL64((aOrbiterB * 4336112198640602307U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16558106007323125094U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3976182233825939422U;
            aOrbiterA = RotL64((aOrbiterA * 4392162052317572289U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2889047161195954395U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2241831345026962605U;
            aOrbiterH = RotL64((aOrbiterH * 5757458560979927857U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12850802412140579294U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13541744735436450160U;
            aOrbiterK = RotL64((aOrbiterK * 906089290000537439U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2085863085516538212U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2969034221711544086U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7768528124408400403U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 35U) + RotL64(aOrbiterH, 11U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 38U)) + aOrbiterB) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 27U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 44U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 42U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21065U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 18435U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 22332U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18596U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17705U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24459U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 4259993311776766595U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 2857813330021126753U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 19U)) + 1345396841329442896U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 34U)) + 320992148982301024U) + aPhaseHOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 5619109532065293074U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10380157329426706345U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12449831150625409695U;
            aOrbiterB = RotL64((aOrbiterB * 3354095240459774437U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7847096607042268396U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11707184096803214678U;
            aOrbiterF = RotL64((aOrbiterF * 1959476948106553973U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9893643746186827088U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 333687403830908774U;
            aOrbiterI = RotL64((aOrbiterI * 17911256836121454271U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13837360705077441580U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4367119682175710689U;
            aOrbiterH = RotL64((aOrbiterH * 10295744669174603401U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1193493435041306784U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15062951612027370606U;
            aOrbiterK = RotL64((aOrbiterK * 2509383510565136549U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 54U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterB, 18U));
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 54U) + aOrbiterI) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29015U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 28648U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26830U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31798U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30259U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30120U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 27U)) + (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aCross, 47U)) + 12809562813316740345U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 17084212535326321199U) + aPhaseHOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 16074921689983846769U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 58U)) + RotL64(aCarry, 3U)) + 14027986153007120145U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 37U)) + 7633455951809250227U) + aPhaseHOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 340989348513370174U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5307820377645020116U;
            aOrbiterB = RotL64((aOrbiterB * 8402492604131262157U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5605285015771527274U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5293500434746182790U;
            aOrbiterH = RotL64((aOrbiterH * 17674669610895537063U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7263156475892261811U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10672879570907433005U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2506338667179450741U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16659226780900986107U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9774892622769850665U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7487477727543183211U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10728057184108279042U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5032485856947407217U;
            aOrbiterD = RotL64((aOrbiterD * 16651577903809154285U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 54U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 20U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
