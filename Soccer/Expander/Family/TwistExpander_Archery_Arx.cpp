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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA8EB05C1565F8D53ULL + 0xAB10AC4AF3F9ED48ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA0856096596B8BE9ULL + 0xC8024AC386D723D6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8E3370F36E16B63DULL + 0x8AA9FAC53544451CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE6C1FD8EFDA54E31ULL + 0x83C550420DDCCB07ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB422D3DA2D7DC579ULL + 0xEA209773EDDB090CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEA2D61ABB6F2AC87ULL + 0xDEAC0F53EE862DD3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE7A23484D502702DULL + 0xAA8433873C59136FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB07F5D980010E229ULL + 0xE82000E40DA3440EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA4790D1BE5B62371ULL + 0x8C2842D936B5F844ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA46ED93273F539C3ULL + 0xDCB2B29ACEBEEE93ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x937E2EC0214B75D3ULL + 0xC650673B8CAFAE2DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x95140491733EEEADULL + 0xD172284996929F1DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAD11ADFD68CEFF85ULL + 0xE0E8A780F9F17D3EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFF314656EB23C631ULL + 0x8C55450AA65B1AD9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC9CFE9086AB77E55ULL + 0xB447D55658718078ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBB87107ABA0774FDULL + 0xBCB726F5CA267AEEULL);
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
            aIngress = RotL64(mSource[((aIndex + 5112U)) & S_BLOCK1], 20U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 509U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 3016U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3990U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 27U)) ^ (RotL64(aCross, 56U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = (aWandererB + RotL64(aPrevious, 23U)) + 898812731947995389U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 21U)) + 8677347622525527167U) + aNonceWordH;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 57U)) + 770321564027567654U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 5U)) + 11020474858081526395U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 43U)) + 17289793580414993470U) + aNonceWordG;
            aOrbiterI = ((aWandererG + RotL64(aCross, 39U)) + 10111912559295118444U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 53U)) + 8083622125544542011U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 11U)) + 7149858558922988240U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 30U)) + RotL64(aCarry, 21U)) + 5919683821379905699U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 19U)) + 6860902846079238714U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 15083517836867542075U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14852868368708376381U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9860233289028878323U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 13418143547952204667U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 772406119079116272U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7971141501337627589U;
            aOrbiterK = RotL64((aOrbiterK * 10168120622976358617U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8478568022896691911U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4027604850785607101U;
            aOrbiterF = RotL64((aOrbiterF * 4826627523578901467U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17199331557841535430U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7515957656979776361U;
            aOrbiterD = RotL64((aOrbiterD * 5468950152869656599U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17138249294921502391U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16236812863923234668U;
            aOrbiterH = RotL64((aOrbiterH * 2925542836624164807U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 16941524155859123682U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 11240343728857342866U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 7281012444214294659U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15163914964139858328U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6673576554415729652U;
            aOrbiterC = RotL64((aOrbiterC * 1558880328574736975U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5399050402101642989U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11806006719060024615U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15782156615926092159U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9812148913932011655U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4737919734590584193U;
            aOrbiterG = RotL64((aOrbiterG * 2739737604370936959U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3415477403346468057U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5922725868927615919U;
            aOrbiterB = RotL64((aOrbiterB * 12390148483052777871U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17435294951520465659U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 898812731947995389U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 17248379279729365007U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + aNonceWordF);
            aWandererB = aWandererB + (((((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 18U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 23U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterB, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 38U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 35U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 48U) + aOrbiterD) + RotL64(aOrbiterG, 47U));
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 7113U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9097U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7816U)) & S_BLOCK1], 47U) ^ RotL64(pSnow[((aIndex + 10036U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 56U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (aWandererE + RotL64(aPrevious, 47U)) + 17019646486641172469U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 36U)) + 12276141179299971572U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 3617241694029841555U;
            aOrbiterE = (aWandererC + RotL64(aCross, 21U)) + 6967963401259371737U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 5U)) + 6340709284279891017U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 41U)) + 456065368903896482U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aWandererD + RotL64(aCross, 58U)) + RotL64(aCarry, 5U)) + 17686765719908116203U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 53U)) + 1322045955429785736U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 3U)) + 5163772703302372887U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 13268431135020363252U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 11U)) + 6538789950366849332U) + aNonceWordF;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10390344544314544893U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5087084271300584267U;
            aOrbiterF = RotL64((aOrbiterF * 15149302947570776165U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13423071121590981727U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18324443012024134729U;
            aOrbiterH = RotL64((aOrbiterH * 15814349432207734533U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4129091815978464507U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17024797553831962245U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 3137753479364378175U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6501545108779991661U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11930037791867597447U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4904739567549702851U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4667298703308315851U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6315980380900062127U;
            aOrbiterJ = RotL64((aOrbiterJ * 12080555704907924637U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12732382340390769888U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7792095326183864547U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12645556660611824631U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17428384983571405782U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3193205313177048443U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 14488006565106259731U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2813743367131107264U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2742138679703780981U;
            aOrbiterG = RotL64((aOrbiterG * 18356569025783532225U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6270291142961043031U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3490174937775044998U;
            aOrbiterB = RotL64((aOrbiterB * 13879285210885619613U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13182535825771438942U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13047228760732694484U;
            aOrbiterE = RotL64((aOrbiterE * 10365428317468779549U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17926326514553542739U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17019646486641172469U;
            aOrbiterI = RotL64((aOrbiterI * 13978838314848228053U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 54U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterC, 11U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 43U)) + aOrbiterA) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + aNonceWordG);
            aWandererD = aWandererD + (((RotL64(aCross, 18U) + RotL64(aOrbiterD, 41U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 30U));
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterE, 21U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 50U) + aOrbiterB) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 12427U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15589U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 15646U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 11152U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 52U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 3U)) + 12632404972795375757U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 42U)) + 5351879979055988456U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 11U)) + 3597737727467443413U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 2830846754917852318U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 57U)) + 17311925960294518018U) + aNonceWordG;
            aOrbiterF = ((aWandererC + RotL64(aCross, 21U)) + 2083584640523695383U) + aNonceWordC;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 60U)) + 15049343611387010158U) + aNonceWordF;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 6443050378205811147U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 51U)) + 6021965178697344070U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 5080289878758029976U) + aNonceWordM;
            aOrbiterE = (aWandererE + RotL64(aCross, 37U)) + 576927745306972983U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 4728489691382690859U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6184355840165758855U;
            aOrbiterJ = RotL64((aOrbiterJ * 1515043910404156423U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11220539885798595450U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11091438724966718214U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 8225347114759391961U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17184210490020062419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2150997767099116408U;
            aOrbiterG = RotL64((aOrbiterG * 8058553821648892499U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 7021953562676903717U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17159676348343312834U;
            aOrbiterC = RotL64((aOrbiterC * 13877284519668483549U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10367891770525239784U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11922478487264201233U;
            aOrbiterI = RotL64((aOrbiterI * 9195137452661956029U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17815162358981720634U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 9582631251085100284U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11838992994130850483U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 872593750259572264U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17832330100262167302U;
            aOrbiterF = RotL64((aOrbiterF * 1114416841510028467U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16601139856969287418U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14931287111691324985U;
            aOrbiterE = RotL64((aOrbiterE * 16757174577841001179U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11413072442039115924U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15253605470589905889U;
            aOrbiterH = RotL64((aOrbiterH * 10832817442285245673U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3653487723581514107U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14891378240114471865U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 1386594204573386051U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15659724464711852035U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12632404972795375757U;
            aOrbiterA = RotL64((aOrbiterA * 2407347385127296647U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 14U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterH, 53U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterD, 11U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + aNonceWordK);
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterD, 41U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterF, 48U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 23U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterD, 29U));
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererI, 6U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 18387U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20561U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 18367U)) & S_BLOCK1], 22U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 21573U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17213U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 56U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (aWandererI + RotL64(aPrevious, 27U)) + 3255291173184001106U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 21U)) + 15308468160116255528U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 30U)) + 18186972408589866656U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 3U)) + 4439324265978331914U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 13099263173016322486U) + aNonceWordJ;
            aOrbiterE = ((aWandererD + RotL64(aCross, 41U)) + 7041561081767500660U) + aNonceWordO;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 48U)) + RotL64(aCarry, 53U)) + 6196422612687812971U) + aNonceWordF;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 13U)) + 7664260932541281413U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 57U)) + 17802347823020441056U;
            aOrbiterC = (aWandererC + RotL64(aCross, 35U)) + 4253107484061190446U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 13799496534030645312U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14252892847595951926U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5663527578664291422U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 18314294235895182465U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 11148755959699137661U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17036900929333594592U;
            aOrbiterG = RotL64((aOrbiterG * 16041243617369003291U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2403828181385259549U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17813580350434928194U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 13666780980793857831U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5623611126885414523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7293224381174846969U;
            aOrbiterA = RotL64((aOrbiterA * 7032561584670788117U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10602620906929686163U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 18015916257203385982U;
            aOrbiterD = RotL64((aOrbiterD * 10684090189688871993U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13592915735376305773U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 13995866908043417505U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 3802175869395887331U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8200465989447697618U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9866671660800629464U;
            aOrbiterE = RotL64((aOrbiterE * 2138851839905326265U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11557528777230608777U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 131060617338185060U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11068705423012265209U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13404720733342982167U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13128574378042136042U;
            aOrbiterI = RotL64((aOrbiterI * 5805270317312187011U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15879295432652112238U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9433361543323748909U;
            aOrbiterK = RotL64((aOrbiterK * 3592390041363796221U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6262775775981534941U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3255291173184001106U;
            aOrbiterJ = RotL64((aOrbiterJ * 2748492753337241005U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 46U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + aNonceWordB);
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 5U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterH, 34U)) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 11U)) + aOrbiterB) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 44U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 19U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 56U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 37U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 52U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 22513U)) & S_BLOCK1], 60U) ^ RotL64(mSource[((aIndex + 23771U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(pSnow[((aIndex + 21914U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 22853U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26630U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 26224U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 13U)) ^ (RotL64(aPrevious, 26U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = (aWandererB + RotL64(aScatter, 28U)) + 5171470532667965920U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 53U)) + 750549462358682403U) + aNonceWordK;
            aOrbiterK = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 3325689257577120525U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 57U)) + 18031575461559790826U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 11U)) + 13874739537012288677U) + aNonceWordB;
            aOrbiterE = (aWandererA + RotL64(aIngress, 39U)) + 4250029868785016865U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 8211158803112611161U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 46U)) + RotL64(aCarry, 3U)) + 1083939790236786027U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 5U)) + 3446525462376962464U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 51U)) + 6973817815000417325U) + aNonceWordG;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 37U)) + 15230876489676945543U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9359727659738755880U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8775170107816327654U;
            aOrbiterK = RotL64((aOrbiterK * 6910680458261008653U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11958941755525038545U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16966819714283167348U;
            aOrbiterJ = RotL64((aOrbiterJ * 16363457661846050749U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14556087985619763243U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17915047508377045221U;
            aOrbiterA = RotL64((aOrbiterA * 6727635453185130109U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8578745677485367222U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7002181668717618866U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 12329703532414955235U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3569939503066735457U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2956247934282522184U;
            aOrbiterB = RotL64((aOrbiterB * 9946650822131152531U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4285180013402474041U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5976239869535619811U;
            aOrbiterI = RotL64((aOrbiterI * 3458095419039067465U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2424524955161695463U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6849595426583763537U;
            aOrbiterH = RotL64((aOrbiterH * 12727902040238318101U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 11414890686374886716U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5668287266836153445U;
            aOrbiterG = RotL64((aOrbiterG * 8011885266143066285U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9976985606260445887U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9223940029500676834U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8508023992488499955U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4480967907876921958U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5132766654502526597U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 321625389942019245U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12921555132452983464U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5171470532667965920U;
            aOrbiterF = RotL64((aOrbiterF * 9710487797420618879U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterB, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 48U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 19U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterA, 58U)) + aOrbiterD) + aNonceWordH);
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterA, 21U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterC, 39U)) + aNonceWordP) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererH, 4U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 32022U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((aIndex + 30296U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28740U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29453U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28267U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 31867U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 16802219662864902427U) + aNonceWordF;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 10U)) + 14332033461409490629U) + aNonceWordN;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 43U)) + 8781794298640286845U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 8459933908074937264U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 1883580287986004426U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 5U)) + 17500258188004626118U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 3U)) + 7934811305150872870U;
            aOrbiterH = (aWandererF + RotL64(aCross, 37U)) + 6380363892361098905U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 53U)) + 12623079132626676910U) + aNonceWordI;
            aOrbiterI = ((aWandererD + RotL64(aCross, 29U)) + 10455208121949202703U) + aNonceWordD;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 56U)) + 8805532707916767629U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9161544391400377699U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3501434325829663268U;
            aOrbiterJ = RotL64((aOrbiterJ * 7933545151293799637U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 651783304096081996U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 441505031509930622U;
            aOrbiterB = RotL64((aOrbiterB * 8045355432310956143U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1771159983581326424U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15227946417377695989U;
            aOrbiterH = RotL64((aOrbiterH * 1563141188972797601U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4153717524193279095U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4404521756523902829U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 1410342912973206203U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6231945075461813285U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3864780227164426690U;
            aOrbiterC = RotL64((aOrbiterC * 18031353247480673617U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1509699687948576558U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17316114302489411191U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 15490661284980281585U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2250572827340157410U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6403966113144372915U;
            aOrbiterA = RotL64((aOrbiterA * 726441947009132383U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2329903609147403156U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2486330017319455238U;
            aOrbiterK = RotL64((aOrbiterK * 17427461345935191757U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9333421733051210144U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14779925626161889533U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9120486933147706541U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4343688173541745311U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12686722305368397686U;
            aOrbiterD = RotL64((aOrbiterD * 17484250022537912537U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3745163111502795473U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16802219662864902427U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4343730534036919417U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 4U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterF, 39U)) + aNonceWordO) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterD, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterH, 27U));
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + aNonceWordC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterA, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterE, 13U));
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 21U)) + aOrbiterB) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 24U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 54U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCCC46239A9B7F7F3ULL + 0x96E0AFFC08E3B996ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCE8E37D6A94ED70DULL + 0x85BC9A00485F44BAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9A158CBDB864DABDULL + 0xDD2E238C1A82E431ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB85D8D783DBA9F77ULL + 0x8F92881167ED09DCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD4551690035958A7ULL + 0xB6E651EDB0EF0D79ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8B09856B476969C3ULL + 0xBB2E5C5B016A936BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCF8F6A52BD617C7BULL + 0x84652B864826C0AAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCF24AA3CDADF05A3ULL + 0x92B534660216A532ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB121639AB53B591BULL + 0xB96ED636304FEA42ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA77DD1980CCB53F9ULL + 0xB8C22F2BD8E60B21ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xABCAEA76049E4DF3ULL + 0x835455DAA1BD9C7DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD142B72CDEE1B213ULL + 0xBE359395C32EA562ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x814B15D8B26A0829ULL + 0x818425B24C5264E4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF54ADCA8F9163485ULL + 0xBDE4FDC6EBD8206AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x833DE7AA2DD3C757ULL + 0x8FEEA6784DAA5EAEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA649005742E0FEF5ULL + 0xF6351502B5D488E0ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3969U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2318U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1252U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4187U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 13278949403988203974U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 9213599924054673756U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 18U)) + RotL64(aCarry, 43U)) + 1255746482932381798U) + aNonceWordE;
            aOrbiterA = (aWandererH + RotL64(aIngress, 23U)) + 11575321997144516122U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 11U)) + 15881587525529432437U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aWandererA + RotL64(aScatter, 5U)) + 9846195809864862707U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 53U)) + 12319815691858217670U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 47U)) + 16322617427294439587U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 58U)) + 16332130810525887437U) + aNonceWordB;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4920951156015336794U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16767126455124552329U;
            aOrbiterD = RotL64((aOrbiterD * 4440352337076842603U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12553595911087945223U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1437522202135436142U;
            aOrbiterH = RotL64((aOrbiterH * 2001992794165550905U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12313100454852227143U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2761983020631055729U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3874839760378039509U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17635303588421554367U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 788212489507463763U;
            aOrbiterI = RotL64((aOrbiterI * 17896475584538528059U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5192552894670654434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6784748488807738811U;
            aOrbiterE = RotL64((aOrbiterE * 8077237651953896479U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 16113417046719114943U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1096874945215225916U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17308604412622879833U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7610274704570171595U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10466070212284342550U;
            aOrbiterG = RotL64((aOrbiterG * 6449728258497920613U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6777845928873855221U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5251515022021984126U;
            aOrbiterB = RotL64((aOrbiterB * 9018277343404261611U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13849343158824111498U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7977711210181714021U;
            aOrbiterC = RotL64((aOrbiterC * 4182053966171053577U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 28U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 56U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterE, 28U));
            aWandererK = aWandererK + ((((RotL64(aCross, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 39U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aScatter, 46U) + RotL64(aOrbiterD, 51U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + aNonceWordG) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 20U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 23U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13801U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 11512U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11046U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10396U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneD[((aIndex + 16010U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 38U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 12122689833405846292U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 24U)) + 9640400270962766788U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 9141937998266739071U) + aNonceWordC;
            aOrbiterI = (aWandererG + RotL64(aScatter, 43U)) + 12899395770434090537U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 53U)) + 13457918115408031842U) + aNonceWordN;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 15134784483576000943U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 48U)) + 12540961268790055438U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 13U)) + 6306886773092764230U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 3U)) + 13573343491337243121U) + aNonceWordP;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8545588657348974413U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10891410570357275120U;
            aOrbiterB = RotL64((aOrbiterB * 5399310978367842841U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2877137119767060151U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9178097682386595144U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3524486002084427513U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15528007881855616978U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11368419529245281435U;
            aOrbiterJ = RotL64((aOrbiterJ * 12433207037378339309U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5932738914934356645U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5551842263864055419U;
            aOrbiterE = RotL64((aOrbiterE * 16093776759971522681U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3824433359595690603U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17184628855571662441U;
            aOrbiterH = RotL64((aOrbiterH * 691208053136187317U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 8724462245014132623U) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7481349499528092352U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8212182934509617583U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6908362960248294718U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5354057969992655314U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16586084885820679343U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11138301629323903147U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14164180536320940750U;
            aOrbiterI = RotL64((aOrbiterI * 9099767681053390287U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 709942920176922902U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17128241237359414945U;
            aOrbiterK = RotL64((aOrbiterK * 14063385518459963529U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 54U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aScatter, 6U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 10U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterF, 35U)) + aNonceWordL);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterG, 14U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 21U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 44U) + aOrbiterA) + RotL64(aOrbiterF, 43U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19036U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((aIndex + 23593U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 23886U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21589U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22635U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 17834U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 19U) + RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 5U)) + 14823268998003220191U) + aNonceWordO;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 52U)) + 15295237288788213847U) + aNonceWordK;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 41U)) + 16434853402001133899U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 35U)) + 7555911304407871631U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 14977248264994834620U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 47U)) + 9707764144919392380U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 1277304385464681529U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 3089786220465849395U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 30U)) + 3700503853358695085U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3240054112993517371U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16897532076915366859U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4120874717534309035U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18167359289798364307U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8870819278575769863U;
            aOrbiterA = RotL64((aOrbiterA * 9334066154398059075U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15363069206212330251U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14858164441499725158U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14931933411393847915U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5357144808788707522U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2910681277417754860U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 13170868582159347059U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9824408699018165151U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 368370224788793300U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 14358982366258729959U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7095398304588825115U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11418879758164313554U;
            aOrbiterK = RotL64((aOrbiterK * 5983520332639771791U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2171599720681913272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17593730219647495033U;
            aOrbiterE = RotL64((aOrbiterE * 12926053208918563087U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17755947635188715523U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 14565740605227022106U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 15866418354612945335U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14538017880915584414U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6174566474851449123U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 179569008593475683U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 56U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 34U) + aOrbiterK) + RotL64(aOrbiterF, 44U));
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterC, 35U));
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterF, 4U)) + aNonceWordI) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 53U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30658U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((aIndex + 27941U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 26538U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25140U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27049U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 29532U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 43U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 2783898056762489197U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 34U)) + RotL64(aCarry, 37U)) + 7177192902873343053U) + aNonceWordE;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 12254703232691980774U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 43U)) + 15446547245691219559U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aWandererH + RotL64(aIngress, 51U)) + 888475203006174856U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 18U)) + 3649183529366307877U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 57U)) + 4642631047518805167U) + aNonceWordH;
            aOrbiterG = ((aWandererD + RotL64(aCross, 29U)) + 6108329730724782250U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 23U)) + 8334054653023816636U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5891895375031474350U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3176720746238477862U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 1869961473768307911U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6111038696865301675U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11914998302228682704U;
            aOrbiterH = RotL64((aOrbiterH * 11738924766359642853U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17005063057791320948U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 18333780598768130670U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 5416759844884107303U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2056115016443263153U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10245512728872962677U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 707106795383284903U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4810366069422162351U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3051442983125942469U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13558537578054436423U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9285068547223654308U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13067251130180968842U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 7000687697769766605U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3203670242792002165U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1770881716916463461U;
            aOrbiterA = RotL64((aOrbiterA * 13870229847371882171U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16286823712870537410U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13067191141829694202U;
            aOrbiterG = RotL64((aOrbiterG * 15629974528467350445U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3414576315085336932U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8979691827341555245U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15971594804040295757U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 50U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 23U)) + aOrbiterI) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 18U) + aOrbiterA) + RotL64(aOrbiterF, 56U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterI) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aScatter, 14U) + aOrbiterF) + RotL64(aOrbiterJ, 18U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x81AA98DEFA626069ULL + 0xF29F04EAF7B72250ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC9E39D432246BA59ULL + 0x936BEB12CA5829FDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCCACB120AEADAFBFULL + 0xD3250F1AA603D0C3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB89D8CBA675B3C6FULL + 0xFD202493E793B9BDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE6D8903F6DE4B4ABULL + 0xDC2A0DE0DDABB900ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEDDF7924D55BD0B9ULL + 0x9F3D16B37BDCA962ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x81B90E1026741C79ULL + 0x9A82AA34F0163758ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9D631778EE604C17ULL + 0x8A0A7C3E91F595D3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFB1AEC204B366821ULL + 0xB2D9CE6541933F51ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF8D5BDFD6487AA2FULL + 0x819B46A21872264DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9A920B68F6C26991ULL + 0xBB4770B19F40FA23ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBF6925FF7DC2050FULL + 0xD327214A3B615F50ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA5473371416B89E9ULL + 0x954BA61AAEA8CAFEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC5D708F9C94CD49BULL + 0xF355A5B6D75DDE28ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB68DAC34EF7AB169ULL + 0x8529974ACB57AF26ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF779540258387513ULL + 0xBD53D50CBE331871ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneB, aWorkLaneB, aFireLaneD, aWorkLaneC, aFireLaneA
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1907U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 6675U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 6328U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5272U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7362U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 37U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 57U)) + 2330952702412094686U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 23U)) + 7820188225935060799U) + aNonceWordB;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 48U)) + RotL64(aCarry, 41U)) + 9347644591709839145U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 2288624878446846870U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 9358977729492824128U) + aNonceWordL;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1858511275052455039U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13715478509322292552U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15552121744869003235U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 16413396625604260455U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 17714322215518432705U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 1904184102419934333U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16188315436202861122U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5564445841368207813U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14125834616162835983U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13717068949900594673U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14143659432287313765U;
            aOrbiterF = RotL64((aOrbiterF * 17281441046722262917U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5729546141908425670U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4297827922736712074U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 13631630436759768885U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 58U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 3U)) + aOrbiterA) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aScatter, 12U) + aOrbiterI) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 53U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterA, 44U)) + aNonceWordC) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9301U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 14423U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13256U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9164U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13556U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 8223U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 36U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 10404808878585437255U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 20U)) + RotL64(aCarry, 53U)) + 10587858736301591439U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 11U)) + 1430530909801644435U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 9090938022430118902U) + aNonceWordP;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 57U)) + 12936604311751121235U) + aOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1000583006020232032U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12352532088997042232U;
            aOrbiterA = RotL64((aOrbiterA * 494418029883239087U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16723410947058502564U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16614089235313154270U;
            aOrbiterK = RotL64((aOrbiterK * 11530998303573027827U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4245553025593349277U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3353146318549477494U;
            aOrbiterI = RotL64((aOrbiterI * 14246377408238318091U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 5935727336135635196U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10312187090293319667U;
            aOrbiterH = RotL64((aOrbiterH * 1395964500396711899U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 12192843181244744484U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2542570124502586365U;
            aOrbiterC = RotL64((aOrbiterC * 17222847847573534963U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aIngress, 40U) + aOrbiterC) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 39U)) + aNonceWordM) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 37U)) + aOrbiterI) + aNonceWordI);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 57U)) + aNonceWordL) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + aNonceWordG);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24280U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 20978U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 21249U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17964U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24558U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22537U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 3236820517816085022U;
            aOrbiterD = ((((aWandererC + RotL64(aCross, 20U)) + RotL64(aCarry, 23U)) + 741288875914097926U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 8417246926007729580U) + aNonceWordK;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 51U)) + 9715717805774537170U) + aNonceWordD;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 29U)) + 14360243844821619482U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10760908100206775334U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3434641779946167811U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3305698324169010803U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7885568822756234567U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3041563437672051294U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11440300917533482297U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15761355327564963516U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1158633562785937421U;
            aOrbiterH = RotL64((aOrbiterH * 15511324886867188235U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9338581575871970653U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9172038894262857354U;
            aOrbiterJ = RotL64((aOrbiterJ * 3110871165285625807U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14653924713599790081U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3854497592598563309U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11737111068815795303U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + aNonceWordN);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterB, 20U)) + RotL64(aCarry, 41U)) + aNonceWordP) + aWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27647U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 27024U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27905U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30677U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27675U)) & S_BLOCK1], 60U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31806U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 27191U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 28U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 23U)) + 6243113109470883144U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((((aWandererJ + RotL64(aScatter, 14U)) + RotL64(aCarry, 43U)) + 3891552123999605832U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aWandererK + RotL64(aIngress, 5U)) + 8758797898587019128U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 1005891374086408851U) + aNonceWordA;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 3713426782180050764U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 18358143862391573534U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 17504394029693712404U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 3391716204095092531U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5312729289027417014U) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2560873623431186029U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16843728573219210173U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16309322822806704211U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10195513918020652600U;
            aOrbiterE = RotL64((aOrbiterE * 14569219741824123715U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 2552116263258744287U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7732784879810980089U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 15041929399477790999U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16499127570665381507U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 10890036715535519036U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 9065115450010475187U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 58U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterI, 6U)) + aNonceWordE) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB6DCB6CFADA89DF5ULL + 0xD806FE954C2429D4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9551522CFBFC1E81ULL + 0xCA6813CF902EEE1DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC120A4F6597F4FF5ULL + 0xA5E27052A4F6F198ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBA0CCE4FF382D833ULL + 0x98ED440F171F9DB8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF77408F214F86F55ULL + 0xAB26291AF8E98660ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBF7D370E409F26BBULL + 0xF90140824CF62491ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD50F82F61B91C7CFULL + 0xC6331ABA54143EBEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9D178BFC895728CBULL + 0xC78332FEA3543E4EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA46B7F86572B99C3ULL + 0x8EAB73D9F81FD5F0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8E39F6D7A0893C03ULL + 0xEA2B7507B2705D93ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8934BDD3B2AB1F85ULL + 0x86973FC7B7B3EE17ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x859CAB8026C83B07ULL + 0xF4C68FD1D68A1834ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFF35C919CB53EEF9ULL + 0xEDD9A217F5093E18ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC86322D3EBDF0F59ULL + 0xEE410B8677AF0482ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x81491F9F9E0AA6E3ULL + 0xAC178EF9F0B721DCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8A0ED9B4B662357FULL + 0xB3B871795AA48573ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneB, aExpandLaneC, aExpandLaneD, aFireLaneA, aWorkLaneA, aOperationLaneC, aOperationLaneA, aWorkLaneB, aOperationLaneD, aFireLaneD, aWorkLaneC, aFireLaneC, aFireLaneB
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8028U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 1605U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3502U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2519U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6976U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 4354U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 34U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 6361545377408870615U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 5U)) + 2967245486744774933U) + aNonceWordE;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 3836634268482850139U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 14U)) + RotL64(aCarry, 3U)) + 7691642115360086297U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 57U)) + 16479280384178279281U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 41U)) + 2901468732552539249U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 47U)) + 2600353867755647475U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5666596904781510956U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16108791609267427553U;
            aOrbiterI = RotL64((aOrbiterI * 8904649663479834199U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8389926875737312112U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1689501721163024426U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 6517194895779049139U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11721701506949917719U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3963842745030140473U;
            aOrbiterC = RotL64((aOrbiterC * 6692473494944919373U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8510538243472109368U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18281865214102080387U;
            aOrbiterD = RotL64((aOrbiterD * 1351546966368884609U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2259725140963665123U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11652011949557979650U;
            aOrbiterB = RotL64((aOrbiterB * 11260100762113295037U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1116085424226174473U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4725260319270802912U;
            aOrbiterH = RotL64((aOrbiterH * 4697109059565450269U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7348945429843437036U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1249234309180653260U;
            aOrbiterJ = RotL64((aOrbiterJ * 3136745255820405881U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 12U) + aOrbiterJ) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 28U)) + aOrbiterJ) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 43U)) + aOrbiterK) + aNonceWordA);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 11U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterB);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 57U)) + aNonceWordL) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15219U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 11769U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 12240U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15290U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16361U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8419U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 22U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 13650869943246163567U) + aNonceWordP;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 38U)) + 3435284932011770999U) + aNonceWordE;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 13U)) + 12388155658186776579U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 5U)) + 2374345913955712039U;
            aOrbiterB = ((((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 6095094526980292156U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 4965147025852444174U) + aNonceWordK;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 47U)) + 3261881216269075298U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4939780217097329222U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3019862009792676287U;
            aOrbiterE = RotL64((aOrbiterE * 2452316208025448747U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 901910626217143974U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3647055146712366383U;
            aOrbiterH = RotL64((aOrbiterH * 1792602402476450009U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7731765438957392967U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13409819457393479741U;
            aOrbiterJ = RotL64((aOrbiterJ * 3345078200262410715U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5415832109107794258U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8876738832313114471U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 1304277600444504135U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 17135570542519390359U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2373193062766802082U;
            aOrbiterA = RotL64((aOrbiterA * 4213691513185791519U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16318403285501718552U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 8456043288604687045U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 10556964529144571683U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10572534930284516528U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14616251186735204677U;
            aOrbiterD = RotL64((aOrbiterD * 2048651204265459805U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterB, 13U)) + aOrbiterK) + aNonceWordM);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 41U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 22U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneD
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22219U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((aIndex + 23801U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 17200U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24329U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24210U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 22138U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 1393781663398437180U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 17414594746688585273U) + aNonceWordI;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 5U)) + 2823888497053071250U) + aNonceWordM;
            aOrbiterI = ((((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 17032631958617884859U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 47U)) + 15222697630461125019U) + aNonceWordE;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 13U)) + 15737414920751551780U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 38U)) + 1357196111055783001U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5315122321649251691U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7893744655508595974U;
            aOrbiterJ = RotL64((aOrbiterJ * 17863000246694319149U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16721939414324611738U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3444375866323610848U;
            aOrbiterI = RotL64((aOrbiterI * 10874157227815775661U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1825716513674511632U) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 15582066843912467318U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12765146555943757373U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15673590949193923915U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13887365046280406413U;
            aOrbiterF = RotL64((aOrbiterF * 3169061375011420121U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12730414371734709356U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 4819112390640821927U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 8782547948627685451U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 3089925954422937464U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7180179304678622530U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16118051565147747413U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17030269962085008657U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6675917351883004046U;
            aOrbiterG = RotL64((aOrbiterG * 14134335325316949687U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + aNonceWordJ);
            aWandererG = aWandererG + ((RotL64(aCross, 42U) + RotL64(aOrbiterE, 5U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 19U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 60U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneB
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26436U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 27442U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29763U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26262U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26552U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 26314U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aIngress, 23U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 37U)) + 18144572925667544139U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 5659758077574059728U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 54U)) + 6343330616999166392U) + aNonceWordF;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 17754639838410839447U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 9451843819849581729U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 23U)) + 7957854457197462212U) + aNonceWordH;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 3U)) + 1461994799722205010U) + aNonceWordO;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18002214276252170177U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14689869073147027164U;
            aOrbiterG = RotL64((aOrbiterG * 12242482963989582191U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3978104368003440293U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8512135845221335386U;
            aOrbiterA = RotL64((aOrbiterA * 10506667163729414667U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1477533446382953439U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2166717790929947990U;
            aOrbiterB = RotL64((aOrbiterB * 6538884492418324461U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 8082437060686606995U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4363687722464700362U;
            aOrbiterE = RotL64((aOrbiterE * 7199165810993478887U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15782763348014924206U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8572509150015960728U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3340528604891897779U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12248271773316742521U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9602078627638561949U;
            aOrbiterI = RotL64((aOrbiterI * 1860631869877427405U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17244849374768558859U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1030743048280579012U;
            aOrbiterF = RotL64((aOrbiterF * 10858949914285817051U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterD, 58U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 41U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 19U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 13U)) + aOrbiterB) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aCross, 51U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterE) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEA9F99CE73E71E35ULL + 0x9ECED40235C02BB9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB92ED9AEBA4EA273ULL + 0xC73EE1C610287A39ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBD3A1B08A890F8FFULL + 0xF6BBB0A37E4741C1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC496BE6CDA26F841ULL + 0x97554DE87C959456ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8CDD6DAD4675E10FULL + 0xD297A240E555FE12ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x83E5C5948C332B53ULL + 0xBDA4B7DF9A17FFEAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB82340C0F97F2F05ULL + 0xD47E90C623C36AEDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA823CBEB91C338EFULL + 0xEFCBFCC39A96C6D6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE768A40DAEBE5C6FULL + 0x8381852A5A73A916ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC8EA87F8F235DE47ULL + 0x9BBF010455C07381ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x909F82932B3D2A33ULL + 0xED7B931B67C9597DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFA6D1D772D51CBB3ULL + 0xCE5CB92990AAC841ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEE50993ECCAAF423ULL + 0xCAC73DCEA0D5078DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE145FCFB0ED0702DULL + 0xB099B8FD77249E9FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB51A270AC2EA6825ULL + 0xD55C3B993A2AA9B3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEBC441DD35E34793ULL + 0xF0260043D70899ABULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aFireLaneC, aExpandLaneA, aFireLaneD, aOperationLaneA, aExpandLaneB, aFireLaneB, aFireLaneA, aExpandLaneC, aOperationLaneB, aOperationLaneD
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4438U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 135U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 4776U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 77U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6317U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 374U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (aWandererD + RotL64(aPrevious, 27U)) + 5173905450211892891U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 56U)) + RotL64(aCarry, 57U)) + 3555542451908039957U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 11559884700283861559U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 41U)) + 1352524329968738673U) + aNonceWordK;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 8914206450420616349U) + aNonceWordA;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 19U)) + 2251523378498463946U) + aNonceWordF;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 5U)) + 9541575923299247038U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1239854507907214595U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17698101462598498934U;
            aOrbiterA = RotL64((aOrbiterA * 2304948713665996433U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12305566971683256060U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13804545036303215569U;
            aOrbiterJ = RotL64((aOrbiterJ * 10359543704152744971U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10239749097704329264U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4212214906286320308U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3661436621615751071U), 23U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 12192418916967430783U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4475514289326450361U;
            aOrbiterG = RotL64((aOrbiterG * 17497164630368757887U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 17376102613298827459U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 18129393209955439341U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 6404089025014118979U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4014763724300253568U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 17325007199676828814U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 1420888274815627083U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15480474849292388685U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14357924730184375449U;
            aOrbiterB = RotL64((aOrbiterB * 16723492259068034209U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterB, 11U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ);
            aWandererG = aWandererG + (((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 5U)) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 56U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 47U)) + aOrbiterE) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 19U)) + aOrbiterG) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 38U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11471U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((aIndex + 14436U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 15063U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10749U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11329U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16017U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 22U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 11698283336767769359U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 13297826354831483872U) + aNonceWordA;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 39U)) + 15254999058287530795U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 41U)) + 17474166585085346567U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 47U)) + 15684783498452840289U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 23U)) + 5061229733465216486U) + aNonceWordJ;
            aOrbiterG = ((aWandererD + RotL64(aCross, 29U)) + 15370981279168377944U) + aNonceWordC;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 17966672773619554092U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14685092893994491068U;
            aOrbiterH = RotL64((aOrbiterH * 1627758964162892429U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12798804186209406389U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2848444181474221574U;
            aOrbiterC = RotL64((aOrbiterC * 13730480364920876877U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 8551142075919636146U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8833198159158950723U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 7650289040764974737U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7351473160893666232U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14204899612487622222U;
            aOrbiterK = RotL64((aOrbiterK * 6317485031956448029U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7008985178526543258U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13576796403863120356U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13745839827679114077U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5769784656937900699U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14075925808204936705U;
            aOrbiterA = RotL64((aOrbiterA * 5844894088757604713U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17818667502858010896U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16016922065572683130U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7525645833898085373U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 57U)) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterG, 51U));
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterH, 34U)) + aOrbiterG) + aNonceWordP);
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 11U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 14U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21399U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneD[((aIndex + 21528U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 19242U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18546U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17771U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 21943U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 14214886793361825363U) + aNonceWordG;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 21U)) + 17267959031078766320U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 41U)) + 16436067429484887644U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 9885951769332633820U;
            aOrbiterA = (aWandererH + RotL64(aCross, 12U)) + 12971711341813893304U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 29U)) + 199970353398450154U) + aNonceWordD;
            aOrbiterJ = ((((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 1237341696444162094U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 7991128854417613360U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14809029847149045833U;
            aOrbiterK = RotL64((aOrbiterK * 5940857360838299105U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2559509556915775947U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14336829730147834160U;
            aOrbiterF = RotL64((aOrbiterF * 15103242520064900873U), 21U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 8853631886733610440U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13346159398673246914U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13660497151446983393U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12121095718571872976U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16239781125815589804U;
            aOrbiterB = RotL64((aOrbiterB * 5157009090454962231U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9051377033794324106U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13805815136723461780U;
            aOrbiterJ = RotL64((aOrbiterJ * 571129481747181357U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14849157800322754413U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 18116651528452542634U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 3638480428016835537U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4105057226952948599U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5911714320560994391U;
            aOrbiterH = RotL64((aOrbiterH * 1796514171654961389U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 26U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterF, 57U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterF, 50U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 21U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterH, 43U)) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26997U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 30158U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 31289U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25554U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27024U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 25678U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 29U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 26U)) + RotL64(aCarry, 11U)) + 8506388683755208267U) + aNonceWordM;
            aOrbiterJ = (aWandererK + RotL64(aCross, 51U)) + 2179323259055019735U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 3345902531140983016U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 17456139311481306584U) + aNonceWordL;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 41U)) + 14587864088462311164U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 57U)) + 13178947246650647057U) + aNonceWordD;
            aOrbiterE = (aWandererE + RotL64(aCross, 13U)) + 12866578138946916962U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13098524333655118173U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15451329483787541982U;
            aOrbiterC = RotL64((aOrbiterC * 13580376920467431451U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9494299579678389385U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15581954810375490643U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13670002280188424825U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4487042505730624892U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2774455928791636186U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15847933919136777451U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12435319582397755819U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10077180055177766823U;
            aOrbiterE = RotL64((aOrbiterE * 3924363471701748703U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10391963896910956455U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6149237416725301794U;
            aOrbiterJ = RotL64((aOrbiterJ * 10115917698918612823U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15673402771629639978U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14729117178956592426U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9070464269215820531U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14492001279368870240U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6278248084483259952U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 16731228350971263873U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 35U)) + aOrbiterC);
            aWandererI = aWandererI + (((((RotL64(aIngress, 56U) + aOrbiterG) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 37U)) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 18U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + aNonceWordK) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC8F7127DB03211D5ULL + 0xFAF2074EEA4B12AFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF36163E965C732D1ULL + 0xABAB3271AB694E7FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB195712807BB91D1ULL + 0xA525CE3D8F2109D7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9C32878CD8AD223FULL + 0xC221626993D0D915ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD0B3BEC6112B5AD1ULL + 0x9A9489B48636B00AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCBE6BB34FB36874DULL + 0xDCDD265E88B17B80ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE688B078F0DEC69BULL + 0xF82DE393E30F9861ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA248198BFA00AC9FULL + 0xDE4EAE56BBBA0511ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9E56A40122A8AD61ULL + 0xBE1BEBC01BA73B93ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAFC5B1B0A9056A63ULL + 0xB5CD8C93D549F8DFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC15E2B7FBFB559AFULL + 0x9FC0743905C22417ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE027C14E55D35223ULL + 0xBAEC1F9B96880074ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBA0F2FC9B68DA957ULL + 0x9796E1CDFA5952CAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE6ED537FE1D33EABULL + 0x864FB61F59BE0509ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB016DAD1D7B170C7ULL + 0xFD5C2D055B16AA37ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE0343F8368CCA543ULL + 0xA9D21317AF28349BULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aWorkLaneA, aOperationLaneA, aFireLaneC, aFireLaneB, aOperationLaneB, aWorkLaneC, aFireLaneD, aOperationLaneC, aWorkLaneB, aWorkLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6320U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 8067U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2673U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3852U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2146U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6453U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 9023059520606551446U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 43U)) + 662441755115638133U;
            aOrbiterC = (aWandererI + RotL64(aCross, 41U)) + 16957253361196144712U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 7840955025765308605U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 6U)) + 346855809270395799U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 57U)) + 16099139781586668343U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 53U)) + 3706457327118322098U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 12166825885547622870U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 47U)) + 7792658665720344200U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 3U)) + 7128477606152986326U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 34U)) + 11116533962780290084U) + aNonceWordJ;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10443889548568288532U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4402387036946561017U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 9032964741841833277U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13002706161178447654U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13929727277530310708U;
            aOrbiterI = RotL64((aOrbiterI * 7005639090871200285U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10949073760696935106U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15405923432006783533U;
            aOrbiterB = RotL64((aOrbiterB * 17989565878445202495U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 18096057968822208905U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3032155040484574973U;
            aOrbiterD = RotL64((aOrbiterD * 448597307502544605U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17462076466907467134U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15471015427013701406U;
            aOrbiterG = RotL64((aOrbiterG * 6113474000571976139U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3549031751266594344U) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14243218483842508113U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9041601306479302047U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5803147589312920032U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5549470512227427855U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12592362489263862879U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10076661824293832189U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 3196799148974716550U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8183276968961467775U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5245559903456662243U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5907555542861339984U;
            aOrbiterH = RotL64((aOrbiterH * 10224549416454347583U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12670710096595941569U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 655047039452620836U;
            aOrbiterJ = RotL64((aOrbiterJ * 9717552134857988153U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2654837870443908572U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9023059520606551446U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 170905364378771841U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 34U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 47U)) + aOrbiterB) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 56U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 21U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterA, 50U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 30U) + RotL64(aOrbiterG, 19U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterF, 11U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11482U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 14586U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 10119U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8496U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16094U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11009U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = (aWandererH + RotL64(aCross, 26U)) + 15652862298542575895U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 16925323928418184554U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 3U)) + 4413861484961668394U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 2215946422098155969U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 35U)) + 14975185533513111110U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 39U)) + 9711613814905834552U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aScatter, 14U)) + 13154957291850149471U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 21U)) + 5058313016418534840U) + aNonceWordH;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 11U)) + 15011423472941211620U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 43U)) + 2030053257469580168U) + aNonceWordB;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 150530795186791193U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10878237472104183427U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11724672539469573109U;
            aOrbiterH = RotL64((aOrbiterH * 16158741837357985395U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9589700906445846956U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1367381624958248949U;
            aOrbiterD = RotL64((aOrbiterD * 8459515089081211977U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 12003215666757518106U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11232479330848006729U;
            aOrbiterA = RotL64((aOrbiterA * 10993290955464593033U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13013910456628561621U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6092509838924105265U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 805601154718006061U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11999225836250312801U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14421271973875748413U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9529010940887430157U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15536288285741825272U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2071793889925436679U;
            aOrbiterB = RotL64((aOrbiterB * 1526376970151714589U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5622386476463436967U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16147972771639168516U;
            aOrbiterJ = RotL64((aOrbiterJ * 11826916832825159095U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4519892856053952290U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12059500374938843538U;
            aOrbiterK = RotL64((aOrbiterK * 14987533625537956299U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4547335128847992282U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15378473334472216418U;
            aOrbiterC = RotL64((aOrbiterC * 13907560285280544037U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14644123269581735633U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6434315615480805381U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 4335857173941645355U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14241680137158382296U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15652862298542575895U;
            aOrbiterE = RotL64((aOrbiterE * 4190840063924551519U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 18U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 52U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + aNonceWordI);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 10U)) + aOrbiterC) + aNonceWordP) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterH, 27U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 50U) + aOrbiterC) + RotL64(aOrbiterH, 41U));
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 37U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterF, 24U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererI, 58U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneC
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21357U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 23406U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 17879U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22352U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19145U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18775U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 22U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 14823268998003220191U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 43U)) + 15295237288788213847U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 16434853402001133899U) + aNonceWordI;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 6U)) + 7555911304407871631U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 37U)) + 14977248264994834620U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 21U)) + 9707764144919392380U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 11U)) + 1277304385464681529U) + aNonceWordE;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 3089786220465849395U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 13U)) + 3700503853358695085U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 47U)) + 3240054112993517371U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 54U)) + 16897532076915366859U) + aNonceWordH;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 18167359289798364307U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8870819278575769863U;
            aOrbiterG = RotL64((aOrbiterG * 9334066154398059075U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15363069206212330251U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14858164441499725158U;
            aOrbiterJ = RotL64((aOrbiterJ * 14931933411393847915U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5357144808788707522U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2910681277417754860U;
            aOrbiterE = RotL64((aOrbiterE * 13170868582159347059U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9824408699018165151U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 368370224788793300U;
            aOrbiterK = RotL64((aOrbiterK * 14358982366258729959U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7095398304588825115U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11418879758164313554U;
            aOrbiterH = RotL64((aOrbiterH * 5983520332639771791U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2171599720681913272U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17593730219647495033U;
            aOrbiterB = RotL64((aOrbiterB * 12926053208918563087U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17755947635188715523U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14565740605227022106U;
            aOrbiterI = RotL64((aOrbiterI * 15866418354612945335U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14538017880915584414U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6174566474851449123U;
            aOrbiterD = RotL64((aOrbiterD * 179569008593475683U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3806438394748643441U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13737114463856719285U;
            aOrbiterA = RotL64((aOrbiterA * 13439346068497710151U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3698379331577470045U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1097081284062708554U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 3498627643013255777U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 215117138867597766U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14823268998003220191U;
            aOrbiterC = RotL64((aOrbiterC * 12131828437975771377U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 19U)) + aOrbiterC) + aNonceWordM) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 60U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 5U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterB, 53U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 23U));
            aWandererA = aWandererA + ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterI, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 50U) + aOrbiterK) + RotL64(aOrbiterI, 50U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneB
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31213U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((aIndex + 28919U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27456U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25562U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30554U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 27151U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 21U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 36U)) + 2330952702412094686U) + aNonceWordE;
            aOrbiterD = (aWandererG + RotL64(aScatter, 3U)) + 7820188225935060799U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 9347644591709839145U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 21U)) + 2288624878446846870U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 11U)) + 9358977729492824128U) + aNonceWordN;
            aOrbiterE = ((((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 1858511275052455039U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 51U)) + 13715478509322292552U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 29U)) + 16413396625604260455U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 17714322215518432705U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 27U)) + 16188315436202861122U) + aNonceWordA;
            aOrbiterC = (aWandererH + RotL64(aIngress, 14U)) + 5564445841368207813U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13717068949900594673U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14143659432287313765U;
            aOrbiterJ = RotL64((aOrbiterJ * 17281441046722262917U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5729546141908425670U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4297827922736712074U;
            aOrbiterI = RotL64((aOrbiterI * 13631630436759768885U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 829520109395163673U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11547160328525174295U;
            aOrbiterA = RotL64((aOrbiterA * 4759690159673049775U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2907177944512117206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11100346409065275671U;
            aOrbiterF = RotL64((aOrbiterF * 17927994356809011637U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1344592529249949068U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6470438516791143572U;
            aOrbiterK = RotL64((aOrbiterK * 13339390828725370475U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5217751823741520847U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5371275223586938039U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 12318403075523724125U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 14218103150268532919U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1367628876596800571U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13777531272321533137U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2372041991018455610U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9870744274890595581U;
            aOrbiterH = RotL64((aOrbiterH * 12093443117747395585U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15531376915156611594U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11166549148968363252U;
            aOrbiterE = RotL64((aOrbiterE * 10024372567841218915U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8555942275137258839U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3304132937209624841U;
            aOrbiterC = RotL64((aOrbiterC * 7965093976633155809U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14825330575158830172U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2330952702412094686U;
            aOrbiterD = RotL64((aOrbiterD * 9146641978165131495U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 38U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 6U) + aOrbiterH) + RotL64(aOrbiterA, 41U));
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 21U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 48U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + aNonceWordC);
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterD, 51U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 40U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aNonceWordP);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterE, 60U)) + aNonceWordI) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF9CEF3362736B71BULL + 0xC18F446834B44A9DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD6910C4A53F6DA39ULL + 0xBEED3F8A4AC8DDB3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB1B0DADB3C10C48FULL + 0x852F09DB834A42CBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCCFBA208FC14EFCDULL + 0x82F4D46FFDC637EBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8E8F9319D3B8F843ULL + 0xB9337F4B9DF3BE5DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD482E4352531D645ULL + 0xCC062D067626F600ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8BBB2D9DE27EFE27ULL + 0xA156504C95E5F603ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF40BA73A86D2C0EFULL + 0x9410349C2F159F2FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC03E821EEF472605ULL + 0xE349563BA4F71C76ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAC32B1A5B97D998DULL + 0xBF3465D02D7126A7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAAA030FF8F15B4D3ULL + 0xA034968A5AE47888ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF05CF520CA93A4F1ULL + 0xBA7FC8DBEE97DDC5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE4A559E0E119E163ULL + 0xDDD12F9C9AEEA89FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC6345CD1BC8B4887ULL + 0xB9DD481A7AC982EFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE49E013BF23B4D39ULL + 0xA2119A258A7C2D4DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x950EF251B07D7531ULL + 0xFE6FBFBF1D47A5D5ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneB, aExpandLaneA, aFireLaneB, aWorkLaneD, aExpandLaneB, aFireLaneA, aFireLaneD, aExpandLaneC, aFireLaneC, aWorkLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2661U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 3428U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 7105U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3762U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6993U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 3229U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 4U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererH + RotL64(aScatter, 41U)) + 12583180859826261500U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 27U)) + 9067093488553721468U) + aNonceWordF;
            aOrbiterG = (aWandererF + RotL64(aIngress, 23U)) + 12173106198862881754U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 36U)) + RotL64(aCarry, 23U)) + 11333491014394592654U;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 3511883526940919554U) + aNonceWordN;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 47U)) + 7416810692106273044U) + aNonceWordI;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 13U)) + 8341174972619784110U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aCross, 57U)) + 2220852854836962979U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 52U)) + RotL64(aCarry, 51U)) + 8090781422229383825U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2338801236599102223U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12484514711848308104U;
            aOrbiterG = RotL64((aOrbiterG * 10364216764253366067U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13684861340589131816U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12796636819991873058U;
            aOrbiterF = RotL64((aOrbiterF * 5533508014234835669U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7634198650894837690U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10240326122201201762U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 8758703497719125901U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4162814763739453934U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2766504649149048469U;
            aOrbiterD = RotL64((aOrbiterD * 16731843453895178671U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11051393030148769655U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17687055068651386665U;
            aOrbiterH = RotL64((aOrbiterH * 1042927176246229537U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3353615315436983420U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5971640796220306310U;
            aOrbiterE = RotL64((aOrbiterE * 15804313508835034807U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 12299773092762384765U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7435804907797063411U;
            aOrbiterK = RotL64((aOrbiterK * 9848139805288165965U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8735783937125735699U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11903126115475835615U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16942088822124940265U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4427166023462475475U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6011733469446008137U;
            aOrbiterI = RotL64((aOrbiterI * 17298067225913923517U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 42U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 56U)) + aOrbiterE) + aNonceWordO);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterI, 51U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterF) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 30U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 18U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12637U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 9032U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 10362U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9885U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15837U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12738U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 12U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 8975885703279267062U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 47U)) + 8664844915562660637U) + aNonceWordM;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 28U)) + 12281774799736296726U;
            aOrbiterD = (aWandererG + RotL64(aCross, 53U)) + 15347461352311329726U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 43U)) + 12967500561828907834U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 5002833859280402726U;
            aOrbiterG = (aWandererH + RotL64(aCross, 47U)) + 11908257536954668983U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 34U)) + 17017174811949227162U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 19U)) + 16851323125613931180U) + aNonceWordG;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13469326957728686706U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5228638551056105241U;
            aOrbiterH = RotL64((aOrbiterH * 13369947664646167255U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11945166198089308564U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16268645041872996022U;
            aOrbiterJ = RotL64((aOrbiterJ * 5391448793718370911U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14781204627695095701U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5365325354838101092U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8017284997946310807U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 563147416025715953U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14660867395395625851U;
            aOrbiterE = RotL64((aOrbiterE * 4769458126865307103U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3168989056355712105U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16179131669773665579U;
            aOrbiterD = RotL64((aOrbiterD * 5641461617066671723U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4160220074225527179U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8597134686962559111U;
            aOrbiterF = RotL64((aOrbiterF * 639572585431474015U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16811551552456811661U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5827323970423386301U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9328247349730652021U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15583234353262170227U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2950816254621717748U;
            aOrbiterI = RotL64((aOrbiterI * 1102417597476170143U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4426165025104306337U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 11871220132164971152U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 2366168050042802207U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 42U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 11U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterI, 24U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 52U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterD, 43U));
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 11U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 48U) + aOrbiterK) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19349U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneD[((aIndex + 20916U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17674U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24137U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22229U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18179U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 38U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (aWandererF + RotL64(aCross, 48U)) + 3105313968748067810U;
            aOrbiterG = ((((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 9977249451119627064U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 17941392803495349366U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 53U)) + 4279533326705471133U;
            aOrbiterH = (aWandererH + RotL64(aCross, 60U)) + 13983828966811580039U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 3983490984234810378U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 19U)) + 308786542215259956U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 37U)) + 8443607695364427037U) + aNonceWordD;
            aOrbiterK = (aWandererA + RotL64(aCross, 11U)) + 14939626441464340668U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9350693577306121110U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1717071159396961752U;
            aOrbiterE = RotL64((aOrbiterE * 11062480662625054525U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15911765265202100610U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 14898546272333182767U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 2674900543810733067U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3560903518513465868U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5367062725726860234U;
            aOrbiterF = RotL64((aOrbiterF * 8521908836601319553U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15233321480618877327U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9288449812290126074U;
            aOrbiterB = RotL64((aOrbiterB * 6815298520404038519U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5504840529511585676U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6825598386801620046U;
            aOrbiterG = RotL64((aOrbiterG * 11666542445846250077U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6433024450721339470U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 97934156644929458U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 8630530773006923215U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3260053604798744515U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16539416623243059076U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 12199577351166064503U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9814290051339038920U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13280156404507444041U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15269010043398910061U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11853942590993546833U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13207869904312989977U;
            aOrbiterK = RotL64((aOrbiterK * 15503461937625795969U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterD, 20U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 14U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + aNonceWordI) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 10U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneA
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31269U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 26160U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 26460U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26682U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27243U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24848U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 6U)) + 16651241552253078315U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 29U)) + 4558144676982478003U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 8814884320080367550U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 16011579668555672117U) + aNonceWordD;
            aOrbiterI = (aWandererE + RotL64(aCross, 43U)) + 4738918668759862438U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 21U)) + 12526083125540985108U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 36U)) + RotL64(aCarry, 13U)) + 8048723561746000552U) + aNonceWordI;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 57U)) + 1082218464034639039U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 47U)) + 8432043246965946816U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9982080524048636852U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6720069955755215919U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1025046364205332059U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1019035028070247757U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7360619079463870467U;
            aOrbiterI = RotL64((aOrbiterI * 6623074813047915863U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10893918488381348474U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1390297670907738019U;
            aOrbiterB = RotL64((aOrbiterB * 11909657437658597735U), 3U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 12512200589031203480U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14741471280748399540U;
            aOrbiterC = RotL64((aOrbiterC * 3012135242889901095U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8543897248359826770U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8545972622733791272U;
            aOrbiterF = RotL64((aOrbiterF * 11793879362775346821U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7049384618581928664U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 14730773807906925408U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 10711566871536755073U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11480717275652449986U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1135397594974536859U;
            aOrbiterK = RotL64((aOrbiterK * 6347492892938856497U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6897207625849516702U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10920630712550287148U;
            aOrbiterJ = RotL64((aOrbiterJ * 4140705091806993359U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1094056478999931332U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6784487144549717207U;
            aOrbiterA = RotL64((aOrbiterA * 6295177724167067891U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 28U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 18U)) + aOrbiterD) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 10U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aNonceWordP);
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterC, 4U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 44U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterF, 35U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC2BC6E7D4F4AFEA7ULL + 0xEBCA64CE48CD1481ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8709EA740D643EEFULL + 0xCCF387C944BB1C1AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC88BBAFDED980E91ULL + 0xE40990ECD3626EEBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB3FB049F2D9F56E3ULL + 0xE9E9BD172187EA9DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x94B202769A828477ULL + 0x8EC50EF83199D1AFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEE54B1A84AFD7EC1ULL + 0x85913AA8C9AF6598ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x887C98B284212721ULL + 0xB964CD16A5B663C5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE3BC43A0BAB074FBULL + 0xAFF3929328593CE4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x926642A34845BAFFULL + 0x86A6448AB01DB9F3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC58BB92B5F90B27FULL + 0xB774E9F1670E131CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x828BAAA424A4B32BULL + 0xFB8C9BFDDA1234AFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF1869BFA7687A90FULL + 0x9E52DE87ED019857ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x97D645D25D55D489ULL + 0xD3383A0F9BAEC324ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE8E56BBB959EE035ULL + 0xE01A32F3BB9F81E7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEFA8125614D773C3ULL + 0xE84ADC97AC7825AEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFD7CE5A082C6F84FULL + 0xBD2B3C7FDFB46AF4ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aOperationLaneA, aOperationLaneC, aExpandLaneB, aFireLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneD, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1877U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 7939U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4595U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6351U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4455U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 116U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 48U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = (aWandererH + RotL64(aCross, 41U)) + 5721224134332887360U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 47U)) + 6892749729775049095U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 3884839462099556836U) + aNonceWordD;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 4365431706830216193U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 15501528746571578773U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 35U)) + 4505911326320650606U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererB + RotL64(aCross, 60U)) + 1865129050927879580U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2011737665969640369U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 611672935827062688U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 12873671551304596619U), 5U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 663547038310431047U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5468932264754299556U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11968657455484578525U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17920294117231191705U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 486058453837528110U;
            aOrbiterB = RotL64((aOrbiterB * 8851102552244026737U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2789178451938129313U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 420772587981211184U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 17402987842294006667U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16196774774442181825U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16264169656793713547U;
            aOrbiterE = RotL64((aOrbiterE * 6900221986041638783U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10207659833859860796U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 8593749091183323678U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 10696776033512404927U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7224922076047787384U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15366267474865172373U;
            aOrbiterD = RotL64((aOrbiterD * 10134187073321814217U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 54U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 5U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 12U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16131U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneC[((aIndex + 15198U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15416U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8345U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9431U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14999U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 5U)) + 14157904117287696136U;
            aOrbiterF = (aWandererE + RotL64(aCross, 35U)) + 7369512677371640676U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 44U)) + 8411250745902073798U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 21U)) + 5002041814539710275U) + aNonceWordD;
            aOrbiterG = ((((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 9538041410816283124U) + aOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 5210700103927513061U) + aNonceWordM;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 7600709399101287982U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2366369466696580499U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5544575244203019109U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16231219246786333057U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8710073749110329779U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15998211310115361630U;
            aOrbiterG = RotL64((aOrbiterG * 15275657696897688955U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15354357553877376422U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 10657523549259276169U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 13695239532898311073U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10405750198355464768U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3465819693133515142U;
            aOrbiterD = RotL64((aOrbiterD * 14678343718277562799U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16724189641701408630U) + aNonceWordA;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 3484340153620198872U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 17247547677520703125U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7420442404884871126U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11138445997256757636U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11167543379937571127U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1428191560884663125U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16950093140800653985U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 4423012306984814805U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 50U) + aOrbiterH) + RotL64(aOrbiterI, 29U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 23U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 21U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterG, 14U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererA, 34U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18128U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 22938U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 20803U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23007U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16457U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 23658U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 6U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = ((aWandererI + RotL64(aScatter, 35U)) + 13174219512651137892U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 51U)) + 2715455762789269341U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 11U)) + 1338018183235594313U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 42U)) + RotL64(aCarry, 53U)) + 16566866551729552930U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 6901845297307236726U) + aNonceWordG;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 29U)) + 2476078302049201718U) + aNonceWordH;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 15531109473927052260U) + aNonceWordP;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4087849380858572351U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5167830630098599644U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1982835131228146099U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7275995452428627217U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14794340370010024117U;
            aOrbiterE = RotL64((aOrbiterE * 8779497557416568379U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8509217403041662849U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2321522025240806996U;
            aOrbiterG = RotL64((aOrbiterG * 113568101672878697U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5676672952755594051U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2304681269233504384U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15731441084605554497U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8383399721062437300U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13181984036942227666U;
            aOrbiterA = RotL64((aOrbiterA * 1648761328771932069U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13602604532551684210U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12725687663616352843U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 4684699861686199753U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5831790822416009806U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4535048543735457407U;
            aOrbiterD = RotL64((aOrbiterD * 12076777878870257053U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 11U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aCross, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 29U)) + aNonceWordM) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterH, 35U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 60U)) + aOrbiterE) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterG, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31002U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 24944U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29043U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28062U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24576U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30767U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 60U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 18191288703716505885U) + aNonceWordL;
            aOrbiterD = ((aWandererI + RotL64(aCross, 57U)) + 9824014524910417136U) + aNonceWordG;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 11953012029254917548U;
            aOrbiterF = ((((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 6297568011027199089U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 35U)) + 2576999400457367975U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 43U)) + 13176139160575558254U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aWandererE + RotL64(aCross, 10U)) + 9978408174563621810U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16765834875061607142U) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16534507305459121344U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 8943988574248229067U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 3114710944346151807U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10240517868726718592U;
            aOrbiterB = RotL64((aOrbiterB * 4645691562915606463U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10721450637990777883U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16689590768796583952U;
            aOrbiterG = RotL64((aOrbiterG * 3046344179729901637U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2427422768928450209U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13495584061816457831U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6670984773768885119U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7058636403765106682U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 9897341853944713767U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 14286816859999869231U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17749559755733386064U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12515645083926326659U;
            aOrbiterF = RotL64((aOrbiterF * 6582878478865838245U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2625692458813609962U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10596240255026143019U;
            aOrbiterD = RotL64((aOrbiterD * 11605800195771080135U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + aNonceWordC);
            aWandererH = aWandererH + ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + aNonceWordI);
            aWandererI = aWandererI + (((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 23U)) + aNonceWordK) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 60U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterB, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE762F14BC933F0A5ULL + 0xC0FDA2765ADC8A70ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF1740E61B8C43FC9ULL + 0xC62D3135B4B165BCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x89FE51CEB4C74257ULL + 0xDC503BDE2902D0CEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB6540CBED6771901ULL + 0x9B90BC3FD95AD745ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCFC51C76A4FEFA19ULL + 0xC8EAECCF0BD8B0A1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD80DD70633D0D9F3ULL + 0xB4FD7D2BB52F5D4EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDC1E18F40E860E99ULL + 0xD45C610A0DF0FB24ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB560986B0D49CDBBULL + 0x8E318EC59AC76B87ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB5608F834ABCE0CFULL + 0xAB1FCE31F47156BDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB7EB07550028BF9FULL + 0xD2F053A4EE9EA55EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x85F79120BAB3F687ULL + 0xCBB72E3C0B172A45ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD839514647F4D3A3ULL + 0xACCD38380700D61BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE9E50062CCD3A31FULL + 0x8A5C2DE5BC95AEB5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x998B9A2BD20CC31FULL + 0xE26B8A75E31BD432ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFC71DE2D452B281FULL + 0xBD2138F1576B9EA7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA819CB5AA80BD37FULL + 0xC656FE78BA5D8D82ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1257U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 2063U)) & W_KEY1], 34U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 18U)) & W_KEY1], 58U) ^ RotL64(mSource[((aIndex + 2319U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 60U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 17081642665820489793U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 43U)) + 14468854040067229623U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 29U)) + 2249450222593057429U) + aNonceWordN;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 14964389079511378664U) + aNonceWordE;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 17003491054252360650U) + aPhaseEOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 21U)) + 12710882240582032588U) + aNonceWordL;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 50U)) + 9887078182156755359U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7665284531810584704U) + aNonceWordF;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 7304284015511876717U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 6193179739025093929U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5517927023543751734U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17704756310857362759U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15826832172923213591U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11347400363019508578U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11696395232760991243U;
            aOrbiterF = RotL64((aOrbiterF * 9725231749679442003U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10875780291242873583U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7808740614343437672U;
            aOrbiterJ = RotL64((aOrbiterJ * 8889516201913716283U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3145390996141902032U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16080636485642732615U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 7445756373012217305U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3929263288176983844U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18210228766683996806U;
            aOrbiterC = RotL64((aOrbiterC * 13178080076505449091U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13948962323541421431U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3037683309790156893U;
            aOrbiterA = RotL64((aOrbiterA * 13406672352222636739U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 28U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterC, 6U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 39U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 52U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3234U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 5103U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4676U)) & W_KEY1], 52U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4211U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 54U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 57U)) + 3621877681473089725U) + aNonceWordE;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 13U)) + 4451752751536414717U) + aNonceWordG;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 46U)) + RotL64(aCarry, 57U)) + 11371625415377772117U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 6046792758881150619U) + aNonceWordC;
            aOrbiterI = ((aWandererK + RotL64(aCross, 5U)) + 8213166120394461682U) + aPhaseEOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 29U)) + 4343156661140422645U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 11105271483234947905U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 348904609985341372U) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12924652822526858767U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 2801892489296408735U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7461211697358520287U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16551553555297890558U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 16432952324635746293U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11908056404140782995U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9147367258259948715U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10777628928376261667U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8876461054692728610U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10546855952702525404U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10071104785895309677U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 4748636139110443794U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 783046909529525098U;
            aOrbiterI = RotL64((aOrbiterI * 8969157702460927215U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16683965945838696665U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12385412690177109575U;
            aOrbiterH = RotL64((aOrbiterH * 10795062772707143187U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8210546822184469023U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13146493623236979963U;
            aOrbiterK = RotL64((aOrbiterK * 13199947810161148155U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 44U)) + aPhaseEWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 4U) + RotL64(aOrbiterI, 57U)) + aOrbiterH) + aNonceWordK) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 13U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 37U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6294U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6152U)) & W_KEY1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6346U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5523U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 7894U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 22U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 14823268998003220191U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 44U)) + 15295237288788213847U) + aNonceWordB;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 16434853402001133899U) + aPhaseEOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 7555911304407871631U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 29U)) + 14977248264994834620U) + aNonceWordA;
            aOrbiterE = (aWandererE + RotL64(aIngress, 37U)) + 9707764144919392380U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 5U)) + 1277304385464681529U) + aNonceWordI;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3089786220465849395U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3700503853358695085U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 2079089949442685421U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3240054112993517371U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16897532076915366859U;
            aOrbiterE = RotL64((aOrbiterE * 4120874717534309035U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18167359289798364307U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8870819278575769863U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 9334066154398059075U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15363069206212330251U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14858164441499725158U;
            aOrbiterK = RotL64((aOrbiterK * 14931933411393847915U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5357144808788707522U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2910681277417754860U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13170868582159347059U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9824408699018165151U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 368370224788793300U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14358982366258729959U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7095398304588825115U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11418879758164313554U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5983520332639771791U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterE, 48U)) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aCross, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 27U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 8828U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadB[((aIndex + 10432U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(mSource[((aIndex + 10612U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 10080U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8721U)) & W_KEY1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10358U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 27U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (aWandererI + RotL64(aPrevious, 19U)) + 6163290588946759209U;
            aOrbiterG = ((((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 7342672468560105447U) + aPhaseFOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererH + RotL64(aCross, 29U)) + 11574563167017282321U) + aNonceWordL;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 36U)) + RotL64(aCarry, 41U)) + 2254820206194758964U) + aNonceWordE;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 11U)) + 1469783447473099498U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 5U)) + 14174828900676165088U) + aNonceWordK;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 16277954291890598132U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14845750668693136766U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 150099699692047766U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7644895634421086357U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 1200784917165131703U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 9469982764806754302U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 17851969334511301943U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10956702761701710182U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7915506894975487807U;
            aOrbiterA = RotL64((aOrbiterA * 8874108311712727983U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17335794183733623213U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 557028996286989506U;
            aOrbiterG = RotL64((aOrbiterG * 3993359298602424281U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1597385667771002414U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4376417959915162639U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4626236858205178149U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 549770198518993876U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 756554555648070919U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 16272320259614325355U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7298557532533152193U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3336802611342112013U;
            aOrbiterJ = RotL64((aOrbiterJ * 14679103452120080499U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 28U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterD, 58U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 41U)) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterF, 27U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11681U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 11589U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11969U)) & W_KEY1], 53U) ^ RotL64(mSource[((aIndex + 11086U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13110U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12421U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13382U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 24U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererH + RotL64(aCross, 20U)) + RotL64(aCarry, 13U)) + 15549114274303128055U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 5U)) + 16466750056388063241U;
            aOrbiterF = ((((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 12209449840836787142U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererI + RotL64(aIngress, 27U)) + 14551496099734294336U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 6266576428679808622U) + aNonceWordJ;
            aOrbiterK = (aWandererD + RotL64(aCross, 51U)) + 16892841575635668152U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 57U)) + 7375966221423362125U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11926105302821753530U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16219253791550461124U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2117550758226173419U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7299056065319248160U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15234001484933728439U;
            aOrbiterG = RotL64((aOrbiterG * 8182244796017018911U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6615802589932632120U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5481176858895819247U;
            aOrbiterK = RotL64((aOrbiterK * 3604590158551984877U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17220507586542139380U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14137921473739415340U;
            aOrbiterJ = RotL64((aOrbiterJ * 10634645686035907603U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16981960446540932787U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10897565927079518588U;
            aOrbiterH = RotL64((aOrbiterH * 418843936329303571U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2746889569299593263U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 4894117146736361379U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2656750612042673191U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 18294823016957137777U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 86828501068883383U;
            aOrbiterI = RotL64((aOrbiterI * 11432686669235402365U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 12U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 41U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + aNonceWordM);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 54U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 11U)) + aNonceWordG) + aPhaseFWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 52U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16149U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14841U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16007U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15118U)) & W_KEY1], 21U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14210U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16067U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 13684U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 9446153639709651566U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 10550762260670758167U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 5U)) + 7062634922142578383U;
            aOrbiterE = ((((aWandererK + RotL64(aCross, 28U)) + RotL64(aCarry, 21U)) + 9178499097812764515U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 21U)) + 6887103379773525538U) + aNonceWordG;
            aOrbiterA = ((aWandererA + RotL64(aCross, 51U)) + 6239750312052010257U) + aNonceWordC;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 13U)) + 17645022614523287959U) + aNonceWordM;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3639618183259408272U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3131737117548745095U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 6585057380704940395U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7253994382396406554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15217993711938379561U;
            aOrbiterG = RotL64((aOrbiterG * 17853313384747259923U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12594152227603630033U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 11250170200489647869U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 546800378327864723U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 12936942656624279424U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10990736056052106149U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7123916809953459187U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12787293075893090465U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17154990205620778151U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10031369940028159521U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1270827262969060301U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17337623431665013136U;
            aOrbiterH = RotL64((aOrbiterH * 1517262088236356107U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 830330490987911853U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6828309232554560547U;
            aOrbiterB = RotL64((aOrbiterB * 9742464176986145819U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 3U)) + aOrbiterH) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 58U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + aNonceWordI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 11U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16646U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 16403U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 18442U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18096U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18583U)) & W_KEY1], 48U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18540U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18590U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 11521331427196538632U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 43U)) + 16653824187682957632U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 11654676587350088289U) + aPhaseGOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererE + RotL64(aScatter, 34U)) + 8010313317412193584U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 23U)) + 1108775560502907471U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 51U)) + 243952321439823521U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 2324945800401240403U) + aNonceWordC;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9257554497543369657U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16701314607244592540U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8790054741039817107U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3900445848034341782U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7652316487347103658U;
            aOrbiterC = RotL64((aOrbiterC * 11480123491361589799U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14980368605272070578U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2001165460948764796U;
            aOrbiterI = RotL64((aOrbiterI * 8110980921827107649U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1911044015666991050U) + aNonceWordE;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 11366207111147818339U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 17234439040652553865U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16469329744002456607U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8062793687044950815U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 5856142259851144369U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15364721421972807872U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8979915611483540231U;
            aOrbiterG = RotL64((aOrbiterG * 10899377466171153383U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7654234623563110457U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1526832460342135008U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12766083052650723051U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + aPhaseGWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterC, 12U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + aNonceWordK);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 35U)) + aNonceWordL) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + aNonceWordJ);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21721U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 20513U)) & S_BLOCK1], 36U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19789U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20655U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20010U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20399U)) & W_KEY1], 3U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19547U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 21207U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (aWandererF + RotL64(aPrevious, 37U)) + 6024062041314952357U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 29U)) + 18340757093658015585U) + aNonceWordP;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 11911120493880346751U;
            aOrbiterC = (aWandererD + RotL64(aCross, 22U)) + 17428074353884654439U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 13U)) + 12790849760814795936U) + aPhaseGOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 12633397052172117800U) + aNonceWordO;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 11946150433665237945U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16842157900909419285U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14186235783224155962U;
            aOrbiterE = RotL64((aOrbiterE * 10521157787073684417U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13284904542579767591U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11609181965078844357U;
            aOrbiterF = RotL64((aOrbiterF * 5455780554452453513U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9628562297095374984U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7850281529011259759U;
            aOrbiterI = RotL64((aOrbiterI * 17611485102925470357U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 257458718073794527U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10693404545773519306U;
            aOrbiterH = RotL64((aOrbiterH * 14821443722828498323U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3430519236533871460U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6183054506953198055U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6121082743789970911U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2905610989884221654U) + aNonceWordN;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4472163910775333862U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 7770678426310856745U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16870142883133769663U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1403692060594816451U;
            aOrbiterK = RotL64((aOrbiterK * 9740854430251597879U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 39U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 22U)) + aOrbiterJ) + aNonceWordH);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterK, 11U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aScatter, 36U) + aOrbiterE) + RotL64(aOrbiterC, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 43U)) + aNonceWordE) + aPhaseGWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 51U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24465U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 24242U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24211U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((aIndex + 24106U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22912U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23907U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23269U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22839U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 39U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 21U)) + 13854738573712660276U) + aPhaseGOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 29U)) + 16835460633412286294U;
            aOrbiterC = (aWandererD + RotL64(aCross, 47U)) + 6785859293758091931U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 11U)) + 126317283127992659U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 53U)) + 7568963536291415413U) + aNonceWordL;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 12U)) + RotL64(aCarry, 23U)) + 12294016745653004819U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 18269588932920281147U) + aNonceWordC;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5872406424994751026U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7764434758831474129U;
            aOrbiterC = RotL64((aOrbiterC * 3772146788188420071U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4804168969415573371U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 959601763507651280U;
            aOrbiterA = RotL64((aOrbiterA * 4647396592804833217U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9257644462479293048U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14332699366894494579U;
            aOrbiterB = RotL64((aOrbiterB * 8829304078930625541U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10487012596470786004U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 612729229562321440U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 11380387280507726003U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7845523921295625315U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 12742115479740024747U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 15578543510683986421U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10294667720904610944U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14369711143154904567U;
            aOrbiterG = RotL64((aOrbiterG * 13753005602288309379U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10918344717497681894U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 18136794828308636957U;
            aOrbiterE = RotL64((aOrbiterE * 17899418637978002409U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 10U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterI, 35U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + aNonceWordJ);
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 51U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 29U)) + aOrbiterH) + aNonceWordF) + aPhaseGWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 36U) + aOrbiterC) + RotL64(aOrbiterB, 44U));
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26860U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 24874U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26998U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((aIndex + 25146U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24782U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26820U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27038U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25922U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 36U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererD + RotL64(aScatter, 41U)) + 11480359716598965890U) + aNonceWordH;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 15431182525482873419U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 11360504974812776707U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 57U)) + 9292576416573382769U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 13U)) + 1549257414531028975U) + aPhaseHOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aScatter, 50U)) + 5347769463033129317U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 17019199177478377234U) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16558106007323125094U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3976182233825939422U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 4392162052317572289U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2889047161195954395U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2241831345026962605U;
            aOrbiterH = RotL64((aOrbiterH * 5757458560979927857U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12850802412140579294U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13541744735436450160U;
            aOrbiterD = RotL64((aOrbiterD * 906089290000537439U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2085863085516538212U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2969034221711544086U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 7768528124408400403U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6482666944512391472U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16969153556875844613U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9483462388353216219U), 23U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 5161314086757363678U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7150282484670673211U;
            aOrbiterI = RotL64((aOrbiterI * 8522427002337918663U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5465304381272305847U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2344610773390354017U;
            aOrbiterB = RotL64((aOrbiterB * 17010258514288089191U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 4U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 18U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD);
            aWandererE = aWandererE + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterA, 35U));
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + aNonceWordP);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + aNonceWordM) + aPhaseHWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27785U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((aIndex + 29870U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28413U)) & W_KEY1], 21U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28454U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28912U)) & W_KEY1], 56U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29774U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29651U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 29244U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (aWandererH + RotL64(aScatter, 35U)) + 16200278595895089008U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 20U)) + RotL64(aCarry, 11U)) + 1029614154810465897U) + aNonceWordL;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 29U)) + 7129562468705441295U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 14388903902433951274U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 1013568949315967455U) + aPhaseHOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aIngress, 47U)) + 3128823373497815651U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aWandererI + RotL64(aScatter, 13U)) + 14525694606889470589U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14443983602196782887U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12244220415328641190U;
            aOrbiterC = RotL64((aOrbiterC * 15052949098014803181U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10477159225338766614U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2842870123078131566U;
            aOrbiterB = RotL64((aOrbiterB * 11522265477555954071U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8621138818955849917U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5038396344400303181U;
            aOrbiterD = RotL64((aOrbiterD * 14636756322207385447U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2768613802894372496U) + aNonceWordK;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 2027754864051410015U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 2461322540050569287U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2848088309172056399U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 15017458513904884651U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 9926904679902843055U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9079797279596336139U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 15424866642305110811U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 12912331089970158845U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 13751764050290602740U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7694557131324740282U;
            aOrbiterE = RotL64((aOrbiterE * 14980807690491467023U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterH, 5U)) + aPhaseHWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterB, 22U)) + aNonceWordG) + aPhaseHWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 35U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 48U) + aOrbiterC) + RotL64(aOrbiterI, 47U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 52U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32342U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 32387U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31513U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30520U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30466U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 31301U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 34U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 12U)) + 10404808878585437255U) + aPhaseHOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 10587858736301591439U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 1430530909801644435U) + aNonceWordM;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 9090938022430118902U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 57U)) + 12936604311751121235U) + aNonceWordB;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 43U)) + 1000583006020232032U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 27U)) + 12352532088997042232U) + aNonceWordF;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16723410947058502564U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16614089235313154270U;
            aOrbiterH = RotL64((aOrbiterH * 11530998303573027827U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4245553025593349277U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3353146318549477494U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14246377408238318091U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5935727336135635196U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10312187090293319667U;
            aOrbiterA = RotL64((aOrbiterA * 1395964500396711899U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12192843181244744484U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2542570124502586365U;
            aOrbiterF = RotL64((aOrbiterF * 17222847847573534963U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3315472769469002444U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17512858811783071174U;
            aOrbiterB = RotL64((aOrbiterB * 9070400454074283765U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16633218007427888082U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2502077714838858460U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 970762420815997725U), 13U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 14792910273226469214U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15739513291150783151U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11896279674116906915U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 12U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 53U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            aWandererE = aWandererE + (((((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aNonceWordH) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + aNonceWordC);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterI, 3U));
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC9D373AD4160B1F7ULL + 0xF80622416C9A54C8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x906B295C1C32AD25ULL + 0xBF38BCB131B1DB87ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDDDCC235B897AD37ULL + 0xE9E9F7026F07D047ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA783782A81A39A1FULL + 0xA90DABE4D7A3DEFDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAD23A8AD8704B36FULL + 0xD191A9F510C1131EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE4E1BB0994BBA80BULL + 0xD350DC18718C2E6FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE97C333A278190BBULL + 0xCCFB33B3F36A25BBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9F345C3359131D01ULL + 0xC10A9E7D2595082AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x87DD3AF75B83A0D3ULL + 0xD949F09B437DC99DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDDE6495182EC14D7ULL + 0xEE643E78C4AD7BB9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA29B9CA9DB24596BULL + 0xF98494B5B0F3B975ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA2E63344EDA70CA1ULL + 0xD2407A1A77F97D1BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF451F6AA5DEB34D1ULL + 0xCF577B5769C033D1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAF42C35E8AAB9DBDULL + 0xF84BC272D0F7EB84ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEDCC828BDACEE7FBULL + 0xC1D96BCC7ADC7632ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA912238D7320DC15ULL + 0xB5D9FB872A391374ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4762U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 3994U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 531U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 656U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2769U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 5480870806135400132U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 5U)) + 8034874599430768743U) + aNonceWordJ;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 19U)) + 4006919843736863767U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 54U)) + RotL64(aCarry, 3U)) + 2988069748674633718U) + aPhaseAOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 12347295651973135786U) + aNonceWordK;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 14152683894431568192U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15765143815254196598U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8948877544291035189U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 10473067082331244233U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 1089466925383677249U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17334888609179149753U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13215039929873682230U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3957997712247961479U;
            aOrbiterC = RotL64((aOrbiterC * 7631186240013784703U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10023907397941685546U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14593012591254614353U;
            aOrbiterH = RotL64((aOrbiterH * 17111300092082154687U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13353797968154036726U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9259966668512102858U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8326732574268308221U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 39U)) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aPhaseAWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 56U) + aOrbiterD) + RotL64(aOrbiterF, 23U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + aNonceWordI) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 21U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10695U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 8417U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9225U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9431U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9658U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 47U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = ((((aWandererI + RotL64(aPrevious, 12U)) + RotL64(aCarry, 53U)) + 16124889768301047791U) + aPhaseAOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 11912338587186717280U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 53U)) + 8594012868813114354U) + aNonceWordK;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 18281043566156682815U) + aNonceWordC;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 3U)) + 16853106130200942302U) + aPhaseAOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2611212958619673086U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 18039472325066855180U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10213999643376367785U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14495785571345122046U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4556063793412832418U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 13166927543135467627U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14896419970271244358U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 880028529183500036U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14228281807461251361U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2379557167489415783U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11854373946064529806U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 150755294320438887U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 1487252775956449964U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12777924204511625545U;
            aOrbiterD = RotL64((aOrbiterD * 1366019527386994789U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 4U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + aNonceWordA);
            aWandererK = aWandererK + (((((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterD, 10U)) + RotL64(aCarry, 27U)) + aNonceWordM) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + aNonceWordN);
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15786U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 14671U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13489U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 16356U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11707U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15709U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = ((((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 6318740973868639425U) + aPhaseAOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 40U)) + RotL64(aCarry, 23U)) + 5487840061430920881U) + aNonceWordA;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 5U)) + 10258706763248072672U) + aNonceWordI;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 18356875269730338208U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 51U)) + 12883160282903147010U) + aPhaseAOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1010140474942697730U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17733939421700898293U;
            aOrbiterD = RotL64((aOrbiterD * 9233534157871885251U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13693055887924981201U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 14574732452793385269U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 9373765929885750185U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10832873941223609012U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8212600587135328040U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5334613996794796145U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5312744319781971178U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6173741211706546923U;
            aOrbiterC = RotL64((aOrbiterC * 12854414066390848249U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3693249147883790810U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 18365859989736602556U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 3348463719324104997U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 58U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + aNonceWordD) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 41U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aNonceWordP) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 20U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20623U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 20923U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 20692U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16764U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18836U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19736U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 5U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 13880995121909552664U) + aNonceWordA;
            aOrbiterE = (aWandererC + RotL64(aCross, 29U)) + 14534942818069300546U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 17745973100886007133U) + aNonceWordB;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 12U)) + RotL64(aCarry, 21U)) + 2249805580771946872U) + aPhaseAOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aCross, 51U)) + 4460116116396439410U) + aPhaseAOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3378683994078106878U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3992996501048809123U;
            aOrbiterC = RotL64((aOrbiterC * 13273544260537223797U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12057768808864451929U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 4115362079047921130U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 12263015903331031345U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 15297384955502206698U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17623548383481905636U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 7487278217901483685U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3559213898000162417U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12311605719074507335U;
            aOrbiterA = RotL64((aOrbiterA * 3982199462062847697U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14807313864347885885U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 11222085523291581822U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 12580941911587215653U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 34U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 58U) + aOrbiterJ) + RotL64(aOrbiterE, 57U));
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterF, 11U)) + aNonceWordF) + aPhaseAWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26548U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 25268U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25839U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22454U)) & S_BLOCK1], 48U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26071U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 23130U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 58U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 39U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = ((((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 5960680319644404115U) + aPhaseAOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 13U)) + 16050752633567034185U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 28U)) + RotL64(aCarry, 23U)) + 8447503223226854741U) + aNonceWordE;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 43U)) + 14176813813397917591U) + aNonceWordI;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 10534915376130006644U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6866224454375302514U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16506374165041008396U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1326855300197233833U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7167814023968794098U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13870852197416596664U;
            aOrbiterE = RotL64((aOrbiterE * 17015971222069856463U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 18064038854848993105U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9869630811507771691U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 13723164383800461387U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 863613100452759380U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16597969741225436529U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 2680793528887208903U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6575347108051310653U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17062262265485019063U;
            aOrbiterA = RotL64((aOrbiterA * 7601045488473620019U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 34U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterE, 3U)) + aNonceWordG) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA);
            aWandererC = aWandererC + (((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 53U)) + aNonceWordB) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 19U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29788U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 28650U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 28255U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30962U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28905U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31219U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 56U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 13U)) + 6467297102954816305U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((aWandererB + RotL64(aCross, 56U)) + RotL64(aCarry, 3U)) + 7921154109831114952U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 5701131763215638919U) + aPhaseAOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 10022999076719002684U) + aNonceWordP;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 43U)) + 4367135243038982316U) + aNonceWordM;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14445846824810383592U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7683697954545773253U;
            aOrbiterA = RotL64((aOrbiterA * 4832124801510084629U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17517006750428030899U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2052484792684025476U;
            aOrbiterI = RotL64((aOrbiterI * 12463117571122469643U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6279463052085808926U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 679280153651813684U;
            aOrbiterG = RotL64((aOrbiterG * 3047031560593583881U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2939516520188460569U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1960616434964712325U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15145998415466343039U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12273819390719947361U) + aNonceWordH;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 5685033154709449397U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 9845666295874714959U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + aNonceWordD) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 57U)) + aNonceWordO) + aPhaseAWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB + ((((RotL64(aCross, 38U) + RotL64(aOrbiterI, 40U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9444B5AE8F7B863BULL + 0x8BFC82B4D802FD4AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9B926B5A859713A3ULL + 0x929FD99452083581ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE4B203E01021F66DULL + 0xC662D19ACD7A79A4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDD3A4B7273A0D941ULL + 0x98185362BFA1B408ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB386BA8B6771392FULL + 0xFF13E583386E079AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8E3B88C9CA4FEEE3ULL + 0xF1C31C8B215F9FD3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB2162C34A0388AF7ULL + 0xE0507E50BB2AB709ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD2922B8B27BD0383ULL + 0xE4B2361B181F07CFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB0E663D0AF102287ULL + 0xCA7DB0F983232F45ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC309629247511DB1ULL + 0xACBE8C3A4F040CB1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCED47E79F89A339BULL + 0xD3578FB96EF04E80ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBFFBB4B63111C4ABULL + 0xF7D8760D85841FEDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBAAE6145B8082A17ULL + 0xD6E93722E6547A4FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x858D0A34FC8CFBE3ULL + 0xE437C68D3CD48882ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBE5F780FCD0F1EF3ULL + 0xD8D70AA403137A48ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB21FDD2F497AAA97ULL + 0xF914561E348289BFULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneC, aInvestLaneC, aFireLaneC, aExpandLaneB, aInvestLaneD, aFireLaneB, aWorkLaneA, aExpandLaneA, aWorkLaneB, aExpandLaneD, aWorkLaneC, aFireLaneD
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3770U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 1292U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 85U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 287U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3645U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 5231U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 27U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 6U)) + 12980104182836602177U) + aNonceWordH;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 19U)) + 3172622203188863995U) + aPhaseBOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 27U)) + 1170974132219980203U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 47U)) + 6035201940965047490U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 18033907118424996722U) + aNonceWordA;
            aOrbiterC = (aWandererB + RotL64(aIngress, 53U)) + 14604813424800580304U;
            aOrbiterG = ((((aWandererD + RotL64(aPrevious, 42U)) + RotL64(aCarry, 43U)) + 13720232492851066035U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 3902659710585257448U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 11U)) + 8331560652661619868U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 4485014147538689794U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 168202636924512424U;
            aOrbiterB = RotL64((aOrbiterB * 13711020666131492091U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16227825670092707848U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4792781933944671365U;
            aOrbiterC = RotL64((aOrbiterC * 15859849676231455283U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12636865372722601282U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 18198291399585556632U;
            aOrbiterH = RotL64((aOrbiterH * 18155803890313399795U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3650053185419807206U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5897288963905408776U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3706949366974086151U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9922308113622901726U) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13352279749091561510U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4025213180483632557U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14969461950939646117U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10231661776135056651U;
            aOrbiterA = RotL64((aOrbiterA * 11284575051455238501U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10621934544068320859U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6029116920305246887U;
            aOrbiterE = RotL64((aOrbiterE * 6087523725059376905U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12887482425168671195U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8351351557123783853U;
            aOrbiterK = RotL64((aOrbiterK * 3839381627914762245U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5405938210926464973U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 385145802287899406U;
            aOrbiterF = RotL64((aOrbiterF * 8330751480464271445U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 34U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 23U)) + aOrbiterG) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterD, 44U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + aNonceWordE) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterA, 10U)) + aNonceWordB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 18U) + aOrbiterC) + RotL64(aOrbiterH, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 7733U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 9124U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7631U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8386U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6375U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6709U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9596U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 28U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererD + RotL64(aCross, 60U)) + 16462052553719977502U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 12337064059566619581U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 15801005007094515447U;
            aOrbiterJ = ((((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 8228706742665081656U) + aPhaseBOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 53U)) + 11006723027845190869U) + aNonceWordC;
            aOrbiterI = ((aWandererK + RotL64(aCross, 47U)) + 18173765337829177450U) + aNonceWordP;
            aOrbiterF = (aWandererH + RotL64(aScatter, 12U)) + 530215083653542558U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 39U)) + 6608611827035564511U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 27U)) + 2246051826221626809U) + aPhaseBOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5228575308895381421U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10999213210689606857U;
            aOrbiterG = RotL64((aOrbiterG * 5467601259546342925U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 3773371037240485696U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8887985779436152504U;
            aOrbiterC = RotL64((aOrbiterC * 698713082830739677U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11150566414723818350U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8336366151003049546U;
            aOrbiterJ = RotL64((aOrbiterJ * 9033771197242493699U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13233968794237090787U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8172558473508478819U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17837070423649268435U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 133564480283347997U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15104810248883567064U;
            aOrbiterE = RotL64((aOrbiterE * 706802420642303533U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9138629520201127075U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13993086066341664080U;
            aOrbiterD = RotL64((aOrbiterD * 4875046427147105077U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6547273508580516932U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9838727018769865759U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 11395273371936839815U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 11685694999526122626U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8945983172566303116U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17791527981004597623U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17606249889617356327U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9296903152000480008U;
            aOrbiterI = RotL64((aOrbiterI * 18066622289408024413U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 6U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 36U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + aNonceWordL);
            aWandererE = aWandererE + ((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterJ, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 53U)) + aOrbiterE) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 40U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 50U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + aNonceWordA);
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneB
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12198U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 16059U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12741U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14814U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12649U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 48U)) + 13174219512651137892U) + aNonceWordD;
            aOrbiterA = ((aWandererB + RotL64(aCross, 53U)) + 2715455762789269341U) + aNonceWordF;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 1338018183235594313U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 11U)) + 16566866551729552930U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 19U)) + 6901845297307236726U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 2476078302049201718U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 57U)) + 15531109473927052260U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 24U)) + 4087849380858572351U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 5167830630098599644U) + aPhaseBOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7275995452428627217U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14794340370010024117U;
            aOrbiterG = RotL64((aOrbiterG * 8779497557416568379U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8509217403041662849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2321522025240806996U;
            aOrbiterA = RotL64((aOrbiterA * 113568101672878697U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5676672952755594051U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2304681269233504384U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15731441084605554497U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8383399721062437300U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13181984036942227666U;
            aOrbiterH = RotL64((aOrbiterH * 1648761328771932069U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 13602604532551684210U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12725687663616352843U;
            aOrbiterK = RotL64((aOrbiterK * 4684699861686199753U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5831790822416009806U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 4535048543735457407U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12076777878870257053U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10617608605149381858U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5244225377862618630U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 15307177251167023999U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18229989093139888456U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9728120630096192811U;
            aOrbiterF = RotL64((aOrbiterF * 16052574428163231023U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1312233443099767304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8043115602160128619U;
            aOrbiterE = RotL64((aOrbiterE * 9365756845731616963U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aCross, 52U) + aOrbiterE) + RotL64(aOrbiterD, 20U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterF) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aCross, 34U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterF, 48U)) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19404U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((aIndex + 18336U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 16700U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18469U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 21135U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 54U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 15383045568644941552U) + aNonceWordG;
            aOrbiterD = (aWandererK + RotL64(aIngress, 52U)) + 17452811657750910067U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 15660117718455155603U) + aNonceWordM;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 57U)) + 10396441207743665753U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 35U)) + 3708971058200841442U) + aNonceWordK;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 7000673057768598750U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 23U)) + 9886354469011131596U) + aPhaseBOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 5U)) + 16018065329058043467U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 18U)) + 5024756166109352320U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6587818720728886652U) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3652672354944162319U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10807121230791716109U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6307315649915348048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16405347331742979258U;
            aOrbiterC = RotL64((aOrbiterC * 7183142442906743699U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5427299664054601957U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4983381733483185898U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14646556236306407673U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10182995521328377487U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8694282877540593550U;
            aOrbiterD = RotL64((aOrbiterD * 14614602561910403893U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4085927978153269932U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6176195962815240877U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 16792916528959579875U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6966742100601433005U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9920952446921247521U;
            aOrbiterG = RotL64((aOrbiterG * 1879821050131820933U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11958734477518336014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2058335903640404380U;
            aOrbiterJ = RotL64((aOrbiterJ * 6986170159285417789U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 77366119537297816U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12072894199692855000U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 9083781120514635987U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11874297832446385377U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13715562531763053196U;
            aOrbiterK = RotL64((aOrbiterK * 12822488258322963187U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 4U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 47U)) + aOrbiterI) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterG, 20U)) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aScatter, 40U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterI, 39U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterG, 56U)) + aNonceWordF);
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterI, 27U)) + aOrbiterH) + aNonceWordE);
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aExpandLaneD
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25260U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneD[((aIndex + 27225U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 26086U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25064U)) & S_BLOCK1], 54U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25916U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 44U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererB + RotL64(aScatter, 34U)) + RotL64(aCarry, 41U)) + 5510690816044082200U) + aNonceWordM;
            aOrbiterE = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 15967820875033940530U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 21U)) + 539348720848176221U) + aNonceWordP;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 57U)) + 15779318183635560817U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 38U)) + 14511058534424187469U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 5811130556873428391U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 47U)) + 1085928476499444025U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 27U)) + 6973335316600768130U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 3U)) + 10747243745475009744U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1072260008981349754U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2018772405352495753U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 10840562112080574241U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1092091597048996547U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15103140149542167197U;
            aOrbiterC = RotL64((aOrbiterC * 621856991658027989U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13194619321108681542U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16749188603268621850U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9575408950550922039U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7427959503086895166U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9895804051379551393U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2701997336201570715U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4526020800679774259U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4484850928870048176U;
            aOrbiterE = RotL64((aOrbiterE * 17556987520625677313U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1837404844299040155U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15213208978489570694U;
            aOrbiterB = RotL64((aOrbiterB * 7062740584650274133U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9615231781751396800U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15872192167825648096U;
            aOrbiterJ = RotL64((aOrbiterJ * 2900526493682580729U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12530672039655918903U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10617836782870315804U;
            aOrbiterF = RotL64((aOrbiterF * 9716778004909794973U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 550750725406860977U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3498554352021622907U;
            aOrbiterG = RotL64((aOrbiterG * 9846933294851238495U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 24U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterC, 36U)) + aNonceWordH) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 47U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 53U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 6U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aNonceWordD);
            aWandererD = aWandererD + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterI, 21U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28003U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 31842U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29826U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31586U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneB[((aIndex + 29667U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 60U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererF + RotL64(aScatter, 10U)) + RotL64(aCarry, 21U)) + 14179205183062705133U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 57U)) + 210032324058740920U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 7387115089142500152U;
            aOrbiterI = (aWandererC + RotL64(aCross, 23U)) + 17583362781238061430U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 53U)) + 4991442849150005943U) + aPhaseBOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 38U)) + RotL64(aCarry, 43U)) + 2891376254689854555U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 27U)) + 10523274382407446239U) + aPhaseBOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 5U)) + 3861893764676218667U) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 19U)) + 3366674459852093746U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5898492634386601145U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7047353571244768721U;
            aOrbiterG = RotL64((aOrbiterG * 2257518291062508467U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14374108805453186316U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8763667021501226510U;
            aOrbiterE = RotL64((aOrbiterE * 7694695426430267863U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18261523829316379575U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 650477532238860965U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8291758490821819851U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2162326554604894042U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 5776546692501825278U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14911545784585246537U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3501863793638415049U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 14853789267425352958U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10590325397179928739U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15399673014671329743U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12253428583438990426U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 12052855472196447849U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13202953937621953839U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7547616636832698398U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9533399972562428073U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15709801946594868318U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12458677982746610971U;
            aOrbiterK = RotL64((aOrbiterK * 6662570874316418993U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6957370791367530127U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10511379961344950861U;
            aOrbiterF = RotL64((aOrbiterF * 15551333099264031337U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 26U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 5U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 46U) + aOrbiterD) + RotL64(aOrbiterJ, 37U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 28U)) + aOrbiterF) + aNonceWordN);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + aNonceWordJ) + aPhaseBWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterD, 51U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 58U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterF, 41U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 11U)) + aOrbiterF) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 50U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF3B72AEEE92FD921ULL + 0x8387FEE95A4B9BA6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA79E83A1CB51FA51ULL + 0xD39A2AC468E44D05ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8F7599D6993BD135ULL + 0xD492BC6614FF2003ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x86C25AFC6375EB83ULL + 0xF2318A4C99FD1C48ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCA4CB3F25D60BAE5ULL + 0xC0369C111F3985F2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEA2877933E785EF7ULL + 0xE5FB6D1FEBB45F4BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xADB950A5431BF73DULL + 0xF8CC3FBEBDD2F545ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE38198E7C2AC3B8BULL + 0xD1BD0A01576C4B92ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC0976AE18FEB0F79ULL + 0x9233EFDCD4CEA056ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD2EBB70D025B4207ULL + 0xB1735BF896E1A10CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x97BF05BBF16CEBB1ULL + 0xB70285816B52370BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC650D55BD7D08C87ULL + 0xBB694FB3F46E0709ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x93A72183BFBA14A3ULL + 0xBDADD3AE59D3A6F3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE0DFD20C6FB92DA9ULL + 0xC852A5BB483D4F32ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8C051ADFFF2CC9A9ULL + 0xEC57D7A277569040ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFB60409B9C38772FULL + 0x935B834B791620C3ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3517U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 2850U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1859U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4470U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 661U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 2345U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 13915875634607599122U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aIngress, 58U)) + 1695770381382411673U) + aNonceWordO;
            aOrbiterG = ((aWandererK + RotL64(aCross, 51U)) + 3709105579778295511U) + aNonceWordI;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 7673376335333251804U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 35U)) + 8814147709738503518U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 13451412605350381172U) + aNonceWordK;
            aOrbiterD = (aWandererC + RotL64(aScatter, 29U)) + 6447870234069609538U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13419487997946496825U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5478309847615220345U;
            aOrbiterG = RotL64((aOrbiterG * 12953043149543448765U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3635184969215610049U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 12527903812035294828U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12540800512035534967U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1684685110885338814U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 12860354576326835090U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12743745087733307255U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9081823570147481835U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14369321778210049109U;
            aOrbiterD = RotL64((aOrbiterD * 17865953349448767035U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11518132079084873250U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11893535026126957389U;
            aOrbiterH = RotL64((aOrbiterH * 15751374986135615095U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7084079180579206226U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2999676609847603277U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14602698397511266403U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17683445810614029153U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11576460512964896969U;
            aOrbiterC = RotL64((aOrbiterC * 5243651036457051155U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterC, 43U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + aPhaseDWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterF, 58U)) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 21U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 29U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8481U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 5701U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10731U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 7636U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10488U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6370U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 7262U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 40U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 11U)) + 5295352595333316211U) + aNonceWordO;
            aOrbiterC = (((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 2341795367042042605U) + aNonceWordG;
            aOrbiterF = (aWandererA + RotL64(aScatter, 29U)) + 10122175780504033663U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 10084612804696198554U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 5U)) + 16470424309851045971U) + aPhaseDOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aIngress, 54U)) + RotL64(aCarry, 53U)) + 656016130975227994U) + aNonceWordH;
            aOrbiterD = (((aWandererB + RotL64(aCross, 19U)) + 15313268829659834317U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3795220914993923394U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14044442220988813825U;
            aOrbiterF = RotL64((aOrbiterF * 3270650852546606835U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3804224626734584802U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7980006306010255693U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13958505239726088561U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13746830564584711549U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11852212099729274845U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2164880979318247855U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9083223471018084847U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13706723820703853346U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11361854103656219887U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1713819986642275223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1382000168233902914U;
            aOrbiterI = RotL64((aOrbiterI * 3894160765130198157U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4540474625764565485U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1756168174375757220U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 12739160208010092017U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1409297070183609309U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6082750101445444357U;
            aOrbiterD = RotL64((aOrbiterD * 17438740230251860935U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterF, 58U)) + aNonceWordP) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 10943U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 16331U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15296U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 10955U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((aIndex + 14570U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (((aWandererA + RotL64(aScatter, 3U)) + 12206125048349568300U) + aPhaseDOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 35U)) + 5843520589343188818U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 21U)) + 12195046124287121687U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 12U)) + RotL64(aCarry, 11U)) + 16769779119214020640U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 5257603646260695833U) + aNonceWordA;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 8523523946234886745U) + aNonceWordO;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 29U)) + 7316024684200084096U) + aPhaseDOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11996978575084115207U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15491711479085513628U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15136690392026011819U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6036648530996821484U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 926323222234121863U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 6639661141258803779U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2700323841295743492U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5852273765810284935U;
            aOrbiterC = RotL64((aOrbiterC * 16665696735016345215U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11697397483133538067U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17777142964957007194U;
            aOrbiterA = RotL64((aOrbiterA * 6338967222543284999U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10892176201151170298U) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11759700374509499684U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14247697264744736081U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11343756773329590643U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 15785048929757652350U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 17208103574389502597U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 7508839228498497238U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13088508510402094665U;
            aOrbiterB = RotL64((aOrbiterB * 15730279447009669103U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 53U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA) + aNonceWordI) + aPhaseDWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 30U) + aOrbiterA) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterA, 47U));
            aWandererF = aWandererF + ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + aNonceWordM);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 30U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererB, 38U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 21812U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 16908U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 20314U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18556U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 20545U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 35U)) + 15904465836916519864U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 21U)) + 17725629806317789307U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 27U)) + 13794170125914914828U) + aPhaseDOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 2149055907476874332U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 5342047776745074649U) + aNonceWordN;
            aOrbiterD = ((((aWandererD + RotL64(aPrevious, 58U)) + RotL64(aCarry, 23U)) + 8268148484060546838U) + aPhaseDOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aWandererC + RotL64(aCross, 5U)) + 10821151364028563719U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4294213820894407378U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10884726101307943090U;
            aOrbiterA = RotL64((aOrbiterA * 1116128870387229159U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16432210042202444824U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15196602644336228055U;
            aOrbiterD = RotL64((aOrbiterD * 12680438355124070237U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14117787670220328165U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 219833877949480215U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10736293047771972173U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3326396981881473962U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 14918513066311426279U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14269763278564574663U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11795234681370163206U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3068267285352664813U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 15746255933920904619U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 245233356957999496U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 709926406353796673U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 13627039596842073595U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5378105439430271038U) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10114555061122044430U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5351295043424885549U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 60U)) + aOrbiterI) + aNonceWordK) + aPhaseDWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 34U) + aOrbiterK) + RotL64(aOrbiterJ, 41U));
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 23363U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneB[((aIndex + 24367U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 21950U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24321U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneA[((aIndex + 23163U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCarry, 4U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (aWandererD + RotL64(aCross, 35U)) + 3684295017013759987U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 4U)) + RotL64(aCarry, 23U)) + 6740408842457292881U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 4563975890702399441U) + aPhaseDOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 797804144825287940U) + aNonceWordP;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 57U)) + 2763779540450101303U) + aNonceWordB;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 19U)) + 13211846164102089685U) + aPhaseDOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 47U)) + 15214578447281401982U) + aNonceWordG;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13745208628754232427U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17358621225969190747U;
            aOrbiterD = RotL64((aOrbiterD * 5325024317338823061U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 779739369960480023U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4370963533701407813U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3123135216876641039U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6061333005507739975U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3589705340762734456U;
            aOrbiterJ = RotL64((aOrbiterJ * 16499293983611196967U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10607697666369230567U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9356757995305239271U;
            aOrbiterG = RotL64((aOrbiterG * 10945513661439954731U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10093033335903048138U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11037328061699834100U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 11189760551792389605U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 558431161176115540U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17795680919453449358U;
            aOrbiterB = RotL64((aOrbiterB * 3910117359996283803U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6096779391116214109U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17594243286880690775U;
            aOrbiterK = RotL64((aOrbiterK * 12655610181937429915U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 56U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 40U)) + aOrbiterC) + aNonceWordJ);
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterG, 27U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterD) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + aPhaseDWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29648U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((aIndex + 27710U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 32739U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28138U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29720U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 44U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 4752759164691497960U) + aNonceWordM;
            aOrbiterC = ((aWandererH + RotL64(aCross, 58U)) + RotL64(aCarry, 3U)) + 12088872623537639782U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 29U)) + 3734943577379734227U) + aPhaseDOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 8854778183012444234U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 21U)) + 16948373492893967275U) + aNonceWordB;
            aOrbiterG = (((aWandererE + RotL64(aCross, 13U)) + 7962415690046184385U) + aPhaseDOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aWandererI + RotL64(aIngress, 51U)) + 1872682375669714454U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7776801806943853566U) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16665439117257230732U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6866375628213114965U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11088186766134265676U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10850237991780969350U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7547414856143095121U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6464817712131305812U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 244557182884209844U;
            aOrbiterC = RotL64((aOrbiterC * 2394270354887582889U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13261563971157415841U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2323811103717827362U;
            aOrbiterG = RotL64((aOrbiterG * 11483723582415081925U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12338803568475493422U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2811342930111104982U;
            aOrbiterJ = RotL64((aOrbiterJ * 5020981755203607757U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5554497011738996057U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12712169745460598698U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1985586486150377769U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 17415058661427002973U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9430421222715343818U;
            aOrbiterB = RotL64((aOrbiterB * 10321140659099470811U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 6U)) + aOrbiterC);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aNonceWordK) + aPhaseDWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterA, 19U)) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterG, 51U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 22U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA22142A1510DBB79ULL + 0x903FE13647F9BD2AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDE4EACFBE5E6276DULL + 0x9781A22C54D9421DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD5CBE1C9B283D16BULL + 0xB877C7A41EFDDC9AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFDEC84C0845C3AD1ULL + 0x89AC2D1181F28C2AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE6794D306D224197ULL + 0xF973AA5A04E517EDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9F92DF7D77411537ULL + 0xAA864957A0E7FCA9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCA40FB3431E95801ULL + 0xF98802F8CF908CFDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAEEBD81F87256C53ULL + 0xA8E2587F13F7A77AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x80033A67B7A94BE3ULL + 0xDD10712124827252ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCF67330EC14C5847ULL + 0x8A474C5B8205706AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB85DEAC13216565BULL + 0xBA292AAC737C21B2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE6A3DD534DBEE485ULL + 0xB200170382013C47ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBC705E6B0C772753ULL + 0xBD41360EB2599085ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA83C358A6F3392B7ULL + 0xC84C03BA1CECEE23ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF19D830BCD7F1E15ULL + 0xA449F12FAF178277ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA819FF9CD4DE1CC3ULL + 0xB4FA9630EB05F84FULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 1078U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((aIndex + 824U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4695U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3099U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4183U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1070U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 51U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (aWandererI + RotL64(aPrevious, 11U)) + 439898681482066326U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 48U)) + RotL64(aCarry, 41U)) + 17362083676671776094U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 37U)) + 6418499837265155024U) + aNonceWordN;
            aOrbiterI = (aWandererA + RotL64(aCross, 51U)) + 17262244253027454972U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 53U)) + 2382066162993139503U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 14345808395587174135U) + aPhaseEOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 21U)) + 7534743166385552851U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 16994453324688523966U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 39U)) + 7079553728544045092U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 6U)) + 3562822704508440641U) + aNonceWordA;
            aOrbiterC = (aWandererK + RotL64(aCross, 57U)) + 13990892681975857821U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1796728922368577238U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6605161260520067178U;
            aOrbiterK = RotL64((aOrbiterK * 8147537646591674091U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13994083795942328918U) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 6144523182899107711U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4153879991344611283U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12247462325297436642U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1065809332002012789U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5496601177032953251U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10147919864511540753U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17138553441127273354U;
            aOrbiterI = RotL64((aOrbiterI * 5773875596275267871U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2653924016109573974U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6254416952351699582U;
            aOrbiterJ = RotL64((aOrbiterJ * 12756861659704947257U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 813046408080197079U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 9624466135414123483U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 6960320253124395015U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 972586705850825744U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 155283774901960223U;
            aOrbiterF = RotL64((aOrbiterF * 9928051687724257041U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 18200100644751360406U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1168426822045686004U;
            aOrbiterC = RotL64((aOrbiterC * 5867027156069481313U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2271564377169233643U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1896317305868283986U;
            aOrbiterA = RotL64((aOrbiterA * 8080751157990019287U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10209708407397294552U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 947585551223387294U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 15339472308062247067U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12313594490465462211U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 439898681482066326U;
            aOrbiterE = RotL64((aOrbiterE * 12336632799055203705U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterA) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + aNonceWordC) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterH, 60U));
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterE, 57U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterF, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 37U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 26U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 48U) + aOrbiterE) + RotL64(aOrbiterH, 51U)) + aPhaseEWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 6477U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneC[((aIndex + 8131U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7770U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 9313U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 8529U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7563U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5759U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 36U)) + RotL64(aCarry, 11U)) + 2168513956284366370U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 19U)) + 10290361969974613111U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 11U)) + 15673836275828498050U) + aNonceWordK;
            aOrbiterB = (aWandererA + RotL64(aCross, 21U)) + 16600540024145812236U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 5U)) + 9428052101528111892U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 27U)) + 12763657928312763377U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 29U)) + 10751286982008662485U;
            aOrbiterK = (aWandererE + RotL64(aCross, 3U)) + 1708230173038057979U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 41U)) + 4011389705422783816U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 11704428328093077714U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 51U)) + 2055336619674699284U) + aNonceWordC;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1870865272102705804U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3574214263751923179U;
            aOrbiterF = RotL64((aOrbiterF * 13132083406834413563U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 984611970726966186U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15207945449947643672U;
            aOrbiterA = RotL64((aOrbiterA * 9539470161576639981U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4181398506373973169U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15222345431506025949U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6925143692628659467U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15023513452326240962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14965669361708810699U;
            aOrbiterH = RotL64((aOrbiterH * 587008860996713147U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7985755518735406360U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 225592097619240187U;
            aOrbiterI = RotL64((aOrbiterI * 2313509354133400439U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3659537916566939383U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17043668033610689611U;
            aOrbiterD = RotL64((aOrbiterD * 10797634709118100773U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10217321522161675848U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8013663869536146842U;
            aOrbiterC = RotL64((aOrbiterC * 2293233079384777175U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13762445330867496042U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2692400019659269106U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 167704184292219399U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 18232551682424867647U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 14785847596876239854U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 4569180925037758487U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5910282247522389536U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16556038638738871204U;
            aOrbiterK = RotL64((aOrbiterK * 18356922295088260901U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 141620663839815754U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2168513956284366370U;
            aOrbiterB = RotL64((aOrbiterB * 8605382725635471683U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 60U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterA, 44U)) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterA, 47U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterE, 5U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 21U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 19U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterG, 3U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 22U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 15593U)) & S_BLOCK1], 44U) ^ RotL64(aInvestLaneA[((aIndex + 13406U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 15397U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15638U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneC[((aIndex + 16139U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 40U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 19U)) + 11998579547770778580U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 14U)) + RotL64(aCarry, 23U)) + 8409465187298704610U) + aNonceWordL;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 11U)) + 3470222286110333500U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 5704486785203069994U) + aNonceWordF;
            aOrbiterG = (aWandererE + RotL64(aCross, 27U)) + 10334944660253279633U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 7626852700722567477U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 50U)) + 14631310754943209743U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 5U)) + 807160297237854120U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 3U)) + 5624154783624196107U) + aNonceWordI;
            aOrbiterD = (aWandererK + RotL64(aScatter, 21U)) + 4971444394698940423U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 41U)) + 6340057638461027062U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9003019862787819481U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13632057463595873033U;
            aOrbiterK = RotL64((aOrbiterK * 12575202147280216765U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12766104026871797746U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4062118445824915939U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 13130770039048080701U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5258212525426469978U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9956946981015983939U;
            aOrbiterA = RotL64((aOrbiterA * 8106382657040497669U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10837606223056473999U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13292864885504191134U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 4445739587553669471U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 166087925900318658U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6786842221885441388U;
            aOrbiterE = RotL64((aOrbiterE * 4411147600413147773U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16888086378070246404U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5240855484445974002U;
            aOrbiterG = RotL64((aOrbiterG * 402652898573422271U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6874866669211571608U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 732890824978127460U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3776365957702257453U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5541380495707308058U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17947326584411475765U;
            aOrbiterI = RotL64((aOrbiterI * 10920952349981652899U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15060679340045767910U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1675974028461383576U;
            aOrbiterF = RotL64((aOrbiterF * 15127962310365242819U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 226889112033170368U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4290719734244011388U;
            aOrbiterH = RotL64((aOrbiterH * 6453598182035414143U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7712233480730639084U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 11998579547770778580U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 11599893373156816375U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + aNonceWordJ);
            aWandererI = aWandererI + (((((RotL64(aCross, 43U) + RotL64(aOrbiterF, 27U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordD) + aPhaseEWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 18U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterA, 11U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterB, 53U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterH, 5U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 40U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21116U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneA[((aIndex + 16412U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17803U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18610U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneD[((aIndex + 18994U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 47U)) ^ (RotL64(aCarry, 60U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 21U)) + 4179952823252098240U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 3U)) + 3745613452332101749U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 2955689793395307176U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 12U)) + 5639060180251322019U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 7901969163853586463U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 53U)) + 2242166787816318119U) + aNonceWordP;
            aOrbiterD = (aWandererB + RotL64(aCross, 29U)) + 5239936443960750064U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 35U)) + 13939136954732185558U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 39U)) + 17058884136712717463U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 18148618660054585941U) + aNonceWordC;
            aOrbiterG = ((aWandererC + RotL64(aCross, 10U)) + 7022023484530327814U) + aPhaseEOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7722084537340095637U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11764151879690934182U;
            aOrbiterE = RotL64((aOrbiterE * 12264384877711365655U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16412785901758144708U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9666718667728274824U;
            aOrbiterF = RotL64((aOrbiterF * 10865799822751771795U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4307127540152109364U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2457646804702647606U;
            aOrbiterB = RotL64((aOrbiterB * 6340030928007058595U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3179394870088602208U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 504977947273774249U;
            aOrbiterJ = RotL64((aOrbiterJ * 16190282058883481551U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16182729401018310837U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 7110817020445860609U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 13371352088428584087U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12960656706837391973U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7103806893724395904U;
            aOrbiterH = RotL64((aOrbiterH * 14365984439655979791U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1248300178080633527U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7195473175424961337U;
            aOrbiterG = RotL64((aOrbiterG * 4633558992739305045U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13007951568242991449U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10296811247653636372U;
            aOrbiterC = RotL64((aOrbiterC * 16469682651380549395U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13922797949001028335U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16773545425463040155U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 10639282630227832397U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2888887140296117803U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10279517418046269817U;
            aOrbiterK = RotL64((aOrbiterK * 8600355360339461535U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17303373436784809093U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4179952823252098240U;
            aOrbiterA = RotL64((aOrbiterA * 3675754609699406437U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 18U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 11U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 14U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterF, 19U)) + aNonceWordB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + aNonceWordD) + aPhaseEWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterB, 38U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 5U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 29U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 58U) + aOrbiterF) + RotL64(aOrbiterG, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererB, 6U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22693U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneB[((aIndex + 23083U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 25631U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23651U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26938U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22088U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 27U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 14U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 39U)) + 6771552164800695068U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 12131763371571322040U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 3326182381395522013U) + aNonceWordG;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 3U)) + 12288775097697156383U) + aNonceWordA;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 29U)) + 5195948373449796741U) + aNonceWordL;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 43U)) + 14404044002250137144U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 27U)) + 11142382920035825426U) + aNonceWordN;
            aOrbiterK = (aWandererD + RotL64(aScatter, 51U)) + 2967149520256475485U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 36U)) + 1470907369577818097U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 19U)) + 9231668148004163910U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 21U)) + 13078929163913892386U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9485274692075657877U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12216951187543631673U;
            aOrbiterF = RotL64((aOrbiterF * 6571066246507310805U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6933334652581744234U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17260276102423580920U;
            aOrbiterB = RotL64((aOrbiterB * 7796879893790990605U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 387767848169714392U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8597538259308082638U;
            aOrbiterK = RotL64((aOrbiterK * 4888054690557707241U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 7996708724489146033U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15357384191688149939U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 9827691726832491373U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17739222908739454637U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1614322333281471170U;
            aOrbiterC = RotL64((aOrbiterC * 7063116837752240891U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4531604274893197209U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3453280714992341288U;
            aOrbiterI = RotL64((aOrbiterI * 8390029711127907805U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 116623650872661533U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6565636510115095988U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 9691897067492501177U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10303258439817808058U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10917642773040237611U;
            aOrbiterG = RotL64((aOrbiterG * 10232856828372963363U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2087058228468680821U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3691125545393861889U;
            aOrbiterA = RotL64((aOrbiterA * 1768745056298937903U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9240209357066002219U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7645250700232422804U;
            aOrbiterE = RotL64((aOrbiterE * 6762116797395687607U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9859862257084218280U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6771552164800695068U;
            aOrbiterH = RotL64((aOrbiterH * 11063630807191661109U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + aNonceWordH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 48U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterF, 53U)) + aOrbiterK);
            aWandererD = aWandererD + (((((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 35U)) + aNonceWordI) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterG, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterH, 23U));
            aWandererC = aWandererC + ((RotL64(aIngress, 10U) + RotL64(aOrbiterI, 11U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterB, 46U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30270U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 27589U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 32006U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30328U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27327U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (aWandererH + RotL64(aPrevious, 37U)) + 12136097566601676613U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 57U)) + 7969431322248040056U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 39U)) + 10530676021510553889U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 11U)) + 8740777303075445264U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 57U)) + 13249434169895564739U) + aNonceWordA;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 15529577005925628472U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 41U)) + 344627093687331562U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 35U)) + 8824277416519988893U) + aNonceWordE;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 23U)) + 5636276438449709875U) + aNonceWordO;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 44U)) + RotL64(aCarry, 37U)) + 2079413361031851552U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 3U)) + 7807998179168655561U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13589392896232029112U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10733011474804473996U;
            aOrbiterJ = RotL64((aOrbiterJ * 361749145931578805U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15934162328347805968U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7573511217796245232U;
            aOrbiterF = RotL64((aOrbiterF * 10694563909931636155U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4828475187337891975U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13284974329890393113U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10831075817642374287U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13173869918669643112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15841507674783398167U;
            aOrbiterK = RotL64((aOrbiterK * 15632933198136963277U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14168272451055700516U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11134471485501999898U;
            aOrbiterA = RotL64((aOrbiterA * 8019507184494591705U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2611858916687822610U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17863271539727513641U;
            aOrbiterH = RotL64((aOrbiterH * 4987884722174985677U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8874401993454249066U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5131480593493950665U;
            aOrbiterG = RotL64((aOrbiterG * 8585874663602346121U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9366563022381918996U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7890729519928340296U;
            aOrbiterC = RotL64((aOrbiterC * 11428572374057899517U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 131774386529223292U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4108356674478240148U;
            aOrbiterE = RotL64((aOrbiterE * 2492753294539081613U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7651738365157869789U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2745458108574051004U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 2175955806036373729U), 41U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 10492013124307434604U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12136097566601676613U;
            aOrbiterI = RotL64((aOrbiterI * 13128652803485742119U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 34U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterD, 58U)) + aNonceWordB) + aPhaseEWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterK, 41U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 44U) + aOrbiterH) + RotL64(aOrbiterJ, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterC, 47U));
            aWandererI = aWandererI + (((RotL64(aCross, 24U) + aOrbiterF) + RotL64(aOrbiterB, 24U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterD) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB3812312859D59FDULL + 0xE7878F27F6F902DEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCDF67A44BB382ADDULL + 0xFBF5444B09B9324DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE701479B3F0FF8F9ULL + 0xBA7B31084293FEC9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x93D3930CA09B9271ULL + 0xA530447C89C5A1EDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB66F509ED8785BCBULL + 0xBA96532E6A11F47AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x86EE5B6120AF51C3ULL + 0xCC33E8666E492311ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCF41EA20197C3877ULL + 0xC5B931321438983DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9CBAEBA7D9B00735ULL + 0xFC77FA7822226FA4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD63CBC0086D54BC5ULL + 0x9C40DE8F5FF2DD5CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA477103DC49B7F49ULL + 0x91F77CE8DB46108AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDB1E7F8256FE2F7FULL + 0x97C174B0305BAD65ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xECD6222F03564F2DULL + 0xEBAB6B613A62C7B7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA060849A1D8CB703ULL + 0xCA0B2CB7CB366F74ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA09EF5C7F6A8F081ULL + 0xC24D7A415E4D7778ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEF607B08EEFDD0DFULL + 0xC2FE9F62E80FEA7FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA13762E19F525A23ULL + 0xA3645F265F594772ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneC, aWorkLaneD, aInvestLaneD, aSnowLaneD, aWorkLaneC, aExpandLaneA, aInvestLaneC, aExpandLaneB, aInvestLaneA, aExpandLaneC, aSnowLaneB
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3323U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 5338U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 4062U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4708U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5359U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 2966U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 19U) + RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 14214886793361825363U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 47U)) + 17267959031078766320U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 16436067429484887644U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 19U)) + 9885951769332633820U;
            aOrbiterH = (aWandererE + RotL64(aCross, 52U)) + 12971711341813893304U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 29U)) + 199970353398450154U) + aNonceWordH;
            aOrbiterD = (aWandererA + RotL64(aScatter, 57U)) + 1237341696444162094U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 39U)) + 7991128854417613360U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 23U)) + 14809029847149045833U) + aNonceWordN;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2559509556915775947U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14336829730147834160U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15103242520064900873U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8853631886733610440U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 13346159398673246914U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 13660497151446983393U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12121095718571872976U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16239781125815589804U;
            aOrbiterG = RotL64((aOrbiterG * 5157009090454962231U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9051377033794324106U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13805815136723461780U;
            aOrbiterE = RotL64((aOrbiterE * 571129481747181357U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14849157800322754413U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18116651528452542634U;
            aOrbiterB = RotL64((aOrbiterB * 3638480428016835537U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4105057226952948599U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5911714320560994391U;
            aOrbiterA = RotL64((aOrbiterA * 1796514171654961389U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4439149331729987587U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10278532228230163632U;
            aOrbiterD = RotL64((aOrbiterD * 17428224919864716517U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2342456582668741750U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2360578572554664800U;
            aOrbiterH = RotL64((aOrbiterH * 1108428466956691925U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 12132934875391401246U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17213278726790245812U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 11904899990681410419U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 23U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 35U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 60U)) + aNonceWordG);
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 27U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + aNonceWordB) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 4U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 9737U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 7255U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8548U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 7415U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7494U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5532U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 8110U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 12U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 13687218104610230596U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 29U)) + 6841550124960692709U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 19U)) + 17418968668458764131U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 23U)) + 8303537912696948204U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 4U)) + 12376614417285936537U) + aNonceWordB;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 35U)) + 14215749063579232654U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 4111736931433665347U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 11250375934571631522U) + aNonceWordP;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 60U)) + 5367367837773331275U) + aNonceWordI;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15514089192382674434U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1475991716685034960U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 17720681295551650891U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5531622777788629748U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8363822215908303335U;
            aOrbiterB = RotL64((aOrbiterB * 17850203366840994883U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3741256932685720414U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11634667238062155772U;
            aOrbiterK = RotL64((aOrbiterK * 15925089729784547403U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 18180546911210417155U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5123234656838556335U;
            aOrbiterE = RotL64((aOrbiterE * 15362857462853398025U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11215734271189250284U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16863747802158398092U;
            aOrbiterC = RotL64((aOrbiterC * 1828035970246160023U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9859050606636646323U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9331300036643654675U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 2502263410556166281U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15028845665427209759U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8916444839488901676U;
            aOrbiterJ = RotL64((aOrbiterJ * 6646561894156038791U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8024631140949068570U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1116378858490660031U;
            aOrbiterI = RotL64((aOrbiterI * 4247798531910227367U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5066486214537899212U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9346312092322423057U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13443190089768875191U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 4U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterA, 28U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + aNonceWordN) + aPhaseFWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordD) + aPhaseFWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterE, 42U));
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterK, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 56U) + aOrbiterC) + RotL64(aOrbiterB, 37U));
            aWandererB = aWandererB + ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 13805U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 13213U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 14803U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12549U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11222U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 12U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (aWandererA + RotL64(aScatter, 23U)) + 16200278595895089008U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 58U)) + 1029614154810465897U) + aNonceWordO;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 7129562468705441295U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 14388903902433951274U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 35U)) + 1013568949315967455U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 19U)) + 3128823373497815651U) + aNonceWordN;
            aOrbiterA = (((aWandererG + RotL64(aCross, 43U)) + 14525694606889470589U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 28U)) + RotL64(aCarry, 43U)) + 14443983602196782887U) + aPhaseFOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 39U)) + 12244220415328641190U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10477159225338766614U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2842870123078131566U;
            aOrbiterJ = RotL64((aOrbiterJ * 11522265477555954071U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 8621138818955849917U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5038396344400303181U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14636756322207385447U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2768613802894372496U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2027754864051410015U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 2461322540050569287U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2848088309172056399U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15017458513904884651U;
            aOrbiterI = RotL64((aOrbiterI * 9926904679902843055U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 9079797279596336139U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 15424866642305110811U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12912331089970158845U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13751764050290602740U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7694557131324740282U;
            aOrbiterK = RotL64((aOrbiterK * 14980807690491467023U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3508673897305667669U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3600868397311393233U;
            aOrbiterC = RotL64((aOrbiterC * 5165032044164139165U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1222655844979128996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2257342337168905875U;
            aOrbiterF = RotL64((aOrbiterF * 6198995971182272119U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6290990717563682725U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15308494772443447109U;
            aOrbiterH = RotL64((aOrbiterH * 1925593111157842325U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterI, 28U)) + aNonceWordJ);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterC, 3U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 43U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + aNonceWordG);
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 20U) + aOrbiterF) + RotL64(aOrbiterK, 23U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 52U)) + aOrbiterF) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19044U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneC[((aIndex + 20786U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 20185U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 21239U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 16883U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 38U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 37U)) + 4751694786009671052U) + aNonceWordN;
            aOrbiterH = (aWandererG + RotL64(aScatter, 52U)) + 16362725160370844224U;
            aOrbiterD = (aWandererC + RotL64(aCross, 11U)) + 6360885380915941057U;
            aOrbiterA = ((((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 5154536007972297036U) + aPhaseFOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 9362540581874808253U) + aNonceWordG;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 27U)) + 13902493871525612934U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 41U)) + 10208452885367546542U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 4U)) + RotL64(aCarry, 19U)) + 3117030377279160998U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 57U)) + 17286247690414027870U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3930314320040949141U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7289525252391668404U;
            aOrbiterD = RotL64((aOrbiterD * 15452162299105112187U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3434167955466809185U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17852573095128575663U;
            aOrbiterB = RotL64((aOrbiterB * 1485660158767033425U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6137259687928853253U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 13992510605237574698U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 15346263295995333395U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6470556523400123474U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4333255670390099293U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11089933812030082647U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7700424876430257995U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 16920736951239453071U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 8920407493132380497U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1635071690430295730U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9966700845966398620U;
            aOrbiterI = RotL64((aOrbiterI * 17210048121896546867U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9833458070123027075U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1990346556486746432U;
            aOrbiterK = RotL64((aOrbiterK * 8704943923474148699U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13339523466436517327U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5018264760406215603U;
            aOrbiterH = RotL64((aOrbiterH * 2769197961801783627U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 123427497520755346U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4535841104215792886U;
            aOrbiterA = RotL64((aOrbiterA * 1417676310539177131U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 26U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 6U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 57U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 14U) + aOrbiterK) + RotL64(aOrbiterA, 19U));
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 23U)) + aOrbiterF) + aNonceWordF);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 10U)) + aOrbiterK) + aNonceWordM) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterK, 35U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 46U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 41U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneA
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27281U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneD[((aIndex + 27196U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 22216U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21896U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneC[((aIndex + 26039U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 48U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 1866656689936219099U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 50U)) + 2312314528139448289U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 57U)) + 3554037526469185237U) + aNonceWordL;
            aOrbiterH = ((aWandererD + RotL64(aCross, 39U)) + 405707755060974111U) + aNonceWordJ;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 11U)) + 1862976326004007697U) + aNonceWordF;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 12992483065443288263U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 21U)) + 3793854946371595197U;
            aOrbiterI = ((((aWandererJ + RotL64(aCross, 6U)) + RotL64(aCarry, 11U)) + 4244007978867369382U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aWandererA + RotL64(aScatter, 43U)) + 10280867500312580308U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 472563452959164242U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12041770406895816553U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17811798500132002631U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6118634015704900486U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13637107920449233307U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 17712028184714868053U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16673735670669318830U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8602681273646630496U;
            aOrbiterK = RotL64((aOrbiterK * 6995213887710749241U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7683264695930369476U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 9146674871199188218U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7403427067419261981U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3012935612827493084U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1259789268731661945U;
            aOrbiterB = RotL64((aOrbiterB * 2372843620327050137U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5623690455471160780U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18355567776031865462U;
            aOrbiterH = RotL64((aOrbiterH * 9553862670107886679U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7705134893833304792U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4435192506444773834U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5249651218395299501U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6204683785806409075U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17886971535016484255U;
            aOrbiterI = RotL64((aOrbiterI * 6047216474762933535U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4430578901091376829U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 607557685798141547U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 12342665567201483107U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 4U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 23U)) + aOrbiterG) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 19U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterE, 13U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterK, 5U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterI, 51U));
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 4U) + RotL64(aOrbiterH, 30U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aSnowLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aSnowLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28514U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 32537U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 27998U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28904U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 31934U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 11U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 39U)) + 17668251151213543491U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 18U)) + 16101602509895104517U;
            aOrbiterA = (aWandererI + RotL64(aCross, 43U)) + 9083915270773304935U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 51U)) + 12810720730318214811U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 47U)) + 18113428002071925621U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 1582208899354109878U;
            aOrbiterE = (aWandererC + RotL64(aCross, 56U)) + 4180688104819188154U;
            aOrbiterD = ((((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 8954598189262820611U) + aPhaseFOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 15360094153175355879U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8383954114668216260U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15626783326234049197U;
            aOrbiterA = RotL64((aOrbiterA * 15058420415480073793U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10609978564404958066U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17656516608997517984U;
            aOrbiterJ = RotL64((aOrbiterJ * 4590620354119899777U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 760077259110786536U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 3597338735888033063U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6548831472863517621U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4431777844935985157U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10710423172154671296U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 16267496318491473315U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10240882795242085185U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7826053487019825891U;
            aOrbiterD = RotL64((aOrbiterD * 15053729937684375907U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9418883403715727353U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11507423614799075545U;
            aOrbiterC = RotL64((aOrbiterC * 16189463984557044693U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11545217316421066655U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 617921402135485341U;
            aOrbiterH = RotL64((aOrbiterH * 8182920764965471653U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14456933220749921009U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7990243583564535387U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 5994900368027985469U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14023633125757654751U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11319146808574958827U;
            aOrbiterE = RotL64((aOrbiterE * 13676159969338309307U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 56U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + aNonceWordH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterF, 14U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterD, 43U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + aNonceWordN) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterA, 28U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterK, 39U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD154B45993504985ULL + 0xE82CF3CED986144FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDAE79379B5125DA7ULL + 0xD0943FE909F91329ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC0917E8C778E7833ULL + 0xF2B9923D2C577E47ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC784F9F9B2B3BD53ULL + 0x9781E4DD79578AFAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD7A51E3C6401231FULL + 0xDC9EEF7AABAB007BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBC1452A9D55D7237ULL + 0xAA0CCD416F8769C9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x85837CDADA93FFD9ULL + 0x825696237B37E661ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x80DA925475EB7D31ULL + 0x8324AFF2EA0CE198ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAEFAB3D14FD1C40FULL + 0xE5847E5CA29BFF6BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE75E11A8C49E5377ULL + 0xFCF4DFE7BE173DC5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE2539662F76912A5ULL + 0xD2C5C36296F4DFA0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x980522740DDF50F9ULL + 0x808A619DD317C796ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8DC253168A185C47ULL + 0xF054F965DACDFECEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x897FED6ACA47EE1FULL + 0x84541AA9C640DFAEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA2A23178D86CAF2BULL + 0xA695BCC9EC47AE2AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x86CBA9D327D2B76DULL + 0xF97141DDF941768CULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneA, aWorkLaneA, aInvestLaneB, aFireLaneB, aWorkLaneB, aFireLaneD, aExpandLaneA, aFireLaneC, aExpandLaneB, aInvestLaneD, aExpandLaneC, aInvestLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneA
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4817U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((aIndex + 1079U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1559U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1571U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 5205U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 3724U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 10404808878585437255U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 10587858736301591439U) + aNonceWordB;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 23U)) + 1430530909801644435U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 9090938022430118902U) + aNonceWordM;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 29U)) + 12936604311751121235U) + aNonceWordN;
            aOrbiterK = (aWandererH + RotL64(aIngress, 3U)) + 1000583006020232032U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 44U)) + 12352532088997042232U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16723410947058502564U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16614089235313154270U;
            aOrbiterH = RotL64((aOrbiterH * 11530998303573027827U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4245553025593349277U) + aNonceWordA;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 3353146318549477494U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 14246377408238318091U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5935727336135635196U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10312187090293319667U;
            aOrbiterB = RotL64((aOrbiterB * 1395964500396711899U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12192843181244744484U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2542570124502586365U;
            aOrbiterK = RotL64((aOrbiterK * 17222847847573534963U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3315472769469002444U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17512858811783071174U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9070400454074283765U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16633218007427888082U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2502077714838858460U;
            aOrbiterE = RotL64((aOrbiterE * 970762420815997725U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14792910273226469214U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15739513291150783151U;
            aOrbiterI = RotL64((aOrbiterI * 11896279674116906915U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + aNonceWordH);
            aWandererG = aWandererG + (((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 41U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aNonceWordL) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + aNonceWordO) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 60U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 34U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 13U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 52U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneB
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9938U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneC[((aIndex + 6668U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 7224U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneB[((aIndex + 7134U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7746U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8202U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6608U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererK + RotL64(aScatter, 51U)) + 6733949564325516029U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 7304098437143918796U) + aNonceWordA;
            aOrbiterC = ((((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 3923949518391777800U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 14243591003388927124U;
            aOrbiterA = (aWandererE + RotL64(aCross, 3U)) + 18329498724605410406U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 36U)) + 13118172167747037249U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 21U)) + 5272025143849174212U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16075917179214318424U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15263590648674658399U;
            aOrbiterC = RotL64((aOrbiterC * 9918239923411740337U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13730046728289525921U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7703141464499623408U;
            aOrbiterD = RotL64((aOrbiterD * 5886009900621521987U), 47U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 1382279753822135359U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2973369221699098292U;
            aOrbiterK = RotL64((aOrbiterK * 7440242040663550631U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11578274119583013219U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3419411247737896674U;
            aOrbiterG = RotL64((aOrbiterG * 17814942652262802991U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2582783513078999303U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3959762790273529677U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 383974377372162751U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 465795011576934604U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17880826624185821135U;
            aOrbiterB = RotL64((aOrbiterB * 4445949147592860913U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10819659185349413173U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17298208553586835030U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 1965860510614222093U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 34U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 60U)) + aOrbiterC) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aIngress, 12U) + RotL64(aOrbiterG, 23U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterF, 53U)) + aPhaseHWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterB, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14260U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((aIndex + 13128U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 14858U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11002U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12732U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 39U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 898812731947995389U) + aNonceWordP;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 8677347622525527167U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aIngress, 5U)) + 770321564027567654U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 11020474858081526395U) + aNonceWordA;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 29U)) + 17289793580414993470U) + aNonceWordC;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 13U)) + 10111912559295118444U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 54U)) + 8083622125544542011U) + aNonceWordG;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7149858558922988240U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5919683821379905699U;
            aOrbiterH = RotL64((aOrbiterH * 16705119888884231567U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6860902846079238714U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15083517836867542075U;
            aOrbiterI = RotL64((aOrbiterI * 4686657139237578325U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14852868368708376381U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9860233289028878323U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 13418143547952204667U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 772406119079116272U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7971141501337627589U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10168120622976358617U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8478568022896691911U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4027604850785607101U;
            aOrbiterF = RotL64((aOrbiterF * 4826627523578901467U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17199331557841535430U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7515957656979776361U;
            aOrbiterK = RotL64((aOrbiterK * 5468950152869656599U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17138249294921502391U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16236812863923234668U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2925542836624164807U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 44U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 34U) + aOrbiterH) + RotL64(aOrbiterI, 50U)) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + aPhaseHWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterK, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterC, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18987U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((aIndex + 16945U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 17554U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21358U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneD[((aIndex + 20211U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 58U)) + (RotL64(aPrevious, 23U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 3199575576585871314U;
            aOrbiterK = ((((aWandererE + RotL64(aIngress, 6U)) + RotL64(aCarry, 29U)) + 2533378188975571824U) + aPhaseHOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aWandererD + RotL64(aScatter, 21U)) + 6819782112558312658U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 12690060987724798497U) + aNonceWordD;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 41U)) + 7088375139715629606U) + aNonceWordH;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 29U)) + 17785618677423695666U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aIngress, 47U)) + 1714999280296491277U) + aNonceWordA;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17611338506932491624U) + aNonceWordG;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 6475727359297421201U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 15133348244242438069U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2347744591204119530U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 2739317903351401068U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15435029315209475631U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8663535261373274338U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8205245127823536479U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 13857005110466856439U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8916510616749754516U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3944805940148512932U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18082271583211389701U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14094751253118853302U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14094299829196076311U;
            aOrbiterI = RotL64((aOrbiterI * 6370012560657108493U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 3940673811518673802U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3015106523254484839U;
            aOrbiterG = RotL64((aOrbiterG * 9655401190755573379U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15404103131982599922U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1828655763233900875U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 13024358077740310049U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + aNonceWordF);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterE, 28U)) + aNonceWordL) + aPhaseHWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 51U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 13U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + aPhaseHWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 19U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aInvestLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23378U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 27057U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 25946U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24633U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23122U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = ((aWandererJ + RotL64(aCross, 11U)) + 4259993311776766595U) + aNonceWordA;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 2857813330021126753U) + aNonceWordI;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 1345396841329442896U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 320992148982301024U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 53U)) + 5619109532065293074U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 3U)) + 10380157329426706345U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 60U)) + 12449831150625409695U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 7847096607042268396U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11707184096803214678U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1959476948106553973U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9893643746186827088U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 333687403830908774U;
            aOrbiterA = RotL64((aOrbiterA * 17911256836121454271U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13837360705077441580U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4367119682175710689U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10295744669174603401U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1193493435041306784U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15062951612027370606U;
            aOrbiterG = RotL64((aOrbiterG * 2509383510565136549U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16000173839235429105U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15294482444605409961U;
            aOrbiterE = RotL64((aOrbiterE * 1031800997944302665U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5720749055549773527U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17248674962996093668U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 15730637462755795591U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16956840483882091059U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9637715107943515594U;
            aOrbiterC = RotL64((aOrbiterC * 8878362378343603463U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 23U)) + aOrbiterC) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + aNonceWordC);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 60U)) + aOrbiterB) + aPhaseHWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterK, 11U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 35U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27853U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 29095U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 32089U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28850U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((aIndex + 29615U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 13U)) + 1457104756581596530U) + aNonceWordN;
            aOrbiterA = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 6127240317844622874U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 58U)) + RotL64(aCarry, 21U)) + 16492290056044189421U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 10963676850938416468U) + aNonceWordJ;
            aOrbiterC = ((aWandererF + RotL64(aCross, 3U)) + 4872917367399752405U) + aPhaseHOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 23U)) + 15218882377875616148U) + aPhaseHOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 29U)) + 5934166612122118251U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14215280930872003003U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11428034799044600979U;
            aOrbiterJ = RotL64((aOrbiterJ * 12162528943733976177U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5453003654321728726U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14273775120265649389U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5139018128323795309U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 328723770018440271U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13032190719588211088U;
            aOrbiterH = RotL64((aOrbiterH * 13363368478932798315U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2386881543033598494U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1649501123340887116U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11148976582360499033U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16462401546754210583U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1510579201823042227U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16287912400104043275U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6889066000014251983U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11324594596597724357U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 15344987814648586023U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 12237796033168436537U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17306069670330000343U;
            aOrbiterK = RotL64((aOrbiterK * 3167451351403385259U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 42U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterF, 29U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 11U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + aNonceWordI) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ) + aNonceWordC);
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 22U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 430U)) & W_KEY1], 46U) ^ RotL64(aKeyRowReadB[((aIndex + 1096U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1763U)) & W_KEY1], 10U) ^ RotL64(mSource[((aIndex + 676U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 56U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 3621877681473089725U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 40U)) + 4451752751536414717U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 29U)) + 11371625415377772117U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 3U)) + 6046792758881150619U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 8213166120394461682U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 4343156661140422645U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 24U)) + 11105271483234947905U;
            aOrbiterK = (aWandererA + RotL64(aCross, 51U)) + 348904609985341372U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 13U)) + 12924652822526858767U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7461211697358520287U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16551553555297890558U;
            aOrbiterI = RotL64((aOrbiterI * 16432952324635746293U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11908056404140782995U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9147367258259948715U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10777628928376261667U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8876461054692728610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10546855952702525404U;
            aOrbiterJ = RotL64((aOrbiterJ * 10071104785895309677U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4748636139110443794U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 783046909529525098U;
            aOrbiterE = RotL64((aOrbiterE * 8969157702460927215U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16683965945838696665U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12385412690177109575U;
            aOrbiterK = RotL64((aOrbiterK * 10795062772707143187U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8210546822184469023U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13146493623236979963U;
            aOrbiterG = RotL64((aOrbiterG * 13199947810161148155U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13857628148804187115U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7241297989337473475U;
            aOrbiterC = RotL64((aOrbiterC * 16223448508809614229U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 773904571213804946U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7660676598236419707U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14467390638468925567U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16822672435156055469U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6514707119190640433U;
            aOrbiterH = RotL64((aOrbiterH * 7097496727567460535U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterB, 28U));
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterG, 43U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 11U)) + aOrbiterB) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterK, 51U));
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 39U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterE, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 40U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 2898U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3120U)) & W_KEY1], 36U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3537U)) & W_KEY1], 18U) ^ RotL64(mSource[((aIndex + 4612U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 26U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 18U)) + 3917730204724097072U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 1874642340716212824U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 6900165757434854160U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 43U)) + 12750946097023807161U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 34U)) + 6563216048479513594U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 14960240191349450795U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 53U)) + 16306180275951788289U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 39U)) + 6502066618271045547U) + aPhaseAOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aPrevious, 23U)) + 6219852857850888738U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2272931312452845850U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3028929882263199463U;
            aOrbiterK = RotL64((aOrbiterK * 11005324285856805069U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6067393030073568112U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10094809900437037258U;
            aOrbiterI = RotL64((aOrbiterI * 18095564940730322769U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5962414178157074575U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15755563045799129417U;
            aOrbiterA = RotL64((aOrbiterA * 3692603590609922031U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6321455513889880590U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1197435601998121700U;
            aOrbiterC = RotL64((aOrbiterC * 17693996266260557625U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12496949381666299968U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6357070235648527030U;
            aOrbiterF = RotL64((aOrbiterF * 2931486644220862433U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8423760160877540210U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8090246492554850768U;
            aOrbiterG = RotL64((aOrbiterG * 2949407491181921633U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11436635942985063755U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17086363141014359856U;
            aOrbiterJ = RotL64((aOrbiterJ * 10504127577318206801U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10734017887545474935U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 375515325165740779U;
            aOrbiterD = RotL64((aOrbiterD * 9980486695448151709U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5217148491945389821U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14696058217023530058U;
            aOrbiterB = RotL64((aOrbiterB * 11026674782236654799U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterD, 3U));
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterI, 27U)) + aOrbiterK) + aPhaseAWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterD, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterA, 38U));
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 53U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 18U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6658U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadB[((aIndex + 6125U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6748U)) & W_KEY1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6580U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7348U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 24U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererE + RotL64(aCross, 53U)) + 701291026547470433U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 34U)) + 17283292650462111643U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 11U)) + 9969124091931303406U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 21U)) + 889176772718046988U) + aPhaseAOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 6054541844643748084U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 14703226235143028132U;
            aOrbiterK = (aWandererC + RotL64(aCross, 57U)) + 7977975878522921062U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 48U)) + RotL64(aCarry, 37U)) + 16894322614172266274U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 3U)) + 12160451749345900570U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10870847008043897470U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8159920947172520247U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4833194641611011805U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2440099120969517932U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2428396147731468007U;
            aOrbiterH = RotL64((aOrbiterH * 9363073341539598441U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2213226274394673479U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7079731443427765333U;
            aOrbiterG = RotL64((aOrbiterG * 16918930776877030559U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 958896789550478970U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10788682955708075458U;
            aOrbiterD = RotL64((aOrbiterD * 913321215613559729U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2003386579317564870U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8419686358774204999U;
            aOrbiterK = RotL64((aOrbiterK * 6547052526438697621U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6989167615157578904U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17636634003643824148U;
            aOrbiterI = RotL64((aOrbiterI * 11038576417283732937U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13824962118933907859U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9543912892587859646U;
            aOrbiterB = RotL64((aOrbiterB * 14736710162285997415U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15729878041027706114U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9542137475454825463U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11420547128115090491U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5327302277575009955U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2707383132257428583U;
            aOrbiterF = RotL64((aOrbiterF * 6120763309390182129U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 22U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 46U) + RotL64(aOrbiterB, 48U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterG, 57U));
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterF, 37U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterE, 41U));
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterG, 19U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterK, 5U)) + aOrbiterD) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterB, 12U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10898U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadB[((aIndex + 9334U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 9006U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 10846U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9277U)) & W_KEY1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8428U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 14U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererA + RotL64(aIngress, 51U)) + 15188686795415908074U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 17310049041983079779U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 8246925977992441471U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 8644260919918112781U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 3U)) + 13401663736874819483U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 29U)) + 7940358935238314973U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aScatter, 43U)) + 13278990328548007839U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 20U)) + 11346868298353840706U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 39U)) + 2374077904806833579U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6978903378645019166U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11951633297870965212U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12778236598654492185U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17398460995357409673U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1215437945597836770U;
            aOrbiterE = RotL64((aOrbiterE * 9322970054123481621U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1878751468043972239U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5343002808239712390U;
            aOrbiterC = RotL64((aOrbiterC * 11878640995447558811U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9884918450053276861U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15894599082080422550U;
            aOrbiterH = RotL64((aOrbiterH * 8359936745539546131U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13917339232771145459U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 18101134009493720683U;
            aOrbiterI = RotL64((aOrbiterI * 15835859435306756387U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3830086372356903769U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15894394599564584010U;
            aOrbiterD = RotL64((aOrbiterD * 9513921913446609263U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5127590955274245812U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 9410946933309720054U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14507476989423060561U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15544384157294987085U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 998801294460434123U;
            aOrbiterJ = RotL64((aOrbiterJ * 5946968142746472745U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 16442095194965452163U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14294936349037516932U;
            aOrbiterG = RotL64((aOrbiterG * 14655345374740882581U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 36U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterD, 42U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterH, 3U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 23U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterG, 52U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12231U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 11342U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12635U)) & W_KEY1], 58U) ^ RotL64(mSource[((aIndex + 11290U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11634U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12444U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13413U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 41U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererI + RotL64(aPrevious, 57U)) + 11410829607777684449U;
            aOrbiterB = (aWandererD + RotL64(aCross, 13U)) + 7502698839700975347U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 48U)) + RotL64(aCarry, 3U)) + 13267685058252106173U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 238242706996630625U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 27U)) + 8184695499511454281U) + aPhaseBOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 12767823220461985403U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 5U)) + 12293198423143850330U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 44U)) + 11149495229952495939U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 19U)) + 7556992689338382800U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3431338808774134649U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16863099140844995099U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 752376661101787919U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17872458049880677604U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16760153457252546974U;
            aOrbiterD = RotL64((aOrbiterD * 11225037229069712805U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3115544493537438408U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4359882942759752958U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 561477566995575801U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13387113067202396536U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12955690074544490161U;
            aOrbiterC = RotL64((aOrbiterC * 12449941770827974511U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15614054443728226807U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1939441328066616114U;
            aOrbiterE = RotL64((aOrbiterE * 4484917074808974359U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4599016263007782537U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9962305629016158048U;
            aOrbiterB = RotL64((aOrbiterB * 1496184427500037279U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8428467674122750557U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3938884087806393439U;
            aOrbiterF = RotL64((aOrbiterF * 12810531094050481761U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6018636830758044658U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 1510372000641305416U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9002834928626918247U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17592782466215337843U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8119921507606870360U;
            aOrbiterG = RotL64((aOrbiterG * 1299795061644535485U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 46U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 10U) + aOrbiterD) + RotL64(aOrbiterC, 10U));
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 29U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterD, 23U));
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterD, 39U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 28U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterF, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14319U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 16083U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14681U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15066U)) & W_KEY1], 5U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13967U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15424U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14770U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 7270044678408187242U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 60U)) + 10192278965379756766U) + aPhaseBOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 17568666746676060748U) + aPhaseBOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 51U)) + 14312927531124963037U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 19U)) + 9825825726152087706U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 13U)) + 9696778570255265896U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 17657841352013417228U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 47U)) + 16207815085909628439U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 4U)) + 1752979206374514227U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10456310689643905854U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16127830548663742550U;
            aOrbiterB = RotL64((aOrbiterB * 4355938404839045417U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2940917376003930842U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7353596864777649953U;
            aOrbiterH = RotL64((aOrbiterH * 7499468723171042005U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12725092740446150705U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5791296650856037010U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 760379251950502133U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1200130368046206150U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16689604428598558547U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13815324235939996623U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14359561591103730856U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3975025843599045263U;
            aOrbiterG = RotL64((aOrbiterG * 5025047888533298617U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14017901732955607601U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10431526786489555196U;
            aOrbiterD = RotL64((aOrbiterD * 10181915874476132407U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7320527073559849223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15333411223710709907U;
            aOrbiterK = RotL64((aOrbiterK * 3488684905528068775U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14302474063321663801U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2104154521019935187U;
            aOrbiterI = RotL64((aOrbiterI * 12944382959742278055U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5167600586916325228U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4566823109447208716U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9997799807454267443U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 30U)) + aOrbiterA) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterD, 57U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 48U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterI, 11U)) + aPhaseBWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterD, 37U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 34U) + aOrbiterG) + RotL64(aOrbiterK, 43U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17999U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 17182U)) & W_KEY1], 50U));
            aIngress ^= (RotL64(mSource[((aIndex + 17107U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19007U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17937U)) & W_KEY1], 3U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17915U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17142U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 26U)) + (RotL64(aIngress, 13U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 37U)) + 12535417189990029950U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 43U)) + 6204401443676390273U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 60U)) + 869613505613154672U;
            aOrbiterG = (aWandererC + RotL64(aCross, 51U)) + 15053590879563855802U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 3U)) + 13338989605204591428U;
            aOrbiterI = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 18306470022403825392U) + aPhaseCOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 1150696349434090218U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 13549541786420596437U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 30U)) + 14302878430259588461U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4660437084477165225U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1653628537860912069U;
            aOrbiterA = RotL64((aOrbiterA * 2624835201155303123U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5594199757006711631U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11008472193138708891U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13645764762027798301U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3668516817279364310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 128159531749679984U;
            aOrbiterH = RotL64((aOrbiterH * 4523246859249826987U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6378674346113979108U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11438762460659123362U;
            aOrbiterG = RotL64((aOrbiterG * 2733309638158283953U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10624263004446482910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12546839706919241411U;
            aOrbiterE = RotL64((aOrbiterE * 11468326687628079347U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8466639576503293921U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5828694979857951504U;
            aOrbiterK = RotL64((aOrbiterK * 7835487310289634515U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16496305151014092976U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 589464613876410567U;
            aOrbiterF = RotL64((aOrbiterF * 13190816610718051897U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4168532743415647825U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15944887793736489375U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17273403561158196717U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11642456814106259483U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1609897693632334867U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12912773555616819941U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 19U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterK, 39U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 52U)) + aOrbiterF) + aPhaseCWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterE, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 22U) + aOrbiterA) + RotL64(aOrbiterK, 29U));
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 10U)) + aOrbiterA) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21758U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 21684U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19778U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 19160U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21022U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19444U)) & W_KEY1], 3U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20257U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 20721U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 5U)) + 16124889768301047791U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 11912338587186717280U;
            aOrbiterB = (aWandererK + RotL64(aCross, 58U)) + 8594012868813114354U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 23U)) + 18281043566156682815U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 16853106130200942302U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 19U)) + 2611212958619673086U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 12U)) + 18039472325066855180U) + aPhaseCOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 14495785571345122046U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 35U)) + 4556063793412832418U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14896419970271244358U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 880028529183500036U;
            aOrbiterB = RotL64((aOrbiterB * 14228281807461251361U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2379557167489415783U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11854373946064529806U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 150755294320438887U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1487252775956449964U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12777924204511625545U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1366019527386994789U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15998631485222477969U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8864212892296191613U;
            aOrbiterC = RotL64((aOrbiterC * 579242788050369815U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17069347835763226743U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7443008171694679791U;
            aOrbiterD = RotL64((aOrbiterD * 748894368884566607U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17334256152350782002U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8986626119086556393U;
            aOrbiterJ = RotL64((aOrbiterJ * 2258172145924120235U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8528180968228358674U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12702290928064582589U;
            aOrbiterF = RotL64((aOrbiterF * 15673603224146737631U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7742438100860023610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3729687240959702198U;
            aOrbiterA = RotL64((aOrbiterA * 3756794766163746783U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 426129097367382096U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 16782175452274911213U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1041477289638333659U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 14U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterD, 47U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterF, 10U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 35U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 23U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 41U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 60U)) + aOrbiterA) + aPhaseCWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + aPhaseCWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23006U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadA[((aIndex + 23397U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22367U)) & W_KEY1], 21U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24471U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24034U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23274U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22026U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneB[((aIndex + 22137U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 40U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 35U)) + 12222235191147985484U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 52U)) + RotL64(aCarry, 39U)) + 16367317014523328414U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 23U)) + 3511378091284703789U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 19U)) + 15247492830966725949U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 57U)) + 7745995913390407897U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 43U)) + 6463593307540108810U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 29U)) + 1101669311005268630U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 12988052764067518580U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 12U)) + RotL64(aCarry, 13U)) + 17717179747434679772U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11662190906682400416U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6563014073547628748U;
            aOrbiterC = RotL64((aOrbiterC * 16967910471722117761U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13099094932059419219U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16342730862261868847U;
            aOrbiterA = RotL64((aOrbiterA * 10988124108686164829U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 16855346813127524624U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6570063128502306944U;
            aOrbiterG = RotL64((aOrbiterG * 4571570049463124831U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 11328352033809240501U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11640986648833160901U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2895830492089678919U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2675226158571501666U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17700531248266458165U;
            aOrbiterK = RotL64((aOrbiterK * 2231403813970188657U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7729597396731910874U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15172374484412053756U;
            aOrbiterJ = RotL64((aOrbiterJ * 149009041406406517U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9178769489257842683U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9020154972097834926U;
            aOrbiterB = RotL64((aOrbiterB * 8910504667566521429U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1317403761217790562U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17151528554929201571U;
            aOrbiterH = RotL64((aOrbiterH * 3735945655450625203U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11621882033959669977U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10289504450815075623U;
            aOrbiterE = RotL64((aOrbiterE * 13365982786836243195U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 44U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 13U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 34U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterA, 39U));
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 46U) + RotL64(aOrbiterG, 28U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26827U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 26104U)) & W_KEY1], 18U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25846U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26997U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27284U)) & W_KEY1], 22U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26179U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26612U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26588U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 5171470532667965920U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 42U)) + RotL64(aCarry, 35U)) + 750549462358682403U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 23U)) + 3325689257577120525U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 19U)) + 18031575461559790826U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 47U)) + 13874739537012288677U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 37U)) + 4250029868785016865U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 8211158803112611161U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 51U)) + 1083939790236786027U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 58U)) + 3446525462376962464U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6973817815000417325U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15230876489676945543U;
            aOrbiterB = RotL64((aOrbiterB * 7737039082964537651U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9359727659738755880U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8775170107816327654U;
            aOrbiterH = RotL64((aOrbiterH * 6910680458261008653U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11958941755525038545U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16966819714283167348U;
            aOrbiterC = RotL64((aOrbiterC * 16363457661846050749U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14556087985619763243U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17915047508377045221U;
            aOrbiterJ = RotL64((aOrbiterJ * 6727635453185130109U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8578745677485367222U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7002181668717618866U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12329703532414955235U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3569939503066735457U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2956247934282522184U;
            aOrbiterK = RotL64((aOrbiterK * 9946650822131152531U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4285180013402474041U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5976239869535619811U;
            aOrbiterA = RotL64((aOrbiterA * 3458095419039067465U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2424524955161695463U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6849595426583763537U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12727902040238318101U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11414890686374886716U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5668287266836153445U;
            aOrbiterE = RotL64((aOrbiterE * 8011885266143066285U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 20U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 24U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterI, 5U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterI) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterE, 60U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 40U) + aOrbiterB) + RotL64(aOrbiterA, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27933U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 27997U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28313U)) & W_KEY1], 57U) ^ RotL64(aFireLaneC[((aIndex + 29689U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27956U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28662U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28692U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 28873U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererD + RotL64(aIngress, 24U)) + 12632404972795375757U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 5351879979055988456U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 47U)) + 3597737727467443413U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 53U)) + 2830846754917852318U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 11U)) + 17311925960294518018U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 46U)) + 2083584640523695383U;
            aOrbiterH = (aWandererK + RotL64(aCross, 19U)) + 15049343611387010158U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 3U)) + 6443050378205811147U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 6021965178697344070U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5080289878758029976U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 576927745306972983U;
            aOrbiterF = RotL64((aOrbiterF * 16008958833683246115U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4728489691382690859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6184355840165758855U;
            aOrbiterG = RotL64((aOrbiterG * 1515043910404156423U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11220539885798595450U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11091438724966718214U;
            aOrbiterH = RotL64((aOrbiterH * 8225347114759391961U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17184210490020062419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2150997767099116408U;
            aOrbiterD = RotL64((aOrbiterD * 8058553821648892499U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7021953562676903717U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17159676348343312834U;
            aOrbiterJ = RotL64((aOrbiterJ * 13877284519668483549U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10367891770525239784U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11922478487264201233U;
            aOrbiterA = RotL64((aOrbiterA * 9195137452661956029U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17815162358981720634U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 9582631251085100284U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11838992994130850483U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 872593750259572264U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17832330100262167302U;
            aOrbiterI = RotL64((aOrbiterI * 1114416841510028467U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16601139856969287418U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14931287111691324985U;
            aOrbiterC = RotL64((aOrbiterC * 16757174577841001179U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 54U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 53U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 37U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 34U) + aOrbiterH) + RotL64(aOrbiterA, 20U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 11U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 5U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterG, 42U)) + aOrbiterI) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterH) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 52U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32479U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30179U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30615U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30335U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32137U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31037U)) & W_KEY1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 48U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererG + RotL64(aIngress, 51U)) + 5088525177670191619U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 46U)) + 9966456257813932112U) + aPhaseDOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 41U)) + 7707646574027146307U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 75480203757681173U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 3U)) + 384659134071835163U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aPrevious, 60U)) + 3158769775373307778U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 17360830943513941272U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 5317278822721604586U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 29U)) + 1371427105215954781U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3162710551223553423U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5332921933853550756U;
            aOrbiterG = RotL64((aOrbiterG * 11709546145149357887U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10572462410297815854U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10234389605554817892U;
            aOrbiterJ = RotL64((aOrbiterJ * 2130374833440291193U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13421365517991380605U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10186643614984034083U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8554471709467808453U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4742438973260817120U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6081590345899008846U;
            aOrbiterF = RotL64((aOrbiterF * 7069396301823124931U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15360092808493795340U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 12186413069553132646U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3815981440611914267U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16756221656224451552U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12232880965861373143U;
            aOrbiterE = RotL64((aOrbiterE * 14196910735715726471U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10090954323470840557U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15615770271463853537U;
            aOrbiterI = RotL64((aOrbiterI * 13544181592829027283U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 556029032505658411U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13311879111583579039U;
            aOrbiterD = RotL64((aOrbiterD * 3924744868168749003U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8646360871497847336U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2064833941982069154U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10016546852137913163U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 38U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 51U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterH, 3U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 34U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterF, 23U));
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 60U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneC, aInvestLaneD, aFireLaneA, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2634U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 4160U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 1366U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3201U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4221U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aScatter, 35U)) + 7948891781097675369U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 13928362874228230226U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 10776180542602258926U;
            aOrbiterB = (aWandererE + RotL64(aCross, 27U)) + 5735115172149470447U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 3U)) + 5353591822981766987U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 20U)) + 562301708107268570U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 10467810247578364868U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 14541630141152308564U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2350076897065139429U;
            aOrbiterF = RotL64((aOrbiterF * 12222554362482034393U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17519109078651162228U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6061035173339902910U;
            aOrbiterA = RotL64((aOrbiterA * 10021905773432907835U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15654836633731000065U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13723521735153718904U;
            aOrbiterB = RotL64((aOrbiterB * 14459516479283070563U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2849680038315532197U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17336102435576647923U;
            aOrbiterE = RotL64((aOrbiterE * 10984689101753586739U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7671010488872356142U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11485114338165600777U;
            aOrbiterC = RotL64((aOrbiterC * 4162584865462407791U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8759060657343458985U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11009137869375286581U;
            aOrbiterI = RotL64((aOrbiterI * 8741417343929809115U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15792999392743144135U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6180808423175992479U;
            aOrbiterH = RotL64((aOrbiterH * 13681230339693676907U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterC, 35U)) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 58U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterI, 51U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 12U) + aOrbiterI) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterA, 29U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8471U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((aIndex + 7980U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 6694U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8088U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10771U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 5906639480605353429U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 53U)) + 5293518570213287605U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 40U)) + RotL64(aCarry, 39U)) + 15383185501428521377U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 21U)) + 15364072512743978902U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 27U)) + 4525473357144014271U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 10400911938125603074U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 47U)) + 16417506293824627550U) + aPhaseEOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2419329331753341815U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14929222427923332069U;
            aOrbiterE = RotL64((aOrbiterE * 11596261802662514979U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16771573504983922586U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1863466450051787622U;
            aOrbiterG = RotL64((aOrbiterG * 2585626547126027053U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12895350137096692415U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3700979086526298327U;
            aOrbiterD = RotL64((aOrbiterD * 10279730254867618193U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1977099106211282426U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6144698304096915742U;
            aOrbiterI = RotL64((aOrbiterI * 5039822990560519609U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3858895556659724975U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 1283646340363435327U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11622421841377018069U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6240532051889108891U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 757364889381634634U;
            aOrbiterH = RotL64((aOrbiterH * 943852137901972945U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5272945693977418174U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6850528198786172283U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1966383079897679953U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 12U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 53U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterI, 3U)) + aPhaseEWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 44U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 11077U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((aIndex + 11596U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16322U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11014U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14153U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 14837U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 42U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 6733949564325516029U) + aPhaseEOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 19U)) + 7304098437143918796U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 51U)) + 3923949518391777800U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 14243591003388927124U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 5U)) + 18329498724605410406U;
            aOrbiterG = (aWandererB + RotL64(aCross, 42U)) + 13118172167747037249U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 5272025143849174212U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16075917179214318424U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15263590648674658399U;
            aOrbiterF = RotL64((aOrbiterF * 9918239923411740337U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13730046728289525921U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7703141464499623408U;
            aOrbiterH = RotL64((aOrbiterH * 5886009900621521987U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1382279753822135359U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2973369221699098292U;
            aOrbiterB = RotL64((aOrbiterB * 7440242040663550631U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11578274119583013219U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3419411247737896674U;
            aOrbiterG = RotL64((aOrbiterG * 17814942652262802991U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2582783513078999303U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3959762790273529677U;
            aOrbiterD = RotL64((aOrbiterD * 383974377372162751U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 465795011576934604U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17880826624185821135U;
            aOrbiterE = RotL64((aOrbiterE * 4445949147592860913U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10819659185349413173U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17298208553586835030U;
            aOrbiterJ = RotL64((aOrbiterJ * 1965860510614222093U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + aPhaseEWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 11U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 58U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17939U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((aIndex + 16544U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 19969U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18106U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16900U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17831U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 12046647397183218524U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 14U)) + 2760779375026461991U) + aPhaseEOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 43U)) + 13735454443176855650U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 51U)) + 4370377000586647724U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 14566322384189969094U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 5056565959818422786U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 35U)) + 8795403810686579209U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9625947666256011567U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1703669290934254701U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5763881345676123583U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 6664070663184147951U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2104148316797553431U;
            aOrbiterG = RotL64((aOrbiterG * 12887842067180975983U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1197910004222596145U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9922977170060903197U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13047828062605568603U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2048376210852567829U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12568990647075931409U;
            aOrbiterC = RotL64((aOrbiterC * 9860242601194210927U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15026894775772902751U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3439447160137900629U;
            aOrbiterA = RotL64((aOrbiterA * 1813754963043785165U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6532671388552829796U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17261098369835997661U;
            aOrbiterJ = RotL64((aOrbiterJ * 568292591215203521U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3171300991007459947U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5935563269327662024U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11271790283157765003U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 10U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 28U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 41U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 52U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24952U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((aIndex + 25862U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22840U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27186U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23684U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 23142U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 21U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererA + RotL64(aPrevious, 3U)) + 8604208734152026945U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 1374329953253889829U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 11U)) + 5779278910548228339U) + aPhaseEOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 17670451230882805140U) + aPhaseEOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 54U)) + 8193848740764866860U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 39U)) + 15801168428145650104U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 2584718176087499066U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14950366247822737997U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9779293225265670135U;
            aOrbiterF = RotL64((aOrbiterF * 11625969538497982117U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8688968319288372383U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13665723186950342601U;
            aOrbiterB = RotL64((aOrbiterB * 292035540396910837U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9395428688359973510U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2152719218018108418U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15271961483518392671U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1350324137411377992U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8729317951386057921U;
            aOrbiterA = RotL64((aOrbiterA * 6008790836417785083U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6317310451893678411U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10175620379041384281U;
            aOrbiterE = RotL64((aOrbiterE * 14079679617394330781U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1203082119358827708U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 523869107818193101U;
            aOrbiterH = RotL64((aOrbiterH * 4629501113595689157U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4028324959540432983U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15447631947468213912U;
            aOrbiterD = RotL64((aOrbiterD * 6037306615787729185U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 22U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 12U) + aOrbiterA) + RotL64(aOrbiterE, 35U));
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 28U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 11U)) + aOrbiterF) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 5U)) + aOrbiterB) + aPhaseEWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterH, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28628U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 29578U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31880U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28255U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31376U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 29397U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 23U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 3105313968748067810U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 9977249451119627064U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 17941392803495349366U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 57U)) + 4279533326705471133U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 26U)) + 13983828966811580039U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 47U)) + 3983490984234810378U) + aPhaseEOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 11U)) + 308786542215259956U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8443607695364427037U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14939626441464340668U;
            aOrbiterG = RotL64((aOrbiterG * 16793255020331774983U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9350693577306121110U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1717071159396961752U;
            aOrbiterD = RotL64((aOrbiterD * 11062480662625054525U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 15911765265202100610U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14898546272333182767U;
            aOrbiterB = RotL64((aOrbiterB * 2674900543810733067U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3560903518513465868U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5367062725726860234U;
            aOrbiterK = RotL64((aOrbiterK * 8521908836601319553U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15233321480618877327U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9288449812290126074U;
            aOrbiterF = RotL64((aOrbiterF * 6815298520404038519U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5504840529511585676U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6825598386801620046U;
            aOrbiterE = RotL64((aOrbiterE * 11666542445846250077U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6433024450721339470U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 97934156644929458U;
            aOrbiterA = RotL64((aOrbiterA * 8630530773006923215U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterA, 19U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterF, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterD, 36U)) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB, aSnowLaneA, aInvestLaneB, aExpandLaneD, aSnowLaneB, aExpandLaneC, aWorkLaneA, aInvestLaneD, aWorkLaneB, aExpandLaneA, aWorkLaneC, aInvestLaneA
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1711U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 4113U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2855U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3240U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 407U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5380U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aCarry, 36U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererE + RotL64(aScatter, 35U)) + 15726877954695761686U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 26U)) + 14187652171881943587U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 3U)) + 8420423151313882782U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 14942322692433259283U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 5U)) + 7272331475919796255U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 38U)) + 154504365041805840U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 17475491222554948786U;
            aOrbiterE = (aWandererC + RotL64(aCross, 41U)) + 5759181483165339605U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 57U)) + 5993060214499322845U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 10901786237875941844U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 19U)) + 17135786595614068473U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5208202073886811165U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6821452921018900631U;
            aOrbiterG = RotL64((aOrbiterG * 13119330055184115669U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13348064837402206969U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8967943922403445136U;
            aOrbiterD = RotL64((aOrbiterD * 300168481725373093U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8130283784171430891U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6351113882502502876U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15960622823993072903U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6894708729226455769U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12065058511247133944U;
            aOrbiterF = RotL64((aOrbiterF * 5432601727436935831U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17138279326229372741U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12987698199066890628U;
            aOrbiterA = RotL64((aOrbiterA * 12665716655177320977U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13688833537574196675U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4211971980434000618U;
            aOrbiterH = RotL64((aOrbiterH * 1374411763361518851U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10376917117582537592U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4807742522197923516U;
            aOrbiterC = RotL64((aOrbiterC * 15257251453302090961U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 18038296468177121243U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6879666349379745258U;
            aOrbiterB = RotL64((aOrbiterB * 15819475269715810555U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5193656664432659624U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 680899397323387963U;
            aOrbiterJ = RotL64((aOrbiterJ * 9857476056194621321U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1851929589073547860U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13093101559415170218U;
            aOrbiterI = RotL64((aOrbiterI * 13950928576652143737U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13695333301427028607U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15726877954695761686U;
            aOrbiterK = RotL64((aOrbiterK * 960063676226172027U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 37U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterG, 27U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 6U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 47U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 35U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterC, 44U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 18U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneB
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8913U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 10582U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8308U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneB[((aIndex + 8761U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8759U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7805U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 9391U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCross, 56U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 12535417189990029950U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 6204401443676390273U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 869613505613154672U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 19U)) + 15053590879563855802U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 27U)) + 13338989605204591428U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 40U)) + 18306470022403825392U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 53U)) + 1150696349434090218U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 57U)) + 13549541786420596437U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 37U)) + 14302878430259588461U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 13U)) + 4660437084477165225U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 6U)) + 1653628537860912069U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5594199757006711631U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11008472193138708891U;
            aOrbiterD = RotL64((aOrbiterD * 13645764762027798301U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3668516817279364310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 128159531749679984U;
            aOrbiterG = RotL64((aOrbiterG * 4523246859249826987U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6378674346113979108U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11438762460659123362U;
            aOrbiterE = RotL64((aOrbiterE * 2733309638158283953U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10624263004446482910U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12546839706919241411U;
            aOrbiterA = RotL64((aOrbiterA * 11468326687628079347U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8466639576503293921U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5828694979857951504U;
            aOrbiterJ = RotL64((aOrbiterJ * 7835487310289634515U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16496305151014092976U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 589464613876410567U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13190816610718051897U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4168532743415647825U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15944887793736489375U;
            aOrbiterK = RotL64((aOrbiterK * 17273403561158196717U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11642456814106259483U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1609897693632334867U;
            aOrbiterB = RotL64((aOrbiterB * 12912773555616819941U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14950238412766325479U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11862438528287402255U;
            aOrbiterF = RotL64((aOrbiterF * 7635864312080265695U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5900629306795222263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3221591991392500536U;
            aOrbiterI = RotL64((aOrbiterI * 7188525011266868855U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16938699391746264010U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12535417189990029950U;
            aOrbiterH = RotL64((aOrbiterH * 18212319484142613215U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterE, 60U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterH, 41U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 6U) + RotL64(aOrbiterA, 23U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterC, 43U)) + aPhaseFWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 29U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 30U) + aOrbiterH) + RotL64(aOrbiterF, 52U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 37U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 16332U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 15531U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 10942U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11188U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13803U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 11U)) + (RotL64(aCross, 29U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererI + RotL64(aCross, 37U)) + 3561491146322798260U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 35U)) + 7075025056181885339U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 13U)) + 9230910887904171613U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 39U)) + 4119781172609908917U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 51U)) + 17155609083870983149U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 2423018561430181695U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 42U)) + 12957280305617615744U) + aPhaseFOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 2461704174772065813U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 21U)) + 7907123257849391997U;
            aOrbiterG = (aWandererH + RotL64(aCross, 53U)) + 7257868138318960007U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 3U)) + 16425903703085702285U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2990822664594079467U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5654819006718953817U;
            aOrbiterJ = RotL64((aOrbiterJ * 4465096036756887801U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12183676471235678779U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15026286960542123922U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17199049329995315279U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12169080607071830522U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2906296852254787499U;
            aOrbiterA = RotL64((aOrbiterA * 6754514406846040163U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3029858695410344584U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14406410317495954566U;
            aOrbiterI = RotL64((aOrbiterI * 9663780721657983421U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11048818178401163861U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13622063920319445043U;
            aOrbiterB = RotL64((aOrbiterB * 2516025554421589857U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2642646089141233277U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12761571777929273548U;
            aOrbiterD = RotL64((aOrbiterD * 5518252696078700127U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7753802695131502382U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8510425459525030222U;
            aOrbiterF = RotL64((aOrbiterF * 12412361423636026483U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13522645164493316722U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1437430302489702713U;
            aOrbiterG = RotL64((aOrbiterG * 14019316635365783545U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14745189473423751499U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16968328257002103715U;
            aOrbiterC = RotL64((aOrbiterC * 17915588590593471981U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5001838243344386314U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 13506188720092630563U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7010027510838271877U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16902624500530747723U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3561491146322798260U;
            aOrbiterE = RotL64((aOrbiterE * 95761172090277669U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 44U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 10U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 26U) + aOrbiterE) + RotL64(aOrbiterH, 21U));
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 37U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterD, 18U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 34U) + aOrbiterD) + RotL64(aOrbiterG, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 20096U)) & S_BLOCK1], 42U) ^ RotL64(aSnowLaneA[((aIndex + 16594U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 21295U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19413U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 20403U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 51U)) + (RotL64(aCross, 38U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererB + RotL64(aCross, 47U)) + 252059974543142812U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 35U)) + 11690823093681457368U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 10U)) + 13282189752890971123U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 9507416294305708435U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 19U)) + 14053038174390776539U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 21U)) + 14605253312318725009U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 18138286582677863671U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 27U)) + 8530091235978489988U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 3U)) + 14381731677571170073U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 5U)) + 13316413456378978456U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 51U)) + 3910529530149320706U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6302070286831566901U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12324134652758551396U;
            aOrbiterD = RotL64((aOrbiterD * 17136438281540250165U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4773478557638475048U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4031153435446078944U;
            aOrbiterH = RotL64((aOrbiterH * 3876928995240982769U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3114794895962903899U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3552936509969106796U;
            aOrbiterE = RotL64((aOrbiterE * 16823186892738820299U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5828754613946145627U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17985241114076114558U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1986669631395606833U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11319331046368072261U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6104267020171882160U;
            aOrbiterA = RotL64((aOrbiterA * 12525117969211576177U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7662668379725735125U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6583034411403600735U;
            aOrbiterJ = RotL64((aOrbiterJ * 262095656452193889U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5569865728026310280U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4176065898330374039U;
            aOrbiterI = RotL64((aOrbiterI * 11305749530796963967U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13677146592276526676U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2734371113158117596U;
            aOrbiterB = RotL64((aOrbiterB * 13146444882662731975U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14890607377967461739U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3110674898918355049U;
            aOrbiterK = RotL64((aOrbiterK * 9637837600671200315U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15329760212453783067U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 18214263442264013242U;
            aOrbiterC = RotL64((aOrbiterC * 9139354822936682953U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6727267537859989206U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 252059974543142812U;
            aOrbiterG = RotL64((aOrbiterG * 9559128226993261041U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 10U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterG, 37U));
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 22U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aIngress, 54U) + RotL64(aOrbiterC, 57U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 11U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 50U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 43U));
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterH, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererC, 44U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25378U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneB[((aIndex + 22094U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21979U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24647U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 27229U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererD + RotL64(aScatter, 53U)) + 10404808878585437255U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 39U)) + 10587858736301591439U;
            aOrbiterF = (aWandererH + RotL64(aCross, 51U)) + 1430530909801644435U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 43U)) + 9090938022430118902U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 41U)) + 12936604311751121235U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 10U)) + 1000583006020232032U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 27U)) + 12352532088997042232U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 29U)) + 16723410947058502564U) + aPhaseFOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 57U)) + 16614089235313154270U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 4245553025593349277U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 13U)) + 3353146318549477494U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5935727336135635196U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10312187090293319667U;
            aOrbiterF = RotL64((aOrbiterF * 1395964500396711899U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12192843181244744484U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2542570124502586365U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17222847847573534963U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3315472769469002444U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17512858811783071174U;
            aOrbiterJ = RotL64((aOrbiterJ * 9070400454074283765U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16633218007427888082U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2502077714838858460U;
            aOrbiterA = RotL64((aOrbiterA * 970762420815997725U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14792910273226469214U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15739513291150783151U;
            aOrbiterB = RotL64((aOrbiterB * 11896279674116906915U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2192903544350345992U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 844428341223009295U;
            aOrbiterD = RotL64((aOrbiterD * 4768368713974002539U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2998511458298901402U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7790789639864783373U;
            aOrbiterE = RotL64((aOrbiterE * 9173097618440495497U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4540735375055164995U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13700342877362633034U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14730797752841670505U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16966725424259324323U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5945539295893015935U;
            aOrbiterI = RotL64((aOrbiterI * 12226268057062268981U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12560355243513521281U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2104086086480258265U;
            aOrbiterH = RotL64((aOrbiterH * 17989755118752755577U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4476697099257280568U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10404808878585437255U;
            aOrbiterC = RotL64((aOrbiterC * 6245415417832089357U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 21U));
            aWandererG = aWandererG + ((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterD, 37U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterA, 51U)) + aPhaseFWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 57U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 30U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterI, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterB, 19U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 41U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterC, 26U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 36U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31031U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 30496U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 28627U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28724U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32205U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 6U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 23U)) + 6024062041314952357U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aPrevious, 47U)) + 18340757093658015585U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 35U)) + 11911120493880346751U) + aPhaseFOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 17428074353884654439U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 10U)) + RotL64(aCarry, 47U)) + 12790849760814795936U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 41U)) + 12633397052172117800U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 11946150433665237945U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 29U)) + 16842157900909419285U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 3U)) + 14186235783224155962U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 51U)) + 13284904542579767591U;
            aOrbiterB = (aWandererA + RotL64(aCross, 18U)) + 11609181965078844357U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9628562297095374984U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7850281529011259759U;
            aOrbiterF = RotL64((aOrbiterF * 17611485102925470357U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 257458718073794527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10693404545773519306U;
            aOrbiterK = RotL64((aOrbiterK * 14821443722828498323U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3430519236533871460U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6183054506953198055U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6121082743789970911U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2905610989884221654U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4472163910775333862U;
            aOrbiterD = RotL64((aOrbiterD * 7770678426310856745U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16870142883133769663U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1403692060594816451U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9740854430251597879U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16904169913507057108U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4773518591580333357U;
            aOrbiterG = RotL64((aOrbiterG * 5306070307776061267U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6528141733853494275U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11254806909313951442U;
            aOrbiterC = RotL64((aOrbiterC * 6316669786405548827U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6857506858448143407U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2855763534355983644U;
            aOrbiterE = RotL64((aOrbiterE * 16881334940165182415U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12328391751024624740U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16475072086109949522U;
            aOrbiterJ = RotL64((aOrbiterJ * 15218626930666825883U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15505670341076785424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6972128419331939330U;
            aOrbiterB = RotL64((aOrbiterB * 12206069109180246067U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7151546362283646210U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6024062041314952357U;
            aOrbiterI = RotL64((aOrbiterI * 10243806128059850493U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 24U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 26U) + aOrbiterH) + RotL64(aOrbiterK, 60U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 41U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 39U)) + aPhaseFWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterB, 19U));
            aWandererK = aWandererK + ((RotL64(aScatter, 42U) + aOrbiterG) + RotL64(aOrbiterK, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 57U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterG, 4U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 53U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 22U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
        // ingress from: aWorkLaneA, aWorkLaneB, aInvestLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3627U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 7988U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 5096U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2486U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 274U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6119U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 38U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 10726035965553989335U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 967354339530195662U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aScatter, 3U)) + 10834593005478605624U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 38U)) + RotL64(aCarry, 43U)) + 1012888282838656933U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 29U)) + 15283530351725183253U) + aPhaseGOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11724495956731703750U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4288330117317505776U;
            aOrbiterD = RotL64((aOrbiterD * 2738997410474076757U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10894778070022873473U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15563886747621617467U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17884709931569040065U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 11182488628562891937U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10420140066310588580U;
            aOrbiterI = RotL64((aOrbiterI * 13898299782819948719U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11775138062167543111U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16545391898578161683U;
            aOrbiterB = RotL64((aOrbiterB * 14588306527161321535U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1550144656312299266U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14903504853138279883U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8003033561266164387U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 14U)) + aOrbiterH) + aPhaseGWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterB, 27U));
            aWandererC = aWandererC + (((RotL64(aIngress, 14U) + RotL64(aOrbiterB, 51U)) + aOrbiterI) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11797U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 11694U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8779U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11883U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12830U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 15177U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 28U)) + RotL64(aCarry, 51U)) + 17454559218352016650U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 13U)) + 8005709669325164803U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 13393741948412816357U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 47U)) + 3665865624348875553U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 8334142570031883436U) + aPhaseGOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17226066128706139657U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3319093033121522613U;
            aOrbiterC = RotL64((aOrbiterC * 17961784341097933029U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6657535603401588798U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5469746182326331147U;
            aOrbiterA = RotL64((aOrbiterA * 11315450342347794329U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17846791786050221418U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15939541003714896288U;
            aOrbiterF = RotL64((aOrbiterF * 1400351482213119809U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12076763190461077406U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3594038213596405284U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10244002692575821495U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8301291631324464622U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8460406137668390582U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9117147929757711595U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 40U) + aOrbiterC) + RotL64(aOrbiterB, 53U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 29U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 14U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterA, 37U)) + aPhaseGWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererB, 34U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20846U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 16733U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 17585U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17467U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23773U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 21826U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 28U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererA + RotL64(aScatter, 3U)) + 8767379393098711499U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 7168159491580816433U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 9879279829061883406U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 10537167136053399303U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aScatter, 54U)) + 2839070018069188936U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13844278063968429732U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 11278946626186474646U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6601953972456332355U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11798425216660557799U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7618446090703335192U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7168757300685156779U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 695423597006983660U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14344728202803488813U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5168825904902285909U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11656100506575697086U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10384358779985773937U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 247494692039140973U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17585001605131977341U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9964478171465522911U;
            aOrbiterA = RotL64((aOrbiterA * 13484044854790175315U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 23U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + RotL64(aOrbiterF, 47U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterG, 4U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30824U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 32429U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 24918U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28975U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31496U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32201U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 15920462086654025436U) + aPhaseGOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 487844076858004017U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 27U)) + 14502883786442630566U) + aPhaseGOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 57U)) + 3787107318658233674U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 42U)) + RotL64(aCarry, 41U)) + 12548777544693755491U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4907309444075181683U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 18342396700266492072U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14842961036061482089U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13503051997624242670U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17845742460521374571U;
            aOrbiterH = RotL64((aOrbiterH * 1366356786138085155U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8640887211877858169U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5273913123709097537U;
            aOrbiterD = RotL64((aOrbiterD * 1661149444148461791U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17756844173695563883U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6713055830729302951U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2832836748513174311U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5106468334224035972U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10228769728713526172U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9760310686414358435U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 54U) + aOrbiterF) + RotL64(aOrbiterA, 20U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5365U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 4526U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1028U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7092U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7470U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 4911U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 19U) + RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 16922357079016918108U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 29U)) + 11771749797137599131U) + aPhaseHOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 43U)) + 4635668433708036077U) + aPhaseHOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 15827952719230577008U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 20U)) + RotL64(aCarry, 35U)) + 1495675306110023086U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7294835466949728365U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 179122461212041978U;
            aOrbiterF = RotL64((aOrbiterF * 14467072888722097971U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 545981421632236251U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15338259639814630535U;
            aOrbiterJ = RotL64((aOrbiterJ * 14895421566334357871U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12924313840290895215U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17846785921286020610U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18309347016029917133U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5721472794107057875U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16359630793856870319U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14186771515526698907U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10614102110239037308U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16421992251278236531U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2561232904676068089U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 22U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterH, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 52U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9764U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 13381U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 14607U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12423U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11757U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14041U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 48U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 5U)) + 1364174714924216027U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 58U)) + RotL64(aCarry, 53U)) + 13561796874229506613U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 41U)) + 11845572344206238305U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 15762708240326773763U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 1157119665207900473U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6823546624372055260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14465564210523945121U;
            aOrbiterB = RotL64((aOrbiterB * 10957323253786161255U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10667464548080807531U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13445737493224316575U;
            aOrbiterC = RotL64((aOrbiterC * 12137295000900795711U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3009837893785957665U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2886920524111083752U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15308180928967762543U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10886177449328249656U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15067759884678100433U;
            aOrbiterI = RotL64((aOrbiterI * 5724566815989860041U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 18307930462682331536U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8791864377579255801U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9265158882471421767U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 27U);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterE, 19U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 41U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterH, 54U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + aPhaseHWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16519U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 18241U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22142U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18713U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17569U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 20559U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 29U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 46U)) + 2617613537256538553U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 16642868916835132715U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 10860291124337073254U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 6432511273906902472U) + aPhaseHOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 27U)) + 7505375005848241910U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11086616004678821329U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3298830587569881951U;
            aOrbiterF = RotL64((aOrbiterF * 4304047944073454489U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9775143140064220979U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4147601326580823120U;
            aOrbiterG = RotL64((aOrbiterG * 13462244678782260871U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12245920269898100415U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8391940489176734499U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9119606167674098007U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17876893379544668477U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 18301882058180370541U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16680384667098921309U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6869225862715140102U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15404118372589259800U;
            aOrbiterA = RotL64((aOrbiterA * 5766851935950389915U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterA, 11U)) + aPhaseHWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 26U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + aPhaseHWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 58U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32742U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((aIndex + 31545U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 27950U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31334U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30933U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 24923U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 26U)) + 13915875634607599122U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 1695770381382411673U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 3709105579778295511U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 7673376335333251804U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 13U)) + 8814147709738503518U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13451412605350381172U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6447870234069609538U;
            aOrbiterD = RotL64((aOrbiterD * 4016219229618539433U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13419487997946496825U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5478309847615220345U;
            aOrbiterG = RotL64((aOrbiterG * 12953043149543448765U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3635184969215610049U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12527903812035294828U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12540800512035534967U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1684685110885338814U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12860354576326835090U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12743745087733307255U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9081823570147481835U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14369321778210049109U;
            aOrbiterB = RotL64((aOrbiterB * 17865953349448767035U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterG, 35U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterD, 23U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 14U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
