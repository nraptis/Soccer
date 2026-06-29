#include "TwistExpander_Boxing_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Boxing_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC38A75C0BC07F4CFULL + 0xAAE3E3A45036031AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEA4D6AC281169D03ULL + 0xC1C01002898723BDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9F5F2C6E2E6BB4C3ULL + 0xFBD9728D4C24ECD2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA38CA14F46FB6C31ULL + 0xDF8AA148CA7F4A75ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA5FE2835ADF86F57ULL + 0xC1EF20AA2B5366DAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x836AEA48B138E9D5ULL + 0x9AAC402D3F0EA9FAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8F4ABFCC3E37405BULL + 0xE4D19BC56CC82680ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFBA8782117881FC3ULL + 0xE9937A7B4C00FECDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC89F2F84CB2469F7ULL + 0x89C6D916C6B96CDFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD61EF276D7E9FE05ULL + 0xB05B565154AB08ADULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFCB3EDCB3460E8D7ULL + 0xB5B36DDB7B15670CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB388D6E0CC8CAC3BULL + 0x82E76FD2FC61AE03ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF68B77643684FA01ULL + 0x95C3B12317310FEAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8650F98607FE3DD5ULL + 0xF4B4ECDC7AFC41D6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDD7F3E96DBD99EC3ULL + 0xD448126F9DE01587ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8CBE4A39A70425A5ULL + 0xB67ED12B64C99F26ULL);
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
            aIngress = RotL64(mSource[((aIndex + 2750U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2591U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4834U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((aIndex + 628U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (aWandererH + RotL64(aCross, 51U)) + 3970829908171131502U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 19U)) + 7040283759419531991U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 3U)) + 11856292169397052901U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 53U)) + 819598588791819022U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 12U)) + RotL64(aCarry, 41U)) + 2176451710970866848U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 39U)) + 6454704928613390494U) + aNonceWordJ;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 21U)) + 11792122387218053841U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 37U)) + 9254780213489752211U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 14U)) + RotL64(aCarry, 21U)) + 16591812589999846482U) + aNonceWordP;
            aOrbiterC = (aWandererK + RotL64(aCross, 41U)) + 1471246223935074832U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 1424843083106386453U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1856469958050891629U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6331743690452052712U;
            aOrbiterH = RotL64((aOrbiterH * 15327924647897459645U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10351075711345476487U) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9518585245330480185U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 3792179827396760391U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 17787514620244712033U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14182328067398162557U;
            aOrbiterJ = RotL64((aOrbiterJ * 18107337388659070197U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12798088948801072444U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9563215159275202323U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7058145016617349141U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9904919772580498232U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16579777394992143043U;
            aOrbiterE = RotL64((aOrbiterE * 10516761340320196661U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6344049286854588503U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3531503618941046788U;
            aOrbiterD = RotL64((aOrbiterD * 10855385899703024105U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11334308840132700377U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11093833870078787770U;
            aOrbiterG = RotL64((aOrbiterG * 16105889714648555755U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3831491136025364271U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12505259454860591372U;
            aOrbiterC = RotL64((aOrbiterC * 6135450888433504093U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2210290810330253363U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10786160915224323113U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 799075068398619501U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7791474921127653867U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1046454625851499863U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18040454167287729591U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14636813124839719351U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3970829908171131502U;
            aOrbiterB = RotL64((aOrbiterB * 2737568880005765517U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 39U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 56U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterF, 23U)) + aOrbiterH) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterK, 54U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 48U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 8737U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7073U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7473U)) & S_BLOCK1], 22U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 7463U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 44U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 47U)) + 17019646486641172469U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 4U)) + 12276141179299971572U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aCross, 35U)) + 3617241694029841555U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererB + RotL64(aScatter, 27U)) + 6967963401259371737U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 57U)) + 6340709284279891017U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 19U)) + 456065368903896482U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 44U)) + 17686765719908116203U) + aNonceWordC;
            aOrbiterE = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 1322045955429785736U) + aNonceWordG;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 5163772703302372887U) + aNonceWordA;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 13268431135020363252U;
            aOrbiterB = (aWandererI + RotL64(aCross, 51U)) + 6538789950366849332U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10390344544314544893U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5087084271300584267U;
            aOrbiterJ = RotL64((aOrbiterJ * 15149302947570776165U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13423071121590981727U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 18324443012024134729U;
            aOrbiterA = RotL64((aOrbiterA * 15814349432207734533U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4129091815978464507U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17024797553831962245U;
            aOrbiterC = RotL64((aOrbiterC * 3137753479364378175U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6501545108779991661U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11930037791867597447U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 4904739567549702851U), 37U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 4667298703308315851U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6315980380900062127U;
            aOrbiterI = RotL64((aOrbiterI * 12080555704907924637U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12732382340390769888U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7792095326183864547U;
            aOrbiterF = RotL64((aOrbiterF * 12645556660611824631U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17428384983571405782U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3193205313177048443U;
            aOrbiterD = RotL64((aOrbiterD * 14488006565106259731U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2813743367131107264U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2742138679703780981U;
            aOrbiterK = RotL64((aOrbiterK * 18356569025783532225U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6270291142961043031U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3490174937775044998U;
            aOrbiterB = RotL64((aOrbiterB * 13879285210885619613U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13182535825771438942U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13047228760732694484U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10365428317468779549U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17926326514553542739U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17019646486641172469U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 13978838314848228053U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 36U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 27U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 6U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 24U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 39U)) + aOrbiterA) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 51U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterK, 12U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterB, 57U));
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 43U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterF, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 14U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 12086U)) & S_BLOCK1], 50U) ^ RotL64(mSource[((aIndex + 11271U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 12159U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16297U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 20U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 43U)) + 2101601659597850213U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 14U)) + 2759794072560720121U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 57U)) + 9443562552411269339U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 11U)) + 10801360546699857975U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 19U)) + 8020716394829332019U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 1021894212367773801U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 21U)) + 13346855534622490176U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 16359309548462953836U) + aNonceWordI;
            aOrbiterB = ((aWandererB + RotL64(aCross, 40U)) + 12642446944680783519U) + aNonceWordD;
            aOrbiterH = (aWandererK + RotL64(aScatter, 51U)) + 8197424982767553380U;
            aOrbiterC = ((((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 14346334610901859094U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14171304260534233539U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 334531601308283605U;
            aOrbiterF = RotL64((aOrbiterF * 5012968232749075075U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10707856298471572695U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 18364775750091914766U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15735143943129143265U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8531394793118363836U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15352876929406908882U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 475199047053777179U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 567682016232278157U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2068146551757663119U;
            aOrbiterJ = RotL64((aOrbiterJ * 1557877740957797555U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7776122587613256525U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16430938890724272256U;
            aOrbiterI = RotL64((aOrbiterI * 4540270493783593257U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11912000645055436094U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16800749242578741498U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17804584625034241737U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5909199180260499150U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5751089915336865588U;
            aOrbiterH = RotL64((aOrbiterH * 15376689503142397927U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3478216857728853008U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 18007567146937338241U;
            aOrbiterG = RotL64((aOrbiterG * 6620498877303917855U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17454259424163653490U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6276120962018305311U;
            aOrbiterA = RotL64((aOrbiterA * 7560618224285018801U), 23U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 3839336239901666431U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6230149015045237670U;
            aOrbiterB = RotL64((aOrbiterB * 1838983748994340883U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17552095486612766544U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2101601659597850213U;
            aOrbiterE = RotL64((aOrbiterE * 2915330118061857271U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterC, 41U)) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 21U)) + aOrbiterK) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 36U) + aOrbiterA) + RotL64(aOrbiterD, 19U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 34U)) + aOrbiterA) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 5U));
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ) + aNonceWordA);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterG, 30U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 20131U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 19639U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 18781U)) & S_BLOCK1], 27U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 16689U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19532U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 23U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (aWandererE + RotL64(aIngress, 35U)) + 8988572360732005217U;
            aOrbiterA = (aWandererH + RotL64(aCross, 43U)) + 17889613225105985335U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 26U)) + 15563478320513948626U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 3441351228410524816U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 41U)) + 4425592689451435346U;
            aOrbiterC = ((((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 12733160231627305928U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 39U)) + 3574152157304607854U) + aNonceWordC;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 15167631896729808783U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 60U)) + 15822667973915417055U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 29U)) + 17181685481076577637U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 51U)) + 9979204751408873468U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1334240485667164762U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9190066751460137016U;
            aOrbiterK = RotL64((aOrbiterK * 14585141844653660363U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15465215829109246336U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2305208282453624419U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 10257861974108363283U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16951510027310993926U) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 11117938943423526901U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7805486716716924787U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12461379120662979432U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11719697049048823897U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 14880996802304818757U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6843357278142933570U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12727898578324702374U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9786435451654365097U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 18127999660067652233U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11754709060558683082U;
            aOrbiterD = RotL64((aOrbiterD * 12798744012150745847U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16940151146420516184U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12924950783056761895U;
            aOrbiterF = RotL64((aOrbiterF * 8898170377271926745U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14829713915929878471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 840466047621042565U;
            aOrbiterC = RotL64((aOrbiterC * 10748511630509529489U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11469637840333471085U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5561780312837795893U;
            aOrbiterG = RotL64((aOrbiterG * 11935079844970978957U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1059834104159730610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10122108814456766430U;
            aOrbiterB = RotL64((aOrbiterB * 2184693583782179921U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14857099570072635006U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8988572360732005217U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14409836741925393077U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 28U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 29U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterB, 51U));
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterJ, 23U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 58U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 37U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 58U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 43U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 14U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererC, 30U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 25991U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 25004U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25277U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22899U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25190U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 23375U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererI + RotL64(aCross, 42U)) + 13278949403988203974U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 9213599924054673756U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 37U)) + 1255746482932381798U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 23U)) + 11575321997144516122U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 11U)) + 15881587525529432437U) + aNonceWordJ;
            aOrbiterA = (aWandererD + RotL64(aCross, 4U)) + 9846195809864862707U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 39U)) + 12319815691858217670U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 27U)) + 16322617427294439587U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 16332130810525887437U) + aNonceWordK;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 4920951156015336794U;
            aOrbiterE = (aWandererB + RotL64(aCross, 21U)) + 16767126455124552329U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 12553595911087945223U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1437522202135436142U;
            aOrbiterC = RotL64((aOrbiterC * 2001992794165550905U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12313100454852227143U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2761983020631055729U;
            aOrbiterA = RotL64((aOrbiterA * 3874839760378039509U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17635303588421554367U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 788212489507463763U;
            aOrbiterK = RotL64((aOrbiterK * 17896475584538528059U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5192552894670654434U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6784748488807738811U;
            aOrbiterF = RotL64((aOrbiterF * 8077237651953896479U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16113417046719114943U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1096874945215225916U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17308604412622879833U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7610274704570171595U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10466070212284342550U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6449728258497920613U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6777845928873855221U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5251515022021984126U;
            aOrbiterD = RotL64((aOrbiterD * 9018277343404261611U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13849343158824111498U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7977711210181714021U;
            aOrbiterI = RotL64((aOrbiterI * 4182053966171053577U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6494539818728106982U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11314590450226080781U;
            aOrbiterE = RotL64((aOrbiterE * 12455979257225599157U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 552687702594328012U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14961304171192292246U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 846375892915484717U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9771874402848476494U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13278949403988203974U;
            aOrbiterG = RotL64((aOrbiterG * 2119203863777871233U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 54U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 56U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 50U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 46U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterA, 21U));
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 14U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 31634U)) & S_BLOCK1], 20U) ^ RotL64(pSnow[((aIndex + 28773U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31926U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31122U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31962U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 28949U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 57U)) + 12980104182836602177U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 3172622203188863995U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 41U)) + 1170974132219980203U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 24U)) + 6035201940965047490U) + aNonceWordO;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 18033907118424996722U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 29U)) + 14604813424800580304U) + aNonceWordJ;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 13720232492851066035U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 35U)) + 3902659710585257448U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 47U)) + 8331560652661619868U) + aNonceWordC;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 10U)) + 4485014147538689794U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 39U)) + 168202636924512424U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16227825670092707848U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4792781933944671365U;
            aOrbiterE = RotL64((aOrbiterE * 15859849676231455283U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12636865372722601282U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 18198291399585556632U;
            aOrbiterH = RotL64((aOrbiterH * 18155803890313399795U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3650053185419807206U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5897288963905408776U;
            aOrbiterD = RotL64((aOrbiterD * 3706949366974086151U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9922308113622901726U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13352279749091561510U;
            aOrbiterF = RotL64((aOrbiterF * 4025213180483632557U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14969461950939646117U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10231661776135056651U;
            aOrbiterC = RotL64((aOrbiterC * 11284575051455238501U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10621934544068320859U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6029116920305246887U;
            aOrbiterJ = RotL64((aOrbiterJ * 6087523725059376905U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12887482425168671195U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8351351557123783853U;
            aOrbiterA = RotL64((aOrbiterA * 3839381627914762245U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5405938210926464973U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 385145802287899406U;
            aOrbiterI = RotL64((aOrbiterI * 8330751480464271445U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7907749190875916461U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5138733192253468642U;
            aOrbiterG = RotL64((aOrbiterG * 17028325976353263843U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14382272868178763187U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14354777100157531233U;
            aOrbiterK = RotL64((aOrbiterK * 7095764230272037767U), 41U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 4390647647193363824U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12980104182836602177U;
            aOrbiterB = RotL64((aOrbiterB * 11124472075872147333U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterK, 43U));
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 37U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aScatter, 36U) + RotL64(aOrbiterB, 26U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 23U)) + aOrbiterD) + aNonceWordD) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 47U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterC, 19U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 41U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterI, 4U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Boxing_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8C1784D6714EDDCDULL + 0xDB5FBF3F3F7320A2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x87924DED8F27401DULL + 0xF9B0C58895429ADFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDF6E05F565A3D1E5ULL + 0xC6AE79137CCF5630ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA946165F5C2F902BULL + 0xAF2AFF6696E628B0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD0F41E220624F307ULL + 0xE4DDA0CD889D71C8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE38D070BE59E6845ULL + 0x9B2241E85E323625ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD1C95BB3A8E9E6DFULL + 0x99567C52C1C496F2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF21FEB6628591221ULL + 0x9C70A9D2C39AC5A3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF4D4D7BE4F082629ULL + 0xB0D1B60EA1A6A834ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE0945838150120F7ULL + 0xACAAFB5DDB3FA19EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8204116A63CE8709ULL + 0xFA1F007D583A50EFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDBBB1CE8424F56A7ULL + 0xF1C491E616BD70A9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEE738E8815993135ULL + 0xFD068687F76521B3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB39376B0EAB89441ULL + 0x89C4BF31DA4036F6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8591E9A70AFA8357ULL + 0xF580451C548AB085ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF9E3D42E4F63CB57ULL + 0xD7D8781FF3461CD3ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 5187U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneB[((aIndex + 3360U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1479U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 1754U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCarry, 4U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (((aWandererC + RotL64(aIngress, 4U)) + 17081642665820489793U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aWandererK + RotL64(aScatter, 47U)) + 14468854040067229623U;
            aOrbiterG = (aWandererG + RotL64(aCross, 39U)) + 2249450222593057429U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 14964389079511378664U) + aNonceWordE;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 21U)) + 17003491054252360650U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 11U)) + 12710882240582032588U) + aNonceWordF;
            aOrbiterE = (aWandererF + RotL64(aIngress, 43U)) + 9887078182156755359U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 7665284531810584704U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 30U)) + 7304284015511876717U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5517927023543751734U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17704756310857362759U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 15826832172923213591U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11347400363019508578U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11696395232760991243U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9725231749679442003U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10875780291242873583U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7808740614343437672U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 8889516201913716283U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3145390996141902032U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16080636485642732615U;
            aOrbiterC = RotL64((aOrbiterC * 7445756373012217305U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3929263288176983844U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18210228766683996806U;
            aOrbiterH = RotL64((aOrbiterH * 13178080076505449091U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13948962323541421431U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3037683309790156893U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13406672352222636739U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17827265198532699474U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7270895262023504864U;
            aOrbiterD = RotL64((aOrbiterD * 13467417362477308167U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 6431243064980879185U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6680205390976259885U;
            aOrbiterJ = RotL64((aOrbiterJ * 10421386694108590789U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15910655919164357152U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 8046213498216027383U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18061867495824063553U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 20U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterK, 36U)) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 56U)) + aOrbiterG) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10486U)) & S_BLOCK1], 18U) ^ RotL64(aFireLaneB[((aIndex + 15533U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14108U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9139U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 8215U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 58U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 16124889768301047791U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 11912338587186717280U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 35U)) + 8594012868813114354U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 52U)) + RotL64(aCarry, 53U)) + 18281043566156682815U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 5U)) + 16853106130200942302U) + aNonceWordA;
            aOrbiterG = (aWandererI + RotL64(aScatter, 41U)) + 2611212958619673086U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 19U)) + 18039472325066855180U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 23U)) + 14495785571345122046U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 48U)) + 4556063793412832418U) + aNonceWordE;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14896419970271244358U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 880028529183500036U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 14228281807461251361U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2379557167489415783U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11854373946064529806U;
            aOrbiterG = RotL64((aOrbiterG * 150755294320438887U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1487252775956449964U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12777924204511625545U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 1366019527386994789U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15998631485222477969U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8864212892296191613U;
            aOrbiterC = RotL64((aOrbiterC * 579242788050369815U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17069347835763226743U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7443008171694679791U;
            aOrbiterK = RotL64((aOrbiterK * 748894368884566607U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17334256152350782002U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8986626119086556393U;
            aOrbiterI = RotL64((aOrbiterI * 2258172145924120235U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8528180968228358674U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12702290928064582589U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15673603224146737631U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7742438100860023610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3729687240959702198U;
            aOrbiterA = RotL64((aOrbiterA * 3756794766163746783U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 426129097367382096U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16782175452274911213U;
            aOrbiterD = RotL64((aOrbiterD * 1041477289638333659U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 54U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterH, 34U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 43U)) + aOrbiterD) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterC, 39U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 23U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 27U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 28U) + aOrbiterK) + RotL64(aOrbiterI, 51U)) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterB, 56U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23463U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 23586U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22191U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22132U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19753U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22094U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 3U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (((aWandererF + RotL64(aScatter, 24U)) + RotL64(aCarry, 51U)) + 5295352595333316211U) + aNonceWordE;
            aOrbiterI = (aWandererI + RotL64(aIngress, 47U)) + 2341795367042042605U;
            aOrbiterK = (aWandererB + RotL64(aCross, 43U)) + 10122175780504033663U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 10084612804696198554U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 16470424309851045971U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 11U)) + 656016130975227994U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 60U)) + 15313268829659834317U) + aNonceWordJ;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 35U)) + 3795220914993923394U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererH + RotL64(aCross, 19U)) + 14044442220988813825U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3804224626734584802U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7980006306010255693U;
            aOrbiterK = RotL64((aOrbiterK * 13958505239726088561U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13746830564584711549U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11852212099729274845U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2164880979318247855U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9083223471018084847U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13706723820703853346U;
            aOrbiterE = RotL64((aOrbiterE * 11361854103656219887U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1713819986642275223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1382000168233902914U;
            aOrbiterG = RotL64((aOrbiterG * 3894160765130198157U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4540474625764565485U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1756168174375757220U;
            aOrbiterC = RotL64((aOrbiterC * 12739160208010092017U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 1409297070183609309U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6082750101445444357U;
            aOrbiterJ = RotL64((aOrbiterJ * 17438740230251860935U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1113239890859479202U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10932192439503964363U;
            aOrbiterB = RotL64((aOrbiterB * 5915660289913324281U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 3732595033748508428U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5117760372351117286U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2671510075176315761U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7399968659654088641U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14835608167871904147U;
            aOrbiterH = RotL64((aOrbiterH * 8312521710415756159U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterK, 22U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterH, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterB, 18U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + aNonceWordH);
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 43U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28774U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((aIndex + 31434U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31722U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30954U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26344U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 28719U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 18U)) + 9080426856729228705U) + aNonceWordF;
            aOrbiterI = (aWandererI + RotL64(aIngress, 39U)) + 7851218321653539276U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 3U)) + 7023344692919298036U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 9772846154227440734U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 35U)) + 12008298632429608431U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 46U)) + 12201090455849562875U) + aNonceWordB;
            aOrbiterE = (aWandererG + RotL64(aScatter, 53U)) + 9498721803411445471U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 351203764023093632U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 4966360430644539250U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9194167899071345693U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 4922477697284269116U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 8444814161720407881U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15742625291642356429U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7528703106518431730U;
            aOrbiterA = RotL64((aOrbiterA * 11530049278751507567U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 15279053574704935317U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2425839793660355555U;
            aOrbiterB = RotL64((aOrbiterB * 11486964816849830667U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13209849392400008898U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9041500097716231309U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 340661035700748739U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7885423750878814599U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1992993999902904603U;
            aOrbiterI = RotL64((aOrbiterI * 1478629826632201617U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6120758615019314102U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8529621625846992066U;
            aOrbiterD = RotL64((aOrbiterD * 8485991471612862467U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9125182130757385320U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15691232622970220043U;
            aOrbiterG = RotL64((aOrbiterG * 16517916951054758147U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11413090085435424697U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11563151001080914939U;
            aOrbiterH = RotL64((aOrbiterH * 16828196274450408201U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1778975369262558069U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3232132443557192010U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17132823737792200981U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 50U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 18U) + aOrbiterA) + RotL64(aOrbiterD, 52U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterD, 29U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + aNonceWordN);
            aWandererF = aWandererF + (((((RotL64(aCross, 10U) + RotL64(aOrbiterI, 5U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterF, 34U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 23U)) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Boxing_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCD1C090D8CCA0963ULL + 0xF018AB7F80CAAF45ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF303219CB2ADE691ULL + 0xFCE91BC3D789DC11ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE0E751399FA75407ULL + 0xB80FF6BA664259A8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE8B8127FDB9B81BDULL + 0xEDADD4EC4890231AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF5D8A9B73E85BCD1ULL + 0xF83558AC1005DD13ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8B144E86FA8876F5ULL + 0x86C45E4D153B541AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x840AF2F3ECD1A967ULL + 0xEBBB3F5BFC840C44ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA889E902095E82B5ULL + 0xFC7067A8FFA97956ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC55895402376EF85ULL + 0xAAD6364A54585B5EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8B93DDF92B29253DULL + 0xE41357E548714C7BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8D8771AA404472E1ULL + 0x95C0FE548E72DB6AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAB47A45CBF203E9DULL + 0xB6203999693E821CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDEC152D58D22CB15ULL + 0xA1268BD85F898E97ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEA5643E7F9850ACDULL + 0xFDCA347973675081ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x88805838F2C4EEEBULL + 0xF5993113BA709EA5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC6962D06F7479711ULL + 0xEE02554B7D4361E4ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneB, aWorkLaneC, aFireLaneD
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1994U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((aIndex + 4463U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1621U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2128U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4199U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 20U)) + (RotL64(aPrevious, 35U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 12632404972795375757U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 20U)) + RotL64(aCarry, 5U)) + 5351879979055988456U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 39U)) + 3597737727467443413U) + aNonceWordK;
            aOrbiterH = ((((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 2830846754917852318U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 29U)) + 17311925960294518018U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2083584640523695383U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15049343611387010158U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5567816356477420399U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6443050378205811147U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6021965178697344070U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 6054064448935006741U), 39U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 5080289878758029976U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 576927745306972983U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 16008958833683246115U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4728489691382690859U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6184355840165758855U;
            aOrbiterB = RotL64((aOrbiterB * 1515043910404156423U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 11220539885798595450U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11091438724966718214U;
            aOrbiterE = RotL64((aOrbiterE * 8225347114759391961U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 21U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterB, 43U)) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterK, 34U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterK, 57U));
            aWandererB = aWandererB + (((((RotL64(aIngress, 42U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 3U)) + aNonceWordL) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererI, 54U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14799U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 8675U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16108U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9093U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12168U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 11360U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 1042610313571524121U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 37U)) + 3505725321008825582U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 12584654563843782991U) + aNonceWordM;
            aOrbiterK = ((((aWandererB + RotL64(aCross, 48U)) + RotL64(aCarry, 35U)) + 6645399144515770935U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 21U)) + 3608978423753715584U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8089198857670370983U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15207251813516399879U;
            aOrbiterG = RotL64((aOrbiterG * 7596841660069752069U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9579268660105824516U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16055044469473802812U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2269649280637188723U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 583811872609805949U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7027491967970873942U;
            aOrbiterC = RotL64((aOrbiterC * 12686754713465826139U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 18256061823189677508U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 12708429127816136937U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 12593886633108075321U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12169216645156306078U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12694325407567795065U;
            aOrbiterH = RotL64((aOrbiterH * 3711789483877261899U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 41U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 21U)) + aOrbiterC) + aNonceWordO) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterK, 29U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterD, 54U)) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 14U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 13U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20007U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 18806U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24369U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22431U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16585U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 18242U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 6U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (aWandererK + RotL64(aPrevious, 35U)) + 13499155707765393469U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 3740324981823726185U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 5470765363949735652U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aScatter, 14U)) + RotL64(aCarry, 53U)) + 3446436171274452326U) + aNonceWordG;
            aOrbiterI = ((aWandererC + RotL64(aCross, 23U)) + 1778929412631211933U) + aNonceWordK;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14666308799855220954U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4548410236791175055U;
            aOrbiterF = RotL64((aOrbiterF * 6822908616815218501U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5829739767694190372U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 14319231414903675748U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 4966501102515775601U), 19U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 1513851750246111405U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1685620217748986019U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9286548037413609445U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16284162182006054402U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6271539598462003309U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13923286694131331137U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12669312437565969473U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11894755313393001665U;
            aOrbiterI = RotL64((aOrbiterI * 12556759675372354075U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + aNonceWordA);
            aWandererK = aWandererK + (((((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterI, 5U)) + aNonceWordB) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterK, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28396U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 27733U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28673U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32151U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24652U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29308U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 26734U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 36U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (((aWandererA + RotL64(aCross, 28U)) + 77518479758428414U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 4832061802166300011U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 11695291171006574112U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 7467412817843260094U) + aNonceWordG;
            aOrbiterB = ((aWandererC + RotL64(aCross, 51U)) + 17801484124471154757U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5555455638503958639U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5669470540733721606U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17219613748084498879U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3042388456327784163U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2236734925228156691U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10076582424701705531U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14459720401528685450U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4814967631216658856U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18288097536171386643U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16950679344449075945U) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6262238639302011050U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 9942659897425088183U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3522256359074996724U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12524717897707074242U;
            aOrbiterB = RotL64((aOrbiterB * 6787771338063891989U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + aNonceWordM) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 40U) + aOrbiterI) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterE, 11U)) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterF, 30U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Boxing_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x86D2AB1EA7EF63DFULL + 0xFC118B5CEE058FA1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD0D2402D69EEADD9ULL + 0xD65CCE0A34A14CDEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD1D051C49002032FULL + 0xEB0B712AF76880FEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBFC03B70AFD60A0DULL + 0xD447F55BDEA2392BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFAB48749AB54545BULL + 0x88107BE1099D850BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x91A623486945CFF7ULL + 0x83AABE6363EA9114ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD236CA50CF692C67ULL + 0x85013F48EF1EB09BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDCE4C77A2A2ED0FDULL + 0xAB4FCA592C233B47ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCC5BF8B6A19C8D03ULL + 0xEF1FEE985B017B9BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9780BD5F7C08F151ULL + 0xB35E4CD0B71016D3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE491BB163856FAD5ULL + 0xD679FEDA89B5540DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBD70B30D10D46105ULL + 0xC3AA5D094C6A7548ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAC457BC552EB08D3ULL + 0x93C28A5AE5FEFB08ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9E7E2AF604F8E42BULL + 0xD84682970F04C807ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA9EF76CB84F17913ULL + 0xB89E1B73A7319E7FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9593291EBD8FECA5ULL + 0x8531533D882A8BDCULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneB, aExpandLaneC, aExpandLaneD, aFireLaneA, aWorkLaneA, aFireLaneC, aOperationLaneD, aWorkLaneB, aOperationLaneC, aOperationLaneA, aWorkLaneC, aFireLaneD, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1068U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 7912U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 6840U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3697U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6338U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1894U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 36U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 1087148170018530502U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aWandererH + RotL64(aCross, 13U)) + 15530846874509311414U) + aNonceWordO;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 57U)) + 16987358651515511212U) + aNonceWordK;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 19U)) + 12504143181007924259U) + aNonceWordP;
            aOrbiterH = ((aWandererK + RotL64(aCross, 50U)) + RotL64(aCarry, 27U)) + 393322117322732418U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 3U)) + 14325937299241887166U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 9395262907017475742U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 13658510441418344769U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6410754322737005336U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 6932217611373076391U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9257290738538818434U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7489828960857692286U;
            aOrbiterA = RotL64((aOrbiterA * 16519674788777989043U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4118778591214588387U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16619215231168796563U;
            aOrbiterK = RotL64((aOrbiterK * 14876884956536265157U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11326283811003573430U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1865401866017614604U;
            aOrbiterJ = RotL64((aOrbiterJ * 8378326058282460073U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 670150121105733604U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1499331510641068749U;
            aOrbiterH = RotL64((aOrbiterH * 16623742535540383107U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1116410848560838532U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2696841341036281779U;
            aOrbiterB = RotL64((aOrbiterB * 9598953298074904869U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5487352391229549881U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12008243050943342979U;
            aOrbiterG = RotL64((aOrbiterG * 9087261224804582459U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 41U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 58U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 36U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 6U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15834U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((aIndex + 8733U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13893U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13200U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11154U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10368U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 20U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 3448371607470865612U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 51U)) + 3743742913651580573U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 13069491287948807280U) + aNonceWordE;
            aOrbiterI = ((((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 16872779275586545632U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererD + RotL64(aIngress, 30U)) + 17945792656755062795U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 41U)) + 18199747196793731853U) + aNonceWordC;
            aOrbiterH = (aWandererH + RotL64(aScatter, 23U)) + 15953311878379809513U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 941268763494588338U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10090221530365796809U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14035236086292997613U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8335698093307607001U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 6147498804734306100U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6904444049941211327U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5980246079567570090U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4152167624425912978U;
            aOrbiterJ = RotL64((aOrbiterJ * 10019421651535123573U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14990418790239735916U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3418668387496597219U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 12814077238529863119U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4206650904177199425U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3905470780938996069U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16030122739273137005U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9968672788233080924U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 602258075661864866U;
            aOrbiterH = RotL64((aOrbiterH * 2615726693066300065U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 17751667243048041383U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2414054413585296027U;
            aOrbiterK = RotL64((aOrbiterK * 1049512574773201893U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 54U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + aNonceWordB);
            aWandererJ = aWandererJ + ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 12U) + aOrbiterC) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 36U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneC
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21807U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 20112U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 19071U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19804U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22231U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 23566U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 24U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (((aWandererA + RotL64(aIngress, 3U)) + 7948891781097675369U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 13928362874228230226U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 43U)) + 10776180542602258926U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 5735115172149470447U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 5353591822981766987U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 10U)) + 562301708107268570U) + aNonceWordH;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 57U)) + 10467810247578364868U) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14541630141152308564U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 2350076897065139429U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 12222554362482034393U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17519109078651162228U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6061035173339902910U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 10021905773432907835U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15654836633731000065U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13723521735153718904U;
            aOrbiterH = RotL64((aOrbiterH * 14459516479283070563U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2849680038315532197U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17336102435576647923U;
            aOrbiterE = RotL64((aOrbiterE * 10984689101753586739U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7671010488872356142U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11485114338165600777U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4162584865462407791U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8759060657343458985U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11009137869375286581U;
            aOrbiterA = RotL64((aOrbiterA * 8741417343929809115U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 15792999392743144135U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6180808423175992479U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 13681230339693676907U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 28U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aPrevious, 56U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 56U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 21U)) + aOrbiterH) + aNonceWordA);
            aWandererK = aWandererK + (((((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 27U)) + aNonceWordD) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneB
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29595U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 31851U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30812U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31367U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27488U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27862U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 14U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 11998579547770778580U) + aNonceWordL;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 8409465187298704610U) + aNonceWordH;
            aOrbiterB = (((aWandererF + RotL64(aCross, 50U)) + 3470222286110333500U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 5704486785203069994U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 41U)) + 10334944660253279633U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 57U)) + 7626852700722567477U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 23U)) + 14631310754943209743U) + aNonceWordN;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 807160297237854120U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5624154783624196107U;
            aOrbiterB = RotL64((aOrbiterB * 2404066593958052159U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4971444394698940423U) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6340057638461027062U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12027586111086798629U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 9003019862787819481U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13632057463595873033U;
            aOrbiterE = RotL64((aOrbiterE * 12575202147280216765U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 12766104026871797746U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4062118445824915939U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13130770039048080701U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5258212525426469978U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9956946981015983939U;
            aOrbiterA = RotL64((aOrbiterA * 8106382657040497669U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10837606223056473999U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13292864885504191134U;
            aOrbiterF = RotL64((aOrbiterF * 4445739587553669471U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 166087925900318658U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6786842221885441388U;
            aOrbiterI = RotL64((aOrbiterI * 4411147600413147773U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterA) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterG, 13U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterF, 51U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 50U) + aOrbiterA) + RotL64(aOrbiterI, 42U)) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Boxing_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAA01B2B067C59945ULL + 0xD0ADB5668165D6F0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA1EE89CCD2458DFBULL + 0xD9F3DAA9769C3293ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xACE5445F0B2370BDULL + 0xA6AC4175D4481A35ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x89829DBFDD5770FDULL + 0x911396AE7C161590ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC47D009FEE3DE491ULL + 0xE88543BED15A0581ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFDE760FF256E4969ULL + 0xB748DA3AE8E763C8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAF0DD7A537A103D5ULL + 0xD2A94DFF0EEBD6BEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCB6AD9E1A11E27B5ULL + 0xF46F630C6E4B06A0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x97A2E5C831DBDDE9ULL + 0xB348044ACA3716F4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8441DC5C704BC63DULL + 0xFD314F176C3B49F7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9C3A00062ACF0D77ULL + 0xBF007FB9C2516CD3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF33A23ADF021EF91ULL + 0x86958317599F0BC3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC70B74E7F70F4E33ULL + 0xF46A3A21937BE54CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE918733E1D945BA3ULL + 0xCEAD869485830A37ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF0757E441AC382FBULL + 0xCBF049CA22BF682CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC92C9916656DDED9ULL + 0xC5C8E8247F3C5EEEULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aWorkLaneD, aOperationLaneA, aExpandLaneA, aFireLaneC, aFireLaneA, aExpandLaneB, aFireLaneB, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4077U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 1912U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4476U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2463U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5555U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6956U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 26U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 12980104182836602177U;
            aOrbiterC = ((((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 3172622203188863995U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 51U)) + 1170974132219980203U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 42U)) + 6035201940965047490U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 23U)) + 18033907118424996722U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 14604813424800580304U;
            aOrbiterI = (((aWandererB + RotL64(aCross, 3U)) + 13720232492851066035U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3902659710585257448U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8331560652661619868U;
            aOrbiterG = RotL64((aOrbiterG * 11418103770615560205U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 4485014147538689794U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 168202636924512424U;
            aOrbiterF = RotL64((aOrbiterF * 13711020666131492091U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16227825670092707848U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 4792781933944671365U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 15859849676231455283U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12636865372722601282U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 18198291399585556632U;
            aOrbiterC = RotL64((aOrbiterC * 18155803890313399795U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3650053185419807206U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5897288963905408776U;
            aOrbiterD = RotL64((aOrbiterD * 3706949366974086151U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9922308113622901726U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13352279749091561510U;
            aOrbiterK = RotL64((aOrbiterK * 4025213180483632557U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14969461950939646117U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10231661776135056651U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 11284575051455238501U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 4U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterC, 41U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 13U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 46U) + aOrbiterK) + RotL64(aOrbiterF, 23U)) + aNonceWordA) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterD, 11U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11733U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 12108U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 13157U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8280U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10726U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13883U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aPrevious, 60U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (((aWandererC + RotL64(aScatter, 5U)) + 4848316479321533394U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aWandererK + RotL64(aCross, 11U)) + 6919360256662636195U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 9897013582181108544U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 57U)) + 7319353809896158678U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 50U)) + RotL64(aCarry, 11U)) + 2848175435514849859U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 6967780718720437934U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 29U)) + 10143884766603388136U) + aNonceWordK;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8675965006150972051U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16350117755560994281U;
            aOrbiterE = RotL64((aOrbiterE * 15072308930382994425U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 17976597517118423760U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1399631141355370237U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 16537788276543236833U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3590613762034716792U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5134624314245932157U;
            aOrbiterF = RotL64((aOrbiterF * 13077589037975283371U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10082236952942943654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4015535035905433450U;
            aOrbiterH = RotL64((aOrbiterH * 4961808568701908559U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 611474103801573800U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5786708483794098001U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7694007039340089267U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 5201943497363274455U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9282160506938328489U;
            aOrbiterI = RotL64((aOrbiterI * 5368182164239021367U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4932320527498940158U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11576526341731392916U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1712051774729439363U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterI, 53U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 20U) + aOrbiterE) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 28U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterG) + aNonceWordL) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterE) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 47U)) + aOrbiterA) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21717U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneD[((aIndex + 22036U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21279U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20426U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19169U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 16610U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 47U)) + 7893287783892523139U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 54U)) + RotL64(aCarry, 21U)) + 10257331997383491153U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 27U)) + 14562226733652231753U) + aNonceWordJ;
            aOrbiterB = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 14320342577110737851U) + aNonceWordK;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 37U)) + 9816717579822880756U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 13U)) + 9558926960095881953U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 3U)) + 9230371862654338324U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6414274291252913420U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13868546184398350849U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1547986864837497409U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16940736952569949038U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2866957764814864371U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 3554702178644797003U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7916721976073979724U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1602444214978842275U;
            aOrbiterC = RotL64((aOrbiterC * 11072503711308122385U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9529061385251008037U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8402775110887376588U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 13980225144628227381U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15003592180290390713U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14195681406520825751U;
            aOrbiterJ = RotL64((aOrbiterJ * 11455000833788877217U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3263577002367714202U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12019422062655581928U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5002313835338447799U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8508638054582582917U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6536618106353552880U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 6233964121117511885U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 37U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 60U)) + aNonceWordE) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + aNonceWordF);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 20U) + RotL64(aOrbiterD, 43U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27295U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 31218U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28451U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30719U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30780U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28029U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 27U)) + (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 5697928251815176134U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 57U)) + 337587740689259575U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 19U)) + 4927686903263973950U) + aNonceWordN;
            aOrbiterH = ((aWandererA + RotL64(aCross, 13U)) + 3742409032569801033U) + aNonceWordD;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 29U)) + 1608092659172197650U) + aNonceWordA;
            aOrbiterG = ((((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 15848744267145717509U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (((aWandererI + RotL64(aCross, 46U)) + RotL64(aCarry, 27U)) + 15300174177963339253U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14162868453323648628U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12020167069983729869U;
            aOrbiterC = RotL64((aOrbiterC * 2071080217680099017U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16259538291658723956U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8516686212464112245U;
            aOrbiterG = RotL64((aOrbiterG * 4731296903548893627U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3722184575520553132U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5663609293306386784U;
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15265344442454471986U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3050323350098829515U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 5890624677162388135U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1093356813820599238U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15167726103772238440U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 5719466863561311069U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15170797965325981472U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17826286701992981628U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11186808881726573677U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14710892030473425181U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 397194787697553904U;
            aOrbiterH = RotL64((aOrbiterH * 14368930300818752833U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterK, 48U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aIngress, 28U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterK, 11U));
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterA, 5U)) + aNonceWordH) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Boxing_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBEB9AFE0AA10403FULL + 0xEBDBECADE0F41DE7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF9F4FE43FB646A91ULL + 0x836B1B0F5941F25DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF48BFC9604158E4FULL + 0x9058ECD37DE69D11ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF88FE18B27C0E065ULL + 0xEDB8AA3ECABBF3C9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA6F24408E65D07A9ULL + 0xB4D2C6010C5802ACULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA2CD41FD99198D89ULL + 0xC4A18DBB573E78B2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x85936980080187B7ULL + 0xECD28EEF8E37A507ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD8A096E04A6CC201ULL + 0x908621874BC169A3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF0A97637B03A5FDFULL + 0xB25D2F67CDC43E1CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x89DA22155CD3A413ULL + 0xA826463C581FCF6CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x81CDDAF816D99BA9ULL + 0xA04508AA88A760CBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE774E479884DA1A7ULL + 0x968CBD060E500990ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x91FFDEF134DD10B7ULL + 0xB2E89C5B0DBED07CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC47D02F2C779E8EDULL + 0xB9D7F04BBA807C9BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA3E028537362F323ULL + 0x9144A42BD4706DFDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCF39B04710B73437ULL + 0xDD235C63A919E5D0ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD, aWorkLaneA, aOperationLaneA, aWorkLaneD, aFireLaneB, aOperationLaneB, aFireLaneD, aFireLaneA, aOperationLaneC, aFireLaneC, aWorkLaneB
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6809U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 4063U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4685U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 721U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3561U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5824U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 26U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (aWandererK + RotL64(aCross, 13U)) + 14823268998003220191U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 27U)) + 15295237288788213847U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 16434853402001133899U) + aNonceWordA;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 7555911304407871631U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 6U)) + 14977248264994834620U) + aNonceWordJ;
            aOrbiterJ = (aWandererE + RotL64(aCross, 41U)) + 9707764144919392380U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 43U)) + 1277304385464681529U) + aNonceWordC;
            aOrbiterH = (aWandererH + RotL64(aIngress, 23U)) + 3089786220465849395U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 3700503853358695085U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 3U)) + 3240054112993517371U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aWandererA + RotL64(aIngress, 36U)) + 16897532076915366859U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 18167359289798364307U) + aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8870819278575769863U;
            aOrbiterD = RotL64((aOrbiterD * 9334066154398059075U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15363069206212330251U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14858164441499725158U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14931933411393847915U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5357144808788707522U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2910681277417754860U;
            aOrbiterE = RotL64((aOrbiterE * 13170868582159347059U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9824408699018165151U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 368370224788793300U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 14358982366258729959U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7095398304588825115U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11418879758164313554U;
            aOrbiterA = RotL64((aOrbiterA * 5983520332639771791U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2171599720681913272U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17593730219647495033U;
            aOrbiterB = RotL64((aOrbiterB * 12926053208918563087U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17755947635188715523U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14565740605227022106U;
            aOrbiterC = RotL64((aOrbiterC * 15866418354612945335U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14538017880915584414U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6174566474851449123U;
            aOrbiterH = RotL64((aOrbiterH * 179569008593475683U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3806438394748643441U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13737114463856719285U;
            aOrbiterJ = RotL64((aOrbiterJ * 13439346068497710151U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3698379331577470045U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1097081284062708554U;
            aOrbiterG = RotL64((aOrbiterG * 3498627643013255777U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 215117138867597766U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14823268998003220191U;
            aOrbiterF = RotL64((aOrbiterF * 12131828437975771377U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 48U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterH, 18U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 39U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterC, 11U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 44U) + aOrbiterE) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 21U)) + aNonceWordO);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aNonceWordL);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 43U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterF, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneD
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12662U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 8781U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 11401U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14852U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13483U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 10670U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 12U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 2168513956284366370U) + aNonceWordK;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 42U)) + RotL64(aCarry, 11U)) + 10290361969974613111U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 15673836275828498050U;
            aOrbiterE = (aWandererF + RotL64(aCross, 19U)) + 16600540024145812236U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 3U)) + 9428052101528111892U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 47U)) + 12763657928312763377U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 58U)) + 10751286982008662485U) + aNonceWordA;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 51U)) + 1708230173038057979U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 53U)) + 4011389705422783816U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 37U)) + 11704428328093077714U;
            aOrbiterF = (aWandererK + RotL64(aCross, 35U)) + 2055336619674699284U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1870865272102705804U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3574214263751923179U;
            aOrbiterG = RotL64((aOrbiterG * 13132083406834413563U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 984611970726966186U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15207945449947643672U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9539470161576639981U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4181398506373973169U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15222345431506025949U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 6925143692628659467U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15023513452326240962U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14965669361708810699U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 587008860996713147U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7985755518735406360U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 225592097619240187U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 2313509354133400439U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3659537916566939383U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17043668033610689611U;
            aOrbiterA = RotL64((aOrbiterA * 10797634709118100773U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10217321522161675848U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8013663869536146842U;
            aOrbiterD = RotL64((aOrbiterD * 2293233079384777175U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13762445330867496042U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2692400019659269106U;
            aOrbiterH = RotL64((aOrbiterH * 167704184292219399U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18232551682424867647U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14785847596876239854U;
            aOrbiterJ = RotL64((aOrbiterJ * 4569180925037758487U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5910282247522389536U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 16556038638738871204U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18356922295088260901U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 141620663839815754U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2168513956284366370U;
            aOrbiterF = RotL64((aOrbiterF * 8605382725635471683U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 34U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterC, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 39U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 46U)) + aOrbiterK) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 48U) + aOrbiterH) + RotL64(aOrbiterA, 37U));
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 48U)) + aOrbiterF) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 4U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneD
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneA
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19137U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 20030U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 20080U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16840U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18922U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 23428U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 53U)) + 7790166497945719700U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 39U)) + 7136208896846119188U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 12123156943355100886U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 5095546037880875199U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 13U)) + 17642705393916765992U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 3U)) + 9918479837334416990U) + aNonceWordG;
            aOrbiterH = (aWandererG + RotL64(aScatter, 35U)) + 4890009823843176466U;
            aOrbiterB = (aWandererD + RotL64(aCross, 51U)) + 17652590786213674124U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 19U)) + 870002527644696135U) + aNonceWordP;
            aOrbiterD = ((aWandererI + RotL64(aCross, 23U)) + 12545429703552643682U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 48U)) + 5310272867406182581U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3264719049050179440U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1967241238180278937U;
            aOrbiterC = RotL64((aOrbiterC * 13004319774269457957U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 773883832927040736U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12766817190261232485U;
            aOrbiterA = RotL64((aOrbiterA * 7448864556802318431U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 260069382395598265U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15462103891287350123U;
            aOrbiterH = RotL64((aOrbiterH * 5029268763635635753U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4072032867513289827U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17153061419083897076U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 11934532169271718913U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6207264270332656966U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18048064697837314947U;
            aOrbiterD = RotL64((aOrbiterD * 13632594619404208489U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14484617445340272026U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16160443600497652026U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1988599349457831597U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5873314228291583482U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16418290052752166515U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18270363452003213317U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9158414409987627714U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8205937960146492168U;
            aOrbiterI = RotL64((aOrbiterI * 14008398661393344261U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16386126219854809263U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12418021156683187869U;
            aOrbiterJ = RotL64((aOrbiterJ * 13897930566207284517U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5427232681451476584U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 18237670074497382745U;
            aOrbiterK = RotL64((aOrbiterK * 15528665160297906195U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 8330262458028468513U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7790166497945719700U;
            aOrbiterE = RotL64((aOrbiterE * 6001280767763971107U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 19U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterA, 24U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 51U)) + aNonceWordH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 11U));
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 56U) + aOrbiterK) + RotL64(aOrbiterI, 39U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterA, 54U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 28U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 54U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26243U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 26643U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 26484U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27205U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31640U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 27733U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aIngress, 29U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (aWandererC + RotL64(aIngress, 43U)) + 5721224134332887360U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 6892749729775049095U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 4U)) + 3884839462099556836U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 21U)) + 4365431706830216193U) + aNonceWordN;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 29U)) + 15501528746571578773U) + aNonceWordK;
            aOrbiterG = (aWandererA + RotL64(aCross, 39U)) + 4505911326320650606U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 1865129050927879580U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 57U)) + 2011737665969640369U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 611672935827062688U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 41U)) + 663547038310431047U;
            aOrbiterC = (aWandererF + RotL64(aCross, 34U)) + 5468932264754299556U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17920294117231191705U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 486058453837528110U;
            aOrbiterJ = RotL64((aOrbiterJ * 8851102552244026737U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2789178451938129313U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 420772587981211184U;
            aOrbiterE = RotL64((aOrbiterE * 17402987842294006667U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16196774774442181825U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16264169656793713547U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 6900221986041638783U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10207659833859860796U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8593749091183323678U;
            aOrbiterD = RotL64((aOrbiterD * 10696776033512404927U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7224922076047787384U) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15366267474865172373U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10134187073321814217U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4235342515820080294U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5239480080426950612U;
            aOrbiterG = RotL64((aOrbiterG * 12077621553561927079U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10891752830598395582U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 7797358829694471108U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 7621206775460997431U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3755715857903753416U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3172069024987421726U;
            aOrbiterC = RotL64((aOrbiterC * 16048490837178650865U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8623351347363497301U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5895306804546658158U;
            aOrbiterA = RotL64((aOrbiterA * 1568542219600635919U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5026075347235960113U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3706258841140585921U;
            aOrbiterK = RotL64((aOrbiterK * 4911715089264902109U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6753904207571971217U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5721224134332887360U;
            aOrbiterI = RotL64((aOrbiterI * 4531182106796534951U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 44U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 52U) + RotL64(aOrbiterD, 56U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterG, 27U));
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 23U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 47U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterA, 44U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 46U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + aNonceWordI) + aWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 13U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererC, 26U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Boxing_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x81016851FD9717ADULL + 0x9C83606079C6C68BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEBDC1D59DD473A3DULL + 0xA4E8D1B51D087F92ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE35FEE86CD24D5D9ULL + 0xDE7D805BB4D3A82CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE45F6DF618FC03E9ULL + 0x8D8B43484513A64BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF5959A08B8D3F889ULL + 0x830424593D59EB3CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x91A4F5C013657D55ULL + 0xDD5BCBB9536E06D6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF6E8B445503EEBF3ULL + 0x83794FE43943E7EDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8F472F0EBA70C9D5ULL + 0xEF95C51FCF50513AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFCD5E79F0E4EA791ULL + 0xBADC21FEAFFDA4D8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE2C131FABA33CC1DULL + 0x90D46343E1E9BA99ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAB704907E9749D2FULL + 0xA880E8920DB353FEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDB6416661D3D6833ULL + 0xD4CAF7064BA66FACULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC8AC5B8D2A0E8C87ULL + 0xDD649549C3F87FCFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA6BC0FA12FA46F2FULL + 0x944789AF6115060DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9ED6C7A70B44A5BFULL + 0xE52736A2B6432B00ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDA318A65E9BC4A13ULL + 0xCC901A3DCB2A3649ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneB, aOperationLaneC, aOperationLaneD, aWorkLaneA, aExpandLaneA, aFireLaneD, aFireLaneC, aExpandLaneB, aFireLaneA, aWorkLaneD, aExpandLaneC, aWorkLaneC, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6815U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 6098U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 506U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6130U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7154U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 4932U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 19U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 6733949564325516029U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aIngress, 57U)) + 7304098437143918796U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 35U)) + 3923949518391777800U) + aNonceWordJ;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 14243591003388927124U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 40U)) + 18329498724605410406U) + aNonceWordO;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 29U)) + 13118172167747037249U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 5272025143849174212U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 23U)) + 16075917179214318424U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 6U)) + 15263590648674658399U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13730046728289525921U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7703141464499623408U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5886009900621521987U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1382279753822135359U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2973369221699098292U;
            aOrbiterD = RotL64((aOrbiterD * 7440242040663550631U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11578274119583013219U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3419411247737896674U;
            aOrbiterC = RotL64((aOrbiterC * 17814942652262802991U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2582783513078999303U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3959762790273529677U;
            aOrbiterJ = RotL64((aOrbiterJ * 383974377372162751U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 465795011576934604U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17880826624185821135U;
            aOrbiterK = RotL64((aOrbiterK * 4445949147592860913U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10819659185349413173U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17298208553586835030U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1965860510614222093U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12585880006661489402U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16650193903267408586U;
            aOrbiterE = RotL64((aOrbiterE * 5781132589396936615U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 885882046325991589U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 869560078374809974U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 13440973563438747181U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11871305571797951851U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12137095015607196226U;
            aOrbiterA = RotL64((aOrbiterA * 7618152256560808581U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 46U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 35U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 12U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterD, 51U)) + aNonceWordB);
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 29U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterI, 18U)) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterH, 23U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12001U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 14903U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13684U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13637U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15396U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14691U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 17081642665820489793U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 18U)) + RotL64(aCarry, 29U)) + 14468854040067229623U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 37U)) + 2249450222593057429U) + aNonceWordI;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 14964389079511378664U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 5U)) + 17003491054252360650U) + aNonceWordA;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 60U)) + 12710882240582032588U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 53U)) + 9887078182156755359U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 47U)) + 7665284531810584704U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 23U)) + 7304284015511876717U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5517927023543751734U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 17704756310857362759U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15826832172923213591U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11347400363019508578U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11696395232760991243U;
            aOrbiterC = RotL64((aOrbiterC * 9725231749679442003U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10875780291242873583U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7808740614343437672U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8889516201913716283U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3145390996141902032U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16080636485642732615U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 7445756373012217305U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3929263288176983844U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 18210228766683996806U;
            aOrbiterF = RotL64((aOrbiterF * 13178080076505449091U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13948962323541421431U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3037683309790156893U;
            aOrbiterK = RotL64((aOrbiterK * 13406672352222636739U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17827265198532699474U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7270895262023504864U;
            aOrbiterJ = RotL64((aOrbiterJ * 13467417362477308167U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6431243064980879185U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6680205390976259885U;
            aOrbiterE = RotL64((aOrbiterE * 10421386694108590789U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15910655919164357152U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 8046213498216027383U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 18061867495824063553U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 30U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 51U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 12U) + aOrbiterG) + RotL64(aOrbiterI, 41U)) + aNonceWordP);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterK, 24U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 19U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 11U)) + aOrbiterI) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterB, 46U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17254U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 21395U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16415U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17445U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19665U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23769U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 36U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 1210605127156905516U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 58U)) + 11964595428173569519U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 13U)) + 16277319029916258482U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 35U)) + 12369497463101824572U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 3U)) + 6201248574067068202U) + aNonceWordH;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 1727477025667206661U) + aNonceWordG;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 1404510627789806851U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 48U)) + 6948213591282018925U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 27U)) + 6688865181284421478U) + aNonceWordL;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3351130769402360855U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12681032488906270823U;
            aOrbiterA = RotL64((aOrbiterA * 3680893896579741263U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3591412591193726763U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16153817571210878589U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4165137036092246349U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3808228354421006630U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1427373776207504205U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4534374093769595531U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1831554180932501132U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1114853085120949215U;
            aOrbiterH = RotL64((aOrbiterH * 4264176108298812905U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2080935638828366835U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16104777999646489828U;
            aOrbiterK = RotL64((aOrbiterK * 15205199362011777473U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9782806013673440791U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3721620299829386454U;
            aOrbiterJ = RotL64((aOrbiterJ * 6286765834910272409U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4013706412064296527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5751022780695158579U;
            aOrbiterC = RotL64((aOrbiterC * 13766736471646116397U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17684546333240329338U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1106947111128020920U;
            aOrbiterB = RotL64((aOrbiterB * 3158839453318658951U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 11564229705849500598U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 1585817314460274286U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 12687162159791577431U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 38U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 47U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 19U)) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterB, 42U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 27U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 34U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterG, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26002U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 25144U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26917U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26550U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25831U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 28530U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 20U)) + (RotL64(aCarry, 37U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 60U)) + 7632760812370906911U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 23U)) + 6007174525479723089U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 13U)) + 3362829642521821048U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 18009548556107978286U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 17880909432272697327U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 47U)) + 15961567935420752568U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 10136559064656837921U) + aNonceWordC;
            aOrbiterB = (aWandererA + RotL64(aCross, 18U)) + 17622019364405410277U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 37U)) + 6927494824421416306U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 7125170407794874847U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12342273503071032250U;
            aOrbiterH = RotL64((aOrbiterH * 867417849555857179U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14997696377476124836U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14874498694181230698U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 4026127545746010937U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 2549397729130885686U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4217995818662767955U;
            aOrbiterF = RotL64((aOrbiterF * 5525525344485251063U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4706089044415442525U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17983900172670031015U;
            aOrbiterC = RotL64((aOrbiterC * 541552737180932879U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1904937798143929988U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10620877287033139483U;
            aOrbiterI = RotL64((aOrbiterI * 16711012562024287213U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15681091173163181525U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2655543246639000084U;
            aOrbiterJ = RotL64((aOrbiterJ * 16686375598149755947U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2647895110857289213U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5581609212017175954U;
            aOrbiterB = RotL64((aOrbiterB * 15330263616699031311U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13609076329627787987U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 6244266279516622070U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12488345779236971095U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5289624364508923581U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16351476803965903112U;
            aOrbiterG = RotL64((aOrbiterG * 9012522724650442597U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 60U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 24U) + RotL64(aOrbiterH, 6U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterH, 51U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 11U));
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 34U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + aNonceWordO);
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 27U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Boxing_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA684C329B46165C1ULL + 0x9C4207198974206FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD42BBB4384EADBA1ULL + 0x959491272358EBDAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE924A3F39CCEFE85ULL + 0x8EE1492265F361B0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9BD18142CBD66CC7ULL + 0xC83421690BF93BE9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD0F8B0733A920FCDULL + 0xF1794AE171E5D5B9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xECE3C2688E37A687ULL + 0xCC98F3107CEEFA2FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x87C634BE9F01A8A5ULL + 0x818DBC4EDADD9E29ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCC929E6C1645E1C5ULL + 0xA6A6C701E1BF1F0CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC2AD8981A9AA2D19ULL + 0xE7638DB9D432FEC7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE2F32FCE25920C77ULL + 0xF8487CD4565446C0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC2A8F9D285B32AE5ULL + 0x836771913566ACCCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9FE59150D4F8FD75ULL + 0xC26AE55F156317EEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB07A64757414242BULL + 0xE76B5CCD3F9D6117ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC519F3498C8CBD69ULL + 0x9B5011211D1B1273ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB74EF7616AD29D61ULL + 0xF88C2E7C9EB3E658ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF6ACF2666EA61177ULL + 0xC80A06D4B7304DF6ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aFireLaneC, aExpandLaneA, aOperationLaneB, aOperationLaneA, aExpandLaneB, aOperationLaneD, aFireLaneA, aExpandLaneC, aFireLaneB, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1113U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 206U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1628U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2460U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1562U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7508U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 13U)) + 6243113109470883144U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 5U)) + 3891552123999605832U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 8758797898587019128U) + aNonceWordM;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 1005891374086408851U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 3713426782180050764U) + aNonceWordB;
            aOrbiterK = (aWandererK + RotL64(aCross, 29U)) + 18358143862391573534U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 60U)) + 17504394029693712404U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5312729289027417014U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2560873623431186029U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 16843728573219210173U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16309322822806704211U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10195513918020652600U;
            aOrbiterB = RotL64((aOrbiterB * 14569219741824123715U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2552116263258744287U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7732784879810980089U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 15041929399477790999U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16499127570665381507U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10890036715535519036U;
            aOrbiterJ = RotL64((aOrbiterJ * 9065115450010475187U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16288944603478791554U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14542766121469312846U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8435383464425875209U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5973595239494084696U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1820492719977197097U;
            aOrbiterE = RotL64((aOrbiterE * 16164917159141304405U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10489529555776381736U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6392552206958240484U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11761477994533503307U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 54U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 22U)) + aNonceWordJ) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 3U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 4U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13656U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 15827U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15423U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13444U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15382U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10162U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCross, 12U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 12980104182836602177U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 3172622203188863995U) + aNonceWordN;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 35U)) + 1170974132219980203U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 6035201940965047490U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 41U)) + 18033907118424996722U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 60U)) + 14604813424800580304U) + aNonceWordJ;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 21U)) + 13720232492851066035U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3902659710585257448U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8331560652661619868U;
            aOrbiterC = RotL64((aOrbiterC * 11418103770615560205U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4485014147538689794U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 168202636924512424U;
            aOrbiterH = RotL64((aOrbiterH * 13711020666131492091U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16227825670092707848U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4792781933944671365U;
            aOrbiterJ = RotL64((aOrbiterJ * 15859849676231455283U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12636865372722601282U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 18198291399585556632U;
            aOrbiterI = RotL64((aOrbiterI * 18155803890313399795U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3650053185419807206U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 5897288963905408776U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 3706949366974086151U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9922308113622901726U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13352279749091561510U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 4025213180483632557U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14969461950939646117U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10231661776135056651U;
            aOrbiterE = RotL64((aOrbiterE * 11284575051455238501U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 50U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 21U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 43U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 36U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterC, 57U)) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16814U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 22970U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 20836U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19374U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21098U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22629U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 22U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 26U)) + RotL64(aCarry, 29U)) + 5041131702736607991U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 5U)) + 9295010428212681446U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 19U)) + 6235875895358766017U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 11U)) + 2622227802531866918U) + aNonceWordL;
            aOrbiterB = ((((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 3888894734834524972U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererF + RotL64(aCross, 35U)) + 241682012014701753U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 15758000422451568079U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2061944548396976912U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8177144990755754531U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 12702392689484397947U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 554978075608818497U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 250408260560714933U;
            aOrbiterK = RotL64((aOrbiterK * 1295379390497107727U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8700027645880997552U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10026130047465480902U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 12417270861933696623U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9785843014096326696U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9998582683258411251U;
            aOrbiterH = RotL64((aOrbiterH * 7197956237569462269U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13817734599383455151U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6647207154174092691U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 1578528131687283531U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4957715980509035719U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4994885315786213197U;
            aOrbiterB = RotL64((aOrbiterB * 5676683798126497011U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5072908311783966503U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5535039946192891515U;
            aOrbiterA = RotL64((aOrbiterA * 2989412783482309753U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 40U) + aOrbiterD) + RotL64(aOrbiterA, 13U)) + aNonceWordO) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 56U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aNonceWordN);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 21U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32714U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 31762U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26167U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27178U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25066U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31817U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 10U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 18191288703716505885U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 51U)) + 9824014524910417136U) + aNonceWordE;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 11953012029254917548U) + aNonceWordG;
            aOrbiterD = (aWandererK + RotL64(aScatter, 13U)) + 6297568011027199089U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 27U)) + 2576999400457367975U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 13176139160575558254U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 37U)) + 9978408174563621810U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16765834875061607142U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16534507305459121344U;
            aOrbiterC = RotL64((aOrbiterC * 8943988574248229067U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3114710944346151807U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10240517868726718592U;
            aOrbiterI = RotL64((aOrbiterI * 4645691562915606463U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10721450637990777883U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16689590768796583952U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3046344179729901637U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2427422768928450209U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13495584061816457831U;
            aOrbiterJ = RotL64((aOrbiterJ * 6670984773768885119U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7058636403765106682U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9897341853944713767U;
            aOrbiterK = RotL64((aOrbiterK * 14286816859999869231U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17749559755733386064U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12515645083926326659U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6582878478865838245U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2625692458813609962U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10596240255026143019U;
            aOrbiterD = RotL64((aOrbiterD * 11605800195771080135U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 30U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 11U)) + aNonceWordN);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 36U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + aNonceWordP) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Boxing_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9D4B76AE8F90F36BULL + 0xC6EC2FBB541C5C6DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA7698065030B7B53ULL + 0xD053A2DD98E407E6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCC1F7EE494B370BBULL + 0xFAA5F856C5D9A1EDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFA0E4CF465AF5B1BULL + 0x9B4242B7D4262229ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDCE87681FDF1231BULL + 0xB152400A9C8BDC3FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xECB104AF16F4011BULL + 0xC52F5A2930DD128FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB5A0A48BA56D7407ULL + 0x8B1220D0DD0B0E64ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBEDD5BFBF6A81043ULL + 0x9390D2C5B54C85F0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAB5695AECF86BFA9ULL + 0xD1382114FFAEE3F3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD4C10B2A449CB3B9ULL + 0xEFCCB05A27066961ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFDBEE59442D386EBULL + 0xFB719ACF038C61E1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9C4E1846AD494555ULL + 0xF37F5B5F2A69F5F8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEABF130965985BA5ULL + 0x83C8D6C7A4CD7DC2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC95BEBFBBEE86DB1ULL + 0xF77653B36A4DE5F3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x93190FA9658CBFD5ULL + 0xC026B0B909EF77A4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x905003BF1739583FULL + 0xA478EF4676C769E2ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2272U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 2078U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2395U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 922U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 20U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 13U)) + 9471546960258473684U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 53U)) + 18050235435948942244U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 39U)) + 3005107102671544641U) + aPhaseEOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 17898396434573801850U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 15071602525497771648U) + aNonceWordB;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 46U)) + RotL64(aCarry, 23U)) + 5780119462702672108U) + aNonceWordE;
            aOrbiterI = ((aWandererK + RotL64(aCross, 5U)) + 13301326224151025687U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 18129323022260575961U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1199228670638790709U;
            aOrbiterF = RotL64((aOrbiterF * 1780426336211781025U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1839199978088021020U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4999517042246790165U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4585813675677234577U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8788607633376516299U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15143903839930468749U;
            aOrbiterG = RotL64((aOrbiterG * 12735914889325422675U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 16674732686428431869U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15908873150953195581U;
            aOrbiterC = RotL64((aOrbiterC * 18049755517524334107U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11204775359756474667U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2525984309543939465U;
            aOrbiterA = RotL64((aOrbiterA * 3988529812023791571U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4566345170476825512U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14876612901557406267U;
            aOrbiterI = RotL64((aOrbiterI * 9047956948845135339U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14926290877038883931U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12710203178186614846U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14841163494801662515U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterF, 14U)) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterA, 43U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + aNonceWordN) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 54U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterA, 21U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + aNonceWordA) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3449U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5033U)) & W_KEY1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4418U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4827U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 51U)) ^ (RotL64(aCross, 10U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 8975885703279267062U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 43U)) + 8664844915562660637U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 11U)) + 12281774799736296726U) + aNonceWordN;
            aOrbiterK = (aWandererI + RotL64(aScatter, 3U)) + 15347461352311329726U;
            aOrbiterE = ((((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 12967500561828907834U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 20U)) + RotL64(aCarry, 39U)) + 5002833859280402726U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 27U)) + 11908257536954668983U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 17017174811949227162U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16851323125613931180U;
            aOrbiterA = RotL64((aOrbiterA * 12446990992858763577U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13469326957728686706U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5228638551056105241U;
            aOrbiterE = RotL64((aOrbiterE * 13369947664646167255U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11945166198089308564U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 16268645041872996022U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 5391448793718370911U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14781204627695095701U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5365325354838101092U;
            aOrbiterK = RotL64((aOrbiterK * 8017284997946310807U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 563147416025715953U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14660867395395625851U;
            aOrbiterH = RotL64((aOrbiterH * 4769458126865307103U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3168989056355712105U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16179131669773665579U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5641461617066671723U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4160220074225527179U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8597134686962559111U;
            aOrbiterB = RotL64((aOrbiterB * 639572585431474015U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 57U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 43U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 13U)) + aOrbiterH) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 37U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterB, 5U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 28U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5664U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 5958U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6163U)) & W_KEY1], 44U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7794U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5824U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCross, 21U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 16462052553719977502U) + aNonceWordI;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 29U)) + 12337064059566619581U) + aNonceWordA;
            aOrbiterH = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 15801005007094515447U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 3U)) + 8228706742665081656U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 54U)) + 11006723027845190869U;
            aOrbiterE = ((((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 18173765337829177450U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aWandererB + RotL64(aCross, 19U)) + 530215083653542558U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6608611827035564511U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2246051826221626809U;
            aOrbiterH = RotL64((aOrbiterH * 6333352641495253539U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5228575308895381421U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10999213210689606857U;
            aOrbiterK = RotL64((aOrbiterK * 5467601259546342925U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3773371037240485696U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8887985779436152504U;
            aOrbiterA = RotL64((aOrbiterA * 698713082830739677U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11150566414723818350U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8336366151003049546U;
            aOrbiterD = RotL64((aOrbiterD * 9033771197242493699U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13233968794237090787U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8172558473508478819U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17837070423649268435U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 133564480283347997U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15104810248883567064U;
            aOrbiterJ = RotL64((aOrbiterJ * 706802420642303533U), 35U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 9138629520201127075U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13993086066341664080U;
            aOrbiterF = RotL64((aOrbiterF * 4875046427147105077U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 54U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 46U)) + aOrbiterA) + aNonceWordF);
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 21U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterE, 37U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + aNonceWordD) + aPhaseEWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererI, 20U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 8900U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 9337U)) & W_KEY1], 34U));
            aIngress ^= (RotL64(mSource[((aIndex + 9171U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 10797U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10900U)) & W_KEY1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 8894U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 5160910997561396461U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 51U)) + 14920764751058512062U) + aNonceWordO;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 6080952401749660022U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 17667234330526298627U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 35U)) + 760630072638686756U) + aPhaseFOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 6U)) + 3504157162816997476U) + aNonceWordP;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 13U)) + 9489022223422585882U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1149898536879968964U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10492284328940025310U;
            aOrbiterE = RotL64((aOrbiterE * 7893416766300156495U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13213275606286399312U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10557118912847180413U;
            aOrbiterC = RotL64((aOrbiterC * 10077877991284587845U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15618980209023994776U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5268600749854045564U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3849660559223919613U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8011552687609649990U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3148133096349525066U;
            aOrbiterF = RotL64((aOrbiterF * 5245156554959620007U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12032847944237867285U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14999005703490824673U;
            aOrbiterH = RotL64((aOrbiterH * 6631584955208646049U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5426735969392906710U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3593177531650386729U;
            aOrbiterA = RotL64((aOrbiterA * 12997284886192717043U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1701444719333347373U) + aNonceWordE;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 15928731228196894960U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 1919318226904213433U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 37U)) + aNonceWordF) + aPhaseFWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 53U)) + aOrbiterE) + aNonceWordC);
            aWandererC = aWandererC + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 20U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterF, 41U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 10987U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 10986U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12690U)) & W_KEY1], 56U) ^ RotL64(mSource[((aIndex + 13543U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12728U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11200U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 13135U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 60U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (((aWandererD + RotL64(aIngress, 4U)) + 13499155707765393469U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 3740324981823726185U) + aNonceWordB;
            aOrbiterB = (((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 5470765363949735652U) + aPhaseFOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 29U)) + 3446436171274452326U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 47U)) + 1778929412631211933U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 14666308799855220954U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 13U)) + 4548410236791175055U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5829739767694190372U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14319231414903675748U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4966501102515775601U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1513851750246111405U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1685620217748986019U;
            aOrbiterC = RotL64((aOrbiterC * 9286548037413609445U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 16284162182006054402U) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6271539598462003309U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13923286694131331137U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12669312437565969473U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11894755313393001665U;
            aOrbiterD = RotL64((aOrbiterD * 12556759675372354075U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6315983824634946566U) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17106616474222892782U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 167205520766791073U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13350266700180455548U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4608846311203767162U;
            aOrbiterF = RotL64((aOrbiterF * 2504857468837437365U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14195866746143604365U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7917977448256795054U;
            aOrbiterA = RotL64((aOrbiterA * 5927771378657284557U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 60U)) + aOrbiterC) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterD, 29U)) + aNonceWordA) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + aNonceWordN) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14194U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15227U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15396U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14694U)) & W_KEY1], 3U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15429U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13745U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14846U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 35U)) + 16200278595895089008U) + aNonceWordK;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 29U)) + 1029614154810465897U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 7129562468705441295U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 14388903902433951274U) + aNonceWordI;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 21U)) + 1013568949315967455U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 44U)) + 3128823373497815651U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 14525694606889470589U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14443983602196782887U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12244220415328641190U;
            aOrbiterH = RotL64((aOrbiterH * 15052949098014803181U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10477159225338766614U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2842870123078131566U;
            aOrbiterE = RotL64((aOrbiterE * 11522265477555954071U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8621138818955849917U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5038396344400303181U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14636756322207385447U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 2768613802894372496U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2027754864051410015U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2461322540050569287U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2848088309172056399U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15017458513904884651U;
            aOrbiterF = RotL64((aOrbiterF * 9926904679902843055U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 9079797279596336139U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15424866642305110811U;
            aOrbiterB = RotL64((aOrbiterB * 12912331089970158845U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13751764050290602740U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7694557131324740282U;
            aOrbiterC = RotL64((aOrbiterC * 14980807690491467023U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 43U));
            aWandererI = aWandererI + (((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 30U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordN) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + aNonceWordB);
            aWandererB = aWandererB + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 37U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 53U)) + aOrbiterB) + aNonceWordD);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 19033U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadA[((aIndex + 17625U)) & W_KEY1], 20U));
            aIngress ^= (RotL64(mSource[((aIndex + 16408U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16711U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17591U)) & W_KEY1], 42U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18936U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17465U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 39U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 3U)) + 3199575576585871314U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 2533378188975571824U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 11U)) + 6819782112558312658U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 12690060987724798497U) + aNonceWordK;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 7088375139715629606U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 60U)) + 17785618677423695666U) + aPhaseGOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aWandererG + RotL64(aScatter, 53U)) + 1714999280296491277U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17611338506932491624U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6475727359297421201U;
            aOrbiterH = RotL64((aOrbiterH * 15133348244242438069U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2347744591204119530U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2739317903351401068U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15435029315209475631U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8663535261373274338U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8205245127823536479U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13857005110466856439U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8916510616749754516U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3944805940148512932U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18082271583211389701U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14094751253118853302U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14094299829196076311U;
            aOrbiterB = RotL64((aOrbiterB * 6370012560657108493U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3940673811518673802U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3015106523254484839U;
            aOrbiterE = RotL64((aOrbiterE * 9655401190755573379U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15404103131982599922U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1828655763233900875U;
            aOrbiterK = RotL64((aOrbiterK * 13024358077740310049U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 4U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 54U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterA, 5U)) + aNonceWordD) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 58U)) + aOrbiterE) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterA, 27U)) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 21U)) + aOrbiterA) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererG, 42U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20274U)) & S_BLOCK1], 24U) ^ RotL64(mSource[((aIndex + 21616U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21837U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 21262U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20551U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20871U)) & W_KEY1], 41U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19902U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 21173U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 10U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (aWandererH + RotL64(aCross, 21U)) + 11177787645248006236U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 27U)) + 3808340254579817169U) + aPhaseGOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 43U)) + 828030667598518279U) + aNonceWordN;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 60U)) + 16177835921238398371U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 5518747735458708741U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 17346319082399995165U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 6397156921893030937U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15559381654710713582U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 940404446491415088U;
            aOrbiterC = RotL64((aOrbiterC * 16401260971303026881U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8047166032048732645U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 4688468645859470491U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14383536431614496369U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3710878044770337260U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 116343189456629220U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5637725064169289339U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 883908030159391659U) + aNonceWordH;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 18058691521694880482U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 3132200449123497619U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17521015077103586117U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3668332225435714918U;
            aOrbiterA = RotL64((aOrbiterA * 12658899101297839881U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12229480388278883300U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16206524049491531816U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 11122340196620859805U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5743265849441077466U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2812293020719282236U;
            aOrbiterD = RotL64((aOrbiterD * 8903956475200417109U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + aNonceWordJ);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 19U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 42U)) + aOrbiterA) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + aNonceWordO) + aPhaseGWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 27U));
            aWandererH = aWandererH + ((((RotL64(aCross, 4U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 29U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22955U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 21907U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23168U)) & W_KEY1], 40U) ^ RotL64(aFireLaneC[((aIndex + 23476U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22917U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23149U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22826U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 22313U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 14U)) + RotL64(aCarry, 23U)) + 14499676118633326000U) + aNonceWordF;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 17191273593018552288U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 23U)) + 4085176294948097737U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 3U)) + 11112671474158908186U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 35U)) + 8745787969012266485U) + aPhaseGOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 18074049663777707948U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 41U)) + 2543758649719164688U) + aNonceWordB;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4659584749412700523U) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 974639159259871273U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 17918719351847605523U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9211220687971081987U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 8567024626862182714U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 7755874089832496393U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5803002132294840900U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11968489432878148467U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4501441062617123165U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9470807228394903442U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1692347973120388469U;
            aOrbiterB = RotL64((aOrbiterB * 17433393164156231575U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 16510815732690193145U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 755159406833096510U;
            aOrbiterD = RotL64((aOrbiterD * 14091736464659561165U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1518824876475937620U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 701225390867330446U;
            aOrbiterA = RotL64((aOrbiterA * 12264618860580199927U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8425976693733003889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7182176375442410367U;
            aOrbiterJ = RotL64((aOrbiterJ * 8860605703761731859U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterD, 10U)) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterA, 41U)) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterE, 19U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 54U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererB = aWandererB + (((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 43U)) + aNonceWordH) + aPhaseGWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26119U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 25354U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26960U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((aIndex + 26938U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27032U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26739U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25633U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 27295U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 29U)) + (RotL64(aIngress, 13U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 29U)) + 8866844335448071821U) + aNonceWordG;
            aOrbiterE = (aWandererD + RotL64(aCross, 3U)) + 15159698739856430085U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 9582805772989594633U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 50U)) + RotL64(aCarry, 37U)) + 1438538239931588373U) + aPhaseHOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 10862044156620436139U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 23U)) + 13682173320058164615U) + aNonceWordA;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 41U)) + 8351013291045977592U) + aPhaseHOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15777857431516633916U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16178966745333885377U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 7545129923202147703U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9031889187993001617U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6308472367425865347U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17118710301967158153U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 642109145903321046U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9186268569255318035U;
            aOrbiterI = RotL64((aOrbiterI * 10714674348507516749U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6091345356803675860U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13218507921880873749U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 15415157927185637717U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4266652275234474616U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4391422098164506195U;
            aOrbiterE = RotL64((aOrbiterE * 17634679403195085867U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5160682323243635577U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10351728852161347404U;
            aOrbiterG = RotL64((aOrbiterG * 11105410036471745951U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3950932176454814023U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9536466386833427441U;
            aOrbiterF = RotL64((aOrbiterF * 18064984243491293435U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 4U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + aNonceWordK);
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 44U)) + aOrbiterE) + aNonceWordB) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterE, 11U));
            aWandererA = aWandererA + ((((RotL64(aCross, 53U) + RotL64(aOrbiterB, 21U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 46U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29486U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 27408U)) & S_BLOCK1], 20U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 30026U)) & W_KEY1], 39U) ^ RotL64(aFireLaneC[((aIndex + 29140U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29211U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29797U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29927U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((aIndex + 29717U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 21U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (aWandererG + RotL64(aIngress, 35U)) + 898812731947995389U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 8677347622525527167U) + aPhaseHOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 39U)) + 770321564027567654U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 53U)) + 11020474858081526395U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 17289793580414993470U) + aNonceWordF;
            aOrbiterE = (aWandererD + RotL64(aCross, 11U)) + 10111912559295118444U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 41U)) + 8083622125544542011U) + aNonceWordK;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 7149858558922988240U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5919683821379905699U;
            aOrbiterK = RotL64((aOrbiterK * 16705119888884231567U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6860902846079238714U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15083517836867542075U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 4686657139237578325U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14852868368708376381U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9860233289028878323U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13418143547952204667U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 772406119079116272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7971141501337627589U;
            aOrbiterE = RotL64((aOrbiterE * 10168120622976358617U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8478568022896691911U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4027604850785607101U;
            aOrbiterD = RotL64((aOrbiterD * 4826627523578901467U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17199331557841535430U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7515957656979776361U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 5468950152869656599U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17138249294921502391U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16236812863923234668U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2925542836624164807U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterF, 13U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 29U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aNonceWordI);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + aNonceWordE) + aPhaseHWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 28U) + RotL64(aOrbiterK, 20U)) + aOrbiterF) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31204U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 32588U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31211U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30676U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30912U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadB[((aIndex + 30652U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 47U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 58U)) + 13481227414590594621U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 17425964381118918026U) + aPhaseHOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 4792004356135956581U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 3U)) + 11926849936000639098U) + aNonceWordJ;
            aOrbiterK = ((aWandererK + RotL64(aCross, 27U)) + 990697329347742142U) + aNonceWordB;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 19U)) + 9307721505373076588U) + aNonceWordF;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 17605732738841908719U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13110764518634187439U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17970109897810645911U;
            aOrbiterJ = RotL64((aOrbiterJ * 10395095143998920213U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10273133817644703654U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11239046688920468137U;
            aOrbiterC = RotL64((aOrbiterC * 5197802934333553327U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8355821483275763145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15522151127786049345U;
            aOrbiterH = RotL64((aOrbiterH * 4844278537850520413U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5381663179722418112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9551368011768104906U;
            aOrbiterE = RotL64((aOrbiterE * 14202470972121732997U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16264476585232221270U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7721417776432288282U;
            aOrbiterI = RotL64((aOrbiterI * 10267770327791051869U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 339418090653475277U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 3247926250495935511U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 16824669543765729097U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3390560045236418590U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3894024951542543635U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10599637790900418767U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 34U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterD, 27U)) + aPhaseHWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + aNonceWordL);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 10U)) + aOrbiterJ) + aNonceWordM);
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterK, 35U)) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aScatter, 22U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Boxing_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8D7F9ACFFEE1E747ULL + 0xE9098C8FA3D9387BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD32216AD93442379ULL + 0xC7A657B2FCC7F2A8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE47C9ACFC94D5DEFULL + 0xF6090CF3F8260D29ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF782BAC253BEF147ULL + 0x88C28251877CA6B9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFA482B09A7AC13F1ULL + 0xC6B41E0B6CF3DCCDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8D6BDEF5397C4D33ULL + 0xE1F444911699434EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8FACAE4413E82C7FULL + 0x85D48B8AE302962BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD51854CF6709D1C9ULL + 0xB02561388899E989ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA4FCB57C030D5707ULL + 0xCA6FE447B372CF7FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCEF2346F1252C109ULL + 0xFF6845592C7515DBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA8EA00881204A517ULL + 0x843A19823AB2D7B0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF6346F81552D68C3ULL + 0xFE6C8FDD13451330ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x93EAE1073C572E63ULL + 0xA028EE6B8AFCB76FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEE798EF6F2E7EE29ULL + 0xE93A742FAC689298ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8B49CAA2F0A896C9ULL + 0xF0B5714F28FBF348ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDE07E8A66D5BAAF3ULL + 0xABDB0FA183043B2DULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneD, aInvestLaneB, aFireLaneB, aOperationLaneA, aFireLaneC, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5275U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 5315U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 326U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2081U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 2006U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((((aWandererB + RotL64(aScatter, 44U)) + RotL64(aCarry, 29U)) + 5480870806135400132U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 35U)) + 8034874599430768743U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 4006919843736863767U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 2988069748674633718U) + aNonceWordM;
            aOrbiterH = (aWandererK + RotL64(aScatter, 27U)) + 12347295651973135786U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14152683894431568192U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 15765143815254196598U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 8948877544291035189U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10473067082331244233U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1089466925383677249U;
            aOrbiterK = RotL64((aOrbiterK * 17334888609179149753U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13215039929873682230U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3957997712247961479U;
            aOrbiterH = RotL64((aOrbiterH * 7631186240013784703U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 10023907397941685546U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14593012591254614353U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17111300092082154687U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13353797968154036726U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9259966668512102858U;
            aOrbiterB = RotL64((aOrbiterB * 8326732574268308221U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 54U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterK) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 41U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererK = aWandererK + (((((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 5U)) + aNonceWordF) + aPhaseAWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 4U) + aOrbiterK) + RotL64(aOrbiterH, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 42U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9226U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 6482U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 8661U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8256U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7729U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 41U)) + 5721224134332887360U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererH + RotL64(aCross, 29U)) + 6892749729775049095U) + aNonceWordF;
            aOrbiterK = ((((aWandererD + RotL64(aScatter, 14U)) + RotL64(aCarry, 51U)) + 3884839462099556836U) + aPhaseAOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 4365431706830216193U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 15501528746571578773U) + aNonceWordB;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4505911326320650606U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1865129050927879580U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 9198152644404068721U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2011737665969640369U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 611672935827062688U;
            aOrbiterA = RotL64((aOrbiterA * 12873671551304596619U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 663547038310431047U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5468932264754299556U;
            aOrbiterH = RotL64((aOrbiterH * 11968657455484578525U), 21U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 17920294117231191705U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 486058453837528110U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 8851102552244026737U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2789178451938129313U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 420772587981211184U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17402987842294006667U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 11U)) + aOrbiterB) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + aNonceWordP);
            aWandererF = aWandererF + (((((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 40U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aNonceWordK) + aPhaseAWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterC, 23U)) + aNonceWordO) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12524U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 15565U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16010U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15456U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12034U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 13147U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 1457104756581596530U) + aPhaseAOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((((aWandererH + RotL64(aCross, 12U)) + RotL64(aCarry, 57U)) + 6127240317844622874U) + aPhaseAOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 16492290056044189421U) + aNonceWordA;
            aOrbiterE = (aWandererF + RotL64(aIngress, 57U)) + 10963676850938416468U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 47U)) + 4872917367399752405U) + aNonceWordE;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15218882377875616148U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5934166612122118251U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 10365045124180379919U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 14215280930872003003U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11428034799044600979U;
            aOrbiterK = RotL64((aOrbiterK * 12162528943733976177U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5453003654321728726U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14273775120265649389U;
            aOrbiterI = RotL64((aOrbiterI * 5139018128323795309U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 328723770018440271U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13032190719588211088U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13363368478932798315U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2386881543033598494U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1649501123340887116U;
            aOrbiterE = RotL64((aOrbiterE * 11148976582360499033U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 48U)) + aOrbiterE) + aNonceWordO);
            aWandererG = aWandererG + ((((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20983U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((aIndex + 20934U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 17107U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21200U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18224U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 21000U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 39U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 898812731947995389U) + aNonceWordJ;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 13U)) + 8677347622525527167U) + aPhaseAOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (((aWandererF + RotL64(aCross, 21U)) + 770321564027567654U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 54U)) + RotL64(aCarry, 53U)) + 11020474858081526395U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 17289793580414993470U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10111912559295118444U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8083622125544542011U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 3610772128071340341U), 13U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 7149858558922988240U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5919683821379905699U;
            aOrbiterK = RotL64((aOrbiterK * 16705119888884231567U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6860902846079238714U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 15083517836867542075U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 4686657139237578325U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14852868368708376381U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9860233289028878323U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13418143547952204667U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 772406119079116272U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 7971141501337627589U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10168120622976358617U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 18U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterK) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + aNonceWordE);
            aWandererK = aWandererK + (((((RotL64(aIngress, 58U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordP) + aPhaseAWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterH, 56U)) + aNonceWordH) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26032U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((aIndex + 24562U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25452U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26323U)) & S_BLOCK1], 54U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22518U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 23436U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 43U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (((aWandererG + RotL64(aCross, 51U)) + 1087148170018530502U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 15530846874509311414U;
            aOrbiterB = ((((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 16987358651515511212U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 12504143181007924259U) + aNonceWordM;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 22U)) + 393322117322732418U) + aNonceWordE;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14325937299241887166U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 9395262907017475742U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 3442643798173589117U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13658510441418344769U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6410754322737005336U;
            aOrbiterI = RotL64((aOrbiterI * 6932217611373076391U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9257290738538818434U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7489828960857692286U;
            aOrbiterD = RotL64((aOrbiterD * 16519674788777989043U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4118778591214588387U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 16619215231168796563U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 14876884956536265157U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11326283811003573430U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1865401866017614604U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8378326058282460073U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordK) + aPhaseAWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterD, 58U)) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterD) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29961U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 29717U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28932U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32561U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32094U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 30614U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 4U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererC + RotL64(aCross, 41U)) + 11700815697312060726U) + aPhaseAOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 11808423452327465441U) + aNonceWordF;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 8670503858631730886U;
            aOrbiterG = ((((aWandererA + RotL64(aScatter, 4U)) + RotL64(aCarry, 57U)) + 2400061067991988544U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 13U)) + 16163118178366229686U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3280178595904941068U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3298683600817047727U;
            aOrbiterC = RotL64((aOrbiterC * 9865649058799255343U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16321624053445183574U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6730229877611375225U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 2022290495153519279U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10162830636713641322U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15646771327759599256U;
            aOrbiterJ = RotL64((aOrbiterJ * 15333053762177144775U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14841751262270544102U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 9545541117228834895U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11529769874752969377U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14676615635857599982U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1231768638470558855U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2716808508509014677U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterD, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + aNonceWordP) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 4U) + aOrbiterE) + RotL64(aOrbiterJ, 52U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 43U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Boxing_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFCC63F262B4A445FULL + 0xD76F3A6A571FABE7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xABCD4946F2EF69A1ULL + 0x8971E675C17F2985ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA57613D3E534BAB5ULL + 0xDC138736C4DC53EDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC903261D68D64A49ULL + 0x98CA5EE536FC7052ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC6760B3F41BAAAA7ULL + 0xEF89156299A12961ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA1B28D176BA54511ULL + 0xA076915D472EC82CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB9D8DB7A1BED149FULL + 0xCFD911E5E7CA0D9DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9D6549D3E0E63D8DULL + 0x8318C75936F99921ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCAA5DB051E4A3203ULL + 0xD706E033CBFAE691ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB1A7BD1FB4E51595ULL + 0x8899CC6DEF195CF3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEB6BF85891528BF7ULL + 0xE053EB701BE16430ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x98FFDA6405B4112DULL + 0xBE0DD6A4AAE18DF8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x93971046DD783D9FULL + 0xE5046873A3802DA1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA8171C4810061AF3ULL + 0xBCFAB92897A5180AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE19D749DF4E7B8EDULL + 0xF820B6538A61C5F6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF901AF8F9CB63AFBULL + 0xFEC0ADF9C673A604ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneD, aOperationLaneC, aOperationLaneD, aExpandLaneB, aInvestLaneC, aFireLaneC, aFireLaneD, aInvestLaneD, aExpandLaneA, aWorkLaneA, aFireLaneA, aWorkLaneB, aExpandLaneC, aWorkLaneC, aFireLaneB
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 356U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 4488U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1176U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2392U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2634U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1444U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererC + RotL64(aCross, 46U)) + RotL64(aCarry, 39U)) + 9630214189402543339U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 27U)) + 4072576573737526819U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 15994787452709618869U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 5U)) + 6403240137132259482U) + aNonceWordE;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 39U)) + 10229266900170507720U) + aNonceWordD;
            aOrbiterG = ((aWandererA + RotL64(aCross, 35U)) + 5025294577989748989U) + aNonceWordH;
            aOrbiterI = (aWandererD + RotL64(aIngress, 51U)) + 16696461238217956883U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 57U)) + 9878318855341719119U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 14U)) + RotL64(aCarry, 47U)) + 16086635438116177346U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12295437783084203730U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7681150419912842402U;
            aOrbiterA = RotL64((aOrbiterA * 7289497379725191451U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2639104034287637448U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12298170009332243573U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9397919591171238575U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3485932317267669626U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16569551670038752475U;
            aOrbiterK = RotL64((aOrbiterK * 8139802826402217631U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4448490103784103954U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14510534073046885941U;
            aOrbiterG = RotL64((aOrbiterG * 7777192047386438305U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4286195398675733451U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15790355933840266463U;
            aOrbiterH = RotL64((aOrbiterH * 13342257823027075501U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6362891510370156055U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15121822034579983174U;
            aOrbiterI = RotL64((aOrbiterI * 7268045994574844937U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13817341015719915628U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14113474087906143783U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12838910141533126059U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 9988301252236121106U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11287477288382171758U;
            aOrbiterC = RotL64((aOrbiterC * 4979297247881426383U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9491727010910328644U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7961202721830514030U;
            aOrbiterF = RotL64((aOrbiterF * 16300364540313620767U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 14U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 19U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aCross, 26U) + aOrbiterC) + RotL64(aOrbiterK, 28U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 39U)) + aOrbiterG) + aPhaseBWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterK, 43U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterG, 12U)) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 47U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10132U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 6069U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6911U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneC[((aIndex + 7243U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10428U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8175U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7708U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 6U)) + (RotL64(aIngress, 47U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (((aWandererK + RotL64(aCross, 10U)) + 8685374557928800912U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 27U)) + 3482312691892161229U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 6948130297389161165U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 35U)) + 5506385663788942690U) + aNonceWordP;
            aOrbiterI = (((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 17859982009307397161U) + aNonceWordJ;
            aOrbiterK = (aWandererB + RotL64(aIngress, 51U)) + 9178488809207094043U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 1835479501226057169U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 42U)) + 5368101733632614939U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 47U)) + 9050459666576835422U) + aNonceWordM;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9042186993119635078U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17528342580198295025U;
            aOrbiterC = RotL64((aOrbiterC * 14316671546614386775U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6495418332558436882U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 8834495762667327342U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 10783141541937645995U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4364314196965690905U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6357485231062120459U;
            aOrbiterJ = RotL64((aOrbiterJ * 289429584586504995U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3321488322626415347U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10817330671781848737U;
            aOrbiterG = RotL64((aOrbiterG * 15875919466358823335U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17974092279281611763U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 2871472057292789157U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 16104199340711015181U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15187929795092006849U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13482063681546475923U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14466266308157364963U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6232152545071397380U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17488906002621373262U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 4719340606442742577U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12444819880507588549U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13808941689757772497U;
            aOrbiterH = RotL64((aOrbiterH * 6541360905282412317U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8049361354387692374U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7137831335606542401U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 11022231291507235007U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 57U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aCross, 4U) + aOrbiterA) + RotL64(aOrbiterH, 53U)) + aNonceWordC);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterA, 22U)) + RotL64(aCarry, 47U)) + aNonceWordG) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aCross, 30U) + aOrbiterI) + RotL64(aOrbiterG, 41U)) + aPhaseBWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterC, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneA
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15985U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 14504U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11934U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15968U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 15275U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 54U)) ^ (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 12583180859826261500U) + aNonceWordB;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 9067093488553721468U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 13U)) + 12173106198862881754U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 58U)) + 11333491014394592654U) + aNonceWordL;
            aOrbiterI = (aWandererC + RotL64(aScatter, 39U)) + 3511883526940919554U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 23U)) + 7416810692106273044U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 8341174972619784110U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 54U)) + 2220852854836962979U) + aNonceWordO;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 43U)) + 8090781422229383825U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2338801236599102223U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12484514711848308104U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10364216764253366067U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13684861340589131816U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12796636819991873058U;
            aOrbiterI = RotL64((aOrbiterI * 5533508014234835669U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7634198650894837690U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10240326122201201762U;
            aOrbiterG = RotL64((aOrbiterG * 8758703497719125901U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4162814763739453934U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2766504649149048469U;
            aOrbiterH = RotL64((aOrbiterH * 16731843453895178671U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11051393030148769655U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17687055068651386665U;
            aOrbiterA = RotL64((aOrbiterA * 1042927176246229537U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3353615315436983420U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5971640796220306310U;
            aOrbiterK = RotL64((aOrbiterK * 15804313508835034807U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12299773092762384765U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7435804907797063411U;
            aOrbiterB = RotL64((aOrbiterB * 9848139805288165965U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8735783937125735699U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11903126115475835615U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16942088822124940265U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4427166023462475475U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6011733469446008137U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 17298067225913923517U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 38U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 40U)) + aOrbiterG) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + aPhaseBWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterG, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterD, 3U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterK, 35U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 24U) + aOrbiterK) + RotL64(aOrbiterI, 44U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18699U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneC[((aIndex + 16866U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 21580U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16567U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneD[((aIndex + 18099U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 30U)) ^ (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 27U)) + 2783898056762489197U) + aNonceWordC;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 46U)) + 7177192902873343053U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 23U)) + 12254703232691980774U;
            aOrbiterF = ((((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 15446547245691219559U) + aPhaseBOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 888475203006174856U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 34U)) + 3649183529366307877U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 53U)) + 4642631047518805167U) + aNonceWordH;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 6108329730724782250U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 11U)) + 8334054653023816636U) + aNonceWordN;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5891895375031474350U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3176720746238477862U;
            aOrbiterH = RotL64((aOrbiterH * 1869961473768307911U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6111038696865301675U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11914998302228682704U;
            aOrbiterG = RotL64((aOrbiterG * 11738924766359642853U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17005063057791320948U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18333780598768130670U;
            aOrbiterD = RotL64((aOrbiterD * 5416759844884107303U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2056115016443263153U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10245512728872962677U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 707106795383284903U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4810366069422162351U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3051442983125942469U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 13558537578054436423U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9285068547223654308U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13067251130180968842U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 7000687697769766605U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3203670242792002165U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1770881716916463461U;
            aOrbiterI = RotL64((aOrbiterI * 13870229847371882171U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16286823712870537410U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13067191141829694202U;
            aOrbiterC = RotL64((aOrbiterC * 15629974528467350445U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3414576315085336932U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8979691827341555245U;
            aOrbiterJ = RotL64((aOrbiterJ * 15971594804040295757U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + aNonceWordM);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterG, 52U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aPhaseBWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterC, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterF, 43U));
            aWandererH = aWandererH + (((RotL64(aCross, 22U) + aOrbiterA) + RotL64(aOrbiterI, 36U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 23U)) + aNonceWordL) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aExpandLaneC
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22476U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneD[((aIndex + 26373U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24926U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23774U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneC[((aIndex + 22610U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 24U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = ((aWandererD + RotL64(aCross, 6U)) + RotL64(aCarry, 39U)) + 6654158889644956636U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 57U)) + 9045779659363991870U) + aPhaseBOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 3888897662136993491U) + aNonceWordO;
            aOrbiterK = (aWandererA + RotL64(aIngress, 27U)) + 6882016842864459345U;
            aOrbiterE = (aWandererF + RotL64(aCross, 39U)) + 15601891715956172291U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 46U)) + RotL64(aCarry, 53U)) + 5176811598629335350U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 13U)) + 12519945150889074325U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 51U)) + 4552583214397603278U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 19U)) + 14225482701804864688U) + aNonceWordA;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5485298070606280363U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11237713257388094289U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11032429223099413011U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14340345895626142788U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16275167270553643347U;
            aOrbiterJ = RotL64((aOrbiterJ * 7308578867128951199U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14041860597556520250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1436068974197066343U;
            aOrbiterG = RotL64((aOrbiterG * 3938460345031496843U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11483155566419547004U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4608508534724289325U;
            aOrbiterI = RotL64((aOrbiterI * 13461385011638899485U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2389196334288832895U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 4062682330273866602U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 8787682133271101901U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5655656046585592034U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 7977947821249746880U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10082104644185964787U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11653718118543974168U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5456429682072377614U;
            aOrbiterD = RotL64((aOrbiterD * 12504180638665296649U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12457179652004203574U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 445821754230182952U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 16043092621697786393U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12429505513284703263U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12480745784412363537U;
            aOrbiterK = RotL64((aOrbiterK * 643617210585287593U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 18U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 10U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterK, 29U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 50U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + aNonceWordB);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterE, 57U)) + aOrbiterK) + aNonceWordI) + aPhaseBWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 23U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterK, 44U));
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 39U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aNonceWordM) + aPhaseBWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 30U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27770U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 27611U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 29483U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27783U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((aIndex + 30914U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 13880995121909552664U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 10U)) + 14534942818069300546U) + aNonceWordM;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 57U)) + 17745973100886007133U) + aNonceWordH;
            aOrbiterE = (aWandererA + RotL64(aCross, 5U)) + 2249805580771946872U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 4460116116396439410U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 37U)) + 3378683994078106878U) + aPhaseBOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 23U)) + 3992996501048809123U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 51U)) + 12057768808864451929U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 44U)) + RotL64(aCarry, 13U)) + 4115362079047921130U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15297384955502206698U) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17623548383481905636U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7487278217901483685U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3559213898000162417U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12311605719074507335U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 3982199462062847697U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14807313864347885885U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11222085523291581822U;
            aOrbiterD = RotL64((aOrbiterD * 12580941911587215653U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 916681229436292462U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2441350114032314686U;
            aOrbiterB = RotL64((aOrbiterB * 7336079498999018067U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 7361470539894653271U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12153585147213579808U;
            aOrbiterI = RotL64((aOrbiterI * 3040327545467672961U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13566300726101613579U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14875254144748509128U;
            aOrbiterK = RotL64((aOrbiterK * 13699179902908972403U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9268158535644002904U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14144295981814993491U;
            aOrbiterE = RotL64((aOrbiterE * 12739937231684038161U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13861225650900541642U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12620513474052058164U;
            aOrbiterF = RotL64((aOrbiterF * 18141974182442267181U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14163773386433257965U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 5725700029399455855U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10446930901088908809U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 26U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + aNonceWordA) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 30U) + aOrbiterG) + RotL64(aOrbiterH, 48U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterF) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterK, 35U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 48U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterA, 20U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 11U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Boxing_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC62DCB00504C54E7ULL + 0xF5981F89FBAAB50FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEE4F255D645B7F97ULL + 0x81104B920D134047ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE7B7E32D8F4DFCCDULL + 0xFAC14E41A43E5958ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9B52F29E0DA3B539ULL + 0xBFFBE3014E8D63C0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8E4967F5B870817BULL + 0xF70F25075363CC94ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD2970A7D6FACB5A7ULL + 0xC3FDE6F5080446E7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB2CCE275C900510DULL + 0x8FB20E69DFB30FDFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD2FDF082E625E023ULL + 0xFB1238116AAE75F1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC065361A063B2C8FULL + 0x9ADE457D4CC068C0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD94C66642C3D5A3DULL + 0x8EE4F6D632C2182DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA535B59AE323DBC3ULL + 0x89384A044FDE62B9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA10479F1C107E599ULL + 0xF188B3B03E19D1D0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x887123A0E67D0EADULL + 0xC0DDDAD08F8D73A0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x85A7A4D193AD40AFULL + 0xE99E0D48579A0989ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCD9C17D2802AE69BULL + 0xD0D90DA1D0ABF727ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD7615DC032A731B9ULL + 0x84FD472AC9EF53DCULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 550U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 1617U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 3352U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3428U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4944U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 3001U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 23U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 42U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (aWandererC + RotL64(aPrevious, 5U)) + 1042610313571524121U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 54U)) + 3505725321008825582U) + aNonceWordB;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 19U)) + 12584654563843782991U) + aNonceWordO;
            aOrbiterG = (aWandererI + RotL64(aScatter, 39U)) + 6645399144515770935U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 3608978423753715584U;
            aOrbiterH = ((((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 8089198857670370983U) + aPhaseDOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 15207251813516399879U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9579268660105824516U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16055044469473802812U;
            aOrbiterD = RotL64((aOrbiterD * 2269649280637188723U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 583811872609805949U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 7027491967970873942U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 12686754713465826139U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18256061823189677508U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12708429127816136937U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12593886633108075321U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 12169216645156306078U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12694325407567795065U;
            aOrbiterB = RotL64((aOrbiterB * 3711789483877261899U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16109994660203297503U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4234704064165718913U;
            aOrbiterG = RotL64((aOrbiterG * 730085881474787681U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14119541943554602878U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8777769004811352951U;
            aOrbiterA = RotL64((aOrbiterA * 2556957257736134223U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15642663488392549609U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11594468530833278624U;
            aOrbiterH = RotL64((aOrbiterH * 6639306656361601143U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 20U) + aOrbiterE) + RotL64(aOrbiterD, 21U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 37U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordE) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 60U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 11U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5600U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 9576U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6822U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 8391U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10057U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6304U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6465U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 5U)) + 3612110001869385068U) + aNonceWordF;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 16340824141280225936U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 15222338965130765231U) + aPhaseDOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 52U)) + 6649270508107155041U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 43U)) + 768217258655426384U) + aNonceWordK;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 4481855259658861851U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 21U)) + 18318041934562434016U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4212457153804401807U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16143621095636987628U;
            aOrbiterC = RotL64((aOrbiterC * 6576072860505961427U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2095664232866642086U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 4339527736737366572U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17503569508822244125U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13679353177869884790U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11582168502846418236U;
            aOrbiterF = RotL64((aOrbiterF * 135539430034462861U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10451330452898542191U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12951448817640617841U;
            aOrbiterE = RotL64((aOrbiterE * 4141870904192742091U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15389161934419370747U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4754886272708253014U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16638243718191281597U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11746389873929280688U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12042680172517298768U;
            aOrbiterK = RotL64((aOrbiterK * 3814780289755857543U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2648103752465009244U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 451594673632597973U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8496763663271072425U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 56U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterI, 41U)) + aPhaseDWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 28U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterG, 13U));
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13632U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 15924U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16098U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14815U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12327U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 15904465836916519864U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 17725629806317789307U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 47U)) + 13794170125914914828U) + aNonceWordC;
            aOrbiterI = (aWandererH + RotL64(aScatter, 27U)) + 2149055907476874332U;
            aOrbiterD = (aWandererK + RotL64(aCross, 11U)) + 5342047776745074649U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 5U)) + 8268148484060546838U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 3U)) + 10821151364028563719U) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4294213820894407378U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10884726101307943090U;
            aOrbiterK = RotL64((aOrbiterK * 1116128870387229159U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16432210042202444824U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15196602644336228055U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12680438355124070237U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14117787670220328165U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 219833877949480215U;
            aOrbiterH = RotL64((aOrbiterH * 10736293047771972173U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3326396981881473962U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14918513066311426279U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14269763278564574663U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11795234681370163206U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3068267285352664813U;
            aOrbiterI = RotL64((aOrbiterI * 15746255933920904619U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 245233356957999496U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 709926406353796673U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 13627039596842073595U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5378105439430271038U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 10114555061122044430U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 5351295043424885549U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterF, 28U)) + RotL64(aCarry, 53U)) + aNonceWordO) + aPhaseDWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 21U)) + aOrbiterI) + aNonceWordH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 34U) + RotL64(aOrbiterB, 53U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterG, 47U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterH, 5U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterK, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 21444U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneA[((aIndex + 18243U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 20190U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21804U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17987U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aPrevious, 18U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererG + RotL64(aScatter, 13U)) + 18255347001097480328U) + aNonceWordJ;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 13679246790311505735U) + aNonceWordN;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 21U)) + 10565839529765027116U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 14327172566224769901U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 16239024612038195174U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 29U)) + 13800012174212131890U) + aPhaseDOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (((aWandererH + RotL64(aCross, 52U)) + 13900288860157577583U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4144386119777112740U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3154558262670631372U;
            aOrbiterB = RotL64((aOrbiterB * 13236911910092437063U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7456728543137614001U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11709519851158935384U;
            aOrbiterK = RotL64((aOrbiterK * 7016689518570071587U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15607438907832240304U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 9276575329661725624U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 8879744070762412745U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6459435969129449226U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6442382118416542275U;
            aOrbiterC = RotL64((aOrbiterC * 2921027306686588233U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12117432107282150865U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6831279293184793243U;
            aOrbiterI = RotL64((aOrbiterI * 2435360641135249073U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9520022957804572889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8322178689474588679U;
            aOrbiterA = RotL64((aOrbiterA * 1627707191467537115U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4162401591586869316U) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8994015844714895961U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15421910378057951895U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 6U) + aOrbiterI) + RotL64(aOrbiterC, 13U)) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + aPhaseDWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 26U)) + aOrbiterA) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterE, 57U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 41U)) + aOrbiterA) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 22173U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((aIndex + 22814U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24402U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 21986U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 26351U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 12U)) + (RotL64(aIngress, 39U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 11039986441331892533U) + aNonceWordL;
            aOrbiterF = ((aWandererE + RotL64(aCross, 23U)) + 6256024955965426119U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 60U)) + 9857443189988995666U) + aPhaseDOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 11900944813380998208U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 11U)) + 8422577734978875541U) + aNonceWordG;
            aOrbiterA = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 3100835100713928724U) + aNonceWordF;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 29U)) + 11871553509810206993U) + aNonceWordO;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17614749493763417027U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3638372131856199916U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 480683274898147025U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6582275259281025770U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17016882418498941958U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4269869255230867823U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1747214688658984715U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 9356088987044015278U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 16221733545319753695U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4056238112133473456U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 16013150119949532998U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12913648646318115315U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16076621211111834889U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9940824359571581765U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 11624767861336495331U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15624084004784515753U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7630989544834680335U;
            aOrbiterE = RotL64((aOrbiterE * 12261063237156822067U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18003586430673313786U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1654118743290334161U;
            aOrbiterA = RotL64((aOrbiterA * 1153250137357176071U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 42U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterK) + aNonceWordM) + aPhaseDWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterF, 21U));
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 10U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 28744U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((aIndex + 30521U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30420U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27753U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29468U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((aWandererC + RotL64(aIngress, 21U)) + 11700815697312060726U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 11U)) + 11808423452327465441U) + aNonceWordN;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 8670503858631730886U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 2400061067991988544U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 51U)) + 16163118178366229686U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 36U)) + RotL64(aCarry, 51U)) + 3280178595904941068U) + aNonceWordD;
            aOrbiterG = (aWandererB + RotL64(aCross, 43U)) + 3298683600817047727U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16321624053445183574U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6730229877611375225U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 2022290495153519279U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10162830636713641322U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15646771327759599256U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15333053762177144775U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14841751262270544102U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9545541117228834895U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 11529769874752969377U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14676615635857599982U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1231768638470558855U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 2716808508509014677U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1945905595345404833U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1406171421638586846U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4577864352425476233U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1970292335806697198U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12309719390375013297U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16540660957923687327U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5352135521358954576U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15465675376193501658U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16385761112921041387U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 37U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + aNonceWordO);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 23U)) + aOrbiterI) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aIngress, 42U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterI, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Boxing_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC6236D62693D1C9DULL + 0x99725C8E515F9EEDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x85EE508E5055770FULL + 0xB601FD1D3FBB9B52ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA6C0138A315BEDABULL + 0xF9CA938F7B6A933CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA1FF141A10FF57D3ULL + 0xAE3A38D6FD9724CBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE2597C259BBB4069ULL + 0xAAAF3923D85C390DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF4819A99ECCF0BEFULL + 0xE2975964BCC04567ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9528F4029A6AC74FULL + 0xC7C462F69E569435ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD3F430013FB4FB4BULL + 0x8C5F94A60D560FB7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA3E37A0BD6D430E3ULL + 0xE6E161F339EA2796ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8CC827B669F0553BULL + 0xD722ABDFE0BDB120ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAB4CAE98D8DCC769ULL + 0xFA669C5B7646EF74ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD430DE75C17A5FB3ULL + 0xC1F5DC293AB600CBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBB9CD82A8CA46C9FULL + 0xFCE609C4A6ADC355ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA9510EF07B9197ADULL + 0xCD9341B9F841669BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA35E5D8DA19187FDULL + 0xC63DB113959299A7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC5E7418F17E94427ULL + 0xF3B6D2347DCB5003ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3691U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneB[((aIndex + 3337U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4656U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2757U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3866U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4314U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 11U)) + 10812151398716051703U) + aNonceWordE;
            aOrbiterG = (aWandererC + RotL64(aIngress, 43U)) + 18202551453336003710U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 9434410809101973752U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 30U)) + 12955829998028534045U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 53U)) + 12271740641929640181U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 14009351527014534752U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 57U)) + 4316296955679133450U) + aNonceWordK;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 16473324966997442872U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 18U)) + 15735123324965019802U) + aNonceWordG;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 39U)) + 17656375090484080236U) + aNonceWordL;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 27U)) + 16066325053456055298U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12908968778503516903U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12761433987676836197U;
            aOrbiterF = RotL64((aOrbiterF * 1023329467480907925U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12737513138040664509U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14535795767570998392U;
            aOrbiterH = RotL64((aOrbiterH * 15560519667062222269U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14370908061811284364U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7001358781208669795U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 11641248025734015835U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7298578161120090849U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 10498302152357484629U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 13144110412179037175U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11447343228638006767U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18284143620422655675U;
            aOrbiterK = RotL64((aOrbiterK * 572862190073605651U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5918253208127360199U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3910541329178205943U;
            aOrbiterA = RotL64((aOrbiterA * 4550654545328228103U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 10357053096941367910U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5610891501128498748U;
            aOrbiterI = RotL64((aOrbiterI * 8676370811772047449U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9049881176058575811U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6307599924966452216U;
            aOrbiterJ = RotL64((aOrbiterJ * 5551444450572055895U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17109966783467892046U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11563095828344462249U;
            aOrbiterE = RotL64((aOrbiterE * 15463753739272001875U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3739147427725509014U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5324449517615050698U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 5926079615575226853U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5706251076252597592U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10812151398716051703U;
            aOrbiterG = RotL64((aOrbiterG * 5666491216813197045U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 44U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 41U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterF, 39U)) + aNonceWordB);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 51U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 37U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 34U) + aOrbiterH) + RotL64(aOrbiterF, 21U));
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterG, 18U)) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + aNonceWordO) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 10U) + aOrbiterD) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 23U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 56U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 6U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 10421U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 8913U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8780U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10418U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5738U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7366U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 9274U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (aWandererA + RotL64(aCross, 21U)) + 11210042748013785976U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 4584747303233477454U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 5U)) + 8878765929792969517U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 29U)) + 2172232330280041122U) + aPhaseEOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aWandererF + RotL64(aIngress, 51U)) + 8378937026022264016U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 10U)) + 8683007464695824208U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 13U)) + 9564352997357118134U) + aNonceWordH;
            aOrbiterA = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 11713878436769887528U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 57U)) + 8052917623074021077U;
            aOrbiterI = ((((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 7720597162792145185U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aWandererB + RotL64(aIngress, 48U)) + 2602847785328475621U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17813669222300509724U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8724263063156573013U;
            aOrbiterK = RotL64((aOrbiterK * 3632927017737834359U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6882429835961613492U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 13213313479525717359U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2411431247725974895U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2401526093648669573U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3616448566579979749U;
            aOrbiterA = RotL64((aOrbiterA * 13323155103752121393U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18268262471839710401U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5116424918948694752U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 7641143782996332069U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11405305689555640431U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12427591396711015574U;
            aOrbiterF = RotL64((aOrbiterF * 8112834135715541223U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16960781161508084626U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12382604781005282628U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17196168631120103115U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10054839091354729292U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4167641616532985407U;
            aOrbiterG = RotL64((aOrbiterG * 919291747187787625U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14383737233143309039U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16258779988369405932U;
            aOrbiterH = RotL64((aOrbiterH * 8348773195366160215U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4777263172049970723U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12498046021142146499U;
            aOrbiterI = RotL64((aOrbiterI * 5941015011162130901U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7435001955334177144U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4100235545173125433U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5046572784117638909U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1981704568071298614U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11210042748013785976U;
            aOrbiterD = RotL64((aOrbiterD * 17889749044418386565U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 22U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 50U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 13U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 27U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 21U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 56U)) + aOrbiterB) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 29U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + aNonceWordB);
            aWandererH = aWandererH ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterD, 39U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 12657U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 14898U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12459U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14227U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((aIndex + 12657U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 10336802574069791273U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 169025388197058936U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 37U)) + 6541354188379168846U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 3U)) + 16223920526599306104U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 24U)) + 12756613707692514808U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 5U)) + 5082475548176484035U) + aNonceWordA;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 47U)) + 4907435526952698526U;
            aOrbiterG = (aWandererH + RotL64(aCross, 53U)) + 14236627073831834337U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 40U)) + RotL64(aCarry, 57U)) + 11502511046130497584U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 13U)) + 3679044835550219497U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 27U)) + 11254838916686736746U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10582608424233200966U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10449735026385340313U;
            aOrbiterC = RotL64((aOrbiterC * 7363770199734997411U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4628253464169957835U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17664454668473204465U;
            aOrbiterB = RotL64((aOrbiterB * 4234720298731378527U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3798386391743884889U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1379331161819246587U;
            aOrbiterK = RotL64((aOrbiterK * 13086160171095077295U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9816600392407327227U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16781971616348376878U;
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4807797577690520554U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2492057261148595922U;
            aOrbiterE = RotL64((aOrbiterE * 9453302540675483005U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7909676419643119585U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 256053568910383007U;
            aOrbiterI = RotL64((aOrbiterI * 11965085163352053161U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16179914439220412472U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3968867762761955845U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 7473632378251893139U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7474832923901283742U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4736994731050735779U;
            aOrbiterF = RotL64((aOrbiterF * 9839654409121414047U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 596484364660389193U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13822222274464306169U;
            aOrbiterA = RotL64((aOrbiterA * 1723502278319885511U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16307920280681985443U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3505106171801702915U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8479675421552861243U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4987142580981135150U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10336802574069791273U;
            aOrbiterD = RotL64((aOrbiterD * 2670706512498539705U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 30U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 22U) + aOrbiterA) + RotL64(aOrbiterG, 41U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 56U)) + aOrbiterE) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 41U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + aNonceWordN) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterA, 19U));
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 23U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 30U) + aOrbiterI) + RotL64(aOrbiterD, 44U)) + RotL64(aCarry, 11U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16632U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((aIndex + 20112U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20102U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21842U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 20876U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 6U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 27U)) + 6654158889644956636U) + aNonceWordB;
            aOrbiterG = (aWandererG + RotL64(aScatter, 48U)) + 9045779659363991870U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 3888897662136993491U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 6882016842864459345U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 21U)) + 15601891715956172291U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 39U)) + 5176811598629335350U) + aNonceWordI;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 3U)) + 12519945150889074325U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 43U)) + 4552583214397603278U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 14U)) + 14225482701804864688U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 5485298070606280363U) + aPhaseEOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 11U)) + 11237713257388094289U) + aNonceWordP;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14340345895626142788U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16275167270553643347U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7308578867128951199U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14041860597556520250U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1436068974197066343U;
            aOrbiterF = RotL64((aOrbiterF * 3938460345031496843U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11483155566419547004U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4608508534724289325U;
            aOrbiterI = RotL64((aOrbiterI * 13461385011638899485U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2389196334288832895U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4062682330273866602U;
            aOrbiterD = RotL64((aOrbiterD * 8787682133271101901U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5655656046585592034U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7977947821249746880U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10082104644185964787U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11653718118543974168U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5456429682072377614U;
            aOrbiterH = RotL64((aOrbiterH * 12504180638665296649U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12457179652004203574U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 445821754230182952U;
            aOrbiterG = RotL64((aOrbiterG * 16043092621697786393U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12429505513284703263U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12480745784412363537U;
            aOrbiterB = RotL64((aOrbiterB * 643617210585287593U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6952219750393303609U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13965647644550998416U;
            aOrbiterJ = RotL64((aOrbiterJ * 5395755018020115073U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5602193483992512507U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9593414134773695959U;
            aOrbiterC = RotL64((aOrbiterC * 2186313187456153775U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16469843418561148995U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6654158889644956636U;
            aOrbiterK = RotL64((aOrbiterK * 17490973872858383001U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aPhaseEWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 6U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 51U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 44U) + aOrbiterC) + RotL64(aOrbiterB, 37U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 19U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterK, 39U));
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 60U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            aWandererC = aWandererC + (((RotL64(aIngress, 38U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23894U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 22305U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26784U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26585U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26793U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 27288U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 29U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 9107326720193244489U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 13U)) + 10868585484401664145U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 41U)) + 13637736741437846622U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 6130725216183918844U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 5U)) + 2063834478521338187U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aScatter, 44U)) + 8564870627911949158U) + aPhaseEOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aWandererB + RotL64(aIngress, 27U)) + 6524015751064086390U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 9874937766875388236U) + aNonceWordM;
            aOrbiterB = (aWandererC + RotL64(aScatter, 29U)) + 14723718409522680894U;
            aOrbiterD = (aWandererA + RotL64(aCross, 58U)) + 13767059954741528279U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 37U)) + 6387608251033722169U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5391425980008431000U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11524218415655093779U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12508457981779189389U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 155510463350385905U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10554591788433641311U;
            aOrbiterI = RotL64((aOrbiterI * 5412084824127934293U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8662160162966241542U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5092555636369853727U;
            aOrbiterG = RotL64((aOrbiterG * 433807340167635499U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7163345798448796101U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 695089002178413267U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 17302689458565434475U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5409173939213468972U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15349690077393827541U;
            aOrbiterC = RotL64((aOrbiterC * 10984681254001609841U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12376011890751302027U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7809614158898158383U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13845113198736843629U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13031938699536449576U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3983178190194056516U;
            aOrbiterF = RotL64((aOrbiterF * 1341678482929213405U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5567935037909671790U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 17137042627663349797U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 13535586899620672373U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8726085717433137208U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13154097637429217548U;
            aOrbiterE = RotL64((aOrbiterE * 5523758597936082363U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4030516340575723215U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7121696965917254968U;
            aOrbiterH = RotL64((aOrbiterH * 13569584361980228493U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12079991626282752674U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 9107326720193244489U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 7225937408665051799U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 48U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 21U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 40U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 54U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 41U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + aNonceWordD);
            aWandererG = aWandererG + ((RotL64(aScatter, 10U) + RotL64(aOrbiterD, 37U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterB, 50U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 34U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29308U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 28226U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29381U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31211U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31089U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 53U)) + 16160838483846078448U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 47U)) + 15404960896190227946U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 3U)) + 16904160594024977199U) + aPhaseEOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aWandererC + RotL64(aCross, 39U)) + 17790460246821031802U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 35U)) + 16395168254086971959U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 7484373204039901786U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 50U)) + 18026814691322913510U) + aPhaseEOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 19U)) + 15244817793136966450U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 5795491730356335666U) + aNonceWordF;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 11U)) + 3163873518027801504U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 14U)) + RotL64(aCarry, 39U)) + 2690791759507349172U) + aNonceWordC;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17898067251167087906U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8028010015006604239U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 5601629670521300241U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7304739457289910555U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6476837815096530043U;
            aOrbiterG = RotL64((aOrbiterG * 16380545138701113267U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14242499233467960602U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17305645693017634630U;
            aOrbiterA = RotL64((aOrbiterA * 14442976693206929569U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9772864059444171908U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7897200728282156408U;
            aOrbiterK = RotL64((aOrbiterK * 816306719390807411U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4890999319172950996U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8165132649356094963U;
            aOrbiterB = RotL64((aOrbiterB * 17297706071263690189U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9342923520083533265U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7213639583505088067U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 1349251979649428909U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4079475132684197272U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3350998022472827283U;
            aOrbiterH = RotL64((aOrbiterH * 948841791460066265U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2479140576609216238U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7703147534931674972U;
            aOrbiterF = RotL64((aOrbiterF * 11419116495223970801U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9050277787914448469U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13295888852307317371U;
            aOrbiterI = RotL64((aOrbiterI * 3027097172772140975U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15380254190549884741U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17653690414528791774U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15923958179714368315U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6825072759468337036U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16160838483846078448U;
            aOrbiterD = RotL64((aOrbiterD * 11690325563580492415U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 38U);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterC, 60U));
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterH, 12U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 57U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterB, 23U)) + aNonceWordK);
            aWandererF = aWandererF + ((((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
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

void TwistExpander_Boxing_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA06A36FE72C40AEFULL + 0xA7598B7BA4009F41ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD2F385B8825627A1ULL + 0x9ACF4875C6A18933ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF80949DEB087454DULL + 0xD99E8F61F90F324DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF95192EAD984CD41ULL + 0x9E4AB77FD0DA5722ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC6FE893F7710B253ULL + 0xBC04A05B8FED5E0CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xED36857C887FC51BULL + 0xAA8746AA9A3519FAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC005AF5D282A5037ULL + 0xC835C3C031706E2EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD8FE62BB1CFFFABBULL + 0xDD461E6A695E36EAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8782B02FC81E46B9ULL + 0xDA9F0C9728E74703ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA27E632F945B9D89ULL + 0xDC8C4FDFB80FD351ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCE1B9267C160EEEBULL + 0xB57F815F30A22AF8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCC2058856BE79109ULL + 0xC917250CC49397A4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9A4FE305ACBF32A3ULL + 0xAC378C0C3B954D19ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF073A1B6EE302243ULL + 0x8A10FFD2C98E57ABULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDAD96C66C10A0397ULL + 0xD81040FDB347D27EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCB36AE7DC06B2467ULL + 0xD31EF9CEF9CB7B3AULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneB, aOperationLaneC, aOperationLaneD, aSnowLaneA, aSnowLaneC, aWorkLaneD, aInvestLaneB, aSnowLaneD, aInvestLaneD, aExpandLaneA, aWorkLaneC, aExpandLaneB, aInvestLaneC, aExpandLaneC, aInvestLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneA backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5225U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 2715U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 814U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3395U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4799U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 3686U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 4751694786009671052U) + aNonceWordE;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 4U)) + RotL64(aCarry, 11U)) + 16362725160370844224U) + aNonceWordC;
            aOrbiterC = (aWandererF + RotL64(aIngress, 23U)) + 6360885380915941057U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 39U)) + 5154536007972297036U) + aNonceWordO;
            aOrbiterG = (aWandererE + RotL64(aIngress, 43U)) + 9362540581874808253U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 35U)) + 13902493871525612934U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 19U)) + 10208452885367546542U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 14U)) + 3117030377279160998U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 43U)) + 17286247690414027870U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3930314320040949141U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7289525252391668404U;
            aOrbiterC = RotL64((aOrbiterC * 15452162299105112187U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3434167955466809185U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17852573095128575663U;
            aOrbiterG = RotL64((aOrbiterG * 1485660158767033425U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6137259687928853253U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13992510605237574698U;
            aOrbiterD = RotL64((aOrbiterD * 15346263295995333395U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6470556523400123474U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 4333255670390099293U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11089933812030082647U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7700424876430257995U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16920736951239453071U;
            aOrbiterI = RotL64((aOrbiterI * 8920407493132380497U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1635071690430295730U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9966700845966398620U;
            aOrbiterA = RotL64((aOrbiterA * 17210048121896546867U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9833458070123027075U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1990346556486746432U;
            aOrbiterB = RotL64((aOrbiterB * 8704943923474148699U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 13339523466436517327U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5018264760406215603U;
            aOrbiterF = RotL64((aOrbiterF * 2769197961801783627U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 123427497520755346U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4535841104215792886U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 1417676310539177131U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 20U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterK, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 20U) + RotL64(aOrbiterB, 52U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterE, 19U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + aNonceWordH) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterG) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 36U)) + aOrbiterE) + aNonceWordB) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6718U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneC[((aIndex + 8238U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7013U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 10597U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8916U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9751U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9691U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCarry, 11U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 4204560462077827182U) + aNonceWordA;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 3U)) + 6572370199668594039U) + aNonceWordO;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 15958999876732622825U;
            aOrbiterB = (aWandererA + RotL64(aCross, 26U)) + 9969349486879280377U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 15450238998293956181U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 35U)) + 9128619863683138259U) + aPhaseFOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererD + RotL64(aScatter, 19U)) + 5691270563628979565U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 14U)) + 5901029710568933106U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aCross, 51U)) + 10442738941988588834U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3508116020325721993U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13221917083569767259U;
            aOrbiterH = RotL64((aOrbiterH * 6845108555710135357U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11627915460377128176U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17858261365514253433U;
            aOrbiterJ = RotL64((aOrbiterJ * 7535577636975884641U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4294837988806295989U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11242915481585070249U;
            aOrbiterC = RotL64((aOrbiterC * 17540688242763829319U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13030663829236027109U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7451948220723185149U;
            aOrbiterI = RotL64((aOrbiterI * 5191778587712222029U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5575508866505031037U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5161096033789876794U;
            aOrbiterA = RotL64((aOrbiterA * 16843827915802461797U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3980482740649505122U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11188906150207270241U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 408550837615188413U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4435504916461645189U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 9970252853543702833U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 5829143716916091997U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3766347619186305854U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11004616087340082895U;
            aOrbiterG = RotL64((aOrbiterG * 14469267845747063735U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17600791542296175812U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2556224430252009744U;
            aOrbiterF = RotL64((aOrbiterF * 14469426539907112137U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 24U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 18U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 40U) + RotL64(aOrbiterG, 53U)) + aOrbiterB) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterF, 39U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 28U) + aOrbiterF) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneD
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 11975U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 14655U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 11486U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 13418U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 15654U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 28U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 23U)) + 15549114274303128055U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 27U)) + 16466750056388063241U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 12209449840836787142U) + aNonceWordF;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 6U)) + 14551496099734294336U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 35U)) + 6266576428679808622U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 39U)) + 16892841575635668152U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 7375966221423362125U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 53U)) + 11926105302821753530U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 11U)) + 16219253791550461124U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7299056065319248160U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 15234001484933728439U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 8182244796017018911U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6615802589932632120U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5481176858895819247U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 3604590158551984877U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17220507586542139380U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14137921473739415340U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 10634645686035907603U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16981960446540932787U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10897565927079518588U;
            aOrbiterE = RotL64((aOrbiterE * 418843936329303571U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2746889569299593263U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 4894117146736361379U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 2656750612042673191U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18294823016957137777U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 86828501068883383U;
            aOrbiterF = RotL64((aOrbiterF * 11432686669235402365U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6322053762209547826U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6754524552483363820U;
            aOrbiterC = RotL64((aOrbiterC * 1746163087826694641U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7306452650619361017U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 12717201204443785828U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6121251603905574991U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10422327053543898585U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14786413282036348183U;
            aOrbiterI = RotL64((aOrbiterI * 8713024293107068275U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterD, 54U));
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterA, 23U)) + aPhaseFWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 30U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 34U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterD, 19U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21836U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneC[((aIndex + 20361U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 21732U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19512U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19019U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 37U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 4U)) + RotL64(aCarry, 3U)) + 12692813903177772178U) + aNonceWordI;
            aOrbiterF = ((aWandererC + RotL64(aCross, 19U)) + 7112496446691277899U) + aNonceWordC;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 2112247138290568813U) + aNonceWordD;
            aOrbiterD = (aWandererH + RotL64(aScatter, 53U)) + 3699421080882855947U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 57U)) + 13761832028354380922U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aWandererE + RotL64(aScatter, 41U)) + 9243822514887600214U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 30U)) + 6863833516853046129U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 37U)) + 8863897995943098018U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 13346785686701467520U) + aPhaseFOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15309543066305531619U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17515530938817919111U;
            aOrbiterI = RotL64((aOrbiterI * 16625193986319048245U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 760493237816424254U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7282586354117620860U;
            aOrbiterJ = RotL64((aOrbiterJ * 2327153408185290635U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4129706068526969105U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7020175432730888755U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 10095158356907592239U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9102258982216515596U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10822031305361453690U;
            aOrbiterK = RotL64((aOrbiterK * 2036205056490578491U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12571477440964330246U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8436347026653095199U;
            aOrbiterC = RotL64((aOrbiterC * 17930734781213681573U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14214789872073941940U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12915911919403385001U;
            aOrbiterB = RotL64((aOrbiterB * 13161681603528031511U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15443240166233851298U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7311369180113240915U;
            aOrbiterA = RotL64((aOrbiterA * 13339195007946889423U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12976516224995960015U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7823308381434556721U;
            aOrbiterD = RotL64((aOrbiterD * 502385172763861451U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4829417661664149137U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16306394751966719700U;
            aOrbiterE = RotL64((aOrbiterE * 5294376579588592157U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 10U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC);
            aWandererA = aWandererA + (((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 37U)) + aNonceWordO) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 14U)) + aOrbiterA) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 30U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25756U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneD[((aIndex + 22764U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22294U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21874U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 25575U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 14U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (aWandererA + RotL64(aIngress, 39U)) + 8402620908307642697U;
            aOrbiterE = (aWandererK + RotL64(aCross, 43U)) + 11347672014525086047U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 29U)) + 2816462912503401876U) + aPhaseFOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 11U)) + 6940159795470696093U) + aNonceWordI;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 53U)) + 9134692490095883851U) + aNonceWordO;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 4999455497008026526U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 19U)) + 5992451460350651332U;
            aOrbiterC = ((((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 3417087346651371924U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 24U)) + 3612773820086198270U) + aNonceWordH;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 463398077083428570U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 11249391303705089012U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 7106735772303292983U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17027535139825739501U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 568131384979596481U;
            aOrbiterG = RotL64((aOrbiterG * 5683451044852895957U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4793712537158004047U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 10415170179135963622U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 13729564030210361415U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 2391473979460065630U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4240058362680064261U;
            aOrbiterH = RotL64((aOrbiterH * 12375884373396400889U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9963957011090031698U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3325305624067445525U;
            aOrbiterD = RotL64((aOrbiterD * 3128542681461806309U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2094945647665114693U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10703615640774042674U;
            aOrbiterJ = RotL64((aOrbiterJ * 12641986098450423751U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3768738815518590289U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15021301790376706827U;
            aOrbiterI = RotL64((aOrbiterI * 14445850924223550339U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10571246886181608316U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5130325144599151793U;
            aOrbiterE = RotL64((aOrbiterE * 3185251943547657467U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8617523421720966373U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16574597770835250074U;
            aOrbiterC = RotL64((aOrbiterC * 1759209403428937799U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterJ, 23U)) + aNonceWordK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 58U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterI, 39U));
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 22U) + aOrbiterI) + RotL64(aOrbiterE, 19U)) + aNonceWordP);
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 48U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterH, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32618U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 29266U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 28958U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32640U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28480U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (aWandererH + RotL64(aScatter, 19U)) + 15652862298542575895U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 11U)) + 16925323928418184554U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 28U)) + RotL64(aCarry, 57U)) + 4413861484961668394U) + aNonceWordI;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 47U)) + 2215946422098155969U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 14975185533513111110U) + aPhaseFOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 9711613814905834552U) + aPhaseFOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 23U)) + 13154957291850149471U) + aNonceWordO;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 34U)) + 5058313016418534840U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 3U)) + 15011423472941211620U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2030053257469580168U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 150530795186791193U;
            aOrbiterD = RotL64((aOrbiterD * 11106050063717096073U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10878237472104183427U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11724672539469573109U;
            aOrbiterH = RotL64((aOrbiterH * 16158741837357985395U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9589700906445846956U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1367381624958248949U;
            aOrbiterI = RotL64((aOrbiterI * 8459515089081211977U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12003215666757518106U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11232479330848006729U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 10993290955464593033U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 13013910456628561621U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 6092509838924105265U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 805601154718006061U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11999225836250312801U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14421271973875748413U;
            aOrbiterA = RotL64((aOrbiterA * 9529010940887430157U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 15536288285741825272U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2071793889925436679U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 1526376970151714589U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5622386476463436967U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16147972771639168516U;
            aOrbiterC = RotL64((aOrbiterC * 11826916832825159095U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4519892856053952290U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12059500374938843538U;
            aOrbiterE = RotL64((aOrbiterE * 14987533625537956299U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 46U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 23U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterI, 4U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterD, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 21U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + aNonceWordF) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterI, 34U)) + aNonceWordA) + aPhaseFWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 19U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 53U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aCross, 14U) + aOrbiterA) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererI, 22U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Boxing_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x86342C56D89BC891ULL + 0xE188121B54540B59ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA033E74C340A52B1ULL + 0xF6A8BD63E8B1E6FDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD5257763392FFFA1ULL + 0xC83D36E0FF745090ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8F4272663A4A2D81ULL + 0xBB1CF5F3A2FC3075ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8DC916C1A9113955ULL + 0xF2F1C02A42CDC45DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDD61C5061C7527AFULL + 0x8CB4A7D27AB7E135ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD9217CBE9981888FULL + 0xDBAB2124D0716A8BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x868440C65865F9F5ULL + 0xE19FBEC406BD554BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDB749A0EE3ECB2A5ULL + 0xAC47858D5932AF90ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCD0613D30AC2363BULL + 0xE67C459DF677C018ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x95E22FDB0A5D740FULL + 0xFB7E35C646E05D7EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEE60254BC2B95A5BULL + 0xAD1A3DF0198A9137ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB355FA9F43AE4AFFULL + 0xCF629F382E17D58AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEC9C321BE0141ADBULL + 0xBA4DD02EA1F91B95ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9FD47DED5DE1DC0FULL + 0xC001BE57EBEC9A80ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBAAF65844DB51B9DULL + 0x9E525C9D2FC0F80CULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneC, aSnowLaneC, aSnowLaneD, aInvestLaneD, aWorkLaneA, aFireLaneB, aInvestLaneB, aWorkLaneB, aFireLaneD, aExpandLaneA, aFireLaneA, aExpandLaneB, aInvestLaneC, aExpandLaneC, aInvestLaneA
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 2411U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((aIndex + 581U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 5151U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2766U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 5076U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 105U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 12U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (aWandererH + RotL64(aIngress, 51U)) + 17264605017518259932U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 23U)) + 15209184354580778643U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 35U)) + 3299527965014731384U) + aNonceWordF;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 16293096431816127821U) + aNonceWordO;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 11031983436878828337U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 9188018632448236358U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererI + RotL64(aScatter, 44U)) + 13420816400363406556U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2485063384097917101U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3089135816938128264U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8813152992957361153U), 29U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 10730544971770435788U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10431767565618874806U;
            aOrbiterJ = RotL64((aOrbiterJ * 4723078464590561545U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14883796491656899074U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13465877783538483706U;
            aOrbiterF = RotL64((aOrbiterF * 14311686051108108503U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13322163435314643713U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3307316600284371955U;
            aOrbiterK = RotL64((aOrbiterK * 12337846092069506365U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4950101626975919939U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2596253994220103666U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 7181706961838582889U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17961706029559914243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10321902557977495175U;
            aOrbiterD = RotL64((aOrbiterD * 16189559888625084711U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 18146616411403012772U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8414050129421955787U;
            aOrbiterA = RotL64((aOrbiterA * 14879448948196182863U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 56U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 28U)) + aOrbiterA) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterA, 35U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterF, 43U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + aNonceWordE) + aPhaseHWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 46U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneB
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7515U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneC[((aIndex + 10320U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 5731U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8485U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8832U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6638U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6609U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 27U)) + 11210042748013785976U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 19U)) + 4584747303233477454U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 34U)) + RotL64(aCarry, 23U)) + 8878765929792969517U) + aNonceWordO;
            aOrbiterI = ((((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 2172232330280041122U) + aPhaseHOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 8378937026022264016U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 53U)) + 8683007464695824208U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 41U)) + 9564352997357118134U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11713878436769887528U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8052917623074021077U;
            aOrbiterJ = RotL64((aOrbiterJ * 7450115139081623477U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 7720597162792145185U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2602847785328475621U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14065077077207224525U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 17813669222300509724U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8724263063156573013U;
            aOrbiterD = RotL64((aOrbiterD * 3632927017737834359U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6882429835961613492U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13213313479525717359U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 2411431247725974895U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2401526093648669573U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3616448566579979749U;
            aOrbiterG = RotL64((aOrbiterG * 13323155103752121393U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18268262471839710401U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5116424918948694752U;
            aOrbiterI = RotL64((aOrbiterI * 7641143782996332069U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11405305689555640431U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12427591396711015574U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 8112834135715541223U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterE, 10U)) + aNonceWordN);
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 3U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + aNonceWordM) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 12U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + aPhaseHWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterG, 21U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aFireLaneD
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11828U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((aIndex + 11260U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15540U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14472U)) & S_BLOCK1], 44U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11664U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 21U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 14008824488073394623U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 13317978415866411468U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 5U)) + 13209180141897453900U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 47U)) + 11870521586865233578U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 29U)) + 8052156380448047385U) + aNonceWordO;
            aOrbiterB = (aWandererE + RotL64(aScatter, 38U)) + 12158131176743680605U;
            aOrbiterG = ((((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 14674467487607719347U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18055496790566231147U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3838105585041578784U;
            aOrbiterC = RotL64((aOrbiterC * 1075709247574580091U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2839568255183054418U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11933612922864258179U;
            aOrbiterB = RotL64((aOrbiterB * 7571964469321160347U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6289849094151630580U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2640344350528492271U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16197726750829369365U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16306175266267657791U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3339898380394883600U;
            aOrbiterA = RotL64((aOrbiterA * 7105436590182982373U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15017076663742800002U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8973064296077602496U;
            aOrbiterE = RotL64((aOrbiterE * 9309462227233615761U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17580319233338139859U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14063208878807603874U;
            aOrbiterI = RotL64((aOrbiterI * 16601475239075164585U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13326130855721009942U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12843186026737544416U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4975848122837321619U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 53U)) + aNonceWordM);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterI) + aNonceWordF);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 44U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterA, 53U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterK) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterE, 60U)) + aPhaseHWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18872U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 19007U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 17100U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20761U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 16976U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 29U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 21U)) + 1297415699043177788U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 17583786534509260153U) + aPhaseHOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 643197858925708798U) + aPhaseHOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 37U)) + 5062653766915694874U) + aNonceWordB;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 27U)) + 7034273638367180511U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 2026909726972916996U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 60U)) + 2785690475553211646U) + aNonceWordK;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2910341716302991892U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2834181605200829791U;
            aOrbiterA = RotL64((aOrbiterA * 1510617068750957651U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13323052600571281928U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10434901530315760460U;
            aOrbiterJ = RotL64((aOrbiterJ * 2042210188346767033U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 247903955625194782U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5196515747387257163U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 1799024689023272275U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7196305682377987476U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 14777739876892587484U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 95220583948241581U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10609060796540136671U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8386027207212484155U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4855610536246556893U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 729659744301903424U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2350564261412606157U;
            aOrbiterG = RotL64((aOrbiterG * 16713856782349084977U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16611987556673864177U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1525195188708550503U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10045858602151004553U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 54U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF) + aNonceWordI);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aPhaseHWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterA, 5U)) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterH, 12U)) + aPhaseHWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 53U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererB, 58U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22871U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 25250U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 25066U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24453U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 23104U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 21U)) + 13204735390996728477U) + aNonceWordH;
            aOrbiterG = (aWandererE + RotL64(aCross, 41U)) + 851171359595647173U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 29U)) + 16745304202825290723U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 57U)) + 562392736584913979U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 3244267012529053918U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 17282536111067869133U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 6U)) + RotL64(aCarry, 11U)) + 14851130066471729068U) + aNonceWordL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5256130407952363129U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 2904742485828362001U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 12941135856735075457U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3723346325449225387U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5344621093694027341U;
            aOrbiterJ = RotL64((aOrbiterJ * 9044881458629673499U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12919263300833603026U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17989801264160996071U;
            aOrbiterH = RotL64((aOrbiterH * 15468293047311883751U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5022175042377172157U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16684822380107847758U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 2834049270263837537U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2740326510600876682U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13981423865219318820U;
            aOrbiterG = RotL64((aOrbiterG * 14593082145080056441U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 231945878229848395U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14139797734944312580U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6492256080432266407U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16704102101387552373U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8506734780526852552U;
            aOrbiterB = RotL64((aOrbiterB * 4684566118627414659U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterG, 37U)) + aNonceWordF) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 13U)) + aOrbiterB) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 60U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aIngress, 4U) + aOrbiterK) + RotL64(aOrbiterB, 27U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 53U)) + aOrbiterH) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 18U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27627U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 31549U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 28948U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32395U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 31761U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = ((aWandererK + RotL64(aIngress, 13U)) + 3255291173184001106U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 15308468160116255528U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aWandererH + RotL64(aScatter, 57U)) + 18186972408589866656U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 28U)) + RotL64(aCarry, 51U)) + 4439324265978331914U) + aNonceWordK;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 13099263173016322486U) + aNonceWordH;
            aOrbiterD = (aWandererG + RotL64(aIngress, 41U)) + 7041561081767500660U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 5U)) + 6196422612687812971U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7664260932541281413U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17802347823020441056U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2220679459017369255U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4253107484061190446U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13799496534030645312U;
            aOrbiterF = RotL64((aOrbiterF * 9167675060053848207U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 14252892847595951926U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5663527578664291422U;
            aOrbiterI = RotL64((aOrbiterI * 18314294235895182465U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 11148755959699137661U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17036900929333594592U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16041243617369003291U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2403828181385259549U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17813580350434928194U;
            aOrbiterA = RotL64((aOrbiterA * 13666780980793857831U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 5623611126885414523U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7293224381174846969U;
            aOrbiterJ = RotL64((aOrbiterJ * 7032561584670788117U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10602620906929686163U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 18015916257203385982U;
            aOrbiterG = RotL64((aOrbiterG * 10684090189688871993U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + aPhaseHWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 11U)) + aPhaseHWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterA, 44U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 27U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 39U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 57U);
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

void TwistExpander_Boxing_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2593U)) & W_KEY1], 20U) ^ RotL64(aKeyRowReadB[((aIndex + 200U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2525U)) & W_KEY1], 46U) ^ RotL64(mSource[((aIndex + 1769U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 9654059367478508868U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 6473006635864677427U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 23U)) + 6944184481315853243U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 28U)) + 4061496421939102306U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 39U)) + 15791809275719085463U;
            aOrbiterD = (aWandererB + RotL64(aCross, 57U)) + 14050798802646323055U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 19U)) + 12072905924741758266U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 17639076509231343896U) + aPhaseAOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 14U)) + 12195388285571234715U) + aPhaseAOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4325404419499496529U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5910567888204238382U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11503787177122206937U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13092940059929942699U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13381962590820308761U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6345904465930943295U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15622862439323440527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14027151901132249793U;
            aOrbiterK = RotL64((aOrbiterK * 2273573821630510087U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4584410023907605157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15763755180625487157U;
            aOrbiterG = RotL64((aOrbiterG * 6755736130607297639U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17023059745666559199U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5298529579288492971U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2483562793328357721U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2870152867331654736U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12017191100173748848U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9958191466506480519U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15899529176182436062U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16482713846343388735U;
            aOrbiterA = RotL64((aOrbiterA * 719465695044265601U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12943393531812774449U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9881108254540483225U;
            aOrbiterJ = RotL64((aOrbiterJ * 8011108108007885059U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3532054586199716750U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7142230313294797435U;
            aOrbiterI = RotL64((aOrbiterI * 14154176174768868421U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 42U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterG, 19U));
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterG, 28U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + aPhaseAWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 52U) + aOrbiterH) + RotL64(aOrbiterA, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterC, 60U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4210U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 4402U)) & W_KEY1], 40U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2895U)) & W_KEY1], 5U) ^ RotL64(mSource[((aIndex + 3611U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 40U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aIngress, 35U)) + 2571116506511057880U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aPrevious, 19U)) + 13112435411509707292U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 52U)) + 10403251762787357256U;
            aOrbiterG = (aWandererD + RotL64(aCross, 43U)) + 8461951095541400405U;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 9890793478557463815U) + aPhaseAOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 23U)) + 3030229465991783707U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 7273848154043719247U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 10681774862516028276U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 30U)) + 7105082755586853104U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 6588579345319551129U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14616333550242386092U;
            aOrbiterH = RotL64((aOrbiterH * 2934574715879306337U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15439666290229654921U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3360304356760164799U;
            aOrbiterC = RotL64((aOrbiterC * 5164191920584106237U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14438730801970761889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14515616787452085729U;
            aOrbiterF = RotL64((aOrbiterF * 2041601927968559821U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4167853822635132419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8950982233003320239U;
            aOrbiterG = RotL64((aOrbiterG * 887144270884244907U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12391327853728029953U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7100871010552394421U;
            aOrbiterB = RotL64((aOrbiterB * 16552349374101955967U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15381697462381887944U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 6801677551341079401U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13325954438427340703U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 947011315719204867U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6356920162398333481U;
            aOrbiterD = RotL64((aOrbiterD * 5566721941682667419U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8910262020598577378U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8778455415977526457U;
            aOrbiterI = RotL64((aOrbiterI * 4092470497616637283U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5585696961453127223U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9670655481681494412U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7863197168965036383U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 58U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 48U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterF, 13U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + aPhaseAWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 28U) + aOrbiterF) + RotL64(aOrbiterG, 41U));
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 36U)) + aOrbiterI) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6955U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6410U)) & W_KEY1], 40U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6010U)) & W_KEY1], 36U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6285U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6792U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 57U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 13296600294247799698U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 34U)) + 5818503518080877515U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 6735784238734173597U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 51U)) + 7368398209488856201U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 13U)) + 961734029066455638U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 797011946660892011U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 3U)) + 12841876018396622350U;
            aOrbiterG = (aWandererC + RotL64(aCross, 47U)) + 16213253970483895623U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 22U)) + 15186950557113470375U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5117930310827477341U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12265429373166094162U;
            aOrbiterA = RotL64((aOrbiterA * 1522823535151532249U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13920531346698601568U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14695405206998211456U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13950964363414164279U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7851960904825938443U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9501511171732550190U;
            aOrbiterE = RotL64((aOrbiterE * 5614164120361489613U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5663365182245722077U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9607860124321315555U;
            aOrbiterG = RotL64((aOrbiterG * 3461820361914280601U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18171052650586819280U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3442698321538580861U;
            aOrbiterB = RotL64((aOrbiterB * 6317525514963824829U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1491052813469258970U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3956599824067616133U;
            aOrbiterK = RotL64((aOrbiterK * 2928600779267623085U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10963841237346073453U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2303020125591252534U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9969099842343321981U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14503856057958162356U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11147548150090597694U;
            aOrbiterJ = RotL64((aOrbiterJ * 11856382308792700441U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9191681438318311481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13556072770381999852U;
            aOrbiterH = RotL64((aOrbiterH * 18316231099054203683U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 54U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterG, 11U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 26U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 39U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterK, 43U)) + aPhaseAWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterG, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8974U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 10381U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 9149U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 8740U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10210U)) & W_KEY1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 8528U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 40U)) + (RotL64(aPrevious, 53U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererH + RotL64(aPrevious, 11U)) + 6521330037475130256U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 60U)) + 12611880456055428940U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 27U)) + 12061611078130934708U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 1558112410801116984U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 10509115227850160786U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 41U)) + 4045915960688792066U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 1196541286513243082U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 37U)) + 15564991032722373702U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 56U)) + 4897765238703641798U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12327429514907752733U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6189189797708711636U;
            aOrbiterG = RotL64((aOrbiterG * 9017615866338877651U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6374267075282018852U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1888758503831341439U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 74387714918264257U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14956857689299491800U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14879361107223331957U;
            aOrbiterB = RotL64((aOrbiterB * 9166712966729591953U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16086885494838105042U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8069724185844303923U;
            aOrbiterI = RotL64((aOrbiterI * 8878470736758734353U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10854345917959911439U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7078313614360332089U;
            aOrbiterD = RotL64((aOrbiterD * 9864025732292844871U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15083669236062255011U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 594879695916679116U;
            aOrbiterK = RotL64((aOrbiterK * 9852515479152735283U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6721466068234534523U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 475816724162626782U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4799725182757588407U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4341655358154605899U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15477254302340298586U;
            aOrbiterA = RotL64((aOrbiterA * 13961520225881974201U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10179091913200895775U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6310490897546909571U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15080621088825477613U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 58U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterK, 43U)) + aPhaseBWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 3U)) + aOrbiterG) + aPhaseBWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterH, 24U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 56U) + aOrbiterA) + RotL64(aOrbiterD, 52U));
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12265U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 13320U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12251U)) & W_KEY1], 30U) ^ RotL64(mSource[((aIndex + 11900U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 13056U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13145U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11317U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 57U)) + (RotL64(aIngress, 6U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererF + RotL64(aCross, 47U)) + 5573188770530340913U) + aPhaseBOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 1431772230889897111U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 28U)) + RotL64(aCarry, 37U)) + 4809192776429682319U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 5576603692574369341U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 11U)) + 2720143226007220386U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 35U)) + 17220328778565331629U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 56U)) + 9629485808442089423U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 23U)) + 1136998437010390983U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 5U)) + 11893390497814523841U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1764986431917532370U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1741014798007010376U;
            aOrbiterB = RotL64((aOrbiterB * 13414914086049500731U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12221368453236547044U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7694538641172350430U;
            aOrbiterD = RotL64((aOrbiterD * 8439120733670016501U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17472344518811560603U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3308740700728172984U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15290400462887712083U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9535358833412446771U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11192312491731312451U;
            aOrbiterC = RotL64((aOrbiterC * 17405609148475445743U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14850451970047190039U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11932493299452443256U;
            aOrbiterH = RotL64((aOrbiterH * 7964808728820467795U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5972619895614731870U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17174497535809891690U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15471084511364572533U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17412894714378898351U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14675615208706549810U;
            aOrbiterE = RotL64((aOrbiterE * 7864845089606499769U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16116792108013658523U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9702262005960966336U;
            aOrbiterG = RotL64((aOrbiterG * 970452849653781703U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17337264966818542841U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7004462033775827275U;
            aOrbiterJ = RotL64((aOrbiterJ * 11943575980344402681U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 44U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterD, 5U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 26U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 42U) + aOrbiterG) + RotL64(aOrbiterK, 57U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 12U)) + aOrbiterE) + aPhaseBWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 28U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16094U)) & S_BLOCK1], 54U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15567U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13789U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13878U)) & W_KEY1], 19U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15795U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15372U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14542U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 10805654776556844351U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 3U)) + 582794182442795335U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 2858343650974681068U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 34U)) + 8189584049022064284U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aScatter, 57U)) + 1565100751996962893U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 8062028016947611891U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 39U)) + 8280504280578451745U;
            aOrbiterH = (aWandererK + RotL64(aCross, 53U)) + 11326869194491655350U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 18U)) + 1671695656567777163U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2349843105293943452U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13015545152052004254U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1316662811685429983U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16703354404749291869U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8713231044374305801U;
            aOrbiterE = RotL64((aOrbiterE * 9242480982197688625U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11118401674497783533U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14857556493734710364U;
            aOrbiterK = RotL64((aOrbiterK * 3452566050389715195U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12953419670951660965U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12666121730825089017U;
            aOrbiterH = RotL64((aOrbiterH * 14049925256934142519U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11075249639473053423U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9374217688244187867U;
            aOrbiterJ = RotL64((aOrbiterJ * 5261156325627117877U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17608340953291367867U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13159437499327086340U;
            aOrbiterA = RotL64((aOrbiterA * 4882100944453534805U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4304700511322366815U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10172544755256706767U;
            aOrbiterD = RotL64((aOrbiterD * 4013006212154771797U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17340067939877432472U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14130447570008179105U;
            aOrbiterC = RotL64((aOrbiterC * 8178075071208718915U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2652532710498072378U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10384945384238518296U;
            aOrbiterI = RotL64((aOrbiterI * 17137694272394304045U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 38U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterI, 23U));
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 27U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + aPhaseBWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 12U) + aOrbiterC) + RotL64(aOrbiterI, 12U)) + aPhaseBWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 19062U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 18048U)) & W_KEY1], 38U));
            aIngress ^= (RotL64(mSource[((aIndex + 16385U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 17862U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 19109U)) & W_KEY1], 53U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16492U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18223U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 5576732410244514238U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 35U)) + 2833808925935929629U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 53U)) + 3670188682914544792U) + aPhaseCOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 15759072378887814995U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 14U)) + 13934007231137439994U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 47U)) + 11022225696007690512U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 16989177104453635790U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 21U)) + 9256930045263527091U) + aPhaseCOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aCross, 10U)) + 17788596104417068290U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17044369456673337625U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1310908395523250343U;
            aOrbiterH = RotL64((aOrbiterH * 16305084373037705921U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12067065689034065422U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15130844248737512262U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9409499577465934107U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14532689204495587494U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8198147292120244178U;
            aOrbiterD = RotL64((aOrbiterD * 1418356389507740991U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5485494458627163347U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10830008207150307611U;
            aOrbiterE = RotL64((aOrbiterE * 6526039534042499457U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17770065502486618029U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6397859353395335459U;
            aOrbiterI = RotL64((aOrbiterI * 14286997752368893825U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5128700697381508319U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7103394110057060499U;
            aOrbiterF = RotL64((aOrbiterF * 5053680689949149633U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16024401282261796979U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12818445221897253410U;
            aOrbiterK = RotL64((aOrbiterK * 11450004517784155405U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 13386978409145916350U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16740821954556699503U;
            aOrbiterG = RotL64((aOrbiterG * 5376430209628515105U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 313978038530994953U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1355733685461795345U;
            aOrbiterA = RotL64((aOrbiterA * 15955927322082619735U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterE, 58U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 46U) + aOrbiterE) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterG, 53U));
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterK, 48U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterI, 39U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19233U)) & S_BLOCK1], 60U) ^ RotL64(mSource[((aIndex + 20100U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21037U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 19811U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20721U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19121U)) & W_KEY1], 5U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20885U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((aIndex + 20180U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 47U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererH + RotL64(aCross, 35U)) + 14249093584376402677U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 30U)) + RotL64(aCarry, 37U)) + 8756965951816492264U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 21U)) + 11221139480258176330U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 17218894445564194851U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 8064642692524949490U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 43U)) + 5822093203710704646U) + aPhaseCOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 3U)) + 3217799620158102238U) + aPhaseCOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 51U)) + 2613757677892120843U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 14U)) + 13647481499551657237U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3545714196663685016U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9735422670576621521U;
            aOrbiterD = RotL64((aOrbiterD * 7276207208162697249U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3911046580637583767U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9315984027042049203U;
            aOrbiterA = RotL64((aOrbiterA * 12568550776487242469U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8926367674641729058U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11035347490524961446U;
            aOrbiterB = RotL64((aOrbiterB * 10948288997163592463U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10748158733051120339U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2467801787989056455U;
            aOrbiterG = RotL64((aOrbiterG * 12621934274702358977U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9244415080474351390U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8517784887959492079U;
            aOrbiterK = RotL64((aOrbiterK * 17022899813765884147U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8409307332803038455U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11043806021873232950U;
            aOrbiterC = RotL64((aOrbiterC * 8294888329708842989U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17512395828450251457U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16849067939795823992U;
            aOrbiterE = RotL64((aOrbiterE * 9361991804481514337U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 17541946638063238056U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11430501673960586718U;
            aOrbiterI = RotL64((aOrbiterI * 15074409630605450091U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 78307505705383302U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4834528975263832983U;
            aOrbiterH = RotL64((aOrbiterH * 17245673681686752861U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 36U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 18U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterE, 53U));
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 60U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 13U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 23U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterH, 27U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 37U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 20U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24286U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 21896U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22412U)) & W_KEY1], 18U) ^ RotL64(aFireLaneC[((aIndex + 23813U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22424U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23354U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24275U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23354U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 36U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererC + RotL64(aIngress, 53U)) + 5480870806135400132U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 19U)) + 8034874599430768743U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 10U)) + 4006919843736863767U;
            aOrbiterK = (aWandererA + RotL64(aCross, 29U)) + 2988069748674633718U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 47U)) + 12347295651973135786U) + aPhaseCOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 14152683894431568192U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 40U)) + 15765143815254196598U) + aPhaseCOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 43U)) + 10473067082331244233U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 1089466925383677249U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13215039929873682230U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3957997712247961479U;
            aOrbiterA = RotL64((aOrbiterA * 7631186240013784703U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10023907397941685546U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14593012591254614353U;
            aOrbiterJ = RotL64((aOrbiterJ * 17111300092082154687U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13353797968154036726U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9259966668512102858U;
            aOrbiterE = RotL64((aOrbiterE * 8326732574268308221U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10757861831070349321U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10530223113483866178U;
            aOrbiterI = RotL64((aOrbiterI * 11269177745265396583U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7554320926405521865U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6978052067277966996U;
            aOrbiterD = RotL64((aOrbiterD * 18020134738536217801U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1053695861967171420U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15980734683539854451U;
            aOrbiterB = RotL64((aOrbiterB * 3208466640010555357U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17041258393808061556U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 12846551858751995530U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9303891433380993639U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14617434286683320666U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3999309956180741302U;
            aOrbiterK = RotL64((aOrbiterK * 15037707937050015205U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13452627760403094126U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2633241575260427158U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2638570213290747581U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 48U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 19U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aIngress, 54U) + aOrbiterB) + RotL64(aOrbiterD, 26U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterA, 3U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 50U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 58U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25466U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 24799U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25968U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 26774U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26669U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25606U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26029U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26470U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 39U)) + 964165145848253292U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 58U)) + 10645976767204934746U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 8241612229349212650U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 4159196033256913347U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 19U)) + 7194795864620233507U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 43U)) + 7638928444536778384U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 27U)) + 11819105916503968109U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 23U)) + 18052213302858186237U) + aPhaseDOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 14U)) + RotL64(aCarry, 11U)) + 8663575313970041570U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16644136720439299786U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16930316530442679864U;
            aOrbiterE = RotL64((aOrbiterE * 2650922074098320859U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16251107616988250593U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7171986193609401665U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3543709971414550087U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17885046834432626644U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7757069274715713557U;
            aOrbiterF = RotL64((aOrbiterF * 15766885299397923879U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2212805322061155615U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6368539134638838822U;
            aOrbiterK = RotL64((aOrbiterK * 13383744883433594259U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5264326094252925613U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6126345334815012938U;
            aOrbiterA = RotL64((aOrbiterA * 17180934809764905307U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13826731214018407061U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6621261811613643620U;
            aOrbiterH = RotL64((aOrbiterH * 2823596473596114171U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5964406317285863781U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2167324450276308078U;
            aOrbiterB = RotL64((aOrbiterB * 1098346374733634905U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16740710162977859724U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8236083581048717923U;
            aOrbiterI = RotL64((aOrbiterI * 4364887787000704039U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13967473987446124012U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5136051802217149813U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13997246005108872883U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 20U) + aOrbiterH) + RotL64(aOrbiterC, 47U));
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 56U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 12U) + aOrbiterK) + RotL64(aOrbiterB, 37U)) + aPhaseDWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 11U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 19U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29121U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((aIndex + 29025U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28861U)) & W_KEY1], 3U) ^ RotL64(aFireLaneC[((aIndex + 28376U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29272U)) & W_KEY1], 52U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27586U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27447U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 28299U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 41U)) + 8375305456876489425U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 3U)) + 16193562952772453047U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 37U)) + 18088652458594816223U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 10U)) + RotL64(aCarry, 11U)) + 767344788620249944U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 23U)) + 7705194930396368752U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 3829736891311272834U;
            aOrbiterE = (aWandererA + RotL64(aCross, 53U)) + 9881681671347640061U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 1721196560190164264U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 48U)) + 3002652618388454213U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9811621464004005202U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5652598941069986530U;
            aOrbiterK = RotL64((aOrbiterK * 4797973356708091621U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6250499348327316328U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16025054277615264530U;
            aOrbiterH = RotL64((aOrbiterH * 16446892258704281903U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13800298546867243172U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12256104592865905782U;
            aOrbiterE = RotL64((aOrbiterE * 16983140179497142713U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17817225416918329229U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 17738671327352776217U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 393488251327705063U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6816031224188400541U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16989563985059237014U;
            aOrbiterG = RotL64((aOrbiterG * 8677884225771717797U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16891524847268207549U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1833508573940405571U;
            aOrbiterI = RotL64((aOrbiterI * 9709196587703979539U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12729999421507068973U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6839758643521968957U;
            aOrbiterF = RotL64((aOrbiterF * 16350557395881283975U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 8524167125469267428U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14741523560290472617U;
            aOrbiterB = RotL64((aOrbiterB * 4367850822282205897U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10983798459868424892U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5649250846622078964U;
            aOrbiterA = RotL64((aOrbiterA * 7149612714806023987U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 38U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterK, 35U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 30U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterA, 3U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterA, 21U)) + aPhaseDWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 58U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 26U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 53U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31277U)) & S_BLOCK1], 20U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32648U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32714U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32259U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31659U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 30358U)) & W_KEY1], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 51U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererK + RotL64(aCross, 5U)) + 18319689184146942855U) + aPhaseDOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 47U)) + 8041304130090501019U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 24U)) + 11347064191990897738U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 11U)) + 15242243470024447468U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 10619749107163611105U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 14795614276221947128U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 37U)) + 1578095288886372393U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 51U)) + 13593906305770501684U) + aPhaseDOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 56U)) + 8919815528334599172U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17425548324720065145U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 11125018338392347335U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4377887040461528587U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3779189180734244399U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10958224663276134041U;
            aOrbiterD = RotL64((aOrbiterD * 6206963519509783781U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4317305352561612995U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4891139433808505355U;
            aOrbiterG = RotL64((aOrbiterG * 11507024985663120317U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5166074784835930965U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10080890270621589202U;
            aOrbiterI = RotL64((aOrbiterI * 13170894418184288695U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4501071771615514619U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6486573807774431753U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 324029625116648669U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15714881857668975753U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3506619392820235900U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5707033870161224499U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5295711072762443783U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11192836530396570648U;
            aOrbiterH = RotL64((aOrbiterH * 4361810118382207039U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7993389678399774574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12551394763541226695U;
            aOrbiterF = RotL64((aOrbiterF * 11903486656172026403U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11553674370322129668U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4459881583199320245U;
            aOrbiterB = RotL64((aOrbiterB * 2805857426321555685U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 10U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterH, 38U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 29U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 18U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterB, 24U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 40U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Boxing_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneA, aInvestLaneD, aFireLaneD, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1462U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 1577U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 2729U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 3441U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 48U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 1393781663398437180U) + aPhaseEOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 17414594746688585273U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 43U)) + 2823888497053071250U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 19U)) + 17032631958617884859U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 35U)) + 15222697630461125019U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 53U)) + 15737414920751551780U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 53U)) + 1357196111055783001U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5315122321649251691U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7893744655508595974U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17863000246694319149U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16721939414324611738U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3444375866323610848U;
            aOrbiterI = RotL64((aOrbiterI * 10874157227815775661U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1825716513674511632U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15582066843912467318U;
            aOrbiterK = RotL64((aOrbiterK * 12765146555943757373U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15673590949193923915U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13887365046280406413U;
            aOrbiterG = RotL64((aOrbiterG * 3169061375011420121U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12730414371734709356U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4819112390640821927U;
            aOrbiterE = RotL64((aOrbiterE * 8782547948627685451U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3089925954422937464U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7180179304678622530U;
            aOrbiterF = RotL64((aOrbiterF * 16118051565147747413U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17030269962085008657U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6675917351883004046U;
            aOrbiterB = RotL64((aOrbiterB * 14134335325316949687U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterB, 19U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 52U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + RotL64(aOrbiterI, 13U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterG, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10534U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 10618U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 8192U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6521U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((aIndex + 5866U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererA + RotL64(aScatter, 23U)) + 14008824488073394623U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 13317978415866411468U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 4U)) + 13209180141897453900U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 11870521586865233578U;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 8052156380448047385U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aScatter, 39U)) + 12158131176743680605U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 29U)) + 14674467487607719347U) + aPhaseEOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18055496790566231147U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3838105585041578784U;
            aOrbiterJ = RotL64((aOrbiterJ * 1075709247574580091U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2839568255183054418U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11933612922864258179U;
            aOrbiterB = RotL64((aOrbiterB * 7571964469321160347U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6289849094151630580U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2640344350528492271U;
            aOrbiterI = RotL64((aOrbiterI * 16197726750829369365U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16306175266267657791U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3339898380394883600U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7105436590182982373U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15017076663742800002U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8973064296077602496U;
            aOrbiterF = RotL64((aOrbiterF * 9309462227233615761U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17580319233338139859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14063208878807603874U;
            aOrbiterA = RotL64((aOrbiterA * 16601475239075164585U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13326130855721009942U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12843186026737544416U;
            aOrbiterG = RotL64((aOrbiterG * 4975848122837321619U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aIngress, 12U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 58U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13250U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 16038U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 15589U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14538U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13948U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 12407U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 13U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 12690502671561165478U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 41U)) + 17519943923428102801U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 4U)) + RotL64(aCarry, 53U)) + 10705515807975331385U) + aPhaseEOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 57U)) + 16586447272278538179U;
            aOrbiterI = (aWandererH + RotL64(aCross, 19U)) + 8006560996840971798U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 35U)) + 12928600185788857701U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 14240723153798267172U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8636219177994872072U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7586790235186467512U;
            aOrbiterA = RotL64((aOrbiterA * 15052686382507614169U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1103807034179512424U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7547526530239498693U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3360295583636013509U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8380239679344786397U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5690809173787433519U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5354724308093372953U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8390902801141804609U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3507306189192059486U;
            aOrbiterG = RotL64((aOrbiterG * 18336280496510253103U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6190745292098482871U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8065418693975056902U;
            aOrbiterD = RotL64((aOrbiterD * 6414621418430102589U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12111755051718111803U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7605877769709909297U;
            aOrbiterF = RotL64((aOrbiterF * 17525248694315944599U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5969794501112646237U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5127559299360591476U;
            aOrbiterC = RotL64((aOrbiterC * 4521563633438853069U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterI, 37U));
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 18U) + aOrbiterD) + RotL64(aOrbiterF, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 44U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18113U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 21171U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 17242U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 20820U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19865U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18783U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererD + RotL64(aPrevious, 13U)) + 17912271996338180948U;
            aOrbiterF = (aWandererK + RotL64(aCross, 27U)) + 13259276608841847058U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 16225936008657276089U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 58U)) + 2243058962151834071U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 5U)) + 10637439274127347861U;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 15312219216405992627U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 2393933972129878613U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4327069337247976513U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8307656353434167837U;
            aOrbiterB = RotL64((aOrbiterB * 11386588389133096705U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17299145556933889336U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14458100581172798164U;
            aOrbiterF = RotL64((aOrbiterF * 16543734663677070509U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6410095654927998067U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6168964796264687686U;
            aOrbiterK = RotL64((aOrbiterK * 16218071040190475953U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 3667999465041020730U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16021552859323602007U;
            aOrbiterI = RotL64((aOrbiterI * 6427266472526362663U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12941668202330045095U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4222032891850449934U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17292856787431308097U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 1346342592002730785U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16860611785008118820U;
            aOrbiterE = RotL64((aOrbiterE * 384963420804756607U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3193572711804730241U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5866881282680588589U;
            aOrbiterG = RotL64((aOrbiterG * 9226331800853634597U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 3U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 28U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aIngress, 10U) + RotL64(aOrbiterE, 47U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 19U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterD, 13U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26380U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 23270U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22657U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21855U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23255U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 26014U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 6U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 57U)) + 785861751704720606U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 15968088718435606299U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 1393976526590347151U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 17240750947292745884U;
            aOrbiterF = (aWandererK + RotL64(aCross, 27U)) + 4921576136163183137U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 34U)) + 3334047873553153032U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 47U)) + 15086509978458408698U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 892391205397581998U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2965686403183767521U;
            aOrbiterA = RotL64((aOrbiterA * 709160942482770225U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14632215393655706170U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15740589515342377322U;
            aOrbiterF = RotL64((aOrbiterF * 15677716942904794913U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11131164813943086445U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6988080581278900960U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6412189142344044255U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16021254613117657178U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6183615599897921154U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9976411093264211033U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12533992547026652747U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3104325358982904219U;
            aOrbiterD = RotL64((aOrbiterD * 14977348108778147265U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3878525937957474644U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2120435259884368445U;
            aOrbiterJ = RotL64((aOrbiterJ * 15964718652193073177U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14928658302694194856U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9121310461310309348U;
            aOrbiterK = RotL64((aOrbiterK * 17304439784647477491U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 37U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aIngress, 30U) + aOrbiterD) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 6U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28204U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 30781U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 29019U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29781U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32649U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 28824U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 43U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 9220392006207660113U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 50U)) + RotL64(aCarry, 43U)) + 11305018553489132882U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 21U)) + 5860373868073513684U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 12319586170883987589U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 27U)) + 14072333614354649021U) + aPhaseEOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 57U)) + 9332158529453194608U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 41U)) + 3860569321145958686U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8119005668901240093U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13918259792880333239U;
            aOrbiterH = RotL64((aOrbiterH * 5441062406822088853U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6938856216758228704U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3960905839118710604U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16203746868670689793U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6043879193734253929U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15691425268831319195U;
            aOrbiterE = RotL64((aOrbiterE * 7189195135654636271U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14912209933584715274U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16180183395910618923U;
            aOrbiterF = RotL64((aOrbiterF * 3942858974766467849U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4966642362507707776U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6962226782462822861U;
            aOrbiterJ = RotL64((aOrbiterJ * 3647802407741095419U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12409120845092026295U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2302946450253872465U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7099576330777297911U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16118304388937163838U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15968419034359049422U;
            aOrbiterA = RotL64((aOrbiterA * 11736207775827080165U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 13U)) + aOrbiterH) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterA, 47U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterF, 57U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 28U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Boxing_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneB, aOperationLaneC, aOperationLaneD, aInvestLaneD, aSnowLaneA, aExpandLaneA, aInvestLaneC, aSnowLaneB, aExpandLaneC, aWorkLaneA, aInvestLaneB, aWorkLaneB, aExpandLaneD, aWorkLaneC, aInvestLaneA
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 789U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 423U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 4168U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5063U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4215U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 957U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aIngress, 23U)) + 3561491146322798260U;
            aOrbiterG = (aWandererB + RotL64(aCross, 28U)) + 7075025056181885339U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 9230910887904171613U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 41U)) + 4119781172609908917U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 17155609083870983149U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 2423018561430181695U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 35U)) + 12957280305617615744U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 47U)) + 2461704174772065813U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 60U)) + 7907123257849391997U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 3U)) + 7257868138318960007U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aIngress, 51U)) + 16425903703085702285U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2990822664594079467U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5654819006718953817U;
            aOrbiterI = RotL64((aOrbiterI * 4465096036756887801U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12183676471235678779U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15026286960542123922U;
            aOrbiterD = RotL64((aOrbiterD * 17199049329995315279U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12169080607071830522U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2906296852254787499U;
            aOrbiterC = RotL64((aOrbiterC * 6754514406846040163U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3029858695410344584U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14406410317495954566U;
            aOrbiterA = RotL64((aOrbiterA * 9663780721657983421U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11048818178401163861U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13622063920319445043U;
            aOrbiterG = RotL64((aOrbiterG * 2516025554421589857U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2642646089141233277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12761571777929273548U;
            aOrbiterE = RotL64((aOrbiterE * 5518252696078700127U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7753802695131502382U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8510425459525030222U;
            aOrbiterH = RotL64((aOrbiterH * 12412361423636026483U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13522645164493316722U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1437430302489702713U;
            aOrbiterK = RotL64((aOrbiterK * 14019316635365783545U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14745189473423751499U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16968328257002103715U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17915588590593471981U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5001838243344386314U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13506188720092630563U;
            aOrbiterF = RotL64((aOrbiterF * 7010027510838271877U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16902624500530747723U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3561491146322798260U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 95761172090277669U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 28U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterA, 47U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 37U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 53U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 44U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterA, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 21U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 41U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 4U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneA
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7023U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((aIndex + 6673U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5463U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5955U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10730U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8321U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 9219U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 51U)) + 13278949403988203974U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aPrevious, 34U)) + 9213599924054673756U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 1255746482932381798U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 5U)) + 11575321997144516122U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 57U)) + 15881587525529432437U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 9846195809864862707U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 47U)) + 12319815691858217670U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 39U)) + 16322617427294439587U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 18U)) + 16332130810525887437U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 4920951156015336794U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 27U)) + 16767126455124552329U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12553595911087945223U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1437522202135436142U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2001992794165550905U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12313100454852227143U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2761983020631055729U;
            aOrbiterE = RotL64((aOrbiterE * 3874839760378039509U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17635303588421554367U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 788212489507463763U;
            aOrbiterA = RotL64((aOrbiterA * 17896475584538528059U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5192552894670654434U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6784748488807738811U;
            aOrbiterJ = RotL64((aOrbiterJ * 8077237651953896479U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16113417046719114943U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1096874945215225916U;
            aOrbiterK = RotL64((aOrbiterK * 17308604412622879833U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7610274704570171595U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10466070212284342550U;
            aOrbiterH = RotL64((aOrbiterH * 6449728258497920613U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6777845928873855221U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5251515022021984126U;
            aOrbiterC = RotL64((aOrbiterC * 9018277343404261611U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13849343158824111498U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7977711210181714021U;
            aOrbiterD = RotL64((aOrbiterD * 4182053966171053577U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6494539818728106982U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11314590450226080781U;
            aOrbiterF = RotL64((aOrbiterF * 12455979257225599157U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 552687702594328012U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14961304171192292246U;
            aOrbiterG = RotL64((aOrbiterG * 846375892915484717U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9771874402848476494U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13278949403988203974U;
            aOrbiterI = RotL64((aOrbiterI * 2119203863777871233U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 58U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 50U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterG, 27U));
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterD, 23U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aCross, 14U) + aOrbiterH) + RotL64(aOrbiterB, 10U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterD, 41U));
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneC
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14652U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((aIndex + 14773U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12121U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11951U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 16160U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 42U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 3U)) + 3917730204724097072U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 41U)) + 1874642340716212824U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 26U)) + 6900165757434854160U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 29U)) + 12750946097023807161U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 39U)) + 6563216048479513594U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 14960240191349450795U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 16306180275951788289U;
            aOrbiterE = (aWandererB + RotL64(aCross, 57U)) + 6502066618271045547U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 60U)) + 6219852857850888738U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 2272931312452845850U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 11U)) + 3028929882263199463U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6067393030073568112U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10094809900437037258U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18095564940730322769U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5962414178157074575U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15755563045799129417U;
            aOrbiterC = RotL64((aOrbiterC * 3692603590609922031U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6321455513889880590U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1197435601998121700U;
            aOrbiterG = RotL64((aOrbiterG * 17693996266260557625U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12496949381666299968U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6357070235648527030U;
            aOrbiterI = RotL64((aOrbiterI * 2931486644220862433U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8423760160877540210U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8090246492554850768U;
            aOrbiterD = RotL64((aOrbiterD * 2949407491181921633U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11436635942985063755U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17086363141014359856U;
            aOrbiterA = RotL64((aOrbiterA * 10504127577318206801U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10734017887545474935U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 375515325165740779U;
            aOrbiterK = RotL64((aOrbiterK * 9980486695448151709U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5217148491945389821U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14696058217023530058U;
            aOrbiterH = RotL64((aOrbiterH * 11026674782236654799U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11869055287836412650U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16951500118659983436U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4304372681583055077U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7866300390953569803U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 18017335943787362993U;
            aOrbiterJ = RotL64((aOrbiterJ * 15683049583437004889U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2477944286851267725U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3917730204724097072U;
            aOrbiterE = RotL64((aOrbiterE * 6617615984203047419U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 44U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 50U) + aOrbiterH) + RotL64(aOrbiterF, 5U));
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterK, 27U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 60U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 46U) + aOrbiterK) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17589U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneA[((aIndex + 18438U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17282U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17356U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 18519U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 19U)) + (RotL64(aCross, 52U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 2168513956284366370U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 47U)) + 10290361969974613111U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 57U)) + 15673836275828498050U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 41U)) + 16600540024145812236U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 35U)) + 9428052101528111892U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 27U)) + 12763657928312763377U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 23U)) + 10751286982008662485U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 1708230173038057979U;
            aOrbiterI = (aWandererA + RotL64(aCross, 19U)) + 4011389705422783816U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 53U)) + 11704428328093077714U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 10U)) + 2055336619674699284U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1870865272102705804U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3574214263751923179U;
            aOrbiterG = RotL64((aOrbiterG * 13132083406834413563U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 984611970726966186U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 15207945449947643672U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9539470161576639981U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4181398506373973169U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15222345431506025949U;
            aOrbiterD = RotL64((aOrbiterD * 6925143692628659467U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15023513452326240962U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14965669361708810699U;
            aOrbiterJ = RotL64((aOrbiterJ * 587008860996713147U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7985755518735406360U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 225592097619240187U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2313509354133400439U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3659537916566939383U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17043668033610689611U;
            aOrbiterH = RotL64((aOrbiterH * 10797634709118100773U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10217321522161675848U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8013663869536146842U;
            aOrbiterC = RotL64((aOrbiterC * 2293233079384777175U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13762445330867496042U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2692400019659269106U;
            aOrbiterK = RotL64((aOrbiterK * 167704184292219399U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18232551682424867647U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14785847596876239854U;
            aOrbiterF = RotL64((aOrbiterF * 4569180925037758487U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5910282247522389536U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16556038638738871204U;
            aOrbiterA = RotL64((aOrbiterA * 18356922295088260901U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 141620663839815754U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2168513956284366370U;
            aOrbiterE = RotL64((aOrbiterE * 8605382725635471683U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 24U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterE, 43U)) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 53U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterI, 10U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterC, 37U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 60U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterA, 27U)) + aPhaseFWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 10U) + aOrbiterK) + RotL64(aOrbiterE, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneD
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24191U)) & S_BLOCK1], 38U) ^ RotL64(aSnowLaneB[((aIndex + 22803U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 27120U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27140U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24594U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 53U)) + 14499676118633326000U;
            aOrbiterA = (aWandererC + RotL64(aCross, 26U)) + 17191273593018552288U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 21U)) + 4085176294948097737U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 39U)) + 11112671474158908186U;
            aOrbiterB = (aWandererI + RotL64(aCross, 35U)) + 8745787969012266485U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 48U)) + 18074049663777707948U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 2543758649719164688U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 4659584749412700523U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 974639159259871273U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 37U)) + 9211220687971081987U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 57U)) + 8567024626862182714U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5803002132294840900U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11968489432878148467U;
            aOrbiterE = RotL64((aOrbiterE * 4501441062617123165U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9470807228394903442U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1692347973120388469U;
            aOrbiterB = RotL64((aOrbiterB * 17433393164156231575U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16510815732690193145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 755159406833096510U;
            aOrbiterG = RotL64((aOrbiterG * 14091736464659561165U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1518824876475937620U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 701225390867330446U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12264618860580199927U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8425976693733003889U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7182176375442410367U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8860605703761731859U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4546566785167467924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2593340999038753749U;
            aOrbiterD = RotL64((aOrbiterD * 10152461487764567563U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9756331608356622299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5511625814747641978U;
            aOrbiterH = RotL64((aOrbiterH * 4806076157539829529U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8694400787420160733U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12648969491371382682U;
            aOrbiterF = RotL64((aOrbiterF * 5346585704222643759U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15261238546696118531U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14236129054778329471U;
            aOrbiterK = RotL64((aOrbiterK * 11789581469516267749U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16251500056378064213U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 790320176607605195U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15706130623435648555U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17114773669444878655U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14499676118633326000U;
            aOrbiterA = RotL64((aOrbiterA * 8095707555083587081U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 41U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 11U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 4U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 48U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterF, 39U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 38U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29007U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 28270U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 31571U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29093U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 31679U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 12U) ^ RotL64(aCarry, 29U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 60U)) + 16183871922837164759U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 43U)) + 7002058258090219055U;
            aOrbiterF = (aWandererF + RotL64(aCross, 5U)) + 5650868611888303705U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 11899839660943876690U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 15349649504488111111U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 57U)) + 14060149569086744970U;
            aOrbiterK = (aWandererC + RotL64(aCross, 19U)) + 12920917574225030112U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 39U)) + 2831994965175330135U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 12U)) + RotL64(aCarry, 51U)) + 18312543585028439192U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 35U)) + 11657562205118394239U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 37U)) + 10850792819281246052U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17810371216216125323U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7963413941144223128U;
            aOrbiterF = RotL64((aOrbiterF * 534217972450595401U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5498715358793875584U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9256727548911651373U;
            aOrbiterJ = RotL64((aOrbiterJ * 10498848323914000989U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17246360111302191699U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18309978718113983369U;
            aOrbiterG = RotL64((aOrbiterG * 18267472694666221077U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3100998994319502921U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8129301860291235970U;
            aOrbiterK = RotL64((aOrbiterK * 17847033539279176187U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1889641029473279114U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16538494307002917945U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8081488217920885783U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5432230549146849322U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2634437941396090817U;
            aOrbiterC = RotL64((aOrbiterC * 7612999214758935211U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16940172599174185058U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13151669140593952203U;
            aOrbiterH = RotL64((aOrbiterH * 16225319638131723487U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3995064294869931681U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 913081077665768816U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9299514648768060453U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2469001696075411481U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2167390955194185443U;
            aOrbiterI = RotL64((aOrbiterI * 11805065572289005223U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1574066406534010796U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8736976961589874013U;
            aOrbiterA = RotL64((aOrbiterA * 5980070607180321955U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4233621443153132083U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16183871922837164759U;
            aOrbiterB = RotL64((aOrbiterB * 4030569514959370895U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 22U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterE, 50U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 19U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterG, 13U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 47U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterE, 53U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterC, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 56U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Boxing_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // ingress from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7510U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 6251U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 7233U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2180U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1654U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 6632U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aPrevious, 13U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererG + RotL64(aIngress, 47U)) + 4476099022490972343U;
            aOrbiterB = (aWandererI + RotL64(aCross, 37U)) + 16836423700375760429U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 8850577488928703557U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 7091631824560042743U) + aPhaseGOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aCross, 18U)) + RotL64(aCarry, 53U)) + 12560498899956759494U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7797973377112012161U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6173820673874805794U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15741300047917486527U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10805025132310245348U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7139216143268029968U;
            aOrbiterB = RotL64((aOrbiterB * 8349754682635765573U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 8241544862261635722U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4735527016563596150U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6621354217673598381U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5166171126690294033U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11117641762075368393U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4980156869201219393U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6312932356458415421U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1304139291184508668U;
            aOrbiterD = RotL64((aOrbiterD * 90744653170922319U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterD, 37U));
            aWandererG = aWandererG + ((((RotL64(aCross, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 48U) + aOrbiterD) + RotL64(aOrbiterJ, 46U));
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12754U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 11486U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 15167U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12404U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14578U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14988U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 34U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 43U)) + 12046647397183218524U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 2760779375026461991U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 13735454443176855650U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 4370377000586647724U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 4U)) + 14566322384189969094U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5056565959818422786U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8795403810686579209U;
            aOrbiterD = RotL64((aOrbiterD * 11205867337479457471U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9625947666256011567U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1703669290934254701U;
            aOrbiterA = RotL64((aOrbiterA * 5763881345676123583U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6664070663184147951U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2104148316797553431U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12887842067180975983U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 1197910004222596145U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9922977170060903197U;
            aOrbiterH = RotL64((aOrbiterH * 13047828062605568603U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2048376210852567829U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12568990647075931409U;
            aOrbiterB = RotL64((aOrbiterB * 9860242601194210927U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 40U)) + aOrbiterB) + aPhaseGWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterD, 27U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 51U)) + aOrbiterA) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24382U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 22382U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19741U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21042U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20323U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 21386U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 4U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 57U)) + 8685374557928800912U) + aPhaseGOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 3U)) + 3482312691892161229U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 43U)) + 6948130297389161165U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 5506385663788942690U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 46U)) + RotL64(aCarry, 11U)) + 17859982009307397161U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9178488809207094043U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1835479501226057169U;
            aOrbiterA = RotL64((aOrbiterA * 5671861318767342087U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5368101733632614939U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9050459666576835422U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10351719549990259551U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9042186993119635078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17528342580198295025U;
            aOrbiterD = RotL64((aOrbiterD * 14316671546614386775U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6495418332558436882U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8834495762667327342U;
            aOrbiterK = RotL64((aOrbiterK * 10783141541937645995U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4364314196965690905U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6357485231062120459U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 289429584586504995U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterK, 21U)) + aPhaseGWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 4U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aScatter, 26U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32142U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 28229U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32027U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25245U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27837U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 26450U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 58U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 17264605017518259932U) + aPhaseGOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 19U)) + 15209184354580778643U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 3299527965014731384U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aIngress, 29U)) + 16293096431816127821U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 37U)) + 11031983436878828337U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9188018632448236358U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13420816400363406556U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10958221259662190519U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2485063384097917101U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3089135816938128264U;
            aOrbiterD = RotL64((aOrbiterD * 8813152992957361153U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10730544971770435788U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 10431767565618874806U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4723078464590561545U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14883796491656899074U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13465877783538483706U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14311686051108108503U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13322163435314643713U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3307316600284371955U;
            aOrbiterF = RotL64((aOrbiterF * 12337846092069506365U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 56U)) + aOrbiterE) + aPhaseGWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterF, 13U)) + aPhaseGWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterE, 43U));
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Boxing_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3292U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 3283U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5046U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3832U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4809U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7645U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 18U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 47U)) + 77518479758428414U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 4832061802166300011U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 11695291171006574112U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aIngress, 28U)) + RotL64(aCarry, 57U)) + 7467412817843260094U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 5U)) + 17801484124471154757U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5555455638503958639U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5669470540733721606U;
            aOrbiterD = RotL64((aOrbiterD * 17219613748084498879U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3042388456327784163U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2236734925228156691U;
            aOrbiterI = RotL64((aOrbiterI * 10076582424701705531U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14459720401528685450U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4814967631216658856U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18288097536171386643U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16950679344449075945U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6262238639302011050U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9942659897425088183U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3522256359074996724U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12524717897707074242U;
            aOrbiterE = RotL64((aOrbiterE * 6787771338063891989U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 38U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterH, 27U));
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 51U)) + aPhaseHWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 38U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + aPhaseHWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11915U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 15120U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11664U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13984U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10029U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 10202U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 43U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 12775735908960052604U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 11791373812080296887U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 5537362877706057303U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 42U)) + 2023912048504189380U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aIngress, 3U)) + 17668828109963766893U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 558908629933941224U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1479633119685446888U;
            aOrbiterB = RotL64((aOrbiterB * 4447153373540811385U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15460320397843364063U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10059749397555469054U;
            aOrbiterD = RotL64((aOrbiterD * 8671817118586065469U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9987633811929693924U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 10087337844580228269U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13817142288940843815U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4446204415503364254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9430197906134676162U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1226048679997253363U;
            aOrbiterF = RotL64((aOrbiterF * 14247538885252664127U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterB, 20U)) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aScatter, 26U) + RotL64(aOrbiterD, 3U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterA, 41U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 53U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19864U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 17533U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16573U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23727U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16478U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 22667U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 18U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererK + RotL64(aCross, 27U)) + 2786079456995203065U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 7237256119153857253U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 19U)) + 9310834010563647604U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 17361734905706517877U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 56U)) + RotL64(aCarry, 37U)) + 15837111231884647451U) + aPhaseHOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18065431964418026445U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3029123922999952652U;
            aOrbiterE = RotL64((aOrbiterE * 16309219658285890145U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5166926595573507837U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1918425684273807598U;
            aOrbiterB = RotL64((aOrbiterB * 16616641579714896719U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4724551751012661440U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1818014487579644390U;
            aOrbiterK = RotL64((aOrbiterK * 14904092108647864911U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6670090372241084216U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 8485757110007268693U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11876760095108618363U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4928130251509514742U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2528788422725346792U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1855982047967756661U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 4U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 36U)) + aOrbiterH) + aPhaseHWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 24U) + aOrbiterE) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27798U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 26460U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 28856U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28758U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29562U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31680U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 50U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererC + RotL64(aPrevious, 58U)) + 4068921616130916949U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 12077715273915151726U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 3U)) + 16047546802670596833U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 9690277462716999763U) + aPhaseHOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 14484814700447992628U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 17089267243053958210U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9138746214446211147U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8244950097712975043U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10181001536979097045U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6657458969093373191U;
            aOrbiterG = RotL64((aOrbiterG * 4311019792293202747U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 7515983477876590988U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3039935555863947600U;
            aOrbiterD = RotL64((aOrbiterD * 12511160550780270119U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16209389224740851136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 725253312098083182U;
            aOrbiterC = RotL64((aOrbiterC * 17535989492095522597U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13307041115748941383U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7159572004825238263U;
            aOrbiterH = RotL64((aOrbiterH * 4855009895002398449U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 42U) + aOrbiterI) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 30U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 53U)) + aOrbiterI) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 20U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
