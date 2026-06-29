#include "TwistExpander_Rugby_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Rugby_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x83A64CE7D2BC96B7ULL + 0x847FD85D11CE19EFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x98E1A5B1B8F9E3C1ULL + 0xE53058F15087E375ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFFF27FD6DC50AB3BULL + 0x9D131F9D03A627E8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x99AE379BDC1D4769ULL + 0x910D9CC18ED828EEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF1C9B411B5D5F483ULL + 0xB1EDA04543C53D40ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x91347468BABBD9E1ULL + 0xC23EEE437A1D8F7CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9ED3E104912A1863ULL + 0xA9B35550869C4FA8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9115C6E0E8E13815ULL + 0xEBC27CB01C11D668ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA8C8260EBD60531DULL + 0x9ECC14995A45E4A5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x91E86CC765F85D2BULL + 0x9787CCB9005A23EBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x935830F021FFA18DULL + 0xBF75E47D13082B09ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8E3FEB6A19C852BBULL + 0xB9B9FCC2C7841D7FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCFB0A75666D81931ULL + 0xCB63E449B62574B4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC8F48B24119E57C5ULL + 0x8AE512276EF9F2B2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD00FD1C188C11AC9ULL + 0xB7158628643F9055ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE72BA051B8D999E9ULL + 0x97133AADCDE3D342ULL);
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
            aIngress = RotL64(mSource[((aIndex + 2395U)) & S_BLOCK1], 56U) ^ RotL64(pSnow[((aIndex + 1729U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 3733U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 4253U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 966899917801652720U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 43U)) + 10996327672320748649U) + aNonceWordI;
            aOrbiterI = (aWandererC + RotL64(aCross, 34U)) + 4188171566846621107U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 19U)) + 5886209243097387959U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 11U)) + 14940428957136728111U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 179187285531914832U) + aNonceWordL;
            aOrbiterB = (aWandererG + RotL64(aIngress, 37U)) + 6685351948936817752U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 1894506461704029700U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 30U)) + 4182760368636977082U) + aNonceWordA;
            aOrbiterF = (aWandererF + RotL64(aScatter, 47U)) + 12523318028514940790U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 51U)) + 5059306166973366892U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5890872367917643851U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17747338389865221534U;
            aOrbiterI = RotL64((aOrbiterI * 5306740664798049267U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13906227834259884100U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7152105382899756368U;
            aOrbiterJ = RotL64((aOrbiterJ * 6772157117358310485U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17868101884759619240U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11758843266314148347U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 5919135169337501485U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13950566197090324859U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 17278105609930477854U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11431842718945107359U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9556785965646738355U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 841298436857932987U;
            aOrbiterE = RotL64((aOrbiterE * 15077843186688841797U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1951515285492133830U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15775839819330588437U;
            aOrbiterK = RotL64((aOrbiterK * 7902654031401620995U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5585458468816495436U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17258586689032223623U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1652050227399194271U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5254132659445988836U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15440741734777060925U;
            aOrbiterF = RotL64((aOrbiterF * 17445581079035134067U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16770361602586485631U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14902616717976301965U;
            aOrbiterG = RotL64((aOrbiterG * 7757713071544143453U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9521517757370835715U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 18241677917767801049U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 16977396965907931057U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14307634663160859644U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 966899917801652720U;
            aOrbiterD = RotL64((aOrbiterD * 17012361848398765251U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 46U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 39U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 19U)) + aOrbiterB) + aNonceWordJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + aNonceWordP);
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 58U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 51U)) + aOrbiterC) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterD, 56U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterD, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 14U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 7329U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((aIndex + 8520U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6515U)) & S_BLOCK1], 20U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6344U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (aWandererC + RotL64(aCross, 13U)) + 11274974230580265396U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 16658438747342741547U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 46U)) + RotL64(aCarry, 11U)) + 16612986966106053844U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 9329502236843231290U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 11U)) + 14088261356708344656U) + aNonceWordC;
            aOrbiterA = (aWandererG + RotL64(aIngress, 37U)) + 13692608802007789581U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 3U)) + 6824473946645682398U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 58U)) + 2072915876348570040U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 35U)) + 7420507753044460759U) + aNonceWordI;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 43U)) + 4677557318688502593U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 27U)) + 15081678577055628459U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7026792817486507482U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14871665922943969918U;
            aOrbiterH = RotL64((aOrbiterH * 694073180313083145U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6807734532159292872U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17882797335141303280U;
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9233542707022629190U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1205501586581350876U;
            aOrbiterE = RotL64((aOrbiterE * 2596053290311090589U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10878718669747466677U) + aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8066049063548639241U;
            aOrbiterG = RotL64((aOrbiterG * 3031382633089381605U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 861295180226875235U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9134969787937288583U;
            aOrbiterA = RotL64((aOrbiterA * 7565008208670843555U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6726642007159809594U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8061661744643240470U;
            aOrbiterI = RotL64((aOrbiterI * 6703498926835391813U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13541412083111962884U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8617442758729315637U;
            aOrbiterB = RotL64((aOrbiterB * 15471862889276160953U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16884403561131293362U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9490680911678221233U;
            aOrbiterF = RotL64((aOrbiterF * 15988763830018001033U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10486145044311386738U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10200001044821063684U;
            aOrbiterD = RotL64((aOrbiterD * 16149790736141571017U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6997073594007878034U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 13585783612009989767U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 11425303157774550449U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3847846040256340653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11274974230580265396U;
            aOrbiterJ = RotL64((aOrbiterJ * 13970270689108369205U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 38U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterI, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterB, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterC, 50U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + aNonceWordO);
            aWandererA = aWandererA + ((((RotL64(aCross, 48U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 41U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 46U)) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 39U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererD = aWandererD + (((RotL64(aIngress, 46U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 14825U)) & S_BLOCK1], 20U) ^ RotL64(mSource[((aIndex + 15157U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12499U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((aIndex + 13509U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = ((((aWandererD + RotL64(aCross, 50U)) + RotL64(aCarry, 35U)) + 9855743441035905047U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 13U)) + 8426286937143990276U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 29U)) + 7146752367170267002U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 37U)) + 12947210066678101726U) + aNonceWordC;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 41U)) + 15902163559925328965U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 10U)) + 8506649889346449469U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererF + RotL64(aCross, 3U)) + 8226286036430263052U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 5U)) + 2703047093452420216U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 6769351326360139560U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 9857025533281333281U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 35U)) + 238297452132277585U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7203572312072908931U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12497027346166575632U;
            aOrbiterA = RotL64((aOrbiterA * 1703586436725662307U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 473851890609048879U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1664484956453886047U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 8566500756326590209U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4635095143004754116U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17695676150967345793U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5780416541584439301U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15628965269863402796U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 9190117464399730235U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5586437438425999715U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17835918238346011086U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4398005402429282682U;
            aOrbiterB = RotL64((aOrbiterB * 14828737209913317463U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10902589938246551273U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 15124274429081385923U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 13524180348258805367U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8747233520702236018U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5445611443463112371U;
            aOrbiterH = RotL64((aOrbiterH * 10294109295823410447U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16296005217836151910U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6468336224317602364U;
            aOrbiterJ = RotL64((aOrbiterJ * 7369779919748367133U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3827976387089403774U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7773383658122100111U;
            aOrbiterI = RotL64((aOrbiterI * 9784711300597525161U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 18273794621528918389U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8401424792700263455U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13003420427441089595U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11402828934846813949U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9855743441035905047U;
            aOrbiterF = RotL64((aOrbiterF * 7339549576423555273U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 47U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aScatter, 12U) + RotL64(aOrbiterH, 18U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 41U)) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterA, 39U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 11U)) + aOrbiterC) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterF, 43U));
            aWandererC = aWandererC + ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterE, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 24U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17920U)) & S_BLOCK1], 46U) ^ RotL64(pSnow[((aIndex + 18236U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19179U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 20832U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 18203U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 35U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 11U)) + 1364174714924216027U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 51U)) + 13561796874229506613U) + aNonceWordM;
            aOrbiterA = (aWandererC + RotL64(aIngress, 20U)) + 11845572344206238305U;
            aOrbiterD = (aWandererE + RotL64(aCross, 43U)) + 15762708240326773763U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 1157119665207900473U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aCross, 41U)) + 6823546624372055260U) + aNonceWordN;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 14465564210523945121U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 35U)) + 10667464548080807531U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 13445737493224316575U) + aNonceWordH;
            aOrbiterH = (aWandererK + RotL64(aIngress, 3U)) + 3009837893785957665U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 28U)) + 2886920524111083752U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10886177449328249656U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15067759884678100433U;
            aOrbiterA = RotL64((aOrbiterA * 5724566815989860041U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18307930462682331536U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8791864377579255801U;
            aOrbiterK = RotL64((aOrbiterK * 9265158882471421767U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 805797468642992351U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5743305867058244964U;
            aOrbiterD = RotL64((aOrbiterD * 16263000753351131717U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17102025528234481273U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1841579177327486899U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3841603385577825265U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2189493507896508972U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 18209567010094914374U;
            aOrbiterF = RotL64((aOrbiterF * 3737080408976852351U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6697069234216868330U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 927471474577415372U;
            aOrbiterH = RotL64((aOrbiterH * 10680760991009199309U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13155854301197725408U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 1014625081915435892U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11592754232949990435U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12697209921410914931U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11555096613655648647U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 4598821388864997089U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9335308231651271690U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3160859883353473444U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4753600703924906409U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15681189182414315768U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3147692210581710663U;
            aOrbiterG = RotL64((aOrbiterG * 6271949093080510861U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5373388632562432117U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1364174714924216027U;
            aOrbiterJ = RotL64((aOrbiterJ * 4694926665965807945U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 44U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterC, 41U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 54U)) + aOrbiterG) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterD, 19U)) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 21U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 24U) + aOrbiterA) + RotL64(aOrbiterE, 43U));
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterJ, 11U)) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            aWandererF = aWandererF + (((RotL64(aCross, 48U) + aOrbiterG) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22931U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 23224U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(pSnow[((aIndex + 22107U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((aIndex + 24808U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26986U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25982U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererC + RotL64(aScatter, 28U)) + 18319689184146942855U) + aNonceWordD;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 21U)) + 8041304130090501019U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 11347064191990897738U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 35U)) + 15242243470024447468U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 10619749107163611105U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 14795614276221947128U;
            aOrbiterE = (aWandererG + RotL64(aCross, 6U)) + 1578095288886372393U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 43U)) + 13593906305770501684U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 57U)) + 8919815528334599172U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 11U)) + 17425548324720065145U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 3U)) + 11125018338392347335U) + aNonceWordM;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3779189180734244399U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 10958224663276134041U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 6206963519509783781U), 39U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 4317305352561612995U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4891139433808505355U;
            aOrbiterD = RotL64((aOrbiterD * 11507024985663120317U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5166074784835930965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10080890270621589202U;
            aOrbiterB = RotL64((aOrbiterB * 13170894418184288695U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4501071771615514619U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6486573807774431753U;
            aOrbiterG = RotL64((aOrbiterG * 324029625116648669U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15714881857668975753U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3506619392820235900U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5707033870161224499U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5295711072762443783U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11192836530396570648U;
            aOrbiterH = RotL64((aOrbiterH * 4361810118382207039U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7993389678399774574U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12551394763541226695U;
            aOrbiterJ = RotL64((aOrbiterJ * 11903486656172026403U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11553674370322129668U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4459881583199320245U;
            aOrbiterC = RotL64((aOrbiterC * 2805857426321555685U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3053507713574219459U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15458441755058850309U;
            aOrbiterA = RotL64((aOrbiterA * 7296609957819165877U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17429750026356459756U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17114614857181230304U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 10541235280918902739U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8958993884028672039U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 18319689184146942855U;
            aOrbiterF = RotL64((aOrbiterF * 5430881344386342703U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 28U) + aOrbiterB) + RotL64(aOrbiterD, 41U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterK, 43U));
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterG, 18U));
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterF, 39U)) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterF, 28U)) + aOrbiterK) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 14U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28839U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 30999U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31897U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27741U)) & S_BLOCK1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31682U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 29400U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((aIndex + 27545U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 4U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (aWandererJ + RotL64(aIngress, 19U)) + 15188686795415908074U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 53U)) + 17310049041983079779U) + aNonceWordI;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 27U)) + 8246925977992441471U) + aNonceWordD;
            aOrbiterK = ((aWandererI + RotL64(aCross, 21U)) + 8644260919918112781U) + aNonceWordF;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 30U)) + RotL64(aCarry, 35U)) + 13401663736874819483U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 7940358935238314973U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 13278990328548007839U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 41U)) + 11346868298353840706U;
            aOrbiterA = (aWandererF + RotL64(aCross, 11U)) + 2374077904806833579U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 4U)) + 6978903378645019166U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 13U)) + 11951633297870965212U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17398460995357409673U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1215437945597836770U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9322970054123481621U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1878751468043972239U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5343002808239712390U;
            aOrbiterH = RotL64((aOrbiterH * 11878640995447558811U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9884918450053276861U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 15894599082080422550U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 8359936745539546131U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13917339232771145459U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 18101134009493720683U;
            aOrbiterB = RotL64((aOrbiterB * 15835859435306756387U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3830086372356903769U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15894394599564584010U;
            aOrbiterJ = RotL64((aOrbiterJ * 9513921913446609263U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5127590955274245812U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9410946933309720054U;
            aOrbiterD = RotL64((aOrbiterD * 14507476989423060561U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15544384157294987085U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 998801294460434123U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5946968142746472745U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16442095194965452163U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14294936349037516932U;
            aOrbiterA = RotL64((aOrbiterA * 14655345374740882581U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16680659892463349201U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10921918150041635666U;
            aOrbiterG = RotL64((aOrbiterG * 2908474941036821745U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15350264522133299871U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16413848767507968239U;
            aOrbiterK = RotL64((aOrbiterK * 10226942289998651355U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11963105565077056299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15188686795415908074U;
            aOrbiterF = RotL64((aOrbiterF * 13002484121826831091U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 42U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 20U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 42U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterC) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 24U) + aOrbiterA) + RotL64(aOrbiterH, 24U)) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 53U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterE, 21U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 11U)) + aNonceWordH) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Rugby_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF036AA62143BE09DULL + 0x8DDA8F770D849D8BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8DCC2B3514C30DE5ULL + 0xAEAFFF35D9BA9B19ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBB1021D1B8EBA7B1ULL + 0xF60ADBA438326D3EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE473E254D1A0D121ULL + 0x89763FBCB4ABCE0EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC76BD3F68BE94E63ULL + 0xDDD3C3D07744DA1BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD75EE58990AC7735ULL + 0xF9DE309601A91C07ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA270F8C2543BEBA9ULL + 0xC8E4F05E24F292B5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB5CB079BB63E7585ULL + 0xEE03B7C064EC52B5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE8EEDB2E00F59C01ULL + 0xCA5A97F9AA3126FCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD4635D63712B99F9ULL + 0xC9298C03D17FB806ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x871AA2B08AEDEB5FULL + 0xE78BE4204992A14CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCC66D39766161247ULL + 0xBCC26EE6B42315B3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8145CB516D8B3459ULL + 0xC8F08EEB2A959635ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB601BB6FD4416F7DULL + 0xDA8B949F216424D7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCE86FD645B80F523ULL + 0xEFAFBA8FF1934CA7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE8566B54024BC4FDULL + 0xD3C6444902350388ULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 4718U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 4974U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2272U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((aIndex + 5101U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 24U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 4U)) + 3238389262925516513U) + aNonceWordG;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 12381787182611386995U;
            aOrbiterG = (aWandererC + RotL64(aCross, 35U)) + 7883885539305181549U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 11U)) + 1185413044597727092U) + aNonceWordL;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 28U)) + RotL64(aCarry, 5U)) + 15219353497204773135U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 23U)) + 7533774715626734082U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 2599930450937763464U) + aNonceWordE;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 51U)) + 16074720663961214284U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 47U)) + 15483613196360051221U) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9396557867081376268U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9668459976852660245U;
            aOrbiterG = RotL64((aOrbiterG * 11748505665890567063U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9037269914643207212U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16936742640861088240U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1040172193161012227U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16481274825758546398U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 481851372837611166U;
            aOrbiterK = RotL64((aOrbiterK * 2225030139210599207U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13608921517203544108U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16930740723286214636U;
            aOrbiterD = RotL64((aOrbiterD * 2605108503821980865U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 902242902582149908U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1510861213079342977U;
            aOrbiterJ = RotL64((aOrbiterJ * 3309753895727400707U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7116243600304980310U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6631412278359709602U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11452627691392637463U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9246698682265275165U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8594373032014031450U;
            aOrbiterI = RotL64((aOrbiterI * 2550138341089957033U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15912837963877821048U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11404583513022627609U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 17715204726760125357U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17295214920690244319U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18315664494984189344U;
            aOrbiterE = RotL64((aOrbiterE * 17398893532076312945U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 38U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 54U) + RotL64(aOrbiterB, 13U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterG, 18U));
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterE, 37U)) + aOrbiterI) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 42U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 6434U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 6438U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 6673U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9124U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5782U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 57U)) + 13333509828310369865U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 7645352517103840797U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 36U)) + 5310766306660062655U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 5165635069832352932U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 41U)) + 15684141764734281849U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 19U)) + 3327963374225061738U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 52U)) + 8625811794878848871U) + aNonceWordA;
            aOrbiterK = (aWandererK + RotL64(aScatter, 27U)) + 7598657468430485291U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 2881171216276746485U) + aNonceWordM;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 10237691227222918101U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6419254255884834497U;
            aOrbiterA = RotL64((aOrbiterA * 3816625473642865305U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4238455444646479956U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14936613353493061492U;
            aOrbiterD = RotL64((aOrbiterD * 3544216916806292273U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15324699725208372627U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9506640480601832011U;
            aOrbiterJ = RotL64((aOrbiterJ * 12819564111348390227U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 3709149613660215641U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 1724290199312754307U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12597580418257897965U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13191172833570139194U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3686087945377837886U;
            aOrbiterK = RotL64((aOrbiterK * 10883609557429936283U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10418330386245397022U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5383531313632347245U;
            aOrbiterC = RotL64((aOrbiterC * 2987755379396160073U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7414716553072652212U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11301761123966206201U;
            aOrbiterG = RotL64((aOrbiterG * 1546727321088592187U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8570229732236388847U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8773754460060264773U;
            aOrbiterI = RotL64((aOrbiterI * 3251360788932563495U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13636929800504199371U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5486599841558573720U;
            aOrbiterF = RotL64((aOrbiterF * 2867914211589815153U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 50U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 34U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterI, 19U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 41U)) + aOrbiterA) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 11U)) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterC, 6U));
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterK, 23U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12332U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((aIndex + 12708U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14008U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13821U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 13144U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 18180797995100240808U) + aNonceWordJ;
            aOrbiterD = (aWandererD + RotL64(aIngress, 57U)) + 6585906608223552885U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 14U)) + 14088708930575939855U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 23U)) + 468974153311516044U) + aNonceWordN;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 53U)) + 12481951025619894110U) + aNonceWordB;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 41U)) + 17227987923860711763U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 4373962756657477139U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 46U)) + RotL64(aCarry, 29U)) + 2077576476565420951U) + aNonceWordK;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 19U)) + 17435011300234663764U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4118039398293246896U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13724716599855216683U;
            aOrbiterK = RotL64((aOrbiterK * 17556333902751079677U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12391461204689596339U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9900605191533799627U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13553565332531046301U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 972946858824366125U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17247681919694541215U;
            aOrbiterJ = RotL64((aOrbiterJ * 2974639094630445643U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15442851427306771601U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7303586227288294037U;
            aOrbiterG = RotL64((aOrbiterG * 15406402525021428799U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12650358753454105119U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1483710933373510492U;
            aOrbiterE = RotL64((aOrbiterE * 6531763256577221891U), 5U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 18065810162229740788U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11311677121338794007U;
            aOrbiterD = RotL64((aOrbiterD * 15116367961682119467U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2355285311890287611U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1287783821903407734U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 8054011680932255985U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9282654686791135654U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15488608017745542551U;
            aOrbiterA = RotL64((aOrbiterA * 7858866274035085123U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13296835576073421802U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7127700236018338741U;
            aOrbiterC = RotL64((aOrbiterC * 11246173563106014149U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 54U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterA, 37U)) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 30U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ) + aNonceWordO) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterA, 26U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 41U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 24U) + aOrbiterI) + RotL64(aOrbiterE, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21200U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 17783U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19084U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17534U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 21792U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 47U)) ^ (RotL64(aCarry, 22U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 19U)) + 2177539223979303669U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 28U)) + RotL64(aCarry, 37U)) + 3962004686551521471U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 8457602312617147662U) + aNonceWordE;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 41U)) + 18011802451816510632U) + aNonceWordF;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 23U)) + 9046101759168876832U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 11135620637431969597U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 53U)) + 15913029940697999701U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 58U)) + 16304193109948135982U) + aNonceWordG;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 47U)) + 13208892298820080981U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4182377898949419225U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13970137023071326151U;
            aOrbiterJ = RotL64((aOrbiterJ * 9075061559681739865U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 8402396284835248583U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8859190834060657829U;
            aOrbiterH = RotL64((aOrbiterH * 13552418608113716117U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9760005337757990392U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14108277760135744897U;
            aOrbiterI = RotL64((aOrbiterI * 4474681104256093885U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12226316121949012350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3456392186754113960U;
            aOrbiterF = RotL64((aOrbiterF * 8704729827929941215U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5004087958637038973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7176881295123125567U;
            aOrbiterA = RotL64((aOrbiterA * 15272157962928021009U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10889800478505074438U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 13728832441482547824U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 17588477761978646139U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17345665880706866772U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 301139993853297566U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 5812445396758354505U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2061389844760610160U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13631862266139238355U;
            aOrbiterE = RotL64((aOrbiterE * 143613352104722701U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10767186080827509622U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4893486019456886013U;
            aOrbiterG = RotL64((aOrbiterG * 5194746459545610901U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 36U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 50U) + RotL64(aOrbiterH, 47U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterI, 23U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 18U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 13U)) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 43U)) + aOrbiterE) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterD, 51U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 26798U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneD[((aIndex + 26531U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24492U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22520U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 12849591986267890852U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 8232614804696815750U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 12141567259210877281U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 56U)) + 2928641981037885644U) + aNonceWordI;
            aOrbiterF = ((aWandererD + RotL64(aCross, 5U)) + 980733350554783938U) + aNonceWordB;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 11U)) + 2683985177993350746U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererB + RotL64(aIngress, 51U)) + 14532148403815527355U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 19U)) + 7736296629433884203U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 46U)) + 10428437770166310549U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18327174144859461029U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6810436935194432002U;
            aOrbiterH = RotL64((aOrbiterH * 2715987179577753597U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12606153309690753435U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17123256945895150555U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 13469111258504672565U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9057777759026189541U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16478485918911194442U;
            aOrbiterB = RotL64((aOrbiterB * 11054247078884894131U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18064460487552100483U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11477276762421684083U;
            aOrbiterG = RotL64((aOrbiterG * 3886501230380184395U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 18318375441973295081U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13849305985380030986U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12962140243967824959U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10240409420338313641U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 18360586077779529086U;
            aOrbiterI = RotL64((aOrbiterI * 18196875422391501927U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16801797158622424257U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4950305991208513887U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4437082499761416951U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15790878572843321918U) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9808781805065559728U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 9394280083159162953U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11974996650410830731U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4955004489435232515U;
            aOrbiterD = RotL64((aOrbiterD * 13301966529515483085U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 14U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + aNonceWordA) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterK, 10U)) + aOrbiterI) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterK, 41U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aCross, 11U) + RotL64(aOrbiterG, 60U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterE, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 29767U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31403U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30492U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 30174U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 43U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 27U)) + 5906639480605353429U) + aNonceWordN;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 5293518570213287605U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 12U)) + 15383185501428521377U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 15364072512743978902U) + aNonceWordD;
            aOrbiterI = (aWandererK + RotL64(aIngress, 43U)) + 4525473357144014271U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 3U)) + 10400911938125603074U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aWandererA + RotL64(aCross, 35U)) + 16417506293824627550U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 39U)) + 2419329331753341815U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 56U)) + RotL64(aCarry, 23U)) + 14929222427923332069U) + aNonceWordJ;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16771573504983922586U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1863466450051787622U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 2585626547126027053U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12895350137096692415U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3700979086526298327U;
            aOrbiterH = RotL64((aOrbiterH * 10279730254867618193U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1977099106211282426U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6144698304096915742U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5039822990560519609U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3858895556659724975U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1283646340363435327U;
            aOrbiterB = RotL64((aOrbiterB * 11622421841377018069U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6240532051889108891U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 757364889381634634U;
            aOrbiterD = RotL64((aOrbiterD * 943852137901972945U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5272945693977418174U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6850528198786172283U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1966383079897679953U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14431587733859573714U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16124590257870999553U;
            aOrbiterE = RotL64((aOrbiterE * 7755796211433191143U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14912695018110241411U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11098623474413346520U;
            aOrbiterI = RotL64((aOrbiterI * 15167688959990872051U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3484847683376368686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2295388097292719800U;
            aOrbiterF = RotL64((aOrbiterF * 1240808318176106909U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 36U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 30U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterF) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 57U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 35U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterA, 26U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterA, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 58U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Rugby_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFB5CFAD2AC1A63C7ULL + 0xECF0A261D669D7B2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA4DA4378F681A1D5ULL + 0xC8D6E330348DEE0CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF3039D663EEF135DULL + 0xE1DD80EC2A763616ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBA1B49D4017C9DA9ULL + 0xA123FC03890B298FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB35F8D99EA2E03C5ULL + 0xBF21E4E4F094D3E4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8F47536E9A8A6519ULL + 0xE31AE0A5DD4D6190ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC538D71D90B93365ULL + 0xF95CB2C3A45058FEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCDE6A3FA29F57507ULL + 0xE8955F7C1C34DCFAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF3F30B49EB1B6C95ULL + 0xF4418C0023A5AB3FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC30DF190AEBFEA21ULL + 0xBACDC585D82ECDE8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x92036DC3D9557A03ULL + 0x908445DE8A8BB96DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8A7C6049F0757ACFULL + 0xEF8608A4DB90AF5AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD7A03A43D7B65B51ULL + 0xE68A6BB51FE7736DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x883D8DC30F954EC5ULL + 0xE08C7A2D785024D1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA5F390EF8722C387ULL + 0x90EE373E1FF4AC17ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC875DAB0E806F0A9ULL + 0x89D681F6BA18698FULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 195U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 2204U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2153U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2902U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5871U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7156U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 52U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = ((((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 8375305456876489425U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 29U)) + 16193562952772453047U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 13U)) + 18088652458594816223U) + aNonceWordI;
            aOrbiterE = ((((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 767344788620249944U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererC + RotL64(aScatter, 27U)) + 7705194930396368752U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3829736891311272834U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9881681671347640061U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14380245087931793021U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1721196560190164264U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3002652618388454213U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 15289749311593032657U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9811621464004005202U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5652598941069986530U;
            aOrbiterE = RotL64((aOrbiterE * 4797973356708091621U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 6250499348327316328U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16025054277615264530U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 16446892258704281903U), 11U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 13800298546867243172U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12256104592865905782U;
            aOrbiterI = RotL64((aOrbiterI * 16983140179497142713U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 3U)) + aOrbiterH) + aNonceWordM);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 27U)) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterH, 48U)) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + aNonceWordG) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13877U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((aIndex + 16230U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13813U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10497U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11073U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8870U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12204U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 28U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 11177787645248006236U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 50U)) + RotL64(aCarry, 51U)) + 3808340254579817169U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 11U)) + 828030667598518279U) + aNonceWordJ;
            aOrbiterD = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 39U)) + 16177835921238398371U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 21U)) + 5518747735458708741U) + aNonceWordH;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17346319082399995165U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6397156921893030937U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 11203064569634132929U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15559381654710713582U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 940404446491415088U;
            aOrbiterJ = RotL64((aOrbiterJ * 16401260971303026881U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8047166032048732645U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4688468645859470491U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 14383536431614496369U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3710878044770337260U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 116343189456629220U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5637725064169289339U), 53U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 883908030159391659U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 18058691521694880482U;
            aOrbiterH = RotL64((aOrbiterH * 3132200449123497619U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterH, 23U)) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterG, 60U)) + aNonceWordN);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 48U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 47U)) + aNonceWordG) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18305U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 20020U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 20598U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 17136U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24265U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24316U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17265U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCarry, 38U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 898812731947995389U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aCross, 43U)) + 8677347622525527167U) + aNonceWordP;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 21U)) + 770321564027567654U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 11020474858081526395U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 21U)) + 17289793580414993470U) + aNonceWordK;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 10111912559295118444U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8083622125544542011U;
            aOrbiterB = RotL64((aOrbiterB * 3610772128071340341U), 27U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 7149858558922988240U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5919683821379905699U;
            aOrbiterJ = RotL64((aOrbiterJ * 16705119888884231567U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 6860902846079238714U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15083517836867542075U;
            aOrbiterD = RotL64((aOrbiterD * 4686657139237578325U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14852868368708376381U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9860233289028878323U;
            aOrbiterE = RotL64((aOrbiterE * 13418143547952204667U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 772406119079116272U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 7971141501337627589U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 10168120622976358617U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 28U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 3U)) + aOrbiterE) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 24U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 46U) + RotL64(aOrbiterE, 53U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30470U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 32230U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 30398U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 28120U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31050U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27631U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24774U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 19U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = ((((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 8101351470141807662U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aWandererG + RotL64(aIngress, 51U)) + 6965474099521076705U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 60U)) + RotL64(aCarry, 41U)) + 6803828268885684784U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 29U)) + 13454235922950972488U) + aNonceWordB;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 11678091885751244777U) + aNonceWordO;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5307134544628507141U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4873703518950429353U;
            aOrbiterD = RotL64((aOrbiterD * 2680442582958424915U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8542156221858586039U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 3993726182905296513U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 11331376012938127609U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12113047622035464386U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1944244448665721151U;
            aOrbiterA = RotL64((aOrbiterA * 7010050836758762003U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12914188029425467576U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 2486762763475327024U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 12319769994433811617U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14580191602982245481U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12093414832400135066U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12720286833215690663U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterA, 39U)) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 38U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 24U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Rugby_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDC8263D04B15E83DULL + 0xE656631949D78901ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEC235776FE1A0649ULL + 0xCA89C8A3A886D00EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEE8243C1C19F7F67ULL + 0xD2FB8BFC66E98DA5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE80E246619DDECD9ULL + 0x8688435846F71C1FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFF1179150273CA3DULL + 0xC7E6CEB1E44360DDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x83DB89650EC0CC8BULL + 0xC4B2023C9EE7E8A8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF757E1F40AF2BAC5ULL + 0xD3B680AE3180805EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDD138A1C7E34EACDULL + 0xD2F2B8406E0E951CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8DE3ED2641DB72C7ULL + 0x8A6097FD9146E74FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE42A32ED895E704DULL + 0xD8153F79DA11EA91ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD573764D78B7E6E9ULL + 0xFF48A9C4722AF07DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB766863863858B2BULL + 0xEBDAEBA028877FB2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA73C1DFFAA0ADA23ULL + 0x9FB88FE6F8E75ED5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB427165706346F63ULL + 0xAE271436F421D23FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB5774EE60A87D707ULL + 0x9530B25B6AA5A9BEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB161C0908254C11FULL + 0xEDB57A09565AB53FULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5388U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 6974U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5275U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1477U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5434U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((aWandererG + RotL64(aCross, 12U)) + RotL64(aCarry, 51U)) + 6318740973868639425U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 57U)) + 5487840061430920881U) + aNonceWordP;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 3U)) + 10258706763248072672U) + aNonceWordH;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 29U)) + 18356875269730338208U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 12883160282903147010U;
            aOrbiterC = (aWandererF + RotL64(aCross, 47U)) + 1010140474942697730U;
            aOrbiterG = ((((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 17733939421700898293U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13693055887924981201U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14574732452793385269U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9373765929885750185U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10832873941223609012U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8212600587135328040U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 5334613996794796145U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5312744319781971178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6173741211706546923U;
            aOrbiterD = RotL64((aOrbiterD * 12854414066390848249U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3693249147883790810U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 18365859989736602556U;
            aOrbiterI = RotL64((aOrbiterI * 3348463719324104997U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10645056678337549771U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1175668356822251045U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 6579675292775345579U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13556844570541823717U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4790355739411849736U;
            aOrbiterB = RotL64((aOrbiterB * 4083544011788850307U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 14905575502272644116U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17047244574558476634U;
            aOrbiterC = RotL64((aOrbiterC * 2356386971503880047U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + aNonceWordF);
            aWandererD = aWandererD + ((((RotL64(aCross, 10U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 3U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 43U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 30U)) + aOrbiterA) + aNonceWordA);
            aWandererK = aWandererK + (((((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 57U)) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10529U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 12761U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 12187U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((aIndex + 9936U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8871U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12420U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9103U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 44U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (((aWandererH + RotL64(aIngress, 4U)) + RotL64(aCarry, 53U)) + 16160838483846078448U) + aNonceWordP;
            aOrbiterE = (aWandererF + RotL64(aCross, 35U)) + 15404960896190227946U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 51U)) + 16904160594024977199U) + aNonceWordG;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 17790460246821031802U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 57U)) + 16395168254086971959U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 7484373204039901786U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 19U)) + 18026814691322913510U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15244817793136966450U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5795491730356335666U;
            aOrbiterD = RotL64((aOrbiterD * 13253529465289332171U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3163873518027801504U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2690791759507349172U;
            aOrbiterA = RotL64((aOrbiterA * 16677948635136515083U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 17898067251167087906U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 8028010015006604239U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 5601629670521300241U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 7304739457289910555U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6476837815096530043U;
            aOrbiterC = RotL64((aOrbiterC * 16380545138701113267U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14242499233467960602U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17305645693017634630U;
            aOrbiterE = RotL64((aOrbiterE * 14442976693206929569U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9772864059444171908U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7897200728282156408U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 816306719390807411U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4890999319172950996U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8165132649356094963U;
            aOrbiterG = RotL64((aOrbiterG * 17297706071263690189U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 26U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 51U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 13U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 43U)) + aOrbiterC) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23006U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 21442U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 17695U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18915U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19353U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23096U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20659U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 29U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = (((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 39U)) + 11521331427196538632U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 16653824187682957632U;
            aOrbiterC = (aWandererH + RotL64(aCross, 28U)) + 11654676587350088289U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 19U)) + 8010313317412193584U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 5U)) + 1108775560502907471U) + aNonceWordF;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 243952321439823521U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 43U)) + 2324945800401240403U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9257554497543369657U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16701314607244592540U;
            aOrbiterC = RotL64((aOrbiterC * 8790054741039817107U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3900445848034341782U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 7652316487347103658U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 11480123491361589799U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14980368605272070578U) + aNonceWordI;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 2001165460948764796U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 8110980921827107649U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1911044015666991050U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11366207111147818339U;
            aOrbiterA = RotL64((aOrbiterA * 17234439040652553865U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16469329744002456607U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8062793687044950815U;
            aOrbiterJ = RotL64((aOrbiterJ * 5856142259851144369U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15364721421972807872U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8979915611483540231U;
            aOrbiterD = RotL64((aOrbiterD * 10899377466171153383U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7654234623563110457U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1526832460342135008U;
            aOrbiterI = RotL64((aOrbiterI * 12766083052650723051U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterF, 29U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA) + aNonceWordG) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 30U) + aOrbiterD) + RotL64(aOrbiterB, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterB, 39U));
            aWandererA = aWandererA + ((((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 11U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29166U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 29934U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 29979U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28769U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31132U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28466U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29816U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 52U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 10915618884692072446U;
            aOrbiterD = (aWandererG + RotL64(aCross, 27U)) + 12634922308499254909U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 6533934734564499389U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 60U)) + 6744203303756105181U) + aNonceWordL;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 43U)) + 13086782386652045658U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aWandererK + RotL64(aIngress, 37U)) + 5693840533331397822U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 1803663542535024611U) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3597219300593287708U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1429753448204448904U;
            aOrbiterH = RotL64((aOrbiterH * 10927459251773273143U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17229017825587322715U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1137574712801062932U;
            aOrbiterC = RotL64((aOrbiterC * 3645832160939819415U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2401991077004083378U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1332473247826139292U;
            aOrbiterA = RotL64((aOrbiterA * 15029831858261506447U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11730946340796899885U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15319163439700390962U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 1349242001887975499U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4744141870145159917U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6067132201862688684U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 6046100687757836027U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14991509179286371800U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4342608825699398682U;
            aOrbiterI = RotL64((aOrbiterI * 10240526103933275875U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3727521409410742075U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3302027219498304367U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12153634588200479559U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 57U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + aNonceWordD);
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 37U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterA, 51U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 28U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterC, 21U)) + aNonceWordG) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Rugby_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBE8A2A3BFF062211ULL + 0xAF836BC0B250C1ADULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBB08208458C01EEDULL + 0x8E3AF8E7324CFD37ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAB4116060B9B2469ULL + 0x86CEB4600945191CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEE431A0768EAAD6FULL + 0xE3A27B3CB3614492ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCB1348DBF5FBAB2BULL + 0xE556677AE12D9DF8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x97164CAC8B3202B1ULL + 0x815E3752D2DFF9DDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAE51671AA230BD67ULL + 0x97BC325AE20A26B8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD3B932CA2B177A47ULL + 0xCCA504CE01B99F7FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8BF13B8CFD157051ULL + 0xE1084CA00552214DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE061DB97980AF9CBULL + 0xA6EFAC27B584C616ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA62FF76E618B23BDULL + 0x9A1CCD54C3A3B91BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDCF089477FC35D2FULL + 0xC4908D4E6F3C9897ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD7CC648AA21EF6C1ULL + 0xBD8D81603366A889ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC28533FF40BDF507ULL + 0x8A0308658B0A51EEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF047243C424D3C13ULL + 0xAD88D9A7583302F9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA4A4E489B6F234F7ULL + 0xE7C45BE7D5AA63D6ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4285U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 262U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 3341U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4375U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 10U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (aWandererK + RotL64(aPrevious, 23U)) + 17454559218352016650U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 8005709669325164803U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 43U)) + 13393741948412816357U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 51U)) + 3665865624348875553U) + aNonceWordP;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 5U)) + 8334142570031883436U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 17226066128706139657U) + aNonceWordE;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 14U)) + RotL64(aCarry, 13U)) + 3319093033121522613U) + aNonceWordC;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6657535603401588798U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5469746182326331147U;
            aOrbiterG = RotL64((aOrbiterG * 11315450342347794329U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17846791786050221418U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15939541003714896288U;
            aOrbiterI = RotL64((aOrbiterI * 1400351482213119809U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12076763190461077406U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3594038213596405284U;
            aOrbiterE = RotL64((aOrbiterE * 10244002692575821495U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8301291631324464622U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 8460406137668390582U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 9117147929757711595U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7612394867020871200U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8525076134853103975U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5790440201072204659U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11929899088215090379U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7119509166360685726U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 1662341427992528823U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5081078459225240607U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17149991983909906705U;
            aOrbiterC = RotL64((aOrbiterC * 950223374568067343U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 30U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 35U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + aNonceWordF);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterC, 60U)) + aNonceWordO);
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 19U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 42U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 8622U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 5849U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 6515U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7694U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9211U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 7464U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 24U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 39U)) + 16200278595895089008U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 1029614154810465897U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 5U)) + 7129562468705441295U) + aNonceWordD;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 14388903902433951274U) + aNonceWordO;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 21U)) + 1013568949315967455U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 27U)) + 3128823373497815651U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 53U)) + 14525694606889470589U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14443983602196782887U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12244220415328641190U;
            aOrbiterI = RotL64((aOrbiterI * 15052949098014803181U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10477159225338766614U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2842870123078131566U;
            aOrbiterH = RotL64((aOrbiterH * 11522265477555954071U), 53U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 8621138818955849917U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5038396344400303181U;
            aOrbiterJ = RotL64((aOrbiterJ * 14636756322207385447U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2768613802894372496U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 2027754864051410015U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 2461322540050569287U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2848088309172056399U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15017458513904884651U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9926904679902843055U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9079797279596336139U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 15424866642305110811U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 12912331089970158845U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13751764050290602740U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7694557131324740282U;
            aOrbiterC = RotL64((aOrbiterC * 14980807690491467023U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 58U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterD, 29U)) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA);
            aWandererK = aWandererK + (((((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordK) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 39U)) + aOrbiterI) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 27U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererK, 36U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 14126U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 10933U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16268U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15878U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14527U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 58U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (((aWandererG + RotL64(aScatter, 60U)) + 13278949403988203974U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 47U)) + 9213599924054673756U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 1255746482932381798U) + aNonceWordH;
            aOrbiterE = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 11575321997144516122U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 5U)) + 15881587525529432437U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 35U)) + 9846195809864862707U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 12319815691858217670U) + aNonceWordP;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16322617427294439587U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16332130810525887437U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 7588076439690559343U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4920951156015336794U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16767126455124552329U;
            aOrbiterI = RotL64((aOrbiterI * 4440352337076842603U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 12553595911087945223U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1437522202135436142U;
            aOrbiterC = RotL64((aOrbiterC * 2001992794165550905U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12313100454852227143U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2761983020631055729U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3874839760378039509U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17635303588421554367U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 788212489507463763U;
            aOrbiterE = RotL64((aOrbiterE * 17896475584538528059U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5192552894670654434U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6784748488807738811U;
            aOrbiterF = RotL64((aOrbiterF * 8077237651953896479U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16113417046719114943U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1096874945215225916U;
            aOrbiterB = RotL64((aOrbiterB * 17308604412622879833U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 43U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 37U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterD, 58U)) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterA, 5U)) + aOrbiterE) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 5U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17946U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((aIndex + 20578U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21591U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16842U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21273U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 40U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 47U)) + 12849591986267890852U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 35U)) + 8232614804696815750U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 12141567259210877281U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 2928641981037885644U) + aNonceWordM;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 28U)) + RotL64(aCarry, 41U)) + 980733350554783938U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 57U)) + 2683985177993350746U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 19U)) + 14532148403815527355U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7736296629433884203U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10428437770166310549U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 326634742742373401U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18327174144859461029U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6810436935194432002U;
            aOrbiterB = RotL64((aOrbiterB * 2715987179577753597U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12606153309690753435U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17123256945895150555U;
            aOrbiterA = RotL64((aOrbiterA * 13469111258504672565U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9057777759026189541U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 16478485918911194442U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 11054247078884894131U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 18064460487552100483U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11477276762421684083U;
            aOrbiterG = RotL64((aOrbiterG * 3886501230380184395U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18318375441973295081U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 13849305985380030986U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 12962140243967824959U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10240409420338313641U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 18360586077779529086U;
            aOrbiterC = RotL64((aOrbiterC * 18196875422391501927U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 58U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 27U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 39U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 60U)) + aOrbiterB) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterB, 53U));
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 5U)) + aOrbiterE) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererH, 52U);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 26014U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22983U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24309U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 24372U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (aWandererI + RotL64(aPrevious, 51U)) + 15045917390223766480U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 27U)) + 10763054007033668758U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 13190170142593666607U) + aNonceWordL;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 20U)) + RotL64(aCarry, 35U)) + 9657025731441167065U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 41U)) + 11433367178975954211U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 17904920143996810366U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 3U)) + 3244383020512113283U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 6538815775171139091U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7195368312757976343U;
            aOrbiterK = RotL64((aOrbiterK * 10515679176134176565U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 18134430713910279374U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6571776588427107976U;
            aOrbiterF = RotL64((aOrbiterF * 11916502085252589161U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11830778129647517758U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9793702760907767365U;
            aOrbiterJ = RotL64((aOrbiterJ * 4096246227968677179U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2287235876793192036U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8951959188326141794U;
            aOrbiterH = RotL64((aOrbiterH * 9968356718110753845U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7583061790273240157U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3571364625022806085U;
            aOrbiterA = RotL64((aOrbiterA * 6238360922735480669U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13869345563551689212U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 277480328952975002U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 1057564597096163085U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4983735092494677578U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9490022869381030928U;
            aOrbiterB = RotL64((aOrbiterB * 12926352917961703123U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 20U) + RotL64(aOrbiterH, 28U)) + aOrbiterF) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterB, 5U));
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 27915U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 31402U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31523U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30309U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 43U)) + 7722279280863371124U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 11584220561732385598U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 7834679350105534657U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 13U)) + 11347994382444180879U) + aNonceWordJ;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 20U)) + 9449903188047063431U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 6516243976652795170U) + aNonceWordL;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 29U)) + 8420815253991184777U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 9081386852515170937U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14375955191735286867U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 2772840314542262283U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 880757589768436072U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3349856625725164229U;
            aOrbiterK = RotL64((aOrbiterK * 681514212582331781U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7826309957607577207U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8057435761214313635U;
            aOrbiterE = RotL64((aOrbiterE * 4718430712767038607U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 9565237500443303103U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15893066735310588501U;
            aOrbiterI = RotL64((aOrbiterI * 8457633439171452397U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3276844534476430842U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6828644383891274120U;
            aOrbiterD = RotL64((aOrbiterD * 979580351653410157U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2815676923011504251U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5030251870850928417U;
            aOrbiterH = RotL64((aOrbiterH * 7075653570570819253U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13464083008377887034U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8994560761846897590U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 9892839554658865143U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 29U)) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 11U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 44U) + aOrbiterH) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 23U);
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

void TwistExpander_Rugby_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC810A7876F71609BULL + 0xCFEDE25155417619ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCCE7B6E18D0E282DULL + 0xF89D39E2E0F0C753ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD5F8E19228333233ULL + 0xF0AE61A0C20F65D3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA6BC90683BA51C91ULL + 0xE1A3DBCBA3395974ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9DE8977E53A36557ULL + 0xB7DE01D02EE4DEB5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDB503E3347A97A83ULL + 0xA6CD70CC9AFCC6E2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFC9842E592A1FBADULL + 0xB63422788D6DCB2DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB35F0B482292C471ULL + 0xB1BBFA90D42F1A15ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8A0247E6C519D031ULL + 0xACC6DAA1F39D9202ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEB266D5E1414F4B3ULL + 0xC1611E33EB8A2E00ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE8B676AD2E5AE9A3ULL + 0xB357CD89CD825007ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8AE6070B14473D4DULL + 0xD40B8F40106C8885ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8AAB137A442CCDF7ULL + 0x80323C1A8D23D9AEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD110582716F3C0A5ULL + 0x91776CA4F6DDAFBEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE0286B44668B52B9ULL + 0xA91CBCAD86BF6F5CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAEA4C78E34F397F9ULL + 0x93AC7815570E217FULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6825U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 5405U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 840U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 595U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6817U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5062U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 27U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = (aWandererF + RotL64(aScatter, 51U)) + 2783898056762489197U;
            aOrbiterC = ((((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 7177192902873343053U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aWandererD + RotL64(aCross, 3U)) + 12254703232691980774U) + aNonceWordA;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 15446547245691219559U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 23U)) + 888475203006174856U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 3649183529366307877U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 56U)) + 4642631047518805167U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 35U)) + 6108329730724782250U) + aNonceWordC;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + 8334054653023816636U) + aNonceWordG;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 43U)) + 5891895375031474350U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 54U)) + 3176720746238477862U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6111038696865301675U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11914998302228682704U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11738924766359642853U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17005063057791320948U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 18333780598768130670U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 5416759844884107303U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2056115016443263153U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10245512728872962677U;
            aOrbiterB = RotL64((aOrbiterB * 707106795383284903U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4810366069422162351U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3051442983125942469U;
            aOrbiterK = RotL64((aOrbiterK * 13558537578054436423U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9285068547223654308U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13067251130180968842U;
            aOrbiterA = RotL64((aOrbiterA * 7000687697769766605U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3203670242792002165U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1770881716916463461U;
            aOrbiterC = RotL64((aOrbiterC * 13870229847371882171U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16286823712870537410U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13067191141829694202U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 15629974528467350445U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3414576315085336932U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8979691827341555245U;
            aOrbiterE = RotL64((aOrbiterE * 15971594804040295757U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11370607523115189596U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1346943598249651668U;
            aOrbiterD = RotL64((aOrbiterD * 4994794423314630209U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2441719135451272926U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3347272129827184676U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 10434510775894776597U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1116857329130532047U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2783898056762489197U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9504855173533274401U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 12U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 22U) + aOrbiterJ) + RotL64(aOrbiterG, 60U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 48U)) + aOrbiterA) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 43U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterD, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterC, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 52U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12357U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((aIndex + 12894U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 13857U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 16235U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12329U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11309U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9293U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 17225673071833726819U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 39U)) + 10301458382103627331U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 41U)) + 3960233050857362414U;
            aOrbiterK = (aWandererH + RotL64(aCross, 37U)) + 17768665685046605837U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 5U)) + 14471018461213959767U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 54U)) + 10730597892721340453U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 14863394003122760542U) + aNonceWordO;
            aOrbiterC = (((aWandererB + RotL64(aCross, 11U)) + 9948587274816688296U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aWandererC + RotL64(aIngress, 3U)) + 3573569431435100993U;
            aOrbiterD = (aWandererD + RotL64(aCross, 24U)) + 8153670675740450590U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 16438856577722561424U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15765587867581925041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1082039522061775213U;
            aOrbiterG = RotL64((aOrbiterG * 17023740047246402641U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4202521649260798876U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15877659681260461141U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11369910758551088173U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2551560426129646123U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3005102326163906320U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4241583192662435107U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1675501058857208089U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12774812270956702043U;
            aOrbiterI = RotL64((aOrbiterI * 5488437008504905105U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1044886020922563597U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4857445127457225171U;
            aOrbiterF = RotL64((aOrbiterF * 13223560654459705259U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11548725551787560962U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2434677823189765161U;
            aOrbiterD = RotL64((aOrbiterD * 4283026044563670969U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9606875320524736294U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13732615866277657704U;
            aOrbiterC = RotL64((aOrbiterC * 3905528919281629775U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 13921743663803299567U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13350829301153929899U;
            aOrbiterJ = RotL64((aOrbiterJ * 11858642286713079795U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 9473349030551400156U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7446792050826434742U;
            aOrbiterK = RotL64((aOrbiterK * 6619682184124713031U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17970527747978977453U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2326714817603921480U;
            aOrbiterE = RotL64((aOrbiterE * 14581676978186226887U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7875511075130474136U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17225673071833726819U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 1196024136909896027U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 44U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterK, 26U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterA, 21U)) + aNonceWordF);
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 23U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 22U) + aOrbiterB) + RotL64(aOrbiterC, 42U)) + aNonceWordB);
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 5U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD) + aNonceWordD);
            aWandererK = aWandererK + (((((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 21U)) + aNonceWordH) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterK, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19050U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((aIndex + 17537U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 20631U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 18294U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18338U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20117U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22778U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 39U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 3U)) + 7896237440058555694U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 21U)) + 11870529476037558635U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 39U)) + 9158983227801569448U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 5U)) + 4710172270996950329U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 46U)) + RotL64(aCarry, 3U)) + 14634482800356647630U) + aNonceWordN;
            aOrbiterH = (aWandererI + RotL64(aScatter, 27U)) + 8822207952170610891U;
            aOrbiterF = (aWandererE + RotL64(aCross, 11U)) + 13755891414028982553U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 29U)) + 4555293067488040719U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 2816805148093762081U) + aNonceWordJ;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 2122631477965135190U) + aNonceWordG;
            aOrbiterD = (aWandererC + RotL64(aIngress, 14U)) + 4592922416380416071U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7102471666524164715U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17274623547879474204U;
            aOrbiterC = RotL64((aOrbiterC * 5443572270546181789U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 938587316977094680U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 18258015823797023523U;
            aOrbiterH = RotL64((aOrbiterH * 6068819567674605919U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5809987756043471595U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5083075160112581620U;
            aOrbiterJ = RotL64((aOrbiterJ * 3313957222154937503U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5960021727750946496U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 5967477320950630150U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 330964768256424655U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6578428711689296132U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5601728218197771276U;
            aOrbiterB = RotL64((aOrbiterB * 9552559022315971847U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7923809409017855241U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16479366540906497019U;
            aOrbiterE = RotL64((aOrbiterE * 7118578387798460919U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17000467091738009736U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6801634573655508028U;
            aOrbiterI = RotL64((aOrbiterI * 10584635770060137089U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 123668445682719574U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14462802805503986316U;
            aOrbiterD = RotL64((aOrbiterD * 12398236364304875941U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2433338393261685871U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13869012262404991729U;
            aOrbiterA = RotL64((aOrbiterA * 12443261517483942937U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4832421585086516998U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11284414949564414958U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1586650935440790991U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17872556812561387030U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7896237440058555694U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16784165278693056013U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 34U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 21U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aCross, 58U) + RotL64(aOrbiterB, 41U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 39U)) + aOrbiterI) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterE, 18U)) + aNonceWordP);
            aWandererH = aWandererH + ((((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 51U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 57U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 6U) + aOrbiterK) + RotL64(aOrbiterA, 60U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererI, 36U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28192U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 28016U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25048U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27561U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31378U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27230U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 27690U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 29U)) ^ (RotL64(aCross, 60U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 21U)) + 4634399531433127141U) + aNonceWordG;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 16961792729406903200U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 3U)) + 4105280732301137738U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 15692013501147331191U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 1252216715968780587U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 6U)) + 7958289043012473752U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 41U)) + 6611577301818896615U) + aNonceWordN;
            aOrbiterG = (aWandererK + RotL64(aIngress, 43U)) + 8506226754305949140U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 39U)) + 3648813120449403353U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 19U)) + 5195245426245535735U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 36U)) + 542948051600803051U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11974253551208964789U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10596463592332655367U;
            aOrbiterB = RotL64((aOrbiterB * 10941161258815714641U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12015129484061440159U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8254944355710109060U;
            aOrbiterC = RotL64((aOrbiterC * 3233697992479357615U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2754858806943915419U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5007802002906662779U;
            aOrbiterK = RotL64((aOrbiterK * 15613733948331639723U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6262190752136523216U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10528977986487821428U;
            aOrbiterD = RotL64((aOrbiterD * 1184258264034585525U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8511097226098211854U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12091864735686692582U;
            aOrbiterG = RotL64((aOrbiterG * 6128140528141411237U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4970966265236842566U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10728884018459718341U;
            aOrbiterJ = RotL64((aOrbiterJ * 18205183219769602827U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13760057185629905360U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6590269178744829056U;
            aOrbiterF = RotL64((aOrbiterF * 14482684769712170123U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 765826377665103262U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9364759196106579706U;
            aOrbiterI = RotL64((aOrbiterI * 10315111163659289329U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4629303338428087146U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15107221579712215172U;
            aOrbiterH = RotL64((aOrbiterH * 14410837138199304663U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 9407987092859067074U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13589362515507116096U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4544198075069052713U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2236921538387014026U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4634399531433127141U;
            aOrbiterE = RotL64((aOrbiterE * 13132011613143486575U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 36U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 11U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 10U) + aOrbiterB) + RotL64(aOrbiterJ, 23U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 41U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterG, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 27U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterC, 46U));
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 13U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterD, 51U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Rugby_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x884E84291F51443FULL + 0xDAD5F5506D4390ABULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF1E259B95F23FA4DULL + 0xE4410781B7EE9948ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE833A20104716D61ULL + 0x8E81A637A1C6DD00ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x80A75FAAFF6282E1ULL + 0xEF0DA7747FF9F7F5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xECD7EA1E6E91E097ULL + 0xE92415D4D4B25A53ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC5BA18CA6F2F6535ULL + 0xECCE2B0CCCF764D8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x991B194E3190BBDFULL + 0xADCE2D6B8805125CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE983317D97933C6DULL + 0xD4D37C19E2475604ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC215D2AD926F5537ULL + 0xFDEEA7AEDAAF7820ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x84E8AA2DD8DF95C9ULL + 0x8D6D2B8E0049F90CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB84D40A94410300FULL + 0x81E2B29240B7384CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF2022B2C4AEA9BCFULL + 0x945554CE837262C4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFBE02186DFFA23DDULL + 0xE2C1D540B0DB8AC2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDC42CC30FB9DC4ABULL + 0xB2C38A94D8E9FE56ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA495CFA1104C2ACBULL + 0xC9C21CEE0335A800ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9F553EFC1008B807ULL + 0xAB097E53E6909AB0ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2787U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 8158U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5043U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6345U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7474U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 770U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 24U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 18U)) + 12122689833405846292U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 3U)) + 9640400270962766788U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 9141937998266739071U) + aNonceWordO;
            aOrbiterA = (aWandererH + RotL64(aCross, 39U)) + 12899395770434090537U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 27U)) + 13457918115408031842U;
            aOrbiterE = (aWandererA + RotL64(aCross, 57U)) + 15134784483576000943U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 34U)) + RotL64(aCarry, 23U)) + 12540961268790055438U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 47U)) + 6306886773092764230U) + aOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = ((((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 13573343491337243121U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8545588657348974413U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10891410570357275120U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5399310978367842841U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2877137119767060151U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9178097682386595144U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3524486002084427513U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15528007881855616978U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11368419529245281435U;
            aOrbiterH = RotL64((aOrbiterH * 12433207037378339309U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5932738914934356645U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5551842263864055419U;
            aOrbiterK = RotL64((aOrbiterK * 16093776759971522681U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3824433359595690603U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17184628855571662441U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 691208053136187317U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8724462245014132623U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7481349499528092352U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 8212182934509617583U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6908362960248294718U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5354057969992655314U;
            aOrbiterC = RotL64((aOrbiterC * 16586084885820679343U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11138301629323903147U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14164180536320940750U;
            aOrbiterE = RotL64((aOrbiterE * 9099767681053390287U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 709942920176922902U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17128241237359414945U;
            aOrbiterG = RotL64((aOrbiterG * 14063385518459963529U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 22U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 36U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterC, 5U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 53U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterF, 23U));
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 60U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15103U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 14106U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 15328U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((aIndex + 16301U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11410U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11943U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12725U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 54U)) + (RotL64(aCross, 11U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 34U)) + RotL64(aCarry, 35U)) + 7270044678408187242U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 57U)) + 10192278965379756766U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 39U)) + 17568666746676060748U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 43U)) + 14312927531124963037U) + aNonceWordM;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 9825825726152087706U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 27U)) + 9696778570255265896U) + aNonceWordL;
            aOrbiterK = (aWandererG + RotL64(aScatter, 48U)) + 17657841352013417228U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 16207815085909628439U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 13U)) + 1752979206374514227U) + aNonceWordF;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10456310689643905854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16127830548663742550U;
            aOrbiterF = RotL64((aOrbiterF * 4355938404839045417U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2940917376003930842U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7353596864777649953U;
            aOrbiterH = RotL64((aOrbiterH * 7499468723171042005U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12725092740446150705U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5791296650856037010U;
            aOrbiterB = RotL64((aOrbiterB * 760379251950502133U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1200130368046206150U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 16689604428598558547U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13815324235939996623U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 14359561591103730856U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3975025843599045263U;
            aOrbiterA = RotL64((aOrbiterA * 5025047888533298617U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14017901732955607601U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10431526786489555196U;
            aOrbiterD = RotL64((aOrbiterD * 10181915874476132407U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7320527073559849223U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 15333411223710709907U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3488684905528068775U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14302474063321663801U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2104154521019935187U;
            aOrbiterC = RotL64((aOrbiterC * 12944382959742278055U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5167600586916325228U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4566823109447208716U;
            aOrbiterJ = RotL64((aOrbiterJ * 9997799807454267443U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 10U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ) + aNonceWordH);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterI, 10U)) + aNonceWordK);
            aWandererA = aWandererA + ((((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterH, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 51U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterI, 3U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 58U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + aNonceWordO) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 52U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16599U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 23439U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 20077U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 23296U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17862U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22241U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 18597U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 51U)) + 1393781663398437180U) + aNonceWordI;
            aOrbiterD = (((aWandererH + RotL64(aCross, 24U)) + 17414594746688585273U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 47U)) + 2823888497053071250U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 43U)) + 17032631958617884859U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 39U)) + 15222697630461125019U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 14U)) + 15737414920751551780U;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 1357196111055783001U) + aNonceWordO;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 5315122321649251691U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 7893744655508595974U) + aNonceWordK;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16721939414324611738U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3444375866323610848U;
            aOrbiterJ = RotL64((aOrbiterJ * 10874157227815775661U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 1825716513674511632U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15582066843912467318U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12765146555943757373U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 15673590949193923915U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13887365046280406413U;
            aOrbiterH = RotL64((aOrbiterH * 3169061375011420121U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12730414371734709356U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4819112390640821927U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8782547948627685451U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3089925954422937464U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7180179304678622530U;
            aOrbiterA = RotL64((aOrbiterA * 16118051565147747413U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17030269962085008657U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6675917351883004046U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 14134335325316949687U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 12572022803491077491U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2801421744689267375U;
            aOrbiterI = RotL64((aOrbiterI * 315045745990934023U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4335148696780313055U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12526298573395110141U;
            aOrbiterE = RotL64((aOrbiterE * 11276803410698178607U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6984239833558496091U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12195433952105336808U;
            aOrbiterB = RotL64((aOrbiterB * 8642600547427664495U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 34U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 24U)) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aCross, 56U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 60U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31524U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 30123U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 28835U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25354U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28087U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32519U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 29696U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 34U)) + RotL64(aCarry, 57U)) + 785861751704720606U;
            aOrbiterG = (aWandererE + RotL64(aCross, 39U)) + 15968088718435606299U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 1393976526590347151U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 17240750947292745884U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aWandererF + RotL64(aCross, 43U)) + 4921576136163183137U) + aNonceWordE;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 27U)) + 3334047873553153032U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 47U)) + 15086509978458408698U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 18U)) + 892391205397581998U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 3U)) + 2965686403183767521U) + aNonceWordB;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14632215393655706170U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15740589515342377322U;
            aOrbiterA = RotL64((aOrbiterA * 15677716942904794913U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11131164813943086445U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6988080581278900960U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6412189142344044255U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16021254613117657178U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6183615599897921154U;
            aOrbiterC = RotL64((aOrbiterC * 9976411093264211033U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12533992547026652747U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3104325358982904219U;
            aOrbiterG = RotL64((aOrbiterG * 14977348108778147265U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3878525937957474644U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2120435259884368445U;
            aOrbiterK = RotL64((aOrbiterK * 15964718652193073177U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14928658302694194856U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9121310461310309348U;
            aOrbiterF = RotL64((aOrbiterF * 17304439784647477491U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3715693239100476493U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7336577492932262490U;
            aOrbiterE = RotL64((aOrbiterE * 11074754160002665253U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2312452827448455675U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4322756069651934618U;
            aOrbiterJ = RotL64((aOrbiterJ * 6908893297397073539U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4962079617577705818U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5072727464750706525U;
            aOrbiterH = RotL64((aOrbiterH * 4947670001221089155U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 58U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 24U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterE, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 30U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 13U));
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 26U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Rugby_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x859FC099D52640D9ULL + 0xAACA97C3F7137A51ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDF1DD62B4184C685ULL + 0xB04F0D9F8CCAF27BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD287107B20F5DE23ULL + 0x8FE761510C4F912AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFA6E324674F41395ULL + 0x825AEF830B1CDB43ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA134EE469F9D5731ULL + 0x8C54FC43A79205B8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x94B6895168E8B8F1ULL + 0xEC49643051940E67ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8AB3A33E9B4EE853ULL + 0xFD3883106286F690ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF957831D8E58CCB3ULL + 0xA0D2F3B2FA895FFDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF5632A3DC8B7343BULL + 0x815F4ADB904E22BEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFB50EC94385BAD47ULL + 0xCD5A7BFB534C78C2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBE033B3C03EA059DULL + 0xB44D67032F57F0C4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD97FF7A1A606C67FULL + 0xF76F4F6CC6F9697AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9000C42CE14D791BULL + 0xCBE1F9BFA7631303ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB93312C44A6A2DCFULL + 0xD30C683C1AC9D2A3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9F4E920E96A16E87ULL + 0xD568B869910D0539ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x944BB2E7F55B188DULL + 0xF9209CA039F0D9AEULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7745U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 1303U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7197U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4962U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3563U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7101U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 54U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 6163290588946759209U) + aNonceWordJ;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 51U)) + 7342672468560105447U) + aNonceWordO;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 11574563167017282321U;
            aOrbiterH = (aWandererG + RotL64(aCross, 18U)) + 2254820206194758964U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 41U)) + 1469783447473099498U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 14174828900676165088U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 27U)) + 16277954291890598132U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 14845750668693136766U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 150099699692047766U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 7644895634421086357U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 1200784917165131703U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9469982764806754302U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17851969334511301943U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10956702761701710182U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7915506894975487807U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8874108311712727983U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17335794183733623213U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 557028996286989506U;
            aOrbiterE = RotL64((aOrbiterE * 3993359298602424281U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1597385667771002414U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4376417959915162639U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 4626236858205178149U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 549770198518993876U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 756554555648070919U;
            aOrbiterH = RotL64((aOrbiterH * 16272320259614325355U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7298557532533152193U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3336802611342112013U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 14679103452120080499U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + aNonceWordF) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 47U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterF, 40U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 28U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10686U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 14339U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 13811U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9620U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11910U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9700U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9191U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 11U)) + (RotL64(aPrevious, 28U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (((aWandererG + RotL64(aIngress, 4U)) + RotL64(aCarry, 35U)) + 15920462086654025436U) + aNonceWordL;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 13U)) + 487844076858004017U) + aNonceWordB;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 14502883786442630566U) + aNonceWordE;
            aOrbiterA = ((aWandererF + RotL64(aCross, 47U)) + 3787107318658233674U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aScatter, 39U)) + 12548777544693755491U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 4907309444075181683U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 53U)) + 18342396700266492072U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13503051997624242670U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17845742460521374571U;
            aOrbiterI = RotL64((aOrbiterI * 1366356786138085155U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 8640887211877858169U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5273913123709097537U;
            aOrbiterG = RotL64((aOrbiterG * 1661149444148461791U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17756844173695563883U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6713055830729302951U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 2832836748513174311U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5106468334224035972U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10228769728713526172U;
            aOrbiterB = RotL64((aOrbiterB * 9760310686414358435U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 7687649520668883142U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7757480627354711605U;
            aOrbiterA = RotL64((aOrbiterA * 7222553727737349209U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10876291698508634557U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8149278085586014186U;
            aOrbiterD = RotL64((aOrbiterD * 8577133863470695381U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15592893988925610485U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8639028256640537165U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1880655276432963955U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterH, 36U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + aNonceWordF) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 23U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21410U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 17556U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 19676U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 19076U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18595U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16862U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22457U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 12U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 3612110001869385068U) + aNonceWordH;
            aOrbiterJ = ((((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 16340824141280225936U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 37U)) + 15222338965130765231U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 54U)) + RotL64(aCarry, 35U)) + 6649270508107155041U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 27U)) + 768217258655426384U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 19U)) + 4481855259658861851U) + aNonceWordA;
            aOrbiterC = (aWandererI + RotL64(aIngress, 13U)) + 18318041934562434016U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4212457153804401807U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 16143621095636987628U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6576072860505961427U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 2095664232866642086U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4339527736737366572U;
            aOrbiterK = RotL64((aOrbiterK * 17503569508822244125U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13679353177869884790U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11582168502846418236U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 135539430034462861U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10451330452898542191U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12951448817640617841U;
            aOrbiterC = RotL64((aOrbiterC * 4141870904192742091U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15389161934419370747U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 4754886272708253014U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16638243718191281597U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 11746389873929280688U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12042680172517298768U;
            aOrbiterJ = RotL64((aOrbiterJ * 3814780289755857543U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2648103752465009244U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 451594673632597973U;
            aOrbiterH = RotL64((aOrbiterH * 8496763663271072425U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + aNonceWordK) + aWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterA, 57U)) + aNonceWordI);
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterA, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterF, 11U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 40U) + aOrbiterJ) + RotL64(aOrbiterK, 42U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterD, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30329U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 30583U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 28232U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 28229U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28416U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29165U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27016U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 47U)) + 7632760812370906911U) + aNonceWordN;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 21U)) + 6007174525479723089U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 3362829642521821048U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 39U)) + 18009548556107978286U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 56U)) + RotL64(aCarry, 57U)) + 17880909432272697327U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 27U)) + 15961567935420752568U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 10136559064656837921U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17622019364405410277U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6927494824421416306U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2686290883767829973U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7125170407794874847U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12342273503071032250U;
            aOrbiterD = RotL64((aOrbiterD * 867417849555857179U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14997696377476124836U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14874498694181230698U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 4026127545746010937U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2549397729130885686U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4217995818662767955U;
            aOrbiterJ = RotL64((aOrbiterJ * 5525525344485251063U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4706089044415442525U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17983900172670031015U;
            aOrbiterI = RotL64((aOrbiterI * 541552737180932879U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1904937798143929988U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10620877287033139483U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16711012562024287213U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15681091173163181525U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 2655543246639000084U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 16686375598149755947U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterB, 12U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + aNonceWordL) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterH, 41U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 23U)) + aOrbiterB) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Rugby_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBCFB19E070309FFFULL + 0xE90C2BE0F197034CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC93F9CD745ABEF2FULL + 0x9BD861BF966365B5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8C183A5535197653ULL + 0xD4EBE7569519C59AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCB6D5609A0832749ULL + 0x8AEE50E2CB423704ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC40C623D978992BDULL + 0xD6BBB85F29578911ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB0A03162DB454337ULL + 0x918E7BE180533EC1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEC583F4F8B53A119ULL + 0x9133AE46DEE163DCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCF5877808D651E1BULL + 0xD2FC6C25B5E733F5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF7C3A4F5405DC42FULL + 0xC16C92191568FA97ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDE5BBDD742426C07ULL + 0xA3B91084C0B0229AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCCB4589E17A1FA5BULL + 0xC7EE842C0FF23477ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x99CE39DB609C335FULL + 0x8B739EEC160945BCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFA3D24C7ED2432CFULL + 0x8FA6A40B25CEE497ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE8D52BF8D21BD449ULL + 0x91CCEF39AC96AB8AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDF66F80D29FA3D21ULL + 0xB9428EE014810A42ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFCD38B092F6F85B9ULL + 0x94E9C098E3BAD0EFULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 408U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 2414U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1197U)) & W_KEY1], 13U) ^ RotL64(mSource[((aIndex + 2691U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 21U) + RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 12809562813316740345U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aWandererH + RotL64(aCross, 35U)) + 17084212535326321199U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 60U)) + 16074921689983846769U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 14027986153007120145U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 13U)) + 7633455951809250227U) + aNonceWordE;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 53U)) + 340989348513370174U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 5307820377645020116U) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5605285015771527274U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5293500434746182790U;
            aOrbiterI = RotL64((aOrbiterI * 17674669610895537063U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7263156475892261811U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10672879570907433005U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2506338667179450741U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16659226780900986107U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 9774892622769850665U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7487477727543183211U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10728057184108279042U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5032485856947407217U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16651577903809154285U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14642241075374862345U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8386481273395203518U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11649977733867003445U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2874153265304098104U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11519900149177261000U;
            aOrbiterC = RotL64((aOrbiterC * 2010158758971864505U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8885690878540115768U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4482143389870987714U;
            aOrbiterD = RotL64((aOrbiterD * 7105332459437434281U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 60U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + aNonceWordI) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + aNonceWordC);
            aWandererA = aWandererA + (((((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 57U)) + aNonceWordH) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 14U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 5051U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 4529U)) & W_KEY1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4070U)) & W_KEY1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4905U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aIngress, 13U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 2177539223979303669U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 3962004686551521471U) + aNonceWordG;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 29U)) + 8457602312617147662U) + aNonceWordF;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 51U)) + 18011802451816510632U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 9046101759168876832U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 18U)) + 11135620637431969597U) + aNonceWordB;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 57U)) + 15913029940697999701U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 16304193109948135982U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13208892298820080981U;
            aOrbiterK = RotL64((aOrbiterK * 15093751072618884859U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4182377898949419225U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13970137023071326151U;
            aOrbiterJ = RotL64((aOrbiterJ * 9075061559681739865U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8402396284835248583U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8859190834060657829U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13552418608113716117U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9760005337757990392U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 14108277760135744897U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4474681104256093885U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12226316121949012350U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3456392186754113960U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8704729827929941215U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 5004087958637038973U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7176881295123125567U;
            aOrbiterB = RotL64((aOrbiterB * 15272157962928021009U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10889800478505074438U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13728832441482547824U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 17588477761978646139U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ) + aNonceWordN);
            aWandererI = aWandererI + (((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 13U)) + aNonceWordD) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 22U) + aOrbiterK) + RotL64(aOrbiterA, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 6U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterB, 13U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererI, 22U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 6335U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadB[((aIndex + 6125U)) & W_KEY1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6788U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6298U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6536U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 51U)) + 6654158889644956636U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 9045779659363991870U) + aNonceWordO;
            aOrbiterK = (aWandererC + RotL64(aCross, 19U)) + 3888897662136993491U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 47U)) + 6882016842864459345U) + aPhaseEOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 15601891715956172291U) + aNonceWordK;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 43U)) + 5176811598629335350U) + aNonceWordB;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 27U)) + 12519945150889074325U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4552583214397603278U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14225482701804864688U;
            aOrbiterK = RotL64((aOrbiterK * 8526052833180466359U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5485298070606280363U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11237713257388094289U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11032429223099413011U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14340345895626142788U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16275167270553643347U;
            aOrbiterD = RotL64((aOrbiterD * 7308578867128951199U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14041860597556520250U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1436068974197066343U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 3938460345031496843U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11483155566419547004U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4608508534724289325U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13461385011638899485U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2389196334288832895U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4062682330273866602U;
            aOrbiterI = RotL64((aOrbiterI * 8787682133271101901U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5655656046585592034U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7977947821249746880U;
            aOrbiterH = RotL64((aOrbiterH * 10082104644185964787U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordF) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 60U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterH, 21U));
            aWandererI = aWandererI + (((((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 27U)) + aNonceWordL) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererG, 38U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9450U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 10322U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 10215U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9625U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9992U)) & W_KEY1], 43U) ^ RotL64(aFireLaneB[((aIndex + 8534U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 36U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = ((aWandererA + RotL64(aScatter, 5U)) + 11210042748013785976U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 4584747303233477454U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 8878765929792969517U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 2172232330280041122U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 43U)) + 8378937026022264016U) + aNonceWordC;
            aOrbiterH = (aWandererH + RotL64(aScatter, 53U)) + 8683007464695824208U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 12U)) + 9564352997357118134U) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11713878436769887528U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8052917623074021077U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7450115139081623477U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7720597162792145185U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2602847785328475621U;
            aOrbiterI = RotL64((aOrbiterI * 14065077077207224525U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17813669222300509724U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8724263063156573013U;
            aOrbiterH = RotL64((aOrbiterH * 3632927017737834359U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6882429835961613492U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13213313479525717359U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 2411431247725974895U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2401526093648669573U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3616448566579979749U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 13323155103752121393U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 18268262471839710401U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5116424918948694752U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7641143782996332069U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11405305689555640431U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12427591396711015574U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 8112834135715541223U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 34U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + aNonceWordA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterC, 51U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 34U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterE, 3U)) + aNonceWordM) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12705U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 10989U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12998U)) & W_KEY1], 13U) ^ RotL64(mSource[((aIndex + 11849U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 12275U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11050U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneC[((aIndex + 12129U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 28U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 13U)) + 11410829607777684449U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 37U)) + 7502698839700975347U) + aNonceWordK;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 13267685058252106173U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 51U)) + 238242706996630625U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 29U)) + 8184695499511454281U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 12767823220461985403U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 43U)) + 12293198423143850330U) + aNonceWordP;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11149495229952495939U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7556992689338382800U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 18232398462716803063U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3431338808774134649U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16863099140844995099U;
            aOrbiterB = RotL64((aOrbiterB * 752376661101787919U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17872458049880677604U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16760153457252546974U;
            aOrbiterD = RotL64((aOrbiterD * 11225037229069712805U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3115544493537438408U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 4359882942759752958U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 561477566995575801U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13387113067202396536U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 12955690074544490161U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 12449941770827974511U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15614054443728226807U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1939441328066616114U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4484917074808974359U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4599016263007782537U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9962305629016158048U;
            aOrbiterE = RotL64((aOrbiterE * 1496184427500037279U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 29U)) + aOrbiterG) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterA, 21U));
            aWandererH = aWandererH + ((((RotL64(aCross, 34U) + RotL64(aOrbiterE, 53U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 36U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aNonceWordM) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 14960U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneC[((aIndex + 15973U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13868U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16241U)) & W_KEY1], 19U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13704U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14501U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15565U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 11U)) + 4259993311776766595U) + aPhaseFOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = ((aWandererI + RotL64(aCross, 3U)) + 2857813330021126753U) + aNonceWordN;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 1345396841329442896U) + aNonceWordK;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 320992148982301024U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 57U)) + 5619109532065293074U) + aNonceWordG;
            aOrbiterD = (aWandererH + RotL64(aScatter, 21U)) + 10380157329426706345U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 28U)) + RotL64(aCarry, 23U)) + 12449831150625409695U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7847096607042268396U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11707184096803214678U;
            aOrbiterC = RotL64((aOrbiterC * 1959476948106553973U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9893643746186827088U) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 333687403830908774U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 17911256836121454271U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13837360705077441580U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4367119682175710689U;
            aOrbiterD = RotL64((aOrbiterD * 10295744669174603401U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1193493435041306784U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15062951612027370606U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2509383510565136549U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16000173839235429105U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15294482444605409961U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1031800997944302665U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5720749055549773527U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17248674962996093668U;
            aOrbiterI = RotL64((aOrbiterI * 15730637462755795591U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16956840483882091059U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9637715107943515594U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 8878362378343603463U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 38U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterF, 39U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterD, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aCross, 4U) + RotL64(aOrbiterC, 53U)) + aOrbiterG) + aNonceWordL) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterF, 14U)) + aNonceWordD) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16573U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 18278U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(mSource[((aIndex + 17156U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18103U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17210U)) & W_KEY1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18847U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 16995U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 19U)) + (RotL64(aIngress, 60U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (aWandererB + RotL64(aScatter, 27U)) + 2168513956284366370U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 5U)) + 10290361969974613111U) + aNonceWordG;
            aOrbiterD = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 15673836275828498050U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 16600540024145812236U) + aNonceWordO;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 9428052101528111892U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 21U)) + 12763657928312763377U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 58U)) + 10751286982008662485U) + aPhaseGOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1708230173038057979U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4011389705422783816U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11692237130784795961U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11704428328093077714U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2055336619674699284U;
            aOrbiterJ = RotL64((aOrbiterJ * 6374289210096410907U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1870865272102705804U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3574214263751923179U;
            aOrbiterF = RotL64((aOrbiterF * 13132083406834413563U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 984611970726966186U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15207945449947643672U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 9539470161576639981U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4181398506373973169U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15222345431506025949U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6925143692628659467U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15023513452326240962U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14965669361708810699U;
            aOrbiterC = RotL64((aOrbiterC * 587008860996713147U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7985755518735406360U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 225592097619240187U;
            aOrbiterA = RotL64((aOrbiterA * 2313509354133400439U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 4U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + aNonceWordJ);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterE, 5U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterF, 28U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + aNonceWordB) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aIngress, 26U) + RotL64(aOrbiterA, 43U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aNonceWordM) + aPhaseGWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterC, 19U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20849U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 19167U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 21308U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21073U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20987U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20249U)) & W_KEY1], 13U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20462U)) & S_BLOCK1], 34U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21287U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 12046647397183218524U) + aNonceWordF;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 19U)) + 2760779375026461991U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aIngress, 57U)) + 13735454443176855650U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 44U)) + 4370377000586647724U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 14566322384189969094U) + aNonceWordB;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 5056565959818422786U) + aNonceWordN;
            aOrbiterF = (aWandererF + RotL64(aScatter, 13U)) + 8795403810686579209U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9625947666256011567U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1703669290934254701U;
            aOrbiterA = RotL64((aOrbiterA * 5763881345676123583U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6664070663184147951U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2104148316797553431U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12887842067180975983U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1197910004222596145U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9922977170060903197U;
            aOrbiterD = RotL64((aOrbiterD * 13047828062605568603U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2048376210852567829U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12568990647075931409U;
            aOrbiterJ = RotL64((aOrbiterJ * 9860242601194210927U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15026894775772902751U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3439447160137900629U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 1813754963043785165U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6532671388552829796U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 17261098369835997661U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 568292591215203521U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3171300991007459947U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5935563269327662024U;
            aOrbiterF = RotL64((aOrbiterF * 11271790283157765003U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterA) + aNonceWordP) + aPhaseGWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordH) + aPhaseGWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterD, 60U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22368U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 24385U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23852U)) & W_KEY1], 4U) ^ RotL64(aWorkLaneC[((aIndex + 21953U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23967U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23628U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23114U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((aIndex + 22224U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 36U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 4848316479321533394U) + aNonceWordA;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 21U)) + 6919360256662636195U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 43U)) + 9897013582181108544U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 7319353809896158678U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 57U)) + 2848175435514849859U) + aNonceWordM;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 36U)) + RotL64(aCarry, 41U)) + 6967780718720437934U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 11U)) + 10143884766603388136U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8675965006150972051U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16350117755560994281U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 15072308930382994425U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17976597517118423760U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1399631141355370237U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16537788276543236833U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3590613762034716792U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5134624314245932157U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13077589037975283371U), 23U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 10082236952942943654U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4015535035905433450U;
            aOrbiterA = RotL64((aOrbiterA * 4961808568701908559U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 611474103801573800U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5786708483794098001U;
            aOrbiterJ = RotL64((aOrbiterJ * 7694007039340089267U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5201943497363274455U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9282160506938328489U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 5368182164239021367U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4932320527498940158U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11576526341731392916U;
            aOrbiterI = RotL64((aOrbiterI * 1712051774729439363U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + aPhaseGWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 46U) + aOrbiterJ) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 21U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + aNonceWordI) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24991U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 24909U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 24975U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 26466U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26209U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24843U)) & S_BLOCK1], 20U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25634U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26587U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 39U)) + 12980104182836602177U) + aNonceWordN;
            aOrbiterI = ((((aWandererC + RotL64(aIngress, 56U)) + RotL64(aCarry, 5U)) + 3172622203188863995U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 1170974132219980203U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 6035201940965047490U) + aNonceWordC;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 21U)) + 18033907118424996722U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 47U)) + 14604813424800580304U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 11U)) + 13720232492851066035U) + aNonceWordO;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3902659710585257448U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8331560652661619868U;
            aOrbiterA = RotL64((aOrbiterA * 11418103770615560205U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4485014147538689794U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 168202636924512424U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 13711020666131492091U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16227825670092707848U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4792781933944671365U;
            aOrbiterE = RotL64((aOrbiterE * 15859849676231455283U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12636865372722601282U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 18198291399585556632U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18155803890313399795U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3650053185419807206U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5897288963905408776U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3706949366974086151U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9922308113622901726U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13352279749091561510U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4025213180483632557U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14969461950939646117U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10231661776135056651U;
            aOrbiterK = RotL64((aOrbiterK * 11284575051455238501U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 20U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterH, 27U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + aPhaseHWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 6U)) + aOrbiterD) + aNonceWordM);
            aWandererK = aWandererK + ((((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 37U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27465U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 27384U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28761U)) & W_KEY1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 27473U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29184U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28512U)) & S_BLOCK1], 58U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29542U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29702U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 2783898056762489197U) + aNonceWordC;
            aOrbiterI = ((aWandererB + RotL64(aCross, 13U)) + 7177192902873343053U) + aPhaseHOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 12254703232691980774U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 15446547245691219559U) + aNonceWordH;
            aOrbiterD = (((aWandererC + RotL64(aCross, 47U)) + 888475203006174856U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 60U)) + 3649183529366307877U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 5U)) + 4642631047518805167U) + aNonceWordK;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6108329730724782250U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8334054653023816636U;
            aOrbiterJ = RotL64((aOrbiterJ * 9352516059501924393U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5891895375031474350U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3176720746238477862U;
            aOrbiterD = RotL64((aOrbiterD * 1869961473768307911U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6111038696865301675U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11914998302228682704U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11738924766359642853U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17005063057791320948U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 18333780598768130670U;
            aOrbiterI = RotL64((aOrbiterI * 5416759844884107303U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2056115016443263153U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10245512728872962677U;
            aOrbiterK = RotL64((aOrbiterK * 707106795383284903U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4810366069422162351U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3051442983125942469U;
            aOrbiterH = RotL64((aOrbiterH * 13558537578054436423U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9285068547223654308U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13067251130180968842U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 7000687697769766605U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 60U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 39U)) + aOrbiterH) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 50U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterD, 46U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterK, 53U)) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterD, 27U)) + aNonceWordO) + aPhaseHWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterD, 13U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30811U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30373U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31454U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31715U)) & S_BLOCK1], 20U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32520U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32609U)) & W_KEY1], 39U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 19U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 8767379393098711499U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 22U)) + 7168159491580816433U) + aPhaseHOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 35U)) + 9879279829061883406U) + aNonceWordK;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 5U)) + 10537167136053399303U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 47U)) + 2839070018069188936U) + aPhaseHOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 13844278063968429732U) + aNonceWordH;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 11278946626186474646U) + aNonceWordB;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11798425216660557799U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7618446090703335192U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 7168757300685156779U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 695423597006983660U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14344728202803488813U;
            aOrbiterE = RotL64((aOrbiterE * 5168825904902285909U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11656100506575697086U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10384358779985773937U;
            aOrbiterI = RotL64((aOrbiterI * 247494692039140973U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17585001605131977341U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9964478171465522911U;
            aOrbiterF = RotL64((aOrbiterF * 13484044854790175315U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 2710943171829692624U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17809072853457153057U;
            aOrbiterC = RotL64((aOrbiterC * 16341884203303271365U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12814092033910687774U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1743186323268668740U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 11150822630624332557U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10750472346626754704U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15925901217078035356U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9276504171291801637U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 23U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterA, 44U));
            aWandererA = aWandererA + ((((RotL64(aCross, 30U) + aOrbiterK) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 5U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 51U)) + aOrbiterI) + aNonceWordM);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Rugby_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8085CE9B0B4C8517ULL + 0x98FEEDC51E258D85ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC59A5E29AA485451ULL + 0x972EADD3D451BA00ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB1486F741ABC5285ULL + 0xC8B7B6EE83C63D10ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x83D6A5154980BC9FULL + 0xD2DEFC063D3C84AFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEE48DBAFF66CA0EBULL + 0xEDAECD7082671F75ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF1AD146D5D294AF1ULL + 0xFD5A6D629C6CFDAEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8BF593264DA5EC09ULL + 0xE398F8F40BB6407DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8F96C12B0B9DD1E7ULL + 0xCD74FF6E8CEB359AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE5A1E6907DA212B5ULL + 0xFB6574CE24BEDC1EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8AC54CF69274BEEFULL + 0xBC257BB41ED18D9DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x812BB630D38ACBC7ULL + 0x890D3C9D45E9C944ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x970DFA27F4B015B9ULL + 0xCD4947B95C069CDAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE0015604B7555D7DULL + 0xCC07E16621C39425ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFA3AF8E3B93585B5ULL + 0x928C95BFD4A6A964ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9A912F77F6867E4DULL + 0x877AB78C0CDA18F6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC7596A81D03238ADULL + 0xB8073FCBD5543A83ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1935U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 1118U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2187U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4724U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1356U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1073U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 4U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = ((((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 1866656689936219099U) + aPhaseAOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 56U)) + 2312314528139448289U) + aNonceWordE;
            aOrbiterD = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 3554037526469185237U) + aNonceWordD;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 405707755060974111U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 47U)) + 1862976326004007697U) + aPhaseAOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12992483065443288263U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3793854946371595197U;
            aOrbiterD = RotL64((aOrbiterD * 1819119223110966487U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4244007978867369382U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 10280867500312580308U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 13729899124177931289U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 472563452959164242U) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12041770406895816553U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 17811798500132002631U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6118634015704900486U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13637107920449233307U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17712028184714868053U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16673735670669318830U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8602681273646630496U;
            aOrbiterC = RotL64((aOrbiterC * 6995213887710749241U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 41U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aNonceWordF) + aPhaseAWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + aNonceWordG);
            aWandererI = aWandererI + ((((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 29U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 7647U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 6731U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8795U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8710U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7926U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9927U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8965U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 53U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 8506388683755208267U;
            aOrbiterC = ((((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 23U)) + 2179323259055019735U) + aPhaseAOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 3345902531140983016U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 19U)) + 17456139311481306584U) + aNonceWordF;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 43U)) + 14587864088462311164U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13178947246650647057U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12866578138946916962U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 121991325166969319U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 13098524333655118173U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15451329483787541982U;
            aOrbiterJ = RotL64((aOrbiterJ * 13580376920467431451U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9494299579678389385U) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15581954810375490643U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13670002280188424825U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4487042505730624892U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 2774455928791636186U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15847933919136777451U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12435319582397755819U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10077180055177766823U;
            aOrbiterK = RotL64((aOrbiterK * 3924363471701748703U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 14U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 58U)) + aOrbiterE) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 38U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14186U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 14531U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12477U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14789U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 11213U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 29U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 17912271996338180948U) + aNonceWordN;
            aOrbiterH = (aWandererD + RotL64(aScatter, 53U)) + 13259276608841847058U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 16225936008657276089U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 2243058962151834071U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aScatter, 30U)) + 10637439274127347861U) + aPhaseAOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15312219216405992627U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2393933972129878613U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 13147717214387593761U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4327069337247976513U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8307656353434167837U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11386588389133096705U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 17299145556933889336U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 14458100581172798164U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16543734663677070509U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6410095654927998067U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6168964796264687686U;
            aOrbiterH = RotL64((aOrbiterH * 16218071040190475953U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3667999465041020730U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16021552859323602007U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 6427266472526362663U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterD, 36U)) + aNonceWordE);
            aWandererD = aWandererD + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterD, 57U)) + aOrbiterK) + aPhaseAWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 40U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20523U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((aIndex + 19653U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20351U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20933U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 17115U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 60U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 16922357079016918108U) + aNonceWordE;
            aOrbiterG = ((((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 11771749797137599131U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 10U)) + 4635668433708036077U) + aPhaseAOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 47U)) + 15827952719230577008U) + aNonceWordN;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 1495675306110023086U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 7294835466949728365U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 179122461212041978U;
            aOrbiterC = RotL64((aOrbiterC * 14467072888722097971U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 545981421632236251U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15338259639814630535U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14895421566334357871U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12924313840290895215U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17846785921286020610U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18309347016029917133U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5721472794107057875U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16359630793856870319U;
            aOrbiterK = RotL64((aOrbiterK * 14186771515526698907U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10614102110239037308U) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16421992251278236531U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2561232904676068089U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 54U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterC, 51U)) + aOrbiterF) + aNonceWordP) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 12U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterG, 37U)) + aNonceWordB) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 23U)) + aOrbiterE) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22210U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneB[((aIndex + 25037U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25234U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25014U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23439U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 24U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 27U)) + 10881271196314989997U) + aNonceWordF;
            aOrbiterG = ((((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 6406461249988567558U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 38U)) + 17255067918280095959U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 16690850682497718411U) + aNonceWordL;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 5576201059361086866U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11991259685693687554U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14652535244217836909U;
            aOrbiterJ = RotL64((aOrbiterJ * 18283959577075524171U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 1701789037170782122U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 953429054903473833U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 13482379459700651427U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12064513610469714211U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7993881398822002424U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11572884842788918377U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14421313768013320050U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11112386845630998889U;
            aOrbiterE = RotL64((aOrbiterE * 11771526352030371669U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 17069630896535699015U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3308240081138623373U;
            aOrbiterH = RotL64((aOrbiterH * 10449509484417835159U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + aPhaseAWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 28U)) + aOrbiterG) + aNonceWordI) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 44U) + aOrbiterH) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterK, 5U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31319U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((aIndex + 29533U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 29436U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28349U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 28507U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 12206125048349568300U) + aNonceWordN;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 14U)) + RotL64(aCarry, 47U)) + 5843520589343188818U) + aNonceWordO;
            aOrbiterJ = (aWandererK + RotL64(aCross, 5U)) + 12195046124287121687U;
            aOrbiterI = ((((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 16769779119214020640U) + aPhaseAOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (((aWandererB + RotL64(aCross, 51U)) + 5257603646260695833U) + aPhaseAOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8523523946234886745U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7316024684200084096U;
            aOrbiterJ = RotL64((aOrbiterJ * 11620083021691341337U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11996978575084115207U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 15491711479085513628U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 15136690392026011819U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 6036648530996821484U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 926323222234121863U;
            aOrbiterG = RotL64((aOrbiterG * 6639661141258803779U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2700323841295743492U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 5852273765810284935U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 16665696735016345215U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11697397483133538067U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17777142964957007194U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6338967222543284999U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 6U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterG, 37U)) + aNonceWordI);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Rugby_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCA335446CF221FADULL + 0xB23A77DB2E26CFC0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF2232C3E910FA6B9ULL + 0x96497AD2EFC61790ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE5800137E1B77BCFULL + 0xD5D27D2952605406ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC63B51E0D2241817ULL + 0xE7DE34F91DAA31C9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC8533AA317DCE64DULL + 0xBFE1E24A92883197ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE869C274593BDE21ULL + 0xD327B0F331035322ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDEC6E2B9FB8858EFULL + 0xD3F15F3A4F979F01ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x986E65C86671FD97ULL + 0x84F09F785B4425EAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB778EE5CC0A8F237ULL + 0xDDB8EB4EC746AAC0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEE2C2E94F667D109ULL + 0xA86EEC76FD49B6B1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBF769E9156E63EF9ULL + 0xE8072C09FB5BFAE8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x99ED10E97D65DCB9ULL + 0xF2AC7D05BF86EAC4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA50B8217292CC1D7ULL + 0x8D7FA19730095803ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x982D54C69C89FC8BULL + 0xB5CF9EEBA5C66EA4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDD2C0B43D3E217D5ULL + 0x9D6832CED0417AF4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x80EFEF32C9E6A1DDULL + 0xFED15400FC025253ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4626U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 5146U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 221U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1797U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4232U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 643U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 20U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 43U)) + 1708250618750199233U) + aNonceWordB;
            aOrbiterI = (aWandererF + RotL64(aCross, 11U)) + 12009147777553691142U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 34U)) + RotL64(aCarry, 19U)) + 8393982703399156592U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 3247327098356831221U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 3403590155376353737U) + aNonceWordE;
            aOrbiterD = ((aWandererG + RotL64(aCross, 5U)) + 18197244558104735044U) + aPhaseBOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 60U)) + 3096253642040701606U) + aNonceWordD;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 29U)) + 8012692688785412179U) + aPhaseBOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 47U)) + 17531946907545680745U) + aNonceWordK;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17687695944270225817U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16147773866007628769U;
            aOrbiterG = RotL64((aOrbiterG * 16926442582711557877U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 18244641303026196497U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8839160526348897457U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 14268021129087663397U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10599266240854068246U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2056723540756216155U;
            aOrbiterI = RotL64((aOrbiterI * 13311591601230386375U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4629354220460621284U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9505955649473204942U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17775391885312236187U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17078153810088721310U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9470436761716263000U;
            aOrbiterC = RotL64((aOrbiterC * 5431855497250357229U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3305863413630104742U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14377172434239576161U;
            aOrbiterJ = RotL64((aOrbiterJ * 6880176890091033423U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 415687827894226513U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16975319836893760993U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 6597144958013976445U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12707054129431596074U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8974182792497231239U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7874658957269462717U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10826131924322955095U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4168545139712703154U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 10305904857550051705U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 48U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 58U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterF) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterF, 34U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterG, 19U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 36U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 40U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 29U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15213U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((aIndex + 8872U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 11000U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14519U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15437U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13759U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15495U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 12U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = (aWandererA + RotL64(aCross, 18U)) + 13714409587461539863U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 29U)) + 14101156723903265839U) + aNonceWordH;
            aOrbiterI = (aWandererI + RotL64(aIngress, 23U)) + 7063754562895369001U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 12320578575245519386U;
            aOrbiterA = (aWandererF + RotL64(aCross, 13U)) + 11744826789631008424U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 48U)) + 8744816505096675597U) + aNonceWordI;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 35U)) + 10405435520084528645U) + aPhaseBOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 1463157688070683543U;
            aOrbiterB = ((((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 12379603577919617703U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1343439118031348146U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16118850268070235540U;
            aOrbiterI = RotL64((aOrbiterI * 11184386483735388257U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14116264435819277136U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5251698273012432109U;
            aOrbiterA = RotL64((aOrbiterA * 1495818611622063967U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14806408656041403829U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11569345414052398227U;
            aOrbiterH = RotL64((aOrbiterH * 9913158908301414861U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17063874769147888574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9927420478679581917U;
            aOrbiterF = RotL64((aOrbiterF * 9042782809534196563U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2550285599827162167U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17801534123304996448U;
            aOrbiterK = RotL64((aOrbiterK * 2160836889363614721U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6456685241021762041U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17064208177372969289U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13726627607233302493U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 18279938244131982650U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8211002229712129419U;
            aOrbiterC = RotL64((aOrbiterC * 12931373380977640645U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12795832560781931767U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 286378504074349650U;
            aOrbiterB = RotL64((aOrbiterB * 85453101173293509U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5835304250436889513U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12704972686724379659U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 1198789639656336053U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 42U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + aNonceWordJ);
            aWandererD = aWandererD + ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 56U)) + aOrbiterF) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aIngress, 52U) + aOrbiterK) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + aNonceWordP);
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 37U));
            aWandererH = aWandererH + (((RotL64(aScatter, 4U) + RotL64(aOrbiterH, 12U)) + aOrbiterB) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22596U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 17222U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 19686U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 19113U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19038U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16511U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24008U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 47U)) + 18302975933754610273U) + aPhaseBOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 16736972646771456082U) + aNonceWordL;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 18U)) + 17389406266488137442U) + aNonceWordG;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 5252511566486165539U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 5730715427422747640U) + aPhaseBOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 27U)) + 6412695646456045825U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 34U)) + 9539701605708994494U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 11U)) + 18355107116412945722U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 51U)) + 11735742491750132942U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12363819388562658842U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5861430292304371543U;
            aOrbiterK = RotL64((aOrbiterK * 12989055611235382695U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15027487084595017708U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7012850020745791926U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15952928839355613939U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11904871669287886120U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11199760114477343208U;
            aOrbiterJ = RotL64((aOrbiterJ * 7156374911847525867U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3856004502263742700U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3705931243173921893U;
            aOrbiterC = RotL64((aOrbiterC * 10334871178498711485U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 12305785390539209389U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 18057980996551978823U;
            aOrbiterA = RotL64((aOrbiterA * 4850564181113470859U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3229431819292153014U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2994716629242460094U;
            aOrbiterH = RotL64((aOrbiterH * 1029427328395257917U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9796307843453735512U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2957260393651252432U;
            aOrbiterI = RotL64((aOrbiterI * 7261055869794739609U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 4060469664218866340U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17462081697889685330U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7712009170974461225U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13638660073917821172U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15202349592659062565U;
            aOrbiterD = RotL64((aOrbiterD * 4514326257446024301U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 38U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterA, 47U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterD, 30U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 21U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 47U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 13U)) + aOrbiterK) + aNonceWordJ) + aPhaseBWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 37U));
            aWandererC = aWandererC + (((RotL64(aScatter, 54U) + aOrbiterJ) + RotL64(aOrbiterK, 26U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26969U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 30901U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27111U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 24610U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26909U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25537U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27259U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 19U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = ((aWandererJ + RotL64(aCross, 47U)) + 16160838483846078448U) + aNonceWordC;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 15404960896190227946U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 27U)) + 16904160594024977199U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 57U)) + 17790460246821031802U) + aPhaseBOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 18U)) + 16395168254086971959U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 5U)) + 7484373204039901786U) + aNonceWordK;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 41U)) + 18026814691322913510U) + aNonceWordJ;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 15244817793136966450U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 34U)) + RotL64(aCarry, 51U)) + 5795491730356335666U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3163873518027801504U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2690791759507349172U;
            aOrbiterH = RotL64((aOrbiterH * 16677948635136515083U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17898067251167087906U) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8028010015006604239U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 5601629670521300241U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7304739457289910555U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6476837815096530043U;
            aOrbiterI = RotL64((aOrbiterI * 16380545138701113267U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14242499233467960602U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17305645693017634630U;
            aOrbiterA = RotL64((aOrbiterA * 14442976693206929569U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9772864059444171908U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7897200728282156408U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 816306719390807411U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4890999319172950996U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8165132649356094963U;
            aOrbiterK = RotL64((aOrbiterK * 17297706071263690189U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9342923520083533265U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7213639583505088067U;
            aOrbiterC = RotL64((aOrbiterC * 1349251979649428909U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4079475132684197272U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3350998022472827283U;
            aOrbiterB = RotL64((aOrbiterB * 948841791460066265U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2479140576609216238U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7703147534931674972U;
            aOrbiterG = RotL64((aOrbiterG * 11419116495223970801U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + aNonceWordM);
            aWandererK = aWandererK + ((((RotL64(aCross, 35U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterC, 43U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 22U) + RotL64(aOrbiterH, 12U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 19U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB) + aNonceWordI) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 18U) + aOrbiterK) + RotL64(aOrbiterD, 58U)) + RotL64(aCarry, 13U)) + aNonceWordP) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterK, 23U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Rugby_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF4F222C9A2D1747BULL + 0x8F043181426C8713ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE2FF3F1CBA182BC1ULL + 0xBFB3D3B17490BBD8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC0BC4A586CD82155ULL + 0x9D5A119945CFACA4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC7FFFC61D8EF6B97ULL + 0x8B07B7676FDDC7EFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAE11A281764347FDULL + 0xECF2F3FAB21380FDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF0D2F629E7FA269FULL + 0xF1C30F066F84591EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD5A48CC21A74F471ULL + 0x88FA11870F39F7B7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8C234F1F46F18F37ULL + 0xD18CDC68A49A92F9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBBBF839970F573CBULL + 0xEE18245A46CEC79AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8374BFDD46C678EDULL + 0xCB828530D73EED68ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA0C44371A1BC1BC7ULL + 0xBA3C4D8627E65D1AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB2CE6D6F16B9DF23ULL + 0x8ADCB7E935D9EB46ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC19B189471D98557ULL + 0xB7B4457D36DC614AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA2CF1241C8C78C65ULL + 0xEA8D1E199B55210AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA83BEA168B4A00FBULL + 0xD458F25ED9FD23FFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB159C2D42BED5AFFULL + 0xEEACEE23FB0719FFULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4643U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 305U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1637U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2698U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1131U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4696U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aIngress, 51U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 3U)) + 8975885703279267062U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aScatter, 35U)) + 8664844915562660637U;
            aOrbiterI = (((aWandererC + RotL64(aCross, 28U)) + RotL64(aCarry, 3U)) + 12281774799736296726U) + aNonceWordI;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 15347461352311329726U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 51U)) + 12967500561828907834U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 13U)) + 5002833859280402726U;
            aOrbiterK = ((((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 11908257536954668983U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17017174811949227162U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16851323125613931180U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12446990992858763577U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13469326957728686706U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5228638551056105241U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13369947664646167255U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11945166198089308564U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16268645041872996022U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 5391448793718370911U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14781204627695095701U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5365325354838101092U;
            aOrbiterC = RotL64((aOrbiterC * 8017284997946310807U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 563147416025715953U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14660867395395625851U;
            aOrbiterA = RotL64((aOrbiterA * 4769458126865307103U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3168989056355712105U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 16179131669773665579U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5641461617066671723U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4160220074225527179U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8597134686962559111U;
            aOrbiterH = RotL64((aOrbiterH * 639572585431474015U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 4U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterK, 36U)) + aPhaseDWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 29U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterC, 3U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 12U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererK, 4U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7527U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 9090U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8544U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 9592U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7903U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10557U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7774U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 18255347001097480328U) + aNonceWordM;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 4U)) + 13679246790311505735U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 10565839529765027116U) + aNonceWordA;
            aOrbiterK = (aWandererH + RotL64(aScatter, 53U)) + 14327172566224769901U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 35U)) + 16239024612038195174U;
            aOrbiterB = ((((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 13800012174212131890U) + aPhaseDOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 23U)) + 13900288860157577583U) + aNonceWordK;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 4144386119777112740U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3154558262670631372U;
            aOrbiterG = RotL64((aOrbiterG * 13236911910092437063U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7456728543137614001U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11709519851158935384U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7016689518570071587U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15607438907832240304U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9276575329661725624U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8879744070762412745U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6459435969129449226U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 6442382118416542275U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 2921027306686588233U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12117432107282150865U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6831279293184793243U;
            aOrbiterC = RotL64((aOrbiterC * 2435360641135249073U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9520022957804572889U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8322178689474588679U;
            aOrbiterJ = RotL64((aOrbiterJ * 1627707191467537115U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4162401591586869316U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8994015844714895961U;
            aOrbiterA = RotL64((aOrbiterA * 15421910378057951895U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterB, 18U)) + aOrbiterD) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 41U)) + aOrbiterD) + aPhaseDWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 5U)) + aOrbiterD);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 53U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aNonceWordO) + aPhaseDWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13156U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 11543U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 12516U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12285U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 12178U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 3973833383430652211U) + aNonceWordH;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 5760227042747169187U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aCross, 22U)) + RotL64(aCarry, 37U)) + 4923009065139227286U) + aNonceWordD;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 13U)) + 1477807307009107590U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 3U)) + 5707194514329007301U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 29U)) + 5340439728375269724U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 47U)) + 17080457898946572387U) + aNonceWordP;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 281559150259472813U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16160633048230910560U;
            aOrbiterF = RotL64((aOrbiterF * 16883442583309073785U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9003989610509592121U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10579322462808454333U;
            aOrbiterJ = RotL64((aOrbiterJ * 100832431598087235U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15059383289528723069U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10417647757852880956U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 1457919230286043137U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14484665027393813330U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12344463053485837974U;
            aOrbiterK = RotL64((aOrbiterK * 5762654194001525041U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5826453246659297805U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12547902286376986223U;
            aOrbiterB = RotL64((aOrbiterB * 2982850000322672789U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9637855144278126174U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2132744427444501938U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5911587798564836199U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9248933938130311231U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 13274297928717090383U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2901398809555237563U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 44U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aCross, 6U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 47U)) + aNonceWordC) + aPhaseDWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 58U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 37U)) + aOrbiterF) + aNonceWordO);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + aNonceWordN) + aPhaseDWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererH, 50U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 18769U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 16732U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 19961U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21425U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21121U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 18U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 785861751704720606U) + aPhaseDOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aScatter, 34U)) + 15968088718435606299U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 19U)) + 1393976526590347151U) + aNonceWordH;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 47U)) + 17240750947292745884U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 4921576136163183137U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 13U)) + 3334047873553153032U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 15086509978458408698U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 892391205397581998U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2965686403183767521U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 709160942482770225U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14632215393655706170U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15740589515342377322U;
            aOrbiterF = RotL64((aOrbiterF * 15677716942904794913U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11131164813943086445U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6988080581278900960U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6412189142344044255U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16021254613117657178U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6183615599897921154U;
            aOrbiterG = RotL64((aOrbiterG * 9976411093264211033U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12533992547026652747U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3104325358982904219U;
            aOrbiterH = RotL64((aOrbiterH * 14977348108778147265U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 3878525937957474644U) + aNonceWordC;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 2120435259884368445U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 15964718652193073177U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14928658302694194856U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9121310461310309348U;
            aOrbiterI = RotL64((aOrbiterI * 17304439784647477491U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterB, 4U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH) + aNonceWordL) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterI, 35U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24500U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 26748U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22497U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25297U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23435U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 12U)) + RotL64(aCarry, 53U)) + 12849591986267890852U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 37U)) + 8232614804696815750U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 43U)) + 12141567259210877281U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aWandererG + RotL64(aCross, 5U)) + 2928641981037885644U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 21U)) + 980733350554783938U) + aNonceWordP;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 2683985177993350746U) + aNonceWordE;
            aOrbiterE = ((((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 14532148403815527355U) + aPhaseDOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7736296629433884203U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10428437770166310549U;
            aOrbiterG = RotL64((aOrbiterG * 326634742742373401U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18327174144859461029U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6810436935194432002U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2715987179577753597U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12606153309690753435U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17123256945895150555U;
            aOrbiterB = RotL64((aOrbiterB * 13469111258504672565U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9057777759026189541U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16478485918911194442U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11054247078884894131U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 18064460487552100483U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11477276762421684083U;
            aOrbiterK = RotL64((aOrbiterK * 3886501230380184395U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 18318375441973295081U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13849305985380030986U;
            aOrbiterE = RotL64((aOrbiterE * 12962140243967824959U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10240409420338313641U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18360586077779529086U;
            aOrbiterC = RotL64((aOrbiterC * 18196875422391501927U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 40U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterC, 35U)) + aPhaseDWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 50U) + aOrbiterH) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterE, 4U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterG, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29538U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((aIndex + 30715U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 29963U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31314U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31758U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 19U)) + 13174219512651137892U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 2715455762789269341U) + aNonceWordF;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 1338018183235594313U) + aNonceWordE;
            aOrbiterG = ((((aWandererH + RotL64(aCross, 54U)) + RotL64(aCarry, 3U)) + 16566866551729552930U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 47U)) + 6901845297307236726U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 37U)) + 2476078302049201718U) + aPhaseDOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 5U)) + 15531109473927052260U) + aNonceWordA;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4087849380858572351U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5167830630098599644U;
            aOrbiterK = RotL64((aOrbiterK * 1982835131228146099U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7275995452428627217U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 14794340370010024117U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8779497557416568379U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8509217403041662849U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2321522025240806996U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 113568101672878697U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5676672952755594051U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2304681269233504384U;
            aOrbiterG = RotL64((aOrbiterG * 15731441084605554497U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8383399721062437300U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13181984036942227666U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1648761328771932069U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13602604532551684210U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12725687663616352843U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 4684699861686199753U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5831790822416009806U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4535048543735457407U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12076777878870257053U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + aNonceWordH) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterE, 34U)) + RotL64(aCarry, 11U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 41U)) + aOrbiterB) + aPhaseDWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 51U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 24U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Rugby_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCED0044C4041BEA3ULL + 0xCC6E855650BDAC1CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD09EB4AD94893BE1ULL + 0xD5EE338DF7ED3133ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF5B0371976371437ULL + 0xA102A3ED6C4CF178ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9F306483D8BC5765ULL + 0xAAB2DBA1E1E871C3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x951EF6541E3211D1ULL + 0xD790FBD2BB60AA6DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC525DCCD5CE1C87BULL + 0x9B85E1585AB074E0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8A3B546009722DADULL + 0x8FFD14FEBF9E0E2FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA06E45A2B6170DC7ULL + 0xCD05D3C443948B73ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD3EEE6E4561EB9AFULL + 0x840C51414F60728DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA2358185DBB43C91ULL + 0xF705F135E8345AD8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAA971DE32A86F8FDULL + 0xB24E70B8C6D7C184ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA4D053C0B687775DULL + 0xCFC63FC89E1CD0F3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF89F3D1414D956B3ULL + 0xB1784FD2443700E5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC89BCAD473D383FFULL + 0xDAFB83ADAFE5D078ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x882526FB7CC9A4F3ULL + 0x92EB1D8DF5A312BBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCF75518C54247187ULL + 0xCE8CE853D1944309ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 4053U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((aIndex + 2895U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4515U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2802U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 1572U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2879U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (aWandererK + RotL64(aScatter, 37U)) + 7075016829833562104U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 29U)) + 8783765886115517036U;
            aOrbiterI = (aWandererG + RotL64(aCross, 51U)) + 2996723892384565829U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 9494134707342189476U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 24U)) + RotL64(aCarry, 19U)) + 5052642981395679904U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 39U)) + 8766787055127962238U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 3U)) + 4467211954388738079U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 13U)) + 8030255604633658608U) + aNonceWordO;
            aOrbiterC = (aWandererC + RotL64(aIngress, 20U)) + 16962408063455702251U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 3768222186567699076U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 35U)) + 14930990410207899871U) + aNonceWordL;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14179761938395502502U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1879084742719898108U;
            aOrbiterI = RotL64((aOrbiterI * 16783034788172670121U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5535012408925981515U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12792553516710295939U;
            aOrbiterG = RotL64((aOrbiterG * 8577530993755159329U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8979253163346099252U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5559189896063990740U;
            aOrbiterB = RotL64((aOrbiterB * 8832485423727331621U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13937564337299044079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2393376759689394948U;
            aOrbiterE = RotL64((aOrbiterE * 2352815657830413941U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12647519563697356479U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10946871249960389549U;
            aOrbiterA = RotL64((aOrbiterA * 6272580371881237173U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13376798695582123147U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10958115913599631271U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18233981473003345217U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4283914227806672773U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 910842005516235816U;
            aOrbiterH = RotL64((aOrbiterH * 6722229871617873429U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1509644316619370324U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 165987596716078174U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 13600064054240185123U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12491315345199091186U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 5982431705686495125U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 2547243804779022665U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 231183123382412440U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2872632389683254396U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1972278820468847241U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15259314110008210315U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7075016829833562104U;
            aOrbiterD = RotL64((aOrbiterD * 8350093877370898869U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterI, 51U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aScatter, 42U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 6U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + aNonceWordK);
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterD, 27U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterK, 24U)) + aPhaseEWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8746U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneC[((aIndex + 6071U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8504U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9535U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 7431U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10246U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6012U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 43U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (aWandererF + RotL64(aCross, 50U)) + 11698283336767769359U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 27U)) + 13297826354831483872U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 35U)) + 15254999058287530795U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 41U)) + 17474166585085346567U;
            aOrbiterD = (aWandererK + RotL64(aCross, 37U)) + 15684783498452840289U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 24U)) + 5061229733465216486U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 5U)) + 15370981279168377944U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 53U)) + 17966672773619554092U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 14685092893994491068U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 12798804186209406389U;
            aOrbiterF = ((((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 2848444181474221574U) + aPhaseEOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8551142075919636146U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8833198159158950723U;
            aOrbiterK = RotL64((aOrbiterK * 7650289040764974737U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7351473160893666232U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14204899612487622222U;
            aOrbiterD = RotL64((aOrbiterD * 6317485031956448029U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7008985178526543258U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13576796403863120356U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13745839827679114077U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5769784656937900699U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14075925808204936705U;
            aOrbiterG = RotL64((aOrbiterG * 5844894088757604713U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17818667502858010896U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16016922065572683130U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 7525645833898085373U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1582458237855075977U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10830440354527138227U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 10499386926982228251U), 37U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 10653964151654643772U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11218475491129483859U;
            aOrbiterF = RotL64((aOrbiterF * 3338108067044357141U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9863649760189649255U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13790281439048354358U;
            aOrbiterB = RotL64((aOrbiterB * 4682098083538482849U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14846954923718136337U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 522207783972623813U;
            aOrbiterC = RotL64((aOrbiterC * 14299798934454852811U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 426829715716262697U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7482977730216354509U;
            aOrbiterE = RotL64((aOrbiterE * 6317437989422015173U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10736099808538972990U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11698283336767769359U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17230175904095995929U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 42U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + aPhaseEWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 36U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 30U)) + aOrbiterD) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterE, 35U)) + aNonceWordO) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterF, 3U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterB, 27U)) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterG) + aNonceWordP);
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterE, 54U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererI, 6U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12201U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneA[((aIndex + 12800U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 11920U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14070U)) & S_BLOCK1], 54U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11784U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (aWandererG + RotL64(aCross, 21U)) + 9914837590440975587U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 19U)) + 6706125076401958051U) + aNonceWordC;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 39U)) + 16570817772679258409U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 29U)) + 6843705658115186948U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 29U)) + 16099930446791572351U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 5420550009556030459U) + aNonceWordD;
            aOrbiterC = (aWandererE + RotL64(aIngress, 37U)) + 5729549069420177477U;
            aOrbiterA = (aWandererB + RotL64(aCross, 51U)) + 15590601126188675834U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 27U)) + 13044027390998620029U) + aNonceWordB;
            aOrbiterE = (aWandererK + RotL64(aScatter, 48U)) + 11068338135659636772U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 6584988841809544332U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8516813219883915404U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10647314042912492785U;
            aOrbiterI = RotL64((aOrbiterI * 15559481057047148785U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 201691689889605304U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15512161798401184003U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 11473219183982564709U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3883760518944464145U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13861805129175491145U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 17194438894492581181U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 12019138626550801486U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13030350224959652248U;
            aOrbiterC = RotL64((aOrbiterC * 11724200983306280107U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2643807255422544248U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4127143302485631794U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5441038881111578487U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14602951930809633069U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4555737199162278494U;
            aOrbiterG = RotL64((aOrbiterG * 12415825635220991865U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6343143902997169834U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10404783711336491985U;
            aOrbiterD = RotL64((aOrbiterD * 6235474458879439079U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7406959231434835393U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6684368109277850196U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8760360417572331159U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4835889355927954728U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7917682889852676712U;
            aOrbiterH = RotL64((aOrbiterH * 9045350756570117327U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10268055422944417055U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5563744562922937643U;
            aOrbiterE = RotL64((aOrbiterE * 12442484191329795173U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17244672945880141679U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 9914837590440975587U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 12269340309792850489U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 24U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 13U)) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterG, 41U));
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 50U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterG, 53U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 46U) + aOrbiterK) + RotL64(aOrbiterI, 39U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordA) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 48U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 21U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19537U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneA[((aIndex + 20065U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21483U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19205U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17651U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (aWandererJ + RotL64(aScatter, 13U)) + 5171470532667965920U;
            aOrbiterB = ((((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 750549462358682403U) + aPhaseEOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 3325689257577120525U;
            aOrbiterK = (aWandererH + RotL64(aCross, 57U)) + 18031575461559790826U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 13874739537012288677U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 39U)) + 4250029868785016865U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 6U)) + 8211158803112611161U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 41U)) + 1083939790236786027U) + aNonceWordD;
            aOrbiterI = (aWandererE + RotL64(aIngress, 23U)) + 3446525462376962464U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 29U)) + 6973817815000417325U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 34U)) + 15230876489676945543U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9359727659738755880U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8775170107816327654U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 6910680458261008653U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11958941755525038545U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16966819714283167348U;
            aOrbiterG = RotL64((aOrbiterG * 16363457661846050749U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14556087985619763243U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17915047508377045221U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6727635453185130109U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8578745677485367222U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7002181668717618866U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12329703532414955235U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3569939503066735457U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2956247934282522184U;
            aOrbiterH = RotL64((aOrbiterH * 9946650822131152531U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4285180013402474041U) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5976239869535619811U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 3458095419039067465U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2424524955161695463U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6849595426583763537U;
            aOrbiterA = RotL64((aOrbiterA * 12727902040238318101U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11414890686374886716U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5668287266836153445U;
            aOrbiterI = RotL64((aOrbiterI * 8011885266143066285U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9976985606260445887U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9223940029500676834U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 8508023992488499955U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4480967907876921958U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 5132766654502526597U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 321625389942019245U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12921555132452983464U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 5171470532667965920U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9710487797420618879U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 46U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + aNonceWordM) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterH, 37U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 43U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 44U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterD, 27U)) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterK, 34U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 40U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24701U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 26594U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 22596U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24711U)) & S_BLOCK1], 50U) ^ RotL64(aSnowLaneA[((aIndex + 23473U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 3U)) + (RotL64(aCross, 20U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 37U)) + 17454559218352016650U) + aNonceWordD;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 8005709669325164803U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 3U)) + 13393741948412816357U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 41U)) + 3665865624348875553U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 34U)) + 8334142570031883436U) + aNonceWordN;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 43U)) + 17226066128706139657U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 47U)) + 3319093033121522613U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 6657535603401588798U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 18U)) + RotL64(aCarry, 53U)) + 5469746182326331147U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 51U)) + 17846791786050221418U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 11U)) + 15939541003714896288U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12076763190461077406U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3594038213596405284U;
            aOrbiterJ = RotL64((aOrbiterJ * 10244002692575821495U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8301291631324464622U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8460406137668390582U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9117147929757711595U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 7612394867020871200U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 8525076134853103975U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5790440201072204659U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11929899088215090379U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7119509166360685726U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1662341427992528823U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5081078459225240607U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17149991983909906705U;
            aOrbiterG = RotL64((aOrbiterG * 950223374568067343U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8817303295675241994U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7962039282652745113U;
            aOrbiterB = RotL64((aOrbiterB * 12773588587795522121U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13596273086338032370U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8186297702278180956U;
            aOrbiterA = RotL64((aOrbiterA * 6226504769888753861U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1696277861691580263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17360461831507082959U;
            aOrbiterI = RotL64((aOrbiterI * 1651378456022210983U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1384868996572650981U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2039624849777183290U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 13148024378138271937U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14530407348595669913U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18023931565754525034U;
            aOrbiterE = RotL64((aOrbiterE * 18025122652259338105U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11245556671533878373U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17454559218352016650U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15665798947106818229U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 50U);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterC, 43U));
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 21U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 57U)) + aOrbiterH) + aNonceWordA);
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterC, 10U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterK, 5U));
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterG, 47U));
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 24U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32186U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 30201U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 31636U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31206U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32245U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 13481227414590594621U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 13U)) + 17425964381118918026U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 57U)) + 4792004356135956581U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 11U)) + 11926849936000639098U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 47U)) + 990697329347742142U) + aNonceWordH;
            aOrbiterK = (aWandererH + RotL64(aCross, 53U)) + 9307721505373076588U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 24U)) + RotL64(aCarry, 51U)) + 17605732738841908719U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 13110764518634187439U) + aNonceWordF;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 41U)) + 17970109897810645911U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 51U)) + 10273133817644703654U) + aPhaseEOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 44U)) + 11239046688920468137U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8355821483275763145U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15522151127786049345U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 4844278537850520413U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5381663179722418112U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9551368011768104906U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 14202470972121732997U), 27U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 16264476585232221270U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7721417776432288282U;
            aOrbiterD = RotL64((aOrbiterD * 10267770327791051869U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 339418090653475277U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3247926250495935511U;
            aOrbiterA = RotL64((aOrbiterA * 16824669543765729097U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3390560045236418590U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3894024951542543635U;
            aOrbiterF = RotL64((aOrbiterF * 10599637790900418767U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 3878539166189668154U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5617705593218220843U;
            aOrbiterI = RotL64((aOrbiterI * 82771190372750823U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12320861089148474544U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14943790251625519550U;
            aOrbiterB = RotL64((aOrbiterB * 13758322022902008313U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18119213517612562775U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1413193144229486646U;
            aOrbiterJ = RotL64((aOrbiterJ * 14562375280658115687U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 14810150213456844196U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8468712395797520201U;
            aOrbiterG = RotL64((aOrbiterG * 8167911669632436949U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13501570100536254566U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15409772061478100850U;
            aOrbiterH = RotL64((aOrbiterH * 955182899606655851U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8621805947309982779U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13481227414590594621U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9591362493722704105U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterB, 46U));
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + aNonceWordM);
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterC, 13U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 56U)) + aOrbiterG) + aNonceWordP) + aPhaseEWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 24U) + aOrbiterJ) + RotL64(aOrbiterF, 53U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + aNonceWordO);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 52U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Rugby_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBB1244AC1460EE39ULL + 0xE493EF0D1AB36C4FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x825BECEBCD96A7A7ULL + 0xADC173B8707AF35BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8C5E14D4188E4405ULL + 0xDD913C74300D9364ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x84F472585F21CF1DULL + 0x9F67264589C83616ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB93A083D34B1EFA3ULL + 0xA2B31A12CE1AF7FFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEA5CF5CDD54CD1F7ULL + 0xB22DBE8242061EA1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE446BA9DB19FC2FFULL + 0x879C4415D82F7E2EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE62F5CC900B56CBDULL + 0xB39436B50694CB0FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8C8EC612A810F153ULL + 0xB1670652C5F20F64ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x81CC8E870D366F65ULL + 0xC8085031F192A2AAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCADDB0EC6DE498FDULL + 0xD6793E491723F3E5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9381644DEF88BFF9ULL + 0x9D4424A56BAC130EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFAF724E81C776C67ULL + 0xEF9C4F212A880D42ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD5BDF915AEE104C1ULL + 0xE11E16D37074197FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9F5A4E4CA59283B3ULL + 0xD0519FED746DB79DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x828168936DF43031ULL + 0x8916211210614A2BULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 337U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 2004U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5118U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4758U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 67U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 481U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 5U)) + 6654158889644956636U) + aNonceWordB;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 48U)) + 9045779659363991870U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 3888897662136993491U) + aNonceWordG;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 6882016842864459345U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 29U)) + 15601891715956172291U) + aNonceWordD;
            aOrbiterE = (aWandererB + RotL64(aCross, 13U)) + 5176811598629335350U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 52U)) + RotL64(aCarry, 35U)) + 12519945150889074325U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 23U)) + 4552583214397603278U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 19U)) + 14225482701804864688U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5485298070606280363U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11237713257388094289U;
            aOrbiterC = RotL64((aOrbiterC * 11032429223099413011U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14340345895626142788U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16275167270553643347U;
            aOrbiterE = RotL64((aOrbiterE * 7308578867128951199U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14041860597556520250U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1436068974197066343U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3938460345031496843U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11483155566419547004U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4608508534724289325U;
            aOrbiterF = RotL64((aOrbiterF * 13461385011638899485U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2389196334288832895U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 4062682330273866602U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8787682133271101901U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5655656046585592034U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7977947821249746880U;
            aOrbiterB = RotL64((aOrbiterB * 10082104644185964787U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11653718118543974168U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5456429682072377614U;
            aOrbiterD = RotL64((aOrbiterD * 12504180638665296649U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12457179652004203574U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 445821754230182952U;
            aOrbiterK = RotL64((aOrbiterK * 16043092621697786393U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12429505513284703263U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12480745784412363537U;
            aOrbiterG = RotL64((aOrbiterG * 643617210585287593U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 56U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 4U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterA, 27U)) + aNonceWordC);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 24U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + aNonceWordI) + aPhaseFWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 53U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 36U) + RotL64(aOrbiterC, 12U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 48U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10888U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 8873U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10729U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((aIndex + 6172U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10467U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6866U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10259U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = ((aWandererC + RotL64(aScatter, 36U)) + 15316464782468770057U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 3U)) + 6642872057476351588U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 660732654689529192U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 41U)) + 7235418086884000655U) + aNonceWordA;
            aOrbiterC = (aWandererD + RotL64(aCross, 53U)) + 14784518476694580493U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 12U)) + RotL64(aCarry, 37U)) + 12222433977933449375U) + aNonceWordL;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 47U)) + 8573001207708329927U) + aPhaseFOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 16035256260815013172U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 57U)) + 15767726974121910203U) + aNonceWordJ;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17712217935322939971U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13488963456923357159U;
            aOrbiterA = RotL64((aOrbiterA * 16785285630840310405U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10222949131965611079U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1495561412321657209U;
            aOrbiterC = RotL64((aOrbiterC * 9706305581868526265U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16156530750584361434U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7773792489045606309U;
            aOrbiterH = RotL64((aOrbiterH * 10730624207715601393U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11544578291333360613U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3665587867634242865U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 4840528190844842595U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15248434984650998090U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15487979645426567581U;
            aOrbiterE = RotL64((aOrbiterE * 10868107809356766183U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6972347795052712690U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16074994810010431338U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1262655238856775853U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16851139687900415292U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14630026837021552812U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 9577900853521254603U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14236330619137368169U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17778707026111136216U;
            aOrbiterB = RotL64((aOrbiterB * 16239561893843454747U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9390961969105999083U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1174881758316573228U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6602061268277529311U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 42U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 23U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 29U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 19U)) + aOrbiterI) + aNonceWordK) + aPhaseFWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterK, 39U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 4U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterJ, 43U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererH, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11912U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 15509U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12599U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12977U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15045U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 6361545377408870615U) + aNonceWordA;
            aOrbiterI = (aWandererA + RotL64(aCross, 19U)) + 2967245486744774933U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 40U)) + 3836634268482850139U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 11U)) + 7691642115360086297U) + aNonceWordO;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 47U)) + 16479280384178279281U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 3U)) + 2901468732552539249U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 28U)) + RotL64(aCarry, 21U)) + 2600353867755647475U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 5666596904781510956U;
            aOrbiterF = (aWandererK + RotL64(aCross, 53U)) + 16108791609267427553U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8389926875737312112U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 1689501721163024426U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 6517194895779049139U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11721701506949917719U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3963842745030140473U;
            aOrbiterK = RotL64((aOrbiterK * 6692473494944919373U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8510538243472109368U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 18281865214102080387U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1351546966368884609U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2259725140963665123U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11652011949557979650U;
            aOrbiterB = RotL64((aOrbiterB * 11260100762113295037U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1116085424226174473U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4725260319270802912U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 4697109059565450269U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7348945429843437036U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1249234309180653260U;
            aOrbiterA = RotL64((aOrbiterA * 3136745255820405881U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12463505532573389603U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2304125977906510386U;
            aOrbiterC = RotL64((aOrbiterC * 9960816714791454421U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2178037443783425551U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11712110130079307683U;
            aOrbiterI = RotL64((aOrbiterI * 9797864956200779505U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10703510612147312252U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 18155460326242413483U;
            aOrbiterF = RotL64((aOrbiterF * 6903953708987478723U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 24U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterG, 47U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterI, 18U)) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 37U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterF, 23U)) + aNonceWordG) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterC, 43U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 44U) + RotL64(aOrbiterI, 6U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21692U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 19470U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19241U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18294U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17060U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 24U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 6163290588946759209U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 27U)) + 7342672468560105447U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 60U)) + 11574563167017282321U;
            aOrbiterC = ((((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 2254820206194758964U) + aPhaseFOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererK + RotL64(aIngress, 13U)) + 1469783447473099498U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 51U)) + 14174828900676165088U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 19U)) + 16277954291890598132U) + aPhaseFOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 14845750668693136766U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 46U)) + 150099699692047766U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 1200784917165131703U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9469982764806754302U;
            aOrbiterE = RotL64((aOrbiterE * 17851969334511301943U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10956702761701710182U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7915506894975487807U;
            aOrbiterK = RotL64((aOrbiterK * 8874108311712727983U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 17335794183733623213U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 557028996286989506U;
            aOrbiterH = RotL64((aOrbiterH * 3993359298602424281U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1597385667771002414U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4376417959915162639U;
            aOrbiterC = RotL64((aOrbiterC * 4626236858205178149U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 549770198518993876U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 756554555648070919U;
            aOrbiterI = RotL64((aOrbiterI * 16272320259614325355U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7298557532533152193U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3336802611342112013U;
            aOrbiterD = RotL64((aOrbiterD * 14679103452120080499U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2314938232094714365U) + aNonceWordI;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 12215066333571149153U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 10747052773052630601U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7762752719356805046U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6519429915769040078U;
            aOrbiterG = RotL64((aOrbiterG * 15548676502167938513U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7556691736109752918U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13731245903412646404U;
            aOrbiterF = RotL64((aOrbiterF * 15581965016668635409U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterG, 10U));
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 35U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + aNonceWordK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + aNonceWordM) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 18U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 46U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22368U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((aIndex + 23972U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 24495U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26450U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 25692U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 20U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 9751314027302668907U) + aNonceWordJ;
            aOrbiterE = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 12175450995523107056U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 42U)) + 17519694958730119552U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 9093525527925682263U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 13U)) + 3713831321786810138U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 47U)) + 10108355209191835040U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 52U)) + 12956307447311314768U) + aNonceWordM;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 35U)) + 1904298513945877359U) + aNonceWordG;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 29U)) + 4658049993308574460U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9826333658248851902U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 12058666914724365134U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 964233873188373939U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2516574707110528099U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13335308331049750235U;
            aOrbiterF = RotL64((aOrbiterF * 5880227828760598587U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8230749255538495304U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16536559486797811486U;
            aOrbiterH = RotL64((aOrbiterH * 7097036838156464969U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12387639130570188998U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8459259798142872020U;
            aOrbiterD = RotL64((aOrbiterD * 8001346480955847013U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16083784052002800300U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1957284290736468379U;
            aOrbiterC = RotL64((aOrbiterC * 5046501301740813065U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 7349538179311335863U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16395170077006105258U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 4230485452156662763U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3317652065873784068U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 5517155804799120700U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9789270651974719183U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5568525912112200094U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9334250662962319598U;
            aOrbiterI = RotL64((aOrbiterI * 5034887614541768961U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5641394627075994165U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13524971148931512745U;
            aOrbiterE = RotL64((aOrbiterE * 3699457147759854357U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 36U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterG, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 3U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 10U)) + aOrbiterI) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterE, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterD, 43U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterD, 60U)) + aNonceWordK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererF, 50U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31138U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 30571U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 28888U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32019U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30528U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 9914837590440975587U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 48U)) + 6706125076401958051U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 16570817772679258409U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 21U)) + 6843705658115186948U) + aNonceWordH;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 57U)) + 16099930446791572351U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 11U)) + 5420550009556030459U) + aNonceWordO;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 37U)) + 5729549069420177477U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 28U)) + RotL64(aCarry, 47U)) + 15590601126188675834U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 5U)) + 13044027390998620029U) + aNonceWordE;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11068338135659636772U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6584988841809544332U;
            aOrbiterJ = RotL64((aOrbiterJ * 1683336180438945439U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8516813219883915404U) + aNonceWordI;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 10647314042912492785U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 15559481057047148785U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 201691689889605304U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15512161798401184003U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11473219183982564709U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3883760518944464145U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13861805129175491145U;
            aOrbiterF = RotL64((aOrbiterF * 17194438894492581181U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12019138626550801486U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13030350224959652248U;
            aOrbiterK = RotL64((aOrbiterK * 11724200983306280107U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2643807255422544248U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4127143302485631794U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5441038881111578487U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14602951930809633069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4555737199162278494U;
            aOrbiterB = RotL64((aOrbiterB * 12415825635220991865U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6343143902997169834U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10404783711336491985U;
            aOrbiterG = RotL64((aOrbiterG * 6235474458879439079U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7406959231434835393U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6684368109277850196U;
            aOrbiterI = RotL64((aOrbiterI * 8760360417572331159U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 44U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 23U)) + aOrbiterI) + aNonceWordA);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterK, 60U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aScatter, 48U) + aOrbiterC) + RotL64(aOrbiterH, 29U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterF, 37U)) + aOrbiterB) + aNonceWordG) + aPhaseFWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterK, 46U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Rugby_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCCA249CC92D97FD5ULL + 0x95EF903E41F11D68ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDE315F74AE3DB917ULL + 0xCB8A4DF743157808ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB0C6040CC3F4B381ULL + 0x9887EAFDE4772BF5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8A7B51AF18B59FD5ULL + 0xF9B23DDAB998E96AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCAAC9705B9E0A90DULL + 0xD1CBF9220E78EEA4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA534A7314C1250EFULL + 0xA8F2DFE0EDAF7FF6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFB33AF5792B0DD03ULL + 0xE23140C7158A51BDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB88013488B868785ULL + 0xFA7856B22E2B3D4DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC47D3719F2C5FD2FULL + 0x9726FC0EEE19161FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDBA78B9C61199DA9ULL + 0xEB8C93C98EF07C04ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBD3CB74BA4A93523ULL + 0xD15A774630005D0AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x872195E8DBFD05A3ULL + 0x86060DB5888AFAD7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE35B196C5653ECDFULL + 0xDAC1602063E7194BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEFACB1F1F105323BULL + 0xC062274CC98D8617ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB2DBD81053D47D93ULL + 0x85E94D87170D927AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9D48D7434FC4E7C5ULL + 0xDF9287E28E32B009ULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 2531U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneB[((aIndex + 1536U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4853U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3668U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 1072U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1501U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 21U)) + (RotL64(aIngress, 38U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 13U)) + 15188686795415908074U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 41U)) + 17310049041983079779U) + aNonceWordH;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 8246925977992441471U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 27U)) + 8644260919918112781U) + aNonceWordK;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 6U)) + 13401663736874819483U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 7940358935238314973U;
            aOrbiterG = ((((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 13278990328548007839U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11346868298353840706U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2374077904806833579U;
            aOrbiterD = RotL64((aOrbiterD * 1765686942154321425U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6978903378645019166U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11951633297870965212U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12778236598654492185U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17398460995357409673U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1215437945597836770U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9322970054123481621U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1878751468043972239U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5343002808239712390U;
            aOrbiterJ = RotL64((aOrbiterJ * 11878640995447558811U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9884918450053276861U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15894599082080422550U;
            aOrbiterK = RotL64((aOrbiterK * 8359936745539546131U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13917339232771145459U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 18101134009493720683U;
            aOrbiterE = RotL64((aOrbiterE * 15835859435306756387U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3830086372356903769U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15894394599564584010U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 9513921913446609263U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterK, 11U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 5U)) + aOrbiterD);
            aWandererI = aWandererI + (((((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 48U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordI) + aPhaseHWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterC, 41U)) + aNonceWordM) + aPhaseHWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterD, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10735U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 6783U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10638U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6086U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6600U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 5520U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6579U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 52U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 47U)) + 16183871922837164759U) + aPhaseHOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 34U)) + RotL64(aCarry, 5U)) + 7002058258090219055U;
            aOrbiterH = (aWandererG + RotL64(aCross, 27U)) + 5650868611888303705U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 11899839660943876690U) + aNonceWordC;
            aOrbiterD = (((aWandererD + RotL64(aCross, 5U)) + 15349649504488111111U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 19U)) + 14060149569086744970U) + aNonceWordA;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 12920917574225030112U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2831994965175330135U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 18312543585028439192U;
            aOrbiterH = RotL64((aOrbiterH * 11618182708195744321U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11657562205118394239U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10850792819281246052U;
            aOrbiterB = RotL64((aOrbiterB * 10663100544207879337U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17810371216216125323U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7963413941144223128U;
            aOrbiterE = RotL64((aOrbiterE * 534217972450595401U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5498715358793875584U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9256727548911651373U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 10498848323914000989U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 17246360111302191699U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 18309978718113983369U;
            aOrbiterJ = RotL64((aOrbiterJ * 18267472694666221077U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3100998994319502921U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8129301860291235970U;
            aOrbiterK = RotL64((aOrbiterK * 17847033539279176187U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1889641029473279114U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16538494307002917945U;
            aOrbiterD = RotL64((aOrbiterD * 8081488217920885783U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 4U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterD, 58U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 35U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14982U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 12418U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14969U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13242U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneC[((aIndex + 14874U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aPrevious, 47U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (aWandererB + RotL64(aCross, 47U)) + 6068543441070417854U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 40U)) + 2995980468193441856U) + aNonceWordI;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 18020277482171594003U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 11U)) + 4293807434721230702U) + aNonceWordA;
            aOrbiterA = ((((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 7980599111583893156U) + aPhaseHOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = ((((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 8593141111851052016U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 53U)) + 5903487523900084325U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15112035513447930209U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9854037263057006439U;
            aOrbiterG = RotL64((aOrbiterG * 396276470208637283U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16759760289688823193U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12622628933030601390U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2151912984825538321U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 1264668857268123425U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16302812053619101593U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 18291400055836111547U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16087995784896123610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7970269262800468363U;
            aOrbiterA = RotL64((aOrbiterA * 14924752223305807461U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5331477046030959632U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16534913204255550893U;
            aOrbiterD = RotL64((aOrbiterD * 1013433634373673565U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11042821902537871209U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8069677512345031660U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13622218526054132397U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5737130058129936372U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1076627182956662997U;
            aOrbiterC = RotL64((aOrbiterC * 14342191224014199929U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterC, 21U)) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aCross, 58U) + RotL64(aOrbiterK, 10U)) + aOrbiterG) + aNonceWordP);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17980U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 18904U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16425U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19069U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneD[((aIndex + 20086U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aIngress, 13U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererK + RotL64(aCross, 41U)) + 3550722402315312207U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 16724184551669522754U;
            aOrbiterI = ((((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 981751330116773021U) + aPhaseHOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererA + RotL64(aScatter, 5U)) + 7891159229704944868U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 27U)) + 13618396711464799841U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 34U)) + RotL64(aCarry, 57U)) + 5969291018449003648U) + aPhaseHOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 13U)) + 14595540413313640042U) + aNonceWordG;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3287990436916111762U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 12534369400200483704U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 2345945228434740707U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2277312067930392274U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10026320559261334353U;
            aOrbiterK = RotL64((aOrbiterK * 11020464940995912637U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11258082063135659551U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1445958517675746990U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10062265337488757971U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1011298251290970844U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6487834862470043744U;
            aOrbiterD = RotL64((aOrbiterD * 15477913837027179675U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9966279022928268335U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10285993486057704393U;
            aOrbiterA = RotL64((aOrbiterA * 15965714363201157535U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16005362468813966136U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 223843444699390781U;
            aOrbiterE = RotL64((aOrbiterE * 665392038954573081U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18178876294968532775U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12490136112181806806U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16380841616662993709U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterA, 18U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterI, 27U));
            aWandererE = aWandererE + ((RotL64(aScatter, 34U) + RotL64(aOrbiterG, 39U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22481U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((aIndex + 27141U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 24534U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26530U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23662U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 4U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 16200278595895089008U) + aNonceWordL;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 54U)) + 1029614154810465897U) + aNonceWordH;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 7129562468705441295U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 3U)) + 14388903902433951274U) + aNonceWordJ;
            aOrbiterH = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 1013568949315967455U) + aPhaseHOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 43U)) + 3128823373497815651U) + aNonceWordE;
            aOrbiterB = (aWandererD + RotL64(aIngress, 35U)) + 14525694606889470589U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14443983602196782887U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12244220415328641190U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15052949098014803181U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10477159225338766614U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2842870123078131566U;
            aOrbiterH = RotL64((aOrbiterH * 11522265477555954071U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8621138818955849917U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5038396344400303181U;
            aOrbiterG = RotL64((aOrbiterG * 14636756322207385447U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2768613802894372496U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2027754864051410015U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2461322540050569287U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 2848088309172056399U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15017458513904884651U;
            aOrbiterB = RotL64((aOrbiterB * 9926904679902843055U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9079797279596336139U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15424866642305110811U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 12912331089970158845U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13751764050290602740U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7694557131324740282U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14980807690491467023U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterH, 29U));
            aWandererG = aWandererG + (((((RotL64(aPrevious, 44U) + aOrbiterB) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 53U)) + aNonceWordC) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 3U)) + aNonceWordO);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 38U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30177U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 31610U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 32555U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29352U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneB[((aIndex + 30191U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 8506388683755208267U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 2179323259055019735U) + aPhaseHOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aCross, 41U)) + 3345902531140983016U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 17456139311481306584U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 34U)) + 14587864088462311164U) + aNonceWordG;
            aOrbiterD = ((aWandererE + RotL64(aCross, 21U)) + 13178947246650647057U) + aNonceWordI;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 5U)) + 12866578138946916962U) + aPhaseHOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13098524333655118173U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15451329483787541982U;
            aOrbiterG = RotL64((aOrbiterG * 13580376920467431451U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9494299579678389385U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 15581954810375490643U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 13670002280188424825U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4487042505730624892U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2774455928791636186U;
            aOrbiterE = RotL64((aOrbiterE * 15847933919136777451U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12435319582397755819U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10077180055177766823U;
            aOrbiterJ = RotL64((aOrbiterJ * 3924363471701748703U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10391963896910956455U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6149237416725301794U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10115917698918612823U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15673402771629639978U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14729117178956592426U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9070464269215820531U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14492001279368870240U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6278248084483259952U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16731228350971263873U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 30U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 58U)) + aOrbiterG) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + aPhaseHWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 29U)) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + aPhaseHWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 54U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
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

void TwistExpander_Rugby_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 753U)) & W_KEY1], 42U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1075U)) & W_KEY1], 56U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 585U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 13U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 5568146815535263910U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 52U)) + 7736084960873834666U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 1336413621817562093U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 19U)) + 5218462026934984692U) + aPhaseAOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 35U)) + 7048890985969555935U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 47U)) + 13415955213864702118U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 40U)) + 5657023257021528548U;
            aOrbiterD = (aWandererF + RotL64(aCross, 5U)) + 14338310943137497116U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 12305161641833950473U) + aPhaseAOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 14514226578370459131U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12692904083266024340U;
            aOrbiterA = RotL64((aOrbiterA * 14800805065279908839U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11012959130001327964U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7106471380403489078U;
            aOrbiterI = RotL64((aOrbiterI * 515626559384817223U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3718101961355280891U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13364192077222322664U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1411328915372590283U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6720867800318913440U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14497243926965866546U;
            aOrbiterE = RotL64((aOrbiterE * 13595058589060114653U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 5789056168233262435U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14438482587495779937U;
            aOrbiterG = RotL64((aOrbiterG * 10593535547917767263U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 313917798940179945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15241845511889502917U;
            aOrbiterJ = RotL64((aOrbiterJ * 16483477103771326107U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3591957424821693032U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1559050939014453558U;
            aOrbiterD = RotL64((aOrbiterD * 17933346117866604725U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15340590914441451383U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5538037287390050110U;
            aOrbiterH = RotL64((aOrbiterH * 4082576643144951473U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4151270491894969214U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 263593701314144898U;
            aOrbiterC = RotL64((aOrbiterC * 10372046955804512457U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 6U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 34U) + aOrbiterI) + RotL64(aOrbiterA, 30U));
            aWandererI = aWandererI + ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 21U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 37U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 58U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterD, 43U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3253U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3241U)) & W_KEY1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4169U)) & W_KEY1], 20U) ^ RotL64(mSource[((aIndex + 4035U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererC + RotL64(aCross, 48U)) + 13053031069776604052U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 35U)) + 1331396630251085122U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 3U)) + 15879286043343942393U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 23U)) + 13590365633321406830U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 14569235423040242618U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 44U)) + 11397370636618371560U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 3455933494593971847U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 1307153376443784593U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 19U)) + 10688618762584786871U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17746248451153600096U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8512568600755410158U;
            aOrbiterA = RotL64((aOrbiterA * 16648320170768234063U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8950230550112591092U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17790968369472845496U;
            aOrbiterK = RotL64((aOrbiterK * 5104988920132008913U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12583323865381967534U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11243927099685293887U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12867003042486433971U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9690268715525781389U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7466066217365074653U;
            aOrbiterH = RotL64((aOrbiterH * 17565696765505320889U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3673528673209875118U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14079103852360952255U;
            aOrbiterI = RotL64((aOrbiterI * 17449228863409999629U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6747836856132250630U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5027692924422297153U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2492421273167124437U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11370341866003395776U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14013204893442579282U;
            aOrbiterD = RotL64((aOrbiterD * 6602239957997240785U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3436953430697936790U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6399073534839993637U;
            aOrbiterB = RotL64((aOrbiterB * 14186050072610021241U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7054057507823631422U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5752085719673338095U;
            aOrbiterE = RotL64((aOrbiterE * 13252660162476029593U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 18U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 36U) + RotL64(aOrbiterK, 57U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterK, 6U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterI, 19U)) + aPhaseAWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterE, 43U)) + aPhaseAWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterK, 29U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 6U) + aOrbiterB) + RotL64(aOrbiterH, 34U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 8091U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 6326U)) & W_KEY1], 26U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6531U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5471U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6443U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aIngress, 39U)) + 964165145848253292U;
            aOrbiterA = (aWandererB + RotL64(aCross, 6U)) + 10645976767204934746U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 19U)) + 8241612229349212650U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 13U)) + 4159196033256913347U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 7194795864620233507U) + aPhaseAOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 7638928444536778384U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 48U)) + RotL64(aCarry, 29U)) + 11819105916503968109U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 35U)) + 18052213302858186237U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aIngress, 23U)) + 8663575313970041570U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16644136720439299786U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16930316530442679864U;
            aOrbiterC = RotL64((aOrbiterC * 2650922074098320859U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16251107616988250593U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7171986193609401665U;
            aOrbiterF = RotL64((aOrbiterF * 3543709971414550087U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17885046834432626644U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7757069274715713557U;
            aOrbiterB = RotL64((aOrbiterB * 15766885299397923879U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2212805322061155615U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6368539134638838822U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13383744883433594259U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5264326094252925613U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6126345334815012938U;
            aOrbiterA = RotL64((aOrbiterA * 17180934809764905307U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13826731214018407061U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6621261811613643620U;
            aOrbiterD = RotL64((aOrbiterD * 2823596473596114171U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5964406317285863781U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2167324450276308078U;
            aOrbiterJ = RotL64((aOrbiterJ * 1098346374733634905U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16740710162977859724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8236083581048717923U;
            aOrbiterH = RotL64((aOrbiterH * 4364887787000704039U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13967473987446124012U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5136051802217149813U;
            aOrbiterG = RotL64((aOrbiterG * 13997246005108872883U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 18U) + RotL64(aOrbiterB, 58U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 21U));
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 51U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 11U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterI, 26U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 8495U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 10795U)) & W_KEY1], 4U));
            aIngress ^= (RotL64(mSource[((aIndex + 10208U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9830U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8226U)) & W_KEY1], 27U) ^ RotL64(aFireLaneB[((aIndex + 9095U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 26U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererB + RotL64(aScatter, 52U)) + 3917730204724097072U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 1874642340716212824U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 6900165757434854160U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 12750946097023807161U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 4U)) + 6563216048479513594U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 21U)) + 14960240191349450795U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 13U)) + 16306180275951788289U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 29U)) + 6502066618271045547U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 43U)) + 6219852857850888738U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2272931312452845850U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3028929882263199463U;
            aOrbiterK = RotL64((aOrbiterK * 11005324285856805069U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6067393030073568112U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10094809900437037258U;
            aOrbiterC = RotL64((aOrbiterC * 18095564940730322769U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5962414178157074575U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15755563045799129417U;
            aOrbiterI = RotL64((aOrbiterI * 3692603590609922031U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6321455513889880590U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1197435601998121700U;
            aOrbiterE = RotL64((aOrbiterE * 17693996266260557625U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12496949381666299968U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6357070235648527030U;
            aOrbiterJ = RotL64((aOrbiterJ * 2931486644220862433U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8423760160877540210U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8090246492554850768U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2949407491181921633U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11436635942985063755U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17086363141014359856U;
            aOrbiterG = RotL64((aOrbiterG * 10504127577318206801U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10734017887545474935U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 375515325165740779U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9980486695448151709U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5217148491945389821U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14696058217023530058U;
            aOrbiterF = RotL64((aOrbiterF * 11026674782236654799U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 28U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 60U)) + aOrbiterC) + aPhaseBWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterK, 51U));
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 41U)) + aPhaseBWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterA, 18U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterE, 43U));
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterB, 37U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 20U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11350U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 13551U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11057U)) & W_KEY1], 6U) ^ RotL64(mSource[((aIndex + 13521U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11014U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12396U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12943U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 52U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 6342299552323486695U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 12692748514781367538U;
            aOrbiterB = (aWandererK + RotL64(aCross, 47U)) + 8202639945493229155U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 30U)) + RotL64(aCarry, 27U)) + 4439975701793231639U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 13U)) + 16774235182859553759U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 35U)) + 8764155413335405667U;
            aOrbiterF = (aWandererB + RotL64(aCross, 43U)) + 7167848811974967685U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 6U)) + 16768278912125334220U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 23U)) + 9090838954826296201U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7644075729758006298U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17326182797908071215U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2408330168749256075U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16158809721888137555U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8029938783858263694U;
            aOrbiterE = RotL64((aOrbiterE * 12628072435324195483U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 8716553521415553404U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7012599977009208840U;
            aOrbiterF = RotL64((aOrbiterF * 8775355876188948851U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 13250558696578541499U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13705957059101025396U;
            aOrbiterD = RotL64((aOrbiterD * 16889495686487056367U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2796775206291902461U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13741676263512390669U;
            aOrbiterK = RotL64((aOrbiterK * 10455782033465595947U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1691908360612389252U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4114939415206031540U;
            aOrbiterC = RotL64((aOrbiterC * 2797401802892718297U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2374911514440738727U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12377616933668803091U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2505164835116651215U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 681094033415259645U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13841322124900463362U;
            aOrbiterJ = RotL64((aOrbiterJ * 4210414203856902329U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18082983557580381338U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15731122225678626778U;
            aOrbiterA = RotL64((aOrbiterA * 7785999919955613789U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 56U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 56U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 51U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterG, 3U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 60U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterA, 43U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 14279U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneC[((aIndex + 15953U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14467U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15629U)) & W_KEY1], 58U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15914U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15958U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 15783U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 53U)) ^ (RotL64(aCarry, 22U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 40U)) + RotL64(aCarry, 57U)) + 11480359716598965890U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 15431182525482873419U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 11360504974812776707U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 3U)) + 9292576416573382769U;
            aOrbiterB = (aWandererB + RotL64(aCross, 51U)) + 1549257414531028975U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 57U)) + 5347769463033129317U) + aPhaseBOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aPrevious, 10U)) + 17019199177478377234U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 29U)) + 16558106007323125094U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 47U)) + 3976182233825939422U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2889047161195954395U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2241831345026962605U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5757458560979927857U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12850802412140579294U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13541744735436450160U;
            aOrbiterB = RotL64((aOrbiterB * 906089290000537439U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2085863085516538212U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2969034221711544086U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7768528124408400403U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6482666944512391472U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16969153556875844613U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9483462388353216219U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5161314086757363678U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7150282484670673211U;
            aOrbiterI = RotL64((aOrbiterI * 8522427002337918663U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5465304381272305847U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2344610773390354017U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17010258514288089191U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8335906578006588582U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13668796013474193793U;
            aOrbiterH = RotL64((aOrbiterH * 8228000547141147777U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9663362594301419686U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3683773739120343413U;
            aOrbiterD = RotL64((aOrbiterD * 8319320803406104749U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2538583190438044942U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4454069062219406996U;
            aOrbiterF = RotL64((aOrbiterF * 16329554225309389599U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 12U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 53U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 29U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 12U) + RotL64(aOrbiterI, 35U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterA, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18780U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadA[((aIndex + 18308U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(mSource[((aIndex + 19096U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18160U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18511U)) & W_KEY1], 30U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16931U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 18295U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 19U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aIngress, 38U)) + RotL64(aCarry, 11U)) + 13499155707765393469U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 5U)) + 3740324981823726185U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 19U)) + 5470765363949735652U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 43U)) + 3446436171274452326U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 53U)) + 1778929412631211933U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 14666308799855220954U;
            aOrbiterH = (aWandererD + RotL64(aCross, 57U)) + 4548410236791175055U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 12U)) + RotL64(aCarry, 57U)) + 5829739767694190372U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 23U)) + 14319231414903675748U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1513851750246111405U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1685620217748986019U;
            aOrbiterI = RotL64((aOrbiterI * 9286548037413609445U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16284162182006054402U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6271539598462003309U;
            aOrbiterJ = RotL64((aOrbiterJ * 13923286694131331137U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12669312437565969473U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11894755313393001665U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12556759675372354075U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6315983824634946566U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17106616474222892782U;
            aOrbiterF = RotL64((aOrbiterF * 167205520766791073U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13350266700180455548U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4608846311203767162U;
            aOrbiterE = RotL64((aOrbiterE * 2504857468837437365U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14195866746143604365U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7917977448256795054U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5927771378657284557U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10707336923305131629U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 17122696159336995392U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13953518568670659191U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5182322763573586116U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6503754948502556246U;
            aOrbiterC = RotL64((aOrbiterC * 14749002194140663519U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14907832047832987341U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6258064448676621346U;
            aOrbiterH = RotL64((aOrbiterH * 4407960312705621487U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 58U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 39U)) + aPhaseCWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 46U) + aOrbiterC) + RotL64(aOrbiterF, 54U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterA, 35U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 12U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 39U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 21105U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 21515U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19152U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21605U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19641U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20343U)) & W_KEY1], 11U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19267U)) & S_BLOCK1], 20U) ^ RotL64(aFireLaneB[((aIndex + 21003U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 27U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 48U)) + 6733949564325516029U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 7304098437143918796U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aCross, 19U)) + 3923949518391777800U) + aPhaseCOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 23U)) + 14243591003388927124U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 60U)) + 18329498724605410406U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 13118172167747037249U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 53U)) + 5272025143849174212U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 16075917179214318424U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 39U)) + 15263590648674658399U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13730046728289525921U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7703141464499623408U;
            aOrbiterI = RotL64((aOrbiterI * 5886009900621521987U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1382279753822135359U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2973369221699098292U;
            aOrbiterF = RotL64((aOrbiterF * 7440242040663550631U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11578274119583013219U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3419411247737896674U;
            aOrbiterG = RotL64((aOrbiterG * 17814942652262802991U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2582783513078999303U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 3959762790273529677U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 383974377372162751U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 465795011576934604U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17880826624185821135U;
            aOrbiterC = RotL64((aOrbiterC * 4445949147592860913U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10819659185349413173U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17298208553586835030U;
            aOrbiterK = RotL64((aOrbiterK * 1965860510614222093U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12585880006661489402U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16650193903267408586U;
            aOrbiterA = RotL64((aOrbiterA * 5781132589396936615U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 885882046325991589U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 869560078374809974U;
            aOrbiterE = RotL64((aOrbiterE * 13440973563438747181U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11871305571797951851U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12137095015607196226U;
            aOrbiterH = RotL64((aOrbiterH * 7618152256560808581U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 40U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 58U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterG, 53U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterF, 12U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterI) + aPhaseCWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterK, 47U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterG, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22264U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 22009U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22733U)) & W_KEY1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23297U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23114U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22302U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24022U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((aIndex + 23636U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 23U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 42U)) + 5173905450211892891U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 3U)) + 3555542451908039957U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 11559884700283861559U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 1352524329968738673U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 58U)) + 8914206450420616349U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 19U)) + 2251523378498463946U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 9541575923299247038U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 51U)) + 1239854507907214595U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aIngress, 29U)) + 17698101462598498934U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12305566971683256060U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13804545036303215569U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10359543704152744971U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10239749097704329264U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4212214906286320308U;
            aOrbiterD = RotL64((aOrbiterD * 3661436621615751071U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12192418916967430783U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4475514289326450361U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17497164630368757887U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17376102613298827459U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18129393209955439341U;
            aOrbiterK = RotL64((aOrbiterK * 6404089025014118979U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 4014763724300253568U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17325007199676828814U;
            aOrbiterI = RotL64((aOrbiterI * 1420888274815627083U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15480474849292388685U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14357924730184375449U;
            aOrbiterA = RotL64((aOrbiterA * 16723492259068034209U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4335731868597970070U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8296023680394303015U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14027415401430120543U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2807312426993262800U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15510369660839648501U;
            aOrbiterG = RotL64((aOrbiterG * 18207954408298333959U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12597844696606519907U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7231012798553551535U;
            aOrbiterB = RotL64((aOrbiterB * 2841306785994479299U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 20U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 28U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 10U) + aOrbiterB) + RotL64(aOrbiterK, 37U));
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 53U));
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterG, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 42U)) + aPhaseCWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 5U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26171U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 25732U)) & W_KEY1], 10U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26426U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 26650U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26651U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24735U)) & S_BLOCK1], 60U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25933U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24626U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 58U)) + 1142447269198373880U) + aPhaseDOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 10581460640040336191U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 51U)) + 14703062773878202900U) + aPhaseDOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 15737525756286914746U;
            aOrbiterA = (aWandererD + RotL64(aCross, 29U)) + 16178774478273186999U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 39U)) + 2514897053906809160U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 35U)) + 13702496607592508464U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 46U)) + 18030885275418337965U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 5241783876161655984U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2807052676283587925U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8022804576763271327U;
            aOrbiterI = RotL64((aOrbiterI * 11727096043219370577U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15597099852232205860U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1538435607932096400U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7900752511710516981U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11147868774413615365U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9325213746830411568U;
            aOrbiterC = RotL64((aOrbiterC * 561819005818948769U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13792300423550555634U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3134856508983945719U;
            aOrbiterB = RotL64((aOrbiterB * 4271845067763664863U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8654966018053784882U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8937113935476779267U;
            aOrbiterF = RotL64((aOrbiterF * 7386875687217705855U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4135676350355234788U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11407912615743682678U;
            aOrbiterD = RotL64((aOrbiterD * 2773506587480714695U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10966950663872392059U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6686634993700944582U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2509459942163678241U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14154407529749257990U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18054640398549782388U;
            aOrbiterJ = RotL64((aOrbiterJ * 7830759861389060149U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14623473030642960240U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1857945571104460086U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18039903315045620079U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterC) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 18U) + aOrbiterA) + RotL64(aOrbiterJ, 39U));
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 10U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 14U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 34U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + aPhaseDWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 20U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27854U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 28254U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29353U)) & W_KEY1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29702U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28668U)) & W_KEY1], 36U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27898U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27432U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 29537U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 52U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererG + RotL64(aScatter, 3U)) + 9023059520606551446U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 58U)) + 662441755115638133U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 16957253361196144712U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 7840955025765308605U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 39U)) + 346855809270395799U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 16099139781586668343U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 19U)) + 3706457327118322098U;
            aOrbiterI = (aWandererA + RotL64(aCross, 35U)) + 12166825885547622870U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 50U)) + 7792658665720344200U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7128477606152986326U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11116533962780290084U;
            aOrbiterK = RotL64((aOrbiterK * 11993485572912492297U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10443889548568288532U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4402387036946561017U;
            aOrbiterJ = RotL64((aOrbiterJ * 9032964741841833277U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13002706161178447654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13929727277530310708U;
            aOrbiterB = RotL64((aOrbiterB * 7005639090871200285U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10949073760696935106U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15405923432006783533U;
            aOrbiterH = RotL64((aOrbiterH * 17989565878445202495U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18096057968822208905U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3032155040484574973U;
            aOrbiterG = RotL64((aOrbiterG * 448597307502544605U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17462076466907467134U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15471015427013701406U;
            aOrbiterF = RotL64((aOrbiterF * 6113474000571976139U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3549031751266594344U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14243218483842508113U;
            aOrbiterE = RotL64((aOrbiterE * 9041601306479302047U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5803147589312920032U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5549470512227427855U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12592362489263862879U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10076661824293832189U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3196799148974716550U;
            aOrbiterC = RotL64((aOrbiterC * 8183276968961467775U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 40U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aIngress, 42U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterF, 3U));
            aWandererF = aWandererF + ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterH, 22U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterC, 43U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 4U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 18U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32524U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadA[((aIndex + 31556U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32436U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31278U)) & S_BLOCK1], 10U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30510U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadB[((aIndex + 30496U)) & W_KEY1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 12U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererF + RotL64(aCross, 28U)) + RotL64(aCarry, 57U)) + 16651241552253078315U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 3U)) + 4558144676982478003U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 23U)) + 8814884320080367550U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 57U)) + 16011579668555672117U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 47U)) + 4738918668759862438U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 10U)) + 12526083125540985108U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 41U)) + 8048723561746000552U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 1082218464034639039U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 8432043246965946816U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9982080524048636852U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6720069955755215919U;
            aOrbiterB = RotL64((aOrbiterB * 1025046364205332059U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1019035028070247757U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7360619079463870467U;
            aOrbiterI = RotL64((aOrbiterI * 6623074813047915863U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10893918488381348474U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1390297670907738019U;
            aOrbiterC = RotL64((aOrbiterC * 11909657437658597735U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12512200589031203480U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14741471280748399540U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3012135242889901095U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8543897248359826770U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8545972622733791272U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11793879362775346821U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7049384618581928664U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14730773807906925408U;
            aOrbiterK = RotL64((aOrbiterK * 10711566871536755073U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11480717275652449986U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1135397594974536859U;
            aOrbiterA = RotL64((aOrbiterA * 6347492892938856497U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6897207625849516702U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10920630712550287148U;
            aOrbiterF = RotL64((aOrbiterF * 4140705091806993359U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1094056478999931332U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6784487144549717207U;
            aOrbiterJ = RotL64((aOrbiterJ * 6295177724167067891U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 44U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 19U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 56U) + RotL64(aOrbiterI, 3U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 24U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 35U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterH, 11U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 18U) + aOrbiterC) + RotL64(aOrbiterK, 40U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Rugby_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2696U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 3936U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4366U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5525U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3045U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4064U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 60U)) + 1866656689936219099U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 2312314528139448289U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 5U)) + 3554037526469185237U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 41U)) + 405707755060974111U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 27U)) + 1862976326004007697U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 12992483065443288263U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 3793854946371595197U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4244007978867369382U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10280867500312580308U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13729899124177931289U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 472563452959164242U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12041770406895816553U;
            aOrbiterD = RotL64((aOrbiterD * 17811798500132002631U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6118634015704900486U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13637107920449233307U;
            aOrbiterC = RotL64((aOrbiterC * 17712028184714868053U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16673735670669318830U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8602681273646630496U;
            aOrbiterA = RotL64((aOrbiterA * 6995213887710749241U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7683264695930369476U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9146674871199188218U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7403427067419261981U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3012935612827493084U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1259789268731661945U;
            aOrbiterI = RotL64((aOrbiterI * 2372843620327050137U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5623690455471160780U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 18355567776031865462U;
            aOrbiterB = RotL64((aOrbiterB * 9553862670107886679U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 50U) + aOrbiterC) + RotL64(aOrbiterB, 13U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 42U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10639U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 15226U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 15061U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((aIndex + 11269U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14253U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11243U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8818U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 56U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 5U)) + 13880995121909552664U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aPrevious, 21U)) + 14534942818069300546U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 47U)) + 17745973100886007133U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 2249805580771946872U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 4460116116396439410U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 12U)) + RotL64(aCarry, 5U)) + 3378683994078106878U;
            aOrbiterE = (aWandererG + RotL64(aCross, 35U)) + 3992996501048809123U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12057768808864451929U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4115362079047921130U;
            aOrbiterI = RotL64((aOrbiterI * 12263015903331031345U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15297384955502206698U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17623548383481905636U;
            aOrbiterJ = RotL64((aOrbiterJ * 7487278217901483685U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3559213898000162417U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12311605719074507335U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3982199462062847697U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14807313864347885885U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11222085523291581822U;
            aOrbiterD = RotL64((aOrbiterD * 12580941911587215653U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 916681229436292462U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2441350114032314686U;
            aOrbiterH = RotL64((aOrbiterH * 7336079498999018067U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7361470539894653271U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12153585147213579808U;
            aOrbiterK = RotL64((aOrbiterK * 3040327545467672961U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13566300726101613579U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14875254144748509128U;
            aOrbiterG = RotL64((aOrbiterG * 13699179902908972403U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 38U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterK, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 41U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + aPhaseEWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 14U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19515U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 22700U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 18772U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24433U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23990U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24159U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17676U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 44U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererD + RotL64(aIngress, 27U)) + 2101601659597850213U;
            aOrbiterI = (aWandererE + RotL64(aCross, 41U)) + 2759794072560720121U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 47U)) + 9443562552411269339U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 10801360546699857975U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 10U)) + 8020716394829332019U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 1021894212367773801U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 13346855534622490176U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16359309548462953836U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12642446944680783519U;
            aOrbiterC = RotL64((aOrbiterC * 12197935153255283321U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8197424982767553380U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14346334610901859094U;
            aOrbiterK = RotL64((aOrbiterK * 16982899923227935679U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14171304260534233539U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 334531601308283605U;
            aOrbiterI = RotL64((aOrbiterI * 5012968232749075075U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10707856298471572695U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 18364775750091914766U;
            aOrbiterE = RotL64((aOrbiterE * 15735143943129143265U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8531394793118363836U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15352876929406908882U;
            aOrbiterF = RotL64((aOrbiterF * 475199047053777179U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 567682016232278157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2068146551757663119U;
            aOrbiterG = RotL64((aOrbiterG * 1557877740957797555U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7776122587613256525U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16430938890724272256U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4540270493783593257U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 4U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterI, 60U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterF, 29U));
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterE, 41U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterA, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererC, 46U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26720U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 31592U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 26948U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26449U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28368U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30372U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 28535U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererH + RotL64(aPrevious, 29U)) + 3238389262925516513U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 23U)) + 12381787182611386995U) + aPhaseEOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 60U)) + 7883885539305181549U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 11U)) + 1185413044597727092U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 15219353497204773135U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 7533774715626734082U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 2599930450937763464U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16074720663961214284U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15483613196360051221U;
            aOrbiterJ = RotL64((aOrbiterJ * 11717479088020532861U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9396557867081376268U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9668459976852660245U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11748505665890567063U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9037269914643207212U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16936742640861088240U;
            aOrbiterH = RotL64((aOrbiterH * 1040172193161012227U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16481274825758546398U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 481851372837611166U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2225030139210599207U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13608921517203544108U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16930740723286214636U;
            aOrbiterG = RotL64((aOrbiterG * 2605108503821980865U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 902242902582149908U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1510861213079342977U;
            aOrbiterC = RotL64((aOrbiterC * 3309753895727400707U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7116243600304980310U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6631412278359709602U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11452627691392637463U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 30U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 4U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 57U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterH, 29U)) + aPhaseEWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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

void TwistExpander_Rugby_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6191U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((aIndex + 7493U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 561U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1236U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5688U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2628U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 38U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 41U)) + 1087148170018530502U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 15530846874509311414U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 47U)) + 16987358651515511212U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 56U)) + RotL64(aCarry, 57U)) + 12504143181007924259U;
            aOrbiterH = (aWandererC + RotL64(aCross, 51U)) + 393322117322732418U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 11U)) + 14325937299241887166U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 29U)) + 9395262907017475742U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 13658510441418344769U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 35U)) + 6410754322737005336U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 60U)) + 9257290738538818434U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 27U)) + 7489828960857692286U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4118778591214588387U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16619215231168796563U;
            aOrbiterD = RotL64((aOrbiterD * 14876884956536265157U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11326283811003573430U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1865401866017614604U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8378326058282460073U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 670150121105733604U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1499331510641068749U;
            aOrbiterA = RotL64((aOrbiterA * 16623742535540383107U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1116410848560838532U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2696841341036281779U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9598953298074904869U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5487352391229549881U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12008243050943342979U;
            aOrbiterI = RotL64((aOrbiterI * 9087261224804582459U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 552859665927882960U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8426942688524814473U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10916963622695549105U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1613287981244830815U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15592897923468694288U;
            aOrbiterB = RotL64((aOrbiterB * 6600750586743893303U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7629853970631002676U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13778028957247561272U;
            aOrbiterK = RotL64((aOrbiterK * 4063798788229605659U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2932956928094332652U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14855524972646900872U;
            aOrbiterF = RotL64((aOrbiterF * 9546042275547649745U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11071597794692793784U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6327727700942234552U;
            aOrbiterJ = RotL64((aOrbiterJ * 15301120263944789797U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5147576281502110428U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1087148170018530502U;
            aOrbiterG = RotL64((aOrbiterG * 18045084130531645749U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterA, 34U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 11U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 40U) + aOrbiterG) + RotL64(aOrbiterC, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 24U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterE, 27U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 48U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterH) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12593U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((aIndex + 11906U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9570U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((aIndex + 15008U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10086U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8724U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10530U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 14U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererJ + RotL64(aCross, 43U)) + 4980738603982643969U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 35U)) + 17660278413018470020U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 39U)) + 17598114429859543466U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 5U)) + 10993929335279994739U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 46U)) + 17967203122976322481U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 1872290205549034384U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 23U)) + 16607778671782810797U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 51U)) + 4895226930754394376U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 60U)) + 14960359005982301383U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 9921642352377700630U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 893281964367208693U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8232519988397858732U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4433022122758913407U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 834240393225479419U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12689609831247168353U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 404535388957472176U;
            aOrbiterH = RotL64((aOrbiterH * 14534020545479806593U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3349108201964013155U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4386449511297371730U;
            aOrbiterK = RotL64((aOrbiterK * 9596273264321140229U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14314587717949070586U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10923886625271054985U;
            aOrbiterD = RotL64((aOrbiterD * 7838969002623486809U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17634909585329833520U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2021301459918350372U;
            aOrbiterG = RotL64((aOrbiterG * 1388242915918642741U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5219599112498224367U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10641339455385046206U;
            aOrbiterC = RotL64((aOrbiterC * 1022283727595400719U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5003342156562330058U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10951027475628404336U;
            aOrbiterJ = RotL64((aOrbiterJ * 17836928292555158461U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13040991872592235460U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11149099984302782267U;
            aOrbiterF = RotL64((aOrbiterF * 4248667283139686251U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2202253777854402763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16679038924474862612U;
            aOrbiterE = RotL64((aOrbiterE * 2624443661523083597U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1959650241410955571U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8415989510614674816U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16340289102832732519U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2344501711730399821U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4980738603982643969U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6419275275477478723U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 18U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 26U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aIngress, 54U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 37U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 44U));
            aWandererA = aWandererA + (((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterB, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22329U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 17238U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 22300U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 22931U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23540U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20682U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 22228U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 23U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererD + RotL64(aCross, 27U)) + 12046647397183218524U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 34U)) + 2760779375026461991U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 13735454443176855650U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 53U)) + 4370377000586647724U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 14566322384189969094U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 58U)) + 5056565959818422786U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 13U)) + 8795403810686579209U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 9625947666256011567U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 39U)) + 1703669290934254701U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 11U)) + 6664070663184147951U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 43U)) + 2104148316797553431U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1197910004222596145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9922977170060903197U;
            aOrbiterA = RotL64((aOrbiterA * 13047828062605568603U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2048376210852567829U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12568990647075931409U;
            aOrbiterD = RotL64((aOrbiterD * 9860242601194210927U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15026894775772902751U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3439447160137900629U;
            aOrbiterC = RotL64((aOrbiterC * 1813754963043785165U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6532671388552829796U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17261098369835997661U;
            aOrbiterE = RotL64((aOrbiterE * 568292591215203521U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3171300991007459947U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5935563269327662024U;
            aOrbiterK = RotL64((aOrbiterK * 11271790283157765003U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14290941734320455612U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12371794745736518824U;
            aOrbiterH = RotL64((aOrbiterH * 12208762336145168647U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8782840145467637373U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4067525421190366741U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6671002797916227485U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11854812920571789853U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17564890418553131451U;
            aOrbiterF = RotL64((aOrbiterF * 16657184504366731805U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6250004085193517531U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2362659992682660827U;
            aOrbiterB = RotL64((aOrbiterB * 4365619310373869859U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4597159873252831182U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13197238269207675773U;
            aOrbiterJ = RotL64((aOrbiterJ * 379653377172816575U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8552479493772820372U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12046647397183218524U;
            aOrbiterI = RotL64((aOrbiterI * 17918033655125400323U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 24U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 42U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 26U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterB, 35U));
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterC, 29U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 54U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererC, 52U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26430U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 29174U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27323U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 32143U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29411U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31790U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 25693U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererD + RotL64(aCross, 24U)) + 3255291173184001106U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 5U)) + 15308468160116255528U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 39U)) + 18186972408589866656U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aPrevious, 13U)) + 4439324265978331914U;
            aOrbiterB = (aWandererA + RotL64(aCross, 37U)) + 13099263173016322486U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 53U)) + 7041561081767500660U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 6196422612687812971U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 34U)) + RotL64(aCarry, 5U)) + 7664260932541281413U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 17802347823020441056U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 43U)) + 4253107484061190446U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 27U)) + 13799496534030645312U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14252892847595951926U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5663527578664291422U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18314294235895182465U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11148755959699137661U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17036900929333594592U;
            aOrbiterG = RotL64((aOrbiterG * 16041243617369003291U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2403828181385259549U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17813580350434928194U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13666780980793857831U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5623611126885414523U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7293224381174846969U;
            aOrbiterD = RotL64((aOrbiterD * 7032561584670788117U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10602620906929686163U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18015916257203385982U;
            aOrbiterK = RotL64((aOrbiterK * 10684090189688871993U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13592915735376305773U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13995866908043417505U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3802175869395887331U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8200465989447697618U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9866671660800629464U;
            aOrbiterB = RotL64((aOrbiterB * 2138851839905326265U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11557528777230608777U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 131060617338185060U;
            aOrbiterC = RotL64((aOrbiterC * 11068705423012265209U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13404720733342982167U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13128574378042136042U;
            aOrbiterH = RotL64((aOrbiterH * 5805270317312187011U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15879295432652112238U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9433361543323748909U;
            aOrbiterE = RotL64((aOrbiterE * 3592390041363796221U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6262775775981534941U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3255291173184001106U;
            aOrbiterA = RotL64((aOrbiterA * 2748492753337241005U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 19U));
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterA, 51U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterE, 53U));
            aWandererE = aWandererE + ((((RotL64(aCross, 51U) + RotL64(aOrbiterK, 44U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 35U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterG, 56U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 10U) + aOrbiterK) + RotL64(aOrbiterI, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 22U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Rugby_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7306U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 995U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5496U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5364U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4915U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7085U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 54U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 21U)) + 3105313968748067810U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 6U)) + RotL64(aCarry, 29U)) + 9977249451119627064U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 39U)) + 17941392803495349366U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 4279533326705471133U) + aPhaseGOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 13983828966811580039U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3983490984234810378U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 308786542215259956U;
            aOrbiterD = RotL64((aOrbiterD * 4366245356597769425U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8443607695364427037U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14939626441464340668U;
            aOrbiterI = RotL64((aOrbiterI * 16793255020331774983U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9350693577306121110U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 1717071159396961752U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11062480662625054525U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15911765265202100610U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14898546272333182767U;
            aOrbiterH = RotL64((aOrbiterH * 2674900543810733067U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3560903518513465868U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5367062725726860234U;
            aOrbiterK = RotL64((aOrbiterK * 8521908836601319553U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 34U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 6U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 46U) + aOrbiterI) + RotL64(aOrbiterK, 39U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 38U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16062U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 12996U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13902U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9915U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13600U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 14021U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 6U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 38U)) + 4384716820085860551U) + aPhaseGOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 9715780315942116888U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 15963520052789178632U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 14346700690686392938U) + aPhaseGOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 11U)) + 6005518012489966643U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 2506732930310252119U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16782163084851775826U;
            aOrbiterE = RotL64((aOrbiterE * 1527050617428162663U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 823673076571076303U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1634084509064077736U;
            aOrbiterK = RotL64((aOrbiterK * 1128407326773234517U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1288134975466877686U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 2998220403162908444U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4321412662318298283U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 220430672180734911U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10223923547068528867U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12577370238343872139U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11696469696177647608U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 6545430420379636963U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8387163146257553773U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 22U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 23U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterK, 46U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21176U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 19900U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22268U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22664U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22135U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16970U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aPrevious, 47U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 12U)) + RotL64(aCarry, 53U)) + 13174219512651137892U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 2715455762789269341U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 1338018183235594313U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 29U)) + 16566866551729552930U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 21U)) + 6901845297307236726U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2476078302049201718U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15531109473927052260U;
            aOrbiterF = RotL64((aOrbiterF * 1078804000420970559U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4087849380858572351U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5167830630098599644U;
            aOrbiterC = RotL64((aOrbiterC * 1982835131228146099U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7275995452428627217U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14794340370010024117U;
            aOrbiterD = RotL64((aOrbiterD * 8779497557416568379U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8509217403041662849U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2321522025240806996U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 113568101672878697U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5676672952755594051U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2304681269233504384U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15731441084605554497U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 10U)) + aPhaseGWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 38U) + aOrbiterF) + RotL64(aOrbiterC, 53U)) + aPhaseGWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterF, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31657U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 28114U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29742U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29004U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31610U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 25655U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 9041099828460168106U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 12883711604096848454U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 17420968786226443079U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 43U)) + 3448213891716125104U) + aPhaseGOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 34U)) + 11866455977445336560U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4119356835384495905U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2186212599698637068U;
            aOrbiterC = RotL64((aOrbiterC * 6756888950976735707U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6506144898969301620U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12556800923644051626U;
            aOrbiterF = RotL64((aOrbiterF * 15961043406612913121U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4075551535185182945U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17877694808492008749U;
            aOrbiterA = RotL64((aOrbiterA * 901315308379887473U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5553428900598223316U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14362304852277160675U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11415103199856419303U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9174200302876075831U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16110739511917638547U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7004356839428657949U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterA, 35U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterC, 14U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Rugby_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2447U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 3137U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7259U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1292U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3142U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 2584U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 41U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aCross, 5U)) + 77518479758428414U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 4832061802166300011U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 46U)) + RotL64(aCarry, 21U)) + 11695291171006574112U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 7467412817843260094U) + aPhaseHOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 13U)) + 17801484124471154757U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5555455638503958639U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 5669470540733721606U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17219613748084498879U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3042388456327784163U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2236734925228156691U;
            aOrbiterC = RotL64((aOrbiterC * 10076582424701705531U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14459720401528685450U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4814967631216658856U;
            aOrbiterJ = RotL64((aOrbiterJ * 18288097536171386643U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16950679344449075945U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6262238639302011050U;
            aOrbiterG = RotL64((aOrbiterG * 9942659897425088183U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3522256359074996724U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12524717897707074242U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6787771338063891989U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 37U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterH, 13U));
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterK, 28U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11300U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 10466U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 9304U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9651U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13067U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 10427U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 27U)) + (RotL64(aPrevious, 14U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aCross, 27U)) + 5160910997561396461U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 14920764751058512062U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 14U)) + 6080952401749660022U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 17667234330526298627U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 760630072638686756U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3504157162816997476U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9489022223422585882U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2398110457196177747U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1149898536879968964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10492284328940025310U;
            aOrbiterK = RotL64((aOrbiterK * 7893416766300156495U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13213275606286399312U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10557118912847180413U;
            aOrbiterD = RotL64((aOrbiterD * 10077877991284587845U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 15618980209023994776U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 5268600749854045564U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3849660559223919613U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8011552687609649990U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3148133096349525066U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5245156554959620007U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 39U)) + aOrbiterD) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 30U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 18U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23406U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 18165U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16550U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17775U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18051U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 16574U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 60U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (((aWandererH + RotL64(aScatter, 58U)) + RotL64(aCarry, 43U)) + 9023059520606551446U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 662441755115638133U) + aPhaseHOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 47U)) + 16957253361196144712U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 7840955025765308605U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 3U)) + 346855809270395799U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16099139781586668343U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3706457327118322098U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7810030620470889591U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12166825885547622870U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7792658665720344200U;
            aOrbiterE = RotL64((aOrbiterE * 16305542632794270697U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7128477606152986326U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11116533962780290084U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11993485572912492297U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10443889548568288532U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4402387036946561017U;
            aOrbiterC = RotL64((aOrbiterC * 9032964741841833277U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13002706161178447654U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13929727277530310708U;
            aOrbiterG = RotL64((aOrbiterG * 7005639090871200285U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 50U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + aPhaseHWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 6U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + aPhaseHWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32130U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 31836U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29527U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31996U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27989U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27483U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 13U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 42U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererJ + RotL64(aIngress, 13U)) + 12029393034357490020U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 4526754731580694987U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 17060419646421271853U) + aPhaseHOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 4128488893837059683U) + aPhaseHOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 46U)) + 12706894827547160110U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12506324593645825056U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12581344490649250025U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16311882267466003291U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14357032418199130132U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15341977701796331249U;
            aOrbiterG = RotL64((aOrbiterG * 6332369248718076031U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 7086602307544733241U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12398300065276832486U;
            aOrbiterD = RotL64((aOrbiterD * 18157408831225635333U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2499745046076601988U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7249361592814001829U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14597139848072319685U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3254456186337366437U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3472973415969046680U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14583566953969168353U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 44U) + aOrbiterD) + RotL64(aOrbiterF, 19U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 54U)) + aOrbiterI) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
