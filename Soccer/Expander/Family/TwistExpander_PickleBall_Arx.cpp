#include "TwistExpander_PickleBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_PickleBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x84EFEC1AD4BD55C7ULL + 0xDD8A9DCF8FA7606FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x83076BFDD98FFFA7ULL + 0xDD5B992DB39883BEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE53B1E610E9ECDCBULL + 0xC47C2ED576A45B8BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCEC204BA4A9DE63DULL + 0xED65102A0F1AAE74ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x99ED0D0B0ACF05BFULL + 0x93FBD4FEB2B16342ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x891393575B2D8DD7ULL + 0xEE32E77065F6E78BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC6997D9BF1B53D81ULL + 0xA078B43305500446ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDEE01C48A3FF1899ULL + 0xA15BC8B239A96061ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB8C0D9EE48F71E4BULL + 0x9F7D63FBAC278004ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE8857D24B72DF8FBULL + 0xFC5151FE932E0613ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD615D5EEFB1D0E5BULL + 0x9DA8B6CB797133C8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBC06F02762D5522FULL + 0xECB9D7AFFD6AC84DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x98EE8665382B2765ULL + 0xD00ECF6192BB9A86ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA4A63570B8C24E0DULL + 0x802E2A910C4C5A96ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC6D7FDAFD47E73CFULL + 0x8D89459A13272505ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9861306BE48F8D73ULL + 0xEA7E7B930B207BCDULL);
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
        // read from: mSource, pSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // read from: mSource, pSnow
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4873U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((aIndex + 1536U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 646U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1026U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aIngress, 53U)) + 2672739400294801233U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 3U)) + 8475624545015101850U;
            aOrbiterB = (aWandererD + RotL64(aCross, 34U)) + 1252755112289831257U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 43U)) + 7938039507649183387U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 27U)) + 8167413146948861022U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 17712313989694374353U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 39U)) + 7637042279892596975U) + aNonceWordD;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 11U)) + 15770412950033467341U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 23U)) + 3951812021898608685U) + aNonceWordG;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 8656983621098246507U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 23U)) + 17943342344730687317U) + aNonceWordO;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 3087677463651608668U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16493240011924342788U;
            aOrbiterB = RotL64((aOrbiterB * 16898479041530771871U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7750923317452683057U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2185924841611106546U;
            aOrbiterI = RotL64((aOrbiterI * 708072658250726381U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14676868738946722416U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 6849098251696302393U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2599806275837778069U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17817755047153606419U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9900465270314068757U;
            aOrbiterE = RotL64((aOrbiterE * 9267925873983176685U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11380000891112113701U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15930503831156546113U;
            aOrbiterF = RotL64((aOrbiterF * 14450535035065393845U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5439183530402949780U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3731802052051181843U;
            aOrbiterH = RotL64((aOrbiterH * 7739775058947333169U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14432344583247783600U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16192098795467501636U;
            aOrbiterC = RotL64((aOrbiterC * 6285466374319549047U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1523272672673940290U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7462092373525113574U) ^ aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15067751170235540679U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4612539457663050732U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7959404391235752875U;
            aOrbiterJ = RotL64((aOrbiterJ * 137834571274065007U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 11853468935131763944U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3575434598998149168U;
            aOrbiterD = RotL64((aOrbiterD * 16971321675425065041U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6135993440654291404U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2672739400294801233U;
            aOrbiterG = RotL64((aOrbiterG * 12891757276825641567U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 24U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 53U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 13U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 41U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 42U) + aOrbiterF) + RotL64(aOrbiterD, 29U));
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 11U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 18U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordK);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // read from: aWorkLaneA, mSource, pSnow
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7171U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8284U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 5935U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10778U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCross, 60U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aScatter, 35U)) + 12690502671561165478U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 3U)) + 17519943923428102801U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 10U)) + 10705515807975331385U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 16586447272278538179U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 41U)) + 8006560996840971798U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 21U)) + 12928600185788857701U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 51U)) + 14240723153798267172U) + aNonceWordK;
            aOrbiterG = ((aWandererG + RotL64(aCross, 37U)) + 8636219177994872072U) + aNonceWordA;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 18U)) + RotL64(aCarry, 3U)) + 7586790235186467512U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 1103807034179512424U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 27U)) + 7547526530239498693U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8380239679344786397U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5690809173787433519U;
            aOrbiterH = RotL64((aOrbiterH * 5354724308093372953U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8390902801141804609U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3507306189192059486U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18336280496510253103U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6190745292098482871U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8065418693975056902U;
            aOrbiterD = RotL64((aOrbiterD * 6414621418430102589U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12111755051718111803U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7605877769709909297U;
            aOrbiterK = RotL64((aOrbiterK * 17525248694315944599U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5969794501112646237U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5127559299360591476U;
            aOrbiterJ = RotL64((aOrbiterJ * 4521563633438853069U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10593847754747739786U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4401750688524310121U;
            aOrbiterC = RotL64((aOrbiterC * 14265829318976633707U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 6927893132508779499U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4874009978647014479U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 13340466017023540755U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13146693487138744677U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3298472134223595298U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2145005258008477281U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8729305340729268734U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 18347161842033439538U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 7952715248988302017U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 166831495912855225U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4943633045563697271U;
            aOrbiterA = RotL64((aOrbiterA * 1809857625425000137U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2460623715340753589U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12690502671561165478U;
            aOrbiterE = RotL64((aOrbiterE * 16421139715633515623U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 10U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 53U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterF, 26U)) + aNonceWordF);
            aWandererH = aWandererH + (((RotL64(aCross, 30U) + aOrbiterB) + RotL64(aOrbiterJ, 23U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 43U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 37U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 39U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterD, 3U));
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + RotL64(aOrbiterF, 46U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 51U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // read from: aWorkLaneB, aWorkLaneA, mSource, pSnow
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12539U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10944U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 13294U)) & S_BLOCK1], 41U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 14029U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 4U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 6U)) + 14214886793361825363U;
            aOrbiterK = (aWandererF + RotL64(aCross, 35U)) + 17267959031078766320U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 16436067429484887644U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 39U)) + 9885951769332633820U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 12971711341813893304U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 11U)) + 199970353398450154U) + aNonceWordA;
            aOrbiterF = (aWandererA + RotL64(aScatter, 37U)) + 1237341696444162094U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 30U)) + RotL64(aCarry, 27U)) + 7991128854417613360U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 3U)) + 14809029847149045833U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 13U)) + 2559509556915775947U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 21U)) + 14336829730147834160U) + aNonceWordC;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8853631886733610440U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 13346159398673246914U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13660497151446983393U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 12121095718571872976U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16239781125815589804U;
            aOrbiterB = RotL64((aOrbiterB * 5157009090454962231U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9051377033794324106U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13805815136723461780U;
            aOrbiterK = RotL64((aOrbiterK * 571129481747181357U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14849157800322754413U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 18116651528452542634U;
            aOrbiterD = RotL64((aOrbiterD * 3638480428016835537U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4105057226952948599U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5911714320560994391U;
            aOrbiterA = RotL64((aOrbiterA * 1796514171654961389U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4439149331729987587U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10278532228230163632U;
            aOrbiterG = RotL64((aOrbiterG * 17428224919864716517U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2342456582668741750U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2360578572554664800U;
            aOrbiterI = RotL64((aOrbiterI * 1108428466956691925U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12132934875391401246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17213278726790245812U;
            aOrbiterH = RotL64((aOrbiterH * 11904899990681410419U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7994340481560109811U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13735851271080138255U;
            aOrbiterF = RotL64((aOrbiterF * 12387076892129731557U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6682417543888875268U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 15642799286975840550U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 7861250716882028053U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9839299346094784067U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14214886793361825363U;
            aOrbiterC = RotL64((aOrbiterC * 2103132743364916037U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + aNonceWordH);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterG, 39U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterC, 37U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 41U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 24U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 42U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 41U)) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 50U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordK);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // read from: aExpandLaneA, aWorkLaneB, aWorkLaneA, mSource
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21248U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((aIndex + 17965U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18345U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16419U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 14U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aCross, 38U)) + RotL64(aCarry, 27U)) + 15726877954695761686U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 43U)) + 14187652171881943587U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 23U)) + 8420423151313882782U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 57U)) + 14942322692433259283U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 7272331475919796255U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 35U)) + 154504365041805840U;
            aOrbiterC = (aWandererA + RotL64(aCross, 21U)) + 17475491222554948786U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 28U)) + 5759181483165339605U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 11U)) + 5993060214499322845U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 19U)) + 10901786237875941844U) + aNonceWordD;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 17135786595614068473U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5208202073886811165U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6821452921018900631U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 13119330055184115669U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13348064837402206969U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8967943922403445136U;
            aOrbiterJ = RotL64((aOrbiterJ * 300168481725373093U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8130283784171430891U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6351113882502502876U;
            aOrbiterG = RotL64((aOrbiterG * 15960622823993072903U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6894708729226455769U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12065058511247133944U;
            aOrbiterC = RotL64((aOrbiterC * 5432601727436935831U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17138279326229372741U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12987698199066890628U;
            aOrbiterD = RotL64((aOrbiterD * 12665716655177320977U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13688833537574196675U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4211971980434000618U;
            aOrbiterI = RotL64((aOrbiterI * 1374411763361518851U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10376917117582537592U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4807742522197923516U;
            aOrbiterH = RotL64((aOrbiterH * 15257251453302090961U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 18038296468177121243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6879666349379745258U;
            aOrbiterE = RotL64((aOrbiterE * 15819475269715810555U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5193656664432659624U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 680899397323387963U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9857476056194621321U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1851929589073547860U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 13093101559415170218U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13950928576652143737U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13695333301427028607U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15726877954695761686U;
            aOrbiterB = RotL64((aOrbiterB * 960063676226172027U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 6U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI + ((RotL64(aIngress, 54U) + aOrbiterI) + RotL64(aOrbiterK, 35U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterB, 21U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 30U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 23U)) + aOrbiterG) + aNonceWordH);
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 51U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 28U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26399U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22032U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22731U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 24022U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 22U) ^ RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aIngress, 30U)) + 5088525177670191619U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 23U)) + 9966456257813932112U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 53U)) + 7707646574027146307U) + aNonceWordA;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 57U)) + 75480203757681173U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 35U)) + 384659134071835163U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 3158769775373307778U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 11U)) + 17360830943513941272U;
            aOrbiterK = (aWandererK + RotL64(aCross, 27U)) + 5317278822721604586U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 37U)) + 1371427105215954781U) + aNonceWordC;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 3162710551223553423U) + aNonceWordE;
            aOrbiterH = (aWandererB + RotL64(aCross, 35U)) + 5332921933853550756U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10572462410297815854U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10234389605554817892U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 2130374833440291193U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13421365517991380605U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10186643614984034083U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8554471709467808453U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 4742438973260817120U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 6081590345899008846U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7069396301823124931U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15360092808493795340U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12186413069553132646U;
            aOrbiterI = RotL64((aOrbiterI * 3815981440611914267U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16756221656224451552U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12232880965861373143U;
            aOrbiterB = RotL64((aOrbiterB * 14196910735715726471U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10090954323470840557U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15615770271463853537U;
            aOrbiterJ = RotL64((aOrbiterJ * 13544181592829027283U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 556029032505658411U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13311879111583579039U;
            aOrbiterC = RotL64((aOrbiterC * 3924744868168749003U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8646360871497847336U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2064833941982069154U;
            aOrbiterG = RotL64((aOrbiterG * 10016546852137913163U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1701847261278886621U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9654208200019718374U;
            aOrbiterH = RotL64((aOrbiterH * 4398089490129603677U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14276143262844412074U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10738184916176200661U;
            aOrbiterD = RotL64((aOrbiterD * 8940267914440361883U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2966052720680305600U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5088525177670191619U;
            aOrbiterE = RotL64((aOrbiterE * 11621585388684456139U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 44U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 44U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 54U) + aOrbiterF) + RotL64(aOrbiterH, 21U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterI, 41U));
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 27U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterE, 5U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 30U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterA, 35U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30577U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27823U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30222U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 27887U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 41U)) + 826930775230515406U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 43U)) + 5137814617363250861U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aCross, 60U)) + 14761561947426681616U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 57U)) + 12773023438753662590U) + aNonceWordA;
            aOrbiterI = (aWandererE + RotL64(aCross, 13U)) + 7331345852207096322U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 3899381212671247460U;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 10072004147620068599U) + aNonceWordM;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 3424585039401897560U;
            aOrbiterB = (aWandererF + RotL64(aCross, 11U)) + 8246760141625966321U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 54U)) + 3655992860610853290U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 51U)) + 11154618022505863898U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15629361991059709973U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10842068502278489664U;
            aOrbiterE = RotL64((aOrbiterE * 17223002513104960799U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5571312349016336686U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 589313823745748879U;
            aOrbiterI = RotL64((aOrbiterI * 1356685926549786027U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13633457935771935260U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12684602052812183096U;
            aOrbiterH = RotL64((aOrbiterH * 4689206269919806711U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5711307583717354204U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7181854170553728211U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9835601115561325911U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 1884620014396115821U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1471516373272364262U;
            aOrbiterK = RotL64((aOrbiterK * 5126319375714848029U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 742739371092077733U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8075893317715227838U;
            aOrbiterB = RotL64((aOrbiterB * 11208274111743259795U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8179547722249281263U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15305282712174742323U;
            aOrbiterG = RotL64((aOrbiterG * 7951986906055462929U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1430543231751281079U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14585341768267283387U;
            aOrbiterF = RotL64((aOrbiterF * 313213844964269133U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8123889986027932297U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2081696191347150910U;
            aOrbiterJ = RotL64((aOrbiterJ * 4869653441012615053U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10166788886199265936U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15927074835525735601U;
            aOrbiterC = RotL64((aOrbiterC * 6747650218540675523U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6997764816848988590U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 826930775230515406U;
            aOrbiterD = RotL64((aOrbiterD * 9943232461538279601U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 52U) + aOrbiterJ) + RotL64(aOrbiterA, 10U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterB, 41U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 37U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterE, 21U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 44U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 42U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_PickleBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE272E93DA2771223ULL + 0xD8EDEF3396580F90ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCEC01910E315137BULL + 0xBFD6AC1F68CEA5DEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFA6321FC4E41EE27ULL + 0xFD011DED4097E7B3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCE2B1D3F4014AB05ULL + 0xFF6ACDBEF37BD988ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9BA823325E80C207ULL + 0xF2159F94198F7BE5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9376691F76F0BF17ULL + 0xEA8EB684F9C9F0C7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE5652962446F2F73ULL + 0xE431C01CD78641C6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8EBCF5029E5ECB61ULL + 0xCBF9C2C39915ABC9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDB3D3BFFEADA1F1BULL + 0xB42F4171D2DB3759ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBFE8496329A634BBULL + 0x80F83FCE4DA3C615ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8260DFA91E29BBEBULL + 0xA05C3B03773054BBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB91C7F21DEE1065BULL + 0xCF9B73887987E590ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC62CF57532140739ULL + 0xE267F5ACB88B366FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCE954FC328400EF5ULL + 0x92214C2B0438E173ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF2E1EABD40F4D9AFULL + 0xC7512848B0A30412ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x94CE444B5BEB072DULL + 0xD9D2A8C457FDBFBAULL);
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
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_a_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6325U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3350U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 905U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 1112U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 14U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 5U)) + 3550722402315312207U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 16724184551669522754U) + aNonceWordC;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 35U)) + 981751330116773021U) + aNonceWordH;
            aOrbiterA = ((aWandererB + RotL64(aCross, 10U)) + 7891159229704944868U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 47U)) + 13618396711464799841U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 5969291018449003648U;
            aOrbiterD = (aWandererF + RotL64(aCross, 23U)) + 14595540413313640042U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 18U)) + RotL64(aCarry, 43U)) + 3287990436916111762U) + aNonceWordD;
            aOrbiterF = (aWandererE + RotL64(aIngress, 51U)) + 12534369400200483704U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2277312067930392274U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10026320559261334353U;
            aOrbiterH = RotL64((aOrbiterH * 11020464940995912637U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11258082063135659551U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1445958517675746990U;
            aOrbiterJ = RotL64((aOrbiterJ * 10062265337488757971U), 5U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 1011298251290970844U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6487834862470043744U;
            aOrbiterK = RotL64((aOrbiterK * 15477913837027179675U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9966279022928268335U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10285993486057704393U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15965714363201157535U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16005362468813966136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 223843444699390781U;
            aOrbiterE = RotL64((aOrbiterE * 665392038954573081U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18178876294968532775U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12490136112181806806U;
            aOrbiterA = RotL64((aOrbiterA * 16380841616662993709U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8775696166557913635U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16464340319444310842U;
            aOrbiterD = RotL64((aOrbiterD * 18111632334728200721U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6296039992673546227U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7152939277656436037U;
            aOrbiterG = RotL64((aOrbiterG * 15183918431501487319U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14066791413416223271U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5026743227399908016U;
            aOrbiterI = RotL64((aOrbiterI * 5891343232759075675U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 48U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH) + aNonceWordJ) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterF, 58U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterG, 23U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterD, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 13U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterI, 52U));
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 37U)) + aOrbiterI) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD + (((RotL64(aIngress, 54U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordN);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9380U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((aIndex + 15760U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11898U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14846U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 43U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 22U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 37U)) + 1042610313571524121U) + aNonceWordL;
            aOrbiterD = (aWandererC + RotL64(aCross, 19U)) + 3505725321008825582U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 51U)) + 12584654563843782991U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 6645399144515770935U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 14U)) + 3608978423753715584U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aWandererF + RotL64(aIngress, 41U)) + 8089198857670370983U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 3U)) + 15207251813516399879U) + aNonceWordE;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 9579268660105824516U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 46U)) + RotL64(aCarry, 53U)) + 16055044469473802812U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 583811872609805949U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7027491967970873942U;
            aOrbiterB = RotL64((aOrbiterB * 12686754713465826139U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18256061823189677508U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12708429127816136937U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12593886633108075321U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12169216645156306078U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12694325407567795065U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3711789483877261899U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16109994660203297503U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4234704064165718913U;
            aOrbiterF = RotL64((aOrbiterF * 730085881474787681U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14119541943554602878U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8777769004811352951U;
            aOrbiterK = RotL64((aOrbiterK * 2556957257736134223U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15642663488392549609U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11594468530833278624U;
            aOrbiterJ = RotL64((aOrbiterJ * 6639306656361601143U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7365350535791499871U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5965170981970155956U;
            aOrbiterG = RotL64((aOrbiterG * 1898702752753066851U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9115232101451815522U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9433983580038990072U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1951249217843992179U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8810565477444156140U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 12081286530401844859U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1991383259486140229U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 30U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 24U) + aOrbiterK) + RotL64(aOrbiterC, 22U)) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterB, 58U));
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 40U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19032U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 21470U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23651U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 17492U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aIngress, 47U)) + 6024062041314952357U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aScatter, 39U)) + 18340757093658015585U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 10U)) + 11911120493880346751U) + aNonceWordN;
            aOrbiterH = (aWandererJ + RotL64(aCross, 35U)) + 17428074353884654439U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 12790849760814795936U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 12633397052172117800U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 28U)) + RotL64(aCarry, 27U)) + 11946150433665237945U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 43U)) + 16842157900909419285U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 21U)) + 14186235783224155962U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13284904542579767591U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11609181965078844357U;
            aOrbiterE = RotL64((aOrbiterE * 5455780554452453513U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9628562297095374984U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7850281529011259759U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 17611485102925470357U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 257458718073794527U) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10693404545773519306U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14821443722828498323U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3430519236533871460U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6183054506953198055U;
            aOrbiterD = RotL64((aOrbiterD * 6121082743789970911U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2905610989884221654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4472163910775333862U;
            aOrbiterK = RotL64((aOrbiterK * 7770678426310856745U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16870142883133769663U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1403692060594816451U;
            aOrbiterI = RotL64((aOrbiterI * 9740854430251597879U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16904169913507057108U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4773518591580333357U;
            aOrbiterB = RotL64((aOrbiterB * 5306070307776061267U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6528141733853494275U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11254806909313951442U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6316669786405548827U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6857506858448143407U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2855763534355983644U;
            aOrbiterJ = RotL64((aOrbiterJ * 16881334940165182415U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterE, 42U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterA, 37U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterH, 27U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 4U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordE;
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31185U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 28428U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32211U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 30426U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 44U) + RotL64(aCross, 57U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aIngress, 52U)) + 14624277139785904404U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 35U)) + 6966977309498165611U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 19U)) + 205536824352530761U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aWandererF + RotL64(aScatter, 27U)) + 16629575265808255692U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 596881340147972746U) + aNonceWordD;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 6U)) + 11944412799107412650U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 11U)) + 4615021315668210206U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 8497630055977606216U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 11131601107309336885U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5935883479805510099U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15629346719765798174U;
            aOrbiterI = RotL64((aOrbiterI * 8535523790685945275U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5279128339113651273U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16778365912440331821U;
            aOrbiterB = RotL64((aOrbiterB * 705421028266789241U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16003052937645491524U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 6723226158737614764U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16690657664909260573U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9785784358981219543U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10055457337292292710U;
            aOrbiterE = RotL64((aOrbiterE * 17919129940751761111U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11779163108592974175U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1177999477942202687U;
            aOrbiterF = RotL64((aOrbiterF * 13475069421684114643U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9190694445141492214U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15605342360346353457U;
            aOrbiterH = RotL64((aOrbiterH * 14547769706392595647U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14877565450677523492U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1074095623308025684U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7884068939436891093U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12803174154216941583U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8813356463693637033U;
            aOrbiterA = RotL64((aOrbiterA * 4898237214617563167U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 6063909634038581414U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15112191502834052566U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6780741782103553485U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 52U)) + aOrbiterE) + aNonceWordN);
            aWandererG = aWandererG + ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 38U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + aNonceWordL);
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterF, 36U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 34U) + aOrbiterB) + RotL64(aOrbiterF, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_PickleBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB694060F25768E23ULL + 0x99AAA07CAE514D20ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA4BDE5FCD2A966C3ULL + 0xE0A1160BA75F6C61ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE2BF7A39318ABA83ULL + 0xA87F3DFC4F6958E3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB97275CDF5DAA9B1ULL + 0xD0EE3A1BB259B498ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD511BDC77BDF563BULL + 0xF04D4A036CFB1866ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFA5E3851A147FA81ULL + 0xEB4ECFCFE5ABDF5DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8B880DD281FDFA33ULL + 0xEA9E9F52BF0366F6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x873540D7EC421E55ULL + 0xC2440544073243D0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE5905FB180152EFBULL + 0xF4F8697E2B37A10FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD558B84AE845DDBDULL + 0xBE7FED3466E3920AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA3BFC4D44C79DFD5ULL + 0x88975710DCEFF624ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE2466FE63E02BEB9ULL + 0x8E47A1F3CA17B50CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xABE6AEE236A8E89DULL + 0xADC4D686202A23C3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC57139C0FF1396A7ULL + 0xC4757DFC67A45138ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x88E249A228A58E9DULL + 0x93F64329C870805EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF060C9CDDFED57DBULL + 0x8BCCE258B769EA19ULL);
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
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3582U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3979U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4520U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((aIndex + 6613U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 35U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 4773124477323378268U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 16848723289435796005U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 47U)) + 13846642134917107058U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 56U)) + RotL64(aCarry, 27U)) + 6472057872482789939U) + aNonceWordA;
            aOrbiterI = ((aWandererK + RotL64(aCross, 29U)) + 2747019500690707226U) + aNonceWordB;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9003965289739733880U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3013390651936257377U;
            aOrbiterK = RotL64((aOrbiterK * 11081353600889943167U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3331004709895625067U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15355010435553517129U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8322759117004876831U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 7709870658004280052U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13568728443963926564U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6736090830113688981U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12409548853419307131U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 969183352023661537U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 5549220554838837145U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15370309834426476775U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3896803894396631184U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11018830202891911603U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 42U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH) + aNonceWordL) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 38U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16086U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10699U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9562U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15053U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 24U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererC + RotL64(aScatter, 44U)) + 14499676118633326000U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 17191273593018552288U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 35U)) + 4085176294948097737U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 11112671474158908186U;
            aOrbiterJ = ((((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 8745787969012266485U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 18074049663777707948U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2543758649719164688U;
            aOrbiterK = RotL64((aOrbiterK * 7153845562786344373U), 51U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 4659584749412700523U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 974639159259871273U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17918719351847605523U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9211220687971081987U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8567024626862182714U;
            aOrbiterB = RotL64((aOrbiterB * 7755874089832496393U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5803002132294840900U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11968489432878148467U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4501441062617123165U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9470807228394903442U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1692347973120388469U;
            aOrbiterE = RotL64((aOrbiterE * 17433393164156231575U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 24U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterE, 38U)) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23741U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 18097U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21661U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18297U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCarry, 23U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 15036852811491820366U) + aNonceWordE;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 10U)) + 305637140752898475U) + aNonceWordF;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 11948631574496129610U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 5321623592482991426U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 29U)) + 4075270159062690728U) + aNonceWordP;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15111580500356908928U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 7244150695504160363U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2445733898697939969U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 5131563519577488862U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5881954992088651371U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2424421828597294607U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12780935808751507998U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12599159643925470226U;
            aOrbiterC = RotL64((aOrbiterC * 17690046932587062701U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9466589929741834066U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6093158735705189789U;
            aOrbiterK = RotL64((aOrbiterK * 7453778295800853653U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17461243886150519249U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15456408913739900718U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16093292401746174671U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 37U)) + aOrbiterC);
            aWandererI = aWandererI + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 19U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterG, 51U));
            aWandererE = aWandererE + ((RotL64(aIngress, 6U) + RotL64(aOrbiterK, 4U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 6U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30434U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 31038U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29057U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 32242U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 36U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererF + RotL64(aCross, 54U)) + RotL64(aCarry, 41U)) + 13481227414590594621U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 11U)) + 17425964381118918026U;
            aOrbiterF = ((((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 4792004356135956581U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 11926849936000639098U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 3U)) + 990697329347742142U) + aNonceWordC;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9307721505373076588U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17605732738841908719U;
            aOrbiterF = RotL64((aOrbiterF * 13123627214143336281U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13110764518634187439U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 17970109897810645911U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10395095143998920213U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10273133817644703654U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11239046688920468137U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5197802934333553327U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8355821483275763145U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15522151127786049345U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4844278537850520413U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5381663179722418112U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 9551368011768104906U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 14202470972121732997U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 39U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterI) + aNonceWordL);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            aWandererC = aWandererC + ((((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordE;
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

void TwistExpander_PickleBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8E53948C22F1CD75ULL + 0x8119506B1D67F5E8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB9F698F1C32C8987ULL + 0x8A49766B4BF1F8E7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x828DB0D69F446F51ULL + 0xB7AE64CF45982764ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA20DAD5522D16615ULL + 0x85AE9B680404E04AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9F48623BBCA62969ULL + 0x9955F46AF5B3181AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFCB66266FCF28E83ULL + 0xF7E67B7BC6A67E43ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB25BABB022FF4CB5ULL + 0x8C8D63620ADA9524ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB2944477DE74869BULL + 0xEFFD2C79199B34A9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x81188B459241ED03ULL + 0xDB68BC49F315F823ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD8605C71B0A45A81ULL + 0xEF9DFB2ED4A4A2EAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD885AF276AFE8A2DULL + 0xFD0270DC18438911ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9B65AEDBEA18C0E5ULL + 0xA77B5DDB0AE97038ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA1A0C9D3B948726DULL + 0x97EF8B96068A5FC5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x99E6C0E1E32EFAA5ULL + 0xA3EFC67E60B3B2C5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8FC791EE54FCA5FFULL + 0xB7025D2811284C2FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA8FE68E670F6220FULL + 0xFD70BF5201B618FEULL);
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
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4705U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7218U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 804U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 2765U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCross, 18U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 60U)) + 12426357877879529292U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 12604900366173639176U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 13511119007338929401U;
            aOrbiterC = (aWandererB + RotL64(aCross, 47U)) + 9878720081166788060U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 5U)) + 15463195409806395076U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 6407922778852833423U) + aNonceWordP;
            aOrbiterE = (aWandererI + RotL64(aScatter, 23U)) + 7690427254160734016U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 18030974031722143619U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 17983938038322737041U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12479365337221685413U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16605512170117753884U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 681802273302348322U;
            aOrbiterJ = RotL64((aOrbiterJ * 14608920184802647123U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15550312921312083819U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17824154101711884508U;
            aOrbiterK = RotL64((aOrbiterK * 7358612830654795357U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1939207786756735430U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3132864634777826569U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 13606281919426730325U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12822929773923954849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16576106045887115660U;
            aOrbiterA = RotL64((aOrbiterA * 16370914370769903051U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2398825881649235260U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13700821892926092479U;
            aOrbiterC = RotL64((aOrbiterC * 10830623703416956043U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2439833784883391606U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15870638514107637833U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3797380922767479287U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterC, 60U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 5U)) + aOrbiterK) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 53U)) + aOrbiterC) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 39U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordP;
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13908U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 8676U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9093U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13310U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 13U)) + 826930775230515406U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 5137814617363250861U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 21U)) + 14761561947426681616U) + aNonceWordH;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 29U)) + 12773023438753662590U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 60U)) + 7331345852207096322U) + aNonceWordA;
            aOrbiterD = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 3899381212671247460U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 10072004147620068599U) + aNonceWordJ;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3424585039401897560U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8246760141625966321U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 11478879365443736383U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3655992860610853290U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 11154618022505863898U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4791494171286145231U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15629361991059709973U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10842068502278489664U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17223002513104960799U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5571312349016336686U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 589313823745748879U;
            aOrbiterA = RotL64((aOrbiterA * 1356685926549786027U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13633457935771935260U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12684602052812183096U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4689206269919806711U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5711307583717354204U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7181854170553728211U;
            aOrbiterD = RotL64((aOrbiterD * 9835601115561325911U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1884620014396115821U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1471516373272364262U;
            aOrbiterI = RotL64((aOrbiterI * 5126319375714848029U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterD, 11U));
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererA = aWandererA + (((((RotL64(aPrevious, 22U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 53U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 57U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterG, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordE);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22353U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 17211U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19418U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 16721U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 53U)) + (RotL64(aIngress, 12U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 12632404972795375757U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 12U)) + 5351879979055988456U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 3597737727467443413U) + aNonceWordN;
            aOrbiterG = (aWandererC + RotL64(aIngress, 19U)) + 2830846754917852318U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 41U)) + 17311925960294518018U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 2083584640523695383U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 27U)) + 15049343611387010158U) + aNonceWordH;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6443050378205811147U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6021965178697344070U;
            aOrbiterF = RotL64((aOrbiterF * 6054064448935006741U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5080289878758029976U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 576927745306972983U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 16008958833683246115U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4728489691382690859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6184355840165758855U;
            aOrbiterC = RotL64((aOrbiterC * 1515043910404156423U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11220539885798595450U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11091438724966718214U;
            aOrbiterG = RotL64((aOrbiterG * 8225347114759391961U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17184210490020062419U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2150997767099116408U;
            aOrbiterI = RotL64((aOrbiterI * 8058553821648892499U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7021953562676903717U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17159676348343312834U;
            aOrbiterK = RotL64((aOrbiterK * 13877284519668483549U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10367891770525239784U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11922478487264201233U;
            aOrbiterJ = RotL64((aOrbiterJ * 9195137452661956029U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 5U) + RotL64(aOrbiterC, 53U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 21U)) + aOrbiterF) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + aNonceWordE) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterG, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 60U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ aNonceWordP;
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30159U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30488U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29104U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30878U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 4179952823252098240U) + aNonceWordG;
            aOrbiterG = (aWandererA + RotL64(aScatter, 29U)) + 3745613452332101749U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 41U)) + 2955689793395307176U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 5U)) + 5639060180251322019U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 7901969163853586463U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 57U)) + 2242166787816318119U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 48U)) + RotL64(aCarry, 37U)) + 5239936443960750064U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13939136954732185558U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17058884136712717463U;
            aOrbiterH = RotL64((aOrbiterH * 7222348891215482977U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18148618660054585941U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7022023484530327814U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 650100011311048589U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7722084537340095637U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11764151879690934182U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12264384877711365655U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16412785901758144708U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9666718667728274824U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 10865799822751771795U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4307127540152109364U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2457646804702647606U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6340030928007058595U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3179394870088602208U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 504977947273774249U;
            aOrbiterD = RotL64((aOrbiterD * 16190282058883481551U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16182729401018310837U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 7110817020445860609U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 13371352088428584087U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 51U)) + aOrbiterH);
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 11U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 27U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterG) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 4U)) + aOrbiterF) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordI;
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_PickleBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA1394B6C81499C01ULL + 0xABA5D0F5772F49C1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEEEAF7DB3F6AAA8DULL + 0xFC374071D3389242ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x95B036FD8385BA2BULL + 0x996BCAB0DD96B5ECULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9101CB38A0BFD5ABULL + 0xD286D7472A8A0DE3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD632FA37AE8E13F9ULL + 0x8D3D81A6D881D5DAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDD3390C99D4CA541ULL + 0xC3E435F6EDAF084CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9C5E57016C0E568BULL + 0x9DB83C8E16B960D9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA0C7A8F839127FAFULL + 0x8BAD409C1F0679A4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDBC41DB9FCA77519ULL + 0xF2D5F5ADFE3E0ED8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF6165509C16467F5ULL + 0x9A5A2708A6E081F8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x989870EA6A72CAA5ULL + 0xE0F002AE5B4DC40DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA97F7342453F489BULL + 0x903CDD9E77341435ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x806872D06B14DDBBULL + 0xCFD56E09FF7DEDC6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF8057B007B7D0855ULL + 0x929A3B6657A9B279ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8B24973226CCF383ULL + 0xE7650B31036488D8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB0B09B4D1A6D03D3ULL + 0xEF2A51FF002D792BULL);
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
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 6038U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4150U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2317U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 641U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCross, 13U)) + (RotL64(aIngress, 27U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 37U)) + 12206125048349568300U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 20U)) + 5843520589343188818U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 3U)) + 12195046124287121687U) + aNonceWordL;
            aOrbiterB = ((((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 16769779119214020640U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 5257603646260695833U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 11U)) + 8523523946234886745U) + aNonceWordJ;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 7316024684200084096U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11996978575084115207U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15491711479085513628U;
            aOrbiterI = RotL64((aOrbiterI * 15136690392026011819U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6036648530996821484U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 926323222234121863U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 6639661141258803779U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2700323841295743492U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5852273765810284935U;
            aOrbiterH = RotL64((aOrbiterH * 16665696735016345215U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11697397483133538067U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17777142964957007194U;
            aOrbiterD = RotL64((aOrbiterD * 6338967222543284999U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10892176201151170298U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11759700374509499684U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14247697264744736081U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11343756773329590643U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15785048929757652350U;
            aOrbiterB = RotL64((aOrbiterB * 17208103574389502597U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 7508839228498497238U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13088508510402094665U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 15730279447009669103U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 22U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 28U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 20U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 53U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordN);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // read from: aExpandLaneA, aWorkLaneD, aWorkLaneC, aWorkLaneB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9814U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 8455U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14124U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((aIndex + 13377U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 26U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 11U)) + 18087125778766689269U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = ((aWandererA + RotL64(aCross, 29U)) + 13710545066503235196U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aIngress, 39U)) + 1701939704736254645U) + aNonceWordF;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 50U)) + RotL64(aCarry, 21U)) + 8064093611384019909U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 16623332751533885431U) + aNonceWordM;
            aOrbiterH = (aWandererD + RotL64(aScatter, 21U)) + 15590129153794910109U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 7413312683079107383U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4186064478651458810U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5501191643940735954U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14254804649177125269U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 11064645242200570835U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13825922087298055833U;
            aOrbiterB = RotL64((aOrbiterB * 7529317892716108867U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5944980709887369970U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8181136916070569646U;
            aOrbiterJ = RotL64((aOrbiterJ * 395183021205661827U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15442336949157292482U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11580554435240641337U;
            aOrbiterK = RotL64((aOrbiterK * 6654637892858767739U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11240018128174598322U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2027565596050777471U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18048186560314431815U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 16425887196883725233U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16828683527588834095U;
            aOrbiterH = RotL64((aOrbiterH * 17746289103235902485U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9923829146479008804U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6669171007279929454U;
            aOrbiterG = RotL64((aOrbiterG * 681823450939955099U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 56U)) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterK, 35U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 5U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 50U) + RotL64(aOrbiterC, 47U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordE);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneD, aWorkLaneC
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21274U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 24121U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18837U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((aIndex + 24248U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 58U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 3U)) + 2225397913940961213U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 43U)) + 8342544893601343643U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 29U)) + 162922186381417187U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 21U)) + 11660218373710972210U) + aNonceWordB;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 35U)) + 14909034764605802354U) + aNonceWordP;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 16776955237009701511U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 5834487809188925253U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1498492772767040320U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4161765458781579617U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15535994410289065281U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10511923076962447765U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8575954471692620021U;
            aOrbiterA = RotL64((aOrbiterA * 12526744988828982731U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6536325446331340573U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1790628986900286346U;
            aOrbiterC = RotL64((aOrbiterC * 5262997114200816715U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2623814807619278590U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 11676970995834706612U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 10057461115132434901U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13836786354224256591U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6293096163612129260U;
            aOrbiterD = RotL64((aOrbiterD * 8977954126326217153U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4271144764978661248U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15938494256992560202U;
            aOrbiterH = RotL64((aOrbiterH * 10004841288382726739U), 53U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 11038155227307702976U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12408749795071243930U;
            aOrbiterI = RotL64((aOrbiterI * 5527720475032868855U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterD) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 51U)) + aOrbiterA) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            aWandererD = aWandererD + ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 28U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 51U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneD
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32142U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 31323U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29823U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30010U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 44U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 18255347001097480328U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aIngress, 56U)) + RotL64(aCarry, 5U)) + 13679246790311505735U) + aNonceWordE;
            aOrbiterC = (aWandererG + RotL64(aCross, 43U)) + 10565839529765027116U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 13U)) + 14327172566224769901U) + aNonceWordL;
            aOrbiterA = ((aWandererK + RotL64(aCross, 5U)) + 16239024612038195174U) + aNonceWordJ;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 13800012174212131890U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 27U)) + 13900288860157577583U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4144386119777112740U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3154558262670631372U;
            aOrbiterC = RotL64((aOrbiterC * 13236911910092437063U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 7456728543137614001U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11709519851158935384U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7016689518570071587U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15607438907832240304U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9276575329661725624U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8879744070762412745U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6459435969129449226U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6442382118416542275U;
            aOrbiterA = RotL64((aOrbiterA * 2921027306686588233U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12117432107282150865U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6831279293184793243U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2435360641135249073U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9520022957804572889U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8322178689474588679U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 1627707191467537115U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4162401591586869316U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8994015844714895961U;
            aOrbiterI = RotL64((aOrbiterI * 15421910378057951895U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterD, 29U));
            aWandererF = aWandererF + ((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 41U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_PickleBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDE4A7176D0D47AD7ULL + 0xAEE3C6B9AD091834ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x93F3FC07FCE31F47ULL + 0xF03EAACAB3FDBF0CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC47D9118B2E18CBFULL + 0xE3FA00DE47DDB901ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA669ABBE7E9DA595ULL + 0xF8459BA72A185D62ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE1425731E3A391ADULL + 0x9D018783CEECD415ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD935942C4B52B8D3ULL + 0xD8C71FF6E6FE35D8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9B15C9BC10640BCFULL + 0xF4931B51582909DFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x98B64CC558A8F40BULL + 0x8FEF1F799F1299FFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAAE30C05A7364CA5ULL + 0x83C09D7A235C6C2EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9B8CFA99D0CBE4C1ULL + 0x87695C2ABB9E5304ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD02CE7F050634035ULL + 0xC5599590B1D33BB2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF634B9A434949C4DULL + 0x855961DED63EB784ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC5F5EADBBEC2CB13ULL + 0xEAC381C6C13C66F9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xACA1F02C8CCA95DFULL + 0xA0ED0743C8B1536AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x909EC24248E8AB41ULL + 0xB801CB8756A14D76ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF76D15852ECDA27BULL + 0xB4E4A42B0BC34684ULL);
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
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7955U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 5288U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1238U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 7674U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 22U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 47U)) + 15188686795415908074U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 29U)) + 17310049041983079779U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 52U)) + 8246925977992441471U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 8644260919918112781U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 27U)) + 13401663736874819483U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 35U)) + 7940358935238314973U;
            aOrbiterD = ((((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 13278990328548007839U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererC + RotL64(aCross, 54U)) + RotL64(aCarry, 53U)) + 11346868298353840706U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 13U)) + 2374077904806833579U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 41U)) + 6978903378645019166U) + aNonceWordO;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 5U)) + 11951633297870965212U) + aNonceWordJ;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17398460995357409673U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1215437945597836770U;
            aOrbiterA = RotL64((aOrbiterA * 9322970054123481621U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 1878751468043972239U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5343002808239712390U;
            aOrbiterC = RotL64((aOrbiterC * 11878640995447558811U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9884918450053276861U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15894599082080422550U;
            aOrbiterB = RotL64((aOrbiterB * 8359936745539546131U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13917339232771145459U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 18101134009493720683U;
            aOrbiterJ = RotL64((aOrbiterJ * 15835859435306756387U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3830086372356903769U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15894394599564584010U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9513921913446609263U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5127590955274245812U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9410946933309720054U;
            aOrbiterE = RotL64((aOrbiterE * 14507476989423060561U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15544384157294987085U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 998801294460434123U;
            aOrbiterG = RotL64((aOrbiterG * 5946968142746472745U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16442095194965452163U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14294936349037516932U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14655345374740882581U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16680659892463349201U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10921918150041635666U;
            aOrbiterH = RotL64((aOrbiterH * 2908474941036821745U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15350264522133299871U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16413848767507968239U;
            aOrbiterI = RotL64((aOrbiterI * 10226942289998651355U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11963105565077056299U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15188686795415908074U;
            aOrbiterK = RotL64((aOrbiterK * 13002484121826831091U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 13U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterG, 34U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 46U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 23U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 26U) + aOrbiterE) + RotL64(aOrbiterD, 6U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 29U)) + aOrbiterK) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 46U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordC;
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11818U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15802U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12788U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 11699U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 56U) + RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 5U)) + 1457104756581596530U) + aNonceWordK;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 6127240317844622874U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 21U)) + 16492290056044189421U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + 10963676850938416468U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 11U)) + 4872917367399752405U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 51U)) + 15218882377875616148U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 35U)) + 5934166612122118251U;
            aOrbiterF = (aWandererK + RotL64(aCross, 13U)) + 14215280930872003003U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 43U)) + 11428034799044600979U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 18U)) + 5453003654321728726U) + aNonceWordE;
            aOrbiterK = (aWandererD + RotL64(aCross, 29U)) + 14273775120265649389U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 328723770018440271U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13032190719588211088U;
            aOrbiterG = RotL64((aOrbiterG * 13363368478932798315U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2386881543033598494U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1649501123340887116U;
            aOrbiterJ = RotL64((aOrbiterJ * 11148976582360499033U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16462401546754210583U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1510579201823042227U;
            aOrbiterE = RotL64((aOrbiterE * 16287912400104043275U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6889066000014251983U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11324594596597724357U;
            aOrbiterB = RotL64((aOrbiterB * 15344987814648586023U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12237796033168436537U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17306069670330000343U;
            aOrbiterA = RotL64((aOrbiterA * 3167451351403385259U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14197284538008811658U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4754134852883071927U;
            aOrbiterC = RotL64((aOrbiterC * 3484427259538998699U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17201907781639753736U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8318419319239859855U;
            aOrbiterI = RotL64((aOrbiterI * 10320390501983802091U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 16012488623961565780U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15583721012865354925U;
            aOrbiterD = RotL64((aOrbiterD * 10656414363201743961U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14680351201973315018U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14483973292275372321U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 9279222721410811027U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16324317860030681248U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7038506963317910910U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2960451734542956767U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12767672960346001218U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1457104756581596530U;
            aOrbiterK = RotL64((aOrbiterK * 1560375242310194691U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + aNonceWordJ);
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterD, 47U));
            aWandererH = aWandererH + (((RotL64(aIngress, 18U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterC, 5U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 44U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 44U) + aOrbiterJ) + RotL64(aOrbiterE, 37U));
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 54U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17165U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17060U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21995U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 21607U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 34U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aScatter, 13U)) + 17912271996338180948U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 19U)) + 13259276608841847058U;
            aOrbiterI = (aWandererF + RotL64(aCross, 23U)) + 16225936008657276089U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 41U)) + 2243058962151834071U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 10637439274127347861U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 44U)) + RotL64(aCarry, 3U)) + 15312219216405992627U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 11U)) + 2393933972129878613U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 4327069337247976513U) + aNonceWordC;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 35U)) + 8307656353434167837U) + aNonceWordE;
            aOrbiterD = (aWandererD + RotL64(aScatter, 47U)) + 17299145556933889336U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 26U)) + 14458100581172798164U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6410095654927998067U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6168964796264687686U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16218071040190475953U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3667999465041020730U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16021552859323602007U;
            aOrbiterC = RotL64((aOrbiterC * 6427266472526362663U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12941668202330045095U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4222032891850449934U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17292856787431308097U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1346342592002730785U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16860611785008118820U;
            aOrbiterE = RotL64((aOrbiterE * 384963420804756607U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3193572711804730241U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5866881282680588589U;
            aOrbiterB = RotL64((aOrbiterB * 9226331800853634597U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17180332731328479126U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10222097519535882241U;
            aOrbiterD = RotL64((aOrbiterD * 9422887302872778795U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8863502179821584859U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14872318155712512999U;
            aOrbiterH = RotL64((aOrbiterH * 11830641277356873233U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 16478790641892781150U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8414944141232294781U;
            aOrbiterF = RotL64((aOrbiterF * 17443775794621154023U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13204056527590476037U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15084952142545813228U;
            aOrbiterJ = RotL64((aOrbiterJ * 17183888602469193015U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13051035678904490854U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17565188004293304987U;
            aOrbiterA = RotL64((aOrbiterA * 12785271107667631897U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 814245676602237400U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17912271996338180948U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14557769257469623169U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterG, 29U));
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterG, 34U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterG, 57U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 60U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterD, 21U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterG, 39U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererD, 24U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30449U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29212U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26875U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 29638U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 20U)) + 10038936806177516123U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 35U)) + 1773168435195292638U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 27U)) + 10655711161526628072U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 5U)) + 14422295664639740437U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 4125228715513159576U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 57U)) + 3670449653158650845U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 17553727567180813057U;
            aOrbiterB = (aWandererF + RotL64(aCross, 47U)) + 5111401772713882743U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 39U)) + 7688573124662314413U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 3U)) + 9438375825507814395U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 44U)) + RotL64(aCarry, 41U)) + 14177477039902118886U) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16329942595859623928U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3990536794006836672U;
            aOrbiterJ = RotL64((aOrbiterJ * 579024714339065373U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5072881436583180756U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16789727877867289997U;
            aOrbiterI = RotL64((aOrbiterI * 8766246302636197905U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17313956922306689438U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11530878396329822041U;
            aOrbiterD = RotL64((aOrbiterD * 11356860047841383129U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3612616532321160196U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4172189825359187763U;
            aOrbiterA = RotL64((aOrbiterA * 12938945495299393177U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8677279703778052804U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1912172980909479362U;
            aOrbiterB = RotL64((aOrbiterB * 10053289257955474143U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1460085850227494500U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12116763868122868147U;
            aOrbiterK = RotL64((aOrbiterK * 6076945628020280957U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17571840610366424432U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15581362592611080868U;
            aOrbiterH = RotL64((aOrbiterH * 1129054058044872003U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14434700039977611666U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 4534294602623329152U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5860911553425182045U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 865998255725903702U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16407778704555344108U;
            aOrbiterC = RotL64((aOrbiterC * 15571344643129797977U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1948990288894429805U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 18218556219056835250U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 16574160087642377293U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1309229265173143398U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10038936806177516123U;
            aOrbiterF = RotL64((aOrbiterF * 12954594462760207923U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterB, 57U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aCross, 54U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterK, 60U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterE, 19U));
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterD, 47U));
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 41U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterA, 11U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterF, 50U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 10U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordH);
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

void TwistExpander_PickleBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA897B9474F6E2D03ULL + 0xA281B219F2D2AE3DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8DF34BD800C56775ULL + 0xA11E2C60D6A14BB8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEEBB917567E80B0FULL + 0x84CA22B5AE9D4C4EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE2928BC847005929ULL + 0x9AA77C7E5342E4F8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x84E5E1D8E5DBA737ULL + 0x8235161BF0089934ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF1AA93ADB05FAB45ULL + 0x81D5D1E99CA79B3AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8C741DF81469F625ULL + 0xA93FC75B84862DD9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD85D4980A86CAF83ULL + 0xB123196098AAC330ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEA1D426623F5FDE1ULL + 0xD1BA4246B09C6439ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8840755D14FD4C57ULL + 0xC212FD0D1D131490ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB7A90BB408D1D6FBULL + 0x9E9E869E09C8E78AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAECCEC12B91A9EA5ULL + 0xE3293C3696DE6340ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB0DC85658F9DD877ULL + 0xF67C4520AB3D532FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBC6D6EAFB17A755BULL + 0xA868FD9D03319D87ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC64C285E0777E3F1ULL + 0x9753ED7020839190ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD246946A2D92808FULL + 0xC9AF4E5D06966C92ULL);
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
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3866U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1550U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2361U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1347U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 60U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 43U)) + 1142447269198373880U) + aNonceWordD;
            aOrbiterH = (aWandererH + RotL64(aScatter, 3U)) + 10581460640040336191U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 14703062773878202900U) + aNonceWordG;
            aOrbiterF = ((aWandererK + RotL64(aCross, 48U)) + RotL64(aCarry, 41U)) + 15737525756286914746U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 19U)) + 16178774478273186999U) + aNonceWordE;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 23U)) + 2514897053906809160U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 13702496607592508464U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 27U)) + 18030885275418337965U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 56U)) + 5241783876161655984U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2807052676283587925U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8022804576763271327U;
            aOrbiterK = RotL64((aOrbiterK * 11727096043219370577U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15597099852232205860U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1538435607932096400U;
            aOrbiterA = RotL64((aOrbiterA * 7900752511710516981U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 11147868774413615365U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9325213746830411568U;
            aOrbiterJ = RotL64((aOrbiterJ * 561819005818948769U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13792300423550555634U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3134856508983945719U;
            aOrbiterD = RotL64((aOrbiterD * 4271845067763664863U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8654966018053784882U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8937113935476779267U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7386875687217705855U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4135676350355234788U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11407912615743682678U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2773506587480714695U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10966950663872392059U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6686634993700944582U;
            aOrbiterG = RotL64((aOrbiterG * 2509459942163678241U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 14154407529749257990U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18054640398549782388U;
            aOrbiterH = RotL64((aOrbiterH * 7830759861389060149U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14623473030642960240U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1857945571104460086U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 18039903315045620079U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 38U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 58U)) + aOrbiterG) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aCross, 18U) + aOrbiterE) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 11U)) + aOrbiterH) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + RotL64(aOrbiterK, 27U)) + aOrbiterG) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 40U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9015U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7404U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6768U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((aIndex + 6436U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 39U)) + (RotL64(aIngress, 10U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 5041131702736607991U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 9295010428212681446U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 6U)) + RotL64(aCarry, 3U)) + 6235875895358766017U) + aNonceWordF;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 29U)) + 2622227802531866918U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 41U)) + 3888894734834524972U;
            aOrbiterE = (aWandererF + RotL64(aCross, 21U)) + 241682012014701753U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 37U)) + 15758000422451568079U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 60U)) + 2061944548396976912U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aPrevious, 47U)) + 8177144990755754531U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 554978075608818497U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 250408260560714933U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1295379390497107727U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8700027645880997552U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10026130047465480902U;
            aOrbiterJ = RotL64((aOrbiterJ * 12417270861933696623U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9785843014096326696U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9998582683258411251U;
            aOrbiterB = RotL64((aOrbiterB * 7197956237569462269U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13817734599383455151U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6647207154174092691U;
            aOrbiterA = RotL64((aOrbiterA * 1578528131687283531U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4957715980509035719U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4994885315786213197U;
            aOrbiterK = RotL64((aOrbiterK * 5676683798126497011U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5072908311783966503U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5535039946192891515U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 2989412783482309753U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6594577050344146271U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8750154123258714856U;
            aOrbiterC = RotL64((aOrbiterC * 6942158167127532003U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 3514769314840874873U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8626045200273524281U;
            aOrbiterE = RotL64((aOrbiterE * 4315441782689789689U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8524870284841706517U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1841819423572964209U;
            aOrbiterF = RotL64((aOrbiterF * 9802481758007234681U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterI, 46U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterC, 3U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 54U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 35U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterA, 53U)) + aNonceWordH);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 37U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 60U)) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14604U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14643U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15656U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13106U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 13U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aPrevious, 3U)) + 2177539223979303669U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 51U)) + 3962004686551521471U) + aNonceWordL;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 56U)) + RotL64(aCarry, 13U)) + 8457602312617147662U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 18011802451816510632U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 39U)) + 9046101759168876832U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 11135620637431969597U) + aNonceWordA;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 47U)) + 15913029940697999701U) + aNonceWordE;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 14U)) + 16304193109948135982U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 43U)) + 13208892298820080981U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4182377898949419225U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13970137023071326151U;
            aOrbiterD = RotL64((aOrbiterD * 9075061559681739865U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8402396284835248583U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 8859190834060657829U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 13552418608113716117U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9760005337757990392U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14108277760135744897U;
            aOrbiterC = RotL64((aOrbiterC * 4474681104256093885U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12226316121949012350U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3456392186754113960U;
            aOrbiterH = RotL64((aOrbiterH * 8704729827929941215U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5004087958637038973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7176881295123125567U;
            aOrbiterE = RotL64((aOrbiterE * 15272157962928021009U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10889800478505074438U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13728832441482547824U;
            aOrbiterF = RotL64((aOrbiterF * 17588477761978646139U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17345665880706866772U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 301139993853297566U;
            aOrbiterJ = RotL64((aOrbiterJ * 5812445396758354505U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2061389844760610160U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 13631862266139238355U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 143613352104722701U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10767186080827509622U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4893486019456886013U;
            aOrbiterA = RotL64((aOrbiterA * 5194746459545610901U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 20U));
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 43U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 48U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterA, 57U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 11U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 30U) + RotL64(aOrbiterA, 4U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterH, 37U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 54U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // read from: aExpandLaneA, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20996U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 20799U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21669U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20150U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 58U)) + 18144572925667544139U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 39U)) + 5659758077574059728U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 13U)) + 6343330616999166392U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 53U)) + 17754639838410839447U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 43U)) + 9451843819849581729U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 7957854457197462212U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 6U)) + RotL64(aCarry, 37U)) + 1461994799722205010U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 18002214276252170177U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 35U)) + 14689869073147027164U) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3978104368003440293U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8512135845221335386U;
            aOrbiterG = RotL64((aOrbiterG * 10506667163729414667U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1477533446382953439U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 2166717790929947990U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 6538884492418324461U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8082437060686606995U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4363687722464700362U;
            aOrbiterJ = RotL64((aOrbiterJ * 7199165810993478887U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15782763348014924206U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8572509150015960728U;
            aOrbiterE = RotL64((aOrbiterE * 3340528604891897779U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12248271773316742521U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9602078627638561949U;
            aOrbiterC = RotL64((aOrbiterC * 1860631869877427405U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17244849374768558859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1030743048280579012U;
            aOrbiterA = RotL64((aOrbiterA * 10858949914285817051U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17722342363541914280U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15667504059789880034U;
            aOrbiterI = RotL64((aOrbiterI * 15872269872168533709U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12645332941998550794U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 9938135244509986497U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16548185968987392957U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 4024609904162105979U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6732064218696157303U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 3815409766145891393U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (RotL64(aOrbiterD, 14U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 39U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterI, 21U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterA, 10U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterA) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterE, 5U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterG, 60U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordK);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 5
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25657U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27248U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23996U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27155U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 12U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aScatter, 23U)) + 2915859148137000694U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 210680583721444425U) + aNonceWordG;
            aOrbiterA = (aWandererH + RotL64(aIngress, 46U)) + 6668118118775650387U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 51U)) + 15794200818099010989U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 57U)) + 6565076707062828369U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 37U)) + 16323164497808856719U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 7965435318816716560U) + aNonceWordH;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 4U)) + RotL64(aCarry, 51U)) + 7390281030573369017U;
            aOrbiterG = (aWandererE + RotL64(aCross, 19U)) + 2269738866911824875U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9664014216039993873U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 18284857398028357633U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 8402008251343393737U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 367667619795303009U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7935945060956274197U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5481786693511955209U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16683666162337789540U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10655658270998102390U;
            aOrbiterI = RotL64((aOrbiterI * 15231596813382239841U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8307037916581540297U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3247742749860703524U;
            aOrbiterG = RotL64((aOrbiterG * 15052136713218656641U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10446792483683818139U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16374602929344972364U;
            aOrbiterK = RotL64((aOrbiterK * 12599903932725787599U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2411334498322777183U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1093701164116833765U;
            aOrbiterC = RotL64((aOrbiterC * 13129220206835381729U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17018480952982840635U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17348395690080029814U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6212591395713433257U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16111252311283623152U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12776492920397785951U;
            aOrbiterE = RotL64((aOrbiterE * 6136009241593081821U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12214538600808144816U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10043377462096783363U;
            aOrbiterB = RotL64((aOrbiterB * 14639467375095185877U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterI, 36U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterB, 53U)) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 3U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterC, 18U));
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 57U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 10U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29936U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 27757U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29882U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31519U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 53U)) + 8604208734152026945U) + aNonceWordL;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 1374329953253889829U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 58U)) + RotL64(aCarry, 19U)) + 5779278910548228339U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 17670451230882805140U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 23U)) + 8193848740764866860U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 39U)) + 15801168428145650104U;
            aOrbiterD = (aWandererD + RotL64(aCross, 5U)) + 2584718176087499066U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 18U)) + 14950366247822737997U;
            aOrbiterI = (aWandererK + RotL64(aCross, 35U)) + 9779293225265670135U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8688968319288372383U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13665723186950342601U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 292035540396910837U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9395428688359973510U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2152719218018108418U;
            aOrbiterJ = RotL64((aOrbiterJ * 15271961483518392671U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1350324137411377992U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8729317951386057921U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6008790836417785083U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6317310451893678411U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10175620379041384281U;
            aOrbiterC = RotL64((aOrbiterC * 14079679617394330781U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 1203082119358827708U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 523869107818193101U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4629501113595689157U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4028324959540432983U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15447631947468213912U;
            aOrbiterE = RotL64((aOrbiterE * 6037306615787729185U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14225888694733041031U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11925000696281947629U;
            aOrbiterG = RotL64((aOrbiterG * 4337022940520411253U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15015531024930608745U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16752579225076943550U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15551083683579981439U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2432733494869267901U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10103430321388601485U;
            aOrbiterF = RotL64((aOrbiterF * 18372919379972432569U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (RotL64(aOrbiterF, 14U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterA, 28U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 37U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 43U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterE, 51U)) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 14U)) + aOrbiterD) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 23U));
            aWandererG = aWandererG + (((((RotL64(aCross, 23U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneD[aIndex] = aIngress;
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

void TwistExpander_PickleBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDB9755C1629A9BA3ULL + 0xC664FFDDEF2FD8DBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA7A93FA67CF10415ULL + 0xB8EC10AF40990D19ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9D0378F7743BC961ULL + 0xA3640FA96E3AE7ECULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA686D960B5AF6453ULL + 0xD3C28B7C278F1BC6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE9DAC23764DA7A35ULL + 0xBFDD8E71BE9664EBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDBF1C9908F75F2F3ULL + 0xE0CD213203EB1B27ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE0A0C74B550B4579ULL + 0xDDBB356329EC072CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEE4D72B6A87E470BULL + 0xBF6BA0B6F422E0CDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCBC94FC84B680EADULL + 0xB9F8E1F016A70A2AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x93EC18DAAE414B35ULL + 0xF94BC4A1F6964612ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x80A5E19D73860943ULL + 0xA15F4587ADEBA83AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA6A04EB79EC5BDBBULL + 0x8DA80AF8EA683EAAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF38DC70830778B65ULL + 0x9AB8633E64D43552ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC684858A3A6297EDULL + 0xD4156691A9BA4207ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8BFD811A1A92ED7BULL + 0xA3A06B23A02F9EBBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8AF479663D1F1EF7ULL + 0xC49AA778871F3BB9ULL);
    // GSeedRunSeed_A seed_loop_a (start)
    {
        // GSeedRunSeed_A seed_loop_a lane group
        // read from: mSource, aKeyRowReadA, aKeyRowReadB, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_a loop 1
        // read from: mSource, aKeyRowReadA, aKeyRowReadB
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2747U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 2148U)) & W_KEY1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 531U)) & W_KEY1], 4U) ^ RotL64(mSource[((aIndex + 941U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 21U)) + 7075016829833562104U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 30U)) + 8783765886115517036U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 2996723892384565829U) + aPhaseAOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 37U)) + 9494134707342189476U) + aNonceWordB;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 11U)) + 5052642981395679904U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 8766787055127962238U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 4467211954388738079U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8030255604633658608U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16962408063455702251U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11171737929747471631U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3768222186567699076U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14930990410207899871U;
            aOrbiterI = RotL64((aOrbiterI * 10930005786146268241U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14179761938395502502U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1879084742719898108U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 16783034788172670121U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5535012408925981515U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12792553516710295939U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8577530993755159329U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8979253163346099252U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 5559189896063990740U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 8832485423727331621U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13937564337299044079U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2393376759689394948U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2352815657830413941U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12647519563697356479U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10946871249960389549U;
            aOrbiterD = RotL64((aOrbiterD * 6272580371881237173U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterI, 34U));
            aWandererG = aWandererG + ((RotL64(aIngress, 34U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererA = aWandererA + (((((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 21U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordO) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + aPhaseAWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // read from: aWorkLaneA, mSource, aKeyRowReadA, aKeyRowReadB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9831U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5601U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8861U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[((aIndex + 10765U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 60U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = ((((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 3684295017013759987U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 48U)) + RotL64(aCarry, 51U)) + 6740408842457292881U;
            aOrbiterI = (aWandererA + RotL64(aCross, 21U)) + 4563975890702399441U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 57U)) + 797804144825287940U) + aNonceWordP;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 5U)) + 2763779540450101303U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 13211846164102089685U;
            aOrbiterE = (aWandererG + RotL64(aCross, 11U)) + 15214578447281401982U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13745208628754232427U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17358621225969190747U;
            aOrbiterI = RotL64((aOrbiterI * 5325024317338823061U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 779739369960480023U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 4370963533701407813U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3123135216876641039U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6061333005507739975U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3589705340762734456U;
            aOrbiterK = RotL64((aOrbiterK * 16499293983611196967U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10607697666369230567U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9356757995305239271U;
            aOrbiterJ = RotL64((aOrbiterJ * 10945513661439954731U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10093033335903048138U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11037328061699834100U;
            aOrbiterH = RotL64((aOrbiterH * 11189760551792389605U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 558431161176115540U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17795680919453449358U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3910117359996283803U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6096779391116214109U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 17594243286880690775U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12655610181937429915U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 6U)) + aOrbiterH) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 4U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterI, 27U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterH, 39U)) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 57U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // read from: aWorkLaneB, aWorkLaneA, aKeyRowReadA, aKeyRowReadB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14982U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12301U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16172U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 12284U)) & W_KEY1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 43U)) + 8402620908307642697U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 47U)) + 11347672014525086047U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 27U)) + 2816462912503401876U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aWandererG + RotL64(aCross, 57U)) + 6940159795470696093U) + aNonceWordF;
            aOrbiterD = (aWandererD + RotL64(aScatter, 11U)) + 9134692490095883851U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 36U)) + RotL64(aCarry, 5U)) + 4999455497008026526U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 5992451460350651332U) + aPhaseAOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3417087346651371924U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3612773820086198270U;
            aOrbiterK = RotL64((aOrbiterK * 5519856345435871169U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 463398077083428570U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11249391303705089012U;
            aOrbiterA = RotL64((aOrbiterA * 7106735772303292983U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17027535139825739501U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 568131384979596481U;
            aOrbiterH = RotL64((aOrbiterH * 5683451044852895957U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4793712537158004047U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10415170179135963622U;
            aOrbiterE = RotL64((aOrbiterE * 13729564030210361415U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2391473979460065630U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4240058362680064261U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 12375884373396400889U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9963957011090031698U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3325305624067445525U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3128542681461806309U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2094945647665114693U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10703615640774042674U;
            aOrbiterC = RotL64((aOrbiterC * 12641986098450423751U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 27U)) + aOrbiterH) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 4U) + aOrbiterA) + RotL64(aOrbiterC, 13U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterI, 43U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterH, 51U));
            aWandererG = aWandererG + ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterE, 4U)) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // read from: aExpandLaneA, aWorkLaneB, aWorkLaneA, mSource
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16926U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19498U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19837U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 21696U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 34U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 5573188770530340913U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 1431772230889897111U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 3U)) + 4809192776429682319U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 5576603692574369341U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 13U)) + 2720143226007220386U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 35U)) + 17220328778565331629U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 58U)) + 9629485808442089423U) + aNonceWordL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1136998437010390983U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11893390497814523841U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5329621622743089531U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1764986431917532370U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1741014798007010376U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 13414914086049500731U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12221368453236547044U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7694538641172350430U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8439120733670016501U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17472344518811560603U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3308740700728172984U;
            aOrbiterI = RotL64((aOrbiterI * 15290400462887712083U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9535358833412446771U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11192312491731312451U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 17405609148475445743U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14850451970047190039U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11932493299452443256U;
            aOrbiterC = RotL64((aOrbiterC * 7964808728820467795U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5972619895614731870U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17174497535809891690U;
            aOrbiterD = RotL64((aOrbiterD * 15471084511364572533U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + aPhaseAWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 30U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterI) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 21U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 41U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aCross, 12U) + RotL64(aOrbiterD, 13U)) + aOrbiterF) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23161U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 26988U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22073U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 26044U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 29U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aPrevious, 51U)) + 6521330037475130256U;
            aOrbiterD = ((((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 12611880456055428940U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 12061611078130934708U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 1558112410801116984U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 42U)) + 10509115227850160786U) + aNonceWordH;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 21U)) + 4045915960688792066U) + aPhaseAOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 11U)) + 1196541286513243082U) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15564991032722373702U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4897765238703641798U;
            aOrbiterI = RotL64((aOrbiterI * 9693901276712946763U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 12327429514907752733U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6189189797708711636U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9017615866338877651U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6374267075282018852U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1888758503831341439U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 74387714918264257U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14956857689299491800U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14879361107223331957U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 9166712966729591953U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16086885494838105042U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8069724185844303923U;
            aOrbiterB = RotL64((aOrbiterB * 8878470736758734353U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10854345917959911439U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7078313614360332089U;
            aOrbiterK = RotL64((aOrbiterK * 9864025732292844871U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15083669236062255011U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 594879695916679116U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9852515479152735283U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterD, 27U)) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 34U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterF) + aPhaseAWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 54U) + aOrbiterD) + RotL64(aOrbiterB, 21U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordE);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31867U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 28756U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31717U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 28271U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 18U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 5171470532667965920U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 21U)) + 750549462358682403U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 11U)) + 3325689257577120525U) + aPhaseAOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 57U)) + 18031575461559790826U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 29U)) + 13874739537012288677U) + aNonceWordK;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 50U)) + RotL64(aCarry, 37U)) + 4250029868785016865U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 8211158803112611161U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1083939790236786027U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3446525462376962464U;
            aOrbiterE = RotL64((aOrbiterE * 13603702473750888213U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6973817815000417325U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15230876489676945543U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 7737039082964537651U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9359727659738755880U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8775170107816327654U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 6910680458261008653U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11958941755525038545U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16966819714283167348U;
            aOrbiterD = RotL64((aOrbiterD * 16363457661846050749U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14556087985619763243U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17915047508377045221U;
            aOrbiterG = RotL64((aOrbiterG * 6727635453185130109U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8578745677485367222U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7002181668717618866U;
            aOrbiterJ = RotL64((aOrbiterJ * 12329703532414955235U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3569939503066735457U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2956247934282522184U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9946650822131152531U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 26U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 53U)) + aOrbiterF) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterB, 37U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 6U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordC;
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneD[aIndex] = aIngress;
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

void TwistExpander_PickleBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBA0045D00C67DE91ULL + 0xC4B5B95C67F9779EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9595C5A1D0A3D941ULL + 0xF86697F2B57E604EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x90C2371EC83153FDULL + 0x96DB6F0AAE3BAD9DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA0273026F055D9BFULL + 0xE804089377D4E5B6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x99337BEFDAECE721ULL + 0xC2396D7C53C90429ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD32F67E47DBCFF09ULL + 0xBA0AC5B634038F76ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAAE9AC6C798452C1ULL + 0xD0F87D7CA678A9C6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFBE05C25EAA0828FULL + 0xCE27E185A89E63DEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBD717674A99C1C9BULL + 0xDAB8DA9F78DB9930ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xABE3D2EBDCA09ADBULL + 0xE71ACFCC4E4A6241ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9941C0B23BF7227DULL + 0xA9B7DC5C5E2E0B8AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC2CCDF33297BC417ULL + 0xD126479C9B693FF9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD9DC9FCD035E5777ULL + 0xF24BE8C51003847BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x877A8AF30814652FULL + 0xD5F7C1C780A28D27ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9377D3C8F8A3571DULL + 0x8AD34246C484016AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA3D9F6361170CCF5ULL + 0xF1E263B72E1A8158ULL);
    // GSeedRunSeed_B seed_loop_b (start)
    {
        // GSeedRunSeed_B seed_loop_b lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneA, aWorkLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aWorkLaneA, aWorkLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2998U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1985U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3618U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3843U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 10U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aPrevious, 13U)) + 16424657151168221875U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 43U)) + 17150123681886380361U) + aPhaseBOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 16041993588694572757U) + aNonceWordB;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 9871185846434828537U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 47U)) + 11227236398354430757U) + aPhaseBOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5399325217402192631U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9248828789282890454U;
            aOrbiterG = RotL64((aOrbiterG * 6733832755349139621U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9041370494203701062U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 14944424084524970764U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10283363059424655079U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5481938174456671041U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14783648629543752715U;
            aOrbiterH = RotL64((aOrbiterH * 7260164783191886395U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12355573914530445723U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9863991559011968318U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8495251211794343179U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16149688605937250965U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 106041828692026825U;
            aOrbiterA = RotL64((aOrbiterA * 12199934305374582599U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 54U) + aOrbiterG) + RotL64(aOrbiterK, 37U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 47U)) + aOrbiterA);
            aWandererI = aWandererI + (((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordK) + aPhaseBWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aPhaseBWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterF, 28U)) + RotL64(aCarry, 3U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordP);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5928U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((aIndex + 6807U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6236U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5593U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 18U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 48U)) + 7960325128608297381U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 12773836012104052042U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 11U)) + 3173972621347773016U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 3708401356314308171U) + aPhaseBOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 950774285720019449U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4170092315705438265U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17000449130864980747U;
            aOrbiterF = RotL64((aOrbiterF * 7710635557693533263U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8793910540062893860U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 520277969543516469U;
            aOrbiterC = RotL64((aOrbiterC * 4150613128885828229U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 12762214857389827271U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2932451184340207695U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7513337346940091655U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11062179998786293839U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7919119215271524178U;
            aOrbiterH = RotL64((aOrbiterH * 9053677007180081359U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1774988449597115155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3799792889466518953U;
            aOrbiterA = RotL64((aOrbiterA * 17512791286490623455U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 48U) + aOrbiterC) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 21U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 30U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14145U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14782U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13188U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 12125U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aCross, 4U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 38U)) + RotL64(aCarry, 57U)) + 9888431329297626900U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 53U)) + 2937735167534624403U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 3U)) + 17626022970343789617U;
            aOrbiterC = ((((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 5665660859333693743U) + aPhaseBOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 1060537034632076669U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 743777763907175800U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5744905970181808845U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17426701505806885785U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3545351394494002180U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4877547088414106007U;
            aOrbiterJ = RotL64((aOrbiterJ * 5416792889338547109U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11669378338379598445U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2961072441706158212U;
            aOrbiterG = RotL64((aOrbiterG * 2677988507090705371U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 13984945589234919765U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1433097875470903205U;
            aOrbiterC = RotL64((aOrbiterC * 451996840039906781U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 716415411025451152U) + aNonceWordH;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 8542286150858297810U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 9139015340823332449U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterB, 43U)) + aNonceWordA) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterF, 12U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + aPhaseBWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // read from: aOperationLaneA, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21837U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19050U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20911U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((aIndex + 18120U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 52U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 15036852811491820366U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aScatter, 13U)) + 305637140752898475U;
            aOrbiterF = ((((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 11948631574496129610U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 44U)) + RotL64(aCarry, 47U)) + 5321623592482991426U) + aNonceWordB;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 53U)) + 4075270159062690728U) + aNonceWordA;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15111580500356908928U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7244150695504160363U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2445733898697939969U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5131563519577488862U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5881954992088651371U;
            aOrbiterH = RotL64((aOrbiterH * 2424421828597294607U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12780935808751507998U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12599159643925470226U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17690046932587062701U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9466589929741834066U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6093158735705189789U;
            aOrbiterE = RotL64((aOrbiterE * 7453778295800853653U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 17461243886150519249U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15456408913739900718U;
            aOrbiterC = RotL64((aOrbiterC * 16093292401746174671U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 18U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 46U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + aPhaseBWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // read from: aOperationLaneB, aOperationLaneA, aWorkLaneB, aWorkLaneA
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 27168U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25476U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26941U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23876U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 39U) + RotL64(aPrevious, 13U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aIngress, 37U)) + 5573188770530340913U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 1431772230889897111U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 13U)) + 4809192776429682319U) + aPhaseBOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 29U)) + 5576603692574369341U) + aNonceWordH;
            aOrbiterK = ((((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 2720143226007220386U) + aPhaseBOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17220328778565331629U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9629485808442089423U;
            aOrbiterE = RotL64((aOrbiterE * 18349580416082045015U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1136998437010390983U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11893390497814523841U;
            aOrbiterK = RotL64((aOrbiterK * 5329621622743089531U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1764986431917532370U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 1741014798007010376U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13414914086049500731U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12221368453236547044U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7694538641172350430U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8439120733670016501U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 17472344518811560603U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3308740700728172984U;
            aOrbiterB = RotL64((aOrbiterB * 15290400462887712083U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 6U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterF, 56U)) + aNonceWordD) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneB
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28080U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32052U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29771U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 30198U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 12122689833405846292U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 9640400270962766788U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 21U)) + 9141937998266739071U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 12899395770434090537U) + aPhaseBOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aScatter, 42U)) + 13457918115408031842U) + aPhaseBOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15134784483576000943U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12540961268790055438U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3295706140418040089U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6306886773092764230U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13573343491337243121U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 15893457012357368707U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 8545588657348974413U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10891410570357275120U;
            aOrbiterA = RotL64((aOrbiterA * 5399310978367842841U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2877137119767060151U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9178097682386595144U;
            aOrbiterJ = RotL64((aOrbiterJ * 3524486002084427513U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15528007881855616978U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11368419529245281435U;
            aOrbiterF = RotL64((aOrbiterF * 12433207037378339309U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 24U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 43U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 23U)) + aNonceWordO) + aPhaseBWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 52U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterA, 14U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordC;
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_B seed_loop_b (end)
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

void TwistExpander_PickleBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCB4A83AB882016C7ULL + 0x83099DAC2879F373ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDB235A1006E561C7ULL + 0xBCD492919A6BC39EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAA20746D0351F203ULL + 0xBC6E543D89AEAEF0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDE57DE51C0467F45ULL + 0x98423FD59F509D2BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAEC54183B9B0C909ULL + 0xAB59A685116D9B6BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEDBE90ACC20EB847ULL + 0x9C01E6172EF34B21ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDF9AA64B3F98FC9BULL + 0xF3EA31F2630A5A83ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xADC5723BD9BD1681ULL + 0xDFE66A6FA2F773DCULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xACFA88BFCF315ED1ULL + 0x8F2F26650CEB6F7DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9DB6768FAE97051BULL + 0xC1BE2670FFF06EC0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCD6E2AA97EB348B3ULL + 0x824B5638A6121D28ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFF83FCBEF96AA027ULL + 0xC4AFC0EE63D80E67ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC3E8A854A12E574BULL + 0xD01B9C250067E2BCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB21C783A6AE206FBULL + 0xC0C30E1CC0D06E98ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD2DF5BC04E1F4E55ULL + 0xE6E83CE1B46F7583ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x95347E5618542A67ULL + 0xE62C242A61DC87E8ULL);
    // GSeedRunSeed_C seed_loop_c (start)
    {
        // GSeedRunSeed_C seed_loop_c lane group
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5972U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2455U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2773U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 1378U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 50U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aCross, 51U)) + 14249093584376402677U) + aNonceWordL;
            aOrbiterC = (aWandererC + RotL64(aIngress, 47U)) + 8756965951816492264U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 3U)) + 11221139480258176330U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 17218894445564194851U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 29U)) + 8064642692524949490U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 21U)) + 5822093203710704646U) + aNonceWordB;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 35U)) + 3217799620158102238U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 39U)) + 2613757677892120843U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 35U)) + 13647481499551657237U) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3545714196663685016U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9735422670576621521U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7276207208162697249U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3911046580637583767U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9315984027042049203U;
            aOrbiterK = RotL64((aOrbiterK * 12568550776487242469U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8926367674641729058U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11035347490524961446U;
            aOrbiterE = RotL64((aOrbiterE * 10948288997163592463U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10748158733051120339U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2467801787989056455U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 12621934274702358977U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9244415080474351390U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8517784887959492079U;
            aOrbiterD = RotL64((aOrbiterD * 17022899813765884147U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8409307332803038455U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11043806021873232950U;
            aOrbiterG = RotL64((aOrbiterG * 8294888329708842989U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17512395828450251457U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16849067939795823992U;
            aOrbiterA = RotL64((aOrbiterA * 9361991804481514337U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17541946638063238056U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11430501673960586718U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15074409630605450091U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 78307505705383302U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4834528975263832983U;
            aOrbiterH = RotL64((aOrbiterH * 17245673681686752861U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 34U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterH, 57U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 4U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterG) + aPhaseCWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterH, 41U)) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aCross, 12U) + aOrbiterD) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterF, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordM;
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8570U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11669U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16111U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11811U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aIngress, 60U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aScatter, 28U)) + RotL64(aCarry, 43U)) + 2177539223979303669U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 3U)) + 3962004686551521471U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 8457602312617147662U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 47U)) + 18011802451816510632U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aWandererD + RotL64(aScatter, 52U)) + 9046101759168876832U;
            aOrbiterF = (aWandererF + RotL64(aCross, 13U)) + 11135620637431969597U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 35U)) + 15913029940697999701U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 16304193109948135982U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 19U)) + 13208892298820080981U) + aNonceWordG;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4182377898949419225U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13970137023071326151U;
            aOrbiterI = RotL64((aOrbiterI * 9075061559681739865U), 57U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 8402396284835248583U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8859190834060657829U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13552418608113716117U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9760005337757990392U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14108277760135744897U;
            aOrbiterK = RotL64((aOrbiterK * 4474681104256093885U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12226316121949012350U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3456392186754113960U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8704729827929941215U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5004087958637038973U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7176881295123125567U;
            aOrbiterB = RotL64((aOrbiterB * 15272157962928021009U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10889800478505074438U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13728832441482547824U;
            aOrbiterG = RotL64((aOrbiterG * 17588477761978646139U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 17345665880706866772U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 301139993853297566U;
            aOrbiterJ = RotL64((aOrbiterJ * 5812445396758354505U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2061389844760610160U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13631862266139238355U;
            aOrbiterF = RotL64((aOrbiterF * 143613352104722701U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10767186080827509622U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4893486019456886013U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5194746459545610901U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 6U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 14U) + RotL64(aOrbiterA, 53U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK) + aPhaseCWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterC, 12U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 53U)) + aNonceWordB);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + aNonceWordN);
            aWandererA = aWandererA + ((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17248U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 17498U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23330U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 21305U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 35U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 60U)) + 3255291173184001106U) + aPhaseCOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 43U)) + 15308468160116255528U;
            aOrbiterC = (aWandererH + RotL64(aCross, 35U)) + 18186972408589866656U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 47U)) + 4439324265978331914U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 28U)) + 13099263173016322486U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 7041561081767500660U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 53U)) + 6196422612687812971U) + aNonceWordK;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 7664260932541281413U) + aNonceWordD;
            aOrbiterG = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 17802347823020441056U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4253107484061190446U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13799496534030645312U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 9167675060053848207U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14252892847595951926U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5663527578664291422U;
            aOrbiterE = RotL64((aOrbiterE * 18314294235895182465U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11148755959699137661U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17036900929333594592U;
            aOrbiterF = RotL64((aOrbiterF * 16041243617369003291U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2403828181385259549U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17813580350434928194U;
            aOrbiterH = RotL64((aOrbiterH * 13666780980793857831U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5623611126885414523U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7293224381174846969U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 7032561584670788117U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10602620906929686163U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 18015916257203385982U;
            aOrbiterD = RotL64((aOrbiterD * 10684090189688871993U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13592915735376305773U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13995866908043417505U;
            aOrbiterK = RotL64((aOrbiterK * 3802175869395887331U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8200465989447697618U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9866671660800629464U;
            aOrbiterB = RotL64((aOrbiterB * 2138851839905326265U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11557528777230608777U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 131060617338185060U;
            aOrbiterG = RotL64((aOrbiterG * 11068705423012265209U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 42U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 38U) + aOrbiterC) + RotL64(aOrbiterB, 58U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aPhaseCWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 43U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 48U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterG, 54U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31011U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 29803U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24883U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28144U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 10U)) + RotL64(aCarry, 13U)) + 9751314027302668907U;
            aOrbiterF = (aWandererE + RotL64(aCross, 27U)) + 12175450995523107056U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 17519694958730119552U) + aNonceWordM;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 47U)) + 9093525527925682263U) + aNonceWordF;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 57U)) + 3713831321786810138U) + aPhaseCOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 3U)) + 10108355209191835040U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 21U)) + 12956307447311314768U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 14U)) + 1904298513945877359U;
            aOrbiterA = ((((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 4658049993308574460U) + aPhaseCOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9826333658248851902U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12058666914724365134U;
            aOrbiterH = RotL64((aOrbiterH * 964233873188373939U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2516574707110528099U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13335308331049750235U;
            aOrbiterI = RotL64((aOrbiterI * 5880227828760598587U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8230749255538495304U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16536559486797811486U;
            aOrbiterB = RotL64((aOrbiterB * 7097036838156464969U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12387639130570188998U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8459259798142872020U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 8001346480955847013U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16083784052002800300U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1957284290736468379U;
            aOrbiterD = RotL64((aOrbiterD * 5046501301740813065U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7349538179311335863U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16395170077006105258U;
            aOrbiterE = RotL64((aOrbiterE * 4230485452156662763U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3317652065873784068U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5517155804799120700U;
            aOrbiterJ = RotL64((aOrbiterJ * 9789270651974719183U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5568525912112200094U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9334250662962319598U;
            aOrbiterA = RotL64((aOrbiterA * 5034887614541768961U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5641394627075994165U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13524971148931512745U;
            aOrbiterF = RotL64((aOrbiterF * 3699457147759854357U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (RotL64(aOrbiterH, 20U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterF, 19U)) + aOrbiterA) + aPhaseCWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 37U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 44U)) + aOrbiterB) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterA, 57U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 39U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 24U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 42U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_C seed_loop_c (end)
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

void TwistExpander_PickleBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8C13B31296817589ULL + 0xEA1CB2260612D366ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE1C674A4347E2433ULL + 0xE4A473015A7363C2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x91DA93A3DAE07167ULL + 0xDD9AA795133309AAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE1447BB769B9E777ULL + 0xD8A033DC693A6F3AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAA476490691C1B33ULL + 0xDAFAADA8FBB439B2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA1B10309E3419B65ULL + 0x8DD665CF5C8B93F8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE075FA30EA8F9781ULL + 0xEB4AC5FC062DBD31ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCAC698810399AB85ULL + 0xEA3C78CF2E76EC87ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE86B9948B8BE1233ULL + 0x918A1BE5811A166EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDA0E53A260894D69ULL + 0xE4D44E85B1808669ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB5572770F0F1E0FDULL + 0x9CA7DD2C3C827D6BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x92694FC86C943FDFULL + 0xA8091F377F17B26DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDF58F7B9463A042BULL + 0xFE8BA34315132BD1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x91BD9DEDE5E29F77ULL + 0xF0264D662A4B121AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8566DCA89B0EC647ULL + 0xB37972B7B849FE6EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDC33A04584ECE961ULL + 0xCB0D86FB33FBD446ULL);
    // GSeedRunSeed_D seed_loop_d (start)
    {
        // GSeedRunSeed_D seed_loop_d lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aOperationLaneA, aOperationLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_d loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3322U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 3735U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3842U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4989U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aPrevious, 29U)) + 7632760812370906911U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 6007174525479723089U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 51U)) + 3362829642521821048U) + aNonceWordD;
            aOrbiterD = (aWandererB + RotL64(aCross, 37U)) + 18009548556107978286U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 56U)) + 17880909432272697327U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 15961567935420752568U) + aNonceWordG;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 27U)) + 10136559064656837921U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aScatter, 39U)) + 17622019364405410277U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 10U)) + RotL64(aCarry, 35U)) + 6927494824421416306U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aScatter, 21U)) + 7125170407794874847U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 53U)) + 12342273503071032250U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14997696377476124836U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14874498694181230698U;
            aOrbiterK = RotL64((aOrbiterK * 4026127545746010937U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2549397729130885686U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4217995818662767955U;
            aOrbiterI = RotL64((aOrbiterI * 5525525344485251063U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4706089044415442525U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17983900172670031015U;
            aOrbiterH = RotL64((aOrbiterH * 541552737180932879U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1904937798143929988U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10620877287033139483U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16711012562024287213U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15681091173163181525U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2655543246639000084U;
            aOrbiterJ = RotL64((aOrbiterJ * 16686375598149755947U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2647895110857289213U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5581609212017175954U;
            aOrbiterE = RotL64((aOrbiterE * 15330263616699031311U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13609076329627787987U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6244266279516622070U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12488345779236971095U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5289624364508923581U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 16351476803965903112U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9012522724650442597U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2731198704224650506U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4177455951984414332U;
            aOrbiterF = RotL64((aOrbiterF * 2567165277406175517U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3031687737578718714U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4866790771642413883U;
            aOrbiterA = RotL64((aOrbiterA * 1139524449666360541U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12903299652398385014U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7632760812370906911U;
            aOrbiterC = RotL64((aOrbiterC * 7924544687662448385U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 42U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterI, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 29U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterG, 35U)) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 26U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterC, 41U));
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterA, 43U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + aNonceWordK);
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 12U)) + aOrbiterI) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 60U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5848U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 7784U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5610U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9711U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aIngress, 35U)) + 2672739400294801233U;
            aOrbiterI = (aWandererE + RotL64(aCross, 5U)) + 8475624545015101850U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 3U)) + 1252755112289831257U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 41U)) + 7938039507649183387U) + aNonceWordD;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 8167413146948861022U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 56U)) + 17712313989694374353U) + aPhaseDOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 7637042279892596975U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 15770412950033467341U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 39U)) + 3951812021898608685U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 22U)) + 8656983621098246507U) + aNonceWordP;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 27U)) + 17943342344730687317U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3087677463651608668U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16493240011924342788U;
            aOrbiterK = RotL64((aOrbiterK * 16898479041530771871U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7750923317452683057U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2185924841611106546U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 708072658250726381U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14676868738946722416U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6849098251696302393U;
            aOrbiterF = RotL64((aOrbiterF * 2599806275837778069U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17817755047153606419U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 9900465270314068757U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9267925873983176685U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11380000891112113701U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15930503831156546113U;
            aOrbiterA = RotL64((aOrbiterA * 14450535035065393845U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5439183530402949780U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3731802052051181843U;
            aOrbiterH = RotL64((aOrbiterH * 7739775058947333169U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14432344583247783600U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16192098795467501636U;
            aOrbiterG = RotL64((aOrbiterG * 6285466374319549047U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1523272672673940290U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7462092373525113574U;
            aOrbiterD = RotL64((aOrbiterD * 15067751170235540679U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4612539457663050732U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7959404391235752875U;
            aOrbiterB = RotL64((aOrbiterB * 137834571274065007U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 11853468935131763944U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3575434598998149168U;
            aOrbiterC = RotL64((aOrbiterC * 16971321675425065041U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6135993440654291404U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2672739400294801233U;
            aOrbiterJ = RotL64((aOrbiterJ * 12891757276825641567U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterC, 29U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 12U) + aOrbiterK) + RotL64(aOrbiterD, 51U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 27U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 4U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterB, 41U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ aNonceWordI;
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14195U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16226U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15743U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13078U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 22U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 17264605017518259932U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 39U)) + 15209184354580778643U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 30U)) + RotL64(aCarry, 19U)) + 3299527965014731384U) + aNonceWordN;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 16293096431816127821U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 47U)) + 11031983436878828337U) + aNonceWordG;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 57U)) + 9188018632448236358U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 5U)) + 13420816400363406556U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 14U)) + 2485063384097917101U) + aNonceWordP;
            aOrbiterB = (aWandererH + RotL64(aIngress, 23U)) + 3089135816938128264U;
            aOrbiterF = (aWandererD + RotL64(aCross, 11U)) + 10730544971770435788U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 21U)) + 10431767565618874806U) + aPhaseDOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14883796491656899074U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13465877783538483706U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14311686051108108503U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13322163435314643713U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3307316600284371955U;
            aOrbiterC = RotL64((aOrbiterC * 12337846092069506365U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4950101626975919939U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2596253994220103666U;
            aOrbiterJ = RotL64((aOrbiterJ * 7181706961838582889U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17961706029559914243U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10321902557977495175U;
            aOrbiterA = RotL64((aOrbiterA * 16189559888625084711U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 18146616411403012772U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8414050129421955787U;
            aOrbiterE = RotL64((aOrbiterE * 14879448948196182863U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11739172334166341121U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7936637782633487291U;
            aOrbiterF = RotL64((aOrbiterF * 14940929920543800413U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3160044627483874242U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16816384076887379704U;
            aOrbiterI = RotL64((aOrbiterI * 5052772186568301951U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8101560104988710226U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 8851416379738817624U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 16767420038937389027U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9941784290055185679U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14495651885701938495U;
            aOrbiterH = RotL64((aOrbiterH * 1540692851998143607U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10599676325220702167U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16092000942942971187U;
            aOrbiterB = RotL64((aOrbiterB * 2457268192247656817U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16168470945107928109U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17264605017518259932U;
            aOrbiterK = RotL64((aOrbiterK * 15038386057529909273U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 10U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterF, 4U));
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 27U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterH, 36U));
            aWandererG = aWandererG + (((RotL64(aCross, 22U) + RotL64(aOrbiterE, 23U)) + aOrbiterG) + aPhaseDWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterI, 13U)) + aPhaseDWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aIngress, 30U) + aOrbiterI) + RotL64(aOrbiterD, 43U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 4
        // read from: aWorkLaneA, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 21366U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20446U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19942U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20347U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aCross, 21U)) + 13442819395490639310U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 8187292523194120936U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 11469697159823131388U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 13U)) + 13414083692375929653U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 35U)) + 11404010733687907517U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 23U)) + 6783212827186218247U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 38U)) + 8561131439340372614U;
            aOrbiterD = (aWandererA + RotL64(aCross, 43U)) + 6252609642004429113U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 12804867444200448952U) + aPhaseDOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 19U)) + 2739648749603690781U) + aPhaseDOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 58U)) + 14808861217017399752U) + aNonceWordG;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17588866502571268888U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5882260142735642980U;
            aOrbiterG = RotL64((aOrbiterG * 7688252946143263869U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15493099088132862949U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5175647411532429582U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15226544495598541883U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 14279707376173642767U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6826363572161275158U;
            aOrbiterK = RotL64((aOrbiterK * 5263708315440161809U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13267185753040999992U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9980987858092888720U;
            aOrbiterH = RotL64((aOrbiterH * 13210290848800728635U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3582972937645514549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10140409019562890804U;
            aOrbiterD = RotL64((aOrbiterD * 6944490201647678479U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6160444117287330557U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16344602960561293113U;
            aOrbiterA = RotL64((aOrbiterA * 2319964919335633293U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3497141036108337171U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 91269118352540308U;
            aOrbiterF = RotL64((aOrbiterF * 5160060720189045505U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12739932748793144857U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12820180915064791197U;
            aOrbiterJ = RotL64((aOrbiterJ * 5843849637411948699U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17572075652083359962U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10684041099654982701U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7121293375756263771U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10739534650885677354U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9731206787727954809U;
            aOrbiterB = RotL64((aOrbiterB * 3730875775588585547U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9655432616347117764U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13442819395490639310U;
            aOrbiterI = RotL64((aOrbiterI * 3650859301708619119U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 12U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterG, 50U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 58U) + RotL64(aOrbiterI, 5U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterA, 27U));
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterH, 18U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterB, 47U)) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererH, 54U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 5
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 26066U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21982U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25848U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 27027U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 26U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aIngress, 26U)) + 13481227414590594621U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 17425964381118918026U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 5U)) + 4792004356135956581U) + aNonceWordI;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 11926849936000639098U;
            aOrbiterG = (aWandererI + RotL64(aCross, 35U)) + 990697329347742142U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 57U)) + 9307721505373076588U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 11U)) + 17605732738841908719U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 13110764518634187439U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 13U)) + 17970109897810645911U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 19U)) + 10273133817644703654U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 40U)) + 11239046688920468137U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8355821483275763145U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15522151127786049345U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4844278537850520413U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5381663179722418112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9551368011768104906U;
            aOrbiterK = RotL64((aOrbiterK * 14202470972121732997U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16264476585232221270U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7721417776432288282U;
            aOrbiterE = RotL64((aOrbiterE * 10267770327791051869U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 339418090653475277U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3247926250495935511U;
            aOrbiterD = RotL64((aOrbiterD * 16824669543765729097U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3390560045236418590U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3894024951542543635U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10599637790900418767U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3878539166189668154U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5617705593218220843U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 82771190372750823U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12320861089148474544U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14943790251625519550U;
            aOrbiterB = RotL64((aOrbiterB * 13758322022902008313U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 18119213517612562775U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1413193144229486646U;
            aOrbiterF = RotL64((aOrbiterF * 14562375280658115687U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14810150213456844196U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8468712395797520201U;
            aOrbiterA = RotL64((aOrbiterA * 8167911669632436949U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13501570100536254566U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15409772061478100850U;
            aOrbiterH = RotL64((aOrbiterH * 955182899606655851U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8621805947309982779U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13481227414590594621U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 9591362493722704105U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 58U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterA, 19U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterK, 44U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 13U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterH, 37U)) + aPhaseDWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 48U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + aPhaseDWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterH, 34U));
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 5U)) + aOrbiterE) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 14U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 6
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneB
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30176U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 28021U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28487U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27729U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 36U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 3448371607470865612U) + aNonceWordL;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 26U)) + RotL64(aCarry, 57U)) + 3743742913651580573U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 47U)) + 13069491287948807280U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 53U)) + 16872779275586545632U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 57U)) + 17945792656755062795U) + aNonceWordJ;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 19U)) + 18199747196793731853U) + aPhaseDOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 15953311878379809513U) + aNonceWordG;
            aOrbiterD = (aWandererH + RotL64(aCross, 29U)) + 941268763494588338U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 11U)) + 10090221530365796809U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 51U)) + 8335698093307607001U;
            aOrbiterA = (aWandererF + RotL64(aCross, 4U)) + 6147498804734306100U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5980246079567570090U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 4152167624425912978U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10019421651535123573U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14990418790239735916U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3418668387496597219U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 12814077238529863119U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4206650904177199425U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 3905470780938996069U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16030122739273137005U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 9968672788233080924U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 602258075661864866U;
            aOrbiterE = RotL64((aOrbiterE * 2615726693066300065U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17751667243048041383U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2414054413585296027U;
            aOrbiterD = RotL64((aOrbiterD * 1049512574773201893U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6523322402744047752U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6729901917767398779U;
            aOrbiterJ = RotL64((aOrbiterJ * 8039939871405367139U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11460169185076814539U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7559640379553110573U;
            aOrbiterG = RotL64((aOrbiterG * 9864654321914036135U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17271150091827475028U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3541809324556914646U;
            aOrbiterA = RotL64((aOrbiterA * 12655168871428868639U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 10332471447306597185U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12580133010006951091U;
            aOrbiterI = RotL64((aOrbiterI * 1159183486084705865U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17333553613777910945U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14179392055698682109U;
            aOrbiterB = RotL64((aOrbiterB * 17675559451285279251U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3996830751779338356U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3448371607470865612U;
            aOrbiterK = RotL64((aOrbiterK * 5375529914102609947U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 36U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterG, 41U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 50U) + aOrbiterK) + RotL64(aOrbiterE, 20U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterD, 27U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterK, 23U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 39U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 34U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 53U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterC, 37U)) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordB);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneD[aIndex] = aIngress;
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

void TwistExpander_PickleBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBEBC276ED1235795ULL + 0xD8894CADE4965202ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9F00064CCF83494FULL + 0xE4F762E075193331ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD03292C9E8C257DBULL + 0xEB10CE8CC3E01E36ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x93CD858A63C969E3ULL + 0xA099E4CB02A6A96AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE2AC867FEA880627ULL + 0xA6142143E19E1775ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF2C315256F7BBA59ULL + 0xC5F498784FC4237CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x821C2E06BB640A5DULL + 0xE8E9B6DC187B4135ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF8E219452D719C5FULL + 0xE845FB6D4BE463A0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB98D057271B20627ULL + 0xEF601261229D9B35ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC8FFD6BAA111BDE5ULL + 0x91DFC7030564A7A6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD5FBC017987E5AFBULL + 0x8B56FBE04040AF46ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF7EBC5C43E7001C7ULL + 0xA2DF517E608D436EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF0C97BE6F32E94F9ULL + 0xA2CE32ADEB33FCF1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEE8F0EF7ECC4ADBDULL + 0xEDD6E49676FA12FCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBAA388196F701D93ULL + 0x93F773C979129482ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE42408C27E82FD25ULL + 0xFD0551EE0FE00B9AULL);
    // GSeedRunSeed_E seed_loop_e (start)
    {
        // GSeedRunSeed_E seed_loop_e lane group
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneA, aExpandLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aExpandLaneA, aExpandLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_e loop 1
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1620U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 2763U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5205U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 960U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 36U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 41U)) + 11274974230580265396U;
            aOrbiterA = (aWandererD + RotL64(aCross, 21U)) + 16658438747342741547U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 11U)) + 16612986966106053844U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 13U)) + 9329502236843231290U;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 48U)) + 14088261356708344656U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aWandererC + RotL64(aIngress, 19U)) + 13692608802007789581U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 6824473946645682398U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 2072915876348570040U) + aNonceWordA;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 29U)) + 7420507753044460759U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 53U)) + 4677557318688502593U) + aPhaseEOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aIngress, 46U)) + RotL64(aCarry, 57U)) + 15081678577055628459U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7026792817486507482U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14871665922943969918U;
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6807734532159292872U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17882797335141303280U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 15439872930381050291U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9233542707022629190U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1205501586581350876U;
            aOrbiterH = RotL64((aOrbiterH * 2596053290311090589U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10878718669747466677U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8066049063548639241U;
            aOrbiterJ = RotL64((aOrbiterJ * 3031382633089381605U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 861295180226875235U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9134969787937288583U;
            aOrbiterB = RotL64((aOrbiterB * 7565008208670843555U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6726642007159809594U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8061661744643240470U;
            aOrbiterF = RotL64((aOrbiterF * 6703498926835391813U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13541412083111962884U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8617442758729315637U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 15471862889276160953U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16884403561131293362U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9490680911678221233U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15988763830018001033U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10486145044311386738U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10200001044821063684U;
            aOrbiterG = RotL64((aOrbiterG * 16149790736141571017U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6997073594007878034U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13585783612009989767U;
            aOrbiterI = RotL64((aOrbiterI * 11425303157774550449U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 3847846040256340653U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11274974230580265396U;
            aOrbiterK = RotL64((aOrbiterK * 13970270689108369205U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 26U) + RotL64(aOrbiterD, 56U)) + aOrbiterE) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterF, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterI, 39U));
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterE, 54U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 11U));
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterK, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterA) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 50U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 47U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 2
        // read from: aExpandLaneA, aWorkLaneD, aWorkLaneC, aWorkLaneB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9796U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 7844U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6492U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 9946U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 6U)) + RotL64(aCarry, 37U)) + 1952750591494698524U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 13U)) + 4488270851303332830U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 2738763375328927635U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 3U)) + 6728843649480454340U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 39U)) + 10490717875258865358U) + aNonceWordG;
            aOrbiterA = ((aWandererK + RotL64(aCross, 56U)) + 1429288737812910205U) + aPhaseEOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 53U)) + 2761375016998907636U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 1088988605204499835U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 11U)) + 6829840407300289709U) + aNonceWordP;
            aOrbiterG = (aWandererI + RotL64(aIngress, 27U)) + 9267240337867690471U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 47U)) + 8120113021183975703U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1340980511302566784U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11874452169979878835U;
            aOrbiterF = RotL64((aOrbiterF * 8638486178860092537U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1872314794140971426U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6013952618696225751U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7994863587373565715U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3644011378086236002U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8501867691997891731U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7115282675461711509U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2493546555198066143U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5179240189571799179U;
            aOrbiterD = RotL64((aOrbiterD * 1267579130962756135U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11273348247858394197U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4577476419423118925U;
            aOrbiterI = RotL64((aOrbiterI * 8427261005061162673U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6201955123046621919U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3930651302557530185U;
            aOrbiterK = RotL64((aOrbiterK * 1563512534463027965U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 7571426325227856019U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11098508505512361002U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 9229352429618815089U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6154830144380484305U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4282054616147137364U;
            aOrbiterA = RotL64((aOrbiterA * 14984813139796280171U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14818120999774989697U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12174471855744785761U;
            aOrbiterJ = RotL64((aOrbiterJ * 3061488029278974095U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 3117297607579915182U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2979217539186455309U;
            aOrbiterG = RotL64((aOrbiterG * 12235308335184626143U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 824986728082249286U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1952750591494698524U;
            aOrbiterC = RotL64((aOrbiterC * 10162288961171400541U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 36U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 5U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterG, 48U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterE, 37U));
            aWandererG = aWandererG + ((((RotL64(aCross, 19U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aScatter, 42U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 14U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 40U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 56U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 3
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneD, aWorkLaneC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15449U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16288U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11730U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11762U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aScatter, 4U)) + 3917730204724097072U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 1874642340716212824U) + aNonceWordA;
            aOrbiterI = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 6900165757434854160U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 57U)) + 12750946097023807161U) + aNonceWordM;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 6563216048479513594U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 48U)) + 14960240191349450795U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 37U)) + 16306180275951788289U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 13U)) + 6502066618271045547U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aCross, 29U)) + 6219852857850888738U) + aPhaseEOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 11U)) + 2272931312452845850U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 53U)) + 3028929882263199463U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6067393030073568112U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10094809900437037258U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18095564940730322769U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5962414178157074575U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15755563045799129417U;
            aOrbiterB = RotL64((aOrbiterB * 3692603590609922031U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6321455513889880590U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1197435601998121700U;
            aOrbiterH = RotL64((aOrbiterH * 17693996266260557625U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12496949381666299968U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6357070235648527030U;
            aOrbiterG = RotL64((aOrbiterG * 2931486644220862433U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8423760160877540210U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8090246492554850768U;
            aOrbiterE = RotL64((aOrbiterE * 2949407491181921633U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11436635942985063755U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17086363141014359856U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10504127577318206801U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10734017887545474935U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 375515325165740779U;
            aOrbiterK = RotL64((aOrbiterK * 9980486695448151709U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5217148491945389821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14696058217023530058U;
            aOrbiterC = RotL64((aOrbiterC * 11026674782236654799U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11869055287836412650U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16951500118659983436U;
            aOrbiterD = RotL64((aOrbiterD * 4304372681583055077U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7866300390953569803U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 18017335943787362993U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 15683049583437004889U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2477944286851267725U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3917730204724097072U;
            aOrbiterF = RotL64((aOrbiterF * 6617615984203047419U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 10U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 34U) + aOrbiterG) + RotL64(aOrbiterC, 13U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterK, 41U));
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aCross, 10U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterG, 52U)) + aNonceWordI);
            aWandererK = aWandererK + ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 36U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordI;
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 4
        // read from: aOperationLaneA, aExpandLaneB, aExpandLaneA, aWorkLaneD
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19272U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 18606U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16620U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneD[((aIndex + 19004U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 6U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aIngress, 3U)) + 12615321415808640429U) + aNonceWordP;
            aOrbiterI = (aWandererD + RotL64(aCross, 35U)) + 15712784676459931207U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 14U)) + 11013335427004930046U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 57U)) + 8298733856304768806U) + aPhaseEOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 6207732959150824216U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 29U)) + 9769864876127544038U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 10782181918651152563U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 41U)) + 5790454015845620939U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 44U)) + RotL64(aCarry, 27U)) + 15606578025386733803U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 37U)) + 5522352539991175304U) + aNonceWordG;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 51U)) + 5993355818572869649U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10864534396947622047U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12090053126235913528U;
            aOrbiterJ = RotL64((aOrbiterJ * 7250801471645972261U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 14191181677234981396U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2258570108233924592U;
            aOrbiterC = RotL64((aOrbiterC * 8307541155393855209U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8448114811381534603U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2702389315763499817U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6710443836432274393U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17202184076718780200U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 150549910056015002U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 195034681254956335U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4910512055808124967U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4783477997418403079U;
            aOrbiterF = RotL64((aOrbiterF * 861977492146512865U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13842899106208709771U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7930112618036681468U;
            aOrbiterK = RotL64((aOrbiterK * 8609551859830858419U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8790107242863198659U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6882768826643279144U;
            aOrbiterE = RotL64((aOrbiterE * 13745521454063360763U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12136498871759890015U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8120456314755584336U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 1830725195528043575U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14425711740351183016U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15907406009196323049U;
            aOrbiterD = RotL64((aOrbiterD * 8599371693260686839U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4878521420367891861U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1184672056055028939U;
            aOrbiterI = RotL64((aOrbiterI * 5963961755367831967U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10126736568567000180U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12615321415808640429U;
            aOrbiterH = RotL64((aOrbiterH * 11663715449073755137U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + aNonceWordE) + aPhaseEWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 14U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aScatter, 26U) + aOrbiterD) + RotL64(aOrbiterI, 37U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 41U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterH, 22U)) + aPhaseEWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 28U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordK);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 5
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26105U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 25842U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24493U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26344U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 3U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 24U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 16651241552253078315U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 29U)) + 4558144676982478003U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 43U)) + 8814884320080367550U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 52U)) + RotL64(aCarry, 57U)) + 16011579668555672117U) + aNonceWordK;
            aOrbiterK = (aWandererG + RotL64(aCross, 37U)) + 4738918668759862438U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 12526083125540985108U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 13U)) + 8048723561746000552U) + aNonceWordA;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 27U)) + 1082218464034639039U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 24U)) + 8432043246965946816U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 35U)) + 9982080524048636852U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 41U)) + 6720069955755215919U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1019035028070247757U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7360619079463870467U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 6623074813047915863U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10893918488381348474U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1390297670907738019U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11909657437658597735U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12512200589031203480U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14741471280748399540U;
            aOrbiterG = RotL64((aOrbiterG * 3012135242889901095U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8543897248359826770U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8545972622733791272U;
            aOrbiterD = RotL64((aOrbiterD * 11793879362775346821U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7049384618581928664U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14730773807906925408U;
            aOrbiterJ = RotL64((aOrbiterJ * 10711566871536755073U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11480717275652449986U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1135397594974536859U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6347492892938856497U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6897207625849516702U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10920630712550287148U;
            aOrbiterB = RotL64((aOrbiterB * 4140705091806993359U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1094056478999931332U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6784487144549717207U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6295177724167067891U), 43U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 2224992798329560875U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11486442570446223696U;
            aOrbiterI = RotL64((aOrbiterI * 5680065455032616591U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14681556190496625711U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1809388635055225841U;
            aOrbiterA = RotL64((aOrbiterA * 3449474313001177557U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4480846057441948619U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16651241552253078315U;
            aOrbiterK = RotL64((aOrbiterK * 10628778876898064085U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterF, 6U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 47U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterI, 37U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterK, 27U));
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterE, 10U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 48U) + aOrbiterG) + RotL64(aOrbiterC, 43U));
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + aPhaseEWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterG, 21U)) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 18U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 42U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 6
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneB
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32028U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 31453U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28355U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 28769U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 44U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 19U)) + 12849591986267890852U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 11U)) + 8232614804696815750U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 35U)) + 12141567259210877281U) + aNonceWordP;
            aOrbiterH = ((aWandererH + RotL64(aCross, 26U)) + RotL64(aCarry, 51U)) + 2928641981037885644U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 980733350554783938U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aCross, 53U)) + 2683985177993350746U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 13U)) + 14532148403815527355U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 56U)) + 7736296629433884203U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 5U)) + 10428437770166310549U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 21U)) + 18327174144859461029U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 6810436935194432002U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12606153309690753435U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17123256945895150555U;
            aOrbiterG = RotL64((aOrbiterG * 13469111258504672565U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9057777759026189541U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16478485918911194442U;
            aOrbiterK = RotL64((aOrbiterK * 11054247078884894131U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 18064460487552100483U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11477276762421684083U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3886501230380184395U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 18318375441973295081U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13849305985380030986U;
            aOrbiterC = RotL64((aOrbiterC * 12962140243967824959U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10240409420338313641U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 18360586077779529086U;
            aOrbiterA = RotL64((aOrbiterA * 18196875422391501927U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16801797158622424257U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4950305991208513887U;
            aOrbiterF = RotL64((aOrbiterF * 4437082499761416951U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15790878572843321918U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 9808781805065559728U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 9394280083159162953U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11974996650410830731U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4955004489435232515U;
            aOrbiterJ = RotL64((aOrbiterJ * 13301966529515483085U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1187569634223338864U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5351017164244226367U;
            aOrbiterI = RotL64((aOrbiterI * 14735674576470803699U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9587142385246940125U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16253850371962732943U;
            aOrbiterB = RotL64((aOrbiterB * 3408021872390904463U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14990060157351237661U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12849591986267890852U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2158106726261981983U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterB, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterH, 50U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 6U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ) + aNonceWordG);
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterI, 41U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 46U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 42U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 14U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneD[aIndex] = aIngress;
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

void TwistExpander_PickleBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC3CFA21DCDBB7993ULL + 0xC49060BA9D2AAA40ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9879DBEEFF24EEDDULL + 0x9BACA874262C2FE6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB26A76E322A98BB1ULL + 0xA3BF2C04CFA2DD5DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBB66082AB035E87BULL + 0xEF3470AA8EA45476ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x984140094C83BF25ULL + 0x9B370970A520F238ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9F5E2231C11D9593ULL + 0xEA51BDF14FC6ECF1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF6997040E91A0E33ULL + 0xB25CE4D41385C1BBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC6C6FBEBB8AEBA6FULL + 0xD22C0A5F2C781809ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAA73A6985835A3CDULL + 0xC810F80471011CC6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFDD34ECE02A52D5FULL + 0xB0963C763FFD40DDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8CC590BEA338C36FULL + 0xF9F2892706EBDC3CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE98535104C814E61ULL + 0xF497A3910AA302F4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE1B65C43DD2A1613ULL + 0x9FD5CE043F966FE2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBABD33B008098E69ULL + 0x9BC894DD9DE102C2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDE7C1E4AD7E6C849ULL + 0xAB46D0592CF43A61ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBF87DF29424F160DULL + 0x94B83F31273085ABULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 497U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1145U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2832U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 3372U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 56U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 77518479758428414U) + aNonceWordA;
            aOrbiterG = (aWandererA + RotL64(aIngress, 35U)) + 4832061802166300011U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 37U)) + 11695291171006574112U;
            aOrbiterA = (aWandererC + RotL64(aCross, 53U)) + 7467412817843260094U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 3U)) + 17801484124471154757U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 41U)) + 5555455638503958639U) + aNonceWordP;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 30U)) + 5669470540733721606U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 51U)) + 3042388456327784163U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 2236734925228156691U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 27U)) + 14459720401528685450U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 20U)) + 4814967631216658856U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16950679344449075945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6262238639302011050U;
            aOrbiterJ = RotL64((aOrbiterJ * 9942659897425088183U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3522256359074996724U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12524717897707074242U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6787771338063891989U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13891759914865623828U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11910250571469028666U;
            aOrbiterC = RotL64((aOrbiterC * 12311343917878428995U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2240189915640314069U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5365912986308810837U;
            aOrbiterA = RotL64((aOrbiterA * 15133972552032469957U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9323732721344489753U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13087326560957916553U;
            aOrbiterK = RotL64((aOrbiterK * 14659491687401151733U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16398238057564892809U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11517870519285159224U;
            aOrbiterH = RotL64((aOrbiterH * 1501848878469712681U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7758285512254776734U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17475149091906684720U;
            aOrbiterI = RotL64((aOrbiterI * 6015816725428299273U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2051631493975035243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11684740065349595315U;
            aOrbiterG = RotL64((aOrbiterG * 10918975496337269197U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10575473798991451167U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8267005776169272822U;
            aOrbiterE = RotL64((aOrbiterE * 13166868678285963961U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6249698995716039231U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 13808085811784323978U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 3897731011582061983U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2739364646624876985U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 77518479758428414U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6977724811175035551U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 60U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 26U)) + aNonceWordJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 11U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 6U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 46U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 48U) + aOrbiterK) + RotL64(aOrbiterJ, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordE);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9105U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 7866U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7629U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 9237U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) + RotL64(aCarry, 13U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aPrevious, 27U)) + 8975885703279267062U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 23U)) + 8664844915562660637U) + aNonceWordE;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 12281774799736296726U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 4U)) + 15347461352311329726U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 35U)) + 12967500561828907834U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 37U)) + 5002833859280402726U) + aNonceWordP;
            aOrbiterA = ((aWandererA + RotL64(aCross, 47U)) + 11908257536954668983U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 53U)) + 17017174811949227162U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 42U)) + RotL64(aCarry, 53U)) + 16851323125613931180U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 51U)) + 13469326957728686706U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 5228638551056105241U) + aPhaseFOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11945166198089308564U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16268645041872996022U;
            aOrbiterH = RotL64((aOrbiterH * 5391448793718370911U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14781204627695095701U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5365325354838101092U;
            aOrbiterD = RotL64((aOrbiterD * 8017284997946310807U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 563147416025715953U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14660867395395625851U;
            aOrbiterF = RotL64((aOrbiterF * 4769458126865307103U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3168989056355712105U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16179131669773665579U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5641461617066671723U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4160220074225527179U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8597134686962559111U;
            aOrbiterB = RotL64((aOrbiterB * 639572585431474015U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16811551552456811661U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5827323970423386301U;
            aOrbiterE = RotL64((aOrbiterE * 9328247349730652021U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15583234353262170227U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2950816254621717748U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 1102417597476170143U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4426165025104306337U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11871220132164971152U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2366168050042802207U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3832424136113939717U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17673885217916768611U;
            aOrbiterI = RotL64((aOrbiterI * 10887063696370811871U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3479289844909914390U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9498461576098567546U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8734492074299676555U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10645314291190544864U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8975885703279267062U;
            aOrbiterK = RotL64((aOrbiterK * 16584086014947250551U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 14U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterB, 53U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterH, 18U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 23U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterB, 51U)) + aNonceWordM);
            aWandererD = aWandererD + ((((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 46U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterA, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 43U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererH, 20U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16337U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15978U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15934U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 13308U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 12U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aIngress, 35U)) + 12206125048349568300U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 5843520589343188818U;
            aOrbiterK = (((aWandererB + RotL64(aCross, 29U)) + 12195046124287121687U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aWandererC + RotL64(aScatter, 26U)) + 16769779119214020640U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 5257603646260695833U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 8523523946234886745U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 3U)) + 7316024684200084096U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 52U)) + 11996978575084115207U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 19U)) + 15491711479085513628U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 43U)) + 6036648530996821484U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 47U)) + 926323222234121863U) + aNonceWordD;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2700323841295743492U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5852273765810284935U;
            aOrbiterK = RotL64((aOrbiterK * 16665696735016345215U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11697397483133538067U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 17777142964957007194U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6338967222543284999U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10892176201151170298U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11759700374509499684U;
            aOrbiterI = RotL64((aOrbiterI * 14247697264744736081U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11343756773329590643U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15785048929757652350U;
            aOrbiterJ = RotL64((aOrbiterJ * 17208103574389502597U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7508839228498497238U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13088508510402094665U;
            aOrbiterE = RotL64((aOrbiterE * 15730279447009669103U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16259236641717377699U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11228995722951003980U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4870092259515181323U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13775851561528617086U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3023564646900497080U;
            aOrbiterF = RotL64((aOrbiterF * 9936548213275464131U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 154952467284609583U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14239675888632174461U;
            aOrbiterC = RotL64((aOrbiterC * 1370550680736926425U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 168749514558708557U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5070416708211422927U;
            aOrbiterH = RotL64((aOrbiterH * 13631900152346927703U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1961290602001581341U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12235345489656113478U;
            aOrbiterA = RotL64((aOrbiterA * 14403534235273302211U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2295581049708176078U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12206125048349568300U;
            aOrbiterB = RotL64((aOrbiterB * 6008868846674396181U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 6U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterB, 60U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 19U));
            aWandererH = aWandererH + ((RotL64(aIngress, 56U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 41U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 57U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 10U) + aOrbiterI) + RotL64(aOrbiterH, 52U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 14U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // read from: aExpandLaneA, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19565U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17754U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20894U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20589U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 39U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 16519040829220310189U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 35U)) + 6888002778416941825U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 12U)) + 1310832187746534025U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aWandererA + RotL64(aIngress, 41U)) + 5890888009051281674U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 5143864838362464857U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 21U)) + 15591534069452660003U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 52U)) + 1466867671765325096U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 37U)) + 13931443680107902488U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 15400747367673245552U) + aNonceWordM;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 29U)) + 2836975369734495759U) + aNonceWordC;
            aOrbiterH = (aWandererE + RotL64(aScatter, 5U)) + 2370720358274970117U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3470677184188006133U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 7175584278499266723U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 10067096593682482345U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6095078817776863055U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2176637999243513070U;
            aOrbiterJ = RotL64((aOrbiterJ * 12215701810843975501U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5580391239754903129U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15196125567953871184U;
            aOrbiterD = RotL64((aOrbiterD * 12686361960729564519U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12787014151503209931U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1523153207064063495U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3113907543551927561U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12973289026485937829U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9087439766232078173U;
            aOrbiterE = RotL64((aOrbiterE * 5817029335999350327U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16318022893068674015U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11089160685103562409U;
            aOrbiterK = RotL64((aOrbiterK * 17087834321385147603U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 8680037953925067235U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3112588943274158119U;
            aOrbiterI = RotL64((aOrbiterI * 9214011370307670371U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16749015684369649821U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9419550535891334966U;
            aOrbiterH = RotL64((aOrbiterH * 5421312787569114811U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12309598080688360615U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12244971765096881835U;
            aOrbiterB = RotL64((aOrbiterB * 17260277357109449509U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10088685417774847648U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3241987595838650154U;
            aOrbiterA = RotL64((aOrbiterA * 14096986158958931367U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17916401586500786536U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16519040829220310189U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 6742024268853509861U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 46U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterF, 54U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 41U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 13U)) + aOrbiterK) + aNonceWordL);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 21U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 52U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterB, 27U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterI, 39U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 11U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterI, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 4U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25779U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 25658U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21984U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 22626U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aCross, 18U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 18087125778766689269U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 30U)) + 13710545066503235196U;
            aOrbiterI = (aWandererG + RotL64(aCross, 51U)) + 1701939704736254645U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 37U)) + 8064093611384019909U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 47U)) + 16623332751533885431U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 12U)) + 15590129153794910109U;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 7413312683079107383U) + aNonceWordA;
            aOrbiterK = (aWandererB + RotL64(aIngress, 3U)) + 4186064478651458810U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 5501191643940735954U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 5U)) + 11064645242200570835U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 19U)) + 13825922087298055833U) + aNonceWordC;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5944980709887369970U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8181136916070569646U;
            aOrbiterI = RotL64((aOrbiterI * 395183021205661827U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15442336949157292482U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11580554435240641337U;
            aOrbiterE = RotL64((aOrbiterE * 6654637892858767739U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11240018128174598322U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2027565596050777471U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 18048186560314431815U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16425887196883725233U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16828683527588834095U;
            aOrbiterC = RotL64((aOrbiterC * 17746289103235902485U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9923829146479008804U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6669171007279929454U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 681823450939955099U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3902430046523165149U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6739998149289590041U;
            aOrbiterH = RotL64((aOrbiterH * 2675037435528416821U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16014401255534234075U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14741857638680634564U;
            aOrbiterD = RotL64((aOrbiterD * 8723611021403369393U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5064807861673260054U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 968747317273200299U;
            aOrbiterJ = RotL64((aOrbiterJ * 14122304002722582329U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5282686212362051427U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6902253563196129760U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7682808024658992049U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4995580401402368332U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14949762584793646470U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 3539183342072953803U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2378815735788107402U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 18087125778766689269U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 16799380528404446281U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 20U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterB, 56U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterI, 27U));
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + aNonceWordB);
            aWandererI = aWandererI + ((RotL64(aIngress, 14U) + RotL64(aOrbiterH, 23U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 12U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterH, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 22U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32308U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 29708U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32167U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29392U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 40U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aScatter, 3U)) + 13924571355038625040U) + aNonceWordJ;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 43U)) + 16328300979357156658U) + aPhaseFOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 11U)) + 3947771961206012461U;
            aOrbiterC = (aWandererK + RotL64(aCross, 26U)) + 15428284250569311285U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 57U)) + 5777369485254032486U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 16813320300717644673U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 16689933050200758251U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 28U)) + RotL64(aCarry, 19U)) + 1856422419049390708U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 37U)) + 18214498743831925517U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 13U)) + 18278550878494094923U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 47U)) + 797712062039591797U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15854849439012341347U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 996882939768167773U;
            aOrbiterA = RotL64((aOrbiterA * 14936703950807908575U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3005829974130671692U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8793495343509953906U;
            aOrbiterF = RotL64((aOrbiterF * 14065479348374612031U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7710453029930631112U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9511995836117707047U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7250766204781428201U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 670902975693341744U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 9045820304668279777U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 18373074917532639027U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12417212387607119470U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12816983560669985622U;
            aOrbiterH = RotL64((aOrbiterH * 8406003970221889847U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17245432086377688540U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6806521945548502014U;
            aOrbiterD = RotL64((aOrbiterD * 11335859481858640857U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8947500746292365294U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4468060468522895852U;
            aOrbiterB = RotL64((aOrbiterB * 7022481284816599797U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9892975931958803992U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3042599331526937836U;
            aOrbiterG = RotL64((aOrbiterG * 3308512896171443645U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12991568221485810891U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8551331172836260315U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4509997595920847057U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 183547209633334407U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17275712817092769452U;
            aOrbiterJ = RotL64((aOrbiterJ * 15677355290000929085U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12743863879392372723U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13924571355038625040U;
            aOrbiterC = RotL64((aOrbiterC * 11966689345179279407U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 46U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 39U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 21U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterD, 51U)) + aNonceWordE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterB, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterH, 41U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterG, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterF, 12U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterG, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneD[aIndex] = aIngress;
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

void TwistExpander_PickleBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD9C593D78659F307ULL + 0xC5EF798114DE00C2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDA8AE1219BFFE889ULL + 0xBF6D7CE82B084A74ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9337FFF48F32A0A5ULL + 0x9ED079A42CD02FFCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC9C19CCB790435E9ULL + 0xD33228A728B2A2EFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC74C723DB91DBD89ULL + 0xC0C9C207D9BB9DEEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDB7C218C297C599DULL + 0xFAD5EE8DB9CBAECEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBC3B263A80556ECBULL + 0xC0D0145AF30C1F8EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x924E5688FF66A05BULL + 0x9809611E4A9910ADULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE291F742D32DC23BULL + 0x9D76C9EFE8072770ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCA38A7670B5D53A7ULL + 0xA3506DD995A6A001ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDDA6DA7A578F7001ULL + 0xE34D65F53139DA57ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC671882B25912895ULL + 0xE5CA711DB9AD78EDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE47E125C8925B5E3ULL + 0xB37A1741DD20BE3EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE306AB6048A99D37ULL + 0xD8938EFFB90AC81BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEF4614D448AD965FULL + 0xCA1B1FAD0D8F5E46ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB77F188FB7E2805DULL + 0xE0977BD7F05A58AFULL);
    // GSeedRunSeed_G seed_loop_g (start)
    {
        // GSeedRunSeed_G seed_loop_g lane group
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneA, aOperationLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aOperationLaneA, aOperationLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_g loop 1
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3210U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((aIndex + 4715U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2686U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 239U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 40U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 13U)) + 13960289014350612206U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 22U)) + 3483331015269589730U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 19U)) + 6873299241002444518U) + aNonceWordB;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 3562094007125534229U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 47U)) + 11422367439932782705U) + aNonceWordJ;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 29U)) + 532453428514259816U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 57U)) + 17810941465810193088U) + aNonceWordM;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 4U)) + RotL64(aCarry, 35U)) + 11869759058631106331U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 53U)) + 8837581071876177566U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 35U)) + 17185378327053837778U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 7578253375676981500U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 17112646434432814442U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14949096407295697881U;
            aOrbiterE = RotL64((aOrbiterE * 14770977858283051753U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4259590620758467836U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6534899413644542303U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7987609419215568661U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2637407498893694243U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15819295597921425711U;
            aOrbiterH = RotL64((aOrbiterH * 5202015597375051399U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6373559542002699718U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11694562937392022505U;
            aOrbiterJ = RotL64((aOrbiterJ * 9311557972331218597U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3308736483775453062U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12749929710650475901U;
            aOrbiterB = RotL64((aOrbiterB * 248428400724560945U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1569528215675579656U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1044077933631689572U;
            aOrbiterF = RotL64((aOrbiterF * 6443796233912755143U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8393422728124537471U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2002732612516530754U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13702146823622364279U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13469191942843147943U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7633171368709520560U;
            aOrbiterI = RotL64((aOrbiterI * 9713514012478203047U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 4023206337737491091U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15990323932023596968U;
            aOrbiterK = RotL64((aOrbiterK * 4816480271959713463U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 837005729394899591U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9692088757104339973U;
            aOrbiterC = RotL64((aOrbiterC * 17971548293495807419U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18039464962413134616U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13960289014350612206U;
            aOrbiterA = RotL64((aOrbiterA * 931609478642506411U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 23U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 19U)) + aOrbiterC) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterE, 11U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 54U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterB, 44U)) + aPhaseFWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aCross, 18U) + RotL64(aOrbiterG, 60U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_g loop 2
        // read from: aOperationLaneA, aWorkLaneD, aWorkLaneC, aWorkLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5988U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8059U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9062U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 6975U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aScatter, 39U)) + 380024772508948442U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aIngress, 26U)) + RotL64(aCarry, 43U)) + 7649029098162567210U) + aNonceWordE;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 5329304598870421851U;
            aOrbiterD = (aWandererH + RotL64(aCross, 13U)) + 12306118665045151326U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 47U)) + 960751560457324256U) + aNonceWordG;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 51U)) + 3244070254386191876U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 15733408571609521746U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 11U)) + 17623448932647018544U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 28U)) + 8787759896149035829U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aWandererG + RotL64(aScatter, 23U)) + 14741681792348288162U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 21U)) + 8801731213568307302U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9872248187499779222U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15407371518644528235U;
            aOrbiterA = RotL64((aOrbiterA * 1245102406469471673U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4242060317152943062U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9942784962409917541U;
            aOrbiterI = RotL64((aOrbiterI * 888649755587764533U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7296348796484458631U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15061417216070157797U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10349554676953256231U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3233185810644297433U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9241229457641024287U;
            aOrbiterB = RotL64((aOrbiterB * 2728237515724597517U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8464051359381554575U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3307872165699029375U;
            aOrbiterH = RotL64((aOrbiterH * 4859663401033023433U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5482617843966711997U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4442149210462943872U;
            aOrbiterG = RotL64((aOrbiterG * 8979352218576515647U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10591636597580147381U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 14925122230279312217U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 15038171961638724013U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9772367878232735350U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15800661165607190092U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10493976952980533589U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1571665862499272194U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3162847040693387901U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2747235335326991399U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4868791925868749848U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13134549226315884613U;
            aOrbiterF = RotL64((aOrbiterF * 3551955270718495869U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7830447320021657240U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 380024772508948442U;
            aOrbiterE = RotL64((aOrbiterE * 5143324968958616357U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 52U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterK, 11U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterC, 21U)) + aPhaseFWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 35U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 50U) + aOrbiterA) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 30U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterE, 19U));
            aWandererF = aWandererF + ((RotL64(aCross, 18U) + RotL64(aOrbiterG, 43U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 57U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 60U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_g loop 3
        // read from: aOperationLaneB, aOperationLaneA, aWorkLaneD, aWorkLaneC
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12253U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13120U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14771U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12623U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 42U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aCross, 47U)) + 16424657151168221875U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 57U)) + 17150123681886380361U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 6U)) + 16041993588694572757U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 51U)) + 9871185846434828537U) + aNonceWordB;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 11227236398354430757U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 5399325217402192631U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 53U)) + 9248828789282890454U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 9041370494203701062U;
            aOrbiterH = (aWandererI + RotL64(aCross, 44U)) + 14944424084524970764U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 27U)) + 5481938174456671041U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aIngress, 35U)) + 14783648629543752715U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12355573914530445723U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9863991559011968318U;
            aOrbiterA = RotL64((aOrbiterA * 8495251211794343179U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 16149688605937250965U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 106041828692026825U;
            aOrbiterG = RotL64((aOrbiterG * 12199934305374582599U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8076098639554567792U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11155119311895580013U;
            aOrbiterF = RotL64((aOrbiterF * 1495180896564818647U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6847612160595917702U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16094377920388017367U;
            aOrbiterD = RotL64((aOrbiterD * 4875801863643206333U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13584719866672696684U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13446209321646234607U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9945349065094781529U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15829806645369560988U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12573767256739062550U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 5649504278826069077U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3850030870300393809U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11857593987748189858U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15942863910931814193U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5505918410521728373U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12949653497121247860U;
            aOrbiterJ = RotL64((aOrbiterJ * 90944913639560027U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2448323375614082955U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4386059032042654583U;
            aOrbiterC = RotL64((aOrbiterC * 11730132905525317201U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 108129028178045299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18292666533864994149U;
            aOrbiterH = RotL64((aOrbiterH * 2599590507178673531U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10771402979550786312U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16424657151168221875U;
            aOrbiterI = RotL64((aOrbiterI * 6255743082177474607U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererB = aWandererB + (((RotL64(aCross, 28U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 6U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterC, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 47U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aScatter, 46U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterB, 14U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_g loop 4
        // read from: aExpandLaneA, aOperationLaneB, aOperationLaneA, aWorkLaneD
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19400U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 17942U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16610U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((aIndex + 17939U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 47U)) + (RotL64(aIngress, 60U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 12027839670755583592U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 37U)) + 15380130703509859843U) + aNonceWordF;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 43U)) + 4590907433867798074U) + aNonceWordP;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 11U)) + 1754574023602519724U) + aPhaseFOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 9832756659564903767U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 39U)) + 5035088494491470403U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 20U)) + 14199170923323644638U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 29U)) + 8325619421264440438U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 969534320779067977U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aIngress, 41U)) + 270575869402913847U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 6U)) + 13344806516599578910U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15143147951139409101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14425582489214169238U;
            aOrbiterG = RotL64((aOrbiterG * 16893787086337916355U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13951127523239064584U) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 14177925225918293579U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13079514031864998485U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8258920744278218901U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7408161179397242453U;
            aOrbiterI = RotL64((aOrbiterI * 975737128100519169U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8581481606764773468U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10078416198417433133U;
            aOrbiterA = RotL64((aOrbiterA * 1102721083915858247U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18299772198826189580U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18304668908084397946U;
            aOrbiterE = RotL64((aOrbiterE * 10589455451200578687U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16729632621573817223U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13362300981585573239U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9824473895535518785U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8629682832849915380U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6852852009091469641U;
            aOrbiterC = RotL64((aOrbiterC * 11912646687050011915U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7433098156961745198U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 10931806208899417308U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 14699197041038067483U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 629604718211675247U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1487372736719237118U;
            aOrbiterH = RotL64((aOrbiterH * 705192821277928909U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3567439893461603384U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11143068753134694333U;
            aOrbiterJ = RotL64((aOrbiterJ * 15529326960229305389U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14242098279913980463U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12027839670755583592U;
            aOrbiterD = RotL64((aOrbiterD * 6630014752150544153U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 14U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterH, 37U)) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 30U) + RotL64(aOrbiterK, 23U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 26U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterC, 51U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 26U) + RotL64(aOrbiterI, 5U)) + aOrbiterC) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 18U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterG, 41U));
            aWandererE = aWandererE + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_g loop 5
        // read from: aExpandLaneB, aExpandLaneA, aOperationLaneB, aOperationLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25140U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 26602U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24072U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24171U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 4U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (((aWandererH + RotL64(aCross, 35U)) + 5160910997561396461U) + aPhaseFOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 14920764751058512062U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 53U)) + 6080952401749660022U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 17667234330526298627U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aPrevious, 28U)) + 760630072638686756U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 47U)) + 3504157162816997476U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 21U)) + 9489022223422585882U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 1149898536879968964U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 23U)) + 10492284328940025310U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 13U)) + 13213275606286399312U;
            aOrbiterD = (aWandererK + RotL64(aCross, 18U)) + 10557118912847180413U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15618980209023994776U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5268600749854045564U;
            aOrbiterG = RotL64((aOrbiterG * 3849660559223919613U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8011552687609649990U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3148133096349525066U;
            aOrbiterH = RotL64((aOrbiterH * 5245156554959620007U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12032847944237867285U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14999005703490824673U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 6631584955208646049U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5426735969392906710U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3593177531650386729U;
            aOrbiterC = RotL64((aOrbiterC * 12997284886192717043U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1701444719333347373U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15928731228196894960U;
            aOrbiterF = RotL64((aOrbiterF * 1919318226904213433U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5960179456039157036U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5716434224061596483U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 3731976564761202801U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2136841536293340279U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12969550408652728526U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7612191387451455137U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3641997570461447114U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4677572491523684525U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2730358077882211651U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 2741372094325164504U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4998631511811832690U;
            aOrbiterD = RotL64((aOrbiterD * 10619395395977372695U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6260464862798783617U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16489087874167346533U;
            aOrbiterI = RotL64((aOrbiterI * 11278053967185244867U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7043760915859224327U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5160910997561396461U;
            aOrbiterE = RotL64((aOrbiterE * 15260149870590431675U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 24U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterK, 11U));
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterK, 37U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 58U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 39U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterF, 39U));
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 6U) + aOrbiterG) + RotL64(aOrbiterD, 14U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 27U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererI, 36U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_g loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31149U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((aIndex + 28402U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27512U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 31330U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 18U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 12U)) + 13350544654542863236U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 35U)) + 12364346790125404372U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 41U)) + 9738750172849512764U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 37U)) + 3781373837635491421U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 57U)) + 16635020317512702337U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 43U)) + 5383653921676231276U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 10181959815492056493U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 10005510924273927017U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 47U)) + 9524687662265740565U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aScatter, 3U)) + 4259138552009771014U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 18U)) + RotL64(aCarry, 53U)) + 8973051213213726023U) + aNonceWordG;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17602611840127337490U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8218984546932905269U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17504305273683304231U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18102186122213487888U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2629927500298092976U;
            aOrbiterE = RotL64((aOrbiterE * 6983280164448292723U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2491581597835795234U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9506602492971620955U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 9559829640915637163U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13422942713680612924U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15037354693234876601U;
            aOrbiterH = RotL64((aOrbiterH * 12692376075738621447U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12896066842192894694U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2202952306291905855U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6779368532763429997U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12160313482450599313U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10812986281270407756U;
            aOrbiterA = RotL64((aOrbiterA * 7786608700746771809U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12474638293190144525U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5882870951276225224U;
            aOrbiterF = RotL64((aOrbiterF * 15532427302173572457U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3782896138051179209U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10965680631059882311U;
            aOrbiterJ = RotL64((aOrbiterJ * 14060923998307082385U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15650420683333746952U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4110674660963676864U;
            aOrbiterD = RotL64((aOrbiterD * 11724979274890265275U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 694817156953099464U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4402927404825116007U;
            aOrbiterI = RotL64((aOrbiterI * 579586789292520113U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6849178151532923489U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 13350544654542863236U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 2416097748778941523U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 14U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterH, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 3U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterE, 34U));
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 29U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + aNonceWordL);
            aWandererI = aWandererI + ((RotL64(aPrevious, 46U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterH, 19U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterK, 48U)) + aOrbiterB) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordP;
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_G seed_loop_g (end)
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

void TwistExpander_PickleBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
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
        // read from: mSource, aKeyRowReadA, aKeyRowReadB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // twist_loop_a loop 1
        // read from: mSource, aKeyRowReadA, aKeyRowReadB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1434U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 441U)) & W_KEY1], 58U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1645U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7970U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 23U)) + 2225397913940961213U) + aPhaseCOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aCross, 13U)) + 8342544893601343643U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 162922186381417187U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 47U)) + 11660218373710972210U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 41U)) + 14909034764605802354U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 19U)) + 16776955237009701511U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 5834487809188925253U) + aPhaseCOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 46U)) + 1498492772767040320U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 35U)) + 4161765458781579617U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10511923076962447765U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8575954471692620021U;
            aOrbiterI = RotL64((aOrbiterI * 12526744988828982731U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6536325446331340573U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1790628986900286346U;
            aOrbiterA = RotL64((aOrbiterA * 5262997114200816715U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2623814807619278590U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11676970995834706612U;
            aOrbiterH = RotL64((aOrbiterH * 10057461115132434901U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 13836786354224256591U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6293096163612129260U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8977954126326217153U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4271144764978661248U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15938494256992560202U;
            aOrbiterK = RotL64((aOrbiterK * 10004841288382726739U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11038155227307702976U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12408749795071243930U;
            aOrbiterD = RotL64((aOrbiterD * 5527720475032868855U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1673665849053496882U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12866353361497103629U;
            aOrbiterB = RotL64((aOrbiterB * 6041125499398924871U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10673935802381580966U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8946776538955520352U;
            aOrbiterE = RotL64((aOrbiterE * 12293084177712710021U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16294935203370452805U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4697759331563852212U;
            aOrbiterF = RotL64((aOrbiterF * 14407806317275373043U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 30U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterF, 30U)) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererH = aWandererH + ((RotL64(aScatter, 20U) + aOrbiterB) + RotL64(aOrbiterI, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 53U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterD, 14U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 3U)) + aOrbiterF) + aPhaseCWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 43U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 2
        // read from: aExpandLaneA, mSource, aKeyRowReadA, aKeyRowReadB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15825U)) & S_BLOCK1], 30U) ^ RotL64(mSource[((aIndex + 11095U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8978U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 9226U)) & W_KEY1], 42U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererE + RotL64(aIngress, 29U)) + 18191288703716505885U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 9824014524910417136U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 11953012029254917548U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 12U)) + 6297568011027199089U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 57U)) + 2576999400457367975U) + aPhaseCOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aPrevious, 3U)) + 13176139160575558254U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 9978408174563621810U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 46U)) + 16765834875061607142U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 35U)) + 16534507305459121344U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3114710944346151807U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10240517868726718592U;
            aOrbiterE = RotL64((aOrbiterE * 4645691562915606463U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10721450637990777883U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16689590768796583952U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3046344179729901637U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2427422768928450209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13495584061816457831U;
            aOrbiterK = RotL64((aOrbiterK * 6670984773768885119U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7058636403765106682U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9897341853944713767U;
            aOrbiterI = RotL64((aOrbiterI * 14286816859999869231U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17749559755733386064U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12515645083926326659U;
            aOrbiterH = RotL64((aOrbiterH * 6582878478865838245U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2625692458813609962U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10596240255026143019U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11605800195771080135U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12374290338067865540U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1507386663796330249U;
            aOrbiterG = RotL64((aOrbiterG * 1210241080424446087U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9288099549484146726U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15159312464747000702U;
            aOrbiterB = RotL64((aOrbiterB * 500055502081347757U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14998608679505446229U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17625038109437732009U;
            aOrbiterD = RotL64((aOrbiterD * 14785862243019841689U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterB) + aPhaseCWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 46U) + RotL64(aOrbiterH, 26U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 21U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterD, 47U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 58U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 39U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, aKeyRowReadA, aKeyRowReadB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 18374U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18258U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19597U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 23730U)) & W_KEY1], 18U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 60U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 56U)) + 13174219512651137892U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 43U)) + 2715455762789269341U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 1338018183235594313U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 16566866551729552930U;
            aOrbiterC = (aWandererC + RotL64(aCross, 52U)) + 6901845297307236726U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 11U)) + 2476078302049201718U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 15531109473927052260U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 19U)) + 4087849380858572351U) + aPhaseCOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 3U)) + 5167830630098599644U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7275995452428627217U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14794340370010024117U;
            aOrbiterE = RotL64((aOrbiterE * 8779497557416568379U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8509217403041662849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2321522025240806996U;
            aOrbiterA = RotL64((aOrbiterA * 113568101672878697U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5676672952755594051U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2304681269233504384U;
            aOrbiterD = RotL64((aOrbiterD * 15731441084605554497U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8383399721062437300U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13181984036942227666U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1648761328771932069U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13602604532551684210U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12725687663616352843U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4684699861686199753U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5831790822416009806U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4535048543735457407U;
            aOrbiterG = RotL64((aOrbiterG * 12076777878870257053U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10617608605149381858U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5244225377862618630U;
            aOrbiterB = RotL64((aOrbiterB * 15307177251167023999U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 18229989093139888456U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9728120630096192811U;
            aOrbiterH = RotL64((aOrbiterH * 16052574428163231023U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1312233443099767304U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8043115602160128619U;
            aOrbiterI = RotL64((aOrbiterI * 9365756845731616963U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 6U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 26U) + RotL64(aOrbiterB, 27U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 6U)) + aOrbiterA) + aPhaseCWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + RotL64(aOrbiterE, 39U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 56U)) + aOrbiterK) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, mSource
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30315U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 29183U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25226U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((aIndex + 27561U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 40U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 39U)) + 3255291173184001106U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 15308468160116255528U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 22U)) + RotL64(aCarry, 5U)) + 18186972408589866656U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 53U)) + 4439324265978331914U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 57U)) + 13099263173016322486U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 47U)) + 7041561081767500660U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 6196422612687812971U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 29U)) + 7664260932541281413U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 18U)) + 17802347823020441056U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4253107484061190446U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13799496534030645312U;
            aOrbiterA = RotL64((aOrbiterA * 9167675060053848207U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14252892847595951926U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5663527578664291422U;
            aOrbiterD = RotL64((aOrbiterD * 18314294235895182465U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 11148755959699137661U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17036900929333594592U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16041243617369003291U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2403828181385259549U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17813580350434928194U;
            aOrbiterG = RotL64((aOrbiterG * 13666780980793857831U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5623611126885414523U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7293224381174846969U;
            aOrbiterH = RotL64((aOrbiterH * 7032561584670788117U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10602620906929686163U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 18015916257203385982U;
            aOrbiterF = RotL64((aOrbiterF * 10684090189688871993U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13592915735376305773U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13995866908043417505U;
            aOrbiterC = RotL64((aOrbiterC * 3802175869395887331U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8200465989447697618U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9866671660800629464U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2138851839905326265U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11557528777230608777U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 131060617338185060U;
            aOrbiterI = RotL64((aOrbiterI * 11068705423012265209U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 54U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterA, 18U));
            aWandererH = aWandererH + ((RotL64(aCross, 18U) + RotL64(aOrbiterD, 51U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + aPhaseCWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterC, 47U)) + aPhaseCWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 24U) + aOrbiterF) + RotL64(aOrbiterA, 24U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_PickleBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6861U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3226U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3968U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 4242U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 35U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aScatter, 5U)) + 701291026547470433U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 39U)) + 17283292650462111643U) + aPhaseDOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 9969124091931303406U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 889176772718046988U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 58U)) + RotL64(aCarry, 57U)) + 6054541844643748084U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14703226235143028132U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7977975878522921062U;
            aOrbiterA = RotL64((aOrbiterA * 9030855800028448469U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16894322614172266274U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12160451749345900570U;
            aOrbiterG = RotL64((aOrbiterG * 18055355572903901749U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10870847008043897470U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8159920947172520247U;
            aOrbiterF = RotL64((aOrbiterF * 4833194641611011805U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 2440099120969517932U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2428396147731468007U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9363073341539598441U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2213226274394673479U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7079731443427765333U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16918930776877030559U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterA, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterD, 37U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterI, 56U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15229U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 13170U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10562U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15987U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 3973833383430652211U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 5760227042747169187U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 37U)) + 4923009065139227286U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 29U)) + 1477807307009107590U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 3U)) + 5707194514329007301U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5340439728375269724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17080457898946572387U;
            aOrbiterH = RotL64((aOrbiterH * 17719588880215414933U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 281559150259472813U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16160633048230910560U;
            aOrbiterB = RotL64((aOrbiterB * 16883442583309073785U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9003989610509592121U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10579322462808454333U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 100832431598087235U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 15059383289528723069U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10417647757852880956U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1457919230286043137U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14484665027393813330U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12344463053485837974U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5762654194001525041U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 26U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterI, 58U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 38U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24021U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19434U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19982U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22511U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 6342299552323486695U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 54U)) + 12692748514781367538U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 8202639945493229155U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 4439975701793231639U) + aPhaseDOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 39U)) + 16774235182859553759U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8764155413335405667U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7167848811974967685U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1052856924757654735U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16768278912125334220U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9090838954826296201U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5459329624017272077U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7644075729758006298U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17326182797908071215U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2408330168749256075U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16158809721888137555U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8029938783858263694U;
            aOrbiterD = RotL64((aOrbiterD * 12628072435324195483U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8716553521415553404U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7012599977009208840U;
            aOrbiterB = RotL64((aOrbiterB * 8775355876188948851U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 54U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterD, 4U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterB, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28923U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29759U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31516U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24920U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 44U)) + RotL64(aCarry, 3U)) + 6916817163240024692U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 14554930751292077817U;
            aOrbiterD = (aWandererB + RotL64(aCross, 19U)) + 1098305064484336101U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 12192821172420471527U) + aPhaseDOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 53U)) + 2435134991707318845U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1896745368738512624U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1114996424222923873U;
            aOrbiterD = RotL64((aOrbiterD * 6248754732325773087U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9839135798371512656U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8037967239603177043U;
            aOrbiterC = RotL64((aOrbiterC * 7848951103759663025U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15185468738487237432U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4912098316394854543U;
            aOrbiterA = RotL64((aOrbiterA * 3072785550384399929U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13142688607850380888U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4507379759608945839U;
            aOrbiterH = RotL64((aOrbiterH * 2989332387754215967U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7299006009652289342U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 5390655277207053627U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10973744708856143715U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterB, 3U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 21U)) + aOrbiterB) + aPhaseDWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 30U) + aOrbiterH) + RotL64(aOrbiterD, 46U)) + aPhaseDWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_PickleBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
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
    // GTwistRunTwist_C twist_loop_c (start)
    {
        // GTwistRunTwist_C twist_loop_c lane group
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6203U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3235U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4182U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2991U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 6361545377408870615U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 60U)) + 2967245486744774933U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 3836634268482850139U) + aPhaseEOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 7691642115360086297U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 53U)) + 16479280384178279281U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 43U)) + 2901468732552539249U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 5U)) + 2600353867755647475U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5666596904781510956U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16108791609267427553U;
            aOrbiterF = RotL64((aOrbiterF * 8904649663479834199U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8389926875737312112U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1689501721163024426U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6517194895779049139U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11721701506949917719U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3963842745030140473U;
            aOrbiterJ = RotL64((aOrbiterJ * 6692473494944919373U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8510538243472109368U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18281865214102080387U;
            aOrbiterE = RotL64((aOrbiterE * 1351546966368884609U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2259725140963665123U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11652011949557979650U;
            aOrbiterA = RotL64((aOrbiterA * 11260100762113295037U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1116085424226174473U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4725260319270802912U;
            aOrbiterK = RotL64((aOrbiterK * 4697109059565450269U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7348945429843437036U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1249234309180653260U;
            aOrbiterI = RotL64((aOrbiterI * 3136745255820405881U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 23U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterE, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 60U)) + aOrbiterF) + aPhaseEWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 4U) + RotL64(aOrbiterI, 13U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererK, 48U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11378U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 13083U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12935U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 12327U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 56U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 13U)) + 826930775230515406U) + aPhaseEOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 6U)) + 5137814617363250861U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 14761561947426681616U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 21U)) + 12773023438753662590U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 7331345852207096322U) + aPhaseEOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 27U)) + 3899381212671247460U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 10072004147620068599U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3424585039401897560U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8246760141625966321U;
            aOrbiterG = RotL64((aOrbiterG * 11478879365443736383U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3655992860610853290U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11154618022505863898U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4791494171286145231U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15629361991059709973U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 10842068502278489664U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17223002513104960799U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5571312349016336686U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 589313823745748879U;
            aOrbiterB = RotL64((aOrbiterB * 1356685926549786027U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13633457935771935260U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 12684602052812183096U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4689206269919806711U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5711307583717354204U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7181854170553728211U;
            aOrbiterE = RotL64((aOrbiterE * 9835601115561325911U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1884620014396115821U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1471516373272364262U;
            aOrbiterH = RotL64((aOrbiterH * 5126319375714848029U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterE, 11U));
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 20U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16832U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24041U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22908U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((aIndex + 19633U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 50U) + RotL64(aCarry, 3U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 8975885703279267062U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 8664844915562660637U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 14U)) + 12281774799736296726U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 27U)) + 15347461352311329726U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 3U)) + 12967500561828907834U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 37U)) + 5002833859280402726U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 11908257536954668983U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17017174811949227162U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16851323125613931180U;
            aOrbiterJ = RotL64((aOrbiterJ * 12446990992858763577U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13469326957728686706U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5228638551056105241U;
            aOrbiterK = RotL64((aOrbiterK * 13369947664646167255U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11945166198089308564U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16268645041872996022U;
            aOrbiterH = RotL64((aOrbiterH * 5391448793718370911U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14781204627695095701U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 5365325354838101092U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8017284997946310807U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 563147416025715953U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14660867395395625851U;
            aOrbiterE = RotL64((aOrbiterE * 4769458126865307103U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3168989056355712105U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16179131669773665579U;
            aOrbiterC = RotL64((aOrbiterC * 5641461617066671723U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4160220074225527179U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8597134686962559111U;
            aOrbiterD = RotL64((aOrbiterD * 639572585431474015U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterH, 51U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterE, 12U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterK, 19U));
            aWandererB = aWandererB + (((RotL64(aScatter, 10U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28257U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27853U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26258U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((aIndex + 32369U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 12U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererG + RotL64(aCross, 41U)) + 11521331427196538632U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 29U)) + 16653824187682957632U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 35U)) + 11654676587350088289U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 8010313317412193584U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 52U)) + RotL64(aCarry, 57U)) + 1108775560502907471U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 243952321439823521U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aCross, 13U)) + 2324945800401240403U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9257554497543369657U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16701314607244592540U;
            aOrbiterA = RotL64((aOrbiterA * 8790054741039817107U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3900445848034341782U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7652316487347103658U;
            aOrbiterK = RotL64((aOrbiterK * 11480123491361589799U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14980368605272070578U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 2001165460948764796U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8110980921827107649U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1911044015666991050U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11366207111147818339U;
            aOrbiterH = RotL64((aOrbiterH * 17234439040652553865U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16469329744002456607U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8062793687044950815U;
            aOrbiterD = RotL64((aOrbiterD * 5856142259851144369U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15364721421972807872U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8979915611483540231U;
            aOrbiterC = RotL64((aOrbiterC * 10899377466171153383U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7654234623563110457U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 1526832460342135008U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12766083052650723051U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 21U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterA, 41U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterE, 12U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 34U) + aOrbiterF) + RotL64(aOrbiterC, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 51U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_PickleBall_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
    // GTwistRunTwist_D twist_loop_d (start)
    {
        // GTwistRunTwist_D twist_loop_d lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_d loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 73U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((aIndex + 7055U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7019U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 2457U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 43U)) ^ (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 23U)) + 14823268998003220191U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 11U)) + 15295237288788213847U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 16434853402001133899U;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 48U)) + RotL64(aCarry, 11U)) + 7555911304407871631U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 14977248264994834620U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9707764144919392380U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 1277304385464681529U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2864691650462053463U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3089786220465849395U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3700503853358695085U;
            aOrbiterE = RotL64((aOrbiterE * 2079089949442685421U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3240054112993517371U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16897532076915366859U;
            aOrbiterJ = RotL64((aOrbiterJ * 4120874717534309035U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18167359289798364307U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8870819278575769863U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9334066154398059075U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15363069206212330251U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14858164441499725158U;
            aOrbiterG = RotL64((aOrbiterG * 14931933411393847915U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 53U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 22U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 37U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_d loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11727U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10981U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9237U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 11959U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 40U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 54U)) + 11410829607777684449U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 7502698839700975347U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 13267685058252106173U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 238242706996630625U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 3U)) + 8184695499511454281U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12767823220461985403U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12293198423143850330U;
            aOrbiterB = RotL64((aOrbiterB * 5073886956792823825U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11149495229952495939U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 7556992689338382800U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18232398462716803063U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3431338808774134649U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16863099140844995099U;
            aOrbiterK = RotL64((aOrbiterK * 752376661101787919U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17872458049880677604U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16760153457252546974U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11225037229069712805U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3115544493537438408U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4359882942759752958U;
            aOrbiterH = RotL64((aOrbiterH * 561477566995575801U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 58U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 20U) + aOrbiterB) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterF, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererF, 52U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_d loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17572U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 20620U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24344U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((aIndex + 18223U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 44U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 4476099022490972343U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 43U)) + 16836423700375760429U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 8850577488928703557U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 14U)) + RotL64(aCarry, 51U)) + 7091631824560042743U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 5U)) + 12560498899956759494U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7797973377112012161U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6173820673874805794U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15741300047917486527U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10805025132310245348U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7139216143268029968U;
            aOrbiterG = RotL64((aOrbiterG * 8349754682635765573U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8241544862261635722U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4735527016563596150U;
            aOrbiterA = RotL64((aOrbiterA * 6621354217673598381U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5166171126690294033U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11117641762075368393U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4980156869201219393U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6312932356458415421U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1304139291184508668U;
            aOrbiterF = RotL64((aOrbiterF * 90744653170922319U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 29U) + RotL64(aOrbiterF, 4U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterD, 19U));
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 38U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_d loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31097U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28421U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31219U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27268U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 35U)) + (RotL64(aIngress, 19U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 27U)) + 1898718075389870739U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 58U)) + RotL64(aCarry, 3U)) + 5631794889237247403U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 18219714659484524607U) + aPhaseFOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 15419581386225732921U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 47U)) + 9125575431710198210U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12205871520544965505U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7617534300497343422U;
            aOrbiterK = RotL64((aOrbiterK * 10052675719887595625U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18017579105368135814U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10693882161946020042U;
            aOrbiterJ = RotL64((aOrbiterJ * 2326507900303932855U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11669615701700895306U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11045110212889232165U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5965171269273719849U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 18019107802806469913U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12315940560472528716U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4505122470351404065U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4899009736070044310U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17412253404253730364U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10791901166391946485U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 48U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 29U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_D twist_loop_d (end)
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

void TwistExpander_PickleBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8043U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5547U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1852U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((aIndex + 6801U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 20U) + RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 2786079456995203065U) + aPhaseGOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 41U)) + 7237256119153857253U) + aPhaseGOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 13U)) + 9310834010563647604U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 56U)) + RotL64(aCarry, 57U)) + 17361734905706517877U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 15837111231884647451U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 18065431964418026445U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3029123922999952652U;
            aOrbiterJ = RotL64((aOrbiterJ * 16309219658285890145U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5166926595573507837U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1918425684273807598U;
            aOrbiterE = RotL64((aOrbiterE * 16616641579714896719U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4724551751012661440U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1818014487579644390U;
            aOrbiterG = RotL64((aOrbiterG * 14904092108647864911U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6670090372241084216U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8485757110007268693U;
            aOrbiterA = RotL64((aOrbiterA * 11876760095108618363U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4928130251509514742U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2528788422725346792U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1855982047967756661U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 13U));
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 48U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // grow_key_a loop 2
        // read from: aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10198U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((aIndex + 8589U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9425U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9800U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 4751694786009671052U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 16362725160370844224U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 13U)) + 6360885380915941057U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aIngress, 56U)) + RotL64(aCarry, 43U)) + 5154536007972297036U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 5U)) + 9362540581874808253U) + aPhaseGOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13902493871525612934U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10208452885367546542U;
            aOrbiterD = RotL64((aOrbiterD * 12067703239567933105U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3117030377279160998U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17286247690414027870U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4896931759653832095U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3930314320040949141U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7289525252391668404U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15452162299105112187U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3434167955466809185U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17852573095128575663U;
            aOrbiterK = RotL64((aOrbiterK * 1485660158767033425U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6137259687928853253U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 13992510605237574698U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15346263295995333395U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterE, 40U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterE, 21U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_a loop 3
        // read from: aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22559U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneD[((aIndex + 24227U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22379U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21771U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererA + RotL64(aScatter, 51U)) + 12046647397183218524U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 28U)) + RotL64(aCarry, 11U)) + 2760779375026461991U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 13735454443176855650U) + aPhaseGOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 4370377000586647724U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 3U)) + 14566322384189969094U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5056565959818422786U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8795403810686579209U;
            aOrbiterK = RotL64((aOrbiterK * 11205867337479457471U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9625947666256011567U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1703669290934254701U;
            aOrbiterB = RotL64((aOrbiterB * 5763881345676123583U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6664070663184147951U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2104148316797553431U;
            aOrbiterG = RotL64((aOrbiterG * 12887842067180975983U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1197910004222596145U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9922977170060903197U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13047828062605568603U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2048376210852567829U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12568990647075931409U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9860242601194210927U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 30U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterB, 11U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 40U)) + aOrbiterA) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // grow_key_a loop 4
        // read from: aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 24631U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32199U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30918U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((aIndex + 26786U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 38U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererB + RotL64(aScatter, 56U)) + 9855743441035905047U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 39U)) + 8426286937143990276U) + aPhaseGOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 7146752367170267002U) + aPhaseGOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 12947210066678101726U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 15902163559925328965U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8506649889346449469U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8226286036430263052U;
            aOrbiterH = RotL64((aOrbiterH * 7264199281303956141U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2703047093452420216U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6769351326360139560U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5318104980014706265U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9857025533281333281U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 238297452132277585U;
            aOrbiterG = RotL64((aOrbiterG * 12974709749856065985U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7203572312072908931U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12497027346166575632U;
            aOrbiterD = RotL64((aOrbiterD * 1703586436725662307U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 473851890609048879U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1664484956453886047U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8566500756326590209U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 4U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterC, 47U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterG, 14U));
            aWandererE = aWandererE + ((((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 3U)) + aOrbiterH) + aPhaseGWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 24U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_PickleBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 2488U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 878U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1368U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 6214U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 12U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aScatter, 60U)) + 5960680319644404115U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 16050752633567034185U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 8447503223226854741U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 14176813813397917591U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 35U)) + 10534915376130006644U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6866224454375302514U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16506374165041008396U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1326855300197233833U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7167814023968794098U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13870852197416596664U;
            aOrbiterD = RotL64((aOrbiterD * 17015971222069856463U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18064038854848993105U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9869630811507771691U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13723164383800461387U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 863613100452759380U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16597969741225436529U;
            aOrbiterJ = RotL64((aOrbiterJ * 2680793528887208903U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6575347108051310653U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17062262265485019063U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7601045488473620019U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + aPhaseHWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 54U) + aOrbiterD) + RotL64(aOrbiterI, 38U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // grow_key_b loop 2
        // read from: aExpandLaneB, aExpandLaneC, aExpandLaneD, aWorkLaneA
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 8790U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 14662U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12314U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10901U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 27U)) + 2915859148137000694U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 54U)) + RotL64(aCarry, 29U)) + 210680583721444425U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 37U)) + 6668118118775650387U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 15794200818099010989U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 6565076707062828369U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16323164497808856719U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7965435318816716560U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5984608704943623687U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7390281030573369017U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2269738866911824875U;
            aOrbiterF = RotL64((aOrbiterF * 1198697877998135567U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9664014216039993873U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 18284857398028357633U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8402008251343393737U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 367667619795303009U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7935945060956274197U;
            aOrbiterG = RotL64((aOrbiterG * 5481786693511955209U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16683666162337789540U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10655658270998102390U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15231596813382239841U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 36U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterF, 37U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 56U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_b loop 3
        // read from: aExpandLaneC, aExpandLaneD, aWorkLaneA, aWorkLaneB
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 20427U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 23239U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21667U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 22667U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 966899917801652720U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 19U)) + 10996327672320748649U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 4188171566846621107U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 5886209243097387959U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 36U)) + 14940428957136728111U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 179187285531914832U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6685351948936817752U;
            aOrbiterE = RotL64((aOrbiterE * 15533370414711696803U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1894506461704029700U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4182760368636977082U;
            aOrbiterG = RotL64((aOrbiterG * 972988091869133921U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12523318028514940790U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5059306166973366892U;
            aOrbiterF = RotL64((aOrbiterF * 2857409765717296483U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5890872367917643851U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17747338389865221534U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5306740664798049267U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 13906227834259884100U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7152105382899756368U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6772157117358310485U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 4U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 3U) + RotL64(aOrbiterF, 37U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 26U) + aOrbiterE) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 20U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // grow_key_b loop 4
        // read from: aExpandLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 30690U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 29027U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31080U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27498U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCarry, 53U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 13U)) + 2101601659597850213U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 2759794072560720121U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 27U)) + 9443562552411269339U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 10801360546699857975U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 47U)) + 8020716394829332019U) + aPhaseHOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 1021894212367773801U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13346855534622490176U;
            aOrbiterF = RotL64((aOrbiterF * 12668950387932320985U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16359309548462953836U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12642446944680783519U;
            aOrbiterD = RotL64((aOrbiterD * 12197935153255283321U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8197424982767553380U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14346334610901859094U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16982899923227935679U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14171304260534233539U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 334531601308283605U;
            aOrbiterJ = RotL64((aOrbiterJ * 5012968232749075075U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10707856298471572695U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18364775750091914766U;
            aOrbiterK = RotL64((aOrbiterK * 15735143943129143265U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + RotL64(aOrbiterD, 4U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 23U)) + aOrbiterF) + aPhaseHWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
